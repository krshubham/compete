#include <iostream>
using namespace std;

/*
  We have to write a program that takes a number from the user
  and checks whether the given number is odd or even!
*/
int main() {
  int number;
  cin>>number;
  // we have to check if the number is divisble by 2
  if((number % 2) == 0) {
    cout<<"even"<<endl;
  }
  else {
    cout<<"odd"<<endl;
  }
  return 0;
}
/*
take a number
if number is greater than 2 print "Nice"
if number is greater than 5 print "very Nice"
otehrwise print "You are noob"
*/
