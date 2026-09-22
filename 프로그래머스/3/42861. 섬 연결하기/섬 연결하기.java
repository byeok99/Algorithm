import java.util.*;

class Solution {
    static int[] parent; 
    
    public int solution(int n, int[][] costs) {
        parent = new int[n];
        
        for(int i=0; i<n; i++) parent[i] = i;
        
        Arrays.sort(costs, (a, b) -> Integer.compare(a[2], b[2]));
        
        int answer = 0;
        int cnt = 0;
        for(int[] edge : costs) {
            if (cnt == n-1) break;
            int to = edge[0];
            int from = edge[1];
            int cost = edge[2];
            
            if (find(to) == find(from)) continue;
            
            union(to, from);
            
            answer += cost;
            cnt++;
        }
        
        return answer;
    }
    
    static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    static void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        
        if (rootA == rootB) return;
        
        parent[rootB] = rootA;
    }
}