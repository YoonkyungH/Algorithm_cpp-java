// 게임
// 이분탐색

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000000000

long long X, Y, Z;

int main() {
    ios::sync_with_stdio(0);

    cin >> X >> Y;  // 전체, 이긴게임
    Z = (Y*100/X);  // 승률

    int cnt = -1;

    if(Z >= 99) {   // 승률이 99 이상이면 불가
        cout << cnt << '\n';
        return 0;
    }

    int left = 0;
    int right = MAX;

    while(left <= right) {
        int mid = (right + left) / 2;
        int tmp = (Y+mid) * 100 / (X+mid);  // mid번을 더 해서 mid번을 모두 이긴다는 조건으로 다시 계산한 승률

        if(Z < tmp) { right = mid - 1; }    // 승률이 높아졌다면
        else { left = mid + 1; }
    }

    cout << left << '\n';

    return 0;
}