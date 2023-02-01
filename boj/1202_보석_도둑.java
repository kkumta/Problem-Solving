import java.util.*;
import java.io.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N, K;
    static long result;
    static int[] bags;
    static List<Info> jewels;
    
    public static void main(String[] args) throws IOException {
        
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        jewels = new LinkedList<>();
        K = Integer.parseInt(st.nextToken());
        bags = new int[K];
        
        // 보석을 무게 오름차순으로 정렬
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            jewels.add(
                new Info(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
        Collections.sort(jewels, Comparator.comparingInt(o -> o.weight));
        
        // 가방을 최대 무게 오름차순으로 정렬
        for (int i = 0; i < K; i++) {
            bags[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(bags);
        
        // 보석 가치 최대 우선순위 큐로 가장 적합한 보석 찾기
        Queue<Info> pq = new PriorityQueue<>((o1, o2) -> o2.price - o1.price);
        int jewelIdx = 0;
        for (int i = 0; i < K; i++) {
            while (jewelIdx < jewels.size()) {
                if (jewels.get(jewelIdx).weight <= bags[i]) {
                    pq.add(jewels.remove(jewelIdx));
                } else {
                    break;
                }
            }
            if (!pq.isEmpty()) {
                result += pq.remove().price;
            }
        }
        
        System.out.print(result);
    }
    
    private static class Info {
        
        int weight;
        int price;
        
        public Info(int weight, int price) {
            this.weight = weight;
            this.price = price;
        }
    }
}
