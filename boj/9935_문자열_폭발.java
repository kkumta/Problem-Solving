import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    
    static Stack<Character> mainStack = new Stack<>();
    static Stack<Character> tempStack = new Stack<>();
    static String str, explosion;
    
    public static void main(String[] args) throws IOException {
        
        str = br.readLine();
        explosion = br.readLine();
        
        for (int i = 0; i < explosion.length() - 1;
            i++) { // mainStack에 explosion의 길이 - 1 만큼의 문자열을 넣어준다
            mainStack.push(str.charAt(i));
        }
        
        for (int i = explosion.length() - 1; i < str.length();
            i++) { // mainStack에 str의 원소를 하나씩 넣어주면서 explosion과 비교한다.
            boolean isExplosion = true;
            mainStack.push(str.charAt(i));
            for (int j = 1; j <= explosion.length(); j++) {
                if (mainStack.peek() != explosion.charAt(explosion.length() - j)) {
                    isExplosion = false;
                    while (!tempStack.empty()) {
                        mainStack.push(tempStack.pop());
                    }
                    break;
                }
                tempStack.push(mainStack.pop());
            }
            if (isExplosion) {
                tempStack.clear();
            }
        }
        
        if (mainStack.empty()) {
            sb.append("FRULA");
        } else {
            for (Character c : mainStack) {
                sb.append(c);
            }
        }
        
        System.out.print(sb.toString());
    }
}