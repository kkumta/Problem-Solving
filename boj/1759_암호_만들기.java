import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    static int l;
    static int c;
    static char[] arr;
    static char[] alphabet;
    static boolean[] isUsed;
    
    public static void main(String[] args) throws IOException {
        
        st = new StringTokenizer(br.readLine());
        l = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        
        isUsed = new boolean[c];
        arr = new char[l];
        alphabet = new char[c];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < c; i++) {
            alphabet[i] = st.nextToken().charAt(0);
        }
        Arrays.sort(alphabet);
        
        func(0);
        System.out.println(sb.toString());
    }
    
    private static void func(int k) {
        if (k == l) {
            if (hasVowelConsonant()) {
                for (int i = 0; i < l; i++) {
                    sb.append(arr[i]);
                }
                sb.append("\n");
            }
            return;
        }
        
        for (int i = 0; i < c; i++) {
            if (!isUsed[i] && (k == 0 || arr[k - 1] < alphabet[i])) {
                isUsed[i] = true;
                arr[k] = alphabet[i];
                func(k + 1);
                isUsed[i] = false;
            }
        }
    }
    
    // 모음 1개 이상과 자음 2개 이상을 포함하는 암호인지 검사한다
    private static boolean hasVowelConsonant() {
        
        int vowelCount = 0;
        int consonantCount = 0;
        for (int i = 0; i < l; i++) {
            if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
                ++vowelCount;
            } else {
                ++consonantCount;
            }
        }
        
        if (vowelCount > 0 && consonantCount > 1) {
            return true;
        }
        return false;
    }
}
