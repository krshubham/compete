#include <iostream>
using namespace std;
long int z(long int x){
  long int num = 0;
  while(x){
    x/= 5;
    num += x;
  }
  return num;
}

int main(int argc, char const *argv[])
{
  int t;
  cin>>t;
  while(t--){
    long int n;
    cin>>n;
    cout<<z(n)<<endl;
  }
  return 0;
}
