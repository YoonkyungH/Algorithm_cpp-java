#include <iostream>
#include <string>
// #include <stdlib.h>
using namespace std;

// 영화감독 숌

int main() {
  ios::sync_with_stdio(0);
  int N, count=0;
  int series=665;
  string s;

  cin >> N;
  while(count!=N) {         // 입력한 수 N이 될 때까지
    series++;               // 한번 돌 때마다 series++ 즉, series를 계속 올리면서 666이 들어간 수들을 검사
    // itoa(series, s);
    s = to_string(series);  // series 수를 s에 문자열 형태로 저장

    if(s.find("666")!=-1) { // find함수 존재하지 않을 경우 -1 반환
      count++;              // s문자열 안에 666이 존재한다면 count++
    }
  }
  cout << series << endl;
  return 0;
}
