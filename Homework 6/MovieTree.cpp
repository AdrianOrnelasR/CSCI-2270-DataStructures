#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST
MovieNode* getMovieNode(int rank, string t, int y, float r) 
{
    MovieNode* nn = new MovieNode;
    nn->title = t;
    nn->ranking = rank;
    nn->year = y;
    nn->rating = r;
    return nn;
}

MovieTree::MovieTree() 
{
  root = nullptr;
}

MovieTree::~MovieTree() 
{
  delete root;
}

MovieNode* printMovieInventoryHelper(MovieNode* temp)
{
  if(temp)
  {
    printMovieInventoryHelper(temp->left);
      cout << "Movie: " << temp->title << " " << temp->rating << endl;
    printMovieInventoryHelper(temp->right);
  }
  return temp;
}

void MovieTree::printMovieInventory() 
{

   if(root == 0)
   {
     cout << "Tree is Empty. Cannot print" << endl;
   }
   else
   {
    root = printMovieInventoryHelper(root);
   }
   
}   

MovieNode* addMovieNodeHelper(MovieNode* currNode, int tempranking, string temptitle, int tempyear, float temprating)
{
  
    if(currNode == nullptr)
    {
        MovieNode* newNode = new MovieNode;
        newNode->title = temptitle;
        newNode->ranking = tempranking;
        newNode->year = tempyear;
        newNode->rating = temprating;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if(currNode->title < temptitle)
    {
        currNode->right = addMovieNodeHelper(currNode->right, tempranking, temptitle, tempyear, temprating);
    }
    else if(currNode->title > temptitle)
    {
        currNode->left = addMovieNodeHelper(currNode->left, tempranking, temptitle, tempyear, temprating);
    }
    return currNode;
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) 
{
  root = addMovieNodeHelper(root, ranking, title, year, rating);
}

MovieNode* findMovieHelper(MovieNode* temp, string name)
{
  if(temp == nullptr)
  {
    return nullptr;
  }
  if(temp->title == name)
  {
    return temp;
  }
  if(temp->title < name)
  {
    return  findMovieHelper(temp->right, name);
  }
  if(temp->title > name)
  {
    return findMovieHelper(temp->left, name);
  }
    return temp;
}

void MovieTree::findMovie(string title) 
{
    MovieNode* tempTittle = findMovieHelper(root, title);

    if(tempTittle) 
    { 
        cout << "Movie Info:" << endl;
        cout << "==================" << endl;
        cout << "Ranking:" << tempTittle->ranking << endl;
        cout << "Title  :" << tempTittle->title << endl;
        cout << "Year   :" << tempTittle->year << endl;
        cout << "rating :" << tempTittle->rating << endl;
    } 
    else 
    {
        cout << "Movie not found." << endl;
    }
}

MovieNode* queryMoviesHelper(MovieNode* currNode, float Temprating, int TempYear)
{
    if(currNode)
    {   
        if(currNode->rating >= Temprating && currNode->year >= TempYear)
        {
            cout << currNode->title << "(" << currNode->year << ") " << currNode->rating << endl;
        }
        queryMoviesHelper(currNode->left, Temprating, TempYear);
        queryMoviesHelper(currNode->right, Temprating, TempYear);
    }
    return currNode;
}

void MovieTree::queryMovies(float rating, int year) {
  if(root == nullptr)
  {
    cout << "Tree is Empty. Cannot query Movies" << endl;
  }
  else
  {
    cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
    queryMoviesHelper(root, rating, year);
  }
  
}

int numOfMovies(MovieNode* temp)
{
  int count = 0;

  if(temp)
  {
    count++;
    count = count + numOfMovies(temp->left);
    count = count + numOfMovies(temp->right);
  }
  return count;
}

float averageRatingHelper(MovieNode* temp)
{
    
    float total = 0;
    if(temp)
    {
        total = (temp->rating + averageRatingHelper(temp->left) + averageRatingHelper(temp->right));
    }
    
  return (total);
}

void MovieTree::averageRating()
{
    if(root == nullptr)
    {
        cout << "Average rating:0.0" << endl;
    }
    else
    {
       cout << "Average rating:" << (averageRatingHelper(root)/numOfMovies(root)) << endl;
    }
}

MovieNode* printLevelNodesHelper(MovieNode* curr, int Templevel)
{
    if(curr == nullptr)
    {
        return nullptr;
    }
    if (Templevel == 0) {
       
        cout << "Movie: " << curr->title << " " << curr->rating << endl;
    }
    else if (Templevel > 0) {
        printLevelNodesHelper(curr->left, Templevel - 1);
        printLevelNodesHelper(curr->right, Templevel - 1);
    }
    return curr;

}

void MovieTree::printLevelNodes(int level)
{
    if(root == nullptr)
    {
        cout << "Tree is empty" << endl;
    }
    else
    {
        printLevelNodesHelper(root, level);
    }
}
