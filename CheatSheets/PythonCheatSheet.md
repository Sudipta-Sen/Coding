# Python Cheatsheet for DSA

##  1. List (Similar to ArrayList in Java)

### Definition: Dynamic array, allows resizing and various operations.

```python
lst = []  # Empty list
```

### Common Methods:
| Method              | Description                                         |
|---------------------|-----------------------------------------------------|
| `lst.append(item)`   | Adds an item to the end of the list                 |
| `lst.insert(index, item)` | Inserts an item at a specific index            |
| `lst.remove(item)`   | Removes the first occurrence of the item            |
| `lst.pop(index)`     | Removes and returns the item at the given index (last by default) |
| `lst.clear()`        | Removes all items from the list                     |
| `lst.index(item)`    | Returns the index of the first occurrence of the item |
| `lst.count(item)`    | Returns the number of occurrences of the item       |
| `lst.sort()`         | Sorts the list in place                             |
| `lst.reverse()`      | Reverses the list in place                          |

## 2. Stack (Using list or collections.deque)

### Using List:

```python
stack = []  # Empty stack
stack.append(item)  # Push
stack.pop()  # Pop
```

### Using Deque (More efficient for stack operations):
```python
from collections import deque

stack = deque()  # Empty stack
stack.append(item)  # Push
stack.pop()  # Pop
```

## 3. Queue (Using collections.deque or queue.Queue)

### Using Deque (Double-ended queue):
```python
from collections import deque

queue = deque()  # Empty queue
queue.append(item)  # Enqueue
queue.popleft()  # Dequeue
```

### Using Queue (Thread-safe, blocking operations):

```python
from queue import Queue

queue = Queue()  # Empty queue
queue.put(item)  # Enqueue
queue.get()  # Dequeue
```

##  4. HashMap (Using dict, Similar to Java HashMap)
### Definition: 
A key-value pair structure (hash table).

```python
hash_map = {}  # Empty dictionary
```

### Common Methods:

| Method              | Description                                         |
|---------------------|-----------------------------------------------------|
| `hash_map[key] = value`   | Inserts or updates the value for the given key    |
| `hash_map.get(key, default=None)` | Returns the value for the key, or default if the key is not found |
| `hash_map.pop(key)`   | Removes and returns the value for the given key   |
| `hash_map.keys()` | Returns a view object of all keys |
| `hash_map.values()`   | Returns a view object of all values   |
| `hash_map.items()	`   | Returns a view object of all key-value pairs  |

## 5. Set (Similar to Java HashSet)

### Definition: 
Unordered collection of unique items.

```python
hash_set = set()  # Empty set
```

### Common Methods:

| Method              | Description                                         |
|---------------------|-----------------------------------------------------|
| `hash_set.add(item)`    |	Adds an item to the set |
| `hash_set.remove(item)` |	Removes the item from the set (raises KeyError if not found)    |
| `hash_set.discard(item)`    |	Removes the item without raising an error if not found  |
| `hash_set.pop()`    |	Removes and returns an arbitrary item   |
| `hash_set.union(other_set)` |	Returns a new set with elements from both sets  |
| `hash_set.intersection(other_set)`  |	Returns a new set with elements common to both sets |
| `hash_set.difference(other_set)`    | 	Returns a new set with elements in this set but not in the other    |
| `hash_set.clear()`  |	Removes all items from the set |

##  6. Priority Queue (Min-Heap, Using heapq)

### Definition: 
A binary heap (min-heap by default).

```python
import heapq

heap = []
heapq.heappush(heap, item)  # Push
heapq.heappop(heap)  # Pop (smallest element)
```
### Common Methods:
| Method              | Description                                         |
|---------------------|-----------------------------------------------------|
| `heapq.heappush(heap, item)`    |	Pushes an item onto the heap    |
| `heapq.heappop(heap)`   |	Pops the smallest item from the heap    |
| `heapq.heapify(list)`   |	Converts a list into a heap |
| `heapq.nlargest(n, iterable)`   |	Returns the n largest elements  |
|   `heapq.nsmallest(n, iterable)`    |	Returns the n smallest elements |

## 7. Linked List (Using Custom Class)

### Definition:
A linked list can be implemented using a class with Node objects.

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node

```
### Common Methods:

| Method              | Description                                         |
|---------------------|-----------------------------------------------------|
| `append(data)`  | Adds a node to the end of the linked list.    |
| `delete(data)`  | Removes the node with the specified data. |
| `print_list()`  | Prints all elements in the list.    |

## 8. Deque (Double-ended Queue using collections.deque)

### Definition 
A deque is a generalized version of a queue that supports adding and removing elements from both ends.

```python
from collections import deque

dq = deque()
dq.append(item)  # Add to the right
dq.appendleft(item)  # Add to the left
dq.pop()  # Remove from the right
dq.popleft()  # Remove from the left
```

### Common Methods:
| Method              | Description                                         |
|---------------------|-----------------------------------------------------|
| `dq.append(item)`   |	Adds an item to the right end   |
| `dq.appendleft(item)`   |	Adds an item to the left end    |
| `dq.pop()`  |	Removes and returns the rightmost item  |
| `dq.popleft()`  |	Removes and returns the leftmost item   |
| `dq.clear()`  |	Removes all items from the deque   |

## 9. OrderedDict (Using collections.OrderedDict)

### Definition
A dictionary that remembers the insertion order of keys.

```python
from collections import OrderedDict

od = OrderedDict()
od['key'] = value  # Add key-value pair
```

### Common Methods

| Method              | Description                                         |
|---------------------|-----------------------------------------------------|
|`od.popitem(last=True)` |	Removes and returns the last or first (if last=False) key-value pair    |
| `od.move_to_end(key, last=True)`    |	Moves the key to the end or the beginning (if last=False)   |

## 10. Counter (Using collections.Counter)

### Definition
A dictionary subclass for counting hashable objects.

```Python
from collections import Counter
counter = Counter(iterable)
```

### Common Methods

| Method              | Description                                         |
|---------------------|-----------------------------------------------------|
| `counter.most_common(n)`    |	Returns a list of the n most common elements and their counts   |
| `counter.update(iterable)`  |	Updates the counter with elements from the iterable |
| `counter.subtract(iterable)`  |	Subtracts elements from the iterable    |