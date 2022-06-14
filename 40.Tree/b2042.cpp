// 세그먼트 트리
// 구간 합 구하기

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M, K;
vector<long long> tree;
vector<long long> a;

void init(int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
    }
    else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);

        tree[node] = tree[node*2] + tree[node*2 + 1];
    }
}


void update(int node, int start, int end, int idx, long long val) {
    if(idx < start || idx > end) return;

    if(start == end) {
        a[idx] = val;
        tree[node] = val;

        return;
    }

    update(node*2, start, (start+end)/2, idx, val);
    update(node*2 + 1, (start+end)/2 + 1, end, idx, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}


long long query(int node, int start, int end, int left, int right) {
    if(left > end || right < start) {   // 구할 수 있는 범위가 아님
        return 0;
    }

    if(left <= start && end <= right) { // 범위가 일치한다면 바로 반환
        return tree[node]; 
    }

    long long lsum = query(node*2, start, (start+end)/2, left, right);
    long long rsum = query(node*2 + 1, (start+end)/2 + 1, end, left, right);

    return lsum + rsum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    a.resize(N);
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h+1));
    tree.resize(tree_size);

    for(int i=0; i<N; i++) {
        cin >> a[i];
    }

    init(1, 0, N-1);

    for(int i=0; i<M+K; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        if(a == 1) {    // b번째 수를 c로 변경
            update(1, 0, N-1, b-1, c);
        } else if(a == 2) {  // b~c 구간 합
            cout << query(1, 0, N-1, b-1, c-1) << '\n';
        }
    }

    return 0;
}