#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <string>
#include <assert.h>
#include <functional>
using namespace std;
using ll = long long;
#define fi first
#define se second
template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int MOD = 1000000007;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main()
{
  int n;
  cin >> n;
  vector<ll> B(3);
  for (int i = 0; i < 3; i++)
  {
    cin >> B[i];
  }
  vector<int> A(n);
  for (auto &v : A)
    cin >> v;
  vector<ll> S(n + 1);
  set<ll> st;
  for (int i = 0; i < n; i++)
  {
    S[i + 1] = S[i] + A[i];
    // insertの計算量はO(logn)
    st.insert(S[i + 1]);
  }
  for (int x = 0; x < n+1; x++)
  {
    ll tem = S[x];
    for (int i = 0; i < 3; i++)
    {
      tem += B[i];
      // findの計算量はO(log(n))
      if (st.find(tem) == st.end())
        break;
      if (i == 2)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  return 0;
}