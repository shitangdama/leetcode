<<<<<<< HEAD
def findMinHeightTrees(self, n, edges):
    """
    :type n: int
    :type edges: List[List[int]]
    :rtype: List[int]
    """
    #pre check, for n < 3, return directly
    if n < 3:
        return range(n)
    #initiate map, queue and indegree
    map = collections.defaultdict(set)
    indegree = [0] * n
    for edge in edges:
        map[edge[0]].add(edge[1])
        map[edge[1]].add(edge[0])
        indegree[edge[0]] += 1
        indegree[edge[1]] += 1
    queue = []
    for i in range(n):
        if indegree[i] == 1:
            queue.append(i)
    #check from the outer layer to inner layer, stop when count == 1 or 2
    #which means we arrive at the center   
    count = n
    while count > 2:
        newqueue = []
        for current in queue:
            for i in map[current]:
                indegree[i] -= 1
                map[i].remove(current)
                if indegree[i] == 1:
                    newqueue.append(i)
            count -= 1
        queue = newqueue
    return queue
=======
def findMinHeightTrees(self, n, edges):
    """
    :type n: int
    :type edges: List[List[int]]
    :rtype: List[int]
    """
    #pre check, for n < 3, return directly
    if n < 3:
        return range(n)
    #initiate map, queue and indegree
    map = collections.defaultdict(set)
    indegree = [0] * n
    for edge in edges:
        map[edge[0]].add(edge[1])
        map[edge[1]].add(edge[0])
        indegree[edge[0]] += 1
        indegree[edge[1]] += 1
    queue = []
    for i in range(n):
        if indegree[i] == 1:
            queue.append(i)
    #check from the outer layer to inner layer, stop when count == 1 or 2
    #which means we arrive at the center   
    count = n
    while count > 2:
        newqueue = []
        for current in queue:
            for i in map[current]:
                indegree[i] -= 1
                map[i].remove(current)
                if indegree[i] == 1:
                    newqueue.append(i)
            count -= 1
        queue = newqueue
    return queue
>>>>>>> 6200c8704614e918c8bfa5357c648dd1b4f7eb74
