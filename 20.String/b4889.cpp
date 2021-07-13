#include <iostream>
#include <stack>
#include <string>
using namespace std;

// stack: LIFO

// 안정적인 문자열
// {{{{{{ 일 때 {}{}{}이든 {{{}}}이든 3개를 바꿔야 하는 것은 동일

int main() {
  ios::sync_with_stdio(0);

  string s;
  int i=1;

  while(1) {
    stack<char> st;
    cin >> s;

    if(s[0] == '-') { break; }

    int cnt = 0;

    for(int i=0; i<s.size(); i++) {
      if(s[i] == '{') {
        st.push('{');
      } else if(st.empty() && s[i]=='}') {
        st.push('{');
        cnt++;                              // { 로 바꾸어 스택에 넣음. 바꾼 횟수 증가
      } else if(!st.empty() && s[i]=='}') {
        st.pop();                           // 괄호 짝이 맞추어 졌으니 꺼냄
      }
    }

    if(st.size()>0) {
      cnt += st.size()/2;
    }

    cout << i << ". " << cnt << '\n';
    i++;
  }


  // int i = 1;
  // while(1) {
  //
  //   string s;
  //   int cnt = 0;
  //
  //   stack<char> stk;
  //   cin >> s;
  //
  //   if(s[0] == '-') {
  //     break;
  //   }
  //
  //   for(int i=0; i<s.size(); i++) {
  //     if(stk.size()==0 && s[i]=='}') {
  //       cnt++;
  //       s[i] = '{';
  //       stk.push(s[i]);
  //     } else if(stk.size()!=0 && s[i]=='}') {
  //       stk.pop();
  //     } else {
  //       stk.push(s[i]);
  //     }
  //   }
  //
  //   cnt = cnt + stk.size()/2;
  //   cout << i << ". " << cnt << '\n';
  //
  // }

  return 0;
}
