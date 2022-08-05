// 팩토리얼 0의 개수
// 소인수분해 했을 때 2와 5의 개수만 알면 되는데 2보다는 5의 개수가 적으므로 5의 개수만 세어도 된다.
#include <iostream>
using namespace std;

int N;
int dp[501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) {
        int cnt = 0;
        int tmp = i;

        while(1) {
            if(tmp%5 == 0) {
                cnt++;
                tmp /= 5;
            } else {
                break;
            }
        }

        dp[i] = cnt;
    }

    int ans = 0;
    for(int i=1; i<=N; i++) {
        ans += dp[i];
    }

    cout << ans << '\n';

    return 0;
}