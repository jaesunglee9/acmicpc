import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[][] a = new char[5][15];
        int[] len = new int[5];

        for (int i = 0; i < 5; i++) {
            String s = br.readLine();
            len[i] = s.length();
            for (int j = 0; j < s.length(); j++) {
                a[i][j] = s.charAt(j);
            }
        }

        StringBuilder sb = new StringBuilder();

        for (int c = 0; c < 15; c++) {
            for (int r = 0; r < 5; r++) {
                if (c < len[r]) sb.append(a[r][c]);
            }
        }
        System.out.println(sb);
    }
    
}