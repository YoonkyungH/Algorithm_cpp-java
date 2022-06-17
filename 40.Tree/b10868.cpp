// 최솟값
// 세그먼트 트리

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 9876543210;

int N, M;
vector<long long> a;
vector<long long> tree;

void init(int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);

        tree[node] = min(tree[node*2], tree[node*2+1]);
    }
}

long long query(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return MAX;

    if(left <= start && right >= end) {
        return tree[node];
    }

    long long l = query(node*2, start, (start+end)/2, left, right);
    long long r = query(node*2+1, (start+end)/2+1, end, left, right);

    return min(l, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    a.resize(N);

    int h = (int)ceil(log2(N));
    int treeSize = (1 << (h+1));
    tree.resize(treeSize);

    for(int i=0; i<N; i++) {
        cin >> a[i];
    }

    init(1, 0, N-1);

    for(int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;

        cout << query(1, 0, N-1, a-1, b-1) << '\n';
    }

    return 0;
}