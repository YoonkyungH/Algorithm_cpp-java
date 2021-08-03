#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int N;
    int arr[1001];
    int ans = 1;

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);
    for(int i=0; i<N; i++) {
        if(arr[i] > ans) { break; }
        ans += arr[i];
    }

    cout << ans << '\n';

    return 0;
}
