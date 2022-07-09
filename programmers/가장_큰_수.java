import java.io.*;
import java.util.*;

class Solution {

    public String solution(int[] numbers) {

        String answer = "";

        // numbers를 문자열 형태로 변경
        String[] numbersToStr = new String[numbers.length];
        for (int i = 0; i < numbers.length; i++) {
            numbersToStr[i] = Integer.toString(numbers[i]);
        }

        // numbersToStr 정렬
        Arrays.sort(numbersToStr, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return (o2 + o1).compareTo(o1 + o2);
            }
        });

        for (int i = 0; i < numbersToStr.length; i++) {
            if (i != 0 && numbersToStr[0].equals("0")) {
                break;
            }
            answer += numbersToStr[i];
        }

        return answer;
    }
}
