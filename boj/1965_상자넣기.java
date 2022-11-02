import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int n;
    static int[] boxes, d;

    public static void main(String[] args) throws IOException {

        n = Integer.parseInt(br.readLine());
        boxes = new int[n];
        d = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            boxes[i] = Integer.parseInt(st.nextToken());
        }

        // LIS
        Arrays.fill(d, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (boxes[i] > boxes[j] && d[j] + 1 > d[i]) {
                    d[i] = d[j] + 1;
                }
            }
        }

        System.out.print(Arrays.stream(d).max().getAsInt());
    }
}