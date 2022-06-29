import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws IOException {
        
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        Long[] status = new Long[n];
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            status[i] = Long.parseLong(st.nextToken());
        }
        
        // 카드 정렬
        Arrays.sort(status);
        
        for (int i = 0; i < m; i++) {
            Long x = status[0];
            Long y = status[1];
            status[0] = x + y;
            status[1] = x + y;
            Arrays.sort(status);
        }
        
        Long sum = 0l;
        for (int i = 0; i < n; i++) {
            sum += status[i];
        }
        System.out.println(sum);
    }
}
