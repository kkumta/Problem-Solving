import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {

        // 입력
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] a = new int[n];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        // 투 포인터 활용
        int cnt = 0;
        int sum = 0;
        for(int start = 0, end = 0; start < n && end < n;) {
            int curSum = sum + a[end];
            if(curSum >= m) {
                if(curSum == m) {
                    ++cnt;
                }
                sum = 0;
                ++start;
                end = start;
            } else {
                sum = curSum;
                ++end;
            }
        }
        System.out.print(cnt);
    }
}
