#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void Graph::addVertex(string name)
{
    bool found = false;

    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == name)
        {
            found = true;
        }
    }

    if(found == false)
    {
        vertex * temp = new vertex;

        temp->name = name;

        vertices.push_back(temp);
    }
}

void Graph::addEdge(string v1, string v2)
{
    //looping through all vertices
    for(int i = 0; i < vertices.size(); i++)
    {
        //if found the first strin in vector
        if(vertices[i]->name == v1)
        {
            //start searching from were you found it
            for(int j = 0; j < vertices.size(); j++)
            {
                //check if sound and not at the same 'index'
                if(vertices[j]->name == v2 && i != j)
                {
                    //create new 
                    adjVertex av;
                    //the second strign we have
                    av.v = vertices[j];
                    //builds a connection
                    vertices[i]->adj.push_back(av);

                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    //builds a connection bac
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::displayEdges()
{
    int i = 0;
    //we still go through all vertices
    while(i < vertices.size())
    {
        //prints out the vetices
        cout << vertices[i]->name << " --> ";
        //goes from were we started and loops through the adjs 
        for(int j = 0; j < vertices[i]->adj.size(); j++)
        {
            //prints out the connection
            cout << vertices[i]->adj[j].v->name << " ";
        }
        cout << endl;
        i++;
    }
}

void Graph::breadthFirstTraverse(string sourceVertex)
{
    vertex *start = nullptr;

    int i = 0; 

    while(i < vertices.size())
    {
        if(vertices[i]->name == sourceVertex)
        {
            start = vertices[i];
        }
        i++;
    }

    start->visited = true;

    //stl queue
    queue<vertex*> q;
    q.push(start);

    vertex *n;

    cout << "Starting vertex (root): " << start->name << "-> ";
    while(!q.empty())
    {
        n = q.front();

        q.pop();
        //scan the adj list of each element Q
        for(int j = 0; j < n->adj.size(); j++)
        {
            vertex *apple = n->adj[j].v;
            
            if(apple->visited == false)
            {
                q.push(apple);
                apple->visited = true;
                apple->distance = n->distance + 1;
                cout << apple->name << "(" << apple->distance << ")" << " ";
            }
        }
    }
}

void ConnectedBuiHelper(vector<vertex*> vertices, string temp)
{
    vertex *start = nullptr;

    int i = 0; 

    while(i < vertices.size())
    {
        if(vertices[i]->name == temp)
        {
            start = vertices[i];
        }
        i++;
    }

    start->visited = true;

    //stl queue
    queue<vertex*> q;
    q.push(start);

    vertex *n;

    while(!q.empty())
    {
        n = q.front();

        q.pop();
        //scan the adj list of each element Q
        for(int j = 0; j < n->adj.size(); j++)
        {
            vertex *apple = n->adj[j].v;
            
            if(apple->visited == false)
            {
                q.push(apple);
                apple->visited = true;
                apple->distance = n->distance + 1;
            }
        }
    }
}

int countHelper(vector<vertex*> vertices, int &countt)
{
    if(countt - 1 == vertices.size())
    {
        return countt;
    }
    else
    {
        for(int i  = 0; i < vertices.size(); i++)
        {
            //stop when i reach an unvisted vertex, update count and return;

            if(vertices[i]->visited == false)
            {
                vertices[i]->visited = true;
                ConnectedBuiHelper(vertices, vertices[i]->name);
                countt += 1;
            }
        }
        return countt;
    }   
}

int Graph::getConnectedBuildings()
{
    string start = vertices[0]->name;

    for(int i = 0; i < vertices.size(); i++)
    {
        vertices[i]->visited = false;
    }

    int countConection = 0;

    countConection = countHelper(vertices, countConection);
        
    return countConection;
}