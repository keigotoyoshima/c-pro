#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <math.h>
#include <string>
#include <assert.h>
using namespace std;
using ll = long long;
#define fi first
#define se second
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
const long long INF = 1LL << 60;
int inf_int = 2147483647;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int dx8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main()
{
    int N;
    cin >> N;
    int W;
    cin >> W;
    vector<int> w(N);
    vector<ll> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }

    vector<vector<ll>> dp(N, vector<ll>(100001, INF));
    dp[0][0] = 0;
    dp[0][v[0]] = w[0];

    
    // dp[i][j]=i番目までの品物を価値の合計がjになるように選んだ時の重さの総和
    for (int i = 0; i < N-1; i++)
    {
        for (int j = 0; j < 100001; j++)
        {
            int weight = w[i+1];
            int value = v[i+1];
            chmin(dp[i+1][j],dp[i][j]);
            if(j-value>=0){
                chmin(dp[i + 1][j], dp[i][j - value] + weight);
            }
        }
    }
    

    for (int i = 100000; i >= 0; i--)
    {

        
        if(dp[N-1][i] <= W){
            cout << i << endl;
            return 0;
        }
    }
    cout << endl;
    

    return 0;
}