#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001

// 숨바꼭질

queue<pair<int, int> > q;
bool visited[MAX] = {false, };
int N, K;

int bfs(int n) {
    q.push(make_pair(n, 0));

    visited[n] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(x == K) { return cnt; }

        if(x+1<MAX && visited[x+1]==false) {
            q.push(make_pair(x+1, cnt+1));
            visited[x+1] = true;
        }
        // 주의) 빼기니까 0보다 클 때를 검사할 것
        if(x-1>=0&& visited[x-1]==false) {
            q.push(make_pair(x-1, cnt+1));
            visited[x-1] = true;
        }
        if(x*2<MAX && visited[x*2]==false) {
            q.push(make_pair(x*2, cnt+1));
            visited[2*x] = true;
        }

    }

    return 0;
}

int main() {
    ios::sync_with_stdio(0);

    cin >> N >> K;

    cout << bfs(N) << '\n';



    return 0;
}