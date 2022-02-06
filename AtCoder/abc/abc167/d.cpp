#include <iostream>
#include <vector>
#include <queue>
#include <deque>  
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main() {
  int n;
  ll k; 
  cin >> n >> k;
  vector<int>a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    --a[i];
  }

  deque<int> v;
  vector<bool>seen(n, false);
  int cur = 0;
  while (true)
  {
    if(seen[cur]){
      while (v[0] != cur)
      {
        --k;
        v.pop_front();
        if(k == 0){
          cout << v[0]+1 << endl;
          return 0;
        }
      }
      break;
    }
    seen[cur] = true;
    v.push_back(cur);
    cur = a[cur];
  }

  cout << v[k%v.size()] + 1 << endl;
  
}