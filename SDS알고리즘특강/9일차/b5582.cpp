// 공통 부분 문자열
// DP
// 풀이를 생각해내기 어려움

/**
 * 행과 열로 쭉 펼치기
 * (문자열 하나는 행, 하나는 열)
 * 
 * 그리고 같은 문자인가 2차원 배열처럼 검사함
 * 그리고 겹치는 부분이 있다면 계속 검사하면서
 * 그 대각선으로 딱딱딱 겹치면 그 자리에 그 대각선 전 원소에 +1
 * 0 1 0 0
 * 0 0 2 0
 * 0 0 0 3 중복된다면 이런식으로 대각선 위의 숫자에서 +1 해주는
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>  // memset

using namespace std;

string str1;
string str2;
int dp[4001][4001];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str1;
    cin >> str2;
    
    // 초기화
    memset(dp, 0, sizeof(dp));
    ans = 0;

    for(int i=1; i<=str1.length(); i++) {
        for(int j=1; j<=str2.length(); j++) {
            if(str1[i-1] == str2[j-1]) { 
                dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}