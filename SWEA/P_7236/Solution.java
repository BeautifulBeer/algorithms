import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	
	static int T, N, max, depth, tmpx, tmpy;
	static char map[][] = new char[100][100];
	static int delta[][] = {
			{-1, -1},
			{-1, 0},
			{-1, 1},
			{0, -1},
			{0, 1},
			{1, -1},
			{1, 0},
			{1, 1}
	}; 
	
	public static void main(String[] args) throws NumberFormatException, IOException{
//		System.setIn(new FileInputStream("src/input.txt"));
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			max = 0;
			N = Integer.parseInt(reader.readLine());
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(reader.readLine());
				for(int j=0; j<N; j++) {
					map[i][j] = st.nextToken().charAt(0);
				}
			}
			/*for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					System.out.print(map[i][j]);
				}
				System.out.println();
			}*/
			outer: for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					if(map[i][j] == 'G')continue;
					depth = 0;
					for(int k=0; k<8; k++) {
						tmpx = i + delta[k][0];
						tmpy = j + delta[k][1];
						if(tmpx < 0 || tmpx >= N || tmpy < 0 || tmpy >= N) {
							continue;
						}
						if(map[tmpx][tmpy] == 'W') {
							depth++;
						}
					}
					if(depth == 0)depth = 1;
					if(max < depth)max = depth;
					if(max == 8)break outer;
				}
			}
			System.out.println("#"+t+" "+max);
		}
	}
}
