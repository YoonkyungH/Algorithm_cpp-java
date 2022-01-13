// 정수 삼각형
// DP

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[501][501];  // 입력받은 값
int dp[501][501];   // 각 자리까지의 누적합들이 저장
int n, num;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cin >> arr[i][j];
        }
    } 

    dp[1][1] = arr[1][1];
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            if(arr[i][j] + dp[i-1][j] > arr[i][j] + dp[i-1][j-1]) {
                dp[i][j] = arr[i][j] + dp[i - 1][j];
            }
            else {
                dp[i][j] = arr[i][j] + dp[i - 1][j - 1];
            }
        }
    }

    for(int i=1; i<=n; i++) {   // 가장 아래에 모인 값들 중 어떤 값이 가장 큰지
        ans = max(ans, dp[n][i]);
    }

    cout << ans << '\n';

    return 0;
}
