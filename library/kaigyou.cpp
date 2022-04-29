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

// aaa bbb ccc
// ddd eee fff

// 文字列を読み込んでそれが改行コードか，文字列かを識別できればいい．
// 先頭文字列をcin.get()で半角読み込みをすると，文末の改行と文頭の改行の判断が難しくなる．かといって，文末でcin.get()やcin.ignore()をして文末の改行コードを取り除いた場合，cinがスペースや改行コードを区切り文字として入力待ちをする性質があるので，改行コードという区切り文字を取り除く形となり，入力が進まない現象が起きる．そのため，二つ目の入力に対して，cin.get()を行い，それが空白じゃない場合は，入力をやめるという処理にすれば，最終行の改行までの入力が達成できる．つまり，最終行の改行を文字列として入力し，それが改行コードかどうかを認識するために，次のinputが空白かどうかを識別する．

int main()
{
  vector<string> s;
  int roop = 0;
  vector<string> a;
  vector<string> b;
  vector<string> c;
  string tem;

  while (cin >> tem)
  {
    string tem2;
    int c1 = cin.get();
    if (c1 != ' ')
    {
      break;
    }
    cin >> tem2;
    string tem3;
    cin >> tem3;
    a.push_back(tem);
    b.push_back(tem2);
    c.push_back(tem3);
  }
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < b.size(); i++)
  {
    cout << b[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < c.size(); i++)
  {
    cout << c[i] << " ";
  }
  cout << endl;

  return 0;
}