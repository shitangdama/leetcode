261. Graph Valid Tree
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
For example:
Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
Hint:
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
According to the definition of tree on Wikipedia: ��a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.��
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
http://blog.csdn.net/dm_vincent/article/details/7655764
���鼯
���Ӷ�

ʱ�� O(N^M) �ռ� O(1)
˼·

�ж�����ı��Ƿ��ܹ���һ������������Ҫȷ�������£�

    ��Щ���Ƿ񹹳ɻ�·������л����ܹ�����

    ��Щ���Ƿ��ܽ����нڵ���ͨ������в�����ͨ�Ľڵ����ܹ�����

��Ϊ����Ҫ֪�����������ʲô���ӣ�ֻҪ֪����ͨ�Ĺ�ϵ�����Բ��鼯���������������Ǹ��õķ��������Ƕ���һ�����鼯�����ݽṹ�����ṩ��׼���ĸ��ӿڣ�

    union �������ڵ����һ��������

    find �ҵ��ýڵ������ļ��ϱ��

    areConnected �ж������ڵ��Ƿ���һ������

    count ���ظò��鼯���ж��ٸ������ļ���

���岢�鼯��ԭ���μ���ƪ���¡��������������ȹ���һ�����飬�ڵ�0���ڵ�n-1���տ�ʼ�����Զ����������Լ��ļ��ϡ���ʱ���ϵı���ǽڵ�š�Ȼ��ÿ��union����ʱ�����ǰ��������鼯�У����к͵�һ���ڵ��������Ϻ���ͬ�Ľڵ�ļ��Ϻţ����ĳɵڶ����ڵ�ļ��Ϻš������ͽ�һ�����ϵĽڵ������ͬһ�����Ϻ����ˡ����Ǳ���һ�����룬�����б߼������ǵĲ��鼯�У��ӵ�ͬʱ�ж��Ƿ��л�·�����������鼯��ֻ��һ�����ϣ���˵�����Թ�������
ע��

��ΪҪ�ж��Ƿ�������·��union����Ҫ����һ��boolean����������ڵ㱾������һ�������У��ͷ��ؼ٣�˵���л�·