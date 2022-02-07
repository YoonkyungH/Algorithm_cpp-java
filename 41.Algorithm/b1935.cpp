// 후위 표기식2
// 자료구조

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int N, n;
string str, tmp;
stack<double> st;
vector<int> v;

bool flag;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin >> str;

    v.resize(N);

    for(int i=0; i<N; i++) {
        cin >> v[i];
    }

    for(int i=0; i<str.length(); i++) {
        if('A' <= str[i] && str[i] <= 'Z') {
            st.push(v[str[i] - 'A']);
        } else {
            if(!st.empty()) {
                double tmp = st.top();
                st.pop();

                if(str[i] == '+') {
                    tmp += st.top();
                } else if(str[i] == '-') {
                    tmp = st.top() - tmp;
                } else if(str[i] == '*') {
                    tmp *= st.top();
                } else if(str[i] == '/') {
                    tmp = st.top() / tmp;
                }

                st.pop();
                st.push(tmp);   // 다시 결과값 넣기
            }
        }
    }

    cout << fixed;  // "소수점을 고정시켜 표현함"
    cout.precision(2);  // precision(n): 소수점 n자리까지 표현
    cout << st.top() << '\n';

    return 0;
}