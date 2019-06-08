class Solution(object):
    
    seenWords = {}
    lengths = {}
    
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        longestSubstring = 0
        
        end = 1
        length = len(s)+1
        for start in range( 0, length - 1 ):
            # start expanding the window
            sub = s[start:end]
            while end < length and self.isUnique(sub):
                if sub in self.lengths:
                    subStringLength = self.lengths[sub]
                else:
                    l = len(sub)
                    self.lengths[sub] = l
                    subStringLength = l

                if subStringLength > longestSubstring:
                    longestSubstring = subStringLength
                end += 1
                sub = s[start:end]
        
        return longestSubstring
        
    def isUnique(self, s):
        if s in self.seenWords:
            return self.seenWords[s]
        
        if len(s) == len(set(s)):
            self.seenWords[s] = True
            return True
        self.seenWords[s] = False
        return False
    
