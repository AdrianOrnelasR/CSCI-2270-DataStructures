#include "bubblesort.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

MedTracker::MedTracker()
{
    head = NULL;
}

void MedTracker::insert(Node* previous, int id)
{
    if(head == NULL)
    {
        head = new Node;
        head->key = id;
        head->next = nullptr;
        head->prev = nullptr;
        previous = nullptr;
    }

    // if list is not empty, look for prev and append our node there
    else if(previous == nullptr)
    {
        Node* newNode = new Node;
        newNode->next = head;
        newNode->prev = nullptr;
        newNode->key = id;
        head = newNode;
    }

    else
    {

        Node* newNode = new Node;
        newNode->key = id;
        newNode->next = nullptr;
        newNode->next = previous->next;
        newNode->prev = previous->prev;
        previous->next = newNode;
    }
}

Node* MedTracker::search(int id)
{
    Node* newnode = head;

    int tempid = id;
    int idlengthh = 0;

    while(tempid > 0)
    {
        tempid = tempid/10;
        idlengthh++;
    }

    if(idlengthh != 5)
    {
        return nullptr;
    }
    
    else
    {
        while(newnode->key != id && newnode != nullptr)
        {
            newnode = newnode->next;
            
        }
        if(head == nullptr)
        {
            return nullptr;
        }
        
    }
    return newnode;
}

int MedTracker::search_index(int idex)
{
    auto startss = chrono::steady_clock::now();

    Node* newnode = head;

    for(int i = 0; i < idex; i++)
    {
        newnode = newnode->next;
    }
    
    auto endss = chrono::steady_clock::now();
    
    int temp = duration_cast<microseconds>(endss-startss).count();

    return temp;
}

void MedTracker::display()
{
    Node* newnode = head;
    cout << "heres the list: " << endl;
    while(newnode != NULL)
    {
        cout << newnode->key << " -> ";
        newnode = newnode->next;
    }
    cout << "NULL" << endl;
}

void MedTracker::Bubblesort()
{
    int swapped; 
    struct Node *ptr; 
    struct Node *pre = NULL; 
   
    Node *start = head;
    do
    { 
        swapped = 0; 
        ptr = start; 
   
        while (ptr->next != pre) 
        { 
            if (ptr->key > ptr->next->key) 
            {  
                //struct Node *temp = ptr;
                //ptr = ptr->next;
                //ptr->next = temp;
                swap(ptr->key, ptr->next->key); 
                swapped = 1; 
            } 
            ptr = ptr->next; 
        } 
        pre = ptr; 
    } 
    while(swapped); 
}