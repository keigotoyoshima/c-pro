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

  int main(){
    int k; cin >> k;
    vector<int>x(k);
    vector<int>y(k);
    for (int i = 0; i < k; i++)
    {
      cin >> x[i] >> y[i];
    }
    vector<int> v(8);
    // 第3引数は、v[0]の値
    iota(v.begin(), v.end(), 0);  
    vector<string>res;
    do{
      // 入力と相違がある場合はcontinue;
      bool flag_k = true;
      for (int i = 0; i < k; i++)
      {
        int tem_x = x[i];
        int tem_y = y[i];
        if(v[tem_y] != tem_x){
          flag_k = false;
          break;
        }
        // cout << "v[tem_y] " << v[tem_y] << " tem_x " << tem_x << " tem_y " << tem_y <<endl;
      }
      if(!flag_k) continue;
      
      set<int>st_rc;
      set<int>st_lc;
      bool flag = true;
      vector<string>ans(8);

      // iが縦軸、v[i]が横軸の値で、順列を作成。
        for(int i=0; i<8; i++){
          int h = i;
          int w = v[i];
          int rc = h+w; int lc = h-w;
          // どちらかが既に存在していた場合
          if(st_rc.find(rc) != st_rc.end() || st_lc.find(lc) != st_lc.end()) {
            flag = false;
            break;
          }
          st_rc.insert(rc); st_lc.insert(lc);
          string str(8, '.');   
          str[w]  = 'Q';
          ans[i] = str;
        }
        if(flag) res = ans;
      }while(next_permutation(v.begin(),v.end()));
    
    for (int i = 0; i < 8; i++)
    {
      cout << res[i] << endl;
    }
    
    return 0;

  }