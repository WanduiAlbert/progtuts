#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "simpio.h"

using namespace std;

int main(){
  vector <int> inputs;

  cout << "Please enter a series of integers to be sorted" << endl;

  int number;
  int kNumValues = 10;

  for (int i =0; i < kNumValues; i++){
    cout << "Please enter a value: " ;
    number = GetInteger();

    inputs.push_back(number);
  }

  sort(inputs.begin(), inputs.end());

  cout << endl << "Here are the numbers given in sorted order:" << endl;
  for (int n: inputs)
    cout << n << endl;

}
