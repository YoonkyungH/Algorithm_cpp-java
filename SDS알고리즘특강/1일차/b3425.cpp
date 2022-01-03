// 고스택
// 스택사용

#include <iostream>
#include <stack>
#include <string>
#include <cstring>  // strcmp
#include <vector>
#include <cstdlib>

using namespace std;

struct stOpr {
    string instruction;
    int num;
};

// stack<int> s;

int main() {
    ios::sync_with_stdio(0);

    char instruction[5];
    int num;

    string str = "";
    bool flag = true;
    while(1) {
        vector<stOpr> v; // 연산

        while(1) {
            cin >> instruction;

            if(strcmp(instruction, "QUIT") == 0) { return 0; }
            else if(strcmp(instruction, "END") == 0) { break; }
            else if(strcmp(instruction, "NUM") == 0) { cin >> num; }

            string str(instruction);
            v.push_back((stOpr){str, num});
        }

        int n;
        cin >> n;

        while(n--) {
            cin >> num;

            stack<int> s;
            s.push(num);

            bool isError = false;
            for(stOpr opr : v) {
                long long a, b;

                if(isError) { break; }

                if(opr.instruction == "NUM") { s.push(opr.num); }
                else if(opr.instruction == "POP") {
                    if(s.empty()) { isError = true; }
                    else { s.pop(); }
                }
                else if(opr.instruction == "INV") {
                    if(s.empty()) { isError = true; }
                    else {
                        num = s.top();
                        s.pop();
                        s.push(-num);
                    }
                }
                else if(opr.instruction == "DUP") {
                    if(s.empty()) { isError = true; }
                    else {
                        s.push(s.top());
                    }
                }
                else if(opr.instruction == "SWP") {
                    if(s.size() < 2) { isError = true; }
                    else {
                        a = s.top(); s.pop();
                        b = s.top(); s.pop();
                        s.push(a); s.push(b);
                    }
                }
                else if(opr.instruction == "ADD") {
                    if(s.size() < 2) { isError = true; }
                    else {
                        a = s.top(); s.pop();
                        b = s.top(); s.pop();
                        if(abs(a+b) > 1000000000) { isError = true; }
                        else { s.push((int)a + (int)b); }
                    }
                }
                else if(opr.instruction == "SUB") {
                    if(s.size() < 2) { isError = true; }
                    else {
                        a = s.top(); s.pop();
                        b = s.top(); s.pop();
                        if(abs(b-a) > 1000000000) { isError = true; }
                        else { s.push((int)b - (int)a); }
                    }
                }
                else if(opr.instruction == "MUL") {
                    if(s.size() < 2) { isError = true; }
                    else {
                        a = s.top(); s.pop();
                        b = s.top(); s.pop();
                        if(abs(a*b) > 1000000000) { isError = true; }
                        else { s.push((int)a * (int)b); }
                    }
                }
                else if(opr.instruction == "DIV") {
                    if(s.size() < 2) { isError = true; }
                    else {
                        a = s.top(); s.pop();
                        b = s.top(); s.pop();
                        if(a==0) { isError = true; }
                        else {
                            int tmp = 0;
                            if(a<0) tmp += 1;
                            if(b<0) tmp += 1;

                            if(tmp == 1) {  // a, b 중 하나만 마이너스일 경우
                                s.push(abs(b) / abs(a) * (-1));
                            } else {
                                s.push(abs(b) / abs(a));
                            }
                        }
                    }
                }
                else if(opr.instruction == "MOD") {
                    if(s.size() < 2) { isError = true; }
                    else {
                        a = s.top(); s.pop();
                        b = s.top(); s.pop();
                        if(a == 0) { isError = true; }
                        else { s.push(b%a); }
                    }
                }
            }

            if(isError || s.size() != 1) {
                cout << "ERROR\n";
            } else {
                cout << s.top() << '\n';
            }
        }
        cout << '\n';
    }
    
    return 0;
}