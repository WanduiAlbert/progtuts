#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "simpio.h"

using namespace std;

string GetLine(){
  string result;
  getline(cin, result);
  return result;
}

int GetInteger(){
  while (true){
    stringstream converter;
    converter << GetLine();

    int result;

    if (converter >> result){
      char remaining;

      if (converter >> remaining)
        cout << "Unexpected character: " << remaining << endl;
      else
        return result;

    }else
      cout << "Please enter an integer" << endl;

    cout << "Retry: ";
  }
}
