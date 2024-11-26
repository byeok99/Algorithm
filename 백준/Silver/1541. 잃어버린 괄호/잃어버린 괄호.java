import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {

    public static int solve(List<String> strList) {
        int ret = 0;
        int current = 0;
        boolean isNegative = false;

        for (String str : strList) {
            if (str.equals("+")) {
                continue;
            } else if(str.equals("-")) {
                if (isNegative) {
                    ret -= current;
                } else if (!isNegative) {
                    ret += current;
                }
                current = 0;
                isNegative = true;
            } else {
                current += Integer.parseInt(str);
            }
        }

        if (isNegative) {
            ret -= current;
        } else {
            ret += current;
        }

        return ret;
    }

    public static List<String> cSplit(String s) {
        List<String> str = new ArrayList<>();

        int startIdx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '-' || s.charAt(i) == '+') {
                str.add(s.substring(startIdx, i));
                str.add(s.substring(i, i+1));
                startIdx = i + 1;
            }
        }
        str.add(s.substring(startIdx));

        return str;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        List<String> str = cSplit(s);
        System.out.println(solve(str));

    }
}
