<<<<<<< HEAD
class Solution(object):
    def wallsAndGates(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: void Do not return anything, modify rooms in-place instead.
        """
        # first attempt - record the gates position and BFS to propagate
        m = len(rooms)
        if m == 0:
            return 
        n = len(rooms[0])
        if n == 0:
            return
        currentLevel = set()
        for i in range(m):
            for j in range(n):
                if rooms[i][j] == 0:
                    currentLevel.add((i,j))
        while currentLevel:
            nextlevel = set()
            for coordinate in currentLevel:
                y,x= coordinate
                dist = rooms[y][x] + 1
                if x - 1 >= 0 and dist < rooms[y][x-1]:
                    rooms[y][x-1] = dist
                    nextlevel.add((y,x-1))
                if x + 1 < n and dist < rooms[y][x+1]:
                    rooms[y][x+1] = dist
                    nextlevel.add((y,x+1))
                if y - 1 >= 0 and dist < rooms[y-1][x]:
                    rooms[y-1][x] = dist
                    nextlevel.add((y-1,x))
                if y + 1 < m and dist < rooms[y+1][x]:
                    rooms[y+1][x] = dist
                    nextlevel.add((y+1,x))
            currentLevel = nextlevel
        
=======
class Solution(object):
    def wallsAndGates(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: void Do not return anything, modify rooms in-place instead.
        """
        # first attempt - record the gates position and BFS to propagate
        m = len(rooms)
        if m == 0:
            return 
        n = len(rooms[0])
        if n == 0:
            return
        currentLevel = set()
        for i in range(m):
            for j in range(n):
                if rooms[i][j] == 0:
                    currentLevel.add((i,j))
        while currentLevel:
            nextlevel = set()
            for coordinate in currentLevel:
                y,x= coordinate
                dist = rooms[y][x] + 1
                if x - 1 >= 0 and dist < rooms[y][x-1]:
                    rooms[y][x-1] = dist
                    nextlevel.add((y,x-1))
                if x + 1 < n and dist < rooms[y][x+1]:
                    rooms[y][x+1] = dist
                    nextlevel.add((y,x+1))
                if y - 1 >= 0 and dist < rooms[y-1][x]:
                    rooms[y-1][x] = dist
                    nextlevel.add((y-1,x))
                if y + 1 < m and dist < rooms[y+1][x]:
                    rooms[y+1][x] = dist
                    nextlevel.add((y+1,x))
            currentLevel = nextlevel
        
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
