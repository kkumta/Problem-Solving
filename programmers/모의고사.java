import java.util.*;

class Solution {

    public int[] solution(int[] answers) {

        int[] scores = new int[3];
        Arrays.fill(scores,0);

        // 1. 1번 수포자의 점수
        int[] answer1 = new int[10000];
        for (int i = 0; i < answer1.length; i++) {
            answer1[i] = i % 5 + 1;
        }
        for (int i = 0; i < answers.length; i++) {
            if (answer1[i] == answers[i]) {
                ++scores[0];
            }
        }

        // 2. 2번 수포자의 점수
        int[] answer2 = new int[10000];
        for (int i = 0; i < answer2.length; i++) {
            if (i % 2 == 0) {
                answer2[i] = 2;
            } else if (i % 8 == 5) {
                answer2[i] = 4;
            } else if (i % 8 == 7) {
                answer2[i] = 5;
            } else {
                answer2[i] = i % 8;
            }
        }
        for (int i = 0; i < answers.length; i++) {
            if (answer2[i] == answers[i]) {
                ++scores[1];
            }
        }

        // 3. 3번 수포자의 점수
        int[] answer3 = new int[10000];
        for (int i = 0; i < answer3.length; i++) {
            if (i % 10 <= 1) {
                answer3[i] = 3;
            } else if (i % 10 <= 3) {
                answer3[i] = 1;
            } else if (i % 10 <= 5) {
                answer3[i] = 2;
            } else if (i % 10 <= 7) {
                answer3[i] = 4;
            } else {
                answer3[i] = 5;
            }
        }
        for (int i = 0; i < answers.length; i++) {
            if (answer3[i] == answers[i]) {
                ++scores[2];
            }
        }

        // 4. 점수 비교 후 answer 배열 만들기
        Score[] scoreArray = new Score[3];
        for (int i = 0; i < 3; i++) {
            scoreArray[i] = new Score(i+1, scores[i]);
        }
        Arrays.sort(scoreArray);

        int answerLength = 1;
        for (int i = 1; i < 3; i++) {
            if (scoreArray[i].score == scoreArray[0].score ) {
                answerLength++;
            }
        }

        int[] answer = new int[answerLength];
        for (int i = 0; i < answerLength; i++) {
            answer[i] = scoreArray[i].num;
        }

        return answer;
    }

    private class Score implements Comparable<Score> {

        int num;
        int score;

        public Score(int num, int score) {
            this.num = num;
            this.score = score;
        }

        @Override
        public int compareTo(Score o) {
            return o.score - score;
        }
    }
}
