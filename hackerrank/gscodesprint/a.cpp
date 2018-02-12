#pragma comment (linker, "/stack:20000000")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828
#define stp(a,b) a.push(b)
#define all(a) a.begin(),a.end()
#define PI 3.1415926535897932384626433832795
#define rep(i,n) for( int i = 0; i < n; i++ )
#define endl '\n'
#define upper_limit 9223372036854775807

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef unsigned long long ull;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef unordered_map<lli,lli> umlli;
typedef vector<pair<lli,lli> > vplli;

inline vector<string> split(string str,string sep){char* cstr=const_cast<char*>(str.c_str());char* current;vector<string> arr;current=strtok(cstr,sep.c_str());while(current!=NULL){arr.push_back(current);current=strtok(NULL,sep.c_str());}return arr;}
inline bool isPrime(lli n){if (n <= 1){return false;}if (n <= 3)  {return true;}if (n%2 == 0 || n%3 == 0) {return false;}for (int i=5; i*i<=n; i=i+6){if (n%i == 0 || n%(i+2) == 0){return false;}}return true;}
inline lli power(lli x,lli y,lli p){int res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y = y>>1;x = (x*x) % p;}return res;}

//The latest time stamp
ull lastts = 0;

/*
utility function to convert a string into unsigned long long type
*/
inline ull strtoull(string str){
	stringstream ss(str);
	ull x;
	ss>>x;
	return x;
}

//convert a string to long double
inline long double strtodouble(string str){
	stringstream ss(str);
	long double x;
	ss>>x;
	return x;
}

//check if the given {var} is according to constraints of {vt}
inline bool check(string var, string vt){
	if(vt == "oid"){
		if(var.find(".") == string::npos){
			ull test = strtoull(var);
			if(test >= 1 and test <= upper_limit){
				return true;
			}
			else{
				return false;
			}
		}
		else return false;
	}
	else if(vt == "ts"){
		if(var.find(".") == string::npos){
			return (strtoull(var) > lastts);
		}
	}
	else if(vt == "symbol"){
		return (find_if(all(var),[](char c) { return !std::isalpha(c); }) != var.end());
	}
	else if(vt == "orderType"){
		return (var == "M" || var == "L" || var == "I");
	}
	else if(vt == "side"){
		return (var == "B" || var == "S");
	}
	else if(vt == "price"){
		return (vt.find(".") != string::npos);
	}
	else if(vt == "quantity"){
		if(vt.find(".") == string::npos){
			ull test = strtoull(var);
			return (test >= 1 and test <= upper_limit);
		}
	}
	return true;
}

typedef struct order{
	order(){}
	order(string oid,string ts, string symbol,string ot, string side, string price, string quantity){
		this->oid = strtoull(oid);
		this->ts = strtoull(ts);
		this->symbol = symbol;
		this->orderType = ot;
		this->side = side;
		this->price = strtodouble(price);
		this->quantity = strtoull(quantity);
	}
	ull oid,ts;
	string symbol;
	string orderType;
	string side;
	long double price;
	ull quantity;
} Order;


int main(){
	ios_base::sync_with_stdio(0);
	ull t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	string action;
	//to keep track of all the orderIds inserted till now
	map<ull,Order> book;
	while(t--){
		cin>>action;
		vector<string> options = split(action,",");
		string typeofCommand = options[0];
		if(typeofCommand == "N"){
			//everything has to be read as a string
			string oid,ts,quantity,symbol;
			string price;
			string ot,side;
			oid = options[1];
			ts = options[2];
			symbol = options[3];
			ot = options[4];
			side = options[5];
			price = options[6];
			quantity = options[7];
			// cout<<oid<<" "<<ts<<" "<<quantity<<" "<<symbol<<" "<<price<<" "<<ot<<" "<<side<<endl;
			if(check(oid,"oid") and check(ts,"ts") and check(symbol,"symbol") and check(ot,"orderType") and check(side,"side") and check(price,"price") and check(quantity,"quantity")){
				// cout<<book[strtoull(oid)].oid<<endl;
				// if(book[strtoull(oid)]){
				// 	cout<<oid<<" - Reject - 303 - Invalid order details"<<endl;
				// }
				// else{
				// 	Order order(oid,ts,symbol,ot,side,price,quantity);
				// 	book.insert(mp(strtoull(oid),order));
				// 	cout<<oid<<" - Accept"<<endl;
				// }
			}
			else{
				// cout<<check(oid,"oid")<<endl;
				// cout<<check(ts,"ts")<<endl;
				// cout<<check(symbol,"symbol")<<endl;
				// cout<<check(ot,"orderType")<<endl;
				// cout<<check(side,"side")<<endl;
				cout<<check(price,"price")<<endl;
				// cout<<check(quantity,"quantity")<<endl;
				cout<<oid<<" - Reject - 303 - Invalid order details"<<endl;
			}
		}
	}
	bye;
}

