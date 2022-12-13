#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "addStudentDatta.hpp"
using namespace std;

//takes in a struct array, verable, and index
void addStudentData(studentData students[], string studentName1, int homework1, int recitation1, int quiz1, int exam1, int length)
{
    //adds all the info in
    students[length].studentName = studentName1;
    students[length].homework = homework1;
    students[length].recitation = recitation1;
    students[length].quiz = quiz1;
    students[length].exam = exam1;
    //calculate the average for there score and stores it
    students[length].average = ((double)homework1 + (double)recitation1 + (double)quiz1 + (double)exam1)/4;
}

//simple funtion to get a letter grade
char calcLetter(double avg)
{
    char grade;
    if(avg >= 90)
    {
        grade = 'A';
        return grade;
    }
    else if(avg < 90 && avg >= 80)
    {
        grade = 'B';
        return grade;
    }
    else if(avg < 80 && avg >= 70)
    {
        grade = 'C';
        return grade;
    }
    else if(avg < 70 && avg >= 60)
    {
        grade = 'D';
        return grade;
    }
    else
    {
        grade = 'F';
        return grade;
    }
}

//takes in the array and its length
void printList(const studentData students[], int length)
{
    //runs a through array
    for(int i = 0; i < length; i++)
    {
        //prints for each student in array
        double tempGrade = students[i].average;
        cout << students[i].studentName << " earned " << students[i].average << " which is an " << calcLetter(tempGrade) << endl;
    }
}

int main(int argc, char *argv[])
{
    //makes a stuct array with size 100 
    studentData students[100];
    
    //opens the file needed to open
    ifstream in_File(argv[1]);
    
    //if failes to open
    if(in_File.fail())
    {
        cout << "Failed to open the file." << endl;
        return 0;
    }
    else
    {
    //temp verables to plug into equation 
    string Tempname, TempHomework, TempRecitation, TempQuiz, TempExam, TempAverage;
    //keep track of what student we at
    int i = 0; 
    string line;
    while(getline(in_File, line))
    {
        //use stringstream to pull lines
        stringstream s(line);

            //stores each one properly
            getline(s, Tempname, ',');
            string FracName = Tempname;

            getline(s, TempHomework, ',');
            int FracHome = stoi(TempHomework);

            getline(s, TempRecitation, ',');
            int FacRecitation = stoi(TempRecitation);

            getline(s, TempQuiz, ',');
            int FRqu = FRqu = stoi(TempQuiz);

            getline(s, TempExam, ',');
            int FracExam = stoi(TempExam);
            
            //adds student 
            addStudentData(students,FracName, FracHome, FacRecitation, FRqu, FracExam, i);
            //increments to add another student
            i++;
    }
        //print list of all students added and close file
        printList(students, i);
        in_File.close(); 
        
        //opens file to read from it
        ofstream output(argv[2]);

        //runs through our array
        for(int o = 0; o < i; o++)
        {
            //calculates that studets letter grade
            char calctemp = calcLetter(students[o].average);
            //compares if there letter grade is inbetween the given bounds, if so print it, if not move on
            if(calctemp <= *argv[3] && calctemp >= *argv[4])
            {
                output << students[o].studentName << "," <<  students[o].average << ","<< calctemp << endl;
            }
        }
        //than clsoe file
        output.close();
    }
}  
 

