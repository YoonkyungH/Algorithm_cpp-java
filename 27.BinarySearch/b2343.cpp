// 기타 레슨

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;   // N: 강의 수 M: 블루레이
int arr[100000] = {0, };    // 강의 시간


int main() {
    ios::sync_with_stdio(0);

    cin >> N >> M;

    int sum = 0;
    int m = -1;
    for(int i=0; i<N; i++) {
        cin >> arr[i];

        // 최대값은 강의 시간의 총합
        sum += arr[i];
        // 가장 긴 강의 시간 구하기
        m = max(m, arr[i]);
    }

    int right = sum;
    // 최소값은 강의 시간 중 가장 긴 시간
    int left = m;

    // 이분탐색
    while(left <= right) {
        int mid = (right + left) / 2;   // 최소 블루레이에는 mid 값 이상으로 담겨야 한다.

        int cnt = 0, tmp = 0;           // cnt: 블루레이 개수 tmp: 지금 세고 있는 블루레이에 담긴 강의 시간 합
        for(int i=0; i<N; i++) {
            if(tmp + arr[i] > mid) {    // 중간값보다 블루레이에 담긴 값이 크면 지금 블루레이는 마감하고 개수 증가
                cnt++;
                tmp = 0;
            }
            tmp += arr[i];              // 중간값보다 못하면 블루레이에 강의시간 축적 
        }

        if(tmp != 0) { cnt++; }         // 끝가지 돌았는데 mid 값을 채우지 못했다면 블루레이 개수 증가

        if(cnt > M) {
            left = mid + 1;     // mid 값이 늘어남 (원하는 블루레이 수를 맞추지 못했으므로)
        } else {
            right = mid - 1;    // mid 값이 줄어듦 (이렇게 해서는 블루레이 수를 채울 수 없으므로)
        }
    } 

    cout << left << '\n';

    return 0;
}