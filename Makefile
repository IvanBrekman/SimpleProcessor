cr:
	clear
	gcc main.cpp run_cpu.cpp libs/baselib.cpp libs/file_funcs.cpp libs/stack.cpp -lm -o main.out
	./main.out commands.txt program.kitty

r:
	./main.out commands.txt program.kitty

c:
	gcc main.cpp run_cpu.cpp libs/baselib.cpp libs/file_funcs.cpp libs/stack.cpp -lm -o main.out
