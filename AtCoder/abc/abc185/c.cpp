#include <stdio.h>
#include <stdint.h>

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 100100;

int main() {
    long long L;
    cin >> L;
    long long res = 1;
    for (int i = 1; i <= 11; ++i) {
        res *= L - i;
        res /= i;
    }

    
    cout << res << endl;
}