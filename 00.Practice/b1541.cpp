#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> v;      // 숫자
vector<char> v2;    // 연산자
int sum = 0;        // 합(최솟값)

void parsing(string str) {
    string tmp = "";
    for(int i=0; i<str.length(); i++) {
        if(str[i]=='+' || str[i]=='-') {
            v.push_back(stoi(tmp));
            v2.push_back(str[i]);
            tmp = "";
        } else { tmp += str[i]; }
    }
    v.push_back(stoi(tmp));
}

void calculator(vector<int> v, vector<char> v2) {
    sum += v[0];
    int j=0;
    for(int i=1; i<v.size(); i++) {

        if(v2[j] == '+') { sum += v[i]; j++; }
        else if(v2[j] == '-') {
            int tmp = v[i++]; j++;
            while(v2[j]=='+') {
                if(i >= v.size() && j >= v2.size()) { break; } 
                tmp+=v[i]; i++; j++;
            }
            i--;
            sum -= tmp;
        }

    }

}

int main() {
    ios::sync_with_stdio(0);

    string str;
    cin >> str;

    parsing(str);
    calculator(v, v2);

    cout << sum << '\n';

    return 0;
}