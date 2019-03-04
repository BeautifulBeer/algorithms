import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution {

	static Block b;
	static int T, N, row, col;
	static int[][] map = new int[100+2][100+2];
	
	static class Block implements Comparable<Block>{
		int row, col, weight;

		public Block(int row, int col) {
			super();
			this.row = row;
			this.col = col;
			this.weight = row * col;
		}

		@Override
		public int compareTo(Block o) {
			// TODO Auto-generated method stub
			return (weight == o.weight)? row - o.row : weight - o.weight;
		}
		
	}
	
	static Block block(int x, int y) {
		int ex = x, ey = y;
		while(map[ex+1][ey] != 0) {
			ex++;
		}
		while(map[ex][ey+1] != 0) {
			ey++;
		}
		for(int i=x; i<=ex; i++) {
			for(int j=y; j<=ey; j++) {
				map[i][j] = 0;
			}
		} 
		return new Block(ex - x + 1, ey - y + 1);
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException{
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;
//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		PriorityQueue<Block> pq = new PriorityQueue<>();
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			sb.setLength(0);
			N = Integer.parseInt(reader.readLine());
			for(int i=1; i<=N; i++) {
				st = new StringTokenizer(reader.readLine());
				for(int j=1; j<=N; j++) {
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			for(int i=1; i<=N; i++) {
				map[N+1][i] = 0;
				map[i][N+1] = 0;
			}
			
			for(int i=1; i<=N; i++) {
				for(int j=1; j<=N; j++) {
					if(map[i][j] != 0) {
						b = block(i, j);
						pq.offer(b);
					}
				}
			}
			
			sb.append('#').append(t).append(' ').append(pq.size()).append(' ');
			while(!pq.isEmpty()) {
				b = pq.poll();
				sb.append(b.row).append(' ').append(b.col).append(' ');
			}
			sb.append('\n');
			System.out.print(sb.toString());
		}
	}
}
