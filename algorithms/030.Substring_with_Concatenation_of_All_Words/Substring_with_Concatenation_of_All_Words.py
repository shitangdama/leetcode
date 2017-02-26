# Time:  O(m * n * k), where m is string length, n is dictionary size, k is word length
# Space: O(n * k)
class Solution:
    # @param S, a string
    # @param L, a list of string
    # @return a list of integer
    def findSubstring(self, S, L):
        result, words, word_num, word_len = [], {}, len(L), len(L[0])
        for i in L:
            if i not in words:
                words[i] = 1
            else:
                words[i] += 1

        for i in xrange(len(S) + 1 - word_len * word_num):
            cur, j = {}, 0
            while j < word_num:
                word = S[i + j * word_len:i + j * word_len + word_len]
                if word not in words: 
                    break
                if word not in cur: 
                    cur[word] = 1
                else:
                    cur[word] += 1
                if cur[word] > words[word]:
                    break
                j += 1
            if j == word_num:
                result.append(i)
                
        return result

if __name__ == "__main__":
    print Solution().findSubstring("barfoothefoobarman", ["foo", "bar"])
