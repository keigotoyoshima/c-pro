#include <algorithm>
#include <iostream>
#include <algorithm>
#include<vector>
#include<stack>
#include <string>
#include <numeric>

using namespace std;
using ll = long long;

int danken(int l, char ls, int r, char rs){
  int winer = -1;
  if (ls == 'G' && rs == 'C'){
    winer = l;
  } else if (ls == 'G' && rs == 'P')
  {
    winer = r;
  } else if (ls == 'P' && rs == 'G')
  {
    winer = l;
  } else if (ls == 'P' && rs == 'C')
  {
    winer = r;
  } else if (ls == 'C' && rs == 'G')
  {
    winer = r;
  } else if (ls == 'C' && rs == 'P')
  {
    winer = l;
  } 
  
  return winer;
}



int main(){
  int n, m;
  cin >> n >> m;
  int len = n*2;

  vector<string>a(len);
  vector<int>res(len,0);
  vector<int>order(len);
  iota(order.begin(), order.end(), 0);

  for (int i = 0; i < len; i++)
  {
    cin >> a[i];
  }
  for (int j = 0; j < m; j++)
  {
    for (int i = 0; i < n; i++)
    {
      int person_a = order[2*i];
      int person_b = order[2*i+1];
      char ls = a[person_a][j];
      char rs = a[person_b][j];
      int winer_int  = danken(person_a,ls,person_b,rs);
      if(0 <= winer_int )  res[winer_int]++;
    }
    sort(order.begin(), order.end(), [&](int l, int r){
      if(res[l] != res[r]) return res[l] > res[r];

      return l < r;
    });
  }
  for(auto k: order){
    cout << k + 1 << endl;
  }


  return 0;
}