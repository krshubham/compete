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

typedef struct node{
	lli data;
	struct node* left, *right;
} Node;

Node* newNode(lli data){
	Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

Node* insert(Node* root, lli data){
	if(root== NULL){
		return newNode(data);
	}
	if(data < root->data){
		root->left = insert(root->left, data);
	}
	else if(data > root->data){
		root->right = insert(root->right, data);
	}
	return root;
}

bool search(Node* root, lli data){
	if(root == NULL) return false;
	if(data < root->data){
		return search(root->left, data);
	}
	else if(data > root->data){
		return search(root->right, data);
	}
	else if(data == root->data){
		return true;
	}
	return false;
}

Node* deleteNode(Node* root, lli data){
	if(root == NULL) return NULL;
	if(data < root->data){
		root->left = deleteNode(root->left, data);
	}
	else if(data > root->data){
		root->right = deleteNode(root->right, data);
	}
	else{
		// so we are on this node now.
		if(root->right == NULL){
			Node *temp = root->left;
			delete root;
			return temp;
		}
		else if(root->left == NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		}
		Node* temp = root->right;
		while(temp->left != NULL) temp = temp->left;
		root->data = temp->data;
		deleteNode(root->right, temp->data);
	}
	return root;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	Node* root = NULL;
	root = insert(root, 20);
	insert(root,10);
	if(search(root,10)){
		cout<<"YES"<<endl;
	}
	else cout<<"NO"<<endl;
	bye;
}

