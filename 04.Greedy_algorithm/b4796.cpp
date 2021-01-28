#include <iostream>
#include <algorithm>
using namespace std;

// 캠핑
// 처음에 P가 0인 경우 예외처리를 해주지 않아서 런타임 에러
int main() {
  ios::sync_with_stdio(0);
  int L, P, V;
  int camp=0;

  int i=1;
  while(1){
    cin >> L >> P >> V;
    // 0 0 0이 입렸됐을 경우 while문 탈출
    if(L==0 && P==0 && V==0) {
      break;
    }
    // P가 0보다 클 경우
    // 최대 사용일 = 사용가능일*(휴가일/연속사용일) + (휴가일%연속사용일)과 사용가능일 중 최소값
    if(P>0) {
      camp = (L*(V/P))+min(V%P, L);
      cout << "Case " << i << ": " << camp << '\n';
      i++;
    }
  }
  return 0;
}
