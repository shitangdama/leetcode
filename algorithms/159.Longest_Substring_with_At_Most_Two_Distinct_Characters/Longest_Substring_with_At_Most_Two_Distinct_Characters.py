class Solution:
    # @return length of longest substring 
    # with at most two distinct characters
    def longest(self, S):
        if S is None or len(S)==0: return 0
        if len(S) == 1: return 1
        i = 0; j=-1; longest = 1; res = 1
        for cur in range(1, len(S)):
            if S[cur] == S[i]: 
                longest+=1; continue
            elif j==-1 or S[cur]==S[j]:
                j = cur; longest+=1; continue
            else:
                res = max(res, longest)
                if j+1==cur: i=j; j=cur; longest = 2
                else:i=j+1; j = cur; longest = j-i+1
                continue
        res = max(res, longest)
        return res

if __name__ == "__main__":
    s = Solution()
    print s.longest("eceab")
    print s.longest("eeeeccceeeaaabeeee")
    print s.longest("eeeeccceeeaaabeeeeeeeeeeeeeeeeee")
