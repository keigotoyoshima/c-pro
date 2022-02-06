#include <iostream>
#include <vector>
#include <queue>
#include <deque>  
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main() {
  int n; cin >> n;
  int red = 0; int white = 0;
  string str(n, ' ');
  for (int i = 0; i < n; i++)
  {
    cin >> str[i];
    if(str[i] == 'R'){
      ++ red;
    } else{
      ++ white;
    }
  }
  int ans = 0;

  for (int i = 0; i < red; i++)
  {
    if(str[i] == 'W') ans++;
  }

  cout << ans << endl;
  
  
  
  return 0;
}

