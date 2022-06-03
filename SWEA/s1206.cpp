// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV134DPqAA8CFAYh

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 0;
    for(int i=1; i<=10; i++) {
        cin >> tc;

        int ans = 0;
        for(int j=0; j<tc; j++) {
            cin >> arr[j];
        }

        for(int j=2; j<tc-2; j++) {
            if(arr[j] > max(arr[j+1], arr[j+2]) && arr[j] > max(arr[j-1], arr[j-2])) {
                ans += arr[j] - max(max(arr[j + 1], arr[j + 2]), max(arr[j - 1], arr[j - 2]));
            }
        }

        cout << "#" << i << " " << ans << '\n';
    }

    return 0;
}