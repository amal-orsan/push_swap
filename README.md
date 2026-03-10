*This activity has been created as part of the 42 curriculum by aalorsan, fadarwis.*

# push_swap

## Description

**push_swap** is a 42 project that implements sorting algorithms with a restricted set of stack operations (push, swap, rotate).
The goal is to sort a list of integers in as few moves as possible.

The challenge forces you to think about **algorithmic complexity** in a very concrete way. The same input sorted by different
strategies can result in wildly different operation counts. This implementation includes **four distinct sorting strategies** selected automatically
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

```bash
./push_swap 3 1 2 5 4
```

You can also pass integers as a single quoted string:
```bash
./push_swap "3 1 2 5 4"
```

Each operation performed will be printed to stdout. To count the total number of operations:
```bash
./push_swap 3 1 2 5 4 | wc -l
```

To include the header in your own source code:
```c
#include "push_swap.h"
```

### Technical Choices

- Written in C following Norminette rules
- No forbidden functions used
- Doubly-linked list used
- Parsing function ensures correct input
- Disorder metric computed before any moves to drive adaptive strategy selection

### Algorithm Overview

1. Parse and validate all arguments; exit with `Error` on bad input.
2. Build stack `a` as a doubly-linked list from the given integers.
3. Compute the disorder score (ratio of inverted pairs to total pairs).
4. Execute the chosen strategy, printing each operation to stdout.
5. If `--bench` is active, print disorder, strategy name, total ops, and per-operation counts to stderr.

## Data Structures

The project uses a doubly linked list to represent each stack.
Every element in the stack is stored as a node containing its raw integer value, a normalized index representing its rank among all values,
a pointer to the next node toward the bottom of the stack, and a pointer to the previous node toward the top.

A doubly linked list was chosen specifically because the reverse rotate operation requires moving the last node to the top of the stack.
With a `prev` pointer and a direct reference to the tail, this is an O(1) operation.
Without it, finding the second-to-last node would require traversing the entire list on every reverse rotate,
making it O(n) and significantly increasing the total operation count.

### Explanation and Justification of the Used Algorithms

**Simple O(n^2):**
We chose Selection Sort to efficiently handle small stacks in push_swap.
By repeatedly finding the minimum value and rotating it to the top using the shortest path — either upward or downward depending on its position —
the algorithm minimizes unnecessary moves.
Converting numbers to 0-based indices further simplifies comparisons and ensures consistent behavior regardless of the actual input values, allowing
small stacks to be sorted correctly while fully complying with project constraints.

**Medium O(n *sqrt(n)):**
We chose Chunk Sort with a smaller chunk count to efficiently handle medium-sized stacks in push_swap.
By dividing the normalized indices into a limited number of groups and pushing each group to stack b as a batch,
the algorithm reduces the number of full-stack traversals compared to selection sort.
Rotating each target element using the shortest path, either upward or downward depending on its position, further minimizes unnecessary moves,
allowing medium-sized stacks to be sorted with a balanced operation count while fully complying with project constraints.

**Complex O(n * log(n)):**
We chose Radix LSD to efficiently sort stacks in push_swap. By processing numbers from the least significant digit to the most significant,
the algorithm provides stable sorting and predictable performance. Converting numbers to 0-based indices further optimizes stack operations,
allowing large stacks to be sorted with minimal moves while complying with project constraints.

## Resources

1. https://youtu.be/wRvipSG4Mmk?si=BHYMoIYGftUbahjB
2. https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0
3. https://www.geeksforgeeks.org/
4. https://www.youtube.com/results?search_query=radix+sort+LSD (Radix LSD algorithm overview and comparisons)
5. 42 push_swap subject.
6. Various GitHub repositories on push_swap implementations and bench mode.

### Team collaboration : 

The work is done of both team members so :
 aalorsan do flags, swap, rotate, reverse rotate operations, validation, header file, Makefile, complex and adaptive algorithms and all small sorts operations for stack size less than or equal to 5.

 And fadarwis do parsing, stack building , simple and medium algorithms, push operations, bench, bench print, make indexing and utils functions and README.md file. 

all cases are tested from the both team members.

### Use of AI

AI tools were used only as learning support, specifically to:

- Explain algorithmic complexity theory and help reason through the disorder metric design.
- Review the argv parsing logic for the single-string vs multi-argument input edge case.
- Suggest how to split long functions into smaller helpers.

All code was written, tested, and debugged manually.