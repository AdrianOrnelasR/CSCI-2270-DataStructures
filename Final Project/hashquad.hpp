#ifndef HASHQUAD_HPP
#define HASHQUAD_HPP

using namespace std;

class HashTable
{
    int tableSize;  // No. of buckets (linked lists)

    // Pointer to an array containing buckets
    int *table;

    int numOfcolision = 0;

public:
    HashTable(int bsize);  // Constructor
    
    // inserts a key into hash table
    bool insert(int key);

    int search_index(int idex);

    // hash function to map values to key
    unsigned int hashFunction(int key);

    void printTable();
    
    int getNumOfCollision();

    int search(int key);
};

#endif