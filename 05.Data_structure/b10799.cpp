#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 쇠막대기

int main() {
  ios::sync_with_stdio(0);
  string s;           // 입력 괄호들을 받아 저장
  stack<char> str;    // stack에 저장시키며 막대기에 개수를 셀 예정
  int stick = 0;      // 최종 막대기의 개수

  cin >> s;
  for(int i=0; i<s.size(); i++) {
    // '('이며 다음이 ')'가 아닐 때 stack에 '('를 저장
    if(s[i] == '(' && s[i+1] != ')') {
      str.push('(');
    }
    // '('이며 다음이 ')'일 때 잘림.
    // 그러므로 stack에 저장해뒀던 만큼이 stick의 개수로 잘리는 것이기 때문에
    // stick에 stack의 size 만큼을 저장. 그리고 ')'를 건너뛰기 위해 i++
    else if(s[i] == '(' && s[i+1] == ')') {
      stick += str.size(); i++;
    }
    // ')'가 연속될 경우 막대기가 끝나는 경우이기 때문에
    // stack에서 pop시켜서 버림. 그리고 막대기의 끝이 남기 때문에 stick++
    else if(s[i] == ')' && s[i] == ')') {
      str.pop(); stick++;
    }
  }

  cout << stick << '\n';

  return 0;
}
