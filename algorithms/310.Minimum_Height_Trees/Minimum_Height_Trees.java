public class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
    List<Integer> leaves = new ArrayList<>();  
    if(n <= 1) {leaves.add(0); return leaves;}

    // Construct adjencent graph
    Map<Integer, Set<Integer>> graph = new HashMap<>();   
    for(int i = 0; i < n; i++) graph.put(i, new HashSet<Integer>());
    for(int[] e : edges) {
        graph.get(e[0]).add(e[1]);
        graph.get(e[1]).add(e[0]);
    }

    // Add leaves which have one leaf
    for(int i = 0; i < n; i++) {
        if(graph.get(i).size() == 1) leaves.add(i);
    }

    // Remove leaves level by level
    while(n > 2) {
        List<Integer> newLeaves = new ArrayList<>();
        for(int leaf : leaves) {
            for(int nb : graph.get(leaf)) {
                // Remove connection
                graph.get(leaf).remove(nb);
                graph.get(nb).remove(leaf);
                n--;
                if(graph.get(nb).size() == 1) {
                    newLeaves.add(nb);
                }
            }
        }
        leaves = newLeaves;
    }
    return leaves;
}
}