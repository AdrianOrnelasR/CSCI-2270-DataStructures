#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <algorithm> 
#include "Wordsrecordd.hpp"
using namespace std;
/*
struct wordRecord
{
    string word;
    int count;
};
*/
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
    string temp;
    int tempp;
    bool flag = false;
    while(!flag)
    {
        flag = true;
        for(int i = 0; i < length; i++)
        {
            if(distinctWords[i].count < distinctWords[i+1].count && distinctWords[i+1].word > distinctWords[i].word )
            {
                
                flag = false;
                int tempcount = distinctWords[i+1].count;
                string tempword = distinctWords[i+1].word; 
                
                distinctWords[i+1].count = distinctWords[i].count;
                distinctWords[i+1].word = distinctWords[i].word;
                
                distinctWords[i].word = tempword;
                distinctWords[i].count = tempcount; 
                
                
            }

        }
        
    }
    
       
}

void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords)
{
    int tempN = N + 10;
    double pobabilityofoccurence = 0;
    for(int i = N; i < tempN; i++)
    {
        pobabilityofoccurence = (float)distinctWords[i].count/totalNumWords;
        cout << setprecision(5) << fixed << pobabilityofoccurence << " - " <<  distinctWords[i].word << endl;
    }
    
    
}

bool append(string* &str_arr, string s, int &numEntries, int &arraySize)
{
    bool temp;
    
    if(numEntries == arraySize)
    {
        string* tempArray;
        tempArray = new string[arraySize * 2];
                        
        for(int j = 0; j < arraySize; j++)
        {
            tempArray[j] = str_arr[j];
        }

        arraySize = arraySize * 2;
        delete [] str_arr;
        str_arr = tempArray;
        temp = true;
        str_arr[numEntries] = s;
        numEntries = numEntries +1;
        return temp;
    }
    
    if(numEntries < arraySize)
    {
        str_arr[numEntries] = s;
        temp = false;
        numEntries = numEntries +1;
    }
    
    return temp;
}

int main(int argc, const char *argv[])
{
    if(argc != 4) //if there are 3 arguments
    {
        cout << "Usage: Assignment2Solution<number of words><inputfilename.txt><ignoreWordsfilename.txt>" << endl;
        return -1;
    }
    else
    {   
        //temp varables
        string line, temp;
        bool total = false;
        int doubleArraycount = 0;
        int place = 0;
        int mip = 0;
        int currentElement = 0;
        
        //grabs all the words from ignorewords and stores them into the array
        string ignoreWords[50];
        getIgnoreWords(argv[3], ignoreWords);
        
        //ifstream file to open moby dick
        ifstream in_file;
        in_file.open(argv[2]);
        
        //creates the dynamic array with a size of 100
        int disWordSize = 100;
        wordRecord* distinctWords;
        distinctWords= new wordRecord[disWordSize];

        //while it pulls the lines
        while(in_file >> line)
        {
            //stringstream s(line);
            temp = line;
                //first see if the array is full
                if(currentElement > disWordSize - 1)
                {
                    //if so than create a new distinct array with double amount of space as the other one
                    wordRecord* TempdistinctWords;
                    //int tempnumholder = disWordSize * 2;
                    TempdistinctWords = new wordRecord[disWordSize * 2];
                    
                    //run throught the old array and copy eveything to the new array
                    for(int j = 0; j < disWordSize; j++)
                    {
                        TempdistinctWords[j].word = distinctWords[j].word;
                        TempdistinctWords[j].count = distinctWords[j].count;
                    }

                    //has the counter for the double array increment by one
                    doubleArraycount = doubleArraycount + 1;
                    //makes the old hold number of the size equal times 2
                    disWordSize = disWordSize * 2;
                    //deleted the old heap meory array
                    delete [] distinctWords;
                    //have the old array equal the new one
                    distinctWords = TempdistinctWords;

                }

            //test if that word pulled is inside the ignore words array
            total = isIgnoreWord(temp, ignoreWords);
            
            //false means it was not inside the array add to the array
                //if the arry is not full 
                if(total == false)
                {   
                    //makes a temp bool
                    bool temppy = true;

                    //go throught the array and see if the word is in there
                    
                       for(int i = 0; i < currentElement; i++)
                        {
                            //if the word is found in there
                            if(temp == distinctWords[i].word)
                            {
                                //increment the word count 
                                distinctWords[i].count += 1;
                                temppy = false;
                            }
                        }  
                        //place++;       
                    if(temppy == true)
                    {
                        distinctWords[place].word = temp;
                        distinctWords[place].count = 1;
                        currentElement++;
                          
                        //cout << distinctWords[place].word << " index: ";
                        //cout << place << endl;
                        place++;
                    }    
                }
            
        }
        

        in_file.close();

        
        int holdword = getTotalNumberNonIgnoreWords(distinctWords, place);
        cout << "Array doubled: " << doubleArraycount << endl;
        cout << "Distinct non-common words: " << place << endl;
        cout << "Total non-common words: " << holdword << endl;
        cout << "Probability of next 10 words from rank " << argv[1] << endl;
        cout << "---------------------------------------" << endl;
        
        sortArray(distinctWords, place);
        int tempargc = stoi(argv[1]);
        printTenFromN( distinctWords, tempargc, holdword);

        delete [] distinctWords;
    }
    
    return 0;  
}

       