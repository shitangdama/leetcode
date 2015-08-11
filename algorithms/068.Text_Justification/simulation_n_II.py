# Time:  O(n)
# Space: O(1)

class Solution:
    # @param words, a list of strings
    # @param L, an integer
    # @return a list of strings
    def fullJustify(self, words, L):
        result = []
        
        i = 0
        while i < len(words):
            # count words in one line
            size, begin = 0, i
            while i < len(words):
                if size == 0:
                    newsize = len(words[i])
                else:
                    newsize = size + len(words[i]) + 1
                if newsize <= L:
                    size = newsize
                else:
                    break
                i += 1
            
            # count space number    
            spaceCount = L - size
            if i - begin - 1 > 0 and i < len(words):
                everyCount = spaceCount / (i - begin - 1) + 1
                spaceCount %= i - begin - 1
            else:
                everyCount = 1

            # add space
            j = begin
            while j < i:
                if j == begin:
                    s = words[j]
                else:
                    s += ' ' * everyCount
                    if spaceCount > 0 and i < len(words):
                        s += ' '
                        spaceCount -= 1
                    s += words[j]
                j += 1
            s += ' ' * spaceCount
            result.append(s)
            
        return result
    
class Solution2:
    def _format(self, line, maxWidth):
        if len(line) == 1:
            return line[0] + " " * (maxWidth - len(line[0]))
        length = sum([len(w) for w in line])
        s, gaps = line[0], len(line) - 1
        for index, w in enumerate(line[1:]):
            if index < (maxWidth - length) % gaps:
                s = s + " " + " " * ((maxWidth - length) / gaps) + w
            else:
                s = s + " " * ((maxWidth - length) / gaps) + w
        return s
        
    def _formatLast(self, line, maxWidth):
        s = ' '.join(line)
        return s + " " * (maxWidth - len(s))
    
    # @param {string[]} words
    # @param {integer} maxWidth
    # @return {string[]}
    def fullJustify(self, words, maxWidth):
        line, length = [], 0
        results = []
        for w in words:
            if length + len(w) + len(line) <= maxWidth:
                length += len(w)
                line.append(w)
            else:
                results.append(self._format(line, maxWidth))
                length = len(w)
                line = [w]
        if len(line):
            results.append(self._formatLast(line, maxWidth))
        return results

if __name__ == "__main__":
    print Solution().fullJustify(["This", "is", "an", "example", "of", "text", "justification."], 16)
