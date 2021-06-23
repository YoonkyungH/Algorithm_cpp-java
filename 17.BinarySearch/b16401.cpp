#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 과자 나눠주기

int arr[1000001];
int M, N;         // M: 조카 N: 과자
int len = 0;      // 과자 길이

// bool desc(int a, int b) {
//   return a > b;
// }

bool check(int a) {
  int cnt = 0;  // 몇명에게 나눠줄 수 있는지
  int temp;     // 과자 길이

  for(int i=N-1; i>=0; i--) {
    if(len > arr[i]) { break; }     // 확인할 과자 길이가 가진 과자보다 길면 나눠줄 수 없음
    temp = arr[i];
    while(temp >= a) {              // 과자를 자를 수 있을만큼 자르기
      cnt++;                        // 자른 과자가 몇개 나오는지
      temp -= a;                    // 과자를 자르면서 과자의 길이가 줄어듦
    }
    if(cnt >= M) { return true; }   // 과자 수가 아이의 수보다 많으면
  }
  if(cnt >= M) { return true; }
  else { return false; }            // 과자 수가 아이의 수보다 적으면
}

void search(int left, int right) {
  if(left > right) { return; }

  int mid = (left+right) / 2;

  if(check(mid)) {                 // 나누어줄 수 있는 과자 길이라면
    if(len < mid) { len = mid; }
    search(mid+1, right);
  } else {
    search(left, mid-1);
  }
}

int main() {
  ios::sync_with_stdio(0);

  cin >> M >> N;
  for(int i=0; i<N; i++) {
    cin >> arr[i];
  }
  sort(arr, arr+N);

  search(1, arr[N-1]);

  cout << len << '\n';



  return 0;
}
