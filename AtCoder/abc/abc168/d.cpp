#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// using Graph = vector<vector<int>>;

// int main() {
//     int n, m; cin >> n >> m;



//     Graph g(n);
//     for (int i = 0; i < m; ++i) {
//         int a, b;
//         cin >> a >> b;--a;--b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }


//     vector<int> dist(n, -1); 
//     queue<int> que;
//     vector<int>prev(n);



//     dist[0] = 0;
//     que.push(0); 


//     while (!que.empty()) {
//         int v = que.front();    
//         que.pop();


//         for (int nv : g[v]) {
//             if (dist[nv] != -1) continue; 
//             dist[nv] = dist[v] + 1;
//             prev[nv] = v;
//             que.push(nv);
//         } 

//     }
//     cout << "Yes" << endl;
   
//     for (int i = 1; i < n; i++)
//     {
//         cout << prev[i] + 1 << endl;
//     }
    
// }

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>>data(n);
    for (int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        a--;
        b--;
        data[a].push_back(b);
        data[b].push_back(a);
    }
    queue<int> que;
    vector<int>dist(n, 0);
    vector<bool>seen(n,false);
    vector<int>res(n,0);
    que.push(0);
    int k = 0;
    while (!que.empty())
    {
        int q = que.front();
        que.pop();
        k++;
        for (int i = 0; i < data[q].size(); i++)
        {
            int d = data[q][i];
            if(seen[d] == true) continue;
            que.push(d);
            seen[d] = true;
            dist[d] = dist[q] + 1;
            res[d] = q;
        }
           
    }
    
    cout << "Yes" << endl;
    for (int i = 0; i < n; i++)
    {
        if(i == 0)continue;
        int ans = res[i] + 1;
        cout << ans << endl;
    }
    
}