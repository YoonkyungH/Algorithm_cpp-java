#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 수 찾기
// 이분탐색 코드는 공부하다 본 코드를 참고함

// 시간초과(함수 인자에 vector가 들어가면 vector를 복사하는데 오랜 시간 소요)
// vector<int>& number과 같이 vector 참조자를 사용하면 복사하지 않아(클래스를 따로 만들지 않아) 시간 단축
// 질문 게시판 참조

int N, M, num;
vector<int> number;

int search(vector<int>& number, int t) {
  int low = 0;
  int high = number.size() - 1;
  int mid;

  while(low <= high) {
      mid = (low + high) / 2;

      // 찾으려는 값이 vector의 mid값과 일치하면 1 반환
      if (number[mid] == t) return 1;
      // 찾으려는 값이 vector의 mid값보다 작다면 high값에 mid-1
      else if (number[mid] > t) high = mid - 1;
      // 찾으려는 값이 vector의 mid값보다 크다면 high값에 mid+1
      else low = mid + 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> num;
    number.push_back(num);
  }
  sort(number.begin(), number.end());

  cin >> M;
  for(int i=0; i<M; i++) {
    cin >> num;
    cout << search(number, num) << '\n';
  }

  return 0;
}
