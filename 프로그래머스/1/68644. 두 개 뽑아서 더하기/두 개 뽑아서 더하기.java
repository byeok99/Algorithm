import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        ArrayList<Integer> answer = new ArrayList<>();

        for (int i=0; i<numbers.length; i++) {
            for (int j=i+1; j<numbers.length; j++) {
                answer.add(numbers[i] + numbers[j]);
            }
        }

        return answer.stream().sorted().distinct().mapToInt(Integer::intValue).toArray();
    }
}

