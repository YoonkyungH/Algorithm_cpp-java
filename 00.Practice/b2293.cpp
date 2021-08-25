#include <iostream>
using namespace std;

// 동전 1

int main() {
    ios::sync_with_stdio(0);

    int DP[100001] = {0, };      // 들어올 수 있는 동전의 가치 범위만큼

    int arr[101] = {0, };
    int n, k;
    cin >> n >> k;

    for(int i=1; i<=n; i++) {    // 동전의 가치
        cin >> arr[i];
    }

    DP[0] = 1;
    
    for(int i=1; i<=n; i++) {
        for(int j=arr[i]; j<=k; j++) {
            DP[j] += DP[j-arr[i]];
        }
    }

    cout << DP[k] << '\n';

    return 0;
}