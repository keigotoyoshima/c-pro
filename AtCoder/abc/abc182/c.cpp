#include <stdio.h>
#include <stdint.h>

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 100100;





int main() {
	string s;
	cin >> s;
  int c[3] = {};
	int len = s.size();
	for(int i = 0; i < len; i++){
		int k = s[i]%3;
		c[k]++;
	}
	int x = 0;
	for(int i = 0; i < 3; i++){
		x += c[i]*i;
	}
	int ans = INF;
	// iは1を何個消すか、jは2を何個消すか

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(c[1] < i) continue;
			if(c[2] < j) continue;	
			if(i + j == len) continue;
			int nx = x;
			nx -= i*1;
			nx -= j*2;
			if(nx % 3 == 0) ans = min(ans, i + j);
		}
	}
	if(ans == INF) ans = -1;
  cout << ans << endl;
  
  return 0;
}