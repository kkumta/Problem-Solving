import java.io.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringBuilder sb = new StringBuilder();
    
    public static void main(String[] args) throws IOException {
        
        int n = Integer.parseInt(br.readLine());
        int[] input = new int[n];
        for (int i = 0; i < n; i++) {
            input[i] = Integer.parseInt(br.readLine());
        }
        
        int[] countArray = new int[2000001];
        for (int i = 0; i < n; i++) {
            ++countArray[input[i] + 1000000];
        }
        
        for (int i = 0; i < 2000001; i++) {
            for (int j = 0; j < countArray[i]; j++) {
                sb.append(i - 1000000).append("\n");
            }
        }
        
        System.out.print(sb.toString());
    }
}
