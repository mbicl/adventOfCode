
# Load .env variables
include ../../.env
export $$(shell sed -n 's/^\([^#][^=]*\)=.*/\1/p' ../../.env)

one:
	/usr/bin/g++ 1.cpp -o exe -O2 -std=c++20
	./exe < input.txt > output.txt

two:
	/usr/bin/g++ 2.cpp -o exe -O2 -std=c++20
	./exe < input.txt > output.txt

fast:
	/usr/bin/g++ -O3 -std=c++20 fast.cpp -o fast_exe
	./fast_exe

go:
	go build -o go_exe parallel.go
	./go_exe

get:
	aocdl -year 2025 -day 4 -force -session-cookie $(AOC_SESSION)

cp:
	cp 1.cpp 2.cpp

clear:
	rm exe fast_exe go_exe
