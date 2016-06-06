//Question:
/*
Task 
Given an array, , of size  containing distinct elements , sort array  in ascending order using the Bubble Sort algorithm above. Once sorted, print the following  lines:

 
where  is the number of swaps that took place.
 
where  is the first element in the sorted array.
 
where  is the last element in the sorted array.
Hint: To complete this challenge, you will need to add a variable that keeps a running tally of all swaps that occur during execution.

Input Format

The first line contains an integer, , denoting the number of elements in array . 
The second line contains  space-separated integers describing , where the  integer is , .

Constraints

, 
Output Format

There should be  lines of output:

 
where  is the number of swaps that took place.
 
where  is the first element in the sorted array.
 
where  is the last element in the sorted array.
*/

//My answer to the question

//planning:
/*
I plan not to go by above said method. Since bubble sort and other sorting methods are elementary and this question tries to teach.
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void bubbleSort(vector<int> a,int n){
	int numberOfSwaps = 0;
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<n-1;j++){
			if (a[j]>a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				numberOfSwaps++;
			}
		}
	}
	cout<<numberOfSwaps<<endl;
}


int main(int argc, char const *argv[])
{
	int n;
	vector<int> v;
	cin>>n;
	int a;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	cout<<v[0]<<endl<<v[n-1]<<endl;
	bubbleSort(v,n);
	return 0;
}
