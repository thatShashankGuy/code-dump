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




/**
 * @brief  HOW TO IMPLEMENT HASH TABLE 
 *   1. Create an array of structure, data (i.e a hash table).
  *  2. Take a key to be stored in hash table as input.
  *  3. Corresponding to the key, an index will be generated.
  *  4. In case of absence of data in that index of array, create one and insert the data item (key and value) into it and increment the size of hash table.
  *  5. In case the data already exists, the new data cannot be inserted if the already present data does not match given key.
  *  6. To display all the elements of hash table, data at each index is extracted and elements (key and value) are read and printed.
  *  7. To remove a key from hash table, we will first calculate its index and extract its data, delete the key in case it matches the given key.
  *  8. Exit
 */
#include<stdio.h>
#include<stdlib.h>


/**
 * @brief DEFINE HASH FUNCTION HASH ITEMS AND HASH TABLES 
 * 
 */
#define CAPACITY  300 ;
typedef struct HT ht_item;
typedef struct HASHT Hash_table;

/**
 * @brief ht_item will have two properties key and corresponding values 
 * 
 */
struct ht_item
{
    char* key ;
    char* value;

};

/**
 * @brief Hashtable have key-value data (ht_item ) and size and count methods 
 * 
 */

struct Hash_table{
    ht_item** ht_item;
    int size;
    int count;
};



unsigned long Hash_Function(char *str){
    unsigned long i = 0 ;
       
       for(int j = 0 ; str[j]; j++ ){
            i += str[j];
       }

       return i % CAPACITY;
}


/**
 * @brief CREATE HASH TABLE FROM DEFINATIONS 
 * 
 * 
 */



int main(){

    return 0 ;
}

