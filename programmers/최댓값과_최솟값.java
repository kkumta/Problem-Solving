import java.util.*;

class Solution {
    public String solution(String s) {
        String[] nums = s.split(" ");
        int[] numsToInt = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            numsToInt[i] = Integer.parseInt(nums[i]);
        }
        int min = Arrays.stream(numsToInt).min().getAsInt();
        int max = Arrays.stream(numsToInt).max().getAsInt();
        
        return min + " " + max;
    }
}