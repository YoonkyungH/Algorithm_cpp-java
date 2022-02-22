// 세그먼트 트리 뼈대 코드 (top-down)
// 동빈나님의 블로그 참고 (https://m.blog.naver.com/ndb796/221282210534)

#include <iostream>
#include <vector>

using namespace std;

int a[] = {};
int tree[4*12]; // 총 a의 원소가 12개라고 할 때 4를 곱하면 모든 범위를 커버할 수 있음
// (개수에 대해 2의 제곱 형태의 길이를 가지기 때문)

int init(int start, int end, int node) {
    if(start == end) {
        return tree[node] = a[start];
    }

    int mid = (start + end) / 2;
    // 재귀적으로 두 부분으로 나눈 뒤 그 합을 자기 자신으로
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

// start,end: 트리의 시작과 끝
// left, right: 구해야하는 범위
int sum(int start, int end, int node, int left, int right) {
    // 범위 밖
    if(left > end || right < start) return 0;
    
    // 범위 안
    if(left <= start && end <= right) {
        return tree[node];
    }

    // 그렇지 않다면 두 부분으로 나눠 합 구하기
    int mid = (start+end) / 2;
    return sum(start, mid, node*2, left, right)  + sum(mid+1, end, node*2+1, left, right);
}

// index: 구간 합을 수정해야하는 노드
void update(int start, int end, int node, int index, int dif) {
    // 범위 밖
    if(index < start || index > end) return;

    // 범위 안에 있으면 트리를 내려가며 다른 원소도 갱신
    tree[node] += dif;
    if(start == end) return;

    int mid = (start + end) / 2;
    update(start, mid, node*2, index, dif);
    update(mid+1, end, node*2+1, index, dif);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init(0, 12-1, 1);   // 구간 합 트리 생성 (원소가 12개일 경우)

    sum(0, 12-1, 1, 2, 10); // 2~10까지의 구간합

    update(0, 12-1, 1, 5, -3);  // 인덱스 5의 원소를 -3하기

    return 0;
}