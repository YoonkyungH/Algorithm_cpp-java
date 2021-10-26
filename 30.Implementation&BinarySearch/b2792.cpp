// 보석 상자

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    long long M, N;   // M: 색상 수 N: 아이들 수
    cin >> N >> M;


    long long m = 0;
    long long arr[300000] = {0, };
    
    for(int i=0; i<M; i++) {
        cin >> arr[i];

        m = max(m, arr[i]);
    }


    long long left = 1;
    long long right = m;

    long long ans = 1000000000;

    while(left <= right) {
        long long mid = (left + right) / 2;
        long long tmp = 0;

        for(int i=0; i<M; i++) {
            tmp += arr[i] / mid;
            if(arr[i]%mid != 0) { tmp++; }
        }

        if(tmp <= N) {
            right = mid - 1;

            if(mid < ans) { ans = mid; }
        } else {
            left = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}