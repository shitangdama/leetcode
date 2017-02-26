/*
286. Walls and Gates
You are given a m x n 2D grid initialized with these three possible values.
-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
 3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/

/*
只有求路径最短的时候，用BFS。其余多数时候用DFS，比如求路径最长，其他指标最大或者最小。此题显然用BFS。
点分为4种：始点、终点、不始不终、又始又终。
始点对其他点施加影响，但自身不受其他点影响。
终点自身受其他点影响，但不对其他点施加影响。
第三类点，既不施加影响，又不接受影响。可以忽略。
第四类点，又施加影响，又接受影响。
如果只求1点，就从该点开始搜索。如果求全局，就要从所有始点和第四类点开始搜索。
此题中，0显然为始点，无穷大显然为终点，-1为第三类点。没有第四类点。所以此题必然是从每个0启动一轮搜索。
*/