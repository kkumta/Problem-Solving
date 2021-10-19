import java.lang.Math;

class Solution {
    public int maxProfit(int[] prices) {
        int minPrice = 10000;
        int profit = 0;
        
        for(int i = 0; i < prices.length; i++) {
            minPrice = Math.min(minPrice, prices[i]);
            profit = Math.max(profit, prices[i] - minPrice);
        }
        
        return profit;
    }
}