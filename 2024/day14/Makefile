build:
	/usr/bin/g++ 2.cpp -o 2 -std=c++20 `pkg-config --cflags --libs opencv4`
run: build
	./2 < input.txt > output.txt

clear:
	rm 2 rasm.png