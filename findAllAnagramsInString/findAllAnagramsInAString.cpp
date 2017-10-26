/**
 *  https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 *  Runtime: O(s*p) where p is the size of the substring p and s is the size of the string s 
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> solution;
        int lenP = p.size();
        
        if (lenP > s.size()) {
            return solution;
        }
        for (int i = 0; i < s.size()-lenP+1 ; i++){
            // if the previous i was an anagram...
            if ( i > 0 && solution.size() > 0 ) {
                if (solution[solution.size()-1] == i-1) {
                    // Check if the next char is the same as the previous
                    if ( i+lenP <= s.size()-1){
                        if ( s[i-1] == s[i+lenP-1] ) { 
                            // Same chars implies that it is also an anagram.
                            solution.push_back(i);
                            continue;
                        } 
                    }
                }
            } 
            
            if (isAnagram (s.substr(i,lenP), p)) {
                solution.push_back(i);
            }
        }
        return solution;
    }
    
    bool isAnagram (string a, string b) {
        if (a.size() != b.size()) {
            return false;
        }
        int letterCount[26] = {0};
        
        // Count the letters in first string
        for (int i = 0; i < a.size(); i++) {
            char ch = a[i];
            if (letterCount[ch-'a'] > 0) {
                letterCount[ch-'a']++;
            } else {
                letterCount[ch-'a'] = 1;
            }
        }
        
        // Reduce the counts as we go through the second string
        for ( int i = 0; i < b.size(); i++) {
            char ch = b[i];
            int count = letterCount[ch-'a'];
            if (count == 0 ){
                return false;
            } else if ( count > 0) {
                letterCount[ch-'a']--; 
            }
        }
        
        return true;
    }
};