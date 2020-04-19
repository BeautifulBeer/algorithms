import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	static long sum, num;
	static int T, N, a, b;
	static int[][] worms = new int[20][2];
	
	static class Paths{
		int depth;
		long x, y;
		int length;
		int minusLength;
		
		public Paths(int depth, long x, long y, int length, int minusLength) {
			super();
			this.depth = depth;
			this.x = x;
			this.y = y;
			this.length = length;
			this.minusLength = minusLength;
		}
		
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException{
		StringTokenizer st;
		Queue<Paths> queue = new LinkedList<>();
//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			sum = Long.MAX_VALUE;
			N = Integer.parseInt(reader.readLine());
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(reader.readLine());
				a = Integer.parseInt(st.nextToken()); b = Integer.parseInt(st.nextToken());
				worms[i][0] = a; worms[i][1] = b;
			}
			Paths tmp;
			queue.add(new Paths(0, 0, 0, 0, 0));
			while(!queue.isEmpty()) {
				tmp = queue.poll();
				if(tmp.length == N/2) {
					for(int i=tmp.depth; i<N; i++) {
						tmp.x -= worms[i][0];
						tmp.y -= worms[i][1];
					}
					num = tmp.x * tmp.x + tmp.y * tmp.y;
					if(sum > num) {
						sum = num;
					}
					continue;
				}else if(tmp.minusLength == N/2) {
					for(int i=tmp.depth; i<N; i++) {
						tmp.x += worms[i][0];
						tmp.y += worms[i][1];
					}
					num = tmp.x * tmp.x + tmp.y * tmp.y;
					if(sum > num) {
						sum = num;
					}
					continue;
				}
				queue.offer(new Paths(tmp.depth+1,
						tmp.x + worms[tmp.depth][0],
						tmp.y + worms[tmp.depth][1],
						tmp.length+1, tmp.minusLength));
				queue.offer(new Paths(tmp.depth+1,
						tmp.x - worms[tmp.depth][0],
						tmp.y - worms[tmp.depth][1],
						tmp.length, tmp.minusLength+1));
			}
			System.out.println("#"+t+" "+sum);
		}
		
	}
}
