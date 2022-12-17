import java.util.*;

class Solution {
    
    char[] word;
    boolean[] isUsed;
    boolean flag = false;
    
    public int solution(String[] spell, String[] dic) {
        word = new char[spell.length];
        isUsed = new boolean[spell.length];
        func(0, spell, new HashSet(Arrays.asList(dic)));
        
        if (flag) {
            return 1;
        }
        return 2;
    }
    
    private void func(int k, String[] spell, HashSet<String> dic) {
        if (flag) {
            return;
        }
        if (k == spell.length) {
            if (dic.contains(String.copyValueOf(word))) {
                flag = true;
            }
            return;
        }
        
        for (int i = 0; i < spell.length; i++) {
            if (!isUsed[i]) {
                isUsed[i] = true;
                word[k] = spell[i].charAt(0);
                func(k + 1, spell, dic);
                isUsed[i] = false;
            }
        }
    }
}