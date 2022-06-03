import java.util.*;

public class s1206 {
    public static void main(String[] args) {
        int[] arr = new int[1000];
        Scanner sc = new Scanner(System.in);
        for(int i=1; i<=10; i++) {
            int tc = sc.nextInt();

            int ans = 0;
            for(int j=0; j<tc; j++) {
                int data = sc.nextInt();
                arr[j] = data;

            }

            for(int j=2; j<tc-2; j++) {
                if(arr[j] > Math.max(arr[j+1], arr[j+2]) && arr[j] > Math.max(arr[j-1], arr[j-2])) {
                    ans += arr[j] - Math.max(Math.max(arr[j + 1], arr[j + 2]), Math.max(arr[j - 1], arr[j - 2]));
                }
            }

            System.out.println("#"+i+" "+ans);
        }
    }

}