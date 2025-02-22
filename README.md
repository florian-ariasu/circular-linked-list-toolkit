## Train Data Structure Implementation
> A sophisticated implementation of a doubly circular linked list with sentinel node, designed for efficient data manipulation and management.

### 🎯 Project Overview
This implementation represents a train system using a doubly circular linked list with a sentinel node. Each cell in the structure represents a train car, with a mechanic pointer indicating the current position for operations.

### 🏗️ Core Data Structures

```c
typedef struct TrCell2 {
    char data;              // Content of the train car
    struct TrCell2 *next;   // Pointer to next car
    struct TrCell2 *prev;   // Pointer to previous car
} TRCell2, *TRL2;

typedef struct Train {
    TRL2 head;             // Sentinel node
    TRL2 mechanic;         // Current position pointer
} *TTrain;
```

### 🛠️ Implemented Operations

#### Navigation Operations
| Operation | Description |
|-----------|-------------|
| `MOVE_LEFT/RIGHT` | Moves the mechanic cursor to adjacent positions |
| `SEARCH_LEFT/RIGHT` | Searches for a character from current position to sentinel |
| `SEARCH` | Performs circular search from current position |

#### Modification Operations
| Operation | Description |
|-----------|-------------|
| `INSERT_LEFT/RIGHT` | Adds new cell adjacent to mechanic position |
| `WRITE` | Overwrites current cell content |
| `CLEAR_CELL` | Removes current cell |
| `CLEAR_ALL` | Resets structure to initial state |
| `SWITCH` | Reverses queue content up to current position |

#### Display Operations
| Operation | Description |
|-----------|-------------|
| `SHOW` | Displays entire list (mechanic position marked with \|character\|) |
| `SHOW_CURRENT` | Displays mechanic's cell content |

### ⚠️ Important Notes

1. Insert operations will display an error if mechanic is in first car
2. All commands except `SHOW`, `SHOW_CURRENT`, and `SWITCH` are processed through a priority queue
3. The mechanic position always indicates the active cell for operations

### 🔍 Implementation Details

Each operation is carefully implemented to maintain list integrity while providing efficient data manipulation:

- **Circular Nature**: The list maintains its circular property through all operations
- **Sentinel Node**: Provides simplified edge case handling
- **Bidirectional Links**: Enable efficient traversal in both directions
- **Priority Queue**: Ensures ordered command execution

### 💡 Usage Example

```console
// Example structure visualization
[S]-[A]-[B]-[|C|]-[D]-[E]
// Where S is sentinel node and |C| is mechanic position
```

### 📜 Licence
This project is licensed under the MIT Licence. See the [LICENCE](./LICENSE) file for further details.
