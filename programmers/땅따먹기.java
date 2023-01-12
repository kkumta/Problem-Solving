import java.util.Arrays;

class Solution {
    
    int solution(int[][] land) {
        int[][] d = new int[land.length][4];
        for (int i = 0; i < land[0].length; i++) {
            d[0][i] = land[0][i];
        }
        for (int i = 1; i < land.length; i++) { // 행
            for (int j = 0; j < land[0].length; j++) { // 열
                // 직전 행에서 가장 큰 d 값 구하기
                d[i][j] = Math.max(d[i - 1][(j + 1) % land[0].length],
                                   Math.max(d[i - 1][(j + 2) % land[0].length],
                                            d[i - 1][(j + 3) % land[0].length]))
                    + land[i][j];
            }
        }
        return Arrays.stream(d[land.length - 1]).max().getAsInt();
    }
}