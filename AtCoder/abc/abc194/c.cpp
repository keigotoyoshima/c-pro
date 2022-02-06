  #include <stdio.h>
  #include <stdint.h>
  #include<vector>
  #include <string>
  #include <iostream>
  #include <algorithm>
  using namespace std;

  const int Max = 200;

  int main(){
    int n; 
    cin >> n;

    vector<int>arr(Max*2+1);
    for(int i = 0; i < n; i++){
      int a;
      cin >> a;
      arr[Max+a]++;
    }

    long long ans = 0;

    for (int i = 1; i <= Max*2+1; i++)
    {
      for (int j = 0; j < i; j++)
      {
        long long pre = i - j;
        ans += pre*pre*arr[i]*arr[j];
      }
    }
    cout << ans << endl;
    return 0;
  }