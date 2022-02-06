#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;


int main() {
    int n = 5;


    for (int bit = 0; bit < (1<<n); ++bit)
    {
        set<int> st;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { 
                st.insert(i);
            }
        }
    }
}