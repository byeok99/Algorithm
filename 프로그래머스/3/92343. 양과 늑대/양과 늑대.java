import java.util.*;

class Solution {
    private List<Integer>[] tree;
    private int maxVal = 0;
    private int[] INFO;
    private void dfs(int idx, int sheep, int wolf, Queue<Integer> q) {
        if (wolf >= sheep) {
            return;
        }
        maxVal = Math.max(maxVal, sheep);
        Queue<Integer> nextQueue = new ArrayDeque<>(q);
        
        for(int node: tree[idx]) {
            nextQueue.offer(node);
        }
        
        for(int i=0; i<nextQueue.size(); i++) {
            int node = nextQueue.poll();
            int val = INFO[node];
            
            if (val == 1) wolf++;
            else sheep++;
    
            dfs(node, sheep, wolf, nextQueue);
            
            if (val == 1) wolf--;
            else sheep--;
            
            nextQueue.offer(node);
        }
        
    }
    public int solution(int[] info, int[][] edges) {
        int n = info.length;
        int answer = 0;
        int FULLMASK = (1 << n);
        tree = new ArrayList[n]; 
        INFO = info;
        
        for (int i = 0; i < n; i++) {
            tree[i] = new ArrayList<>();
        }
        
        for(int i=0; i<edges.length; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            
            tree[a].add(b);
        }
        // idx, 양, 늑대
        
        dfs(0, 1, 0, new ArrayDeque<>()); 
        
        return maxVal;
    }
}