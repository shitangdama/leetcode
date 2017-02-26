#Solution 1

#Being lazy and using eval for checking:

def removeInvalidParentheses(self, s):
    level = {s}
    while True:
        valid = []
        for s in level:
            try:
                eval('0,' + filter('()'.count, s).replace(')', '),'))
                valid.append(s)
            except:
                pass
        if valid:
            return valid
        level = {s[:i] + s[i+1:] for s in level for i in range(len(s))}

#Update: Meh, ok, checking it myself isn't that much longer, and it's three times as fast:

#Solution 2

def removeInvalidParentheses(self, s):
    def isvalid(s):
        ctr = 0
        for c in s:
            if c == '(':
                ctr += 1
            elif c == ')':
                ctr -= 1
                if ctr < 0:
                    return False
        return ctr == 0
    level = {s}
    while True:
        valid = filter(isvalid, level)
        if valid:
            return valid
        level = {s[:i] + s[i+1:] for s in level for i in range(len(s))}

#Solution 3

#Just a mix of the above two.

def removeInvalidParentheses(self, s):
    def isvalid(s):
        try:
            eval('0,' + filter('()'.count, s).replace(')', '),'))
            return True
        except:
            pass
    level = {s}
    while True:
        valid = filter(isvalid, level)
        if valid:
            return valid
        level = {s[:i] + s[i+1:] for s in level for i in range(len(s))}

#Solution 4

#Yet another way to do isvalid.

def removeInvalidParentheses(self, s):
    def isvalid(s):
        s = filter('()'.count, s)
        while '()' in s:
            s = s.replace('()', '')
        return not s
    level = {s}
    while True:
        valid = filter(isvalid, level)
        if valid:
            return valid
        level = {s[:i] + s[i+1:] for s in level for i in range(len(s))}def minDrop(s, si, oc, cache, pseq):
    N = len(s)

    if oc < 0:
        return N - si + 1

    if si == N :
        if oc == 0:
            pseq[si][oc] = {''}
        return oc

    if cache[si][oc] != -1:
        return cache[si][oc]


    if s[si] in '()':
        dc0 = 1 + minDrop(s, si + 1, oc, cache, pseq)
        pseq0 = pseq[si + 1][oc]

        if s[si] == '(':
            dc1 = minDrop(s, si + 1, oc + 1, cache, pseq)
            pseq1 = ['(' + x for x in pseq[si + 1][oc + 1]]
        else:
            dc1 = minDrop(s, si + 1, oc - 1, cache, pseq)
            pseq1 = [')' + x for x in pseq[si + 1][oc - 1]]

        cache[si][oc] = min(dc0, dc1)

        # note '=' - in case of eqaulity we keep both combination sets
        if dc0 >= dc1 :
            pseq[si][oc] = pseq[si][oc].union(pseq1)

        if dc0 <= dc1 :
            pseq[si][oc] = pseq[si][oc].union(pseq0) 

    else:
        cache[si][oc] = minDrop(s, si + 1, oc, cache, pseq)
        pseq[si][oc] = [s[si] + x for x in pseq[si + 1][oc]]

    return cache[si][oc]

class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        N = len(s)
        cache = [[-1 for x in range(N)] for x in range(N)]
        pseq = [[set() for x in range(N + 1)] for x in range(N + 1)]

        c = minDrop(s, 0, 0, cache, pseq)

        return list(pseq[0][0])



