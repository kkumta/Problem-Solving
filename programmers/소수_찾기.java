import java.util.*;

class Solution {

    static int[] papers;
    static boolean[] isVisited;
    static int[] number;
    ArrayList<Integer> arrayList = new ArrayList<>();

    public int solution(String numbers) {

        int answer = 0;
        isVisited = new boolean[numbers.length()];

        // 1. 가능한 모든 문자열 배열 만들기
        papers = new int[numbers.length()];
        for (int i = 0; i < papers.length; i++) {
            papers[i] = numbers.charAt(i) - '0';
        }

        for (int i = papers.length; i > 0; i--) {
            number = new int[i];
            func(i, 0);
        }

        // 2. 만들어진 모든 수를 탐색하며 소수의 개수 찾기
        for (Integer integer : arrayList) {
            if (isPrimeNumber(integer)) {
                ++answer;
            }
        }

        // 3. ArrayList의 길이를 구해 반환하기
        System.out.println(answer);
        return answer;
    }

    private boolean isPrimeNumber(Integer integer) {

        if (integer <= 1) {
            return false;
        }
        
        for (int i = 2; i <= Math.sqrt(integer); i++) {
            if (integer % i == 0) {
                return false;
            }
        }

        return true;
    }

    private void func(int length, int k) {

        if (k == length) {
            int numberToInt = 0;
            for (int i = 0; i < length; i++) {
                numberToInt += number[i] * Math.pow(10, length - i - 1);
            }

            if (!arrayList.contains(numberToInt)) {
                arrayList.add(numberToInt);
            }

            return;
        }

        for (int i = 0; i < papers.length; i++) {
            if (!isVisited[i]) {
                isVisited[i] = true;
                number[k] = papers[i];
                func(length, k + 1);
                isVisited[i] = false;
            }
        }
    }
}
