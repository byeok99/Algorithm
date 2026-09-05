import java.util.*;

class Solution {
    static int[] parent;
    
    public int solution(int n, int[][] costs) {
        parent = new int[n];
        for(int i=0; i<n; i++) parent[i] = i;
        
        Arrays.sort(costs, (a, b) -> Integer.compare(a[2], b[2]));
        
        int answer = 0;
        int cnt = 0;
        
        for(int[] e : costs) {
            int from = e[0];
            int to = e[1];
            int cost = e[2];
            
            if (find(from) == find(to)) continue;
            
            union(from, to);
            
            answer += cost;
            cnt += 1;
            
            if (cnt == n-1) break;   
        }
        
        return answer;
    }
    
    static int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    
    static void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        
        if (rootA != rootB) parent[rootB] = rootA;
    }
}