#include <bits/stdc++.h>
using namespace std;

typedef struct point{
	pair<int, int> e1;
	pair<int,int> e2;
} Point;


int main(){
	int t,n,a,b,c,d,e,f,x1,y1,x2,y2;
	cin>>n;
	//contains all the points
	vector<Point*> horizontal,vertical;
	for (int i = 0; i < n; ++i){
		cin>>x1>>y1>>x2>>y2;
		Point *p = new Point;
		p->e1 = make_pair(x1,y1);
		p->e2 = make_pair(x2,y2);
		if(x1 == x2){
			//vertical line
			vertical.push_back(p);
		}
		else if(y1 == y2){
			//horizontal line
			horizontal.push_back(p);
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
	return 0;
}



