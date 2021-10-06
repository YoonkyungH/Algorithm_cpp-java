// 예산
// 이분 탐색

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[10000];

bool check(int m) {
    int tmp = 0;

    for(int i=0; i<N; i++) {
        if(m >= arr[i]) { tmp += arr[i]; }
        else { tmp += m; }
    }

    // mid를 상한액으로 계산했을 때 M을 벗어나지 않는지
    if(tmp <= M) { return true; }

    return false;
}

int main() {
    ios::sync_with_stdio(0);

    cin >> N;

    int sum = 0;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    cin >> M;

    sort(arr, arr+N);

    // 예산이 충분하면 더 안 구해도 됨
    if(sum <= M) { cout << arr[N-1] << '\n'; return 0; }


    int left = 1, right = arr[N-1];
    int ans = 0;
    
    while(left <= right) {
        int mid = (left + right) / 2;

        if(check(mid)) {
            ans = max(ans, mid);
            // 최대값을 구해야 하므로 금액을 점점 늘림
            left = mid + 1;
        } else { right = mid - 1;}
    }

    cout << ans << '\n';

    return 0;
}