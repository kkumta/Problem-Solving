import java.io.*;
import java.util.*;

public class Main {
    
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    
    public static void main(String[] args) throws IOException {
        
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            
            // 입력 받아 초기값 설정
            String p = br.readLine();
            int n = Integer.parseInt(br.readLine());
            String x = br.readLine();
            x = x.substring(1, x.length() - 1);
            st = new StringTokenizer(x, ",");
            List<Integer> xList = new LinkedList<>();
            boolean xListPos = true; // 덱을 앞에서부터 가리키게 설정
            boolean isError = false; // 에러 여부
            for (int j = 0; j < n; j++) {
                xList.add(Integer.parseInt(st.nextToken()));
            }
            
            // 함수 동작 수행
            for (int j = 0; j < p.length(); j++) {
                if (p.charAt(j) == 'R') {
                    xListPos = !xListPos; // 덱을 가리키는 방향을 반대로 바꿈
                } else {
                    if (xList.isEmpty()) {
                        isError = true;
                        break;
                    } else {
                        if (xListPos) {
                            xList.remove(0); // 덱을 앞에서부터 가리킨다면, 0번 인덱스 삭제
                        } else {
                            xList.remove(xList.size() - 1);  // 덱을 뒤에서부터 가리킨다면, 마지막 인덱스 삭제
                        }
                    }
                }
            }
            
            // StringBuilder에 결과 삽입
            if (isError) { // 에러일 경우 error 출력
                sb.append("error").append("\n");
            } else { // 에러가 아닐 경우 배열 출력(빈 배열 포함)
                sb.append("[");
                Object[] xArray = xList.toArray();
                if (xListPos) {
                    if (!xList.isEmpty()) {
                        sb.append(xArray[0]);
                    }
                    for (int j = 1; j < xArray.length; j++) {
                        sb.append(",").append(xArray[j]);
                    }
                } else {
                    for (int j = xArray.length - 1; j > 0; j--) {
                        sb.append(xArray[j]).append(",");
                    }
                    if (!xList.isEmpty()) {
                        sb.append(xArray[0]);
                    }
                }
                sb.append("]").append("\n");
            }
        }
        System.out.print(sb.toString());
    }
}
