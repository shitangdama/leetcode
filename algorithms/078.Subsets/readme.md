所有子集问题
两种方法一种是dfs，一种是占位思想
优先考虑dfs模板
先把问题分解成tree
Pick a starting point.
while(Problem is not solved)
    For each path from the starting point.
        check if selected path is safe, if yes select it
        and make recursive call to rest of the problem
        before which undo the current move.
    End For
If none of the move works out, return false, NO SOLUTON.
回朔在和dfs没什么区别
这里主要是在于两种dfs
一种记录了路径
一种之关注与子节点