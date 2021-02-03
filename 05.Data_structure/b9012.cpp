#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 괄호

int main() {
  ios::sync_with_stdio(0);
  int N;
  string s;
  stack<char> sc;

  cin >> N;
  for(int i=0; i<N; i++) {
    s = "";
    while(!sc.empty()) sc.pop();            // 스택 sc를 비우는 과정
    cin >> s;
    for(int j=0; j<s.length(); j++) {
      if(s[j] == '(')  sc.push(s[j]);       // '('를 만나면 스택에 push
      else if(s[j] == ')') {                // ')'를 만나면 하나의 괄호가 된 것. 그러므로 pop
        if(sc.empty()) {                    // 이때 꺼낼 '('가 없다면 스택에 아무값(1)을 넣고 for문 탈출
          sc.push(1); break;
        } else sc.pop();
      }
    }
    if(sc.empty()) cout << "YES" << '\n';   // 스택이 비었다면 VPS이므로 "YES" 출력
    else cout << "NO" << '\n';              // 스택에 무언가 있다면 짝이 맞지 않다는 것이므로 "NO" 출력
  }

  return 0;
}
