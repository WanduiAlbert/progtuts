#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
  ifstream myfile ("basic.cpp");
  ofstream output ("copy_file");
  string word;

  while (myfile >> word){
    cout << word << endl;
    output << word;
  }

  // I want to reread the file from the beginning
  myfile.close();
  myfile.open("copy_file");

  while(getline(myfile, word))
    cout << word<< endl;
}
