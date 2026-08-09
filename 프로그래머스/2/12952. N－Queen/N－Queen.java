class Solution {
    static int N;
    static int[][] map; 
    static int answer = 0;
    
    static boolean check(int r, int c) {
        // 세로
        for(int i=0; i<r; i++) {
            if (i != r && map[i][c] == -1) return false;
        }
        
        // 가로
        for(int i=0; i<N; i++) {
            if (i != c && map[r][i] == -1) return false;
        }
        
       // 대각
        int[] dy = {-1, -1, 1, 1};
        int[] dx = {-1, 1, -1, 1};
        for (int d = 0; d < 4; d++) {
            int y = r + dy[d];
            int x = c + dx[d];
            while (y >= 0 && y < N && x >= 0 && x < N) {
                if (map[y][x] == -1) return false;
                y += dy[d];
                x += dx[d];
            }
        }
        
        return true;
    }
    
    static void solve(int r) {
        if (r == N) { answer++; return; }
        for (int c = 0; c < N; c++) {
            if (!check(r, c)) continue;
            map[r][c] = -1;
            solve(r + 1);
            map[r][c] = 0;
        }
    }
    
    public int solution(int n) {
        N = n;
        map = new int[N][N];
        
        solve(0);
        
        return answer;
    }
}