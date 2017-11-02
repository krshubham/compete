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
	struct node *left,*right,*nextRight;
} Node;

Node *newNode(lli data){
	Node *node = new Node;
	node->data = data;
	node->right = node->left = NULL;
	return node;
}

Node *insert(Node *root, lli data){
	if(root == NULL){
		return newNode(data);
	}
	if(data < root->data){
		root->left = insert(root->left,data);
	}
	else if(data > root->data){
		root->right = insert(root->right,data);
	}
	return root;
}

void joinRight(Node *root){
	queue<Node*> Q;
	Q.push(root);
	Q.push(NULL);
	while(!Q.empty){
		Node *node = Q.front();
		Q.pop();
		if(node != NULL){
			node->nextRight = Q.front();
			if(node->left){
				Q.push(node->left);
			}
			if(node ->right){
				Q.push(node->right);
			}
		}
		else if(!Q.empty()){
			Q.push(NULL);
		}
	}
}

void inorder(Node *root){
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	
	bye;
}

