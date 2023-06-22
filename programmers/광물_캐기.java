import java.util.*;

class Bundle implements Comparable<Bundle> {
    int diaSum;
    int ironSum;
    int stoneSum;
    
    public Bundle (int diaSum, int ironSum, int stoneSum) {
        this.diaSum = diaSum;
        this.ironSum = ironSum;
        this.stoneSum = stoneSum;
    }
    
    @Override
    public int compareTo(Bundle b) {
        return b.stoneSum - this.stoneSum;
    }
}

class Solution {
    public int solution(int[] picks, String[] minerals) {
        
        int ans = 0;
        int possibleSize = (picks[0] + picks[1] + picks[2]) * 5;
        List<Bundle> bundles = new ArrayList<>();
        
        // 광물을 5개씩 나눈 경우에, 각 곡괭이를 사용할 경우 소모하는 피로도 구하기
        int idx = 0;
        int diaSum = 0;
        int ironSum = 0;
        int stoneSum = 0;
        while (idx < minerals.length && idx < possibleSize) {            
            if (minerals[idx].equals("diamond")) {
                diaSum += 1;
                ironSum += 5;
                stoneSum += 25;
            } else if (minerals[idx].equals("iron")) {
                diaSum += 1;
                ironSum += 1;
                stoneSum += 5;
            } else {
                diaSum += 1;
                ironSum += 1;
                stoneSum += 1;
            }
            
            idx++;
            if (idx % 5 == 0) {
                bundles.add(new Bundle(diaSum, ironSum, stoneSum));
                
                diaSum = 0;
                ironSum = 0;
                stoneSum = 0;
            }
        }
        
        if (stoneSum != 0) {
            bundles.add(new Bundle(diaSum, ironSum, stoneSum));
        }        
        
        // 돌 곡괭이를 사용했을 경우의 피로도로 내림차순 정렬하기
        Collections.sort(bundles);
        
        // 다이아몬드, 철, 돌 곡괭이 순으로 광물을 캐서 총 피로도 구하기
        for (idx = 0; idx < 3; idx++) {
            for (int i = picks[idx]; i > 0; i--) {
                if (bundles.isEmpty()) {
                    return ans;
                }
                if (idx == 0) {
                    ans += bundles.remove(0).diaSum;
                } else if (idx == 1) {
                    ans += bundles.remove(0).ironSum;
                } else {
                    ans += bundles.remove(0).stoneSum;
                }
            }
        }
        
        return ans;
    }
}