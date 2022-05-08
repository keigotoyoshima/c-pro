#include <iostream>
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
using namespace std;
using ll = long long;
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
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool isZenkaku(char c)
{
  // 1byteだと先頭ビットが1なら0x80(２進数10000000)
  if (c & 0x80)
    return 1;
  return 0;
}
int main()
{
  string s;
  cin >> s;
  cout << s.size() << endl;
  cout << s.length() << endl;
  cout << s << endl;
  size_t one_char = 3;

  for (int i = 0; i < s.size(); i++)
  {
    if (isZenkaku(s[i]))
    {
      cout << "全角 " << s.substr(i, one_char) << endl;
      string res = s.substr(i, one_char);
      cout << "res " << res << endl;
      i += 2;
    }
    else
    {
      cout << "半角 " << s[i] << endl;
    }
  }
  return 0;
}