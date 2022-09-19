// 플로이드워셜 뼈대코드
#include <iostream>
using namespace std;

#define INF 987654321

int n = 5;

int arr[5][5] = {
    {0, 2, 7, INF, 4},
    {INF, 0, INF, 3, 6},
    {INF, 3, 0, INF, INF},
    {-1, INF, -4, 0, INF},
    {INF, INF, INF, 5, 0},
};

void floydWarshall() {
    int d[5][5]; // 결과 그래프
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            d[i][j] = arr[i][j];
        }
    }

    for(int p=0; p<n; p++) {    // p: 거쳐갈 정점
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(d[i][p] + d[p][j] < d[i][j]) {   // 거쳐 가는 것이 더 짧은 거리라면
                    d[i][j] = d[i][p] + d[p][j];    // 갱신
                }
            }
        }
    }

    // 출력
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         cout << d[i][j] << " ";
    //     } cout << '\n';
    // }
}

int main() {
    floydWarshall();

    return 0;
}