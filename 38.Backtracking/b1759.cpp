// 암호 만들기
// 백트래킹

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

char arr[16];   // 문자열이라 한 칸 공백 필요
vector<char> v;
int L, C;

void DFS(int cnt, int idx, int m, int j) {    // m: 모음, j: 자음
    if(cnt == L) {
        if(m>=1 && j>=2) {
            for(int i=0; i<v.size(); i++) {
                cout << v[i];
            } cout << '\n';
        }
        return;
    }

    for(int i=idx; i<C; i++) {
        v.push_back(arr[i]);

        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') { // 모음 중 하나면
            DFS(cnt+1, i+1, m+1, j);
        } else {
            DFS(cnt+1, i+1, m, j+1);
        }

        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    for(int i=0; i<C; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+C);   // 알파벳 오름차순 정렬
    DFS(0, 0, 0, 0);

    return 0;
}