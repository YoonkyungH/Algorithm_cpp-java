#include <iostream>
#include <algorithm>
using namespace std;

// 플로이드
// 플로이드와샬이 다익스트라랑 다르게 모든 정점에서 모든 정점으로 가는 최단 경로를 다 구함. "거쳐가는 정점"이 포인트

int n, m; // n: 도시 개수, m: 버스 개수
int a, b, c; // 출발, 도착, 가중치
int INF = 987654321;
int arr[101][101]; // 도시가 최대 100개니까 101로 설정

void floydWarshall() {
  for(int k=1; k<=n; k++) {     // 거쳐가는 노드
    for(int i=1; i<=n; i++) {   // 출발 노드
      for(int j=1; j<=n; j++) { // 도착 노드
        if(arr[i][k] != INF && arr[k][j] != INF) {
          arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]); // 거쳐가는 것의 가중치가 더 적다면 갱신
        }
      }
    }
  }

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if(i == j || arr[i][j] == INF)  // 본인에서 본인, 갈길 없음은 0을 출력
        // arr[i][i] = 0;
        cout << '0' << ' ';
      else
        cout << arr[i][j] << ' ';
    } cout << '\n';
  }
}

int main() {
  cin >> n >> m;

  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      arr[i][j] = INF;
    }
  } // 우선 INF로 arr을 초기화

  for(int i=0; i<m; i++) {
    cin >> a >> b >> c;
    if(arr[a][b] > c) arr[a][b] = c; // 원래보다 가중치가 작다면 갱신
  }

  floydWarshall();

  return 0;
}
