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

typedef struct node{
	lli data;
	struct node *left, *right;
} Node;

Node* newNode(lli data){
	Node *node = new Node;
	node->left = node->right = NULL;
	node->data = data;
	return node;
}

Node* insert(Node *root, lli data){
	if(root == NULL) return newNode(data);

	if(data < root->data)
		root->left = insert(root->left,data);
	else if(data > root->data)
		root->right = insert(root->right, data);
	return root;
}

void preorder(Node *root){
	if(root != NULL){
		cout<<root->data<<'\n';
		preorder(root->left);
		preorder(root->right);
	}
}

Node *search(Node *root,lli data){
	if(data < root->data){
		search(root->left, data);
	}
	else if(data> root->data){
		search(root->right, data);
	}
	else if(data == root->data){
		return root;
	}
}

Node* lca(Node *root, lli n1, lli n2){
	if(root == NULL) return NULL;
	while (root != NULL){
		if (root->data > n1 && root->data > n2)
			root = root->left;
		else if (root->data < n1 && root->data < n2)
			root = root->right;
		else break;
	}
	//recursive approach causes more space use on the call stack
	// if(root->data > n1 && root->data > n2){
	// 	lca(root->left,n1,n2);
	// }
	// else if(root->data < n1 && root->data > n2){
	// 	lca(root->right,n1,n2);
	// }
	return root;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>n;
	Node *root = NULL;
	rep(i,n){
		cin>>x;
		if(i == 0){
			root = insert(root,x);
		}
		else insert(root,x);
	}
	cin>>x>>y;
	cout<<max(lca(root,x,y)->data, max(x,y))<<endl;
	bye;
}

