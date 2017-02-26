<<<<<<< HEAD
def minTotalDistance(self, grid):
    row_sum = map(sum, grid)
    col_sum = map(sum, zip(*grid)) # syntax sugar learned from stefan :-)

    def minTotalDistance1D(vec):
        i, j = -1, len(vec)
        d = left = right = 0
        while i != j:
            if left < right:
                d += left
                i += 1
                left += vec[i]
            else:
                d += right
                j -= 1
                right += vec[j]
        return d

    return minTotalDistance1D(row_sum) + minTotalDistance1D(col_sum)
=======
def minTotalDistance(self, grid):
    row_sum = map(sum, grid)
    col_sum = map(sum, zip(*grid)) # syntax sugar learned from stefan :-)

    def minTotalDistance1D(vec):
        i, j = -1, len(vec)
        d = left = right = 0
        while i != j:
            if left < right:
                d += left
                i += 1
                left += vec[i]
            else:
                d += right
                j -= 1
                right += vec[j]
        return d

    return minTotalDistance1D(row_sum) + minTotalDistance1D(col_sum)
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
