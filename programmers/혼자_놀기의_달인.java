import java.util.*;

class Solution {
    public int solution(int[] cards) {
        int[] boxes = new int[cards.length + 1];
        for (int i = 1; i <= cards.length; i++) {
            boxes[i] = cards[i - 1];
        }
        boolean[] isUsed = new boolean[cards.length + 1];
        Arrays.fill(isUsed, false);
        List<Integer> elementCount = new ArrayList<>();

        // 모든 카드를 다 사용할 때까지 상자 그룹을 만든다.
        for (int i = 1; i <= cards.length; i++) {
            if (isUsed[i]) {
                continue;
            }

            // i + 1번째 상자부터 상자 그룹 만들기
            int cardCount = 1;
            int curNum = i;
            isUsed[i] = true;
            while (true) {
                curNum = boxes[curNum];
                if (isUsed[curNum]) {
                    break;
                }

                isUsed[curNum] = true;
                cardCount++;
            }

            elementCount.add(cardCount);
        }

        if (elementCount.size() == 1) {
            return 0;
        }
        Collections.sort(elementCount);
        return elementCount.get(elementCount.size() - 1) * elementCount.get(elementCount.size() - 2);
    }
}