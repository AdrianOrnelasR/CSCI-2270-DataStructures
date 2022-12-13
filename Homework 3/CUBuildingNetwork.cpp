/****************************************************************/
/*                CUBuildingNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*     This class uses a linked-list of CUBuilding structs to      */
/*     represet communication paths between buildings             */
/****************************************************************/

#include "CUBuildingNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUBuildingNetwork::CUBuildingNetwork() {
    /* finished. do not touch. */
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CUBuildingNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: Add a new building to the network
 *   between the building *previous and the Building that follows it in the network.
 * @param previous name of the Building that comes before the new Building
 * @param buildingName name of the new Building
 * @param numOfroom
 * @return none
 */
void CUBuildingNetwork::addBuildingInfo(CUBuilding* previous, string buildingName, int numOfroom) 
{
    
    //Check if head is Null i.e list is empty
  if(head == NULL)
  {
    head = new CUBuilding;
    head->name = buildingName;
    head->totalRoom = numOfroom;
    head->next = nullptr;
    previous = nullptr;
    cout << "adding: " << buildingName << " (HEAD)" << endl;
  }

  // if list is not empty, look for prev and append our node there
  else if(previous == nullptr)
  {
    CUBuilding* newNode = new CUBuilding;
    newNode->next = head;
    newNode->name = buildingName;
    newNode->totalRoom = numOfroom;
    head = newNode;
    cout << "adding: " << buildingName << " (HEAD)" << endl;
  }

  else{

    CUBuilding* newNode = new CUBuilding;
    newNode->name = buildingName;
    newNode->totalRoom = numOfroom;
    newNode->next = nullptr;
    newNode->next = previous->next;
    previous->next = newNode;
    //cout << "adding: " << buildingName << " (HEAD)" << endl;
    cout<< "adding: "<<buildingName<<" (prev: "<<previous->name << ")" << endl;
    }
}


/*
 * Purpose: populates the network with the predetermined buildings
 * @param none
 * @return none
 */
void CUBuildingNetwork::loadDefaultSetup()
{
    
    addBuildingInfo(NULL, "FLMG", 2);

    addBuildingInfo(head, "DLC", 10);

    addBuildingInfo(head->next, "ECOT", 6);

    addBuildingInfo(head->next->next, "CASE", 5);

    addBuildingInfo(head->next->next->next, "AERO", 4);

    addBuildingInfo(head->next->next->next->next, "RGNT", 9);
}
/*
 * Purpose: Search the network for the specified building and return a pointer to that node
 * @param buildingName name of the building to look for in network
 * @return pointer to node of buildingName, or NULL if not found
 *
 */
CUBuilding* CUBuildingNetwork::searchForBuilding(string buildingName)
{
    CUBuilding* newnode = head;
    while(newnode->name != buildingName && newnode != nullptr)
    {
        newnode = newnode->next;
        
    }
    if(head == nullptr)
    {
        return newnode;
    }
    
    return newnode;
    
}

/*
 * Purpose:
 * @param string receiver
 * @param string msg
 */
void CUBuildingNetwork::transmitRoomInfo(string receiver) 
{
    CUBuilding *pH;
    pH = head;
    
    CUBuilding *pH2;
    pH2 = head;
    
    while(pH2->name != receiver && pH2 != NULL)
    {

        pH2 = pH2->next;
        if(pH2 == NULL)
        {
            cout << "Building not found" << endl;
            return;
        }
    }
    
    

    while(pH->name != receiver && pH != NULL)
        {
            pH->numberMessages = pH->numberMessages + 1;
            pH->message = "available room at "+ pH->name +" is " +  to_string(pH->totalRoom);
            cout << pH->name << " [# messages received: "<< pH->numberMessages << "] received: "<< pH->message << endl;
            pH = pH->next;
            
        }
            if(pH == NULL)
            {
                cout << "Empty list" << endl;
            }
            if(pH->name == receiver)
            {
                pH->numberMessages = pH->numberMessages + 1;
                pH->message = "available room at "+ pH->name +" is " +  to_string(pH->totalRoom);
                cout << pH->name << " [# messages received: "<< pH->numberMessages << "] received: "<< pH->message << endl;
            }
    
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CUBuildingNetwork::printNetwork() 
{
    CUBuilding* newnode = head;
    cout << "== CURRENT PATH ==" << endl;
    while(newnode != NULL)
    {
        cout << newnode->name << "(" <<newnode->totalRoom << ")" << " -> ";
        newnode = newnode->next;
    }
    cout << "NULL" << endl;
    cout << "===" << endl;
}
