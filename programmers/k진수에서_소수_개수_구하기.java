import java.util.*;

class Solution {
    public int solution(int n, int k) {

        int answer = 0;

        // k진법으로 수 바꾸기
        int[] kNumber = new int[20];
        for (int i = 0; i < 20; i++) { // int 배열 초기화
            kNumber[i] = -1;
        }
        for (int i = 19; n > 0; i--) {
            kNumber[i] = n % k;
            n /= k;
        }

        // k진법 수 String 형으로 변환하기
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 20; i++) {
            if (kNumber[i] != -1) {// 배열에 값이 있는 경우만 sb에 넣는다
                sb.append(kNumber[i] + "");
            }
        }
        String strNumber = sb.toString();

        // String 형으로 변환한 수를 0으로 Tokenize 하기
        StringTokenizer st = new StringTokenizer(strNumber, "0");
        String[] numbers;
        if (st.countTokens() > 0) {
            numbers = new String[st.countTokens()];
            for (int i = 0; i < numbers.length; i++) {
                numbers[i] = st.nextToken();
            }
        } else {
            numbers = new String[1];
            numbers[1] = strNumber;
        }

        // 소수 찾기
        for (int i = 0; i < numbers.length; i++) {
            boolean flag = true;
            long number = Long.parseLong(numbers[i]);
            if (number <= 1) { // 만약 숫자가 1이라면
                continue;
            }
            for (int j = 2; j <= Math.sqrt(number); j++) {
                if (number % j == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                answer++;
            }
        }

        return answer;
    }
}
