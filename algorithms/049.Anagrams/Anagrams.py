<<<<<<< HEAD
# Time:  O(n)
# Space: O(n)

class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        anagrams_map, result = {}, []
        for s in strs:
            sorted_str = ("").join(sorted(s))
            if sorted_str in anagrams_map:
                anagrams_map[sorted_str].append(s)
            else:
                anagrams_map[sorted_str] = [s]
        for anagram in anagrams_map.values():
            if len(anagram) > 1:
                result += anagram
        return result
        
if __name__ == "__main__":
    result = Solution().anagrams(["cat", "dog", "act", "mac"])
    print result
=======
# Time:  O(n)
# Space: O(n)

class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        anagrams_map, result = {}, []
        for s in strs:
            sorted_str = ("").join(sorted(s))
            if sorted_str in anagrams_map:
                anagrams_map[sorted_str].append(s)
            else:
                anagrams_map[sorted_str] = [s]
        for anagram in anagrams_map.values():
            if len(anagram) > 1:
                result += anagram
        return result
        
if __name__ == "__main__":
    result = Solution().anagrams(["cat", "dog", "act", "mac"])
    print result
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
