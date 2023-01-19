import java.util.*;

class Solution {
    
    public int solution(int n, int[] lost, int[] reserve) {
        
        // 체육복을 가지고 있는 학생을 배열에 체크하기
        boolean[] clothes = new boolean[n + 1];
        clothes[0] = false;
        for (int i = 1; i <= n; i++) {
            clothes[i] = true;
        }
        for (int student : lost) {
            clothes[student] = false;
        }
        
        // 여분의 체육복 set에 정리하기
        SortedSet<Integer> set = new TreeSet<>();
        for (int student : reserve) {
            set.add(student);
        }
        
        // 체육복 스스로에게 빌려 주기
        for (int student : reserve) {
            if (!clothes[student]) {
                set.remove(student);
                clothes[student] = true;
            }
        }
        
        // 다른 사람에게 체육복 빌려 주기
        for (int student : set) {
            if (student != 1 && !clothes[student - 1]) {
                clothes[student - 1] = true;
            } else if (student != n && !clothes[student + 1]) {
                clothes[student + 1] = true;
            }
        }
        
        int ans = 0;
        for (boolean clothe : clothes) {
            if (clothe) {
                ans++;
            }
        }
        
        return ans;
    }
}