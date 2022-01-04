// 게임
// 이분탐색
// Z를 구하는 식: long long Z = (Y*100/X);

#include <iostream>
#include <algorithm>    // max

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long X, Y;
    cin >> X >> Y;

    long long Z = (Y*100/X);
    long long left=0, right=X;
    long long ans = X+1; 
    while(left <= right) {
        long long mid = (left + right) / 2;

        if(((Y+mid)*100)/(X+mid) > Z) {
            ans = min(ans, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if(ans == X+1) { cout << "-1\n"; }
    else { cout << ans << '\n'; }

    return 0;
}