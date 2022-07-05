import static java.util.Arrays.sort;

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
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(br.readLine());
        }
        
        // a 정렬하기
        sort(a);
        
        // 투 포인터를 통해 계산하기
        int min = Integer.MAX_VALUE;
        int start = 0;
        int end = 0;
        for (; start < n && end < n; ) { // start, end 둘 다 0~n-1 인덱스에 속해야 한다
            int difference = a[end] - a[start]; // start, end의 차이
            if (difference >= m) { // difference가 m보다 크거나 같으면 start를 오른쪽으로 한 칸 옮긴다
                if (difference < min) {
                    min = difference;
                    if (min == m) {
                        break;
                    }
                }
                ++start;
            } else { // difference가 m보다 작으면 end를 오른쪽으로 한 칸 옮긴다
                ++end;
            }
        }
        
        System.out.print(min);
    }
}
