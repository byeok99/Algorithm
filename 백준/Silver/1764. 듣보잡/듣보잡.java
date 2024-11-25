import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static String[] solve(String[] word, String[] word2) {
        List<String> result = new ArrayList<>();
        Map<String, Boolean> map = new HashMap<>();
        for (String s : word) map.put(s, true);
        for (String s : word2) {
            if(map.containsKey(s)){
                result.add(s);
            }
        }

        return result.toArray(new String[result.size()]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] num = br.readLine().split(" ");

        int n = Integer.parseInt(num[0]);
        int m = Integer.parseInt(num[1]);

        String[] words = new String[n];
        String[] words2 = new String[m];

        for (int i = 0; i < n; i++) {
            words[i] = br.readLine();
        }
        for (int i = 0; i < m; i++) {
            words2[i] = br.readLine();
        }
        String[] result = solve(words, words2);
        Arrays.sort(result);
        System.out.println(result.length);
        for (String s : result) {
            System.out.println(s);
        }

    }
}
