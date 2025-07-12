#  Mini Project 3 – Dictionary Based on Hash Table

This project features custom implementations of different **hash table** variants in **C++**, with performance evaluation of key operations.

---

##  Project Topic: Dictionary Using Hash Table

A **dictionary** is an abstract data structure designed to store key-value pairs.

A **hash table** is a common data structure used to implement dictionaries. It maps keys to indices (buckets) using a hash function. Since the key space is typically much larger than the number of buckets, **collisions** occur when multiple keys map to the same bucket. Two main collision resolution methods are:

- **Chaining** (buckets with linked lists)
- **Open addressing** (probing techniques)

More advanced variations include:
- Hash table with open addressing plus balanced BST buckets
- Hash table with Cuckoo hashing

---

##  Implemented Variants

  - Separate chaining with linked lists
  - Open addressing (linear/quadratic probing)
  - Hash table with AVL tree buckets

---

##  Analyzed Operations

| Operation | Description                                      |
|-----------|------------------------------------------------|
| `insert()`| Inserts a new key-value pair into the dictionary |
| `remove()`| Removes the pair associated with a given key   |

---


