// 스도쿠
// 백트래킹
// segmentation fault 문제 해결 못함

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int map[10][10];
vector<pair<int, int> > v;

bool isCorrect(int x, int y, int k) {
    for(int i=1; i<=9; i++) {   // 세로 중복 확인
        if(i == x) { continue; }
        if(map[i][y] == k) { return false; }
    }

    for(int i=1; i<=9; i++) {   // 가로 중복 확인
        if(i == y) { continue; }
        if(map[x][i] == k) { return false; }
    }

    int tx, ty; // 3x3 크기의 보드 중복 여부 확인
    if(x%3 == 0) { tx = x/3; }
    else { tx = x/3 + 1; }

    if(y%3 == 0) { ty = y/3; }
    else { ty = y/3 + 1; }

    tx *= 3;
    ty *= 3;

    for(int i=tx-2; i<=tx; i++) {
        for(int j=ty-2; j<=ty; j++) {
            if(i == x && j == y) { continue; }
            if(map[i][j] == k) { return false; }
        }
    }

    return true; 
}

void DFS(int idx) {
    if(idx == v.size()) {   // 출력하기
        for(int i=1; i<=9; i++) {
            for(int j=1; j<=9; j++) {
                cout << map[i][j];
            } cout << '\n';
        }
    }

    int x = v[idx].first;
    int y = v[idx].second;

    for(int j=1; j<=9; j++) {
        if(isCorrect(x, y, j)) {
            map[x][y] = j;
            DFS(idx+1);
            map[x][y] = 0;
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    for(int i=1; i<=9; i++) {
        cin >> str;
        for(int j=1; j<=9; j++) {
            map[i][j] = str[j-1] - '0';
            if(map[i][j] == 0) {
                v.push_back(make_pair(i, j));
            }
        }
    }

    DFS(0); 

    return 0;
}