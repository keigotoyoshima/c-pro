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

int h,w;

bool judge(int ni, int nj){
  if(ni >= h || ni < 0 || nj >= w || nj < 0){
    return false;
  }
  return true;
}


int main() {
  int n;
  cin >> h >> w >> n;

  vector<string>a(h);
  
  int si = 0;
  int sj = 0;
  //縦がi, 横がj
  for (int i = 0; i < h; ++i) {
    cin >> a[i];
    for (int j = 0; j < w; j++)
    {
      if(a[i][j] == 'S') {
        si = i;
        sj = j;
      }
    }
    
  }



  int ans = 0;
  for (int target_int = 1; target_int < n+1; target_int++)
  {
    vector<vector<int>>res(h,vector<int>(w,-1));
    queue<pair<int,int>> que;

    // i,jの順で入れる
    que.push(make_pair(si,sj)); 
    res[si][sj] = 0;
    vector<int>direction={-1,1};
    char target = target_int + '0';
    bool flag = true;
    while (!que.empty() && flag) {
      mpair v = que.front(); 
      int cj = v.second;
      int ci = v.first;
      que.pop();
      for (int i = 0; i < 2; i++)
      {
        for (int j = 0; j < 2; j++)
        {
          int plus_j = 0;
          int plus_i = 0;
          if(i == 0){
            plus_j = direction[j];
          }else{  
            plus_i = direction[j];
          }

          int ni = ci + plus_i;
          int nj = cj + plus_j;

          if(!judge(ni,nj) || a[ni][nj] == 'X' || res[ni][nj] != -1) continue;
          res[ni][nj] = res[ci][cj] + 1;
          que.push(make_pair(ni,nj));
          if(a[ni][nj] == target){
            si = ni;
            sj = nj;
            ans += res[ni][nj];
            flag = false;
            break;
          }
          
        }
      }

    }
  }


  
  
  
  
  
  cout << ans << endl;
  return 0;
}

// 特になし 