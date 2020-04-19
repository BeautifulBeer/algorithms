import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {

	public static void main(String[] args) throws Exception {
		int x, y, T, N;
		int tmp;
		int[] dx = {0, 1, 0, -1};
		int[] dy = {1, 0, -1, 0};
		int[][] result;
		boolean[][] visited;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		T = Integer.parseInt(reader.readLine());
		for(int testCase=1; testCase<=T; testCase++) {
			x = 0;
			y = 0;
			tmp = 0;
			N = Integer.parseInt(reader.readLine());
			result = new int[N][N];
			visited = new boolean[N][N];
			for(int i=1; i<=N*N; i++) {
				result[x][y] = i;
				if(x+dx[tmp] < 0 || x+dx[tmp] >= N || y+dy[tmp] < 0 || y+dy[tmp] >= N || visited[x+dx[tmp]][y+dy[tmp]]) {
					tmp = (tmp + 1) % 4;
				}
				visited[x][y] = true;
				x += dx[tmp];
				y += dy[tmp];
			}

			System.out.println("#" + testCase);
			for(int i=0; i<result.length; i++) {
				for(int j=0; j<result[i].length; j++) {
					System.out.print(result[i][j] + " ");
				}
				System.out.println();
			}
		}

	}
}







