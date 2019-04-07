#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define endl '\n'

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<pair<lli,lli> > vplli;

typedef struct point{
	pair<int, int> e1;
	pair<int,int> e2;
} Line;


int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x1,y1,x2,y2;
	cin>>n;
	//contains all the Lines
	vector<Line*> horizontal,vertical;
	for (int i = 0; i < n; ++i){
		cin>>x1>>y1>>x2>>y2;
		Line *p = new Line;
		p->e1 = mp(x1,y1);
		p->e2 = mp(x2,y2);
		if(x1 == x2){
			//vertical line
			vertical.pb(p);
		}
		else if(y1 == y2){
			//horizontal line
			horizontal.pb(p);
		}
	}
	c = 0;
	for (int i = 0; i < horizontal.size(); ++i){
		for (int j = 0; j < horizontal.size(); ++j){
			if(j != i){
				if((horizontal[i]->e2.first == horizontal[j]->e1.first) || (horizontal[i]->e2.first == horizontal[j]->e2.first)
					|| (horizontal[i]->e1.first == horizontal[j]->e2.first) || (horizontal[i]->e1.first == horizontal[j]->e1.first)){
					for (int k = 0; k < vertical.size(); ++k){
						if(horizontal[i]->e1 == vertical[k]->e1 || horizontal[i]->e2 == vertical[k]->e1){
							if(horizontal[j]->e1 == vertical[k]->e2 || horizontal[j]->e2 == vertical[k]->e2){
								c++;
							}
						}
					}
				}
			}
		}
	}
	cout<<c<<endl;
	bye;
}

