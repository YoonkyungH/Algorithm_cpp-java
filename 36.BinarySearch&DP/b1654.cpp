// 랜선 자르기
// 이분 탐색

#include <iostream>
#include <algorithm>

using namespace std;

int arr[10000]; // 각 랜선 길이가 저장될 것

int main() {
    ios::sync_with_stdio(0);

    long long K, N;
    int ans = 0;
    cin >> K >> N;  // 이미 가진 랜선 K, 필요한 랜선 N

    for(int i=0; i<K; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+K);

    int left = 1; 
    long long right = arr[K-1];
    while(left <= right) {
        long long mid = (left + right) / 2;

        int sum = 0;
        if(mid > 0) {   // 왜 이렇게 mid>0을 굳이 검사해주어야 하는지는 못 찾음
            for(int i=0; i<K; i++) {
                sum += arr[i]/mid;
            }
        }
        

        if(sum >= N) { ans = mid; left = mid + 1; }
        else { right = mid-1; }
    }

    cout << ans << '\n';

    return 0;
}