This a project called push_swap for 42 School.
======

The goal is to write a program that takes as an argument the stack
'a' formatted as a list of integers. The program must display a list of instructions to sort the stack 'a'.

The instructions that can be used are limited:

	-**sa** (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
	-**sb** (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
	-**ss** : sa and sb at the same time.
	-**pa** (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
	-**pb** (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
	-**ra** (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
	-**rb** (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
	-**rr** : ra and rb at the same time.
	-**rra** (reverse rotate a): Shift down all elements of stack a by 1.	The last element becomes the first one.
	-**rrb** (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
	-**rrr** : rra and rrb at the same time.

The args must be integers, and there must not be duplicate numbers, otherwise "Error" must be displayed.

The checker_linux is provided and it prints "OK\n" if the moves correctly sort the numbers, and "KO\n" if they dont.

Also, this project is evaluated by points:

	-With 3 numbers, we need to sort it with not more than 3 instructions.

	-With 5 numbers, we need to sort it with not more than 12 instructions.

	-With 100 numbers, we can get
		5 points if (instructions < 700)
		4 points if (700 < instructions < 900)
		3 points if (900 < instructions < 1100)
		2 points if (1100 < instructions < 1300)
		1 points if (1300 < instructions < 1500)

	-With 500 numbers, we can get
		5 points if (instructions < 5500)
		4 points if (5500 < instructions < 7000)
		3 points if (7000 < instructions < 8500)
		2 points if (8500 < instructions < 10000)
		1 points if (10000 < instructions < 11500)

My push_swap is able to get 1084 instructions with 100 numbers, and 6784 instructions with 500 numbers.

I used the radix sort algorithm to sort the stack.

For easier evaluation, I've added a bash script, to check how many instruction are printed for a given number of initial numbers.

The script usage is as follows:

./test.sh ./push_swap ./checker "amountOfNumbersInStackA" "limitOfMoves"

The bonus part is adding a checker program, that checks if the instructions successfully sort the stack 'a'. A bonus rule should be added to the make file to compile the checker executable. It should also print "OK\n" if the moves correctly sort the numbers, and "KO\n" if they dont.

The full subject was added to the root of the repository.
