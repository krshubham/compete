#include <bits/stdc++.h>
using namespace std;

#define LL long long int
#define ii pair< double , double >
#define iii pair< ii , int > 
#define vi vector<int>
#define vii vector<ii>
#define II pair< LL , LL >
#define III pair< LL  , LL > 
#define vI vector<LL>
#define rI(B) scanf("%d",&B)
#define wI(B) printf("%d",B)
#define FOR(i,f,t) for(int i=f;i<t;i++)
#define r(e) for(int i=0;i<e;i++)
struct circle {
	double r;
	double x, y;
};

vector< circle > v;
bool quadraticFormula(double a, double b, double c, double &ans){
	double numeratorSqrtResult = (b*b) - (4 * a*c);
	if (numeratorSqrtResult < 0) return false;
	numeratorSqrtResult = sqrt(numeratorSqrtResult);
	double denominatorResult = 2 * a;
	double addNegativeTo_b = 0 - b;
	double ans1 = (addNegativeTo_b + numeratorSqrtResult) / denominatorResult;
	double ans2 = (addNegativeTo_b - numeratorSqrtResult) / denominatorResult;
	ans = max(ans1, ans2);
	return true;
}

bool intersect(circle a, circle b, double &sol) {
	double xs = a.x - b.x;
	xs *= xs;
	double cnst = a.r + b.r;
	cnst *= cnst;
	return quadraticFormula(1, -2 * a.y, a.y*a.y + xs - cnst, sol);
}

void test(circle c) {
	double y = c.r;
	for (int i = 0; i < v.size(); i++){
		double y1;
		if (intersect(v[i], c, y1)) {
			y = max(y, y1);
		}
	}
	c.y = y;
	v.push_back(c);
}
int main(){
	int n, m;
	cin >> n >> m;
	r(n) {
		int a;
		cin >> a;
		circle c;
		c.r = m;
		c.x = a;
		test(c);
	}
	r(n) {
		printf("%.15lf ", v[i].y);
	}
	return 0;
}