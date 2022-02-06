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
vector<int>dx_odd={0,-1,0,1,1,1};
vector<int>dy_odd={-1,0,1,1,0,-1};
vector<int>dx_even={-1,-1,-1,0,1,0};
vector<int>dy_even={-1,0,1,1,0,-1};




bool judge(int nx, int ny){ 
  if(nx >= w || nx < 0 || ny >= h || ny < 0){
    return false;
  }
  return true;
}


int main() {
  cin >> w >> h;
  vector<vector<int>>a(h+2,vector<int>(w+2,0));
  vector<vector<int>>seen(h+2,vector<int>(w+2,0)); 
  vector<vector<int>>ans(h+2,vector<int>(w+2,0));
  int len = 0;
  int cnt = 0;

  for (int i = 1; i < h+1; i++)
  {
    for (int j = 1; j < w+1; j++)
    {
      cin >> a[i][j];
    }
    
  }

  for (int y = 1; y < h+1; y++)
  {
    for (int x = 1; x < w+1; x++)
    {
      queue<pair<int,int>> que;
      if(a[y][x] != 1 || seen[y][x] > 0) continue;
      cnt++;
      que.push(make_pair(x,y)); 
      seen[y][x] += 1;
      while (!que.empty()) {
        mpair v = que.front();
        que.pop();
        int cx = v.first;
        int cy = v.second;
        // a[y][x] == 1の時
        // 6方向分のdirection場合分け
        for (int d = 0; d < 6; d++)
        {
          int nx,ny;
          if(cy%2 == 0){
            nx = cx + dx_even[d];
            ny = cy + dy_even[d];
          }else{
            nx = cx + dx_odd[d];
            ny = cy + dy_odd[d];
          } 
          
          if(a[ny][nx] != 1){
            // if(nx == 1 && ny == 5){
            //   cout << "mistake" <<  endl;
            //   cout << "cx " << cx << " cy " << cy << endl;
            // }
            ans[ny][nx] ++;
            continue;
          }
          
          if(seen[ny][nx] > 0) continue; 
          // これ以降は，未探索，探索可能地点
          que.push(make_pair(nx,ny));

          seen[ny][nx] += 1;
          

        }

      }
      
      
    }
    
  }
  for (int i = 0; i < h+2; i++)
  {
    for (int j = 0; j < w+2; j++)
    {
      if(ans[i][j] == 6) continue;
      len += ans[i][j];
    }
    
  }

  cout << endl;
  for (int i = 0; i < h+2; i++)
  {
    for (int j = 0; j < w+2; j++)
    {
      cout << ans[i][j] << " " ;
    }
    cout << endl;
    
  }
  cout << endl;
  for (int i = 0; i < h+2; i++)
  {
    for (int j = 0; j < w+2; j++)
    {
      cout << seen[i][j] << " " ;
    }
    cout << endl;
    
  }
  cout << cnt << endl;
  
  cout << len << endl;
  return 0;
}

// この解法だと囲まれた場合の加算処理がうまくいかないと思ったけど，
// a[y][x] 自身ではなくa[ny][nx] に加算していき，合計6のだけ除外すれば可能．
// だと思ったけど塊で囲まれた時，除外処理が面倒になるので，やはり，下記の外枠を塗りつぶす方針が最適だろう．




// bool judge(int nx, int ny){ 
//   if(nx >= w+2 || nx < 0 || ny >= h+2 || ny < 0){
//     return false;
//   }
//   return true;
// }


// int main() {
//   int n;
//   cin >> w >> h;
//   vector<vector<int>>a(h+2,vector<int>(w+2,0)); 
//   vector<vector<int>>ans(h+2,vector<int>(w+2,0));
//   int len = 0;

//   for (int i = 1; i < h+1; i++)
//   {
//     for (int j = 1; j < w+1; j++)
//     {
//       cin >> a[i][j];
//     }
    
//   }
//   queue<pair<int,int>> que;
//   que.push(make_pair(0,0)); 
//   while (!que.empty()) {
//     mpair v = que.front();
//     que.pop();
//     int cx = v.first;
//     int cy = v.second;

//     // 6方向分のdirection場合分け
//     for (int d = 0; d < 6; d++)
//     {
//       int nx,ny;
//       if(cy%2 == 0){
//         nx = cx + dx_even[d];
//         ny = cy + dy_even[d];
//       }else{
//         nx = cx + dx_odd[d];
//         ny = cy + dy_odd[d];
//       } 
      
//       if(!judge(nx,ny) || a[ny][nx] == 1 || ans[ny][nx] == 1) continue;
//       // これ以降は，未探索，探索可能地点
//       ans[ny][nx] = 1;
//       que.push(mpair(nx,ny));

//     }

//   }
//   // cout << endl;
//   // for (int i = 0; i < h+2; i++)
//   // {
//   //   for (int j = 0; j < w+2; j++)
//   //   {
//   //     cout << ans[i][j] << " ";
//   //   }
//   //   cout << endl;
    
//   // }
  

//   for (int y = 0; y < h+2; y++)
//   {
//     for (int x = 0; x < w+2; x++)
//     {
//       if(ans[y][x] == 1){
//         for (int d = 0; d < 6; d++)
//         {
//           int nx,ny;
//           if(y%2 == 0){
//             nx = x + dx_even[d];
//             ny = y + dy_even[d];
//           }else{
//             nx = x + dx_odd[d];
//             ny = y + dy_odd[d];
//           } 
//           if(!judge(nx,ny)) continue;
//           if(a[ny][nx] == 1) {
//             len ++;
//             // cout << "x " << x << " y " << y << endl;
//             // cout << "ny " << ny << " nx " << nx << endl;
//           }
//         }
        
//       }

//     }
    
//   }
    
  
//   cout << len << endl;
//   return 0;
// }

// 建物の内側を含めない外枠を加算していくには，
// 範囲を増やしつつ周りを幅優先探索で塗りつぶせば，外枠だけ加算していくことができる．