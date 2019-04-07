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

const lli MAXN = 1e5 + 1e2;

struct group{
    int f=0,s=0,t=0,num=0;
    string leader;
    group(){}
    group(int grade, string leader){
        if(grade == 1){
            this->f = 1;
        }
        else if(grade == 2){
            this->s = 1;
        }
        else{
            this->t = 1;
        }
        this->num = 1;
        this->leader = leader;
    }
};

vlli limits;
inline bool ok(lli size[]){
    if(size[0] <= limits[1] && size[1] <= limits[2] && size[2] <= limits[3] && size[3] <= limits[4]){
        return true;
    }
    return false;
}

struct union_find {
    union_find* parent = this;
    lli rank = 0;
    lli size[4] = {1, 0, 0, 0};
    void merge(union_find* second);
    union_find* head();
};

union_find* union_find::head(){
    if(parent != parent->parent){
        parent = parent->head();
    }
    return parent;
}

void union_find::merge(union_find* second){
    union_find* first = head();
    second = second->head();
    lli new_size[] = {first->size[0] + second->size[0],first->size[1] + second->size[1],first->size[2] + second->size[2],first->size[3] + second->size[3]};
    if(ok(new_size) and first != second){
        copy(new_size, new_size + 4, first->size);
        copy(new_size, new_size + 4, second->size);
        if(first->rank < second->rank){
            swap(first, second);
        }
        if(first->rank == second->rank){
            first->rank++;
        }
        second->parent = first;
    }
}

vlli grade(MAXN,0);
map<string, lli> grades;
map<lli, string> grade_student;
union_find union_find_array[MAXN];
lli x = 0;

lli idx(string s){
    auto ite = grades.find(s);
    if(ite == grades.end()){
        grades[s] = x;
    	grade_student[x] = s;
        x++;
        return x - 1;
    } else {
    	return ite->second;
    }
}
string get_string(lli s){
    return grade_student[s];
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    lli t,n,a,b,c,d,e,f,x,y,m,s;
    cin>>n>>m>>a>>b>>f>>s>>t;
    grades.clear();
    grade_student.clear();
    x = 0;

    limits.pb(a);
    limits.pb(b);
    limits.pb(f);
    limits.pb(s);
    limits.pb(t);
    string name;
    lli grade;
    for(int i = 0; i < n; i++){
        cin>>name>>grade;
        union_find_array[idx(name)].size[grade]++;
    }

    lli res = 0;
    string s1, s2;
    for(int i = 0; i < m; i++){
        cin>>s1>>s2;
        lli s1id = idx(s1), s2id = idx(s2);
        union_find_array[s1id].merge(&union_find_array[s2id]);
        res = max(res, union_find_array[s1id].head()->size[0]);
    }
    if(res < a){
        cout<<"no groups"<<endl;
        bye;
    }
    set<string> res_ans;
    for(int i = 0; i < n; i++){
        if(union_find_array[i].head()->size[0] == res){
            res_ans.insert(get_string(i));
        }
    }
    for(auto& name:res_ans){
        cout<<name<<endl;
    }
    bye;
}