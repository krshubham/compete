#include <iostream>
using namespace std;

/*

A year is leap year if the following conditions are satisfied:

Year is multiple of 400.
Year is multiple of 4 and not multiple of 100.


*/

int main() {
  int year;
  cin>>year;
  if(year % 400 == 0) {
    cout<<"leap year"<<endl;
    return 0;
  }

  if(year % 4 == 0) {
    if(year % 100 == 0) {
      cout<<"not leap year"<<endl;
    }
    else {
      cout<<"leap year"<<endl;
    }
  }
  return 0;
}
