// //Reference from :https://www.hackerearth.com/problem/algorithm/tree-and-coprime-queries/editorial/
// #pragma comment (linker, "/stack:20000000")
// #pragma GCC optimize("O1,unroll-loops,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #include <bits/stdc++.h>
// #define gc getchar_unlocked
// using namespace std;
// template <typename T> void in(T &x) {
// T c = gc(); while(((c < 48) || (c > 57)) && (c!='-')) c = gc();
// bool neg = false; if(c == '-') neg = true; x = 0; for(;c < 48 || c > 57;c=gc());
// for(;c > 47 && c < 58;c=gc()) x = (x*10) + (c - 48); if(neg)  x = -x;
// }
// int gcd(unsigned int u, unsigned int v)
// {
//   int shift;
//   if (u == 0) return v;
//   if (v == 0) return u;
//   shift = __builtin_ctz(u | v);
//   u >>= __builtin_ctz(u);
//   do {
//     v >>= __builtin_ctz(v);
//     if (u > v) {
//       int t = v;
//       v = u;
//       u = t;
//     }  
//     v = v - u;
//   } while (v != 0);
//   return u << shift;
// }
// const int MAXN = 1e5 + 2;
// const int MAXLOGN = 17;
// const int MAXQ = 5e4 + 5;
// int n, q;
// int vals[MAXN], use[MAXN], ans[MAXN];
// int st[MAXN], en[MAXN], pool, inv[MAXN];
// vector<int> adj[MAXN];
// int pa[MAXN][MAXLOGN], depth[MAXN];
// int lp[MAXN];
// bool vis[MAXN];
// vector<int> ps[MAXN];
// vector<int> order;
// vector<long long >prime;
// inline void sieve_eratosthenes() {
//   lp[1] = 1;
//   for (int i=2; i<MAXN; i++){
//     lp[i] = i;
//   }
//   for (int i=4; i<MAXN; i+=2){
//     lp[i] = 2;
//   }
//   for (int i=3; i*i<MAXN; i++){
//     if (lp[i] == i){
//       for (int j=i*i; j<MAXN; j+=i){
//         if (lp[j]==j){
//           lp[j] = i;
//         }
//       }
//     }
//   }
//   for(int i = 2; i < MAXN; i++) {
//     int temp = i;
//     while(temp > 1) {
//       int curr = lp[temp];
//       while(temp % curr == 0) temp /= curr;
//       ps[i].push_back(curr);
//     }
//   }
// }
// void walk() {
//   int pool = 0;
//   for(auto &elem: order) {
//     if(st[elem] > 0) {
//       en[elem] = ++pool;
//     } else {
//       st[elem] = ++pool;
//     }
//     inv[pool] = elem;
//   }
// }
// void lca_dfs(int node = 1, int prev = -1, int d = 0) {
//  depth[node] = d;
//  pa[node][0] = prev;
//  order.push_back(node);
//  int sz = int(adj[node].size());
//  for(int i = 0; i < sz; i++) {
//   if(adj[node][i] == prev)  continue;
//   lca_dfs(adj[node][i], node, d+1);
// }
// order.push_back(node);
// }
// void preprocess_lca() {
//   std::fill(&pa[0][0], &pa[0][0] + MAXN*MAXLOGN, -1);
//   lca_dfs();
//   for(int j = 1; j < MAXLOGN; j++)
//     for(int i = 1; i <= n; i++)
//       if(pa[i][j-1] != -1) pa[i][j] = pa[pa[i][j-1]][j-1];
//   }
//   int LCA(int u, int v) {
//    if(depth[u] < depth[v]) swap(u,v);
//    int diff = depth[u]-depth[v];
//    for(int i = 0; i < MAXLOGN; i++) if((diff>>i)&1) u = pa[u][i];
//      if(u == v) return u;
//    for(int i = MAXLOGN-1; i > -1; i--) if(pa[u][i] != pa[v][i])
//     u = pa[u][i], v = pa[v][i];
//   return pa[u][0];
// }
// int dist(int u, int v) {
//   int l = LCA(u, v);
//   return (depth[u] - depth[l]) + (depth[v] - depth[l]);
// }
// /* LCA END */
// int BLK_SIZE;
// struct _query {
//   int t, l, r, lca, x;
//   bool flag;
//   int idx;
//   bool operator<(const _query &other) const {
//     if(l/BLK_SIZE == other.l/BLK_SIZE) {
//       if(r/BLK_SIZE == other.r/BLK_SIZE) {
//         return t < other.t;
//       }
//       return r < other.r;
//     }
//     return l < other.l;
//   }
// } qs[MAXQ];
// struct _update {
//   int t, u, now, before;
// } up[MAXQ];
// bool is_q[MAXQ];
// int cnt[MAXN];
// void modify(int val, int add) {
//   int size = ps[val].size();
//   for(int mask = 1; mask < 1 << size; mask++) {
//     int prod = 1;
//     for(int j = 0; j < size; j++) if((1 << j) & mask) {
//       prod *= ps[val][j];
//     }
//     cnt[prod] += add;
//   }
// }
// void toggle(int node) {
//   if(vis[node]) {
//     modify(use[node], -1);
//   } else {
//     modify(use[node], 1);
//   }
//   vis[node] ^= true;
// }
// int eval(int x) {
//   int size = ps[x].size(), res = 0;
//   for(int mask = 1; mask < 1 << size; mask++) {
//     int prod = 1, c = 0;
//     for(int j = 0; j < size; j++) {
//       if((1 << j) & mask) {
//         prod *= ps[x][j], c++;
//       }
//     }
//     if(c % 2) {
//       res += cnt[prod];
//     }
//     else {
//       res -= cnt[prod];
//     }
//   }
//   return res;
// }
// int main() {
//   sieve_eratosthenes();
//   int opt, a, b, c;
//   in(n);
//   BLK_SIZE = pow(n, 2./3.);
//   for(int i = 1; i <= n; i++) {
//     in(vals[i]);
//     use[i] = vals[i];
//   }
//   for(int i = 1; i < n; i++) {
//     adj[i].push_back(i+1);
//   }
//   preprocess_lca();
//   walk();
//   in(q);
//   int num_q = 0, num_up = 0;
//   for(int i = 0; i < q; i++) {
//     in(opt);
//     if(opt == 1) { // Update: Set node a to b
//       in(a), in(b);
//       num_up++;
//       up[num_up] = {num_up, a, b, use[a]};
//       use[a] = b;
//     } else {       // Query: Find ans on path from a -> b wrt c
//       in(a), in(b), in(c);
//       int l = LCA(a, b);
//       if(l == a or l == b) {
//         qs[num_q++] = {num_up, min(st[a], st[b]), max(st[a], st[b]), l, c, false, i};
//       } else {
//         qs[num_q++] = {num_up, min(en[a], en[b]), max(st[a], st[b]), l, c, true, i};
//       }
//       ans[i] = dist(a, b) + 1;
//       is_q[i] = true;
//     }
//   }
//   sort(qs, qs + num_q);
//   for(int i = 1; i <= n; i++) {
//     use[i] = vals[i];
//   }
//   int curr_l = 1, curr_r = 0, now = 0;
//   for(int i = 0; i < num_q; i++) {
//     while(now < qs[i].t) {
//       now++;
//       if(vis[up[now].u]) {
//         toggle(up[now].u);
//         use[up[now].u] = up[now].now;
//         toggle(up[now].u);
//       } else {
//         use[up[now].u] = up[now].now;
//       }
//     }
//     while(now > qs[i].t) {
//       if(vis[up[now].u]) {
//         toggle(up[now].u);
//         use[up[now].u] = up[now].before;
//         toggle(up[now].u);
//       } else {
//         use[up[now].u] = up[now].before;
//       }
//       now--;
//     }
//     while(curr_l < qs[i].l) {
//       toggle(inv[curr_l]);
//       curr_l++;
//     }
//     while(curr_l > qs[i].l) {
//       curr_l--;
//       toggle(inv[curr_l]);
//     }
//     while(curr_r < qs[i].r) {
//       curr_r++;
//       toggle(inv[curr_r]);
//     }
//     while(curr_r > qs[i].r) {
//       toggle(inv[curr_r]);
//       curr_r--;
//     }
//     ans[qs[i].idx] -= eval(qs[i].x);
//     if(qs[i].flag) {
//       assert(!vis[qs[i].lca]);
//       ans[qs[i].idx] -= gcd(use[qs[i].lca], qs[i].x) != 1;
//     }
//   }
//   for(int i = 0; i < q; i++) {
//     if(is_q[i]) {
//       printf("%d\n", ans[i]);
//     }
//   }
//   return 0;
// } 


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 50001;
const int M = 100001;
bool isprime[M];
int prime[9594];
int primecnt;
struct Update {
    int index,newvalue,previous_value;
};
struct Query {
    int index,left,right,updatestillnow,g;
};
int a[N],temp[N],ans[N];
int divcnt[M];
vector<Update> update;
vector<Query> query;
int block;
vector<int> Div[M];
bool comp(const Query &f,const Query &s) {
    int lindex = f.left/block;
    int loindex = s.left/block;
    if(lindex != loindex) return lindex < loindex;
    else {
        int rindex = f.right/block;
        int roindex = s.right/block;
        if(rindex != roindex) return rindex < roindex;
        return f.updatestillnow < s.updatestillnow;
    }
}
inline void add(int n,int v) {
 
}
void pre() {
  memset(isprime,true,sizeof isprime);
  //isprime[0] = isprime[1] = false;
  for(int i=2;i<=100000;i++) {
     if(isprime[i]) {
        for(int j=i;j<=100000;j+=i) {
            isprime[j] = false;
        }
        isprime[i] = true;
     }
  }
  for(int i=2;i<=100000;i++) {
    if(isprime[i] == true) {
        prime[primecnt++] = i;
    }
  }
  for(int i=1;i<=100000;i++) {
    int sq = sqrt(i);
    for(int j=1;j<=sq;j++) {
        if(i%j == 0) {
            int p = j;
            int q = i/j;
            if(p == q) {
                Div[i].push_back(p);
            }
            else {
                Div[i].push_back(p);
                Div[i].push_back(q);
            }
        }
    }
 
  }
}
int main() {
    //freopen("qns.txt","r",stdin);
    //freopen("ans.txt","w",stdout);
    pre();
    int n,q,t,index,newvalue,L,R,G;
    scanf("%d",&n);
    block = (int)pow(n,0.73);
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        temp[i] = a[i];
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++) {
        scanf("%d",&t);
        if(t == 1) {
            scanf("%d %d",&index,&newvalue);
            index--;
            update.push_back(Update{index,newvalue,temp[index]});
            temp[index] = newvalue;
        }
        else {
            scanf("%d %d %d",&L,&R,&G);
            L--; R--;
            query.push_back(Query{query.size(),L,R,update.size(),G});
        }
    }
    sort(query.begin(),query.end(),comp);
    int s = 0;
    int e = -1;
    int updateDoneTillNow = 0;
 
    int sz = query.size();
    for(int i=0;i<sz;i++) {
        Query qq = query[i];
        int left = qq.left;
        int right = qq.right;
        int qupdatestillnow = qq.updatestillnow;
        int index = qq.index;
        int g = qq.g;
 
        while(updateDoneTillNow < qupdatestillnow) {
            Update U = update[updateDoneTillNow];
            if(U.index >= s && U.index <= e) {
                for(int j=0;j<Div[a[U.index]].size();j++) {
                   divcnt[Div[a[U.index]][j]]--;
                }
            }
            a[U.index] = U.newvalue;
            if(U.index >= s && U.index <= e) {
                for(int j=0;j<Div[a[U.index]].size();j++) {
                   divcnt[Div[a[U.index]][j]]++;
                }
            }
            updateDoneTillNow++;
        }
        while(updateDoneTillNow > qupdatestillnow) {
            updateDoneTillNow--;
            Update U = update[updateDoneTillNow];
            if(U.index >= s && U.index <= e) {
                for(int j=0;j<Div[a[U.index]].size();j++) {
                   divcnt[Div[a[U.index]][j]]--;
                }
            }
            a[U.index] = U.previous_value;
            if(U.index >= s && U.index <= e) {
                for(int j=0;j<Div[a[U.index]].size();j++) {
                   divcnt[Div[a[U.index]][j]]++;
                }
            }
        }
        while(e < right) {
             e++;
             for(int j=0;j<Div[a[e]].size();j++) {
                   divcnt[Div[a[e]][j]]++;
             }
        }
        while(e > right) {
            for(int j=0;j<Div[a[e]].size();j++) {
                   divcnt[Div[a[e]][j]]--;
            }
            e--;
        }
        while(s < left) {
             for(int j=0;j<Div[a[s]].size();j++) {
                   divcnt[Div[a[s]][j]]--;
             }
             s++;
        }
        while(s > left) {
            s--;
            for(int j=0;j<Div[a[s]].size();j++) {
                   divcnt[Div[a[s]][j]]++;
            }
        }
        vector<int> x;
        for(int j=0;j<primecnt;j++) {
            int rp = prime[j];
            if(g < rp || g < 2) break;
            if(g%rp == 0) {
                x.push_back(rp);
                while(g%rp == 0) g /= rp;
            }
        }
        int cntRes = 0;
        int xsz = x.size();
        int upbnd = 1<<xsz;
        for(int j=1;j<upbnd;j++) {
            int cnt= 0;
            int prod = 1;
            for(int k=0;k<xsz;k++) {
                if(j & (1<<k)) {
                    cnt++;
                    prod *= x[k];
                }
            }
            if(cnt&1) cntRes += divcnt[prod];
            else cntRes -= divcnt[prod];
        }
        ans[index] = right-left+1-cntRes;
    }
    for(int i=0;i<sz;i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}