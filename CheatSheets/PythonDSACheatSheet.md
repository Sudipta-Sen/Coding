# Python Cheatsheet for DSA

## Table of Contents
> 1. [List (Similar to ArrayList in Java)](#1-list-similar-to-arraylist-in-java)
> 2. [Stack (Using list or collections.deque)](#2-stack-using-list-or-collectionsdeque)
> 3. [Queue (Using collections.deque or queue.Queue)](#3-queue-using-collectionsdeque-or-queuequeue)
> 4. [HashMap (Using dict, Similar to Java HashMap)](#4-hashmap-using-dict-similar-to-java-hashmap)
> 5. [Set (Similar to Java HashSet)](#5-set-similar-to-java-hashset)
> 6. [Priority Queue (Using heapq)](#6-priority-queue-using-heapq)
> 7. [Linked List (Using Custom Class)](#7-linked-list-using-custom-class)
> 8. [Deque (Double-ended Queue using collections.deque)](#8-deque-double-ended-queue-using-collectionsdeque)
> 9. [OrderedDict (Using collections.OrderedDict)](#9-ordereddict-using-collectionsordereddict)
> 10. [Counter (Using collections.Counter)](#10-counter-using-collectionscounter)
> 11. [Math Functions (math Module)](#11-math-functions-math-module)
> 12. [Random Numbers (Using random Module)](#12-random-numbers-using-random-module)
> 13. [Rounding Functions](#13-rounding-functions)
> 14. [Binary Search](#14-binary-search)
> 15. [Customize sort function](#15-customize-sort-function)
> 16. [String Basics](#16-string-basics)

##  1. List (Similar to ArrayList in Java)

### Definition: Dynamic array, allows resizing and various operations.

```python
lst = []  # Empty list
```

### Create 2D List
```Python
rows = 3
cols = 4
dp = []
for _ in range(rows):
    dp.append([0]*cols)
print(dp) # Output -- [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]

# Oneliner
dp = [[4]*cols]*rows # Output -- [[4, 4, 4, 4], [4, 4, 4, 4], [4, 4, 4, 4]] 
print(dp)

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
| `lst.sort(reverse, key)`         | Take two optional keyword arguments -  <ul><li>`reverse` - By default `False`. If `True` is passed, the list is sorted in `descending` order.</li><li>`key` - Comparion is based on this function</li>                           |
| `lst.reverse()`      | Reverses the list in place                      |

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
length = queue.qsize() # length of queue, buildin len() func does not work with queue 
```

### Workaround for Peeking in queue.Queue

`queue` module does not have a built-in `peek` feature. We have few options to get the `peek` functionality.

- Use a custom wrapper around the `queue.Queue` class that keeps track of the front element.
- Use a `deque` from the `collections` module (as `queue`), which does allow direct access to elements.


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

##  6. Priority Queue (Using heapq)

### Min heap: 
A binary heap (min-heap by default).

```python
import heapq

heap = []
heapq.heappush(heap, item)  # Push
heapq.heappop(heap)  # Pop (smallest element)
```

### Max heap:
There are two ways to implement max heap in python
- Custom Wrapper Class
- Implemented by negating values

#### Custom Wrapper Class
Define custom wrapper class to handle comparisons and create a max-heap by overriding the comparison methods.

```Python
import heapq

class MaxHeapObj:
    def __init__(self, val):
        self.val = val

    # Define comparison operators to create a max-heap
    def __lt__(self, other):
        return self.val > other.val  # Reverse the comparison for max-heap

    def __eq__(self, other):
        return self.val == other.val

    def __str__(self):
        return str(self.val)

# Example of max-heap without negation
max_heap = []
heapq.heappush(max_heap, MaxHeapObj(10))
heapq.heappush(max_heap, MaxHeapObj(20))
heapq.heappush(max_heap, MaxHeapObj(5))

# Extracting the maximum element
print(heapq.heappop(max_heap))  # Output: 20
print(heapq.heappop(max_heap))  # Output: 10
print(heapq.heappop(max_heap))  # Output: 5

```

#### Implemented by negating values
```Python
import heapq

# Initialize an empty max-heap by negating values
max_heap = []

# Add elements (negate the value)
heapq.heappush(max_heap, -10)
heapq.heappush(max_heap, -5)
heapq.heappush(max_heap, -20)

# Pop the largest element (negate to get original value)
max_element = -heapq.heappop(max_heap)  # Returns 20

# Peek at the largest element without popping
max_element = -max_heap[0]

# Convert a list to a max-heap
heap = [10, 5, 20]
heapq.heapify([-x for x in heap])  # Store as negatives for max-heap

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
| `len(dq)`| length of dequeue, build in len() func works with queue |

### How to "Peek" in a deque

- Peek at the front: access the first element without removing it using deque[0].

- Peek at the back: access the last element without removing it using deque[-1]

```Python
from collections import deque

queue = deque([10, 20, 30, 40])

front_peek = queue[0]
print(f"Peek at front: {front_peek}")  # Output: 10

back_peek = queue[-1]
print(f"Peek at back: {back_peek}")    # Output: 40
```

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

## 14. Binary Search

bisect module is used to perform binary search on sorted sequence.

### Common Methods

| Syntax    | Description   |   Time Complexity |
|-----------|---------------|-------------------|
| `bisect_left(sorted_list, x, lo=0, hi=len(sorted_list))` |  Returns the index where to insert `x` into a sorted list. If `x` already exists in list, it returns the index of the first occurrence. | O(logn) |
| `bisect_right(sorted_list, x, lo=0, hi=len(sorted_list))` | Similar to `bisect_left`, but returns the index where you can insert an element `x` in the list to the right of any existing entries of `x`. | O(logn) |
| `insort_left(sorted_list, x, lo=0, hi=len(sorted_list))` | Inserts `x` into the sorted list at the position found by `bisect_left` | O(logn) |
| `insort_right(sorted_list, x, lo=0, hi=len(sorted_list))` | Inserts `x` into the sorted list at the position found by `bisect_right` | O(logn) |

```Python
import bisect

arr = [1, 3, 4, 4, 5, 7, 9]

# Find the insertion point of 4
index = bisect.bisect_left(arr, 4)
print(index)  # Output: 2

index = bisect.bisect_right(arr, 4)
print(index)  # Output: 4

bisect.insort_left(arr, 6)
print(arr)  # Output: [1, 3, 4, 4, 5, 6, 7, 9]

bisect.insort_right(arr, 4)
print(arr)  # Output: [1, 3, 4, 4, 4, 5, 7, 9]
```

## 15. Customize sort function 

### Sorting Based on a Custom Key

You can define a custom key function to determine the sort order. For example, sorting a list of tuples based on the second element of each tuple.

```Python
# List of tuples
data = [(1, 'apple'), (3, 'banana'), (2, 'orange')]

# Sort by the second element (string) in each tuple
sorted_data = sorted(data, key=lambda x: x[1])

print(sorted_data)  # Output: [(1, 'apple'), (3, 'banana'), (2, 'orange')]
```

### Sorting in Descending Order
By default, sorted() sorts in ascending order. To sort in descending order, set reverse=True

```Python
numbers = [3, 1, 4, 1, 5, 9]
# Sort in descending order
sorted_numbers = sorted(numbers, reverse=True)

print(sorted_numbers)  # Output: [9, 5, 4, 3, 1, 1]
```

### Custom Sort Based on Absolute Value

```Python
nums = [-10, 7, -3, 4, -8]

# Sort by absolute value
sorted_nums = sorted(nums, key=abs)

print(sorted_nums)  # Output: [-3, 4, 7, -8, -10]
```

### Sorting Strings by Length
```Python
words = ['banana', 'apple', 'grape', 'blueberry', 'kiwi']

# Sort by length of the string
sorted_words = sorted(words, key=len)

print(sorted_words)  # Output: ['kiwi', 'apple', 'grape', 'banana', 'blueberry']
```

### Partial sort of an array
```Python
nums = [3,16,8,4,2]
nums[0:3] = sorted(nums[0:3])
print(nums) # Output: [3, 8, 16, 4, 2]
``` 

### Custom Comparator Using functools.cmp_to_key

A comparator function compares two elements (x and y) at a time and returns:
1. A negative number if x should come before y.
2. A positive number if x should come after y.
3. Zero if x and y are considered equal.

```Python
import functools
 
l = [6, 8, 10, 23, -4, -7]
 
def compare(x, y):
    return x ** 3 - y ** 3
 
sorted_l = sorted(l, key=functools.cmp_to_key(compare))
print(sorted_l) # Output: [-7, -4, 6, 8, 10, 23]
print(l) # Output: [6, 8, 10, 23, -4, -7]
```

### Sorting a List of Dictionaries

```Python
people = [{'name': 'John', 'age': 45},
          {'name': 'Alice', 'age': 30},
          {'name': 'Bob', 'age': 35}]

# Sort by age
sorted_people = sorted(people, key=lambda x: x['age'])

print(sorted_people)
# Output: [{'name': 'Alice', 'age': 30}, {'name': 'Bob', 'age': 35}, {'name': 'John', 'age': 45}]
```

## 16. String basics

## Accessing Characters
```Python
s = "Hello, World!"

# Slicing
s[0:5]    # 'Hello'
s[:5]     # 'Hello' (same as above)
s[7:]     # 'World!'
s[-6:]    # 'World!'

# Length of the string
len(s)    # 13
```

## Common String Methods
```Python
# Upper and lower case
s.upper()                # 'HELLO, WORLD!'
s.lower()                # 'hello, world!'
s.capitalize()           # 'Hello, world!'

# String splitting and joining
s.split()                # ['Hello,', 'World!']
s.split(',')             # ['Hello', ' World!']
'-'.join(['Hello', 'World'])  # 'Hello-World'

# Remove whitespace
s.strip()                # Removes leading/trailing whitespace
s.lstrip()               # Removes leading whitespace
s.rstrip()               # Removes trailing whitespace

# Replace part of a string
s.replace('World', 'Everyone')  # 'Hello, Everyone!'

# Find substring
s.find('World')          # 7  (Returns index of substring, -1 if not found)
s.rfind('o')             # 8  (Last occurrence of 'o')

# Check string starts/ends
s.startswith('Hello')    # True
s.endswith('!')          # True
```

### ord() and chr() Functions
- `ord(char):` Returns the Unicode code point (integer) for a given character.
- `chr(int):` Converts an integer (Unicode code point) to its corresponding character.

```Python
# ord() examples
ord('a')  # 97
ord('A')  # 65
ord('!')  # 33

# chr() examples
chr(97)   # 'a'
chr(65)   # 'A'
chr(33)   # '!'
```

### Check for Content
```Python
# Check if string contains substring
'World' in s              # True
'Python' in s             # False

# Check if string is alphanumeric, digits, or alphabetic
s.isalnum()               # False (space and punctuation aren't alphanumeric)
'Hello123'.isalnum()      # True
'123'.isdigit()           # True
'abc'.isalpha()           # True
```