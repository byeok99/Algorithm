import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
    public static int solve(HashMap<String, Integer> map, int m, BufferedReader br) throws IOException {
        int ret=0;

        for (int i=0; i <m; i++) {
            String s = br.readLine();
            if (map.containsKey(s)) ret++;
        }

        return ret;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String[] str = s.split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);

        HashMap<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(br.readLine(), 0);
        }

        System.out.println(solve(map, m, br));
    }
}
