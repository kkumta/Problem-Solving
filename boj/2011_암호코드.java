import java.io.*;
import java.util.Arrays;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static void main(String[] args) throws IOException {
        final int divide = 1000000;
        String input = br.readLine();
        int[] d = new int[input.length()];
        Arrays.fill(d, 0);
        
        if (input.charAt(0) == '0') {
            System.out.print(0);
            return;
        }
        
        for (int i = 1; i < input.length(); i++) {
            if (input.charAt(i) == '0' && (input.charAt(i - 1) == '0'
                || input.charAt(i - 1) >= '3')) {
                System.out.print(0);
                return;
            }
        }
        
        d[0] = 1;
        if (input.length() >= 2) {
            if (input.charAt(1) != '0') {
                d[1] += d[0];
            }
            if (input.charAt(0) == '1' || (input.charAt(0) == '2' && input.charAt(1) <= '6')) {
                d[1]++;
            }
            for (int i = 2; i < input.length(); i++) {
                if (input.charAt(i - 1) == '1' || (input.charAt(i - 1) == '2'
                    && input.charAt(i) <= '6')) {
                    d[i] += d[i - 2];
                }
                if (input.charAt(i) != '0') {
                    d[i] += d[i - 1];
                }
                d[i] %= divide;
            }
        }
        
        System.out.print(d[input.length() - 1]);
    }
}