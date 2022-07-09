import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    public static void main(String[] args) throws IOException {
        
        // 입력
        int t = Integer.parseInt(br.readLine());
        
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        
        int m = Integer.parseInt(br.readLine());
        int[] b = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            b[i] = Integer.parseInt(st.nextToken());
        }
        
        // 배열 A의 부 배열의 합으로 만들 수 있는 모든 수 구하기
        List<Integer> sumA = makeAllSum(a);
    
        // 배열 B의 부 배열의 합으로 만들 수 있는 모든 수 구하기
        List<Integer> sumB = makeAllSum(b);
    
        long cnt = 0;
        for (Integer target : sumA) {
            int upperBoundIdx = upperBound(sumB, t - target);
            int lowerBoundIdx = lowerBound(sumB, t - target);
            
            if (upperBoundIdx - lowerBoundIdx > 0) {
                long size = upperBoundIdx - lowerBoundIdx;
                cnt += size;
            }
        }
        
        System.out.print(cnt);
    }
    
    // 배열로 만들 수 있는 모든 누적합을 구하는 메서드
    private static List<Integer> makeAllSum(int[] arr) {
        List<Integer> allSum = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            int sum = 0;
            for (int j = i; j < arr.length; j++) {
                sum += arr[j];
                allSum.add(sum);
            }
        }
        Collections.sort(allSum);
        return allSum;
    }
    
    private static int lowerBound(List<Integer> arr, int target) {
        int start = 0;
        int end = arr.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (arr.get(mid) >= target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
    
    private static int upperBound(List<Integer> arr, int target) {
        int start = 0;
        int end = arr.size();
        while (start < end) {
            int mid = (start + end) / 2;
            if (arr.get(mid) > target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
}