//settings 

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
#include <iomanip>
#include <stack>
#include <climits>
#include <queue>
#include <string>
#include <cstring>
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
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define crep(i,a,b) for( int i = a; i <= b; i++ )

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef vector<pair<lli,lli> > vplli;

inline bool isPrime(lli n){
	if (n <= 1)  {
		return false;
	}
	if (n <= 3)  {
		return true;
	}

	if (n%2 == 0 || n%3 == 0) {
		return false;
	}
	
	for (int i=5; i*i<=n; i=i+6){
		if (n%i == 0 || n%(i+2) == 0){
			return false;
		}
	}

	return true;
}

inline bool isEven(lli x){
	if(x&1) return false;
	else return true;
}

//binary search tree to store the names in it and
//then trying to lookup these names;

typedef struct node{
	string data;
	node *left;
	node *right;
	int count;
} node;

node* newNode(string data){
	node *temp = new node;
	temp->data = data;
	temp->right = temp->left = NULL;
	temp->count = 1;
	return temp;
}

node* insert(node *n, string data){
	if(n == NULL) return newNode(data);

	if(data < n->data){
		n->left = insert(n->left,data);
	}
	else if(data == n->data){
		n->count++;
	}
	else if(data > n->data){
		n->right = insert(n->right, data);
	}
	return n;
}


void inorder(node *root){
	if(root != NULL){
		inorder(root->left);
		while(root->count--){
			cout<<root->data<<endl;			
		}
		inorder(root->right);
	}
}

void search(node *root, string data){
	if(root == NULL){
		cout<<"Not found"<<endl;
		return;
	}
	if(root->data == data){
		cout<<"Yes "<<data<<" exists in the tree"<<endl;
		return;
	}
	else if(data < root->data){
		search(root->left,data);
	}
	else{
		search(root->right,data);
	}
}



int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	string s1,s2;
	node *root = NULL;
	root = insert(root,"shubham");
	inorder(root);
	search(root,"shubham");
	bye;
}

