import java.util.*;

class Solution {
    
    HashMap<String, Integer> hashMap = new HashMap<>();
    
    public int solution(String[][] clothes) {
        
        int answer = 1;
        
        for (String[] clothe : clothes) {
            if (hashMap.containsKey(clothe[1])) {
                hashMap.put(clothe[1], hashMap.get(clothe[1]) + 1);
            } else {
                hashMap.put(clothe[1], 1);
            }
        }
        
        for (String key : hashMap.keySet()) {
            answer *= (hashMap.get(key) + 1);
        }
        
        --answer;
        
        return answer;
    }
}
