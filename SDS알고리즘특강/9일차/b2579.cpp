// 계단 오르기
// DP

#include <iostream>
#include <algorithm>

using namespace std;

int n;
int stair[301];
int dp[301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> stair[i];
    }

    dp[1] = stair[1];
    dp[2] = max(stair[2], stair[1]+stair[2]);
    dp[3] = max(stair[1]+stair[3], stair[2]+stair[3]);
    // 아니면 위의 코드와 반복문 안의 코드 대신 주석코드끼리 짜도 가능함
    // dp[0] = 0;
    // dp[1] = stair[1];
    // dp[2] = stair[1] + stair[2];

    for(int i=3; i<=n; i++) {
        // 3번 연속 한 계단씩 오르는 경우를 체크하지 않는 이유는
        // 이렇게 dp 배열을 채워나가면 해당 자리에 오기까지
        // 두 칸 뛰어서 오는게 큰지, 두 칸 뛴 다음 한 칸 뛰는게 나은지 검사하기 때문에 
        // 연속 세 칸을 뛰는 경우는 애초에 배제된다.
        dp[i] = max(stair[i] + dp[i-2], stair[i] + stair[i-1] + dp[i-3]);

        // dp[i] = max(dp[i - 3] + stair[i - 1], dp[i - 2]) + stair[i];
    }

    cout << dp[n] << '\n';

    return 0;
}