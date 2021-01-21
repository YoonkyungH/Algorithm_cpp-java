#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 부분수열의 합
// DFS: 깊이 우선탐색. 현재 정점에서 갈 수 있는 점들까지 이어 탐색
int arr[20];
int N, S;
int cnt;

void dfs(int i, int sum){
    if(i == N)                // 원소를 모두 탐색하면 끝
        return;
    if(sum + arr[i] == S)     // 전까지 더해오던 sum과 arr[i] 원소 값을 더한 값이 S와 같으면 cnt++
        cnt++;

    dfs(i + 1, sum);          // 원소 하나가 S를 만족하는 경우를 체크(그리고 이 dfs 함수 안에서도 18, 19줄의 함수가 발생하므로 ...)
    dfs(i + 1, sum + arr[i]); // sum에 차곡차곡 원소를 더해가며 탐색
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> N >> S;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    dfs(0, 0);               // 제일 처음부터 탐색, sum=0

    cout << cnt << '\n';
    return 0;
}
