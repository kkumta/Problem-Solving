import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    static int[] a;
    static List<Integer> subSequence = new ArrayList<>();
    
    public static void main(String[] args) throws IOException {
        
        a = new int[Integer.parseInt(br.readLine())];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < a.length; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < a.length; i++) {
            if (subSequence.isEmpty() || subSequence.get(subSequence.size() - 1) < a[i]) {
                subSequence.add(a[i]);
            } else {
                subSequence.set(lowerBound(subSequence, a[i]), a[i]);
            }
        }
        
        System.out.print(subSequence.size());
    }
    
    private static int lowerBound(List<Integer> arr, int target) {
        
        int start = 0;
        int end = arr.size();
        
        while (start < end) {
            int mid = (start + end) / 2;
            if (arr.get(mid) >= target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        
        return start;
    }
}