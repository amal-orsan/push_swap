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
```
### Usage

Include the header file in your source code:

```c
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

## Resources 

1. https://youtu.be/wRvipSG4Mmk?si=BHYMoIYGftUbahjB
2. https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

### Use of AI
AI tools were used only as learning support, specifically to:

    Explain algorithmic complexity theory and help reason through the disorder metric design.

    Review the argv parsing logic for the single-string vs multi-argument input edge case.

    suggest how to split long functions into smaller helpers.

All code was written, tested, and debugged manually. 
