// 이차원 배열과 연산
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>  // memset
using namespace std;

int arr[101][101];
int num[101];
int r, c, k;
int rowMax, colMax;   // 행 열
int sec;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

void calRow() {

    for(int i=1; i<=rowMax; i++) {
        vector<pair<int, int> > v;  // (횟수, 숫자)
        // memset(num, 0, sizeof(num));
        int num[101] = {0, };

        for(int j=1; j<=colMax; j++) {
            if(arr[i][j] != 0) {
                num[arr[i][j]]++;
            }
        }

        for(int j=1; j<=100; j++) {
            if(num[j] == 0) continue;

            v.push_back(make_pair(num[j], j));
        }
        sort(v.begin(), v.end(), cmp);   // 정렬
        colMax = max(colMax, int(v.size()*2));


        for(int j=1; j<=colMax; j++) {
            arr[i][j] = 0;
        }   // 초기화

        int k=1;
        for(int j=0; j<v.size(); j++) {
            arr[i][k++] = v[j].second;
            arr[i][k++] = v[j].first;
        }
    }

}

void calCol() {
    for(int i=1; i<=colMax; i++) {
        vector<pair<int, int> > v;
        // memset(num, 0, sizeof(num));
        int num[101] = {0, };
        for(int j=1; j<=rowMax; j++) {
            if(arr[j][i] != 0) {
                num[arr[j][i]]++;
            }
        }

        for(int j=1; j<=100; j++) {
            if(num[j] == 0) continue;

            v.push_back(make_pair(num[j], j));
        }
        sort(v.begin(), v.end(), cmp);
        rowMax = max(rowMax, int(v.size()*2));
        
        for(int j=1; j<=colMax; j++) {
            arr[j][i] = 0; 
        }   // 초기화

        int k=1; 
        for(int j=0; j<v.size(); j++) {
            arr[k++][i] = v[j].second;
            arr[k++][i] = v[j].first;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;
    for(int i=1; i<=3; i++) {
        for(int j=1; j<=3; j++) {
            cin >> arr[i][j];
        }
    }

    rowMax = 3; colMax = 3;
    while(1) {
        if(arr[r][c] == k) {
            cout << sec << '\n';
            break;
        }
        if(sec > 100) {
            cout << "-1\n";   
            break;
        }

        if(rowMax >= colMax) { calRow(); }
        else { calCol(); }
        
        sec++;
    }

    return 0;
}
