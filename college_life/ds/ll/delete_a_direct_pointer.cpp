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
	struct node *next;
} Node;

Node* newNode(lli data){
	Node *node = new Node;
	node->next = NULL;
	node->data = data;
	return node;
}

Node *push_back(Node* head, lli data){
	if(head == NULL) return newNode(data);
	while(head->next != NULL){
		head = head->next;
	}
	head->next = newNode(data);
	return head;
}

void print(Node *head){
	if(head == NULL) return;
	cout<<head->data<<endl;
	print(head->next);
}

void delete_pointer(Node *node){
	if(node->next == NULL){
		return;
	}
	else{
		node->data = node->next->data;
		node->next = node->next->next;
		delete node->next;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	Node *head = NULL;
	head = push_back(head,10);
	push_back(head,20);
	push_back(head,30);
	push_back(head,40);
	push_back(head,50);
	print(head);
	// delete_pointer(head->next->next->next->next);
	// cout<<"After deletion status:"<<endl;
	// print(head);
	bye;
}

