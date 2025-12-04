package main

import (
	"fmt"
	"os"
	"strings"
	"sync"
	"sync/atomic"
	"time"
)

func main() {
	start := time.Now()
	solve()
	duration := time.Since(start)

	perf_file, _ := os.OpenFile("perf.txt", os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
	res := fmt.Sprintf("Execution time (Go parallel): %d ms\n", duration.Milliseconds())
	perf_file.WriteString(res)
	perf_file.Close()
}

var (
	n = 3002
	m = 3002
)

func solve() {
	l, _ := os.ReadFile("large_input.txt")
	lines := strings.Split(string(l), "\n")

	g := make([]byte, n*m)
	for i := range g {
		g[i] = '.'
	}

	for i, line := range lines {
		r := (i + 1) * m
		for j := 0; j < len(line); j++ {
			g[r+j+1] = line[j]
		}
	}

	var ans int64
	num_workers := max(n-2, 1)

	for {
		var changed int64
		var wg sync.WaitGroup

		row_cnt := (n - 2) / num_workers

		for w := 0; w < num_workers; w++ {
			wg.Add(1)
			start := 1 + w*row_cnt
			end := start + row_cnt
			if w == num_workers-1 {
				end = n - 1
			}

			go func(start, end int) {
				defer wg.Done()
				v := make([]int, 0, 1024)

				for i := start; i < end; i++ {
					left := i * m
					for j := 1; j < m-1; j++ {
						idx := left + j
						if g[idx] != '@' {
							continue
						}

						cnt := 0
						U := idx - m
						if g[U-1] == '@' {
							cnt++
						}
						if g[U] == '@' {
							cnt++
						}
						if g[U+1] == '@' {
							cnt++
						}

						if g[idx-1] == '@' {
							cnt++
						}
						if g[idx+1] == '@' {
							cnt++
						}

						D := idx + m
						if g[D-1] == '@' {
							cnt++
						}
						if g[D] == '@' {
							cnt++
						}
						if g[D+1] == '@' {
							cnt++
						}

						if cnt < 4 {
							v = append(v, idx)
						}
					}
				}

				cur := int64(len(v))
				for _, idx := range v {
					g[idx] = '.'
				}
				atomic.AddInt64(&changed, cur)
				atomic.AddInt64(&ans, cur)
			}(start, end)
		}

		wg.Wait()

		if changed == 0 {
			break
		}
	}

	os.WriteFile("output.txt", []byte(fmt.Sprintf("%d\n", ans)), 0644)
}
