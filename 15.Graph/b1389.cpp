#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

// 케빈 베이컨의 6단계 법칙
// dfs

int N, M, person=101, ans=987654321;
int cnt[101];
vector<vector<int>> v;  // 양방향, 무방향 2차원 벡터

void dfs(int n, int num) { // n: 지정된 친구로부터의 거리차, num: 친구 번호
  if(cnt[num] != 0) {
    // 호출된 친구와의 거리랑 최솟값으로 저장되어 있던 수와 비교해 더 작은 수 갱신
    cnt[num] = min(n, cnt[num]);
  } else {
    cnt[num] = n;
  }

  for(int j=0; j<v[num].size(); j++) { // 연결된 친구 모두 탐색
    int next = v[num][j];
    // 친구를 포함하지 않았거나(바로 아는 사이) 더 가까운 사이의 친구라면 탐색
    if(cnt[next]==0 || cnt[next] > n+1) {
      dfs(n+1, next);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);

  cin >> N >> M;  // N: 유저의 수, M: 친구 관계의 수

  v.resize(N+1);

  int fr1, fr2;
  for(int i=0; i<M; i++) {
    cin >> fr1 >> fr2;
    v[fr1].push_back(fr2);
    v[fr2].push_back(fr1);
  }

  for(int i=1; i<=N; i++) {
    // 친구들과 거리차 초기화
    memset(cnt, 0, sizeof(cnt));

    for(int j=0; j<v[i].size(); j++) {
      dfs(1, v[i][j]);
    }

    int temp = 0;
    for(int j=1; j<=N; j++) {
      if(j==i) { // 본인은 패스
        continue;
      }
      temp += cnt[j];
    }

    if(ans > temp) {
      ans = temp;
      person = i;
    } else if(ans == temp) {
      person = min(person, i);
    }
  }

  cout << person;

  return 0;
}
