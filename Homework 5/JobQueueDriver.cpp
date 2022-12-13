/****************************************************************/
/*                Job Queue Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "JobQueue.hpp"
#include <iostream>
#include <string>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Add jobs into the queue" << endl;
	cout << "2. Dispatch jobs from the queue" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[])
{
	JobQueue JQU;
	int input;
	string mip;
	string temppp;
	int mipp = 0;
	int JobInt;
	
	while(input != 3)
	{
		menu();
			cin >> input;
		
		switch(input)
		{
			case 1:

				cout << "Enter the number of jobs to be created:" << endl;
					cin >> JobInt;
				while(mipp < JobInt)
				{
					cin >> mip;
					JQU.enqueue(mip);
					mipp++;
				}
				for(int i = 0; i < JobInt; i++)
				{	
					cout << "job" << i + 1 << ":" << endl;
				}
				break;
			case 2:
			int optionss;
				cout << "Enter the number of jobs to be dispatched:" << endl;
					cin >> optionss;
				if(optionss > JQU.queueSize())
				{
					for(int o = 0; o < JQU.queueSize(); o++)
					{
						temppp = JQU.peek();
						cout << "Dispatched: " << temppp << endl;
						JQU.dequeue();
					}
					temppp = JQU.peek();
					cout << "Dispatched: " << temppp << endl;
					JQU.dequeue();

					cout << "No more jobs to be dispatched from queue" << endl;
				}
				else
				{
					for(int j = 0; j < optionss; j++)
					{
						temppp = JQU.peek();
						cout << "Dispatched: " << temppp << endl;
						JQU.dequeue();
					}	
				}
				break;
		}	
	}
	
	cout << "Number of jobs in the queue:" << JQU.queueSize() << endl;

}
