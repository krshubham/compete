#include <stdio.h>
#include<string.h>

void print(char a[],int low,int high)
{
int i;
for(i=low;i<=high;i++)
printf("%c",a[i]);
printf("\n");
return;
}

void palin(char a[],int n)
{
int i,low,high;
for(i=1;i<n;i++)
{
low=i-1;
high=i;
while(low>=0 && high<n && a[low]==a[high])
{
if(high-low+1>=3)
{
print(a,low,high);

}
low--;
high++;
}
low=i-1;
high=i+1;
while(low>=0 && high<n && a[low]==a[high])
{
if(high-low+1>=3)
{
print(a,low,high);
}
low--;
high++;
}
}
}

int main(void) {
// your code goes here
char a[16]="cabbaabbacasdasdsdsdsdassadsadasdasadsadasda";
palin(a,strlen(a));
return 0;
}