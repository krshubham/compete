#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class job
{
	int id;
	float time;
public:
	void get();
	float gettime();
	int getid();
};
class job_Sch
{
	int num;
	job j[20];
public:
	void find_Max();
	void get();
};


int main(){
	int n;
	cin>>n;
	int maxTime = 0,maxJobId;	
	int jobId,jobTime;
	for (int i = 0; i < n; ++i){
		cin>>jobId>>jobTime;
		if(jobTime > maxTime){
			maxJobId = jobId;
			maxTime = jobTime;
		}
	}
	cin>>n;
	int maxTimewithPriority,maxTimeIdWithPriority=0,maxJobPriority;
	int m = 0;
	int jobPriority;
	for (int i = 0; i < n; ++i){
		cin>>jobId>>jobTime>>jobPriority;
		if(jobTime > maxTimeIdWithPriority){
			maxTimeIdWithPriority = jobId;
			maxTimewithPriority = jobTime;
			maxJobPriority = jobPriority;
		}
	}
	cout<<jobId<<endl;
	cout<<maxTimeIdWithPriority<<endl;
}