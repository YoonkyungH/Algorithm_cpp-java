// 세그먼트 트리
// 수열과 쿼리 17

import java.util.*;
public class b14438_2 {
    static void init(int[] a, int[] tree, int node, int start, int end) {
        if(start == end) {
            tree[node] = a[start];
        } else {
            init(a, tree, node*2, start, (start+end)/2);
            init(a, tree, node*2+1, (start+end)/2+1, end);

            tree[node] = Math.min(tree[node*2], tree[node*2+1]);
        }
    }

    static void update(int[] a, int[] tree, int node, int start, int end, int idx, int val) {
        if(idx < start || idx > end) {
            return;
        }

        if(start == end) {
            a[idx] = val;
            tree[node] = val;

            return;
        }

        update(a, tree, node*2, start, (start+end)/2, idx, val);
        update(a, tree, node*2+1, (start+end)/2 + 1, end, idx, val);

        tree[node] = Math.min(tree[node*2], tree[node*2+1]);
    }

    static int query(int[] tree, int node, int start, int end, int left, int right) {
        if(left > end || right < start) return -1;

        if(left <= start && end <= right) {
            return tree[node];
        }

        int lmin = query(tree, node*2, start, (start+end)/2, left, right);
        int rmin = query(tree, node*2+1, (start+end)/2+1, end, left, right);

        if(lmin == -1) return rmin;
        else if(rmin == -1) return lmin;
        else return Math.min(lmin, rmin);
    }

    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] a = new int[N];

        for(int i=0; i<N; i++) {
            a[i] = sc.nextInt();
        }

        int h = (int)Math.ceil(Math.log(N) / Math.log(2));
        int treeSize = (1 << (h+1));

        int[] tree = new int[treeSize];
        init(a, tree, 1, 0, N-1);

        int M = sc.nextInt();
        for(int k=0; k<M; k++) {
            int q = sc.nextInt();
            int i = sc.nextInt();
            int j = sc.nextInt();

            if(q == 1) {    // i번째 수를 j로 업데이트
                update(a, tree, 1, 0, N-1, i-1, j);
            } else if(q == 2) {
                System.out.println(query(tree, 1, 0, N-1, i-1, j-1));
            }
        }
    }
}
