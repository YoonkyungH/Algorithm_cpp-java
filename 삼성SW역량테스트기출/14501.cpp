// 퇴사
// 다이나믹 프로그래밍
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int T[16];
int C[16];
int ans;
// int cost[16];

void sol(int day, int sum) {
    if(day == N+1) {
        ans = max(ans, sum);
        return;
    }

    if(day > N+1) {
        return;
    }

    sol(day+1, sum); // 이 날을 선택하지 않을 경우 다음날로,
    sol(day+T[day], sum+C[day]); // 이 날을 선택했을 경우 상담 소요 시간 이후로 이동
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> T[i] >> C[i];

    }

    sol(1, 0);
    cout << ans << '\n';

    return 0;
}