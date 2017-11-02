/**
 *  https://leetcode.com/problems/find-all-anagrams-in-a-string/description/ *
 *  Runtime: O(n lg(n)) due to using a hash map. Switching from hash map
 *  to a character array of size 256 ( 1 byte ) would make each put from 
 *  the hash map from O(lg(n)) to O(1).
*/

class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> solution = new LinkedList<>();
        
        if ( p.length() > s.length() ) {
            return solution;
        }
        
        int begin = 0, end = 0, counter = 0;
        Map<Character, Integer> charMap = new HashMap<>();
        
        // Count the characters in the target string
        for ( char c : p.toCharArray() ) {
            charMap.put (c, charMap.getOrDefault(c,0) + 1);
        }
        
        counter = charMap.size();
        
        while ( end < s.length()) {
            char endChar = s.charAt(end);
            if( charMap.containsKey(endChar) ) {
                charMap.put(endChar, charMap.get(endChar)-1);
                
                // If we we have enough of the character
                if ( charMap.get(endChar) == 0 ) {
                    // Decrease the counter to say that there is a match.
                    counter--;
                }
            }
            end++;
            
            // While the counter is 0 (because if there is a bunch
            // of characters in the beginning that aren't part of the anagram
            // we can skip them)
            while ( counter == 0 ) {
                char beginChar = s.charAt(begin);
                if ( charMap.containsKey(beginChar) ) {
                    charMap.put(beginChar, charMap.get(beginChar)+1);
                    if(charMap.get(beginChar) > 0){
                        counter++;
                    }
                }
                if ( end-begin == p.length() ) {
                    solution.add(begin);
                }
                begin++;
            }
        }
        return solution;
    }
}