#include "heapsort.hpp"
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
        bool theturn = true;
        int loop = hashFunction(key);
    
        if(table[loop] == -1)
        {
            table[loop] = key;
            theturn = true;
        }
        else
        {
            while(table[loop] != -1)
            {
                loop++;
                numOfcolision += 1;
            }
            table[loop] = key;
            
            /*
            int tmp = table[index];
            while(tmp != nullptr)
            {
                tmp = tmp.next;
            }
            tmp = table[index];
            hashElement.next = tmp;
            hashElement.previous = tmp.previous;
            tmp.previous.next = hashElement;
            tmp.previous = hashElement;
            */
           theturn = false;
        }
        return theturn;
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
            int start = index;
            while(table[index] != -1 && table[index] == key)
            {
                index++;
                //numOfcolision += 1;
                
            }
            start = start - index;
            //cout << "found " << start << " away from index.";
            return index;
        }

    }
    void HashTable::mineHeap(int passed) 
    { 
        int smallest = passed;
        int parent = (passed-1)/2;
        int left = (2*passed) + 1; 
        int right = (2*passed) + 2; 
    
        
        if (left > tableSize && table[left] < table[smallest])
        {
            parent = table[left - 1];
            smallest = left; 
        }
        if (right > tableSize && table[right] < table[smallest])
        {
            parent = table[right - 1];
            smallest = right; 
        } 
        if (smallest != passed) 
        { 
            int temp = table[passed];
            table[passed] = table[smallest];
            table[smallest] = temp;
            parent = table[smallest - 1];
            mineHeap(smallest); 
        } 
    } 