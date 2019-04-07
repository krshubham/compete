#include <bits/stdc++.h>
using namespace std;

#define DEBUG 0
#define NMAX 211111
#define LOGMAX 20

int bit[LOGMAX];

void ComputeBits() {
    int i;
    bit[0] = 1;
    for (i = 1; i < LOGMAX; i++){
        bit[i] = bit[i - 1] * 2;
    }
}

char S[NMAX];
int LS;

int group[LOGMAX + 1][NMAX], vs[NMAX], o[NMAX];
vector<pair<int, int> > vps;
vector<pair<pair<int, int>, int> > vps2;

void SuffixArray() {
    int i, j, r, ng = 0;

    vps.resize(LS);
    for (i = 1; i <= LS; i++) {
        vps[i - 1].first = (int) S[i];
        vps[i - 1].second = i;
    }

    sort(vps.begin(), vps.end());
    ng = 0;
    group[0][vps[0].second] = 0;
    vs[1] = vps[0].second;
    for (i = 1; i < LS; i++) {
        if (vps[i].first != vps[i - 1].first)
            ng++;
        group[0][vps[i].second] = ng;
        vs[i + 1] = vps[i].second;
    }
    ng++;

    vps2.resize(LS);
    for (r = 0; r < LOGMAX; r++) {
        for (i = 1; i <= LS; i++) {
            vps2[i - 1].first.first = group[r][vs[i]];
            j = vs[i] + bit[r];
            if (j <= LS)
                vps2[i - 1].first.second = group[r][j];
            else
                vps2[i - 1].first.second = ng;
            vps2[i - 1].second = vs[i];
        }

        sort(vps2.begin(), vps2.end());
        for (i = 0; i < LS; i++)
            vs[i + 1] = vps2[i].second;

        ng = 0;
        group[r + 1][vs[1]] = 0;

        for (i = 2; i <= LS; i++) {
            if (group[r][vs[i]] != group[r][vs[i - 1]] ||
                vs[i] + bit[r] > LS ||
                vs[i - 1] + bit[r] > LS ||
                group[r][vs[i] + bit[r]] != group[r][vs[i - 1] + bit[r]])
                ng++;
            group[r + 1][vs[i]] = ng;
        }

        ng++;
    }

    for (i = 1; i <= LS; i++){
        o[vs[i]] = i;
    }
}

int lcp[NMAX];

void ComputeLCPs() {
    int i, j, p, q;

    lcp[1] = 0;
    
    for (i = 2; i <= LS; i++) {
        p = vs[i];
        q = vs[i - 1];
        lcp[i] = 0;

        for (j = LOGMAX - 1; j >= 0 && p <= LS && q <= LS; j--) {
            if (group[j][p] == group[j][q]) {
                lcp[i] += bit[j];
                p += bit[j];
                q += bit[j];
            }
        }
    }
}

long long psum[NMAX];

void ComputePrefixSums() {
    int i;
    long long ndif;
    psum[0] = 0;
    for (i = 1; i <= LS; i++) {
        ndif = (long long) ((LS - vs[i] + 1) - lcp[i]);
        psum[i] = psum[i - 1] + ndif * lcp[i] + ndif * (ndif + 1) / 2;
    }
}

char Query(long long K) {
    int li, ls, mid, sidx = 0, ssidx;
    long long len;

    li = 1; ls = LS;
    while (li <= ls) {
        mid = (li + ls) >> 1;
        if (psum[mid] < K) {
            sidx = mid;
            li = mid + 1;
        } else
        ls = mid - 1;
    }
    K -= psum[sidx];
    sidx++;
    int ndif = (LS - vs[sidx] + 1) - lcp[sidx];
    li = 1; ls = ndif; ssidx = 0;
    while (li <= ls) {
        mid = (li + ls) >> 1;
        len = (long long) mid * lcp[sidx] + ((long long) mid * (long long) (mid + 1)) / 2;
        if (len < K) {
            ssidx = mid;
            li = mid + 1;
        } else
        ls = mid - 1;
    }

    len = (long long) ssidx * lcp[sidx] + ((long long) ssidx * (long long) (ssidx + 1)) / 2;
    K -= len;
    return S[vs[sidx] + K - 1];
}

long long mulmod(long long a, long long b, long long mod){
    long long res = 0;
    a = a % mod;
    while (b > 0){
        if (b % 2 == 1){
            res = (res + a) % mod;
        }
        a = (a * 2) % mod;
        b /= 2;
    }
    return res % mod;
}

int main() {
    ComputeBits();
    // scanf("%s", S + 1);
    for (int i = 0; i < count; ++i){
        /* code */
    }
    LS = strlen(S + 1);
    SuffixArray();
    ComputeLCPs();
    ComputePrefixSums();
    int T;  
    long long K;
    scanf("%d", &T);
    long long p,m,g;
    g = 0;
    while (T--) {
        cin>>p>>m;
        K = mulmod(p,g,m)+1;
        // printf("%c\n", Query(K));
        char cc = Query(K);
        g += cc;
        cout<<cc<<endl;
    }

    return 0;
} 