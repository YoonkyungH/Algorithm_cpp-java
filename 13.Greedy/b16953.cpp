#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// A->B
// B에서 A로 가는 방향으로 계산
// B가 짝수면 2로 나누고 홀수면 끝자리 '1'을 없앰
// 결국 B==A가 되면 cnt 출력
// B가 A보다 작아지면 -1 출력

int main() {
  ios::sync_with_stdio(0);
  long A, B;
  long cnt = 0;
  string s="";

  cin >> A >> B;

  while(1) {
    if(A == B) {
      cnt++; break;
    } else if (A > B) {
      cnt = -1; break;
    }
    if(B%2 == 0) { // B가 짝수라면
      B /= 2;
      cnt++;
    } else {  // B가 홀수라면 끝자리 1삭제
      // 마지막 자리가 1이 아닌 경우에도 끝 자리 수를 삭제해 버리는 경우가 생기므로
      // 아래와 같이 체크해줄 필요가 있음
      s = to_string(B);
      reverse(s.begin(), s.end());
      if(s[0] == '1') {
        B--;
        B /= 10;
        cnt++;
      } else {cnt = -1; break;}

    }
  }

  cout << cnt;
  return 0;
}
