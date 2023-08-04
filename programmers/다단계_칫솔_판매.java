import java.util.*;

class Solution {

    int PRICE = 100;

    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] ans = new int[enroll.length];
        Arrays.fill(ans, 0);

        Map<String, Integer> enrollMap = new HashMap<>();
        for (int i = 0; i < enroll.length; i++) {
            enrollMap.put(enroll[i], i);
        }

        int[] referralNumbers = new int[referral.length];
        for (int i = 0; i < referral.length; i++) {
            if (referral[i].equals("-")) {
                referralNumbers[i] = -1;
            } else {
                referralNumbers[i] = enrollMap.get(referral[i]);
            }
        }

        // 추천인 찾아 이익 배분하기
        for (int i = 0; i < seller.length; i++) {
            int leftMoney = amount[i] * PRICE;
            int curEnroll = enrollMap.get(seller[i]);
            while (leftMoney > 0) {
                int curMoney = (int) Math.ceil(leftMoney * 0.9);
                leftMoney = leftMoney - curMoney;
                ans[curEnroll] += curMoney;

                // 센터로 이익이 배분된다면
                if (referralNumbers[curEnroll] == -1) {
                    break;
                }
                // 조직에 참여시킨 다른 판매원 찾기
                curEnroll = referralNumbers[curEnroll];
            }
        }

        return ans;
    }
}