// 녹색 옷 입은 애가 젤다지?
// 다익스트라

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std;

typedef struct {
    int y, x;
} Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int map[125][125];
int dist[125][125];
bool visited[125][125];
int N, testCase;

// priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

bool check(int x, int y) {
    if(0 <= x && x < N && 0 <= y && y < N) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    testCase = 1;
    while(1) {
        cin >> N;
        if(N == 0) break;

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                dist[i][j] = INF;
                visited[i][j] = false;
            }
        }

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cin >> map[i][j];
            }
        }
        priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;

        // priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > newPq;
        // swap(newPq, pq);

        pq.push(make_pair(0, make_pair(0, 0)));
        visited[0][0] = true;

        while(!pq.empty()) {
            int nowY = pq.top().second.first;  // y좌표
            int nowX = pq.top().second.second; // x좌표
            int nowCost = pq.top().first;      // 루피
            pq.pop();

            for(int i=0; i<4; i++) {
                int nextY = nowY + moveDir[i].y;
                int nextX = nowX + moveDir[i].x;
                int nextCost = nowCost + map[nextY][nextX];

                if(check(nextX, nextY)) {
                    if(!visited[nextY][nextX] && dist[nextY][nextX] > nextCost) {
                        visited[nextY][nextX] = true;
                        dist[nextY][nextX] = nextCost;
                        pq.push(make_pair(nextCost, make_pair(nextY, nextX)));
                    }
                }
            }
        }

        cout << "Problem " << testCase++ << ": " << map[0][0] + dist[N-1][N-1] << '\n';
    }

    return 0;
}

