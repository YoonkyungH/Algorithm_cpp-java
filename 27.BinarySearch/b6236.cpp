// 용돈 관리
// 이분탐색

#include <iostream>

using namespace std;

int N, M;
int arr[100000];

int sum = 0;        // N일 동안 필요한 최소값

bool check(int m) {
    int tmp = m;    // 첫번재 mid 값 인출
    int cnt = 1;    // 인출 횟수

    for(int i=0; i<N; i++) {
        if(arr[i] > m) { return false; }    // 이 날에 인출해야 하는 값보다 mid 값이 작아 충족 X

        if(tmp - arr[i] < 0) {              // 저번에 인출한 값에서 모자라서 또 인출해야 되니까 cnt++
            cnt++;
            tmp = m;                        // 다시 인출
        }
        tmp -= arr[i];                      // 인출한 금액에서 해당 날짜 비용 소비
    }

    if(cnt <= M) { return true; }           // 인출 횟수가 정해진 횟수에 초과되지 않음

    return false;
}

int main() {
    ios::sync_with_stdio(0);

    cin >> N >> M;      // N일 동안 M번 인출

    for(int i=0; i<N; i++) {
        cin >> arr[i];

        sum += arr[i];  // 최소 sum만큼의 금액이 필요
    }

    int left = 1, right = sum;
    int result = 0;

    // 이분 탐색
    while(left <= right) {
        int mid = (right+left) / 2;

        if(check(mid)) {    // K가 M일 동안 사용할 수 있는 인출 값이라면
            result = mid;

            right = mid - 1;    // 최소 금액을 찾는거니까 범위를 줄임
        } else { left = mid + 1; }  // 현 mid 값으로는 M일 동안 쓸 수 없으므로 범위를 늘림
    }

    cout << result << '\n';

    return 0;
}