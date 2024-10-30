# Python Cheatsheet for DSA

## Table of Contents
> 1. [List (Similar to ArrayList in Java)](#1-list-similar-to-arraylist-in-java)
> 2. [Stack (Using list or collections.deque)](#2-stack-using-list-or-collectionsdeque)
> 3. [Queue (Using collections.deque or queue.Queue)](#3-queue-using-collectionsdeque-or-queuequeue)
> 4. [HashMap (Using dict, Similar to Java HashMap)](#4-hashmap-using-dict-similar-to-java-hashmap)
> 5. [Set (Similar to Java HashSet)](#5-set-similar-to-java-hashset)
> 6. [Priority Queue (Min-Heap, Using heapq)](#6-priority-queue-min-heap-using-heapq)
> 7. [Linked List (Using Custom Class)](#7-linked-list-using-custom-class)
> 8. [Deque (Double-ended Queue using collections.deque)](#8-deque-double-ended-queue-using-collectionsdeque)
> 9. [OrderedDict (Using collections.OrderedDict)](#9-ordereddict-using-collectionsordereddict)
> 10. [Counter (Using collections.Counter)](#10-counter-using-collectionscounter)
> 11. [Math Functions (math Module)](#11-math-functions-math-module)
> 12. [Random Numbers (Using random Module)](#12-random-numbers-using-random-module)
> 13. [Rounding Functions](#13-rounding-functions)

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

## 11. Math Functions (math Module)

First, you need to import the math module:
```Python
import math
```

| Function            | Description                                    | Example                        | Result    |
|---------------------|------------------------------------------------|--------------------------------|-----------|
| `math.sqrt(x)`       | Square root of `x`                             | `math.sqrt(16)`                | `4.0`     |
| `math.pow(x, y)`     | `x` raised to the power `y`                    | `math.pow(2, 3)`               | `8.0`     |
| `math.factorial(x)`  | Factorial of `x` (`x!`)                        | `math.factorial(5)`            | `120`     |
| `math.fabs(x)`       | Absolute value of `x` (float)                  | `math.fabs(-5.3)`              | `5.3`     |
| `math.floor(x)`      | Largest integer less than or equal to `x`      | `math.floor(3.9)`              | `3`       |
| `math.ceil(x)`       | Smallest integer greater than or equal to `x`  | `math.ceil(3.1)`               | `4`       |
| `math.gcd(a, b)`     | Greatest common divisor of `a` and `b`         | `math.gcd(8, 12)`              | `4`       |
| `math.log(x, base)`  | Logarithm of `x` to the given `base`           | `math.log(8, 2)`               | `3.0`     |
| `math.exp(x)`        | Exponential of `x` (`e^x`)                     | `math.exp(2)`                  | `7.389`   |
| `math.degrees(x)`    | Convert radians to degrees                     | `math.degrees(math.pi)`        | `180.0`   |
| `math.radians(x)`    | Convert degrees to radians                     | `math.radians(180)`            | `3.14159` |

## 12. Random Numbers (Using random Module)

```Python
import random
```

| Function                         | Description                                      | Example                            | Result                        |
|---------------------------------- |--------------------------------------------------|------------------------------------ |-------------------------------|
| `random.random()`                 | Returns a random float between 0 and 1           | `random.random()`                  | `0.357` (random float)        |
| `random.randint(a, b)`            | Random integer between `a` and `b` (inclusive)   | `random.randint(1, 10)`            | `5` (random integer)          |
| `random.uniform(a, b)`            | Random float between `a` and `b`                 | `random.uniform(1, 10)`            | `6.3` (random float)          |
| `random.choice(sequence)`         | Random element from a sequence                   | `random.choice([1, 2, 3])`         | `2` (random element)          |
| `random.shuffle(sequence)`        | Shuffle the elements in the sequence in place    | `random.shuffle(my_list)`          | `my_list` is shuffled         |
| `random.sample(sequence, k)`      | Returns `k` random elements from a sequence      | `random.sample([1, 2, 3], 2)`      | `[1, 3]`                      |

## 13. Rounding Functions

| Function        | Description                                  | Example               | Result |
|-----------------|----------------------------------------------|-----------------------|--------|
| `round(x)`      | Rounds `x` to the nearest integer            | `round(3.6)`          | `4`    |
| `round(x, n)`   | Rounds `x` to `n` decimal places             | `round(3.14159, 2)`   | `3.14` |