#include <iostream>
#include <vector>
#include <queue>

// 뱀

using namespace std;

struct Pos {    // 위치 정보
    int y, x;
};

struct Dir {    // 방향 전환 정보
    int t;
    char d;
};

struct Joint {  // 뱀의 꺾인 부분
    int y, x, d;
};

int board[101][101]; // 2차원 보드 배열
int n, k, l;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

queue<Dir> direction;

// 입력
void input() {

    cin >> n >> k;  // 보드 크기, 사과 개수

    int y, x;
    while (k--) {   // 사과 위치
        cin >> y >> x;
        board[y][x] = 2;
    }

    cin >> l;       // 방향 전환 횟수

    int t;
    char d;
    while (l--) {   // 방향 전환 정보 (t초 후 d로 방향 전환)
        cin >> t >> d;

        Dir dir = {t, d};
        direction.push(dir);
        // direction.push({t, d});
    }
}

// 오른쪽 회전
int turnRight(int d) {
    d += 1;
    
    if(d >= 4) { return d-4; }
    // d = d >= 4 ? d - 4 : d;

    return d;
}

// 왼쪽 회전
int turnLeft(int d) {
    d -= 1;

    if(d < 0) { return d+4; }
    // d = d < 0 ? d + 4 : d;

    return d;
}

// 벽이나 자신에게 부딪힌 경우 true 반환
bool isEnd(int y, int x) {
    // 벽에 부딪힌 경우
    if (y > n || y <= 0 || x > n || x <= 0) { return true; }

    // 자신과 부딪힌 경우
    if (board[y][x] == 1) { return true; }

    return false;
}

// 결과 값 출력
void solve() {
    int t = 0;                        // 결과 값
    int head_dir = 2, tail_dir = 2;   // 초기 방향 오른쪽

    Pos head = {1, 1}, tail = {1, 1}; // 머리와 꼬리의 위치 정보 (y, x)
    queue<Joint> joint;               // 꺾인 부분 저장하는 큐

    board[1][1] = 1;                  // 왼쪽 위(1, 1) 시작

    while(1) {
        t++;

        // 머리의 이동
        head.y += dy[head_dir];
        head.x += dx[head_dir];

        // 부딪힌 경우 break;
        if(isEnd(head.y, head.x)) { break; }

        // 머리가 간 곳에 사과(2)가 없으면 꼬리 한 칸 땡기기
        if (board[head.y][head.x] != 2) {
            board[tail.y][tail.x] = 0;  // 꼬리 있던 칸을 비워줌

            tail.y += dy[tail_dir];
            tail.x += dx[tail_dir];
        }

        board[head.y][head.x] = 1;      // 머리가 이동 한 곳 1로 치환

        // 머리 방향 전환 (이동 지시가 남았고 해당 초가 되었다면)
        if (!direction.empty() && t == direction.front().t) {
            if (direction.front().d == 'L') // 왼쪽
                head_dir = turnLeft(head_dir);
            else                            // 오른쪽
                head_dir = turnRight(head_dir);

            Joint j = {head.y, head.x, head_dir};
            joint.push(j);                  // 꺾인 부분 저장 

            // joint.push({head.y, head.x, head_dir}); // 꺾인 부분 저장

            direction.pop();
        }

        // 꼬리가 뱀의 꺾인 부분에 도달하면 -> 꼬리 방향 전환
        if (!joint.empty() && tail.y == joint.front().y && tail.x == joint.front().x) {
            tail_dir = joint.front().d; // 방향

            joint.pop();
        }
    }

    cout << t << '\n';
}

int main() {
    ios::sync_with_stdio(0);

    input();
    solve();

    return 0;
}