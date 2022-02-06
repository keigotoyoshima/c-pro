#include <stdio.h>
#include <stdint.h>
#include<vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>  
#include <math.h>
using namespace std;	
using ll = long long;

// https://esakat.github.io/esakat-blog/posts/about-union-find/
// union by size による実装
// 「各連結成分のサイズ」も自然に取得できる
struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    UnionFind uf(N);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        uf.merge(a, b);
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        res = max(res, uf.size(i));
    }
    cout << res << endl;
}