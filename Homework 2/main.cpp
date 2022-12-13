#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include "Wordsrecordd.hpp"
using namespace std;
// this is reference for reading a file word by word  (Can be used for reading both stop words and unique words)

void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[])
{
    ifstream in_File(ignoreWordFileName);
    string line, temp;
    int i = 0;
   
    if(in_File.fail())
    {
        cout << "Failed to open" << ignoreWordFileName << endl;
    }
    else
    {   
        while(getline(in_File, line))
        {
            stringstream s(line);
        
            getline(s, temp);
            ignoreWords[i] = temp;
            //cout << temp << endl; //test case
            i++;

        }
    }
    in_File.close();
}

bool isIgnoreWord(string word, string ignoreWords[])
{

    for (int i = 0; i < 50; i++)
    {
        if (word == ignoreWords[i])
        {
            //cout << "the word " << word << " is in the row " << i + 1 << endl; // test case
            return true;
        }
           
    }
    return false;  
}

int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length)
{   
    int sum = 0;
    for(int i = 0; i < length; i++)
    {
        sum += distinctWords[i].count;
    }
    return sum;
}

void sortArray(wordRecord distinctWords[], int length)
{
    bool flag = false;
    while(!flag)
    {
        flag = true;
        for(int i = 0; i < length; i++)
        {
            if(distinctWords[i].count < distinctWords[i+1].count )
            {
                flag = false;
                int tempcount = distinctWords[i+1].count;
                string tempword = distinctWords[i+1].word; 
                distinctWords[i+1].count = distinctWords[i].count;
                distinctWords[i+1].word = distinctWords[i].word;
                distinctWords[i].count = tempcount;
                distinctWords[i].word = tempword;
            }
        }
    }
}

void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords)
{
    int tempN = N + 10;
    float pobabilityofoccurence = 0;
    for(int i = N; i < tempN; i++)
    {
        pobabilityofoccurence = (float)distinctWords[i].count/totalNumWords;
        cout << setprecision(5) << fixed << pobabilityofoccurence << " - " <<  distinctWords[i].word << endl;
    }
    
    
}

ifstream inStream;      // stream for reading in file
inStream.open(argv[2]); // open the file

string word;
while (inStream >> word ){

// get stop words / unique words into array

}
inStream.close(); // close the file