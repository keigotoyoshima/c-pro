#include <algorithm>
#include <iostream>
#include <algorithm>
#include<vector>
#include<stack>
#include <string>
#include <numeric>

using namespace std;
using ll = long long;


int main(){
  int n; cin >> n;
  vector<int>s(n);
  vector<int>t(n);
  vector<int>status(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) cin >> t[i];
  status = t;

  for (int i = 0; i < 2*n; i++)
  {
    int a = s[i%n];
    status[(i+1)%n] = min(status[(i+1)%n], status[i%n] + a);
  }

  for (int i = 0; i < n; i++)
  {
    cout << status[i] << endl;
  }
  
 
  
  

  return 0;
}
