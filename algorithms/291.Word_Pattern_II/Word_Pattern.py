<<<<<<< HEAD
class Solution(object):
    def wordPatternMatch(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        return self.helper(pattern, str, 0, 0, {}, {})

    # use two dictionaries as in wordpattern 
    def helper(self, pattern, str, i, j, w2p, p2w):
        if i == len(pattern) and j == len(str):
            return True
        elif i < len(pattern) and j < len(str):
            p = pattern[i]
            if p in p2w:
                w = p2w[p]
                if w == str[j:j+len(w)]:
                    return self.helper(pattern, str, i + 1, j + len(w), w2p, p2w)
            else:
                for k in range(j, len(str)):
                    w = str[j:k+1]
                    if w not in w2p:
                        w2p[w], p2w[p] = p, w;
                        if self.helper(pattern, str, i + 1, k + 1, w2p, p2w):
                            return True
                        w2p.pop(w), p2w.pop(p);
        return False
=======
class Solution(object):
    def wordPatternMatch(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        return self.helper(pattern, str, 0, 0, {}, {})

    # use two dictionaries as in wordpattern 
    def helper(self, pattern, str, i, j, w2p, p2w):
        if i == len(pattern) and j == len(str):
            return True
        elif i < len(pattern) and j < len(str):
            p = pattern[i]
            if p in p2w:
                w = p2w[p]
                if w == str[j:j+len(w)]:
                    return self.helper(pattern, str, i + 1, j + len(w), w2p, p2w)
            else:
                for k in range(j, len(str)):
                    w = str[j:k+1]
                    if w not in w2p:
                        w2p[w], p2w[p] = p, w;
                        if self.helper(pattern, str, i + 1, k + 1, w2p, p2w):
                            return True
                        w2p.pop(w), p2w.pop(p);
        return False
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
