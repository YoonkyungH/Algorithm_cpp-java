#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 회의실 배정
// 처음에 for문 중첩으로 시간초과
int main() {
  ios::sync_with_stdio(0);
  vector<pair<int, int>> v;
  int N, a, b;
  int endtime=0;
  int sum = 0;

  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> a >> b;
    v.push_back(make_pair(b, a));     // 끝나는 시간, 시작 시간 순으로 push_back
  }
  // 오름차순 정렬
  sort(v.begin(), v.end());

  // 처음에는 시작시간, 끝나는 시간대로 vector에 집어넣어 for문을 중첩해서 썼는데(max 함수를 이용해 계속 큰 경우의 수를 갱신)
  // 끝나는 시간이 작은 순서대로 오름차순 sort시키기 위해 b, a 순으로 vector에 저장
  // 그 후 끝나는 시간을 endtime에 저장해 시작시간>=endtime 조건으로 sum을 증가
  // 또한, 시작시간 == 끝시간까지 일치하는 경우도 탐색
  for(int j=0; j<N; j++) {
    if(v[j].second >= endtime && v[j].first == v[j].second) {
      sum++; endtime=v[j].first;
    } else {
      if(v[j].second >= endtime) {
        sum++; endtime=v[j].first;
      }
    }
  }

  cout << sum;

  return 0;
}
