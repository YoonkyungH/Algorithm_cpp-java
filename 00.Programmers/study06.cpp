// 합승 택시 요금

// 다익스트라: 하나의 출발점에서 다른 모든 정점으로 최단 경로
// 플로이드 와샬: 모든 정점에서 모든 정점

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 10000000

int map[201][201];


void floydWarshall(int n) {
    for(int i=1; i<=n; i++) {
        map[i][i] = 0;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                map[j][k] = min(map[j][k], map[j][i]+map[i][k]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    // vector<pair<int, int> > map;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = 10000000;
        }
    }

    for(int i=0; i<fares.size(); i++) {
        map[fares[i][0]][fares[i][1]] = fares[i][2];
        map[fares[i][1]][fares[i][0]] = fares[i][2];
        // 양방향 (가중치 같음)        
    }

    // TEST
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=n; j++) {
    //         cout << map[i][j] << ' ';
    //     } cout << '\n';
    // }

    floydWarshall(n);

    answer = 100000000;

    for(int i=1; i<=n; i++) {
        answer = min(answer, map[s][i]+map[i][a]+map[i][b]);
    }


    return answer;
}