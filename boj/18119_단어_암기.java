import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    static int n, m, max = 0B11111111111111111111111111, alphabet = 0B11111111111111111111111111;
    static int[] words;
    
    public static void main(String[] args) throws IOException {
        
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        
        words = new int[n];
        for (int i = 0; i < n; i++) {
            String word = br.readLine();
            for (int j = 0; j < word.length(); j++) {
                int bitShift = 1;
                for (int k = 0; k < word.charAt(j) - 'a'; k++) {
                    bitShift <<= 1;
                }
                words[i] |= bitShift;
            }
        }
        
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int command = Integer.parseInt(st.nextToken());
            char c = st.nextToken().charAt(0);
            int bitShift = 1;
            for (int k = 0; k < c - 'a'; k++) {
                bitShift <<= 1;
            }
            
            if (command == 1) {
                alphabet &= (bitShift ^ max);
            } else {
                alphabet |= bitShift;
            }
            
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if ((words[j] & alphabet) == words[j]) {
                    cnt++;
                }
            }
            sb.append(cnt).append("\n");
        }
        
        System.out.print(sb.toString());
    }
}