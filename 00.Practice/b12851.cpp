#include <iostream>
#include <queue>
using namespace std;

// 숨바꼭질 2

#define MAX 100001

int N, K;   // N: 수빈, K: 동생의 위치
queue<pair<int, int> > q;
bool visited[MAX] = {false, };
int ans = 0, cnt = 0;

void bfs(int N) {
    q.push(make_pair(N, 0));

    while(!q.empty()) {
        int x = q.front().first;    // 위치
        int time = q.front().second; // 시간
        q.pop();

        visited[x] = true;  // pop시 방문여부 바꿔주기

        if(cnt && ans == time && x == K) {
            cnt++;
        }

        if(!cnt && x == K) {
            ans = time;
            cnt++;
        }

        if (x - 1 >= 0 && visited[x - 1] == false) {
            q.push(make_pair(x - 1, time + 1));
            // visited[x - 1] = true;
        }
        if (x * 2 < MAX && visited[x * 2] == false) {
            q.push(make_pair(x * 2, time + 1));
            // visited[x * 2] = true;
        }
        if (x + 1 < MAX && visited[x + 1] == false) {
            q.push(make_pair(x + 1, time + 1));
            // visited[x + 1] = true;
        }
    }

}

int main() {
    ios::sync_with_stdio(0);

    cin >> N >> K;

    bfs(N);

    cout << ans << '\n' << cnt << '\n';
    
    return 0;
}