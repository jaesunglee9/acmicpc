import java.util.*;
import java.io.*;


public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int v = Integer.parseInt(br.readLine());

        int count = 0;
        for (int i = 0; i < n; i++) {
            int number = Integer.parseInt(st.nextToken());
            if (number == v) {
                count += 1;
            }
        }
        System.out.println(count);
    }
}
