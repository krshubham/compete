#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef vector<pair<lli,lli> > vplli;

inline bool isPrime(lli n){
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;
 
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
 
    return true;
}

inline bool isEven(lli x){
	if(x&1) return false;
	else return true;
}
 
class Graph{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int v, bool visited[], bool *rs);  // used by isCyclic()
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isCyclic();    // returns true if there is a cycle in this graph
    lli count = 0;
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w){
    adj[v].push_back(w); // Add w to v’s list.
}


bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack){
    if(visited[v] == false){
        
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i){
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) ){
            	count++;
            }
            else if (recStack[*i]){
                count++;
            }
        }
 
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    if(count >= 1){
    	return true;
    }
    return false;
}
 
// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS() in http://www.geeksforgeeks.org/archives/18212
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}
 
int main(){
    lli t,a,b,c,d,e,f,n,m,k;
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	Graph g(n);
    	for (int i = 0; i < m; ++i){
    		cin>>a>>b;
    		a--;b--;
    		g.addEdge(a,b);
    	}
	    if(g.isCyclic()){
	        cout<<g.count<<endl;
	    }
	    else{
	        cout << "Graph doesn't contain cycle";
	    }
	}
    return 0;
}