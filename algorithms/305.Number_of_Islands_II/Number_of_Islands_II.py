def numIslands2(self, m, n, positions):
    counts, main, land = [], {}, {}
    for i, j in positions:
        p = i, j
        main[p], land[p] = p, [p]
        for q in (i+1, j), (i-1, j), (i, j+1), (i, j-1):
            if q in main:
                p, q = main[p], main[q]
                if p != q:
                    if len(land[p]) < len(land[q]):
                        p, q = q, p
                    land[p] += land[q]
                    for l in land.pop(q):
                        main[l] = p
        counts += len(land),
    return counts


def numIslands2(self, m, n, positions):
    counts, main, land = [], {}, {}
    for p in itertools.starmap(complex, positions):
        main[p], land[p] = p, [p]
        for q in [p + 1j ** k for k in range(4)]:
            if q in main:
                p, q = main[p], main[q]
                if p != q:
                    if len(land[p]) < len(land[q]):
                        p, q = q, p
                    land[p] += land[q]
                    for l in land.pop(q):
                        main[l] = p
        counts += len(land),
    return counts
