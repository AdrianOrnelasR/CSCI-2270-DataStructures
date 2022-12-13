#ifndef DLL_HPP
#define DLL_HPP

#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *next;       // pointer to the next country
    Node *prev;

};

// class for storing and manipulating linked-list of countries
class MedTracker{
    private:
        Node* head;  // pointer to head of linked list of cities

    public:
        // You will need to define the below unfinished methods in CUBuildingNetwork.cpp
        MedTracker();

        void insert(Node* previous, int id);

        Node* search(int id);

        int search_index(int idex);

        void display();
};

#endif