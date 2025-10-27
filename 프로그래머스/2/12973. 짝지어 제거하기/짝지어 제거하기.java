import java.io.*; 
import java.util.*;
class Solution
{
    public int solution(String s)
    {
        Stack<Character> stk = new Stack<>();

        for (Character c : s.toCharArray()) {
            if (stk.isEmpty()) stk.push(c);
            else if (stk.peek() != c) stk.push(c);
            else stk.pop();
        }
        if (stk.isEmpty()) return 1;
        return 0;
    }
}