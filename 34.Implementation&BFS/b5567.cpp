// 결혼식

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[501];     // 친구관계가 담길 리스트
int visit[501] = {0, }; // 상근이와 얼마나 먼 친구인지 담을 배열

void bfs() {
    queue<int> q;

    q.push(1);      // 상근이로부터
    visit[1] = 1;   

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i=0; i<v[x].size(); i++) {  // 상근와 연관된 친구와 연관관계를 검사하면서
            int nx = v[x][i];
            if(visit[nx] == false) {
                visit[nx] = visit[x] + 1;   // 상근이까지 얼마나 먼 친구인지를 배열에 담음
                q.push(nx);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n;   // 상근이 동기 수
    cin >> m;   // 리스트 길이

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs();

    int cnt = 0;
    for(int i=2; i<=n; i++) {   // 상근이 이후부터  
        if(visit[i] <= 3 && visit[i] > 0) { // 상근이와 친구거나 친구의 친구라면
            // cout << "\nI: " << i << '\n';
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}