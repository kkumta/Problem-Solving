import java.util.*;

class Solution {
    
    public int[] solution(int n, long left, long right) {
        
        int[] arr = new int[(int) (right / n - left / n + 1) * n];
        int idx = 0;
        
        for (int row = (int) (left / n); row <= right / n; row++) {
            for (int col = 0; col < n; col++) {
                if (col <= row) { // col이 row보다 작거나 같은 경우 해당 행의 숫자가 들어간다
                    arr[idx++] = row + 1;
                } else { // col이 row보다 클 경우 해당 열 + 1인 숫자가 들어간다
                    arr[idx++] = col + 1;
                }
            }
        }
        
        int[] ans = Arrays.copyOfRange(arr, (int) (left % n),
                                       arr.length - (int) (n - right % n) + 1);
        
        return ans;
    }
}