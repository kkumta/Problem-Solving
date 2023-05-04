class Solution
{
    public int solution(int n, int a, int b) {
        int answer = 1;
        
        for (; ; answer++) {
            // a가 홀수이고 b가 a+1일 때 || b가 홀수이고 a가 b+1일 때 두 참가자가 붙게 된다.
            if ((a % 2 == 1 && b == a + 1) || (b % 2 == 1 && a == b + 1)) {
                break;
            }
            
            // 다음 라운드에서 부여받을 번호
            a = findNextNum(a);
            b = findNextNum(b);            
        }

        return answer;
    }
    
    private int findNextNum(int num) {
        // 짝수일 경우 다음 번호 = 현재 번호 / 2가 된다.
        if (num % 2 == 0) {
            return num / 2;
        }
        // 홀수일 경우 다음 번호 = 현재 번호 / 2 + 1이 된다.
        else {
            return num / 2 + 1;
        }
    }
}