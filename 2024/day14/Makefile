
# Load .env variables
include ../../.env
export $$(shell sed -n 's/^\([^#][^=]*\)=.*/\1/p' ../../.env)

one:
	/usr/bin/g++ 1.cpp -o exe -O2 -std=c++20
	./exe < input.txt > output.txt

two:
	/usr/bin/g++ 2.cpp -o exe -O2 -std=c++20
	./exe < input.txt > output.txt

get:
	aocdl -year 2024 -day 14 -force -session-cookie $(AOC_SESSION)

cp:
	cp 1.cpp 2.cpp

clear:
	rm exe

