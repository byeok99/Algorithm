import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int[] arr = new int[9];
        int total = 0;

        for (int i = 0; i < 9; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            total += arr[i];
        }

        Arrays.sort(arr);

        outer:
        for (int i=0; i <9; i++) {
            for (int j=i+1; j<9; j++) {
                if (total - (arr[i] + arr[j]) == 100) {

                    for (int k = 0; k < 9; k++) {
                        if (k == i || k == j) continue;
                        sb.append(arr[k]).append('\n');
                    }
                    break outer;
                }
            }
        }

        System.out.println(sb);
    }
}
