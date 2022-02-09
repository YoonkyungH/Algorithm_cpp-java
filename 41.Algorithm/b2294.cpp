// 동전 2
// 다이나믹 프로그래밍

#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[101];
int dp[10001];  // 동전 개수 저장될

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i=1; i<=k; i++) {    // dp 배열 초기화
        dp[i] = 10001;  // k가 최대 10000
    }

    for(int i=1; i<=n; i++) {
        cin >> arr[i];

        for(int j=arr[i]; j<=k; j++) {
            dp[j] = min(dp[j], dp[j-arr[i]] + 1);
        }
    }

    if(dp[k] == 10001) cout << "-1\n";
    else cout << dp[k] << '\n';


    return 0;
}