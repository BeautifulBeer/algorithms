import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Stack;
import java.util.StringTokenizer;

public class Solution {

	static int T, N;
	static double result;
	static double arr[][] = new double[16][16];
	static boolean checked[] = new boolean[16];
	
	static void search(int depth, double value) {
//		System.out.println(depth + " " + value);
		if(depth >= N) {
			result = Math.max(result, value);
			return;
		}
		if(result > value || value == 0)return;
		for(int i=0; i<N; i++) {
			if(!checked[i]) {
				checked[i] = true;
				search(depth+1, value*arr[depth][i]);
				checked[i] = false;
			}
		}
	}
	
	
	
	public static void main(String[] args) throws IOException, NumberFormatException{
		StringTokenizer st;
//		System.setIn(new FileInputStream("src/sample_input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			result = 0;
			N = Integer.parseInt(reader.readLine());
//			System.out.println(N);
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(reader.readLine());
				for(int j=0; j<N; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken()) * 0.01;
				}
			}
			search(0, 1);
			result = Math.round(result * 100000000.0) / 1000000.0;
			System.out.println(String.format("#%d %f",t, result));
		}
	}

}
