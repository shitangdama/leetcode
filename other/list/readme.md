　　在环上相遇后，记录第一次相遇点为Pos，连接点为Join，假设头结点到连接点的长度为LenA，连接点到第一次相遇点的长度为x，环长为R。

　　　　第一次相遇时，slow走的长度 S = LenA + x;

　　　　第一次相遇时，fast走的长度 2S = LenA + n*R + x;

　　　　所以可以知道，LenA + x =  n*R;　　LenA = n*R -x;


思路1：记录下相遇节点存入临时变量tempPtr，然后让slow(或者fast，都一样)继续向前走slow = slow -> next；一直到slow == tempPtr; 此时经过的步数就是环上节点的个数；

思路2： 从相遇点开始slow和fast继续按照原来的方式向前走slow = slow -> next; fast = fast -> next -> next；直到二者再次项目，此时经过的步数就是环上节点的个数 。