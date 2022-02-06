#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INFL = 1LL << 60;
const ll inf = 1e15;

int main() {
    int n; cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    int m; cin >> m;
    vector<int>b(m);
    for (int i = 0; i < m; i++)
    {
      cin >> b[i];
    }
    
    for (int i = 0; i < m; i++)
    {
      int tem = b[i];
      bool flag = false;
      for (int bit = 0; bit < (1<<n); ++bit)
      {
          vector<int> S;
          int res = 0;
          for (int i = 0; i < n; ++i) {
              if (bit & (1<<i)) { 
                res += a[i];
              }
          }
          if(res == tem){
            cout << "yes" << endl;
            flag = true;
            break;
          }

      }
      if(!flag) cout << "no" << endl;
     
    }

    
    return 0;
}