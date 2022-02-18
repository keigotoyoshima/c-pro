#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
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
const long long INFL = 1LL << 60;
const ll inf = 1e15;




// bool judge(int l, int r, string s){
//   while (l>=0)
//   {
//     if(s[l]!=s[r]) return false;
//     --l;++r;
//   }
//   return true;
// }


// vectorでの実装
// int main()
// {


//   string s; cin >> s;
//   int index = s.size() - 1;
//   int end_a = 0;
//   while (1)
//   {
//     if(s[index] == 'a'){
//       ++ end_a;
//     }else{
//      break; 
//     }
//     --index;
//   }
//   int start_a = 0;
//   index = 0;
//   while (1)
//   {
//     if (s[index] == 'a')
//     {
//       ++start_a;
//     }
//     else
//     {
//       break;
//     }
//     ++index;
//   }
//   int add_a = end_a - start_a;
//   if(add_a < 0) {
//     cout << "No" << endl;
//     return 0;
//   }
//   int final_size = s.size() + add_a;
//   int even_odd = final_size % 2;
//   int mid = final_size / 2 - add_a;
//   bool flag;
//   if(even_odd){
//     // 奇数の時 
//     flag =  judge(mid-1, mid+1, s);
//   }else{
//     // 偶数の時
//     flag = judge(mid-1,mid, s);
//   }
//   if(flag){
//     cout <<"Yes" << endl;
//     return 0;
//   }else{
//     cout <<"No" << endl;
//   }
//   return 0;
// }

bool judge(int l, int r, deque<char> de)
{
  while (l >= 0)
  {
    if (de[l] != de[r])
      return false;
    --l;
    ++r;
  }
  return true;
}

// dequeを使った実装
int main()
{

  string s;
  cin >> s;
  deque<char>de;
  for(auto v: s){
    de.push_back(v);
  }
  
  int index = s.size() - 1;
  int end_a = 0;
  while (1)
  {
    if (s[index] == 'a')
    {
      ++end_a;
    }
    else
    {
      break;
    }
    --index;
  }
  int start_a = 0;
  index = 0;
  while (1)
  {
    if (s[index] == 'a')
    {
      ++start_a;
    }
    else
    {
      break;
    }
    ++index;
  }
  int add_a = end_a - start_a;
  if (add_a < 0)
  {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < add_a; i++)
  {
    de.push_front('a');
  }
  
  int final_size = s.size() + add_a;
  int even_odd = final_size % 2;
  int mid = final_size / 2;
  bool flag;
  if (even_odd)
  {
    // 奇数の時
    flag = judge(mid - 1, mid + 1, de);
  }
  else
  {
    // 偶数の時
    flag = judge(mid - 1, mid, de);
  }
  if (flag)
  {
    cout << "Yes" << endl;
    return 0;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}