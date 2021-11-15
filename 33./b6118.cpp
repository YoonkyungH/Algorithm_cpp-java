// 숨바꼭질

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;  // 헛간의 개수 (1~)
int M;  // M개의 양방향 길
// int map[20000];

int idx;    // 숨어야 하는 헛간 번호
int num = 1;    // H까지의 거리
int cnt;    // 같은 거리를 갖는 헛간의 수

vector<int> v[20001];   // 거리가 담김
int visit[20001] = {0, }; 

void bfs() {
    queue<int> q;
    
    q.push(1);
    visit[1] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        // 검사하는 헛간에 연결된 헛간을 검사
        for(int i=0; i<v[x].size(); i++) {
            int nx = v[x][i];
            if(visit[nx] == false) {
                visit[nx] = visit[x] + 1;
                q.push(nx);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(0);

    cin >> N >> M;


    int A, B;
    for(int i=0; i<M; i++) {
        cin >> A >> B;
        v[A].push_back(B);
        v[B].push_back(A);
    }

    bfs();

    for(int i=2; i<=N; i++) {
        if(visit[i] > num) {
            num = visit[i]; // 헛간 거리
            idx = i;    // 헛간 번호(오름차순으로 정렬하기 때문에 가장 작은 헛간 번호가 들어갈 수밖에 없음)
            cnt = 1;    // 1로 초기화
        } else if(visit[i] == num) cnt++;
    }

    cout << idx << ' ' << num-1 << ' ' << cnt << '\n';

    return 0;
}