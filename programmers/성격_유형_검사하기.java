import java.util.*;

class Solution {
    
    public String solution(String[] survey, int[] choices) {
        
        HashMap<Character, Integer> types = new HashMap();
        types.put('R', 0);
        types.put('T', 0);
        types.put('C', 0);
        types.put('F', 0);
        types.put('J', 0);
        types.put('M', 0);
        types.put('A', 0);
        types.put('N', 0);
        
        for (int i = 0; i < survey.length; i++) { // 수치 증가
            if (choices[i] <= 3) { // 3 이하의 수인 경우 첫번째 알파벳의 수치 증가
                types.put(survey[i].charAt(0),
                          types.get(survey[i].charAt(0)) + (4 - choices[i]));
            } else if (choices[i] >= 5) { // 4 이상의 수인 경우 첫번째 알파벳의 수치 증가
                types.put(survey[i].charAt(1), types.get(survey[i].charAt(1)) + choices[i] - 4);
            }
        }
        
        // 유형 판별
        return discriminateType(types);
    }
    
    private static String discriminateType(HashMap<Character, Integer> type) {
        
        String ans = "";
        
        if (type.get('T') > type.get('R')) {
            ans += 'T';
        } else {
            ans += 'R';
        }
        if (type.get('F') > type.get('C')) {
            ans += 'F';
        } else {
            ans += 'C';
        }
        if (type.get('M') > type.get('J')) {
            ans += 'M';
        } else {
            ans += 'J';
        }
        if (type.get('N') > type.get('A')) {
            ans += 'N';
        } else {
            ans += 'A';
        }
        
        return ans;
    }
}