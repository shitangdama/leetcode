
public class Solution {
    
    static class Vertex {
        
        int id;
        
        Vertex(int id){
            this.id = id;
        }
        
        Set<Integer> in  = new HashSet<>();
        Set<Integer> out = new HashSet<>();
        
        boolean isSink(){
            return out.isEmpty();
        }
    }
    
    Vertex safe(Vertex[] G, int id){
        if(G[id] == null){
            G[id] = new Vertex(id);
        }
        
        return G[id];
    }
    
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        
        Vertex[] G = new Vertex[numCourses];
        
        for(int[] p : prerequisites){
            safe(G, p[0]).out.add(p[1]);
            safe(G, p[1]).in.add(p[0]);
        }
        
        Set<Vertex> S = Arrays.stream(G)
                            .filter(v -> v != null)
                            .collect(Collectors.toSet());
        

        loop:
        while(!S.isEmpty()){
            
            for(Vertex v : S){
                if(v.isSink()){
                    S.remove(v);
                    
                    for(int i : v.in){
                        G[i].out.remove(v.id);
                    }
                    
                    continue loop;
                }
            }
            
            return false;
        }
        
        return true;
    }
}
public boolean canFinish(int numCourses, int[][] prerequisites) {
    int[][] matrix = new int[numCourses][numCourses]; // i -> j
    int[] indegree = new int[numCourses];

    for (int i=0; i<prerequisites.length; i++) {
        int ready = prerequisites[i][0];
        int pre = prerequisites[i][1];
        if (matrix[pre][ready] == 0)
            indegree[ready]++; //duplicate case
        matrix[pre][ready] = 1;
    }

    int count = 0;
    Queue<Integer> queue = new LinkedList();
    for (int i=0; i<indegree.length; i++) {
        if (indegree[i] == 0) queue.offer(i);
    }
    while (!queue.isEmpty()) {
        int course = queue.poll();
        count++;
        for (int i=0; i<numCourses; i++) {
            if (matrix[course][i] != 0) {
                if (--indegree[i] == 0)
                    queue.offer(i);
            }
        }
    }
    return count == numCourses;
}

