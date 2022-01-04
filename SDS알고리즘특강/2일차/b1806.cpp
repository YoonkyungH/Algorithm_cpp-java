// 부분합
// 시간초과 -> 수정완료

// 강사님은 left, right = 0

#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
int arr[100000];
int ans = 100000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;

    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    int left=0, right=0;
    int sum = 0;
    int ans = N+1;

    while(1) {
        if(sum >= S) {
            ans = min(ans, right-left);

            // left값을 빼주고 left 우측 이동
            sum -= arr[left];
            left++;
        }
        else if(right == N) {   // 끝에 도달했으면 탈출
            break;
        } 
        else {
            // right값 더하고 right 우측 이동
            sum += arr[right];
            right++;
        }
    }

    if(ans == N+1) { cout << "0\n"; }
    else { cout << ans << '\n'; } 

    return 0;
}