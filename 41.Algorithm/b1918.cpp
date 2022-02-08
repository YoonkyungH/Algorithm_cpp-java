// 후위 표기식

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
stack<char> st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    for(int i=0; i<str.length(); i++) {
        if('A' <= str[i] && str[i] <= 'Z') {    // 피연산자면 그냥 출력
            cout << str[i];
        }
        else {                                  // 연산자일 때
            if(st.empty()) {                    // 스택이 비어있으면 그냥 push
                st.push(str[i]);    
            } else {
                if(str[i] == '(') {             // 열린 괄호라면 push
                    st.push(str[i]);
                }
                else if(str[i] == ')') {        // 닫힌 괄호라면 열린 괄호가 나올 때까지 출력, 스택 pop
                    while(st.top() != '(') {

                        cout << st.top();
                        st.pop();
                    } st.pop();                 // 열린 괄호를 pop
                }
                else if(str[i] == '*' || str[i] == '/') {       // 연산자가 우선순위가 높은 *나 /일 때
                    if (st.top() == '*' || st.top() == '/') {   // 스택의 top이 우선순위가 높은 *나 /라면
                        cout << st.top();                       // 출력해주고 pop
                        st.pop();
                    }
                    st.push(str[i]);                            

                }
                else if(str[i] == '+' || str[i] == '-') {       // 우선순위가 비교적 낮은 +나 -라면
                    while(!st.empty() && st.top() != '(') {     // 스택의 top이 열린 괄호라면 push하고,
                        cout << st.top();                       // 열린 괄호가 아니라면 출력해주고 pop
                        st.pop();
                    }

                    st.push(str[i]);
                }
            }
        }
        
    }


    while(!st.empty()) {        // 스택에 남아있는 원소 모두 출력하고 빼내기
        cout << st.top();
        st.pop();
    } cout << '\n';

    return 0;
}