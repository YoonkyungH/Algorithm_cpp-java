#include <iostream>
using namespace std;

// 블랙잭

int main() {
  ios::sync_with_stdio(0);
  int N, M;
  int card[100];
  int sum;
  int result=0;

  cin >> N >> M;
  for(int i=0; i<N; i++) {
    cin >> card[i];
  }
  for(int i=0; i<N-2; i++) {
    for(int j=i+1; j<N-1; j++) {
      for(int k=j+1; k<N; k++) {          // 카드를 세개씩 묶어서 더하는 과정
        sum = card[i]+card[j]+card[k];
        if(sum<=M && M-sum < M-result) {  // 카드의 합이 외친 수보다 작거나 같아야 하며, 바로 저번 합보다 외친 수와의 차이가 작아야 함
          result = sum;
        }
      }
    }
  }
  cout << result << endl;

  return 0;
}
