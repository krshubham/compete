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
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define crep(i,a,b) for( int i = a; i <= b; i++ )
#define endl '\n'

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

typedef struct node {
	lli data;
	struct node *left;
	struct node *right;
} Node;

Node* newNode(lli data){
	Node *node = new Node;
	node->left = node->right = NULL;
	node->data = data;
	return node;
}

Node* insert(Node* node, lli data){
	if(node == NULL){
		return newNode(data);
	}
	if(data < node->data){
		node->left = insert(node->left,data);
	}
	else{
		node->right = insert(node->right, data);
	}
	return node;
}

void inorder(Node *root){
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}

bool find(Node *root, lli key){
	if(root == NULL) return false;
	if(root->data == key)
		return true;
	else if(key < root->data){
		return find(root->left,key);
	}
	else if(key > root->data){
		return find(root->right, key);
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	Node *root = NULL;
	root = insert(root,10);
	insert(root,20);
	insert(root,30);
	insert(root,5);
	if(find(root,20)){
		cout<<"the value exists in the tree"<<endl;
	}
	else{
		cout<<"the value doesn't exist"<<endl;
	}
	bye;
}
