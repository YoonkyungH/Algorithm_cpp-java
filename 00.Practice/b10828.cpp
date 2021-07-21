#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 스택

int main() {
  ios::sync_with_stdio(0);

  int N;
  cin >> N;

  stack<int> st;
  int n;
  for(int i=0; i<N; i++) {
    string str;

    cin >> str;

    if(str[0] == 'p' && str[1] == 'u') {
      cin >> n;
      st.push(n);
    } else if(str[0] == 'p' && str[1] == 'o') {
      if(!st.empty()) {
        cout << st.top() << '\n';
        st.pop();
      } else { cout << "-1" << '\n'; }
    } else if(str[0] == 's') {
      cout << st.size() << '\n';
    } else if(str[0] == 'e') {
      if(st.empty()) { cout << '1' << '\n'; }
      else { cout << '0' << '\n'; }
    } else if(str[0] == 't') {
      if(!st.empty()) { cout << st.top() << '\n'; }
      else { cout << "-1" << '\n'; }
    }
  }

  return 0;
}
