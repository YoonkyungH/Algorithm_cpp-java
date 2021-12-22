// 1로 만들기
// DP

#include <iostream>
#include <algorithm>

using namespace std;

long long dp[1000001];

int main() {
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    dp[1] = 0;

    for(int i=2; i<=N; i++) {
        dp[i] = dp[i-1] + 1;
        if(i%3 == 0) {
            dp[i] = min((dp[i/3] + 1), dp[i]);
        }
        if(i%2 == 0) {
            dp[i] = min((dp[i/2] + 1), dp[i]);
        }
    }

    cout << dp[N] << '\n';

    return 0;
}