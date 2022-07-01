import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    public static void main(String[] args) throws IOException {
        
        int n = Integer.parseInt(br.readLine());
        long[] cards = new long[n];
        for (int i = 0; i < n; i++) {
            cards[i] = Long.parseLong(br.readLine());
        }
        
        Arrays.sort(cards);
        
        long curNum = cards[0];
        int curCnt = 1;
        int maxCnt = 1;
        long maxCntNum = curNum;
        for (int i = 1; i < n; i++) {
            if (curNum == cards[i]) {
                ++curCnt;
            } else {
                curCnt = 1;
                curNum = cards[i];
            }
            
            if (curCnt > maxCnt) {
                maxCnt = curCnt;
                maxCntNum = curNum;
            }
        }
    
        System.out.println(maxCntNum);
    }
}
