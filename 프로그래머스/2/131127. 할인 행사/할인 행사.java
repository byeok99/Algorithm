class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        
        for(int day = 0; day < discount.length; day++) {
            int[] curr = number.clone();
            
            for(int i=day; i < day + Math.min(discount.length - day, 10); i++) {
                for(int j=0; j<want.length; j++) {
                    if (discount[i].equals(want[j])) {
                        if (curr[j] - 1 >= 0) curr[j]--;
                        break;
                    }
                }
            }
            
            int chk = 0;
            for(int i=0; i < number.length; i++) {
                chk += curr[i];
            }
            
            if (chk == 0) answer++;
        }
        
        return answer;
    }
}