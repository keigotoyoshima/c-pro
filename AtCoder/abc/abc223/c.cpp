#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <deque>  
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
  int n; cin >> n;
  double sum = 0;
  vector<pair<double,double>>v(n);
  vector<double>w(n);
  for (int i = 0; i < n; i++)
  {
    double a, b; cin >> a >> b;
    v[i].first = a; v[i].second = b;
    sum += a/b;
    w[i] = a/b;
  }
  double half = sum / 2;
  double time = 0;
  int cur = 0;
  double ans = 0;
  while (time <= half)
  {
    time += w[cur];
    ans += v[cur].first;
    ++ cur;
  }
  -- cur;

  double overs = time - half;
  ans -= v[cur].second*overs;
  printf("%.10f", ans);
  cout << endl;
}