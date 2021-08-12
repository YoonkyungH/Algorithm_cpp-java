#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001

// 숨바꼭질 3

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

        // if문의 순서가 매우 중요함
        // 1 2의 경우 x+1 보다 x*2로 해야하기 때문에 곱하기 연산자가 먼저 와야함
        // 4 6의 경우 (4-1)*2 = 6이기 때문에 빼기 연산자가 곱하기 연산자보다 먼저 와야함
        if(x-1>=0 && visited[x-1]==false) {
            q.push(make_pair(x-1, cnt+1));
            visited[x-1] = true;
        }
        if(x*2<MAX && visited[x*2]==false) {
            q.push(make_pair(x*2, cnt));
            visited[x*2] = true;
        }
        if(x+1<MAX && visited[x+1]==false) {
            q.push(make_pair(x+1, cnt+1));
            visited[x+1] = true;
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