import java.util.*; 

class Solution {
    public int solution(int[][] board, int[] moves) {
        Stack<Integer>[] lines = new Stack[board.length];

        for (int i=0; i<board.length; i++) {
            lines[i] = new Stack<>();
        }

        for (int i = board.length-1; i >= 0; i--) {
            for (int j=0; j<board[i].length; j++) {
                if (board[i][j] > 0) {
                    lines[j].push(board[i][j]);
                }
            }
        }

        Stack<Integer> stk = new Stack<>();
        int ret =0;

        for (int move : moves) {
            if (!lines[move-1].isEmpty()) {
                int doll = lines[move-1].pop();

                if (!stk.isEmpty() && stk.peek() == doll) {
                    stk.pop();
                    ret += 2;
                } else {
                    stk.push(doll);
                }
            }
        }

        return ret;
    }
}