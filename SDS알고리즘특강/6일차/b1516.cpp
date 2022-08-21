// 게임 개발
// 위상정렬

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>  // memset
#include <algorithm>

using namespace std;

int N, input;
int indegree[501]; // 화살표 개수를 담을 배열
int dp[501];
int cost[501];
queue<int> q;
vector<int> adjust[501];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    // 0으로 초기화
    // memset(cost, 0, sizeof(cost));
    // memset(indegree, 0, sizeof(indegree));
    // memset(dp, 0, sizeof(dp));
    // for(int i=0; i<=N; i++) {
    //     adjust[i].clear();
    // }

    for(int i=1; i<=N; i++) {
        cin >> input;
        cost[i] = input;

        while(1) {
            cin >> input;
            if(input == -1) break;

            adjust[input].push_back(i); // input -> i
            indegree[i]++;
        }
    }

    for(int i=1; i<=N; i++) {
        if(indegree[i] == 0) {  // 출발점
            q.push(i);
            dp[i] = cost[i];
        }
    }

    int vi;
    while(1) {
        if(q.empty()) break;

        int n = q.front();
        q.pop();

        for(int i=0; i<adjust[n].size(); i++) {
            vi = adjust[n].at(i);   // at(): 벗어난 접근 시도시 예외를 발생시킴
            dp[vi] = max(dp[n] + cost[vi], dp[vi]);
            indegree[vi]--;

            if(indegree[vi] == 0) q.push(vi);
        }
    }

    for(int i=1; i<=N; i++) {
        cout << dp[i] << '\n';
    }

    return 0;
}