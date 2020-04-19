import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {	
	static int[][] dxy = {{0,-1},{-1,0},{0,1},{1,0}};
	static char[][] map = new char[10][10];
	static int irx, iry, ibx, iby, hx, hy, N, M;
	static boolean[][][][] visited = new boolean[10][10][10][10];
	static class Ball{
		int depth;
		int rx, ry, bx, by;
		
		public Ball(int depth, int rx, int ry, int bx, int by) {
			super();
			this.depth = depth;
			this.rx = rx;
			this.ry = ry;
			this.bx = bx;
			this.by = by;
		}
	}
	
	public static void move(Ball ball, int direct) {
//		System.out.println("direction : " + direct + " / (" + dxy[direct][0] + " / " + dxy[direct][1] + " )");
		while(true) {
			ball.rx += dxy[direct][0]; ball.ry += dxy[direct][1];
			if(map[ball.rx][ball.ry] == '#') {
				ball.rx -= dxy[direct][0]; ball.ry -= dxy[direct][1];
				break;
			}
			if(map[ball.rx][ball.ry] == 'O') {
				break;
			}
//			System.out.println(ball.rx + " , " + ball.ry + " , " + ball.bx + " , " + ball.by);

		}
		while(true) {
			ball.bx += dxy[direct][0]; ball.by += dxy[direct][1];
			if(map[ball.bx][ball.by] == '#') {
				ball.bx -= dxy[direct][0]; ball.by -= dxy[direct][1];
				break;
			}
			if(map[ball.bx][ball.by] == 'O') {
				break;
			}
//			System.out.println(ball.rx + " , " + ball.ry + " , " + ball.bx + " , " + ball.by);

		}
	}
	
	public static void main(String[] args) throws Exception{
		int result = -1;
		String str;
		StringTokenizer st;
		Queue<Ball> queue = new LinkedList<>();
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(reader.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		for(int i=0; i<N; i++) {
			str = reader.readLine();
			for(int j=0; j<str.length(); j++) {
				map[i][j] = str.charAt(j);
				if(map[i][j] == 'R') {
					irx = i; iry = j;
				}else if(map[i][j] == 'B') {
					ibx = i; iby = j;
				}else if(map[i][j] == 'O') {
					hx = i; hy = j;
				}
			}
		}
		
		visited[irx][iry][ibx][iby] = true;
		queue.offer(new Ball(0, irx, iry, ibx, iby));
//		System.out.println("offed");
		Ball tmp;
		Loop: while(!queue.isEmpty()) {
			tmp = queue.poll();
			irx = tmp.rx; iry = tmp.ry; ibx = tmp.bx; iby = tmp.by;
			if(tmp.depth == 10) {
				break;
			}
			for(int i=0; i<4; i++) {
				move(tmp, i);
//				System.out.println(tmp.rx + " , " + tmp.ry + " , " + tmp.bx + " , " + tmp.by);
				if(tmp.bx == hx && tmp.by == hy) {
					tmp.rx = irx; tmp.ry = iry; tmp.bx = ibx; tmp.by = iby;
					continue;
				}
				if(tmp.rx == hx && tmp.ry == hy) {
					result = tmp.depth + 1;
					break Loop;
				}
				if(tmp.rx == tmp.bx && tmp.ry == tmp.by) {
					//left
					if(i == 0) {
						if(iry > iby) {
							tmp.ry++;
						}else {
							tmp.by++;
						}
					//up
					}else if(i == 1) {
						if(irx > ibx) {
							tmp.rx++;
						}else {
							tmp.bx++;
						}
					//right
					}else if(i == 2) {
						if(iry > iby) {
							tmp.by--;
						}else {
							tmp.ry--;
						}
					//down
					}else if(i == 3) {
						if(irx > ibx) {
							tmp.bx--;
						}else {
							tmp.rx--;
						}
					}
				}
				if(!visited[tmp.rx][tmp.ry][tmp.bx][tmp.by]) {
					queue.offer(new Ball(tmp.depth+1, tmp.rx, tmp.ry, tmp.bx, tmp.by));
				}
				tmp.rx = irx; tmp.ry = iry; tmp.bx = ibx; tmp.by = iby;
			}
		}
		System.out.println(result);
	}
}
