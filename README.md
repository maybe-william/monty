# Stacks, Queues - LIFO, FIFO
---
## Description
* An interpreter for Monty ByteCode files
* Understand what LIFO and FIFO mean
* Understand a stack, and when to use it
* Understand a queue, and when to use it
* Understand the common implementations of stacks and queues
* Understand the most common use cases of stacks and queues
* Understand the proper way to use global variables
* Understand how to work with git submodules

## Compilation
gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic<br/>
___$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty ___

## Files
---
File|Description
---|---
add_dnodeint.c | adds a new node at the beginning of a dlistint_t list
add_dnodeint_end.c | adds a new node at the end of a list_t list
add.c | add two values on the stack
delete_dnodeint.c | deletes the node at index
dlistint_len.c | returns the number of elements in dlistint_t list
div.c | divide two values on the stack
errors1.c | file for opcode error messages
errors2.c | file for opcode error messages
errors3.c | file for opcode error messages
free_dlistint.c | frees a dlistint_t list
get_dnodeint.c | function that returns the nth node of a linked list
insert_dnodeint.c | function that inserts new node at given position
mod.c | modulus two values on the stack
mul.c | multiply two values on the stack
pall.c | print all of the stack
parser.c | read each line from a file, parse, and execute on a stack/queue
pchar.c | print the top value on the stack as a character
pint.c | prints the top of the stack
pop.c | removes the top element of the stack
pstr.c | print the values on the stack as a string
print_dlistint.c | function that prints all the elements of a dlistint_t list
queue.c | change the stack into a queue
rotl.c | move top to end, second to top
rotr.c | rotate the bottom of the stack to the top
stack.c | make stack a stack
status.c | either throw an error and exit, or initialize the fd
sub.c | subtract two values on the stack
sum_dlistint.c | function that returns the sum of all the data of linked list
swap.c | swap two values on the stack

##Examples

## More Info
All files are formatted in Betty style and checked using betty-style.pl and betty-doc.pl
All header files are guarded

## Authors
William Dyralnd-Marquis and Osama Basheer