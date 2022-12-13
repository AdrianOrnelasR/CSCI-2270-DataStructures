#include "bubblesort.hpp"
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

    MedTracker tempie;

    int IDs[10000];
    int indexforSearch[10000];
    int forSort[10000];

    int insertArr[100];
    int sortTime[100];

    if(in_File.fail())
    {
        cout << "Failed to open file" << endl;
        return 0;
    }
        string line = ""; string temp;
        int i = 0; int o = 1; int j = 0; int searchindex = 0;
        
        //------------------------------------Insert ---------------------------------------------------------------------------

        while(getline(in_File, line, ','))
        {
            stringstream s(line);
        
            getline(s, temp, ',');
            int iss = stoi(temp);

            IDs[i] = iss;

            tempie.insert(nullptr, IDs[i]);

            i++;
        }
        in_File.close();

        //-----------------------------------------------Sort Time---------------------------------------------------------------------------
        /*
        for(int loop = 0; loop < 10000; loop++)
        {
            forSort[loop] = tempie.search_index(indexforSearch[loop]);
        }
        */
        int trak = 0; int gg = 0;
        
        for(int g = 0; g < 10000; g++)
        {
            if(g %100 == 0 )
            {
                auto sortt = chrono::steady_clock::now();

                while(gg < g)
                {
                    tempie.Bubblesort();
                    gg++;
                }
                
                auto endsort = chrono::steady_clock::now();

                sortTime[trak] =  duration_cast<milliseconds>(endsort-sortt).count();

                trak++;
                gg = 0;
            }
        }
        //tempie.display();

    //===============================================Write into File ========================================
    
    ofstream myFile;
    myFile.open("bubblesortData.csv");
    
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