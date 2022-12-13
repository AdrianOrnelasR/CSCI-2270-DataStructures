#include <iostream>
#include <string>
#include<cmath>
#include<iomanip>
#include "JobQueue.hpp"
using namespace std;

JobQueue::JobQueue()
{
    queueFront = 0;
    queueEnd = 0;
    counter = 0;
    
}

bool JobQueue::isEmpty()
{
    if(counter == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

bool JobQueue::isFull()
{
    if(counter == 20)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void JobQueue::enqueue(string job)
{

    if(isFull())
    {
        cout << "Queue full, cannot add new job" << endl;
    }
    else
    {
        queue[queueEnd] = job;
        queueEnd++;
        counter++;
    }
    
}

void JobQueue::dequeue()
{
    if(isEmpty())
    {
        cout << "Queue empty, cannot dequeue a job" << endl;
    }
    else
    {
        queue[queueFront] = queue[queueFront + 1];
        queueFront= queueFront + 1;
        counter--;
    }
    
}

string JobQueue::peek()
{
    if(isEmpty())
    {
        cout << "Queue empty, cannot peek" << endl;
        return " ";
    }
    else
    {
        return queue[queueFront];
    }
    
}

int JobQueue::queueSize()
{
    if(isEmpty())
    {
        return 0;
    } 
    if(queueFront < queueEnd)
    {
        return queueEnd - (queueFront + 1);
    }
    else
    {
        return (queueEnd + 1 + SIZE) - queueFront;
    }
} 
