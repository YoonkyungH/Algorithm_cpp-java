// 피보나치 수2
// Bottom up 방식

#include <iostream>

using namespace std;

long long arr[91];

int main() {
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    arr[0] = 0;
    arr[1] = 1;

    for(int i=2; i<=n; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }

    cout << arr[n] << '\n';

    return 0;
}