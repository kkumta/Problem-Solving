import static java.lang.Integer.*;

import java.io.*;
import java.util.*;

public class Main {
    
    static public class Pair implements Comparable<Pair> {
        
        int a, b;
        
        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
        
        @Override
        public int compareTo(Pair o) {
            return this.a - o.a;
        }
    }
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[] d;
    static int n;
    static Pair[] powerPole;
    
    
    public static void main(String[] args) throws IOException {
        
        // 입력
        n = parseInt(br.readLine());
        d = new int[n];
        powerPole = new Pair[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            powerPole[i] = new Pair(parseInt(st.nextToken()), parseInt(st.nextToken()));
        }
        
        Arrays.sort(powerPole); // 전봇대 A를 기준으로 오름차순 정렬
        
        // 전봇대 B를 기준으로 가장 긴 부분 증가 수열의 길이 구하기
        Arrays.fill(d, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (powerPole[i].b > powerPole[j].b && d[i] < d[j] + 1) {
                    d[i] = d[j] + 1;
                }
            }
        }
        
        System.out.print(n - Arrays.stream(d).max().getAsInt());
    }
}