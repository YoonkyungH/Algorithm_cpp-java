#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

// 차이를 최대로
// 순열을 어떻게 해야하나 찾다가 C++ STL next_permutation
// algorithm 헤더 필요. 배열의 시작과 끝을 인자로 받아 n개의 원소의 순열을 구할 수 있음.
// 오름차순으로 정렬된 값만 사용 가능 주의

int main() {
  ios::sync_with_stdio(0);

  // vector<int> v;

  int N, sum=0, result=0;
  cin >> N;
  vector<int> v(N);
  // 왜 벡터의 크기를 지정해줘야 하는지 모르겠음. 근데 지정 안하면 안됨.
  for(int i=0; i<N; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  // m: 가장 큰 원소, mm: 두번째로 큰 원소
  int m = v[0]; int mm = v[1];
  do {
    sum = 0;
    // 왠지 이렇게 하면 더 빨라질 것 같아서
    // 일단 가장 큰 원소 옆에 두번째로 큰 원소가 있으면 답이 될 수 없으므로 break
    for(int i=0; i<N-1; i++) {
      if(v[i]==m||v[i]==mm) {
        if(v[i+1]==m||v[i+1]==mm)
          break;
      }
      sum += abs(v[i]-v[i+1]);
    } result = max(result, sum);  // 최댓값 갱신
  } while(next_permutation(v.begin(), v.end()));  // 순열 생성

  cout << result << '\n';

  return 0;
}
