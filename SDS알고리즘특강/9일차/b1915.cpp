// 가장 큰 정사각형
// DP

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
// int arr[1001][1001];
int dp[1001][1001];
string str;
int ans;

int getMin(int a, int b, int c) {
    int n = a;
    if(n > b) n = b;
    if(n > c) n = c;
    return n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    ans = 0;
    for(int i=1; i<=n; i++) {
        cin >> str;
        for(int j=1; j<=m; j++) {
            dp[i][j] = str[j-1]-'0';

            if(dp[i][j] == 1) {
                dp[i][j] += getMin(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);    // 내 경우 dp[i-1][j-1]을 빼먹고 생각했었음
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans*ans << '\n';

    return 0;
}