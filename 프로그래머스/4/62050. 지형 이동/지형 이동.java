import java.util.*;

class Solution {
    static int N; 
    static int H;
    static int[][] LAND;
    static int[][] groups;
    static PriorityQueue<Edge> edges;
    static int[] parent;
    static int groupCount; 
    
    static int[] dy = {0, 1, 0, -1};
    static int[] dx = {1, 0, -1, 0};
    
    public int solution(int[][] land, int height) {
        N = land.length;
        LAND = land;
        H = height;
        
        makeGroups();
        
        makeEdges();
        
        int sum = 0;
        int cnt = 0;
            
        while(!edges.isEmpty()) { 
            if (cnt == groupCount-1) break;
            Edge e = edges.poll();
            
            if (find(e.from) == find(e.to)) continue;
            
            // System.out.println(e.from + " : " + e.to + " : " + e.cost);
            union(e.from, e.to); 
            
            sum += e.cost;
            cnt++;
        }
    
        return sum;
    }
    
    static void union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        
        if (rootA == rootB) return; 
        
        parent[rootB] = rootA;
        return;
    }
    
    static int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    static void makeGroups() {
        groups = new int[N][N];
        
        int num = 1;
        boolean[][] visited = new boolean[N][N];
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if (visited[i][j]) continue;
                
                Queue<Pair> q = new ArrayDeque<>();
                q.offer(new Pair(i, j));
                
                groups[i][j] = num;
                
                while(!q.isEmpty()) {
                    Pair cur = q.poll();
                    
                    for(int d=0; d<4; d++) {
                        int ny = cur.r + dy[d];
                        int nx = cur.c + dx[d];
                        
                        if (ny >= N || ny < 0 || nx >= N || nx < 0 || visited[ny][nx]) continue;
                        if (Math.abs(LAND[cur.r][cur.c] - LAND[ny][nx]) > H) continue;
                        
                        groups[ny][nx] = num; 
                        visited[ny][nx] = true;
                        q.offer(new Pair(ny, nx));
                    }
                }
                num++;
            }
        }
        
        parent = new int[num];
        groupCount = num;
        
        for(int i=0; i<num; i++) parent[i] = i;
        
        // for(int i=0; i<N; i++) {
        //     System.out.println(Arrays.toString(groups[i]));
        // }
    }
    
    static void makeEdges() {
        // 다른 그룹인 경우에 Edges 구성
        edges = new PriorityQueue<>((a, b) -> Integer.compare(a.cost, b.cost));
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                for(int d=0; d<4; d++) {
                    int ny = i + dy[d];
                    int nx = j + dx[d];

                    if (ny >= N || nx >= N || ny < 0 || nx < 0) continue; 
                    if (groups[ny][nx] == groups[i][j]) continue;

                    edges.offer(new Edge(groups[i][j], groups[ny][nx], Math.abs(LAND[i][j] - LAND[ny][nx])));
                }
            }
        }
    }
    
    static class Pair {
        int r, c;
        
        Pair(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
    
    static class Edge {
        int from, to, cost; 
        Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }
}