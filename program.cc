#include <iostream>
#include <fstream>
#include <string>
#include "books.h"

using namespace std;

int main() {
   book revlist;
   string input;
//my class variable

   cout << "Please input a valid book file" << endl;
   cin >> input;
//user interacttion

   revlist.setInputFile(input);
   revlist.getInputFile();
   revlist.print();
//class in action

   cout << "Thanks for using!" << endl;
//everything will be ok

   return 0;
}
