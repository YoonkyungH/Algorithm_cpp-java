// 구간 곱 구하기
// 세그먼트 트리

import java.util.*;

public class b11505 {
    static void init(int[] a, long[] tree, int node, int start, int end) {
        if(start == end) {
            tree[node] = a[start];
        } else {
            init(a, tree, node*2, start, (start + end) / 2);
            init(a, tree, node*2+1, (start+end)/2 + 1, end);

            tree[node] = (tree[node*2] * tree[node*2+1]) % 1000000007;
        }
    }

    static void update(int[] a, long[] tree, int node, int start, int end, int idx, int val) {
        if(start > idx || end < idx) {
            return;
        }

        if(start == end) {
            a[idx] = val;
            tree[node] = val;

            return;
        }

        update(a, tree, node*2, start, (start+end)/2, idx, val);
        update(a, tree, node*2+1, (start+end)/2+1, end, idx, val);

        tree[node] = (tree[node*2] * tree[node*2+1]) % 1000000007;
    }

    static long query(long[] tree, int node, int start, int end, int left, int right) {
        if(left > end || right < start) {
            return 1;
        }

        if(left <= start && end <= right) {
            return tree[node];
        }

        long lsum = query(tree, node*2, start, (start+end)/2, left, right);
        long rsum = query(tree, node*2+1, (start+end)/2+1, end, left, right);

        return (lsum * rsum) % 1000000007;
    }
    
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        int K = sc.nextInt();

        int[] a = new int[N];

        for(int i=0; i<N; i++) {
            a[i] = sc.nextInt();
        }

        int h = (int)Math.ceil(Math.log(N) / Math.log(2));
        int treeSize = (1 << (h+1));

        long[] tree = new long[treeSize];
        init(a, tree, 1, 0, N-1);

        for(int i=0; i<M+K; i++) {
            int q = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();

            if(q == 1) {    // update
                update(a, tree, 1, 0, N-1, b-1, c);
            } else if(q == 2) { // print
                System.out.println(query(tree, 1, 0, N-1, b-1, c-1));
            }
        }

    }
}
