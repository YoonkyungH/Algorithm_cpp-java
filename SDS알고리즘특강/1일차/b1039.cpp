// 교환
// 핵심: 레이어별로 처리하기
// 강사님 말씀으로는 큐가 아니라 스택이어도 문제가 없다고 하심
// BFS

#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int K;
// char n[10];
queue<string> q;
string str, ans;

int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0);

    str="0"; ans="0";   // K번 연산이 불가능한 경우를 위함

    cin >> str >> K;

    q.push(str);

    for(int i=0; i<K; i++) {
        set<string> s;  // 중복 계산을 방지하기 위해 set

        // 처음에 q.size()를 그대로 범위에 사용하였는데,
        // pop()과정이 있어 크기가 계속 바뀌므로 변수를 사용하는 것이 맞음
        int qSize = q.size(); 

        for(int j=0; j<qSize; j++) {
            str = q.front();
            q.pop();

            // set.count(element): element에 해당하는 개수를 반환
            if(s.count(str) == 1) { continue; } // 이미 (set에 있으므로)처리한 것
            s.insert(str);  // 처리하지 않은 것만 insert

            for(int k=0; k<str.length()-1; k++) {
                for(int l=k+1; l<str.length(); l++) {
                    if(k==0 && str[l]=='0') { continue; }   // 첫번째 문자와 교환할 때, 첫번째 문자가 될 문자가 '0'이라면

                    // 교환하는 과정
                    char tmp = str[k];
                    str[k] = str[l];
                    str[l] = tmp;

                    q.push(str);

                    // 원상복구
                    tmp = str[k];
                    str[k] = str[l];
                    str[l] = tmp;
                }
            }
        }
    }

    while(!q.empty()) {
        ans = max(ans, q.front());  // 교환해 만든 수들이 담긴 set에서 최댓값을 찾는 과정
        q.pop();
    }

    if(ans[0] == '0') cout << "-1\n";   // 연산을 K번 할 수 없다면 -1 출력
    else cout << ans.c_str() << '\n';

    return 0;
}