#include "hashquad.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;
 
  
    HashTable::HashTable(int bsize)// Constructor
    {
        tableSize = bsize;  // No. of buckets (linked lists)

        // Pointer to an array containing buckets
        table = new int[tableSize];
        
        for(int i = 0; i < tableSize; i++)
        {
            table[i] = (-1);
        }

        int numOfcolision = 0;
    
    } 

    // inserts a key into hash table
    bool HashTable::insert(int key)
    {
        //h(x) = x % m;
        int loop = hashFunction(key);
        
        if(table[loop] == -1)
        {
            table[loop] = key;
            //cout <<"first try bitch" << endl;
            return true;

        }
        else
        {
            int track = 1;
            //cout << "reached";
            numOfcolision += 1;
            int quad = track*track;

            for(int i = (loop + quad) % tableSize; i != loop; i = (i + quad) % tableSize)
            {
                if(table[i] == -1)
                {
                    //cout << "out";
                    table[i] = key;
                    return true;
                }
                track++;
                quad = track*track; 
            }
           
           return false;
        }
    }

   

    // hash function to map values to key
    unsigned int HashTable::hashFunction(int key)
    {
        return (key % tableSize);
    }

    void HashTable::printTable()
    {
        for(int i = 0; i < tableSize; i++)
        {
            if(table[i] != -1)
            {
                cout << table[i] << ", ";
            }
            
        }
    }
    
    int HashTable::getNumOfCollision()
    {
        return numOfcolision;
    }

    int HashTable::search_index(int idex)
    {
        if(table[idex] != -1)
        {
            return table[idex];
        }
        else
        {
            while(table[idex] == -1)
            {
                idex++;
            }
            return table[idex];
        }
        
        
    }

    int HashTable::search(int key)
    {
        
        int index = hashFunction(key);
        if(table[index] == key)
        {
            //cout << "found at correct index: " << endl;
            return index;
        }
        else
        {
            int track = 1;
            int quad = track*track;
            for(int i = (index + quad) % tableSize; i != index; i = (i + quad) % tableSize)
            {
                if(table[i] == key)
                {
                    return key;
                }
            }
            //start = start - index;
            //cout << "found " << start << " away from index.";
            return index;
        }

    }