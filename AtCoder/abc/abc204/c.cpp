#include <stdio.h>
#include <stdint.h>
#include<vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>  
#include <math.h>
using namespace std;	
using ll = long long;


using Graph = vector<vector<int>>;
vector<bool> temp;

void dfs(const Graph &G, int v){
   temp[v] = true; 
    for (auto next_v : G[v]) { 
        if (temp[next_v]) continue; 
        dfs(G, next_v); 
    }
}


int main(){
  int n,m; cin >> n >> m;
  Graph G(n);
  int ans = 0;
  temp.resize(n);
  
  for (int i = 0; i < m; i++)
  {
    int a,b; cin >> a >> b;
    --a;--b;
    G[a].push_back(b);
  }

  for (int i = 0; i < n; i++)
  {
    for(int j = 0;  j < n; j++)temp[j] = false;
    dfs(G,i);
    for (int j = 0; j < n; j++)if(temp[j])ans++;
  }
  cout << ans << endl;

	return 0;
}
