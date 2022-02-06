#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for(auto &x: a) cin >> x;
  vector<ll>order(n);
  vector<ll>answer(n, k/n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j){return a[i] < a[j];  });
  for (int i = 0; i < k%n; i++)
  {
    answer[order[i]]++;
  }

  for(auto x : answer) cout << x << endl;
  return 0;
}
