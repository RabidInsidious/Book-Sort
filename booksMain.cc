#include "books.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
//includes, added vector and algorithm for vector use

book::book(){
   FileName_ = "None";
}
//default constructor

book::book(string inFileName){
   FileName_ = inFileName;
}
//intializer

void book::setInputFile(string inFileName){
   FileName_ = inFileName;
}
//set

string book::getInputFile() const{
   return FileName_;
}
//get

void book::print() {
//the main function of this file, in hindsight should probably have broken this up into more functions
   ifstream infs;
   istringstream ss;
   string temptoke;
   string line;
   vector<string> switchlines;
   vector<string> tokei;
//variables

   infs.open(FileName_);
   if (!infs.is_open()) {
      cout << "file is geeking" << endl;
      return;
   }
//return to ensure file works

   while (getline(infs, line)) {
      ss.clear(); // Clear the stringstream
      ss.str(line); // Set stringstream to line
      tokei.clear();
//while for each line read from inputed file

//with line in stringsream I use a while getline to create each variable based off commas rather than indiviual strings
      while (getline(ss, temptoke, ',')) {
         temptoke.erase(0, temptoke.find_first_not_of(" \t")); // Remove leading space
         temptoke.erase(temptoke.find_last_not_of(" \t") + 1); // Remove following space
         tokei.push_back(temptoke);//the while stringstream puts the variables in a vector and pushs them back so they are accessible to be rearranged
      }

      string title = tokei[0];
      string author = tokei[1];
      string year = tokei[2];
//assigning each part of the vector to a respective variable

      switchlines.push_back(author + ", \"" + title + "\" (" + year + ")");
 //finally using the other vector to hold my desired format
   }

   infs.close();
//closing file

   for(int i = switchlines.size()-1; i>=0; --i){
      cout << switchlines[i] << endl;
   }
//using a for loop on my switchlines vector to output the lines in reverse order
}
