# Java Cheatsheet for DSA

## Table of Contents
> 1. [Java Collection Framework Overview](#1-java-collection-framework-overview)
> 2. [Collections Class (Utility Methods for Collections)](#2-collections-class-utility-methods-for-collections)
> 3. [String Class](#3-string-class)
> 4. [Arrays](#4-arrays)
> 5. [Custom Sort](#5-custom-sort)

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
| `max(Collection<T> c)` |	Returns the largest element |	Collections.max(list)	| Largest element |
| `frequency(Collection<T> c, Object o)` |	Returns the frequency of o |	Collections.frequency(list, 1) |	Count of 1 |

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
| `Arrays.asList(array)` |	Converts the array into a List |

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