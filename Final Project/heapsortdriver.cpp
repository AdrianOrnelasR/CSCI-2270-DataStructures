#include "heapsort.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

int main()
{
    ifstream in_File;
    in_File.open("dataSetA.csv");

    HashTable table(40009);

    int IDs[10000];
    float sortTime[100];

    if(in_File.fail())
    {
        cout << "Failed to open file" << endl;
        return 0;
    }
    //========================================INSERT IDs==================================================
        string line = ""; string temp;
        int i = 0; int j = 0; int o = 1; int searchindex = 0;
        
        while(getline(in_File, line, ','))
        {
            stringstream s(line);
        
            getline(s, temp, ',');
            int iss = stoi(temp);

            IDs[i] = iss;

            bool kill = table.insert(IDs[i]);

            i++;
        }

        in_File.close();

        //========================================COLLISION COUNT===================================================
        cout << "=================================COLLISION COUNT===================================================" << endl;
        cout << "Number of collisions while probing: " << table.getNumOfCollision()<< endl;

        //========================================Min Heap===================================================
        int min = IDs[0];
        for(int get = 1; get < 10000; get++)
        {
            if(min > IDs[get])
            {
                min = IDs[get];
            }
        }
        
        int trak = 0; int gg = 0;
        
        for(int g = 0; g < 10000; g++)
        {
            if(g %100 == 0 )
            {
                auto sortt = chrono::steady_clock::now();

                while(gg < g)
                {
                    table.mineHeap(min);
                    gg++;
                }
                
                auto endsort = chrono::steady_clock::now();

                sortTime[trak] =  duration_cast<microseconds>(endsort-sortt).count();

                trak++;
                gg = 0;
            }
        }

        //table.printTable();
        //===============================================Write into File ========================================
        ofstream myFile;
        myFile.open("heapsortData.csv");
        
            int toDivide2 = 0;
            myFile << "Index" << ", " << "Serach" << endl;
            for(int b = 0; b < 100; b++)
            {
                toDivide2 = toDivide2 + sortTime[b];
                
                myFile << b+1 << ", "<< sortTime[b]  << endl;
            }
            
            cout << "Average time: " << toDivide2/100 << endl;

        in_File.close();
    return 0;
}
