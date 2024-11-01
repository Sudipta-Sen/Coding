# Java Cheatsheet for DSA

## Table of Contents
> 1. [Java Collection Framework Overview](#1-java-collection-framework-overview)
> 2. [Collections Class (Utility Methods for Collections)](#2-collections-class-utility-methods-for-collections)
> 3. [String Class](#3-string-class)

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

```Python
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