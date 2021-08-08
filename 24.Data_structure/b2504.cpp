#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 괄호의 값
// 어떻게 풀어야할지 대충은 감을 잡았으나 코드로 구현하는 과정에서 어려움을 겪음.
// 그래서 결국 찾아봤는데 내가 생각했던 방법보다 덜 무식하고 좋은 방법을 찾음.
// (()[[]]) 일때, 2*(2+3*(3))=22 이를 분배법칙으로 풀어보면 2*2 + 2*3*3

int main() {
    ios::sync_with_stdio(0);

    string str;
    cin >> str;

    stack<char> st;

    int tmp = 1, ans = 0;
    bool flag = false;
    for(int i=0; i<str.length(); i++) {
        
        if(str[i] == '(') {
            st.push(str[i]);
            tmp *= 2;
        } else if(str[i] == '[') {
            st.push(str[i]);
            tmp *= 3;
        }
        
        else if(str[i] == ')') {
            if(st.empty()) { flag = true; break; }
            
            if(st.top() == '(') {
                if(str[i-1] == '(') { ans += tmp; }

                st.pop();
                tmp /= 2;
            } else {
                flag = true; break;
            }
        }

        else if(str[i] == ']') {
            if(st.empty()) { flag = true; break; }

            if(st.top() == '[') {
                if(str[i-1] == '[') { ans += tmp; }

                st.pop();
                tmp /= 3;
            } else {
                flag = true; break;
            }
        }
    }

    if(flag==true || st.size()>0) { 
        cout << "0\n"; return 0;
    }

    cout << ans << '\n';


    return 0;
}