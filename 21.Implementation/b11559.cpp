#include <iostream>
#include <vector>
#include <string>
// #include <string.h>
using namespace std;

// 뿌요뿌요
// 연쇄로 터지는 과정을 하나로 친다는 것이 생각하기 어려웠음

string str[12];
vector<char> v[6];

int result = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int visited[6][12] = {0, };


void dfs2(char a, int yy, int xx, int cnt) {
    int sum = cnt;

    for(int i=0; i<4; i++) {
        int y = yy + dy[i];
        int x = xx + dx[i];

        if(y>=0 && y<6 && x>=0 && x<12 && v[y][x]==v[yy][xx] && visited[y][x]==0) {
            sum++;
            visited[y][x] = sum;
            dfs2(a, y, x, sum);
        }
    }
}

void dfs(char a, int yy, int xx) {
    v[yy][xx] = '8';
    visited[yy][xx] = -1;

    for(int i=0; i<4; i++) {
        int y = yy + dy[i];
        int x = xx + dx[i];

        if(y>=0 && y<6 && x>=0 && x<12 && v[y][x]==a && visited[y][x]!=-1) {
            dfs(a, y, x);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);

    for(int i=0; i<12; i++) {
        cin >> str[i];
    }

    // 90도로 회전해서 벡터에 집어넣음
    for(int i=0; i<6; i++) {
        for(int j=11; j>=0; j--) {
            v[i].push_back(str[j][i]);
        }
    }

    while(1) {
        bool b = false;

        for(int i=0; i<6; i++) {
            for(int j=0; j<12; j++) {
                if(v[i][j] != '.') {
                    // 방문 배열 초기화
                    memset(visited, 0, sizeof(visited));
                
                    visited[i][j] = 1;
                    dfs2(v[i][j], i, j, 1);

                    for(int k=0; k<6; k++) {
                        for(int q=0; q<12; q++) {
                            if(visited[k][q] >= 4) {
                                char word = v[k][q];
                                dfs(word, k, q);
                            }
                        }
                    }

                }
            }
        }

        for(int i=0; i<6; i++) {
            for(int j=0; j<v[i].size(); j++) {
                if(v[i][j] == '8') {
                    b = true;
                    v[i].erase(v[i].begin() + j);
                    j--;
                }
            }
        }

        for(int i=0; i<6; i++) {
            if(v[i].size() < 12) {
                while(v[i].size() != 12) {
                    v[i].push_back('.');
                }
            }
        }

        if(b == false) { break; }

        result++;

    }

    cout << result << '\n';


    return 0;
}