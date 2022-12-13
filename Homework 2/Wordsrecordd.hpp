#include <iostream>
#include <string>

using namespace std;

struct wordRecord
{
    string word;
    int count;
};
int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length);
