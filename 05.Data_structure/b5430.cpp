#include <iostream>
#include <string>
#include <deque>
#include <stdlib.h>
using namespace std;

// AC

int main() {
  ios::sync_with_stdio(0);
  deque<int> dq;
  // T: 테스트 케이스 개수
  // n: 배열 원소의 수
  // AC: 연산
  // arr: 수배열을 받을 변수
  int T, n;
  string AC;
  string arr;
  bool R;
  bool error;

  cin >> T;
  for(int i=0; i<T; i++) {
    // 연산 초기화, 배열 원소의 수 초기화, 덱 초기화
    AC = ""; n = 0; dq.clear();
    R = false; error = false;
    cin >> AC >> n;
    cin >> arr;
    int j=0;
    string tmp="";
    // tmp에 배열원소 하나씩 넣은 다음 ','를 만나면 수가 끝난 것이므로 덱에 push
    while(1) {
      if(arr[j]=='[') j++;
      else if(arr[j]==']') break;
      else {
        if(arr[j]==',') {dq.push_back(atoi(tmp.c_str())); j++; tmp="";}
        else {tmp+=arr[j]; j++;}
      }
    }
    // 마지막 tmp에 있는 값까지 덱에 push
    if(tmp.length()!=0) dq.push_back(atoi(tmp.c_str()));

    for(int j=0; j<AC.size(); j++) {
      if(AC[j] == 'R') {
        R = !R;                         // R을 만나면 값을 반대로
      } else if(AC[j] == 'D') {
        if(dq.empty()) {
          error = true; break;         // 덱이 비었으면 error를 true, for문 탈출
        }
        if(R == true) dq.pop_back();   // 뒤집혔으므로 맨 뒤 값 pop
        else dq.pop_front();           // 변화 없으므로 맨 앞 값 pop
      }
    }

    if(error) {                        // 위에서 체크한 덱이 비었을 경우 출력하고 다음 테스트로 넘어갈 것
      cout << "error" << '\n';
      continue;
    }
    else {                             // error가 false일 때,
      cout << '[';
      if(R) {                          // 덱이 뒤집혔다면 뒤에서부터 출력하고 pop
        while(dq.size()) {
          cout << dq.back();
          dq.pop_back();
          if(dq.size()) cout << ',';
        }
      } else {                         // R이 false일 때 앞에서부터 출력하고 pop
        while(dq.size()) {
          cout << dq.front();
          dq.pop_front();
          if(dq.size()) cout << ',';
        }
      }
      cout << ']' << '\n';
    }
  }
  return 0;
}
