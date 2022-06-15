// 구간 곱 구하기
// 세그먼트 트리

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, K;
vector<int> a;
vector<long long> tree;

void init(int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2 + 1, end);

        tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
    }
}

void update(int node, int start, int end, int idx, int val) {
    if(idx < start || idx > end) {
        return;
    }

    if(start == end) {
        a[idx] = val;
        tree[node] = val;

        return;
    }

    update(node*2, start, (start+end)/2, idx, val);
    update(node*2+1, (start+end)/2+1, end, idx, val);

    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
}

long long query(int node, int start, int end, int left, int right) {
    if(left > end || right < start) {
        return 1;
    }

    if(left <= start && end <= right) {
        return tree[node];
    }

    long long lsum = query(node*2, start, (start+end)/2, left, right);
    long long rsum = query(node*2+1, (start+end)/2+1, end, left, right);

    return (lsum * rsum) % 1000000007;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    a.resize(N);
    int h = (int)ceil(log2(N));
    int treeSize = (1 << (h+1));
    tree.resize(treeSize);

    for(int i=0; i<N; i++) {
        cin >> a[i];
    }

    init(1, 0, N-1);

    for(int i=0; i<M+K; i++) {
        int q, b, c;
        cin >> q >> b >> c;

        if(q == 1) {    // b번째 수를 c로 변경
            update(1, 0, N-1, b-1, c);
        } else if(q == 2) { // b~c까지의 곱을 구하여 출력 
            cout << query(1, 0, N-1, b-1, c-1) << '\n';
        }
    }

    return 0;
}