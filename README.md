This project focuses on developing a doubly circular linked list with a sentinel node, including fundamental operations for managing and manipulating the list efficiently.
<br>

> [!NOTE] 
> This is the first homework of data structures and algorithms from UNSTPB ACS faculty, CS field, 1st year.

#### Main structs
```c
typedef struct TrCell2 {
    char data;
    struct TrCell2 *next;
    struct TrCell2 *prev;
} TRCell2, *TRL2;

typedef struct Train {
    TRL2 head;
    TRL2 mechanic;
} *TTrain;
```
#### The operations implemented are
- move left/right

```console
It moves the mechanic, which represents the current cell, to one of its adjacent positions.
```
- insert left/right

```console
It inserts a new cell adjacent to the current mechanic's position and it moves the mechanic accordingly.
```
> [!NOTE]
> If the mechanic is in the first car, it will be displayed an error message
- search left/right

```console
It searches for a certain character from the current position until it reaches the sentinel.
```
- search

```console
It searches circularly for a certain character from the current position to the right until it resches its left neighbour from the start. 
```
- clear_cell

```console
It clears the contents of the cell and it removes it completely.
```
- clear_all

```console
It clears all the cells and it restores the train to its initial state.
```
- switch

```console
It reverts the content of the queue up to that point.
```
> [!NOTE]
> All commands besides SHOW, SHOW_CURRENT and SWITCH are put into a pq.
- show

```console
It shows the content of the entire list with mechanic's character between pipes.
```
- show_current

```console
It shows the content of the mechanic's cell.
```
- write

```console
It overwrites the mechanic's cell content aka the current cell or the cell under the cursor.
```
