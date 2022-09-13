/**
 * @file hashtable.c
 * @author thatshashankguy
 * @brief Full hash table implementation in C 
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */




/**The whole benefit of using a Hash Table is due to it’s very fast access time. While there can be a collision, if we choose a very good hash function, this chance is almost zero.

So, on average, the time complexity is a constant O(1) access time. This is called Amortized Time Complexity.

The C++ STL (Standard Template Library) has the std::unordered_map() data structure which implements all these hash table functions.

However, knowing how to construct a hash table from scratch is a crucial skill, and that is indeed what we aim to show you.

Let us understand more about the implementation details.

Any Hash Table implementation has the following three components:

    A good Hash function to map keys to values
    A Hash Table Data Structure that supports insert, search and delete operations.
    A Data Structure to account for collision of keys*/
