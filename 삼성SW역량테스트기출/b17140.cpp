// 이차원 배열과 연산
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>  // memset
using namespace std;

// int arr[101][101] = {0, };
int check[101] = {0, }; // 숫자 빈도 횟수
vector<vector<int> > v;
int r, c, k;
int rowLen, colLen;
int sec;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

void Row() {    // 행 연산
    for(int i=0; i<rowLen; i++) {
        memset(check, 0, sizeof(check));

        for(int j=0; j<colLen; j++) {
            if(v[i][j] != 0) {
                check[v[i][j]]++;
            }
        }

        vector<pair<int, int> > tmp;
        for(int j=1; j<101; j++) {
            if(!check[j]) continue;

            tmp.push_back(make_pair(j, check[j]));
        }

        sort(tmp.begin(), tmp.end(), cmp);   // 오름차순 정렬

        colLen = max(colLen, int(tmp.size()) * 2);  // 최대 행 수

        for(int j=0; j<v[i].size(); j++) {
            v[i][j] = 0;
        }
        // memset(v[i], 0, sizeof(v[i]));
        for(int j=0; j<tmp.size(); j++) {
            v[i][j*2+1] = tmp[j].first;
            v[i][(j+1) * 2] = tmp[j].second;
        }

    }
}

void Col() {    // 열 연산
    for(int i=0; i<colLen; i++) {
        memset(check, 0, sizeof(check));

        for(int j=0; j<rowLen; j++) {
            if(v[j][i] != 0) {
                check[v[j][i]]++;
            }
        }

        vector<pair<int, int> > tmp;
        for(int j=1; j<101; j++) {
            if(!check[j]) continue;

            tmp.push_back(make_pair(j, check[j]));
        }

        sort(tmp.begin(), tmp.end(), cmp);

        rowLen = max(rowLen, int(tmp.size()) * 2);

        for(int j=0; j<100; j++) {
            v[j][i] = 0;
        }

        for(int j=0; j<tmp.size(); j++) {
            v[j*2 + 1][i] = tmp[j].first;
            v[(j+1) * 2][i] = tmp[j].second;
        }

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;
    rowLen = 3; colLen = 3;   // 행, 열 길이

    v.resize(3, vector<int>(3, 0));
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            // cin >> arr[i][j];
            cin >> v[i][j];
            
        }
    }

    while(1) {
        if(v[r-1][c-1] == k) {
            cout << sec << '\n';
            break;
        }
        if(sec > 100) {
            cout << "-1\n";
            break;
        }

        rowLen = v.size();
        colLen = v[0].size();


        if(rowLen >= colLen) {  // 행의 길이 >= 열의 길이 -> 행 정렬 연산
            Row();
        } else {    // 열의 길이 > 행의 길이 -> 열 정렬 연산
            Col();
        }

        sec++;
    }
    

    return 0;
}