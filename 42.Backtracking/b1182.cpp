// 부분수열의 합
#include <iostream>
using namespace std;

int N, S;
int arr[20];

int ans;

void backtracking(int row, int sum) {
    if(row == N) {
        return;
    }

    if(sum + arr[row] == S) {
        ans++;
    }

    backtracking(row + 1, sum);
    backtracking(row + 1, sum + arr[row]);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    backtracking(0, 0);
    cout << ans << '\n';
 
    return 0;
}