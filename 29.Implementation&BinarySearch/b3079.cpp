// 입국심사
// 이분탐색

#include <iostream>
#include <algorithm>

using namespace std;

long long N, M;
long long arr[100001];
long long sum = 0;

// bool check(long long m) {
//     sum = 0;
//     for(int i=0; i<N; i++) {
//         sum += m/arr[i];
//     }

//     if(sum >= M) { return true; }
//     else if(sum < M) { return false; }
//     return false;
// }

int main() {
    ios::sync_with_stdio(0);


    cin >> N >> M;  // 심사대, 사람

    int m = 0;
    for(int i=0; i<N; i++) {
        cin >> arr[i];

        if(arr[i] > m) { m = arr[i]; }
    }
    // sort(arr, arr+N);

    // cout << "TEST\n";
    // for(int i=0; i<N; i++) {
    //     cout << arr[i] << ' ';
    // } cout << '\n';


    long long left = 1, right = m * M;
    long long answer = m * M;

    while(left <= right) {
        long long mid = (left + right)/2;
        
        sum = 0;
        // 총 몇 명까지 되나 세어
        for(int i=0; i<N; i++) {
            sum += mid/arr[i];
        }

        // 원하는 사람 수보다 적으면 값을 올려 다시
        if(sum < M) { left = mid + 1; }
        // 조건에 충족하면 answer에 넣어놓고 값을 줄여 다시
        else { answer = mid; right = mid - 1; }

        // if(check(mid)) { if(answer > mid) answer = mid; right = mid - 1; }
        // else { left = mid + 1; }
    }
    
    cout << answer << '\n';

    return 0;
}