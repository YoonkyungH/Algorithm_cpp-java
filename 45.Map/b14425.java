// 문자열 집합
// 중복을 허용하지 않는 map 사용
import java.util.*;

public class b14425 {
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        HashMap<String, Boolean> m = new HashMap<>();


        for(int i=0; i<N; i++) {
            String str = sc.next();

            m.put(str, true);
        }

        int ans = 0;
        for(int i=0; i<M; i++) {
            String str = sc.next();
            if(m.containsKey(str)) {
                ans++;
            }
        } 

        System.out.println(ans);
    }
}