class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        if x == z or y == z or z == x+y:
            return True
        if x * y == 0:
            return False
        if z < 0 or z > x + y: return False
        a, b = x, y
        c = a % b
        while c!=0:
            a, b = b, c
            c = a % b

        if z % b == 0:
            return True
        else:
            return False
