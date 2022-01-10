// 네트워크 연결
// MST (크루스칼 / 프림 알고리즘 사용)

// 해당 풀이는 크루스칼
// 크루스칼 알고리즘 공부하기 좋은 풀이

#include <iostream>
#include <queue>

using namespace std;

int parent[1001];

struct Data {
    int node1, node2, weight;
    Data() {};  // 기본 생성자
    Data(int node1, int node2, int weight) : node1(node1), node2(node2), weight(weight) {}; // 생성시 입력받은 것이 이 형태로 저장되는

    bool operator<(const Data d) const {    // priority_queue를 어떻게 정렬할 것인가
        // (operator"<"", return ">") 이 두개를 같은 방향으로 부호를 정해주면 큰 순서대로 반환
        return weight > d.weight;
    }
};

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
    parent[find(x)] = find(y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<Data> pq;

    int N, M;
    cin >> N;   // 컴퓨터의 수
    cin >> M;   // 연결할 수 있는 선의 수

    for(int i=0; i<=N; i++) parent[i] = i;  // 초기화

    for(int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push(Data(a, b, c));
    }

    int cnt = 0, ans = 0;

    while(1) {
        if(cnt == N-1) break;
        Data d = pq.top();
        pq.pop();

        if(find(d.node1) != find(d.node2)) {
            uni(d.node1, d.node2);
            cnt++;
            ans += d.weight;
        }
    }

    cout << ans << '\n';

    return 0;
}