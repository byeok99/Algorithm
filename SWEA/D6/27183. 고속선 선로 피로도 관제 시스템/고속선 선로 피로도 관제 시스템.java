import java.io.*;
import java.util.Arrays;

public class Solution {
	static int[] tree;
	static int[] lazyAdd;
	static int[] lazySet; 
	static int n;
	
    /*=========================================================
      여기서부터 5개 메서드만 구현하시오.
      main 및 입출력 부분은 수정하지 않는 것을 권장한다.

      init      : 각 테스트 케이스 시작 시 1회 호출. 전역 자료 구조 초기화.
      addStress : 구간 [l,r] 의 모든 구간 피로도를 w 만큼 증가(range add).
      repair    : 구간 [l,r] 을 v 로 재설정(range assign, v=0 가능).
      getPeak   : 구간 [l,r] 의 최대 피로도 반환(range max).
      findRisk  : 구간 [l,r] 에서 값 >= x 인 가장 왼쪽 인덱스 반환, 없으면 -1.
    =========================================================*/

    static void init(int N, int[] fatigue) {
        // TODO: fatigue[0..N-1] = 초기 피로도. 전역 자료 구조를 반드시 초기화할 것.
    	n = N; 
    	tree = new int[4 * N];
    	lazyAdd = new int[4 * N];
    	lazySet = new int[4 * N];
    	Arrays.fill(lazySet, Integer.MAX_VALUE);
    	build(fatigue, 1, 0, N-1);
    }
    
    static void build(int[] arr, int node, int s, int e) {
    	if (s == e) {
    		tree[node] = arr[s];
    		return;
    	}
    	
    	int mid = (s + e) / 2;
    	
    	build(arr, node * 2, s, mid);
    	build(arr, node * 2 + 1, mid + 1, e);
    	tree[node] = Math.max(tree[node * 2], tree[node * 2 + 1]);
    }
    
    static void addStress(int l, int r, int w) {
        // TODO: 구간 [l,r] 에 피로도 w 누적
    	add(1, 0, n-1, l, r, w);
    }

    private static void add(int node, int s, int e, int l, int r, int w) {
		// TODO Auto-generated method stub
		pushSet(node, s, e);
		pushAdd(node, s, e);
		if (r < s || e < l) return;
		if (s >= l && e <= r) {
			lazyAdd[node] += w;
			pushAdd(node, s, e);
			return;
		}
		
		int mid = (s + e) / 2;
		add(node * 2, s, mid, l, r, w);
		add(node * 2 + 1, mid + 1, e, l, r, w);
    	tree[node] = Math.max(tree[node * 2], tree[node * 2 + 1]);
	}

	static void repair(int l, int r, int v) {
        // TODO: 구간 [l,r] 을 v 로 재설정
		set(1, 0, n-1, l, r, v);
    }
	
	private static void set(int node, int s, int e, int l, int r, int w) { 
		pushAdd(node, s, e);
		pushSet(node, s, e);
		if (r < s || e < l) return; 
		if (s >= l && e <= r) {
			lazySet[node] = w;
			pushSet(node, s, e);
			return;
		}
		
		int mid = (s + e) / 2;
		set(node * 2, s, mid, l, r, w);
		set(node * 2 + 1, mid + 1, e, l, r, w);
		tree[node] = Math.max(tree[node*2], tree[node * 2 + 1]);
	}

    static int getPeak(int l, int r) {
        // TODO: 구간 [l,r] 의 최대 피로도 반환
        return query(1, 0, n - 1, l, r);
    }
    
    private static int query(int node, int s, int e, int l, int r) {
    	if (r < s || e < l) return 0;
    	pushSet(node, s, e);
    	pushAdd(node, s, e);
    	if (s >= l && e <= r) return tree[node];
    	int mid = (s + e) / 2;
    	return Math.max(
    			query(node * 2, s, mid, l, r),
    			query(node * 2 + 1, mid + 1, e, l, r)
    			);
    }
    
    static int findRisk(int l, int r, int x) {
        // TODO: 구간 [l,r] 에서 값 >= x 인 최소 인덱스 반환, 없으면 -1
        
    	return queryMinIdx(1, 0, n - 1, l, r, x);
    }
    
    private static int queryMinIdx(int node, int s, int e, int l, int r, int x) {
    	if (r < s || e < l) return -1;

    	pushSet(node, s, e);
    	pushAdd(node, s, e);
    	
    	if (tree[node] < x) return -1;
    	if (s == e) return s;
    	
    	int mid = (s + e) / 2;
    	int left = queryMinIdx(node * 2, s, mid, l, r, x);
    	if (left != -1) return left;
    	return queryMinIdx(node * 2 + 1, mid + 1, e, l, r, x);
	}

	static void pushAdd(int node, int s, int e) {
    	if (lazyAdd[node] == 0) return;
    	
    	tree[node] += lazyAdd[node];
    	if (s != e) {
    		lazyAdd[node * 2] += lazyAdd[node];
    		lazyAdd[node * 2 + 1] += lazyAdd[node];
    	}

    	lazyAdd[node] = 0;
    }
	
	static void pushSet(int node, int s, int e) {
		if (lazySet[node] == Integer.MAX_VALUE) return;
		
		tree[node] = lazySet[node];
		
		if (s != e) {
			lazySet[node * 2] = lazySet[node];
			lazySet[node * 2 + 1] = lazySet[node];
		}
		
		lazySet[node] = Integer.MAX_VALUE;
	}
    
    /*========= 이하 수정 비권장 (출력 형식 유지) =========*/
    public static void main(String[] args) throws IOException {
        StreamTokenizer in = new StreamTokenizer(
                new BufferedReader(new InputStreamReader(System.in)));
        StringBuilder sb = new StringBuilder();
        in.nextToken();
        int T = (int) in.nval;
        for (int tc = 1; tc <= T; tc++) {
            in.nextToken(); int N = (int) in.nval;
            in.nextToken(); int M = (int) in.nval;
            int[] fatigue = new int[N];
            for (int i = 0; i < N; i++) {
                in.nextToken();
                fatigue[i] = (int) in.nval;
            }
            init(N, fatigue);
            sb.append('#').append(tc).append('\n');
            for (int q = 0; q < M; q++) {
                in.nextToken(); int op = (int) in.nval;
                if (op == 1) {
                    in.nextToken(); int l = (int) in.nval;
                    in.nextToken(); int r = (int) in.nval;
                    in.nextToken(); int w = (int) in.nval;
                    addStress(l, r, w);
                } else if (op == 2) {
                    in.nextToken(); int l = (int) in.nval;
                    in.nextToken(); int r = (int) in.nval;
                    in.nextToken(); int v = (int) in.nval;
                    repair(l, r, v);
                } else if (op == 3) {
                    in.nextToken(); int l = (int) in.nval;
                    in.nextToken(); int r = (int) in.nval;
                    sb.append(getPeak(l, r)).append('\n');
                } else {
                    in.nextToken(); int l = (int) in.nval;
                    in.nextToken(); int r = (int) in.nval;
                    in.nextToken(); int x = (int) in.nval;
                    sb.append(findRisk(l, r, x)).append('\n');
                }
            }
        }
        System.out.print(sb);
    }
}