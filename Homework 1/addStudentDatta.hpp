#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct studentData
{
    std::string studentName;
    int homework;
    int recitation;
    int quiz;
    int exam;
    double average;
};

void addStudentData(studentData students[], int homework, int recitation, int quiz, int exam, int length){}