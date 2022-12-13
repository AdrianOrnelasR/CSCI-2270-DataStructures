#include <iostream> // predefined header file (defined for you)
#include <string>
using namespace std;

#include "SLL.hpp" // your own header file
// <> vs "" -- compiler looks for the file in the C++ implementation
// vs in the current directory


SLL::SLL(){ // constructor definition
	headOne = nullptr;
	headTwo = nullptr;
}

SLL::SLL(string demo)
{
	headOne = nullptr;
	headTwo = nullptr;
	if (demo == "demo")
	{
		string def[]= {"che","the","fluffy","cat"};
		insert(nullptr, def[0]);
		for(int i=1;i<4;i++)
		{
				Node* prev = search(def[i-1]);
				insert(prev, def[i]);
		}
	}
	else{
		insert(nullptr, demo);
	}
}

SLL::~SLL(){
    //todo
     delete headOne;
    delete headTwo;
}

Node* SLL::search(string sKey){

    Node* crawler = headOne;

    while( crawler != nullptr && crawler->key != sKey){
        crawler = crawler->next;
    }

    return crawler;

}

void SLL::displayList(){
    Node* crawler = headOne;
    cout<< "LL1:";
    while( crawler != nullptr ){
        cout << crawler->key << "->";
        crawler = crawler->next;
    }
    cout << "END" << endl;

    crawler = headTwo;
    cout<< "LL2:";
    while( crawler != nullptr ){
        cout << crawler->key << "->";
        crawler = crawler->next;
    }
    cout << "END" << endl;
}

void SLL::insert(Node* afterMe, string newValue){

    if(headOne == nullptr){
        // first case: empty list
        // add new node and make headOne point to it
        headOne = new Node;
        headOne->key = newValue;
        headOne->next = nullptr; // what if we forget this line?
    }
    else if(afterMe == nullptr){
        // This condition implies that the list is not empty, but
        // the caller wants to add node before the headOne node
        Node* newNode = new Node;
        newNode->key = newValue;
        newNode->next = headOne;
        headOne = newNode;
        // at this point, we can test our code for this use case

    }
    else{
        Node* newNode = new Node;
        newNode->key = newValue;
        newNode->next = afterMe->next;
        afterMe->next = newNode;
    }


}

void SLL::deleteNode(string sKey)
{
    Node *deleteNode = search(sKey);
    if( deleteNode != nullptr)
    {
        // check if deleteNode is headOne
        if( deleteNode == headOne ){
            headOne = headOne->next;
            delete deleteNode;
        }
        //traverse the list:
        else
        {
            Node* crawler = headOne;
            // Stop at node prior the node to be deleted
            while(crawler->next != deleteNode){
                crawler = crawler->next;
            }

            // reconnect the LL around the node about to
            // be removed
            crawler->next = crawler->next->next;

            // deallocate
            delete deleteNode;
        }

    }
    else{
        cout << "Node doesn't exist. Nothing to do." << endl;
    }
}

int SLL::split(string searchKey)
{
    Node *tempy = headOne;
    Node *tempy2 = headTwo;
    Node *pre = nullptr;
    Node *mip = headOne;
    int hold = 0;
    
    if(headOne == nullptr)
    {   
        return 1;
    }
    
    if(headTwo != nullptr)
    {
        return 2;
    }
    
    else
    {
             
        while(tempy != nullptr && tempy->key != searchKey)
        {
            pre = tempy;
            tempy = tempy->next;
            //mip = tempy->next;
        }
        //tempy == fluffy
        Node *testy = search(tempy->key);
        if(testy==NULL)
        {
            return 1;
        }
        else
        {
            headTwo = tempy;
            headTwo->next = nullptr;
            headTwo->next = tempy->next;
            headOne = NULL;
            
            return 0;
        }
        
        

    }
    return 0;

}
