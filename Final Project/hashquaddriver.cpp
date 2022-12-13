#include "hashquad.hpp"
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
    int indexforSearch[10000];
    int forSearch[10000];

    int insertArr[100];
    float searchArr[100];

    if(in_File.fail())
    {
        cout << "Failed to open file" << endl;
        return 0;
    }
    //========================================INSERT TIMES==================================================
        string line = ""; string temp;
        int i = 0; int j = 0; int o = 1; int searchindex = 0;
        
        while(getline(in_File, line, ','))
        {
            stringstream s(line);
        
            getline(s, temp, ',');
            int iss = stoi(temp);

            IDs[i] = iss;

            i++;

            if(i %100 == 0)
            {
                while(searchindex < i)
                {
                    int randome = rand()%(o*100);
                    indexforSearch[searchindex] = randome; 
                    searchindex++;
                }

                auto start = chrono::steady_clock::now();
                
                while(j < i)
                {
                    bool kill = table.insert(IDs[j]);
                    j++;
                }
                
                auto end = chrono::steady_clock::now();

                //cout << duration_cast<nanoseconds>(end-start).count() << endl;
                insertArr[o - 1] =  duration_cast<microseconds>(end-start).count();

                o++;
            }

        }

        in_File.close();

        //========================================COLLISION COUNT===================================================
        cout << "=================================COLLISION COUNT===================================================" << endl;
        cout << "Number of collisions while probing: " << table.getNumOfCollision()<< endl;

        //========================================RANDOM INDEX SEARCH TIMES===================================================
       
        for(int g = 0; g < 10000; g++)
        {
            forSearch[g] = table.search_index(indexforSearch[g]);
        }
        
        int trak = 0; int gg = 0;

        for(int s = 0; s < 10000; s++)
        {
            if(s %100 == 0)
            {
                auto searchstart = chrono::steady_clock::now();

                while(gg < s)
                {
                    table.search(forSearch[gg]);
                    gg++;
                }

                auto endsearch = chrono::steady_clock::now();

                searchArr[trak] =  duration_cast<microseconds>(endsearch-searchstart).count();

                trak++;
            }
        }
        
        //===============================================Write into File ========================================
        
        ofstream myFile;
        myFile.open("hashquadDATA.csv");

            
        
            int toDivide = 0;
            int toDivide2 = 0;
            myFile << "Index" << ", " << "Insert" << ", " << "Search" << endl;
            for(int b = 0; b < 100; b++)
            {
                toDivide2 = toDivide2 + searchArr[b];
                toDivide = toDivide + insertArr[b];
                myFile << b+1 << ", " << insertArr[b] << ", " << searchArr[b] << endl;
            }
            myFile << "\n";
            cout << "Average time for insert: " << toDivide/100 << endl;
            cout << "Average time for search: " << toDivide2/100 << endl;
 
        in_File.close();
        
    return 0;
}
