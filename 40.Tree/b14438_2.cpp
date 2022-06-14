// 수열과 쿼리 17
// 세그먼트 트리

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
vector<int> a;
vector<int> tree;

void init(int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
    } else {
        init(node*2, start, (start+end)/2);
        init(node*2+1, (start+end)/2+1, end);

        // tree[node] = tree[node*2] + tree[node*2+1];
        tree[node] = min(tree[node*2], tree[node*2+1]);
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
    update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val);

    // tree[node] = tree[node*2] + tree[node*2+1];
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int start, int end, int left, int right) {  // 구간 내 최솟값 구하기
    if(left > end || right < start) {
        return -1;
    }
    
    if(left <= start && end <= right) {
        return tree[node];
    }

    int lmin = query(node*2, start, (start+end)/2, left, right);
    int rmin = query(node*2+1, (start+end)/2+1, end, left, right);

    if(lmin == -1) return rmin;
    else if(rmin == -1) return lmin;
    else return min(lmin, rmin);
    
 }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    a.resize(N);
    
    int h = (int)ceil(log2(N));
    int treeSize = (1 << (h+1));
    tree.resize(treeSize);
    
    for(int i=0; i<N; i++) {
        cin >> a[i];
    }
    init(1, 0, N-1);

    cin >> M;
    while(M--) {
        int q, i, j;
        cin >> q >> i >> j;

        if(q == 1) {    // i번째 수를 j로 바꿈
            update(1, 0, N-1, i-1, j);
        } else if(q == 2) { // i~j 범위 내 최솟값 출력
            cout << query(1, 0, N-1, i-1, j-1) << '\n';
        }
    }
    

    return 0;
}