#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 치킨 배달

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
// M개 만큼의 치킨집을 고르는 경우의 수를 모두 저장할 벡터
vector<pair<int, int>> selected_chicken;

int N, M;
int ans = 101;
int total_distance = 0;
int cnt = 0;                        // 치킨집 개수
int map[51][51] = {0, };
int chicken_distance[101] = {0, };

void dfs(int cnt, int num) {
  // 치킨집 M개를 선택했을 때
  if(cnt == M) {
    // 거리 계산
    for(int i=0; i<house.size(); i++) {
      int hx = house[i].first;
      int hy = house[i].second;

      for(int j=0; j<M; j++) {
        int cx = selected_chicken[j].first;
        int cy = selected_chicken[j].second;

        chicken_distance[i] = min(chicken_distance[i], abs(hx-cx) + abs(hy-cy));
      }
    }

    // 도시의 치킨거리 계산
    for(int i=0; i<house.size(); i++) {
      total_distance += chicken_distance[i];
    }

    // 반환할 ans에 계속해서 최소값을 갱신
    ans = min(ans, total_distance);

    // 초기화
    total_distance = 0;

    for(int i=0; i<house.size(); i++) {
      chicken_distance[i] = 101;
    }

    return;

  }

  // 0 1 2와 1 2 0를 같은 조합으로 보는 즉, 순서를 고려하지 않는 조합
  for(int i=num; i<chicken.size(); i++) {
    // 치킨집 선택 후 벡터에 삽입
    selected_chicken.push_back(chicken[i]);
    dfs(cnt+1, i+1);
    selected_chicken.pop_back();
  }

}

int main() {
  ios::sync_with_stdio(0);

  cin >> N >> M;

  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      cin >> map[i][j];

      // 집은 집 벡터, 치킨집은 치킨집 벡터에 push
      if(map[i][j] == 1) {
        house.push_back(make_pair(i, j));
      } else if(map[i][j] == 2) {
        chicken.push_back(make_pair(i, j));
      }

    }


  }

  for(int i=0; i<house.size(); i++) {
    chicken_distance[i] = 101;
  }

  dfs(0, 0);
  cout << ans << '\n';

  return 0;
}
