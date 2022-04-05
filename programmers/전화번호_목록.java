import java.util.*;

class Solution {
    
    HashMap<String, Boolean> phoneBookHash;
    
    public boolean solution(String[] phone_book) {
        phoneBookHash = new HashMap<>();
        for (int i = 0; i < phone_book.length; i++) {
            phoneBookHash.put(phone_book[i], false);
        }
        
        for (String key : phoneBookHash.keySet()) {
            for (int i = 1; i < key.length(); i++) {
                if (phoneBookHash.containsKey(key.substring(0, i))) {
                    return false;
                }
            }
        }
        
        return true;
    }
}
