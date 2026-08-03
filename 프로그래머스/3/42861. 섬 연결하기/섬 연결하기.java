import java.util.*;

class Solution {
    int[] parent;
    public int solution(int n, int[][] costs) {
        int answer = 0;
        parent = new int[n];
        Arrays.sort(costs, (a, b) -> Integer.compare(a[2], b[2]));
        for(int i=0; i<n; i++) parent[i] = i;
        
        int count = 0;
        
        for(int[] edge: costs) {
            int a = edge[0];
            int b = edge[1];
            int cost = edge[2];
            
            if (find(a) == find(b)) continue;
            
            union(a, b);
            
            answer += cost;
            count++;
            
            if(count == n-1) break;
        }
        
        return answer;
    }
    
    private int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    private void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        
        if(rootA != rootB) parent[rootB] = rootA;
    }
    
}