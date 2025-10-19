import java.util.*; 

class Solution {
    boolean solution(String input) {
        Stack<Character> stk = new Stack<>();
        
        for (int i=0; i < input.length(); i++)
        {
            if (input.charAt(i) == '(')
                stk.push(input.charAt(i));
            else if (stk.isEmpty() || stk.pop() == input.charAt(i))
                return false; 
        }

        return stk.isEmpty();
    }
}