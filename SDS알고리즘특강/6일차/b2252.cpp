// 줄 세우기
// 위상정렬 (참고하기 좋음)

#include <iostream>
#include <queue>
#include <vector>

/**
 * < 위상 정렬 구현 순서 >
 * 
 * 1. 도착 화살표 개수가 0인 노드를 큐에 넣기
 * 2. 큐에 저장된 노드를 꺼내 거기서 시작해 도착하는 노드의 화살표 개수를 하나씩 빼줌
 * 3. 그리고 화살표 수가 0이 된 노드를 또 큐에 저장
 * 4. 그리고 또 큐에 저장된 노드를 꺼내 방금 과정을 반복하기
 * 5. 모든 노드의 화살표 수가 0이 되면 종료
 */

using namespace std;

int N, M;
int input_degree[32001];    // 화살표 개수를 담을 배열
vector<int> adjust[32001];  // 누가 누굴 가리키고 있는지가 담겨있는 벡터
int result[32001];          // 출력할 배열(답)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> q;

    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        adjust[a].push_back(b); // 학생 a가 b의 앞에 서야한다 (a->b)
        input_degree[b]++;      // b의 화살표개수 1 더하기
    }

    for(int i=1; i<=N; i++) {
        if(!input_degree[i]) q.push(i);  // 화살표가 1개 이상이라면
    }

    for(int i=1; i<=N; i++) {
        if(q.empty()) break;            // 큐가 비었을 때 과정 끝
        
        int now = q.front();            // 큐에서 하나를 꺼내서
        q.pop();

        result[i] = now;                // 출력할 배열에 넣고

        for(int j=0; j<adjust[now].size(); j++) {   // 거기에 이어진 노드들을 검사하며
            int next = adjust[now][j];
            input_degree[next]--;                   // 해당 노드의 화살표를 하나 줄여주고
            
            if(input_degree[next] == 0) q.push(next);   // 혹시 줄여 0이 되었다면 큐에 넣어주기
        }
    }

    for(int i=1; i<=N; i++) {
        cout << result[i] << ' ';
    } cout << '\n';

    return 0;
}