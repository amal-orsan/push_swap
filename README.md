*This activity has been created as part of the 42 curriculum by aalorsan, fadarwis.*

# push_swap

## Description

**push_swap** is a 42 project that implements sorting algorithms with a restricted set of stack operations (push, swap, rotate). 
The goal is to sort a list of integers in as few moves as possible.

The challenge forces you to think about **algorithmic complexity** in a very concrete way. The same input sorted by different 
strategies can result in wildly different operation counts.This implementation includes **four distinct sorting strategies** selected automatically 
based on how disordered the input is, or forced manually via command-line flags.
## Instructions
### Compilation

```bash
make
```

To clean object files:
```bash
make clean
```

To remove everything including the binary:
```bash
make fclean
```
### Usage
```
*This activity has been created as part of the 42 curriculum by aalorsan, fadarwis.*

# push_swap

## Description

**push_swap** is a 42 project that implements sorting algorithms with a restricted set of stack operations (push, swap, rotate). 
The goal is to sort a list of integers in as few moves as possible.

The challenge forces you to think about **algorithmic complexity** in a very concrete way. The same input sorted by different 
strategies can result in wildly different operation counts.This implementation includes **four distinct sorting strategies** selected automatically 
based on how disordered the input is, or forced manually via command-line flags.
## Instructions
### Compilation

```bash
make
```

To clean object files:
```bash
make clean
```

To remove everything including the binary:
```bash
make fclean
```
### Usage
```
Include the header file in your source code:

#include "push_swap.h"
```
### Technical Choices :

    Written in C following Norminette rules

    No forbidden functions used

    Doubly-linked list used

    Parsing function ensures correct input

    Disorder metric computed before any moves to drive adaptive strategy selection

### Algorithm Overview:

	Parse and validate all arguments; exit with Error on bad input.

	Build stack a as a doubly-linked list from the given integers.
	
	Compute the disorder score (ratio of inverted pairs to total pairs).

	Execute the chosen strategy, printing each operation to stdout.
	
	If --bench is active, print disorder, strategy name, total ops, and per-operation counts to stderr.

## Data Structures

The project uses a doubly linked list to represent each stack.
Every element in the stack is stored as a node containing its raw integer value, a normalized index representing its rank among all values,
a pointer to the next node toward the bottom of the stack, and a pointer to the previous node toward the top.
A doubly linked list was chosen specifically because the reverse rotate operation requires moving the last node to the top of the stack. 
With a `prev` pointer and a direct reference to the tail, this is an O(1) operation. 
Without it, finding the second-to-last node would require traversing the entire list on every reverse rotate, 
making it O(n) and significantly increasing the total operation count.

### Explanation and justification of the used algorithms
	
	For Simple O(n2):
		We chose Selection Sort to efficiently handle small stacks in push_swap. 
		By repeatedly finding the minimum value and rotating it to the top using the shortest path, either upward or downward depending on its position,
		the algorithm minimizes unnecessary moves. 
		Converting numbers to 0-based indices further simplifies comparisons and ensures consistent behavior regardless of the actual input values, allowing 
		small stacks to be sorted correctly while fully complying with project constraints.		
	
	For Meduim O(n*sqrt(n)):
		We chose Chunk Sort with a smaller chunk count to efficiently handle medium-sized stacks in push_swap.
		By dividing the normalized indices into a limited number of groups and pushing each group to stack b as a batch, 
		the algorithm reduces the number of full-stack traversals compared to selection sort. 
		Rotating each target element using the shortest path, either upward or downward depending on its position, further minimizes unnecessary moves, 
		allowing medium-sized stacks to be sorted with a balanced operation count while fully complying with project constraints.
	
	For Complex O(n*log(n))
	    we implemented bitwise Radix LSD for efficient sorting. The algorithm works as follows: Find the largest number in the stack to determine the number of bits needed.
        Start sorting from the least significant bit (rightmost) to the most significant.
        For each bit of each number: If the bit is 0, push the number to stack B (pb). If the bit is 1, rotate the number within stack A (ra).
        Repeat until all bits are processed; the stack becomes fully sorted. 
        We chose this method because it minimizes the total operations and runtime, making it faster and more efficient than other sorting approaches allowed in push_swap.
## Resources 

1. https://youtu.be/wRvipSG4Mmk?si=BHYMoIYGftUbahjB
2. https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0
3. https://www.geeksforgeeks.org/
4. youtube videos to understand radix lsd algorithm and the differences between this and the rest of algorithms.
5. 42 push swap subject. 
6. github repositories about push swap and bench mode.

### Use of AI
AI tools were used only as learning support, specifically to:

	Explain algorithmic complexity theory and help reason through the disorder metric design.

	Review the argv parsing logic for the single-string vs multi-argument input edge case.

	suggest how to split long functions into smaller helpers.

All code was written, tested, and debugged manually.

