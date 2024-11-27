import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static int solve(String[] Strings, int m, BufferedReader br) throws IOException {
        int ret=0;

        for (int i=0; i <m; i++) {
            String s = br.readLine();

            for (String str : Strings) {
                if (str.equals(s)) {
                    ret++;
                    break;
                }
            }
        }

        return ret;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String[] str = s.split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);

        String[] Strings = new String[n];
        for (int i = 0; i < n; i++) {
            Strings[i] = br.readLine();
        }

        System.out.println(solve(Strings, m, br));
    }
}
