#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
  
int addToArrayAsc(float sortedArray[], int numElements, float newValue)
    {
        //adds the new value at the last element
        sortedArray[numElements] = newValue;
        //added one to the total number of elements in the array after called
        numElements = numElements + 1;
        //goes through the array
        for(int i = 0; i < numElements; i++)
        {		
            //holds the one before 
            for(int j = i + 1; j < numElements; j++)
            {
                //checks if the number is before it 
                if(sortedArray[i] > sortedArray[j])
                {
                    //holds the one to be replaced
                    float temp = sortedArray[i];
                    //sets the stop before to the bigger one
                    sortedArray[i] = sortedArray[j];
                    //than sets the next position to next
                    sortedArray[j] = temp;   
                }    
            } 
	    }
        return numElements;
    }

int main(int argc, const char *argv[])
{
    //opens the file 
    ifstream in_File(argv[1]);
    
    //if the file failed to open print that statement 
    if(in_File.fail())
    {
        cout << "Failed to open the file." << endl;
        return 0;
    }
    else
    {
    //list of temp variables
    int listsize;
    string line;
    float mip[101];
    int mipNum = 0;
    float insert;

    //simple get line to pull from file
    while(getline(in_File, line))
    {
        //sets the string pulled into a float
        insert = stof(line);
        //puts it into the array
        mipNum = addToArrayAsc(mip, mipNum, insert);

            //will go through the array that is currently made
            for(int i = 0; i < mipNum; i++)
            {
                //if your at the end print without a comma
                if(i == mipNum -1)
                {
                    cout << mip[i];
                }
                else
                //print with coma seperate
                {
                    cout << mip[i] << ",";
                }
            }
            //endl
            cout << endl;
    }
    }  
}
