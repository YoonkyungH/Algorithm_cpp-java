// 결혼식
// BFS

#include <iostream>

using namespace std;

int map[501][501];
bool visited[501];
bool friends[501];   // 친구인가

int main() {
    ios::sync_with_stdio(0);

    int n = 0, m = 0;   // 동기 수, 리스트 길이
    int ans = 0;        

    cin >> n;
    cin >> m;

    for(int i=0; i<m; i++) {
        int a, b;
        
        cin >> a >> b;
        
        map[a][b] = 1;
        map[b][a] = 1;
    }

    for(int i=2; i<=n; i++) {
        if(map[1][i] == 1) {    // 상근이와 친구인가
            visited[i] = true;
            friends[i] = true;
        }
    }
    
    for(int i=2; i<=n; i++) {   // 상근이 친구들을 모두 표시해뒀으니 친구의 친구 찾기
        if(friends[i]==true) {
            for(int j=2; j<=n; j++) {
                if(map[i][j]==true) {
                    visited[j] = true;
                }
            }
        }
    }

    for(int i=2; i<=n; i++) {
        if(visited[i] == true) { ans++; }
    }

    cout << ans << '\n';

    
    return 0;
}