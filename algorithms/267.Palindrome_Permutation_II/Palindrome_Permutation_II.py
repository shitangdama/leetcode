<<<<<<< HEAD
class Solution(object):
    def generatePalindromes(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        # check element
        d = {}
        for i in s:
            if i not in d:
                d[i] = 1
            else:
                d[i] += 1
        oddcount = 0
        oddchar = ''
        for char in d:
            if d[char] & 1:
                oddcount += 1
                d[char] -= 1
                oddchar = char
            d[char] //= 2
        if oddcount > 1:
            return []
            
        # do permutation to iterate through all possible str
        # note that we just need to permute the first half of the
        # palindrome
        p = ''
        for char in d:
            p += char * d[char]
        if not p:
            return [oddchar]
        p = sorted(list(p))
        l = len(p)
        res = []
        while 1:
            res.append(''.join(p)+oddchar+''.join(p[::-1]))
            n = l-1
            while n > 0 and p[n - 1] >= p[n]:
                n -= 1
            if n == 0:
                break
            t = n
            while t < l and p[n - 1] < p[t]:
                t += 1
            temp = p[t-1]
            p[t-1] = p[n-1]
            p[n-1] = temp
            p[n:] = p[n:][::-1]
        return res
=======
class Solution(object):
    def generatePalindromes(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        # check element
        d = {}
        for i in s:
            if i not in d:
                d[i] = 1
            else:
                d[i] += 1
        oddcount = 0
        oddchar = ''
        for char in d:
            if d[char] & 1:
                oddcount += 1
                d[char] -= 1
                oddchar = char
            d[char] //= 2
        if oddcount > 1:
            return []
            
        # do permutation to iterate through all possible str
        # note that we just need to permute the first half of the
        # palindrome
        p = ''
        for char in d:
            p += char * d[char]
        if not p:
            return [oddchar]
        p = sorted(list(p))
        l = len(p)
        res = []
        while 1:
            res.append(''.join(p)+oddchar+''.join(p[::-1]))
            n = l-1
            while n > 0 and p[n - 1] >= p[n]:
                n -= 1
            if n == 0:
                break
            t = n
            while t < l and p[n - 1] < p[t]:
                t += 1
            temp = p[t-1]
            p[t-1] = p[n-1]
            p[n-1] = temp
            p[n:] = p[n:][::-1]
        return res
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
