import java.util.*;

class Solution {
    
    private class Stock {
        
        int idx;
        int time;
        int price;
        
        public Stock(int idx, int time, int price) {
            this.idx = idx;
            this.time = time;
            this.price = price;
        }
    }
    
    public int[] solution(int[] prices) {
        int[] ans = new int[prices.length];
        
        Stack<Stock> stack = new Stack<Stock>();
        for (int i = 0; i < prices.length; i++) {
            if (!stack.empty()) {
                for (Stock pair : stack) { // 1초가 지날 때마다 스택의 각 원소에 1초씩 더하기
                    pair.time++;
                }
                if (i == prices.length - 1) { // 마지막 시각일 때 현재 스택에 있는 정보를 정답 배열에 넣어준다.
                    prices[prices.length - 1] = 0;
                    for (Stock pair : stack) {
                        ans[pair.idx] = pair.time;
                    }
                    break;
                }
                while (!stack.isEmpty()) { // 새로 들어온 주식 가격보다 더 비싼 가격이 스택에 있을 경우 스택에서 그 가격을 제거한다.
                    Stock last = stack.peek();
                    if (last.price > prices[i]) {
                        ans[last.idx] = last.time;
                        stack.pop();
                    } else {
                        break;
                    }
                }
            }
            stack.push(new Stock(i, 0, prices[i]));
        }
        
        return ans;
    }
}