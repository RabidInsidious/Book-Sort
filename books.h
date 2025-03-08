#ifndef BOOKS_
#define BOOKS_
//defining book.h

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
//including libraries I think would be important and use

using namespace std;
//name space

class book{
   public:
      book();
      book(string inFileName);

      string getInputFile() const;
      void setInputFile(string inFileName);
      void print();
//depending on the int main() either set/get method or intializer constructor can be used
   private:
      string FileName_;
};
//seeting up how I want my class to function

#endif
