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
ֻ����·����̵�ʱ����BFS���������ʱ����DFS��������·���������ָ����������С��������Ȼ��BFS��
���Ϊ4�֣�ʼ�㡢�յ㡢��ʼ���ա���ʼ���ա�
ʼ���������ʩ��Ӱ�죬��������������Ӱ�졣
�յ�������������Ӱ�죬������������ʩ��Ӱ�졣
������㣬�Ȳ�ʩ��Ӱ�죬�ֲ�����Ӱ�졣���Ժ��ԡ�
������㣬��ʩ��Ӱ�죬�ֽ���Ӱ�졣
���ֻ��1�㣬�ʹӸõ㿪ʼ�����������ȫ�֣���Ҫ������ʼ��͵�����㿪ʼ������
�����У�0��ȻΪʼ�㣬�������ȻΪ�յ㣬-1Ϊ������㡣û�е�����㡣���Դ����Ȼ�Ǵ�ÿ��0����һ��������
*/