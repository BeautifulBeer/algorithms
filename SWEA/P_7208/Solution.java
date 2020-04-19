
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
	
	static int T, N, min;
	static boolean connected[][] = new boolean[8][8];
	static int origin[] = new int[8];
	static int tmp[] = new int[8];
	
	static void coloring(int depth) {
		if(depth == N) {
			if(checkCondition()) {
				int count = 0;
				for(int i=0; i<N; i++) {
					if(origin[i] != tmp[i]) {
						count++;
					}
				}
				if(min > count) {
					min = count;
				}
			}
			return;
		}
		for(int i=1; i<=4; i++) {
			tmp[depth] = i;
			coloring(depth+1);
		}
	}
	
	static boolean checkCondition() {
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(connected[i][j]) {
					if(tmp[i] == tmp[j]) {
						return false;
					}
				}
			}
		}
		return true;
	}
	
	public static void main(String[] args) throws IOException, NumberFormatException{
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			min = 1000000;
			N = Integer.parseInt(reader.readLine());
			st = new StringTokenizer(reader.readLine());
			for(int i=0; i<N; i++) {
				origin[i] = Integer.parseInt(st.nextToken());
			}
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(reader.readLine());
				for(int j=0; j<N; j++) {
					connected[i][j] = (Integer.parseInt(st.nextToken()) == 1)?true:false;	
				}
			}
			
			coloring(0);
			System.out.println("#"+t+" "+min);
		}
	}

}
