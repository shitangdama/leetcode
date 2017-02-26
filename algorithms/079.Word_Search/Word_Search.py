<<<<<<< HEAD
# Time:  O(m * n * l)
# Space: O(l)

class Solution:
    # @param board, a list of lists of 1 length string
    # @param word, a string
    # @return a boolean
    def exist(self, board, word):
        visited = [[False for j in xrange(len(board[0]))] for i in xrange(len(board))]
        
        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                if self.existRecu(board, word, 0, i, j, visited):
                    return True
        
        return False
    
    def existRecu(self, board, word, cur, i, j, visited):
        if cur == len(word):
            return True
        
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or visited[i][j] or board[i][j] != word[cur]:
            return False
        
        visited[i][j] = True
        result = self.existRecu(board, word, cur + 1, i + 1, j, visited) or\
                 self.existRecu(board, word, cur + 1, i - 1, j, visited) or\
                 self.existRecu(board, word, cur + 1, i, j + 1, visited) or\
                 self.existRecu(board, word, cur + 1, i, j - 1, visited)         
        visited[i][j] = False
        
        return result
    
if __name__ == "__main__":
    board = [
              "ABCE",
              "SFCS",
              "ADEE"
            ]
    print Solution().exist(board, "ABCCED")
    print Solution().exist(board, "SFCS")
    print Solution().exist(board, "ABCB")
=======
# Time:  O(m * n * l)
# Space: O(l)

class Solution:
    # @param board, a list of lists of 1 length string
    # @param word, a string
    # @return a boolean
    def exist(self, board, word):
        visited = [[False for j in xrange(len(board[0]))] for i in xrange(len(board))]
        
        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                if self.existRecu(board, word, 0, i, j, visited):
                    return True
        
        return False
    
    def existRecu(self, board, word, cur, i, j, visited):
        if cur == len(word):
            return True
        
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or visited[i][j] or board[i][j] != word[cur]:
            return False
        
        visited[i][j] = True
        result = self.existRecu(board, word, cur + 1, i + 1, j, visited) or\
                 self.existRecu(board, word, cur + 1, i - 1, j, visited) or\
                 self.existRecu(board, word, cur + 1, i, j + 1, visited) or\
                 self.existRecu(board, word, cur + 1, i, j - 1, visited)         
        visited[i][j] = False
        
        return result
    
if __name__ == "__main__":
    board = [
              "ABCE",
              "SFCS",
              "ADEE"
            ]
    print Solution().exist(board, "ABCCED")
    print Solution().exist(board, "SFCS")
    print Solution().exist(board, "ABCB")
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
