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
        int s = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        
        // 투포인터를 통해 합이 s 이상인 연속되는 가장 짧은 부분 배열의 길이 구하기
        int sum = 0;
        int length = 0;
        int minLength = Integer.MAX_VALUE;
        for (int start = 0, end = 0; start < n && end < n; ) {
            if (sum + arr[end] >= s) {
                if (length + 1 < minLength) {
                    minLength = length + 1;
                }
                ++start;
                end = start;
                sum = 0;
                length = 0;
            } else {
                sum += arr[end];
                ++length;
                ++end;
            }
        }
        
        if (minLength == Integer.MAX_VALUE) {
            minLength = 0;
        }
        
        System.out.print(minLength);
    }
}
