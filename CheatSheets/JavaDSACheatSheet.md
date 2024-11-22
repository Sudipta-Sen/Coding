# Java Cheatsheet for DSA

## Table of Contents
> 1. [Java Collection Framework Overview](#1-java-collection-framework-overview)
> 2. [Collections Class (Utility Methods for Collections)](#2-collections-class-utility-methods-for-collections)
> 3. [String Class](#3-string-class)
> 4. [Arrays](#4-arrays)
> 5. [Custom Sort](#5-custom-sort)
> 6. [lower_bound using binarySearch](#6-lower_bound-using-binarysearch)
> 7. [String builder](#7-string-builder)
> 8. [Priority Queue](#8-priority-queue)

## 1. Java Collection Framework Overview
![plot](JavaCollection.svg)

## 2. Collections Class (Utility Methods for Collections)

| **Method** |	**Description** |	**Example** | **Output** |
| ------ | ------------ | ----------| ------ |
| `sort(List<T> list)` |	Sorts the list in ascending order.	| `Collections.sort(list)` |	`[1, 2, 3]` |
| `reverse(List<T> list)` | Reverses the elements in the | `list.Collections.reverse(list)`	| `[3, 2, 1]` |
| `shuffle(List<T> list)` |	Shuffles the elements randomly |	`Collections.shuffle(list)` |	Random order |
| `binarySearch(List<T> list, T key)` |	Searches for key in a sorted list |	`Collections.binarySearch(list, 2)` |	Index of key |
| `min(Collection<T> c)` | Returns the smallest element |`Collections.min(list)`	| Smallest element |
| `max(Collection<T> c)` |	Returns the largest element |	`Collections.max(list)`	| Largest element |
| `frequency(Collection<T> c, Object o)` |	Returns the frequency of o |	`Collections.frequency(list, 1)` |	Count of 1 |

binarySearch returns -- 
- rightmost index of the element if found
- -(insertion_point + 1), where the insertion_point is where the element could be inserted if not found 

```Java
List<Integer> list = Arrays.asList(3, 1, 2);
Collections.sort(list);
System.out.println(list);  // Output: [1, 2, 3]

int index = Collections.binarySearch(list, 2);
System.out.println(index);  // Output: 1
```

## 3. String Class
| Method | Description | Example | Output |
| ------ | ----------- | ------- | ------ |
| `charAt(int index)` |	Returns the character at the index. |	"abc".charAt(1) |	`b` |
| `substring(int beginIndex, int endIndex)`	| Returns substring. |	"abcdef".substring(1, 4) |	`bcd` |
| `indexOf(String str)`	| Returns the index of the first occurrence |	"abcabc".indexOf("b")	| `1` |
| `split(String regex)` |	Splits the string into an array. |	"a,b,c".split(",") |	`["a", "b", "c"]` |
| `replace(char oldChar, char newChar)`	| Replaces all occurrences of oldChar. |	"abc".replace('a', 'x') |	`xbc` |
| `toCharArray()` | converts `string` into `char[]`, which is iterable using `for-each` loop | Example below | |

```Java
String s = "hello";

for (char ch : s.toCharArray()) {
    System.out.println(ch);  // output: 'h', 'e', 'l', 'l', 'o'
}
```
## 4. Arrays

### Methods from java.util.Arrays Class

| Method | Description |
| ------ | ----------- |
| `Arrays.toString(array)` |	Returns a string representation of the array. |
| `Arrays.sort(array)` |	Sorts the array in ascending order.|
| `Arrays.binarySearch(array, key)` |	Performs binary search |and returns the index of the element. |
| `Arrays.copyOf(array, newLength)` | Copies the array and returns a new array with the specified length. |
| `Arrays.fill(array, value)`	| Fills the array with the specified value. |
| `Arrays.equals(array1, array2)` |	Checks if two arrays are equal. |
| `Arrays.deepToString(array)` |	Converts a multi-dimensional array to a string. |
| `Arrays.asList(array)` |	Converts the array into a List, It does not work as expected with primitive arrays |

## 5. Custom Sort
We can write our custom sort function to sort Array or List

```Java
public class Main {
    public static void main(String[] args) {
        List<String> list = Arrays.asList("apple", "banana", "pear", "grape");

        // Sort by string length using Comparator
        Collections.sort(list, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                return Integer.compare(s1.length(), s2.length());  // Ascending by length
            }
        });

        System.out.println(list);  // Output: [pear, apple, grape, banana]
    }
}
```

The same thing can also be written as -- 

```Java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<String> list = Arrays.asList("apple", "banana", "pear", "grape");

        // Sort by string length using custom comparator function
        Collections.sort(list, Main::compareByLength);

        System.out.println(list);  // Output: [pear, apple, grape, banana]
    }

    // Custom comparator method to compare by string length
    public static int compareByLength(String s1, String s2) {
        return Integer.compare(s1.length(), s2.length());  // Ascending by length
    }
}

```

## 6. lower_bound using binarySearch
Java does not have a specific lower_bound method in java but we can implement it using `binarySearch()`

```Java
public void example(String[] args) {
    List<Integer> list = Arrays.asList(1, 3, 3, 5, 7, 9);

    int lb1 = lowerBound(list, 6);
    System.out.println(lb1) // Output: 4
    int lb2 = lowerBound(list, 3);
    System.out.println(lb2) // Output: 2

}

public static int lowerBound(List<Integer> list, int value) {
    int index = Collections.binarySearch(list, value);

    // If index is negative, binarySearch returns -(insertion_point + 1)
    if (index < 0) {
        index = -(index + 1);  // This gives us the insertion point
    }
    return index;  // This is the lower bound index
}
```

## 7. String builder
The `StringBuilder` class in Java is used to create mutable (modifiable) sequences of characters, which makes it more efficient for scenarios where a lot of string manipulation is needed.

`StringBuilder` is not thread-safe. `StringBuffer` is a thread safe vesion of `StringBuilder`.

### StringBuilder vs String

- **String:** Immutable. Each time you modify a string, a new object is created, and the old string gets copied to the new object with the modifications. This inefficient in performance and memory.

- **StringBuilder:** Mutable. String modifications happen in the same object, so it is more efficient for cases where many modifications are required

### Intialization
```Java
StringBuilder sb = new StringBuilder();           // Creates an empty StringBuilder
StringBuilder sb = new StringBuilder("Hello");    // Creates a StringBuilder with initial content
```
### Key Methods
| Method |Description | Example | Output/Result |
|------- |----------- |---------| --------------|
| `append(String s)`                        | Appends string `s` to the end of the `StringBuilder`.     | `sb.append(" World");`                              | `Hello World`        |
| `insert(int offset, String s)`            | Inserts string `s` at the specified index.                | `sb.insert(5, " Java");`                            | `Hello Java World`   |
| `replace(int start, int end, String s)`   | Replaces the substring from `start` to `end` with `s`.    | `sb.replace(6, 10, "C++");`                         | `Hello C++ World`    |
| `delete(int start, int end)`              | Deletes characters from `start` to `end`.                 | `sb.delete(5, 10);`                                 | `Hello World`        |
| `deleteCharAt(int index)`                 | Deletes the character at the specified index.             | `sb.deleteCharAt(5);`                               | `HelloWorld`         |
| `reverse()`                               | Reverses the entire string.                               | `sb.reverse();`                                     | `dlroW olleH`        |
| `setCharAt(int index, char ch)`           | Changes the character at the specified index to `ch`.     | `sb.setCharAt(0, 'h');`                             | `hello World`        |
| `substring(int start)`                    | Returns substring from `start` to the end.                | `sb.substring(6);`                                  | `World`              |
| `substring(int start, int end)`           | Returns substring from `start` to `end`.                  | `sb.substring(0, 5);`                               | `Hello`              |
| `charAt(int index)`                       | Returns the character at the specified index.             | `sb.charAt(1);`                                     | `e`                  |
| `length()`                                | Returns the length of the `StringBuilder`.                | `sb.length();`                                      | `11`                 |
| `capacity()`                              | Returns the current capacity of the `StringBuilder`.      | `sb.capacity();`                                    | Varies               |
| `ensureCapacity(int minimumCapacity)`     | Ensures that the capacity is at least `minimumCapacity`.  | `sb.ensureCapacity(50);`                            | Adjusts capacity     |
| `trimToSize()`                            | Reduces the storage size to the current content size.     | `sb.trimToSize();`                                  | Adjusts capacity     |
| `toString` | Return string from the string builder object | `sb.toString()` ||

### Usage Examples

1. Appending Strings
```Java
StringBuilder sb = new StringBuilder("Hello");
sb.append(" World");
System.out.println(sb);  // Output: Hello World
```

2. Inserting a Substring
```Java
StringBuilder sb = new StringBuilder("Hello World");
sb.insert(5, " Java");
System.out.println(sb);  // Output: Hello Java World
```

3. Replacing a Substring
```Java
StringBuilder sb = new StringBuilder("Hello World");
sb.replace(6, 11, "Java");
System.out.println(sb);  // Output: Hello Java
```

4. Deleting a Substring
```Java
StringBuilder sb = new StringBuilder("Hello Java World");
sb.delete(5, 10);
System.out.println(sb);  // Output: Hello World
```

5. Reversing the String
```Java
StringBuilder sb = new StringBuilder("Hello World");
sb.reverse();
System.out.println(sb);  // Output: dlroW olleH
```

6. Modifying a Character
```Java
StringBuilder sb = new StringBuilder("Hello World");
sb.setCharAt(6, 'J');
System.out.println(sb);  // Output: Hello Jorld
```

## 8. Priority Queue

### a. Min heap
we use the `PriorityQueue` class from `java.util` for priority queues. By `default`, it behaves as a `min-heap`. For a max-heap, we can pass a custom comparator.

```java
import java.util.PriorityQueue;

PriorityQueue<Integer> minHeap = new PriorityQueue<>();

// Add elements
minHeap.offer(10);
minHeap.offer(5);
minHeap.offer(20);

// Peek the smallest element
System.out.println(minHeap.peek()); // Output: 5

// Pop the smallest element
System.out.println(minHeap.poll()); // Output: 5
```

### b. Max heap

```Java
import java.util.Collections;
import java.util.PriorityQueue;

public class MaxHeapExample {
    public static void main(String[] args) {
        // Initialize a max-heap using Collections.reverseOrder()
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        // Add elements
        maxHeap.offer(10);
        maxHeap.offer(5);
        maxHeap.offer(20);

        // Peek the largest element
        System.out.println(maxHeap.peek()); // Output: 20

        // Pop the largest element
        System.out.println(maxHeap.poll()); // Output: 20
    }
}
```

### Key Functions
| Function | Description |
| -------- | ----------- |
| `offer(element)` | Adds an element to the priority queue. |
| `poll()` | Removes and returns the top element (smallest or largest). |
| `peek()` | Retrieves, but does not remove, the top element. |
| `size()` |	Returns the number of elements in the queue. |
| `isEmpty()` |	Returns true if the queue is empty. |

### c. Custom Comparator
####  Custom Comparator Using a Lambda Expression
```Java
import java.util.PriorityQueue;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        // Custom comparator for descending order
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);

        // Adding elements
        pq.add(10);
        pq.add(20);
        pq.add(15);

        while (!pq.isEmpty()) {
            System.out.println(pq.poll());  // Output: 20, 15, 10
        }
    }
}
```

#### Using a Static Method in the Same Class
```Java
import java.util.PriorityQueue;
import java.util.Comparator;

public class Main {
    
    // Static method acting as a comparator
    public static int customComparator(Integer a, Integer b) {
        return b - a;  // Descending order
    }

    public static void main(String[] args) {
        // Using the static method as a custom comparator
        PriorityQueue<Integer> pq = new PriorityQueue<>(Main::customComparator);

        pq.add(10);
        pq.add(20);
        pq.add(15);

        // Polling elements from the priority queue
        while (!pq.isEmpty()) {
            System.out.println(pq.poll());  // Output: 20, 15, 10
        }
    }
}
```
####  Using an Anonymous Class
```Java
import java.util.PriorityQueue;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        // Custom comparator for descending order
        PriorityQueue<Integer> pq = new PriorityQueue<>(new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return b - a; // Reverse order
            }
        });

        // Adding elements
        pq.add(10);
        pq.add(20);
        pq.add(15);

        // Polling elements from priority queue
        while (!pq.isEmpty()) {
            System.out.println(pq.poll());  // Output: 20, 15, 10
        }
    }
}
```

####  Custom Comparator for Complex Objects
```Java
import java.util.PriorityQueue;
import java.util.Comparator;

class Person {
    String name;
    int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return name + " (" + age + ")";
    }
}

public class Main {
    public static void main(String[] args) {
        // Custom comparator to sort people by age in ascending order
        PriorityQueue<Person> pq = new PriorityQueue<>(new Comparator<Person>() {
            @Override
            public int compare(Person p1, Person p2) {
                return p1.age - p2.age;
            }
        });

        // Adding Person objects to the PriorityQueue
        pq.add(new Person("Alice", 30));
        pq.add(new Person("Bob", 25));
        pq.add(new Person("Charlie", 35));

        // Polling elements from priority queue
        while (!pq.isEmpty()) {
            System.out.println(pq.poll());
        }
        // Output: Bob (25), Alice (30), Charlie (35)
    }
}
```