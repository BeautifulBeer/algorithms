import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

	static int N, T, B, sx, sy;
	static int max = 0;
	static int[][] map = new int[50+1][50+1];
	
	static void coverage(int x, int y) {
		int i;
		if(x > 1) {
			for(i=x-1; i > x-3 && i>=1; i--) {
				map[i][y]++;
			}
		}
		if(y > 1) {
			for(i=y-1; i > y-3 && i>=1; i--) {
				map[x][i]++;
			}
		}
		if(x < N) {
			for(i=x+1; i < x + 3 && i<=N; i++) {
				map[i][y]++;
			}
		}
		if(y < N-1) {
			for(i=y+1; i < y + 3 && i<=N; i++) {
				map[x][i]++;
			}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException{
		StringTokenizer st;
//		System.setIn(new FileInputStream("src/sampleInput.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine().trim());
		for(int t=1; t<=T; t++) {
			max = 0;
			st = new StringTokenizer(reader.readLine().trim());
			N = Integer.parseInt(st.nextToken()); B = Integer.parseInt(st.nextToken());
			for(int i=1; i<=N; i++) {
				for(int j=1; j<=N; j++) {
					map[i][j] = 0;
				}
			}
			for(int i=0; i<B; i++) {
				st = new StringTokenizer(reader.readLine().trim());
				sx = Integer.parseInt(st.nextToken()); sy = Integer.parseInt(st.nextToken());
				map[sx][sy] -= 31;
				coverage(sx, sy);
			}
			for(int i=1; i<=N; i++) {
				for(int j=1; j<=N; j++) {
//					System.out.print(map[i][j] + " ");
					if(max < map[i][j]) {
						max = map[i][j];
					}
				}
//				System.out.println();
			}
			System.out.println("#"+t+" "+max);
		}
	}
}
