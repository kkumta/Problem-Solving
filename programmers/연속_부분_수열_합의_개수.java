import java.util.*;

class Solution {
    public int solution(int[] elements) {
        HashSet<Integer> sums = new HashSet<>();
        
        // 부분 수열의 길이가 긴 순서대로 합 구하기
        for (int size = elements.length; size > 1; size--) {
            for (int startIdx = 0; startIdx < elements.length; startIdx++) {
                int sum = 0;
                for (int cnt = 0; cnt < size; cnt++) {
                    sum += elements[(startIdx + cnt) % elements.length];
                }
                if (!sums.contains(sum)) {
                    sums.add(sum);
                }
            }
        }
        
        // 부분 수열의 길이가 1인 경우의 합 구하기
        for (int num : elements) {
            if (!sums.contains(num)) {
                sums.add(num);
            }
        }

        return sums.size();
    }
}