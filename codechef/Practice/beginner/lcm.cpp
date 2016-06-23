#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cout<<"For how many numbers do you want to find the LCM?"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the numbers one by one and separated by space"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for (int i = 2; i <=arr[0]; ++i)
	{
		int count = 0;
		for (int j= 0; j < n; ++j)
		{
			if(arr[j] % i==0){
				count++;
			}
		}
		if(count == n){
			cout<<"The LCM of the given numbers is: "<<i<<endl;
			return 0;
		}
	}
	cout<<"The LCM of the given numbers is: "<<1<<endl;
	return 0;
}
