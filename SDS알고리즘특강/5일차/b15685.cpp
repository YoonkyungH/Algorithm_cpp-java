// 치킨 배달
// 조합 응용
// 삼성 공채 스타일

#include <iostream>
#include <cstdlib>  // abs
#include <algorithm>    // min

using namespace std;

#define INF 987654321

struct pos {
    int r, c;
};

int N, M, s;   // s: 지금까지 고른 치킨집 개수
int houseCnt, chickenCnt;
pos house[2501];  // 50*50 + 1
pos chicken[14];    // 집으로 꽉 차있을 순 있지만 치킨집은 최대 13개까지밖에 존재할 수밖에 없으므로
int selectedIdx[14];         // 골라진 치킨집 인덱스
int ans = INF;

void calcDis() {
    int sum = 0;
    for(int i=0; i<houseCnt; i++) {
        int minDist = INF, dist;

        // i번째 집에서 선택된 치킨집들까지의 거리 중 최소 치킨거리
        for(int j=0; j<s; j++) {
            dist = abs(house[i].r - chicken[selectedIdx[j]].r) + abs(house[i].c - chicken[selectedIdx[j]].c);
            minDist = min(minDist, dist);
        }
        sum += minDist;
    }

    ans = min(ans, sum);
}

void backtracking(int idx) {
    if(s == M) {
        calcDis();
        return;
    }

    for(int i=idx; i<chickenCnt; i++) {
        if(chickenCnt-i < M-s) { break; }   // 가지치기
        selectedIdx[s] = i;
        s++;

        backtracking(i+1);
        s--;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    // ans = INF;   // 여기서 초기화해도 됨

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int n;
            cin >> n;
            if(n == 1) {    // 집
                house[houseCnt].r = i;
                house[houseCnt].c = j;
                houseCnt++;
            }
            else if(n==2) { // 치킨집
                chicken[chickenCnt].r = i;
                chicken[chickenCnt].c = j;
                chickenCnt++;
            }
        }
    }

    backtracking(0);
    cout << ans << '\n';

    return 0;
}