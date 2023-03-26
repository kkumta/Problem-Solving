class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[] toT = new int[128];
        boolean[] isUsed = new boolean[128];
        Arrays.fill(toT, -1);
        Arrays.fill(isUsed, false);
        for (int i = 0; i < s.length(); i++) {
            if (toT[s.charAt(i)] == -1 && !isUsed[t.charAt(i)]) {
                toT[s.charAt(i)] = t.charAt(i);
                isUsed[t.charAt(i)] = true;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (t.charAt(i) != toT[s.charAt(i)]) {
                return false;
            }
        }

        return true;
    }
}