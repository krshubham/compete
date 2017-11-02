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
	node->data = data;
	node->next = NULL;
	return node;
}

Node* push_back(Node* node,lli data){
	Node *head = node;
	if(head == NULL) return newNode(data);
	while(head->next != NULL){
		head = head->next;
	}
	head->next = newNode(data);
	return head;
}

void display(Node *head){
	if(head != NULL){
		cout<<head->data<<endl;
		display(head->next);
	}
}

void reverse_print(Node *head){
	if(head != NULL){
		reverse_print(head->next);
		cout<<head->data<<endl;
	}
}

void push_front(Node **head,lli data){
	if(*head == NULL){
		*head = newNode(data);
		return;
	}
	Node* temp = newNode(data);
	temp->next = *head;
	*head = temp;
}




int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	Node *head = NULL;
	head = push_back(head,10);
	push_back(head,20);
	push_back(head,30);
	//important to pass by reference because outside modification has been done;
	push_front(&head,40);
	display(head);
	// reverse_print(head);
	// last_to_first(&head);
	bye;
}

