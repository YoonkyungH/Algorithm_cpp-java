// 이항 계수 2
// DP

#include <iostream>

using namespace std;

long long dp[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    dp[0][0] = 1;
    for(int i=1; i<=N; i++) {
        dp[i][0] = 1;   // "안 뽑는다" -> 방법 하나
        
        for(int j=1; j<=i; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
        }
    }

    cout << dp[N][K] << '\n';

    return 0;
}