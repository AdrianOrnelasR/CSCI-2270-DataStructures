#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    //File wrting
    //Creats instance of ofstream and opens the file
    ofstream oFile("filename.txt");
    oFile << "Inserted this text into filename.txt";
    //Close the file stream
    oFile.close();
}