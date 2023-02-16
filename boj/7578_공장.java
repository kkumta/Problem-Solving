import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    static int N, S = 1;
    static int[] A;
    static int[] B = new int[1000001];
    static long[] tree;
    static long ans;
    
    public static void main(String[] args) throws IOException {
        
        while (S < 1000000) {
            S *= 2;
        }
        tree = new long[S * 2];
        
        N = Integer.parseInt(br.readLine());
        A = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            int b = Integer.parseInt(st.nextToken());
            B[b] = i;
        }
        
        // B 기계보다 오른쪽에 있는 기계의 개수를 구하고, 인덱스 트리를 업데이트한다.
        for (int i = 0; i < N; i++) {
            ans += query(1, S, 1, B[A[i]] + 1, S);
            update(1, S, 1, B[A[i]], 1);
        }
        
        System.out.print(ans);
    }
    
    private static long query(int left, int right, int node, int queryLeft, int queryRight) {
        if (queryRight < left || queryLeft > right) {
            return 0;
        } else if (queryLeft <= left && queryRight >= right) {
            return tree[node];
        } else {
            int mid = (left + right) / 2;
            long leftResult = query(left, mid, node * 2, queryLeft, queryRight);
            long rightResult = query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
            return leftResult + rightResult;
        }
    }
    
    private static void update(int left, int right, int node, int target, int diff) {
        if (target < left || target > right) {
            return;
        }
        tree[node] += diff;
        if (left != right) {
            int mid = (left + right) / 2;
            update(left, mid, node * 2, target, diff);
            update(mid + 1, right, node * 2 + 1, target, diff);
        }
    }
}