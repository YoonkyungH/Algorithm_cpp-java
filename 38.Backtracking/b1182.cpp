// 부분수열의 합
// 백트래킹

/**
 * DFS 함수로 배열 인덱스 차례로 수열의 시작점으로 하여 검사해
 * 끝까지 돌았으면 return, 합이 S와 같아지면 cnt++를 수행했다.
 */

#include <iostream>

using namespace std;

int arr[20];
int cnt = 0;
int N, S;

void DFS(int idx, int sum) {
    if(idx == N) { return; }
    if(arr[idx] + sum == S) { cnt++; }
    
    DFS(idx+1, sum);
    DFS(idx+1, sum+arr[idx]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;

    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    DFS(0, 0);  // arr[0], sum=0 부터

    cout << cnt << '\n';

    return 0;
}