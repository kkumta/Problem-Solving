class Solution {
    
    public int solution(int[][] sizes) {
        int first = 0, second = 0;
        for (int[] size : sizes) {
            int width = Math.max(size[0], size[1]);
            int height = Math.min(size[0], size[1]);
            if (width > first) {
                first = width;
            }
            if (height > second) {
                second = height;
            }
        }
        
        return first * second;
    }
}