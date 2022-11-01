import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static boolean[] alphabet = new boolean[26];
    static int n, k, ans;
    static String[] inputWords;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        if (k == 26) {
            System.out.print(n);
            return;
        }

        if (k < 5) {
            System.out.print(0);
            return;
        }

        inputWords = new String[n];
        for (int i = 0; i < n; i++) {
            inputWords[i] = br.readLine();
        }

        func(0, -1);
        System.out.print(ans);
    }

    private static void func(int alphaCnt, int lastIdx) {
        if (alphaCnt == k) { // race condition
            int wordCnt = 0;
            for (String word : inputWords) {
                boolean flag = true;
                for (int i = 0; i < word.length(); i++) {
                    if (!alphabet[word.charAt(i) - 'a']) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    wordCnt++;
                }
            }
            if (wordCnt > ans) {
                ans = wordCnt;
            }
            return;
        }

        for (int i = lastIdx + 1; i < 26; i++) {
            alphabet[i] = true;
            func(alphaCnt + 1, i);
            alphabet[i] = false;
        }
    }
}