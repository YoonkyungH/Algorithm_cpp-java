// 수열과 쿼리 16
// 세그먼트 트리

#include<iostream>
#include<algorithm>
#include<vector>
#include <cmath>

using namespace std;
const int MAX = 100000;
int a[MAX + 1];
int tree[MAX * 4 + 1];

// int N, M;
// vector<int> tree;
// vector<int> a;

int minIndex(int x, int y) 
{
	if (x == -1) return y;
	if (y == -1) return x;
	if (a[x] == a[y]) return x < y ? x : y;
	else return a[x] <= a[y] ? x : y;
}

int init(int start, int end, int node)
{
	if (start == end) return tree[node] = start;
	int mid = (start + end) / 2;

	return tree[node] = minIndex(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

int update(int start, int end, int node, int index)
{	
	if (start > index || end < index) return tree[node];
	if (start == end) return tree[node];

	int mid = (start + end) / 2;
	return tree[node] = minIndex(update(start, mid, node * 2, index), update(mid + 1, end, node * 2 + 1, index));
}

int query(int start, int end, int node, int left, int right)
{
	if (start > right || end < left) return -1;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return minIndex(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;		
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;

    // a.resize(n);

    // int h = (int)ceil(log2(n));
    // int treeSize = (1 << (h+1));
    // tree.resize(treeSize);

    init(1, n, 1);

	while (m--)
	{
		int q, index, v, left, right;
		cin >> q;
		if (q == 1)
		{
			cin >> index >> v;
			a[index] = v;
			update(1, n, 1, index);
		}
		if (q == 2)
		{
			cin >> left >> right;
			cout << query(1, n, 1, left, right) << '\n';
		}
	}

}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// using namespace std;

// #define INF 987654321

// int N, M;
// vector<int> tree;
// // vector<int> idxTree;
// vector<int> a;

// int minIdx(int q, int w) {
//     if(q == -1) return w;
//     if(w == -1) return q;

//     // if(a[q] == a[w]) return q<w ? q:w;
//     // else return a[q] <= a[w] ? q:w;
//     return a[q] <= a[w] ? q : w;
// }

// int init(int node, int start, int end) {
//     if(start == end) {
//         // tree[node] = node;
//         return tree[node] = start;
//     } else {
//         return tree[node] = minIdx(init(node * 2, start, (start + end) / 2), init(node * 2 + 1, (start + end) / 2 + 1, end));

//     }
// }

// int update(int node, int start, int end, int idx, int val) {
//     if(idx < start || idx > end) return tree[node];

//     if(start == end) {
//         return tree[node];

//         // a[idx] = val;
//         // tree[node] = val;
//         // idxTree[node] = idx;

//     }

//     return tree[node] = minIdx(update(node * 2, start, (start + end) / 2, idx, val), update(node * 2 + 1, (start + end) / 2 + 1, end, idx, val));

// }

// int query(int node, int start, int end, int left, int right) {
//     if(left > end || right < start) {
//         return -1;
//     }

//     if(left <= start && end <= right) {
//         return tree[node];
//     }

//     return minIdx(query(node * 2, start, (start + end) / 2, left, right), query(node * 2 + 1, (start + end) / 2 + 1, end, left, start));
//     // int l = query(node*2, start, (start+end)/2, left, right);
//     // int r = query(node*2+1, (start+end)/2+1, end, left, start);

//     // if( l > r && r != -1) {
//     //     return node*2+1;
//     // } else {
//     //     return node*2;
//     // }

// }

// int main (){
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> N;

//     a.resize(N);

//     int h = (int)ceil(log2(N));
//     int treeSize = (1 << (h+1));
//     tree.resize(treeSize);
//     // idxTree.resize(treeSize);

//     for(int i=1; i<=N; i++) {
//         cin >> a[i];
//     }

//     init(1, 1, N);

//     cin >> M;
//     for(int i=0; i<M; i++) {
//         int q, b, c;
//         cin >> q >> b >> c;

//         if(q == 1) {
//             a[b] = c;
//             update(1, 1, N, b, c);
//         } else if(q == 2) {
//             cout << query(1, 1, N, b, c) << '\n';
//         }
//     }

//     return 0;
// }