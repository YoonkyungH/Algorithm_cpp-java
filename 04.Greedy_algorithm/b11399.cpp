#include <iostream>
#include <algorithm>
using namespace std;

// ATM

int main() {
  ios::sync_with_stdio(0);
  int N, sum=0, result=0;
  int arr[1000];

  cin >> N;
  for(int i=0; i<N; i++) {  // arr에 걸리는 시간들을 다 넣어줌
    cin >> arr[i];
  }
  sort(arr, arr+N);         // 오름차순 정렬
  for(int i=0; i<N; i++) {
    sum += arr[i];          // 해당 인덱스에서 걸리는 시간을 sum으로 체크
    result += sum;          // result에 sum들을 다 더한 값이 문제에서 원하는 값
  }
  cout << result << '\n';
  return 0;
}
