import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {

	static Pos tmp;
	static String str;
	static int T, N, click, mx, my;
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
	static char map[][] = new char[300+2][300+2];
	static boolean visited[][] = new boolean[300+2][300+2];
	static Queue<Pos> queue = new LinkedList<>();

	static class Pos{
		int x, y;

		public Pos(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		
	}
	
	static char getMine(int x, int y) {
		int result = 0;
		for(int i=0; i<8; i++) {
			if(map[x + delta[i][0]][y + delta[i][1]] == '*') {
				result++;
			}
		}
		return (char) (result + '0');
	}
	
	static void bfs(int x, int y) {
		queue.clear();
		queue.offer(new Pos(x, y));
		while(!queue.isEmpty()) {
			tmp = queue.poll();
			if(visited[tmp.x][tmp.y]) {
				continue;
			}
			visited[tmp.x][tmp.y] = true;
			if(map[tmp.x][tmp.y] == '.') {
				map[tmp.x][tmp.y] = getMine(tmp.x, tmp.y);	
			}
			if(map[tmp.x][tmp.y] == '0') {
				for(int i=0; i<8; i++) {
					mx = tmp.x + delta[i][0];
					my = tmp.y + delta[i][1];
					if(map[mx][my] == '.') {
						map[mx][my] = getMine(mx, my);
					}
					// if is zero
					if(map[mx][my] == '0') {
						queue.offer(new Pos(mx, my));
					}
				}
			}
		}
	}
	
	
	public static void main(String[] args) throws NumberFormatException, IOException{
//		System.setIn(new FileInputStream("src/input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		// set boundary
		for(int i=0; i<=301; i++) {
			map[0][i] = 'x';
			map[i][0] = 'x';
			map[301][i] = 'x';
			map[i][301] = 'x';
		}
		for(int t=1; t<=T; t++) {
			// initialize
			click = 0;
			N = Integer.parseInt(reader.readLine());
			for(int i=1; i<=N; i++) {
				str = reader.readLine();
				for(int j=1; j<=N; j++) {
					map[i][j] = str.charAt(j-1);
					visited[i][j] = false;
				}
				map[0][i] = 'x';
				map[i][0] = 'x';
				map[N+1][i] = 'x';
				map[i][N+1] = 'x';
				
				visited[0][i] = false;
				visited[i][0] = false;
				visited[N+1][i] = false;
				visited[i][N+1] = false;
			}
			map[0][0] = 'x';
			map[N+1][N+1] = 'x'; // end initialize
			visited[0][0] = false;
			visited[N+1][N+1] = false;
			
			for(int i=1; i<=N; i++) {
				for(int j=1; j<=N; j++) {
					if(map[i][j] == '.' && getMine(i,j) == '0') {
						bfs(i,j);	
						click++;
					}	
				}
			}
			
			for(int i=1; i<=N; i++) {
				for(int j=1; j<=N; j++) {
					if(map[i][j] == '.') {
						bfs(i,j);	
						click++;
					}
				}
			}
			
			System.out.println("#"+t+" "+click);
		}
	}
}
