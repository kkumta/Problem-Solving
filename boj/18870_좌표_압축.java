import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    public static void main(String[] args) throws IOException {
        
        int n = Integer.parseInt(br.readLine());
        long[] input = new long[n];
        List<Long> removedDuplicatesList = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            input[i] = Long.parseLong(st.nextToken());
            removedDuplicatesList.add(input[i]);
        }
        
        // 정렬 후 중복 제거
        Collections.sort(removedDuplicatesList);
        removedDuplicatesList = removedDuplicatesList.stream().distinct()
            .collect(Collectors.toList());
        
        // 원래 값에 맞는 좌표 압축 결과 출력하기
        for (int i = 0; i < n; i++) {
            long target = input[i];
            sb.append(Collections.binarySearch(removedDuplicatesList, target) + " ");
        }
        
        System.out.print(sb.toString());
    }
}
