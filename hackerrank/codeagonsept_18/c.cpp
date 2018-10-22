#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, ara[300009];

struct trie {
    vector <ll> indx;
    trie *nxt[2];

    trie() {
        nxt[0] = nullptr;
        nxt[1] = nullptr;
        indx.clear();
    }
};

trie *start = new trie();

void build()

{
    for(ll k = 1; k <= n; k++) {
        ll num = ara[k];
        trie *cur = start;

        for(ll i = 30; i >= 0; i--) {
            ll bit = (num >> i) & 1;

            if(cur -> nxt[bit] == nullptr)
                cur -> nxt[bit] = new trie();

            cur = cur -> nxt[bit];
            cur -> indx.push_back(k);
        }
    }
}

ll query(ll l, ll r, ll x)

{
    ll xr = 0;
    trie *cur = start, *cur2 = nullptr;
    for(ll i = 30; i >= 0; i--) {

        ll bit = (x >> i) & 1;
        bool flag = 0;

        if(cur -> nxt[bit ^ 1] != nullptr) {
            cur2 = cur -> nxt[bit ^ 1];
            ll pos = lower_bound(cur2 -> indx.begin(), cur2 -> indx.end(), l) - cur2 -> indx.begin();
            if(cur2 -> indx[pos] >= l && cur2 -> indx[pos] <= r) {
                flag = 1;
                xr = (xr << 1) + 1;
                cur = cur2;
            }
            else if(cur -> nxt[bit] == nullptr)
                return 0;
        }

        if(cur -> nxt[bit] != nullptr && flag == 0) {
            cur2 = cur -> nxt[bit];
            /*ll pos = lower_bound(cur2 -> indx.begin(), cur2 -> indx.end(), l) - cur2 -> indx.begin();
            if(cur2 -> indx[pos] >= l && cur2 -> indx[pos] <= r) {
                xr <<= 1;
                cur = cur2;
            }
            else
                return 0;*/
            xr <<= 1;
            cur = cur2;
        }

    }

    return xr;
}

int main(){
    const int n = 1e5;
    for(ll i = 0; i < n; i++)
        ara[i] = i+1;
    build();
    ll q;
    cin >> q;
    for(ll i = 1; i <= q; i++) {
        ll l, r, x;
        scanf("%lld %lld %lld", &x, &l, &r);
        ll ans = query(l, r, x);
        printf("%lld\n", ans);
    }
    return 0;
}
