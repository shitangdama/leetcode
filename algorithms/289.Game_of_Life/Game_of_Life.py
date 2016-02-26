class Solution(object):
    def gameOfLife(self, board):
    # update the board based on number
    # 0: dead to dead
    # 1: live to live
    # 2: live to dead (1 -> 0)
    # 3: dead to live (0 -> 1)
            drx = [-1, 0,  1, -1, 1, -1, 0, 1]
            dry = [-1, -1, -1, 0, 0,  1, 1, 1]
            n = len(board)
            m = len(board[0])
        
            for i in xrange(n):
                for j in xrange(m):
                    now = board[i][j]
                    nigh_live = 0
                    for k in xrange(8):
                        newx = j+drx[k]
                        newy = i+dry[k]
                        if newx<0 or newx>=m or newy<0 or newy>=n:
                            continue
                        if board[newy][newx] == 1 or board[newy][newx] == 2:
                            nigh_live += 1
        
                    if now == 1 and (nigh_live < 2 or nigh_live > 3):
                        board[i][j] = 2
                    elif now == 0 and nigh_live == 3:
                        board[i][j] = 3
        
            for i in xrange(n):
                for j in xrange(m):
                    board[i][j] %= 2
