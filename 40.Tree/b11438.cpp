// 수열과 쿼리 17
// 세그먼트 트리 top-down(재귀 호출로 메모리가 최대 4n만큼 필요)

#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000001  // 987654321이나 9876543210으로 하면 안됨

using namespace std;

int N, M;
int n;

vector<int> arr;
int a, b, c;
vector<int> v;  // 구간의 최솟값을 저장하는 트리

int init(int node, int start, int end) {
    // 하나짜리 구간에서는 그냥 그 값을 반환
    if(start == end)  return v[node] = arr[start];

    // 이분하여 하위 트리 값 중 최솟값을 찾아 반환
    int mid = (start + end) / 2;
    int leftMin = init(node*2, start, mid);
    int rightMin = init(node*2+1, mid+1, end);

    if(leftMin < rightMin) {
        return v[node] = leftMin;
    } else {
        return v[node] = rightMin;
    }
}

// 1번 노드부터 하위 노드까지 최솟값을 노드에 업데이트
int update(int node, int start, int end, int index) {
    if(index < start || index > end) return v[node];

    if(start == end) return v[node] = arr[index];

    int mid = (start + end) / 2;

    int leftMin = update(node*2, start, mid, index);
    int rightMin = update(node*2+1, mid+1, end, index);

    return v[node] = min(leftMin, rightMin);
}

int findMin(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return INF;
    if(left <= start && right >= end) return v[node];

    // 두 개 이상의 노드에 대해서는 더 작은 값을 반환받을 수 있도록
    int mid = (start + end) / 2;
    int leftMin = findMin(node*2, start, mid, left, right);
    int rightMin = findMin(node*2+1, mid+1, end, left, right);

    return min(leftMin, rightMin);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    arr.resize(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    v.resize(N*4);
    init(1, 0, N-1);

    cin >> M;
    for(int i=0; i<M; i++) {
        cin >> a >> b >> c;
        if(a == 1) {
            arr[b-1] = c;
            update(1, 0, N-1, b-1);
        } else if(a == 2) {
            cout << findMin(1, 0, N-1, b-1, c-1) << '\n';
        }
    }

    return 0;
}
