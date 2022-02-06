#include <iostream>
#include <vector>
#include <queue>
#include <deque>  
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main() {
  ll x; cin >> x;
  for (int a = -120; a <= 120; a++)
  {
    for (int b = -120; b <= 120; b++)
    {
      if (a*a*a*a*a - b*b*b*b*b == x) {
        cout << a << " " << b << endl;
        return 0;
      }
    }
    
  }
  
  return 0;
}

