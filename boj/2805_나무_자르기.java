import java.util.*;
import java.io.*;

public class Main {
    
    static int N;
    static long M;
    static long[] trees;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Long.parseLong(st.nextToken());
        
        trees = new long[N + 1];
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            trees[i] = Integer.parseInt(st.nextToken());
        }
        
        long start = 0, end = Arrays.stream(trees).max().getAsLong(), mid = 0;
        long sum = 0, ans = 0;
        while (start <= end) {
            mid = (start + end) / 2;
            sum = 0;
            for (long height : trees) {
                if (mid < height) {
                    sum += height - mid;
                }
            }
            if (sum == M) {
                ans = mid;
                break;
            } else if (sum > M) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        System.out.print(ans);
    }
}