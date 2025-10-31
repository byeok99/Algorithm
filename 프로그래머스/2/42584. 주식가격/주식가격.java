import java.util.*; 

class Solution {
    public static int[] solution(int[] prices) {
        int[] ans = new int[prices.length];
        Stack<Integer> stk = new Stack<>();

        for (int i=0; i<prices.length; i++) {
            while (!stk.isEmpty() && prices[i] < prices[stk.peek()]) {
                int idx = stk.pop();
                ans[idx] = i - idx;
            }
            stk.push(i);
        }

        while (!stk.isEmpty()) {
            int idx = stk.pop();
            ans[idx] = prices.length - idx - 1;
        }

        return ans;
    }
}