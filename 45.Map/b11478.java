// 서로 다른 부분 문자열 개수

import java.util.*;

public class b11478 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        HashSet<String> s = new HashSet<String>();

        String str = sc.next();
        for(int i=0; i<str.length(); i++) {
            String tmp = "";

            for(int j=i; j<str.length(); j++) {
                tmp += str.substring(j, j+1);
                s.add(tmp);
            }
        }

        System.out.println(s.size());

    }
    
}
