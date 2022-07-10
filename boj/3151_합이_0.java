import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    public static void main(String[] args) throws IOException {
        
        // 입력
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        
        long cnt = 0;
        
        // 오름차순 정렬
        Arrays.sort(a);
        
        // 학생 조합
        for (int first = 0; first < n - 2; first++) {
            for (int second = first + 1; second < n - 1; second++) {
                int target = 0 - (a[first] + a[second]);
                cnt += upperBound(a, second + 1, target) - lowerBound(a, second + 1, target);
            }
        }
        
        System.out.print(cnt);
    }
    
    // int 배열 lowerBound
    private static int lowerBound(int[] arr, int startIdx, int target) {
        int start = startIdx;
        int end = arr.length;
        while (start < end) {
            int mid = (start + end) / 2;
            if (arr[mid] >= target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
    
    // int 배열 upperBound
    private static int upperBound(int[] arr, int startIdx, int target) {
        int start = startIdx;
        int end = arr.length;
        while (start < end) {
            int mid = (start + end) / 2;
            if (arr[mid] > target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
}