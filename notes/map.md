# HashMap: 
most used one. Only one record can has a key of NULL.

std::unordered_map is a hash map

# TreeMap:  
it can store the records in order of key (default: ascending). 
When using a iterator to tranvers a TreeMap, the returned result is ordered. 
Not key can be NULL.

std::map is a tree map, implemented by *red-black tree*

# HashTable: 
Similar to HashMap. 
Both key and value cannot be NULL. 
It supports *synchronization* of multithreads. 
In other word, only one thread can write a HashTable at a given time.

No equivalence in C++

# LinkedHashMap: 

It is a subclass of hash table
Record the order of inputs. 

No equivalence in C++

