// 세그먼트 트리 뼈대

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 9876543210

using namespace std;

int N, M;
int n;

vector<long long> arr;
int a, b, c;
vector<long long> v;

long long init(vector<long long> &arr, vector<long long> &v, int node, int start, int end) {
    if(start == end) {
        return v[node] = arr[start];
    }

    int mid = (start + end) / 2;

    return v[node] = init(arr, v, node*2, start, mid) + init(arr, v, node*2+1, mid+1, end);
}

void update(vector<long long> &v, int node, int start, int end, int index, long long diff) {    // diff 만큼 증가
    if(index < start || index > end) return;

    v[node] = v[node] + diff;

    // 리프노드가 아닌 경우 자식도 변경
    if(start != end) {
        int mid = (start + end) / 2;
        update(v, node*2, start, mid, index, diff);
        update(v, node*2+1, mid+1, end, index, diff);
    }
}

// 노드 담당 구간: [start, end]
// 합이 필요한 구간: [left, right]
long long sum(vector<long long> &v, int node, int start, int end, int left, int right) {
    // 교집합이 공집합인 경우
    if(left > end || right < start) return INF;

    // 교집합이 [start, end]인 경우
    if(left <= start && end <= right) return v[node];

    // 교집합이 [left, right]인 경우
    // + [left, right]와 [start, end]가 겹쳐진 경우
    int mid = (start + end) / 2;
    return sum(v, node*2, start, mid, left, right) + sum(v, node*2+1, mid+1, end, left, right);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> n;

        arr.push_back(n);
    }

    // 트리 초기화
    init(arr, v, 1, 0, N-1);
    update(v, 1, 0, N-1, b, c-v[b]);
    sum(v, N, 1, N-1, b, c);

    return 0;
}