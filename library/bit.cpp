##include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <math.h>
#include <string>
#include <assert.h>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second


// int main() {
//     int n = 5;


//     for (int bit = 0; bit < (1<<n); ++bit)
//     {
//         set<int> st;
//         for (int i = 0; i < n; ++i) {
//             if (bit & (1<<i)) { 
//                 st.insert(i);
//             }
//         }
//     }
// }

// ABC128 C - Switches

int main(){
    int n,m; cin >> n >> m;
    vector<vector<int>>a(m);
    vector<int>p(m);
    for (int i = 0; i < m; i++)
    {
        int k; cin >> k;
        for (int j = 0; j < k; j++)
        {
            int s; cin >> s;
            a[i].push_back(s);
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }
    
    int ans = 0;
    for (int bit = 0; bit < (1<<n); bit++)
    {
        set<int>st;
        for (int i = 0; i < n; i++)
        {
            if(bit & (1<<i)){
                st.insert(i);
            }
        }
        vector<int>data(m);
        for (int o = 0; o < m; o++)
        {
            for (int k = 0; k < a[o].size(); k++)
            {
               if(st.find(k) != st.end()) data[m] ++;
            }
            
        }
        int tem;
        for (int j = 0; j < m; j++)
        {
            if(p[j] == data[j]) tem++;
        }
        chmax(ans,tem);
        
    }

    cout << ans << endl;
    return 0;
}
