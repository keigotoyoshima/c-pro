#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INFL = 1LL << 60;
const ll inf = 1e6;


// class Radix {
// private:
//   const char* s;
//   int a[128]; 
// public:
//   Radix(const char* s = "0123456789ABCDEF") : s(s) {
//     int i;
//     for(i = 0; s[i]; ++i)
//       a[(int)s[i]] = i;
//   }
//   std::string to(long long p, int q) {
//     int i;
//     if(!p)
//       return "0";
//     char t[64] = { };
//     for(i = 62; p; --i) {
//       t[i] = s[p % q];
//       p /= q;
//     }
//     return std::string(t + i + 1);
//   }
//   std::string to(const std::string& t, int p, int q) {
//     return to(to(t, p), q);
//   }
//   long long to(const std::string& t, int p) {
//     cout <<"long long" << endl;
//     int i;
//     long long sm = a[(int)t[0]];
//     for(i = 1; i < (int)t.length(); ++i)
//       sm = sm * p + a[(int)t[i]];
//     return sm;
//   }
// };

int main() {
  string x; cin >> x;
  ll m; cin >> m;
  ll max_x = 0;
  if(x.size()==1){
    if (stoi(x)<=m)
    {
      cout << 1 << endl;
    }
    else {
      cout << 0 << endl;
    }
    return 0;
  }
  for (int i = 0; i < x.size(); i++)
  {
    chmax(max_x, (ll)x[i] - '0');
  }
  

  ll ok = max_x;
  ll ng = m+1;

  while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    // cout << "mid " << mid << endl;
    
    ll v = 0;
    for (int i = 0; i < x.size(); i++)
    {
      if(v > m/mid) {
        v = m+1;
        // cout <<"break " << "mid " << mid << endl;
        break;
      }
      v = v*mid + (x[i] - '0');
    }
    
    if (v <= m) ok = mid;
    else {
      ng = mid;
      // cout << "mid " << mid << " ng " << endl;
    }
    // cout << "ok " << ok << "ng " << ng << endl;
  }
  // cout << "ok " << ok << endl;

  cout << ok - max_x << endl;
  
  
  



//   cout << endl;
//   // 10 進数を n 進文字列に
//   std::cout << r.to(255, 10) << std::endl; // => "255"
//   std::cout << r.to(255, 12) << std::endl; // => "193"
//   std::cout << r.to(255, 16) << std::endl; // => "FF"
// // 16進数は0から15を1桁で表わすため、0~9は10進数と同じで、
// // 10進数の10=A､11=B、12=C、13=D､14=E、15=Fと書きます｡
// // したがってFFは15×16^1+15で255です。
//   cout << "test " << r.to(999,12) << endl;
//   cout << "test " << r.to(999,11) << endl;
//   cout << "test " << r.to("999",11) << endl;









 
  // n 進文字列を 10 進数に
  // std::cout << r.to("255", 10) << std::endl; // => 255
  // std::cout << r.to("255", 14) << std::endl; // => 467

  // // n 進文字列を m 進文字列に
  // std::cout << r.to("255", 7, 11) << std::endl; // => "116"
  // std::cout << r.to("255", 11, 7) << std::endl; // => "611"
  return 0;
}

