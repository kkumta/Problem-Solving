import java.util.*;

class Solution {
    public String solution(String s) {
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < s.length(); i++) {
            // 단어의 첫 문자일 경우
            if (i == 0 || s.charAt(i - 1) == ' ') {
                // 알파벳 소문자일 때 -> 대문자로 변경
                if (s.charAt(i) >= 'a') {
                    char tmp = Character.toUpperCase(s.charAt(i));
                    sb.append(tmp);
                } else {
                    sb.append(s.charAt(i));
                }
            }
            
            // 공백일 경우
            else if (s.charAt(i) == ' ') {
                sb.append(s.charAt(i));
            }
            
            // 단어의 첫 문자가 아닐 경우
            else {
                // 알파벳 대문자일 때 -> 소문자로 변경
                if (s.charAt(i) < 'a') {
                    char tmp = Character.toLowerCase(s.charAt(i));
                    sb.append(tmp);
                } else {
                    sb.append(s.charAt(i));
                }
            }
        }
                
        return sb.toString();
    }
}