#include <cstdio>
using namespace std;


unsigned long long z (unsigned long long x){
  unsigned long long result = 0;
  unsigned long long i;
  
  while(x>0){
    x /= 5;
    result += x;
  }

  return result;  
  
}

int main(){
  int i,j;
  scanf("%d",&j);
  unsigned long long x;

  for (i=0;i<j;i++){
    scanf("%llu",&x);    
    printf("%llun",z(x));  
  }  

  return 0;
}
/*
After that I looked at the growth pattern of zeroes in factorial numbers, 
and discovered that the number grows every 5 multiplications, 
and that at the fifth consecutive increment it jumps by 2 instead of 1
*/