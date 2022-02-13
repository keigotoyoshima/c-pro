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
    #include<math.h>
    using namespace std;
    using ll = long long;
    template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
    template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
    const long long INFL = 1LL << 60;
    const ll inf_ll = 1e15;
    int inf_int = 2147483647;
    using mpair = pair<int,int>;
    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};
    const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

    int main(){
      ll n; cin >> n;
      vector<ll>c(n);
      for (int i = 0; i < n; i++)
      {
        cin >> c[i];
      }
      vector<vector<ll>>dp(n+10, vector<ll>(31,0));
      // 0番目を選んだ時
      dp[1][c[0]] = 1;
      // 計算するcはn-1個
      for (int i = 1; i < n-1; i++)
      {
        for (int j = 0; j < 21; j++)
        {
          // dp[i+1]はcのi番目を選んだか選んでないか
          if(j-c[i]>=0) dp[i+1][j] += dp[i][j-c[i]];
          if(j+c[i]<=20) dp[i+1][j] += dp[i][j+c[i]];
        }
        
      }

      cout << dp[n-1][c[n-1]] << endl;
      

    }