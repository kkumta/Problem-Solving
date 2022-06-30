import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args) throws IOException {
        
        String str = br.readLine();
        
        String[] numberArray = str.split("\\+|\\-");
        ArrayList<Integer> numbers = new ArrayList<>();
        for (int i = 0; i < numberArray.length; i++) {
            numbers.add(Integer.parseInt(numberArray[i]));
        }
        
        ArrayList<Character> operators = new ArrayList<>();
        for (int i = 0; i < str.length(); i++) {
            char operator = str.charAt(i);
            if (operator == '+' || operator == '-') {
                operators.add(operator);
            }
        }
        
        for (int i = 0; i < operators.size(); ) {
            if (operators.get(i) == '+') {
                int plusNum = numbers.get(i) + numbers.get(i + 1);
                numbers.set(i, plusNum);
                numbers.remove(i + 1);
                operators.remove(i);
            } else {
                ++i;
            }
        }
        
        for (int i = 0; i < operators.size();) {
            int minusNum = numbers.get(i) - numbers.get(i + 1);
            numbers.set(i, minusNum);
            numbers.remove(i + 1);
            operators.remove(i);
        }
        
        System.out.println(numbers.get(0));
    }
}
