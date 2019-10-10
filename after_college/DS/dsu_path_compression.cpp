#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+10;
int parent[MAX];

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if(v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)  {
    int x = find_set(a);
    int y = find_set(b);
    if(x != y) {
        parent[y] = x;
    }
}

int main() {
    for(int i = 1; i < 10; i++) {
        make_set(i);
    }
    union_set(1,2);
    union_set(1,3);
    union_set(1,4);
    assert(find_set(1) == 1);
    assert(find_set(4) == 1);
    return 0;
}