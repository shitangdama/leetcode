import string
class Solution:
    # @param start, a string
    # @param end, a string
    # @param dict, a set of string
    # @return an integer
    def ladderLength(self, start, end, dict):
        start_set, end_set = set([start]), set([end])

        n = len(start)
        dis = 1
        chars = string.ascii_lowercase

        while start_set and end_set:
            dis += 1
            if len(start_set) < len(end_set):
                start_set, end_set = end_set, start_set
            new_start_set = set()
            for word in start_set:
                for idx in range(n):
                    for c in chars:
                        s = word[:idx] + c + word[idx+1:]
                        if s in end_set:
                            return dis
                        if s in dict:
                            new_start_set.add(s)
                            dict.remove(s)
            start_set = new_start_set
            
        return 0

# BFS
class Solution:
    # @param start, a string
    # @param end, a string
    # @param dict, a set of string
    # @return an integer
    def ladderLength(self, start, end, dict):
        distance, cur, visited = 0, [start], set([start])
        dict.add(end)
        
        while cur:
            next = []
            for word in cur:
                if word == end:
                    return distance + 1
                for i in xrange(len(word)):
                    for j in 'abcdefghijklmnopqrstuvwxyz':
                        candidate = word[:i] + j + word[i + 1:]
                        if candidate not in visited and candidate in dict:
                            next.append(candidate)
                            visited.add(candidate)
            distance += 1
            cur = next
        
        return 0
    
if __name__ == "__main__":
    print Solution().ladderLength("hit", "cog", set(["hot","dot","dog","lot","log"]))
# debug
s = Solution()
print s.ladderLength("hot", "dog", ["hot","dog"])
