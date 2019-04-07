#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef vector<pair<lli,lli> > vplli;

inline bool isPrime(lli n){
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}

typedef struct ipc{
	lli lectures;
	lli sadness;
} ipc;

inline bool isEven(lli x){
	if(x&1) return false;
	else return true;
}


class trainer{
public:
	int day, lectures, sadness;
	trainer(){

	}
	void set(int day, int lectures, int sadness){
		this->day = day;
		this->lectures = lectures;
		this->sadness = sadness;
	}
};

bool dayComp(trainer const &a, trainer const &b){
	return a.day < b.day;
}

bool sadnessComp(trainer const &a, trainer const &b){
	return a.sadness < b.sadness;
}


int main(){
	ios_base::sync_with_stdio(0);
	
	int t;
	cin >> t;
	trainer trainers[100000];
	while(t--){
		int n, d;
		cin >> n >> d;

		int day, lectures, sadness;
		ll totalSadness = 0;
		for(int i = 0; i<n; i++){
			cin >> day >> lectures >> sadness;
			trainers[i].set(day, lectures, sadness);
			totalSadness += lectures*sadness;
		}
		sort(trainers, trainers+n, dayComp);

		vector<trainer> vec;
		int last_trainer_idx = 0;
		bool added;
		for(int day = 1; day <= d; day++){
			added = false;
			while(last_trainer_idx < n && trainers[last_trainer_idx].day == day){
				vec.push_back(trainers[last_trainer_idx]);
				last_trainer_idx += 1;
				added = true;
			}

			if(added)
				sort(vec.begin(), vec.end(), sadnessComp);

			if(vec.size() > 0){
				trainer last = vec.back();
				totalSadness -= last.sadness;
				last.lectures -= 1;
				if(last.lectures == 0)
					vec.pop_back();
			}
		}
		cout << totalSadness << endl;
	}
	bye;
}
