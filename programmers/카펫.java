import java.util.*;

class Solution {
    public int[] solution(int brown, int yellow) {

        int[] answer = new int[2];
        int amount = brown + yellow;

        for (int i = 3; i <= Math.sqrt(amount); i++) {
            if (amount % i == 0) {
                int width = amount / i; // 가로
                int height = i; // 세로
                if (amount - (width * 2) - (height * 2) + 4 == yellow) {
                    answer[0] = amount / i;
                    answer[1] = i;
                    System.out.println(answer[0] + " " + answer[1]);
                    return answer;
                }
            }
        }
        return answer;
    }
}
