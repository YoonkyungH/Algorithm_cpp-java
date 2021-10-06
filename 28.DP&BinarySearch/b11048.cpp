// 이동하기

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int map[1001][1001];    // (1, 1)부터 시작
int map2[1001][1001];   // 사탕 축적

int c = 0;

// {-1, -1, 0}

int main() {
    ios::sync_with_stdio(0);

    cin >> N >> M;   // 세로, 가로
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            // 이 자리에 오기위해 어떤 경로로 와야 가장 사탕을 많이 가져올 수 있는지 max로 검사
            c = max(max(map2[i-1][j], map2[i][j-1]), map2[i-1][j-1]);
                        
            // 그 값을 더한 후 map2에 지금 자리에 놓인 사탕과 합쳐서 저장
            map2[i][j] = c + map[i][j];
        }
    }
    
    // 목적지 사탕 총합 출력
    cout << map2[N][M] << '\n';

    return 0;
}