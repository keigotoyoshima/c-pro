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
// 問題abc157 d

// https://esakat.github.io/esakat-blog/posts/about-union-find/
// union by size による実装
// 「各連結成分のサイズ」も自然に取得できる
struct UnionFind {
    /**
     * parで親の頂点番号と、サイズを同時に管理する
     * 根ではない頂点のparは親となる頂点の値が入ってる
     * 根にはサイズ数が入っている。区別できるようにサイズはマイナスの値で入っている
     * そのため、初期値はすべて-1になる(mergeの際にmergeされる側の根に、mergeする方の根が加算される)
     */
    vector<int> par;

    // constructor
    UnionFind(int n) : par(n, -1) {}
    // initialize
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool isSame(int x, int y) {
        return root(x) == root(y);
    }

    // 以下は必ずxが大きいほう(サイズはマイナスの値が入ってるので)にするように調整している
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