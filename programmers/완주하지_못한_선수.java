class Solution {
    
    HashMap<String, Integer> completionMap = new HashMap<>();
    
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        for (int i = 0; i < completion.length; i++) {
            if (completionMap.containsKey(completion[i])) {
                completionMap.put(completion[i], completionMap.get(completion[i]) + 1);
            } else {
                completionMap.put(completion[i], 1);
            }
        }
        
        for (int i = 0; i < participant.length; i++) {
            if (completionMap.containsKey(participant[i])
                && (completionMap.get(participant[i]) > 0)) {
                completionMap.put(participant[i], completionMap.get(participant[i]) - 1);
            } else {
                answer = participant[i];
                break;
            }
        }
        
        return answer;
    }
}
