import java.util.*;

public class s1244 {
    static int ch, res;
    static char[] arr;
    static String str;

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int i=1; i<=t; i++) {
            res = 0;
            str = sc.next();
            arr = str.toCharArray();
            
            ch = sc.nextInt();

            dfs(0, 0);

            System.out.println("#" + i + " " + res);
        }

    }

    private static void dfs(int n, int idx) {
        if(n == ch) {
            res = Math.max(res, Integer.parseInt(str));
            return;
        }

        for(int i=idx; i<str.length(); i++) {
            for(int j=i+1; j<str.length(); j++) {
                if(str.charAt(i) <= str.charAt(j)) {
                    swap(i, j);
                    dfs(n+1, i);
                    swap(j, i);
                }
            }
        }
    }

    private static void swap(int i, int j) {
        StringBuilder chNum = new StringBuilder(str);

        char A = str.charAt(i);
        char B = str.charAt(j);

        chNum.setCharAt(i, B);
        chNum.setCharAt(j, A);
        str = chNum.toString();
    }
}
