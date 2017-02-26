def minArea(self, image, x, y):
    top = self.searchRows(image, 0, x, True)
    bottom = self.searchRows(image, x + 1, len(image), False)
    left = self.searchColumns(image, 0, y, top, bottom, True)
    right = self.searchColumns(image, y + 1, len(image[0]), top, bottom, False)
    return (right - left) * (bottom - top)

def searchRows(self, image, i, j, opt):
    while i != j:
        m = (i + j) / 2
        if ('1' in image[m]) == opt:
            j = m
        else:
            i = m + 1
    return i

def searchColumns(self, image, i, j, top, bottom, opt):
    while i != j:
        m = (i + j) / 2
        if any(image[k][m] == '1' for k in xrange(top, bottom)) == opt:
            j = m
        else:
            i = m + 1
    return i
# Runtime: 56 ms
Python (DRY, from Stefan's cool solution)

def minArea(self, image, x, y):
    top = self.search(0, x, lambda mid: '1' in image[mid])
    bottom = self.search(x + 1, len(image), lambda mid: '1' not in image[mid])
    left = self.search(0, y, lambda mid: any(image[k][mid] == '1' for k in xrange(top, bottom)))
    right = self.search(y + 1, len(image[0]), lambda mid: all(image[k][mid] == '0' for k in xrange(top, bottom)))
    return (right - left) * (bottom - top)

def search(self, i, j, check):
    while i != j:
        mid = (i + j) / 2
        if check(mid):
            j = mid
        else:
            i = mid + 1
    return i
# Runtime: 56 ms
