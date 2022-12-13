#include <iostream>
#include "StackCalculator.hpp"


using namespace std;
/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-")
      return false;

    else if(s.size() > 1 && s[0] == '-')
      s = s.substr(1);

    bool point = false;

    for(int i = 0; i < s.size(); i++){
      if(!isdigit(s[i]) && s[i] != '.')
        return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

StackCalculator::StackCalculator()
{
  stackHead = nullptr;
}

StackCalculator::~StackCalculator()
{
  delete stackHead;
}

bool StackCalculator::isEmpty()
{
	if(stackHead == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
  
}

void StackCalculator::push(float number)
{
  Operand* tempy = new Operand;

    tempy->number = number;
    tempy->next = stackHead;
    stackHead = tempy;
}

void StackCalculator::pop()
{
  if(isEmpty())
  {
    cout << "Stack empty, cannot pop an item." << endl;
  }
  else
  {
    Operand* tempy = stackHead;
    stackHead = stackHead->next;
    delete tempy;
  }
  
}

Operand* StackCalculator::peek()
{
	if(isEmpty())
  {
    cout << "Stack empty, cannot peek." << endl;
    
  }
  else
  {
    return stackHead; 
  }
  return nullptr;
}

bool StackCalculator:: evaluate(string* s, int size)
{
    /*TODO: 1.scan the array from the end
            2.Use isNumber function to check if the input is an operand
            3.push all operands to the stack
            4.If operator take two element of from the stack,
              compute and put the result back in stack
            5.Handle the boundery cases as required.
            6.Read the writeup for more details
    */
    Operand* tempy = new Operand;
    bool lol;
    float pushTEMP;
    if(size < 3)
    {
      cout << "err: not enough operands" << endl;
      return false;
    }
    for(int i = size-1; i >= 0; i--)
    {
      lol = isNumber(s[i]);
      {
        if(lol == true)
        {
          pushTEMP = stof(s[i])
          push(pushTEMP);
        }
        else
        {
          if(s[i] != "+" || s[i] != "*")
          {
            cout << "err:invalid operation" << endl;
            return false;
          }
          else
          {
            float tempnum1, tempnum2, answer;    

            if(s[i] == "+")
            {
                tempnum1 = stackHead->number;
                  pop();
                tempnum2 = stackHead->number;
                  pop();
                answer = tempnum1 + tempnum2;
                  push(answer);
                return true;
            }
            else
            {
                tempnum1 = stackHead->number;
                  pop();
                tempnum2 = stackHead->number;
                  pop();
                answer = tempnum1 * tempnum2;
                  push(answer);
                return true;
            }
          }
          
        }
        
      }
      
    }
    return true;
}
