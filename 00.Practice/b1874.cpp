#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 스택 수열

int main() {
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> v;
  vector<char> v2;
  int num;

  for(int i=0; i<n; i++) {
    cin >> num;
    v.push_back(num);
  }

  stack<int> st;
  int j=0;
  for(int i=1; i<=n; i++) {
    st.push(i);
    v2.push_back('+');

    while(!st.empty() && st.top()==v[j]) {
      st.pop();
      v2.push_back('-');
      j++;
    }
  }

  if(!st.empty()) { cout << "NO\n"; }
  else {
    for(int i=0; i<v2.size(); i++) {
      cout << v2[i] << '\n';
    }
  }


  return 0;
}
