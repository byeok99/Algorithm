import java.util.*; 

class Solution {
    public int solution(String s) {
        HashMap<Character, Character> map = new HashMap<>();
        map.put(')', '(');
        map.put(']', '[');
        map.put('}', '{');
        int num = s.length();
        s += s;
        int answer = 0;

        A:for (int i=0; i < num; i++) {
            Stack<Character> stk = new Stack<>();
            System.out.println(stk);
            for (int j=i; j<num + i; j++) {
                if (!map.containsKey(s.charAt(j)))
                    stk.push(s.charAt(j));
                else if (stk.isEmpty() || !stk.pop().equals(map.get(s.charAt(j)))) {
                    continue A;
                }
            }
            
            if (stk.isEmpty()) answer++;
        }
        return answer;
    }
}