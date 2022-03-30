class Solution {
    
    static StringBuilder sb = new StringBuilder();
    static int min = Integer.MAX_VALUE;
    
    static public int solution(String s) {
        int answer = 0;

        for (int unit = 1; unit <= s.length(); unit++) {
            func(unit, s);
            sb.delete(0, sb.length());
        }
        
        answer = min;
        return answer;
    }
    
    private static void func(int unit, String s) {
        for (int i = 0; i < s.length(); i = i + unit) {
            if (((s.length() - i) / unit == 0) && (((s.length() - i) % unit)
                != 0)) { // unit 단위로 문자열을 자르고 마지막에 남은 문자열을 그대로 붙여준다.
                sb.append(String.copyValueOf(s.toCharArray(), i, (s.length() - i) % unit));
                break;
            }
            
            int count = 1;
            String unitStr = String.copyValueOf(s.toCharArray(), i, unit);
            while (((i + unit * 2 - 1) < s.length()) && (unitStr.equals(
                String.copyValueOf(s.toCharArray(), i + unit, unit)))) {
                i = i + unit;
                count++;
            }
            
            if (count == 1) {
                sb.append(unitStr);
            } else {
                sb.append(count).append(unitStr);
            }
        }
        if (sb.length() < min) {
            min = sb.length();
        }
    }
}
