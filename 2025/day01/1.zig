const std = @import("std");
const print = std.debug.print;

pub fn main() void {
    var stdin_buffer: [1 << 10]u8 = undefined;
    var stdin_reader = std.fs.File.stdin().reader(&stdin_buffer);
    const stdin = &stdin_reader.interface;

    var a: i32 = 50;
    var ans: i32 = 0;

    while (true) {
        const res = stdin.takeDelimiter('\n');
        var text: []u8 = undefined;
        if (res) |line| {
            if (line) |l| {
                text = l;
            } else {
                break;
            }
        } else |err| {
            switch (err) {
                error.ReadFailed => {
                    print("Encountered a ReadFailed error.\n", .{});
                },
                error.StreamTooLong => {
                    print("Stream was too long.\n", .{});
                },
            }
            continue;
        }

        const c = text[0];
        const x = std.fmt.parseInt(i32, text[1..], 10);
        var n: i32 = 0;
        if (x) |xx| {
            n = xx;
        } else |err| {
            switch (err) {
                error.InvalidCharacter => {
                    print("Invalid character found in input.\n", .{});
                },
                error.Overflow => {
                    print("Overflow.\n", .{});
                },
            }
        }
        if (c == 'L') {
            a -= n;
        } else {
            a += n;
        }
        a = @mod((a + 100), 100);
        if (a == 0) {
            ans += 1;
        }
    }

    print("{d}\n", .{ans});
}
