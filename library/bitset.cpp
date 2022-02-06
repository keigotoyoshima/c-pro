#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int A = 0x2d;
    int B = 0x19;
    cout << A << " AND " << B << " = " << (A&B) << endl;
    cout << bitset<8>(A) << " AND " << bitset<8>(B) << " = " << bitset<8>(A&B) << endl;
//     45 AND 25 = 9
//     00101101 AND 00011001 = 00001001
    bitset<5> dp;
    cout << dp << endl;
    dp[0] = 1;
    cout << dp << endl;
//     00000
//     00001
}