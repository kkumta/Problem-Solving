class Solution {
    
    public int solution(String myString) {
        int ans = 0;
        for (int i = 0; i < myString.length(); ) {
            String tmp = "";
            while (i < myString.length()) {
                char c = myString.charAt(i);
                i++;
                if (c >= '0' && c <= '9') {
                    tmp += c;
                } else {
                    break;
                }
            }
            if (!tmp.isEmpty()) {
                ans += Integer.parseInt(tmp);
            }
        }
        
        return ans;
    }
}