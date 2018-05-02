# monty
#### 0x18. C - Stacks, Queues - LIFO, FIFO

A Monty bytecode interpreter.

To run, compile all the C files, make the resultant file executable, then run the program by calling it and passing the Monty bytecode file to it as an agrument.

<br>

#### Opcodes:

`push` - Adds a new node at the beginning of a stack_t list.

`pall` - Prints all the elements of a stack_t list.

`pint` - Prints the value at the top of the stack, followed by a new line.

`pop` - Deletes the first node of the stack.

`swap` - Swaps the top two elements of the stack.

`add` - Adds the top two elements of the stack.

`sub` - Subtracts the top element of the stack from the second top element of the stack.

`div` - Divides the second top element of the stack by the top element of the stack.

`mul` - Multiplies the second top element of the stack with the top element of the stack.

`mod` - Computes the rest of the division of the second top element of the stack by the top element of the stack.

`pchar` - Prints the char at the top of the stack, followed by a new line.

`pstr` - Prints the string starting at the top of the stack, followed by a new line.

`rotl` - Rotates the stack to the top.

`rotr` - Rotates the stack to the bottom.

`nop` - Doesn’t do anything.

<br>

#### Examples:
##### Compile and run:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
$ chmod a+x monty
$ ./monty FILENAME
```

##### File input and output:
```
$ cat commands.txt 
push 5
push 22
pall
pop
pall
push 77
pchar
$ ./monty commands.txt 
22
5
5
M
```
