#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>        // INT_MAX를 위함
using namespace std;

// 나무 자르기
// 자꾸만 답이 1만 나와서 질문에 있는 코드가 저랑 비슷하길래 좀 참고,,
// int treelen과 int ans -> long long

vector<int> tree;
long long treelen;
int N, M;
long long ans;

void search(long long start, long long end) {
  long long mid;

  // while에서 if로 수정
  if(start<=end) {
    treelen = 0;
    mid = (start + end) / 2;
    // 잘리고 남은 나무의 길이를 다 더하기 위한 for문
    for(int i=0; i<tree.size(); i++) {
      if(tree[i]-mid < 0) continue;
      treelen += tree[i]-mid;
    }
    // treelen이 필요한 길이 M보다 크거나 같으면 ans에 mid값을 넣고 절단기 높이를 늘려 또 탐색
    if (treelen >= M) {ans = mid; search(mid+1, end);}
    // else if (treelen > M) search(mid+1, high);
    else search(start, mid-1);      // treelen이 필요한 길이 M보다 모자랄 때 절단기 길이를 줄여 탐색
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;

  cin >> N >> M;
  for(int i=0; i<N; i++) {
    cin >> t;
    tree.push_back(t);
  }

  sort(tree.begin(), tree.end());
  // INT_MAX는 int의 최댓값. climits 헤더에 선언되어 있음.
  // 원래 정렬된 벡터의 [0]과 젤 끝 값을 넣었음.
  search(0, INT_MAX);
  cout << ans << '\n';

  return 0;
}
