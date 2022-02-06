#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INFL = 1LL << 60;
const int inf = 1e6;

int main(){
  int n,m; cin >> n >> m;
  vector<vector<int>>ab(n);
  vector<vector<int>>cd(n);
  for (int i = 0; i < m; i++)
  {
    int a,b; cin >> a >> b;
    --a; --b;
    ab[a].push_back(b);
    ab[b].push_back(a);
    // ab[a][b] = true;
    // ab[b][a] = true;
  }
  for (int i = 0; i < m; i++)
  {
    int a,b; cin >> a >> b;
    --a; --b;
    cd[a].push_back(b);
    cd[b].push_back(a);
    // cd[a][b] = true;
    // cd[b][a] = true;
  }
  
  vector<int>v(n);
  iota(v.begin(),v.end(), 0);
  // for(auto k: v) cout << k << " ";
  // cout << endl;
  do{
      bool flag = true;
      // for (int i = 0; i < n; i++)
      // {
      //   for (int j = 0; j < n; j++)
      //   {
      //     if(ab[i][j] != cd[v[i]][v[j]]){
      //       flag = false;
      //     }
      //   }
      // }
      
      for(int i=0; i<n; i++){
        int tem = v[i];
        if(ab[tem].size() != cd[i].size()){
          flag = false;
          break;
        } 
      }
      if(flag) {
        cout << "Yes" << endl;
        return 0;
      }
    }while(next_permutation(v.begin(),v.end()));

  cout << "No" << endl;
  return 0;
}