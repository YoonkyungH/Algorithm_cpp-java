// dfs 함수 c++ 예제
// 재귀 활용

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define N 10

vector<int> graph[N+1];
bool check[N+1];
int n, m, start;

void dfs_recursion(int x) {
    check[start] = true;
    // cout << start << '\n';

    for(int i=0; i<graph[start].size(); i++) {
        int next = graph[start][i];

        if(check[next] == false) {
            dfs_recursion(next);
        }
    }
}

void dfs_stack(int x) {
    stack<int> s;
    s.push(start);

    check[start] = true;

    // cout << start << '\n';

    while(!s.empty()) {
        int cur = s.top();
        s.pop();

        for(int i=0; i<graph[cur].size(); i++) {
            int next = graph[cur][i];

            if(check[next] == false) {
                // cout << next << '\n';
                check[next] = true;

                s.push(cur);
                s.push(next);
                break;
            }
        }
    }
} 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> start;

    // graph.resize(n+1);

    fill(check, check+n+1, false);

    for(int i=0; i<m; i++) {
        int k, q;
        cin >> k >> q;

        graph[k].push_back(q);
        graph[q].push_back(k);
    }

    for(int i=1; i<=n; i++) {
        sort(graph[i].begin(), graph[i].end()); // 하나의 정점에서 다음 탐색은 node 값에 순차적으로 접근해 이루어져야함
    }

    dfs(start);

    return 0;
}