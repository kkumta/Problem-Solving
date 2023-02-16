class Solution {
    
    int transformCnt, zeroCnt;
    
    public int[] solution(String s) {
        
        while (!s.equals("1")) {
            transformCnt++;
            
            // s에 있는 0의 개수 세기
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '0') {
                    zeroCnt++;
                }
            }
            
            // s의 모든 0 제거하기
            s = s.replaceAll("0", "");
            
            // s = s의 길이를 2진법으로 표현한 문자열
            s = toBinary(s.length());
        }
        
        return new int[]{transformCnt, zeroCnt};
    }
    
    private String toBinary(int length) {
        StringBuilder result = new StringBuilder();
        while (length != 0) {
            result.insert(0, length % 2);
            length /= 2;
        }
        
        return result.toString();
    }
}