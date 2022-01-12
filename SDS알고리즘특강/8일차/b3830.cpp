// 교수님은 기다리지 않는다
// union find 알고리즘 변형
// https://mapocodingpark.blogspot.com/2020/02/BOJ-3830.html 참고

#include <iostream>

using namespace std;

long long dist[100001]; // 물체와 root 사이의 거리를 저장하는 배열
int root[100001];       // 물체의 root를 저장하는 배열

int N, M;   // 샘플 종류, 한 일의 수
char c;
int a, b, w;    // b가 a보다 w그램 무거움

/**
 * find(): x 물체와 root 간의 거리 dist[x]를 최신화
 */
int find(int x) {   // find 변형
    if(root[x] == x) return x;
    
    int r = find(root[x]);
    dist[x] += dist[root[x]];
    return root[x] = r;
}

/**
 * a, b를 union
 * a의 root를 aRoot, b의 root를 bRoot라고 하면
 * bRoot의 root를 aRoot로, aRoot와 bRoot의 거리차를 dist[bRoot]에 저장
 * 
 * dist[bRoot] = (aRoot 기준 b 거리) - (bRoot 기준 b 거리)
 * aRoot 기준 b 거리 = (aRoot 기준 a 거리) + (a 기준 b 거리)
 */
void uni(int a, int b, int diff) {  // union 변형
    int aRoot = root[a];
    int bRoot = root[b];

    if(aRoot == bRoot) return;

    int newD = dist[a] + diff;  // aRoot 기준 b 위치
    int originD = dist[b];  // bRoot 기준 b 위치

    root[bRoot] = aRoot;    // bRoot를 aRoot으로 재조정
    dist[bRoot] = newD - originD;   // 기존 bRoot에서 aRoot의 거리
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
        cin >> N >> M;
        if(N==0 && M==0) break;

        for(int i=1; i<=N; i++) {
            dist[i] = 0;    // root까지의 거리는 다 0으로
            root[i] = i;    // 자기 자신을 root로
        }

        for(int i=0; i<M; i++) {
            cin >> c >> a >> b;
            find(a);
            find(b);
            if(c == '!') {
                cin >> w;
                uni(a, b, w);
            } else if(c == '?') {
                // a, b가 같은 root면 dist[b]-dist[a]
                // 다른 root면 UNKNOWN
                if(root[a] == root[b]) cout << dist[b] - dist[a] << '\n';
                else cout << "UNKNOWN\n";
            }

        }
    }

    return 0;
}