// 나무 자르기
// 이분탐색

#include <iostream>
#include <algorithm>

using namespace std;

long long arr[1000000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+N);

    long long ans = 0;
    long long left=0, right=arr[N-1];
    while(left <= right) {
        long long mid = (left + right) / 2;

        long long sum = 0;
        for(int i=0; i<N; i++) {
            if(arr[i]-mid < 0) { continue; }
            
            sum += arr[i] - mid;
        }

        if(sum >= M) { ans = max(ans, mid); left = mid+1; }
        else { right = mid-1; }
    }
 
    cout << ans << '\n';

    return 0;
}