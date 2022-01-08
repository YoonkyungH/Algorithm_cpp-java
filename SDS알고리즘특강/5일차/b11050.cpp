// 이항 계수 1

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int ans = 1;
    for(int i=1; i<=K; i++) {   // 분자
        ans *= N--;
    }
    for(int i=1; i<=K; i++) {   // 분모
        ans /= i;
    }

    cout << ans << '\n';

    return 0;
}