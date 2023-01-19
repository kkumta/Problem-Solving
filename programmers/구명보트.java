import java.util.*;

class Solution {
    
    public int solution(int[] people, int limit) {
        List<Integer> list = new ArrayList<>(people.length);
        for (int weight : people) {
            list.add(weight);
        }
        Collections.sort(list, Collections.reverseOrder());
        
        int ans = 0;
        for (int firstIdx = 0, lastIdx = people.length - 1; firstIdx <= lastIdx; ) {
            if (firstIdx != lastIdx && list.get(firstIdx) + list.get(lastIdx) <= limit) {
                lastIdx--;
            }
            firstIdx++;
            ans++;
        }
        
        return ans;
    }
}