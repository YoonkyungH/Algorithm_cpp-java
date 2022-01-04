// 수들의 합 2
// 백준 1806 부분합 문제 참고

#include <iostream>

using namespace std;

int arr[10000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N, M;
    cin >> N >> M;

    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    int left=0, right=0;
    long long sum=0, cnt=0;
    while(1) {
        if(sum >= M) { // sum이 크거나 같으면
            if(sum==M) { cnt++; }     // 같으면 일단 cnt 증가
            sum -= arr[left++];       // 다시 left 자리값 sum에서 빼주고 left 우측 이동
        }
        else if(right == N) { break; }  // 끝까지 도달한 경우 break
        else { sum += arr[right++]; }   // 아직 sum이 M값에 만족하지 못한 경우 right 자리값 더해주고 right 우측이동
    }

    cout << cnt << '\n';

    return 0;
}