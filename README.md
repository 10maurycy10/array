# Arrays VS linked lists

Everyone knows linked lists are slower than arrays, but are they?

TLDR: a linked list of ints is 50% to **access** slower than a array.

## source files:

- ll.c: a standerd linked list implementation: 

- ar.c: a standard array implementaion

- bigll.c: a linked list of 10 ints per element.

- bigar.c: a array iterated every 10th element.

## results

Iteration over linked lists are 50%-60% slower than arrays.

The speed difrence will not depend on the size of the elements.

The programs output is the time taken by 10000 iterations (in clock ticks) and, the amount of ticks per second.

### raw results

see ``/results``
