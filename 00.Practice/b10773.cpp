#include <iostream>
#include <stack>
using namespace std;

// 제로

int main() {
  ios::sync_with_stdio(0);

  int K, n;
  stack<int> st;
  cin >> K;

  for(int i=0; i<K; i++) {
      cin >> n;
      if(n == 0) { st.pop(); }
      else { st.push(n); }
  }

  int sum = 0;
  while(!st.empty()) {
    sum += st.top();
    st.pop();
  }

  cout << sum << '\n';

  return 0;
}
