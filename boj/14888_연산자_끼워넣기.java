import java.io.*;
import java.util.StringTokenizer;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    static int n, max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
    static int[] a; // 수
    static int[] inputOperator, myOperator; // 입력 연산자, 실제 사용되는 연산자. 0: +, 1: -, 2: *, 3: /
    static boolean[] isUsed; // 입력된 연산자가 이미 사용됐는지 구분
    
    public static void main(String[] args) throws IOException {
        
        n = Integer.parseInt(br.readLine());
        a = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        inputOperator = new int[n - 1];
        isUsed = new boolean[n - 1];
        st = new StringTokenizer(br.readLine());
        int idx = 0;
        for (int i = 0; i < 4; i++) {
            int cnt = Integer.parseInt(st.nextToken());
            for (int j = 0; j < cnt; j++, idx++) {
                inputOperator[idx] = i;
            }
        }
        myOperator = new int[n - 1];
        
        func(0);
        sb.append(max).append("\n").append(min);
        System.out.print(sb.toString());
    }
    
    private static void func(int k) {
        if (k == n - 1) { // race condition
            int result = a[0];
            for (int i = 0; i < n - 1; i++) {
                if (myOperator[i] == 0) {
                    result += a[i + 1];
                } else if (myOperator[i] == 1) {
                    result -= a[i + 1];
                } else if (myOperator[i] == 2) {
                    result *= a[i + 1];
                } else {
                    result /= a[i + 1];
                }
            }
            if (result > max) {
                max = result;
            }
            if (result < min) {
                min = result;
            }
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (!isUsed[i]) {
                isUsed[i] = true;
                myOperator[k] = inputOperator[i];
                func(k + 1);
                isUsed[i] = false;
            }
        }
    }
}