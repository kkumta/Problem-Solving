class Solution {
    public boolean isSubsequence(String s, String t) {
        int sIdx = 0, tIdx = 0;
        if (sIdx == s.length()) {
            return true;
        }
        while (sIdx < s.length() && tIdx < t.length()) {
            if (s.charAt(sIdx) == t.charAt(tIdx++)) {
                sIdx++;
            }
        }
        return sIdx == s.length();
    }
}