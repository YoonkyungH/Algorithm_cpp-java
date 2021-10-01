// 공유기 설치
// 이분탐색

#include <iostream>
#include <algorithm>

using namespace std;

int arr[200000] = {0, };    // 집 위치들이 들어갈 것
int N, C;

bool check(int d) {
    int cnt = 1;
    int tmp = arr[0];

    for(int i=1; i<N; i++) {    // 거리가 최대인지
        if(arr[i]-tmp >= d) {
            cnt++;
            tmp = arr[i];
        }
    }

    if(cnt >= C) {              
        return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);

    cin >> N >> C;  // 집 개수, 공유기 개수

    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);

    int left=1, right=arr[N-1]-arr[0];  // 최소 거리, 최대 거리
    int ans = 0;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(check(mid)) {
            ans = max(ans, mid);
            left = mid+1;
        } else { right = mid-1; }
    }

    cout << ans << '\n';

    return 0;
}