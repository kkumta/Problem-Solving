import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    
    public static void main(String[] args) throws IOException {
        
        // 입력
        int n = Integer.parseInt(br.readLine());
        
        // n보다 작은 모든 소수 구하기
        List<Integer> primeList = new LinkedList<>();
        
        for (int i = 2; i <= n; i++) {
            boolean isPrime = true;
            for (int j = 2; j <= Math.sqrt(i); j++) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                primeList.add(i);
            }
        }
        
        Integer[] arr = new Integer[primeList.size()];
        primeList.toArray(arr);
        
        // 투 포인터를 사용하여 n을 연속된 소수의 합으로 나타낼 수 있는 모든 경우의 수 구하기
        int start = 0;
        int end = 0;
        int sum = 0;
        int cnt = 0;
        for (; start < arr.length && end < arr.length; ) {
            int curSum = sum + arr[end];
            if (curSum >= n) {
                if (curSum == n) {
                    ++cnt;
                }
                ++start;
                end = start;
                sum = 0;
            } else {
                sum += arr[end];
                ++end;
            }
        }
        System.out.print(cnt);
    }
}
