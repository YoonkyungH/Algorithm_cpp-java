#include <iostream>
#include <algorithm>
using namespace std;

// 동전 0

bool desc(int a, int b) {         // 내림차순 정렬
  return a > b;                   // 처음에 부호 반대로 써서 삽질함
}

int main() {
  ios::sync_with_stdio(0);
  int N, K;
  int coin[10];
  int sum=0;

  cin >> N >> K;
  for(int i=0; i<N; i++) {
    cin >> coin[i];
  }
  sort(coin, coin+N, desc);       // 내림차순 정렬(동전 개수의 최소값을 구해야 하기 때문)
  int i=0;
  while(K!=0) {                   // K가 0이 될 때까지
    if(K-coin[i] > 0) {           // K에서 배열 원소를 뺐을때 양수가 남으면 낼 수 있는 최대 값어치를 하는 동전을 냈다는 것
      sum++;
      K -= coin[i];               // 동전을 낸만큼 K값을 감소
    } if(K-coin[i] == 0) {        // 내야하는 만큼의 동전을 모두 냈다는 것
      sum++; K -= coin[i];
    } if(K-coin[i] < 0) {         // K-coin[i]이 음수가 나오면 동전을 거슬러 받아야 하는 경우이기 때문
      i++;
    }
  }
  cout << sum << '\n';
  return 0;
}
