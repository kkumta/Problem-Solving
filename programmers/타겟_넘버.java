class Solution {

    int count;

    public int solution(int[] numbers, int target) {

        func(numbers, target, 0, numbers.length, 0);

        int answer = count;
        System.out.println(answer);
        return answer;
    }

    private void func(int[] numbers, int target, int sum, int n, int k) {

        if (k == n) {
            if (sum == target) {
                ++count;
            }
            return;
        }

        func(numbers, target, sum + numbers[k], n, k + 1);
        func(numbers, target, sum - numbers[k], n, k + 1);
    }
}
