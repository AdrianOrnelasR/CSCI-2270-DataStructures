#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

void Graph::createEdge(string v1, string v2, int num)
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
                    av.weight = num;
                    //builds a connection
                    vertices[i]->adj.push_back(av);

                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    av2.weight = num;
                    //builds a connection bac
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::insertVertex(string n)
{

}

void Graph::displayEdges()
{
    //loop through all vertices and adjacent vertices
    // cout<<"here"<<vertices.size()<<endl;
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->name<<":"<<endl;
        for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
            cout<<" --> "<< vertices[i]->adj[j].v->name << " "<<vertices[i]->adj[j].weight<<endl;
        }
        cout<<endl;
    }
}

void Graph::traverseWithDijkstra(string start)
{
    
    vertex *startie = nullptr;

    int i = 0; 

//finds the vertice were we  want start
    while(i < vertices.size())
    {
        if(vertices[i]->name == start)
        {
            startie = vertices[i];
        }
        i++;
    }

//sets all distance to infinity, visited to false and pred to null
    for(int m = 0; m < vertices.size(); m++)
    {
        vertices[m]->distance = INT_MAX;
        vertices[m]->visited = false;
        vertices[m]->pred = nullptr;
    }
    
    //the start is set to 0 and visited 
    startie->distance = 0;
    startie->visited = true;
    
    vector<vertex*> sptSet;

    //keeps track on what we put in
    sptSet.push_back(startie);
    
    while(sptSet.size() != vertices.size())
    {
        double minDisFound = INT_MAX;
    
        for(int j = 0; j < vertices.size(); j++)
        {
            vertex *temp = vertices[j];

            for(int g = 0; g < temp->adj.size(); g++)
            {
                double tempWeight = temp->adj[g].weight;
                vertex *hold = temp->adj[g].v;
                    
                if(hold->visited == false)
                {
                    if(minDisFound > tempWeight + temp->distance)
                    {
                        hold->visited = true;
                        minDisFound = tempWeight + temp->distance;
                        hold->distance = minDisFound;
                        sptSet.push_back(hold);
                    }
                    
                }
            }
        }
    }
}

void DftHelper(vertex *plug, vector<vertex*> vertices)
{
    vertex *temp = nullptr;
    for(int i = 0; i < plug->adj.size(); i++)
    {
        if(plug->adj[i].v->visited == false)
        {
            cout << plug->adj[i].v->name << " -> ";
            temp = plug->adj[i].v;
            temp->visited = true;
            
            DftHelper(temp, vertices);
        }
    }
}

void Graph::depthFirstTraversal(string sourceVertex)
{
    if(vertices.size() == 0)
    {
        cout << "its empty bruh" << endl;
    }
    else
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

        cout << start->name << " -> ";

        DftHelper(start, vertices);
        
        cout << "DONE";
    
    }
}

void Graph::minDistPath(string source, string destination) 
{
    vertex *startie = nullptr;
    vertex *endie = nullptr;

    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i]->name == source)
        {
            startie = vertices[i];
        }
        if(vertices[i]->name == source)
        {
            endie = vertices[i];
        }
    }

    for(int m = 0; m < vertices.size(); m++)
    {
        vertices[m]->distance = INT_MAX;
        vertices[m]->visited = false;
        vertices[m]->pred = nullptr;
    }
    
    startie->distance = 0;
    startie->visited = true;
    
    vector<vertex*> sptSet;

    sptSet.push_back(startie);
    
    while(sptSet.size() != vertices.size())
    {
        double minDisFound = INT_MAX;
    
        for(int j = 0; j < vertices.size(); j++)
        {
            vertex *temp = vertices[j];

            for(int g = 0; g < temp->adj.size(); g++)
            {
                double tempWeight = temp->adj[g].weight;
                vertex *hold = temp->adj[g].v;
                    
                if(hold->visited == false)
                {
                    if(minDisFound > tempWeight + temp->distance)
                    {
                        hold->visited = true;
                        minDisFound = tempWeight + temp->distance;
                        hold->distance = minDisFound;
                        hold->pred = temp;
                        sptSet.push_back(hold);
                    }
                    else
                    {
                        minDisFound = INT_MAX;
                        //hold->visited = false;
                        hold->distance = minDisFound;
                        hold->pred = nullptr;
                    }
                
                }
                
            }
        }
    }


}




void Graph::traverseWithDijkstra(string start)
{
    
    vertex *startie = nullptr;

    int i = 0; 

    while(i < vertices.size())
    {
        if(vertices[i]->name == start)
        {
            startie = vertices[i];
        }
        i++;
    }

    for(int m = 0; m < vertices.size(); m++)
    {
        vertices[m]->distance = INT_MAX;
        vertices[m]->visited = false;
        vertices[m]->pred = nullptr;
    }
    
    startie->distance = 0;
    startie->visited = true;
    
    vector<vertex*> sptSet;

    sptSet.push_back(startie);
    
    bool flag = false;
    
    while(!flag)
    {   
        flag = true;
        int minDisFound = INT_MAX;
        vertex *holdTwo = nullptr;
    
        for(int j = 0; j < sptSet.size(); j++)
        {
            vertex* temp = sptSet[j];
            
            for(int g = 0; g < temp->adj.size(); g++)
            {
                
                int tempWeight = temp->adj[g].weight;
                vertex *hold = temp->adj[g].v;
                
                if(hold->visited == false)
                {
                    if(minDisFound > tempWeight + temp->distance)
                    {
                        flag = false;
                        hold->visited = true;
                        minDisFound = tempWeight + temp->distance;
                        holdTwo = hold;
                        holdTwo->pred = temp;
                    }
                }
                
            }
        }
        if(flag == false)
        {
            holdTwo->distance = minDisFound;
            
            holdTwo->visited = true;
            sptSet.push_back(holdTwo);
        }
    }
}









#include <climits>
void Graph::traverseWithDijkstra(string start)
{
    
    vertex *startie = nullptr;

    int i = 0; 

    while(i < vertices.size())
    {
        if(vertices[i]->name == start)
        {
            startie = vertices[i];
        }
        i++;
    }

    for(int m = 0; m < vertices.size(); m++)
    {
        vertices[m]->distance = INT_MAX;
        vertices[m]->visited = false;
        vertices[m]->pred = nullptr;
    }
    
    startie->distance = 0;
    startie->visited = true;
    
    vector<vertex*> sptSet;

    sptSet.push_back(startie);
    
    while(sptSet.size() != vertices.size())
    {
        double minDisFound = INT_MAX;
    
        for(int j = 0; j < vertices.size(); j++)
        {
            vertex *temp = vertices[j];

            for(int g = 0; g < temp->adj.size(); g++)
            {
                double tempWeight = temp->adj[g].weight;
                vertex *hold = temp->adj[g].v;
                    
                if(hold->visited == false)
                {
                    if(minDisFound > tempWeight + temp->distance)
                    {
                        hold->visited = true;
                        minDisFound = tempWeight + temp->distance;
                        hold->distance = minDisFound;
                        hold->pred = temp;
                        sptSet.push_back(hold);
                    }
                    else
                    {
                        minDisFound = INT_MAX;
                        //hold->visited = false;
                        hold->distance = minDisFound;
                        hold->pred = nullptr;
                    }
                
                }
                
            }
        }
    }
}