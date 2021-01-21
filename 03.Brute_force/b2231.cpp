#include <iostream>
using namespace std;

// 분해합

int main() {
  ios::sync_with_stdio(0);
  int N;

  cin >> N;

  for(int i=1; i<N; i++) {  // 생성자가 N보다 클 수는 없으므로 N까지만 순회
    int sum = i;            // 분해합
    int j = i;              // 분해합을 구하기 위한 변수(i를 그대로 쓰면 19줄 출력할 때 못 쓰기 때문)
    while(j>0) {            // 10으로 나눈 값이 0이 될 때는 분해합을 끝까지 구한 경우이기 때문
        sum += j%10;        // 245의 경우 245에 "2+4+5를 더하는 과정"을 구하기 위함
        j /= 10;
    } if(sum == N) {        // 245+2+4+5의 값이 입력했던 N과 같아지는 때 생성자를 구한 것
      cout << i << endl;
      return 0;             // 0까지 출력하지 않게 하기 위함
    }                       // return 0은 어떻게 코드를 멈춰야할지 몰랐는데 질문을 검색하다 발견
  }
  cout << "0" << endl;      // 생성자가 없을 경우 0을 출력
  return 0;
}
