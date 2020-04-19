
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {

	static String str;
	static Pos start, end;
	static int memory, R, C, T, tmpx, tmpy, direction;
	// <  : 0, > : 1, ^ : 2, v : 3
	static int delta[][] = {
			{0, -1},
			{0, 1},
			{-1, 0},
			{1, 0}
	};
	static char[][] map = new char[20][20];
	static int[][] visited = new int[20][20];
	static Queue<Pos> queue = new LinkedList<>();

	static class Pos{
		int x, y, direct;

		public Pos(int x, int y, int direct) {
			super();
			this.x = x;
			this.y = y;
			this.direct = direct;
		}


	}

	static Pos move(Pos cur) {
		Pos tmp = null;
		tmpx = cur.x + delta[cur.direct][0];
		tmpy = cur.y + delta[cur.direct][1];
		if(tmpx == -1) {
			tmpx = R-1;
		}else if(tmpx == R) {
			tmpx = 0;
		}
		if(tmpy == -1) {
			tmpy = C-1;
		}else if(tmpy == C) {
			tmpy = 0;
		}
		tmp = new Pos(tmpx, tmpy, cur.direct);
		return tmp;
	}


	static void bfs() {
		queue.clear();
		Pos tmp;
		queue.offer(start);
		while(!queue.isEmpty()) {
			tmp = queue.poll();
//			System.out.println(tmp.x + " " + tmp.y + " " + tmp.direct + " " + map[tmp.x][tmp.y] + " " + memory);
			if(visited[tmp.x][tmp.y] == 16)continue;
			visited[tmp.x][tmp.y]++;
			direction = tmp.direct;
			if(map[tmp.x][tmp.y] != '?') {
				if(map[tmp.x][tmp.y] == '<') {
					direction = 0;
				}else if( map[tmp.x][tmp.y] == '>'){
					direction = 1;
				}else if(map[tmp.x][tmp.y] == '^'){
					direction = 2;
				}else if(map[tmp.x][tmp.y] == 'v'){
					direction = 3;
				}else if(map[tmp.x][tmp.y] == '_') {
					if(memory == 0) {
						direction = 1;
					}else {
						direction = 0;
					}
				}else if(map[tmp.x][tmp.y] == '|') {
					if(memory == 0) {
						direction = 3;
					}else {
						direction = 2;
					}
				}else if(map[tmp.x][tmp.y] >= '0' && map[tmp.x][tmp.y] <= '9') {
					memory = map[tmp.x][tmp.y] - '0';
				}else if(map[tmp.x][tmp.y] == '@') {
					end.x = 1; end.y = 1;
					return;
				}else if(map[tmp.x][tmp.y] == '+') {
					if(memory == 15) {
						memory = 0;
					}else {
						memory++;
					}
				}else if(map[tmp.x][tmp.y] == '-') {
					if(memory == 0) {
						memory = 15;
					}else {
						memory--;
					}
				}
				tmp.direct = direction;
				queue.offer(move(tmp));
			}else {
				for(int i=0; i<4; i++) {
					tmp.direct = i;
					queue.offer(move(tmp));
				}
			}
		}
	}


	public static void main(String[] args) throws IOException, NumberFormatException{
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		start = new Pos(0, 0, 1);
		end = new Pos(1, 1, 0);
		for(int t=1; t<=T; t++) {
			start.x = 0; start.y = 0; start.direct = 1; memory = 0;
			end.x = -1; end.y = -1;
			st = new StringTokenizer(reader.readLine());
			R = Integer.parseInt(st.nextToken()); C = Integer.parseInt(st.nextToken());
			for(int i=0; i<R; i++) {
				str = reader.readLine();
				for(int j=0; j<C; j++) {
					map[i][j] = str.charAt(j);
					visited[i][j] = 0;
				}
			}
			bfs();
			if(end.x == -1) {
				System.out.println("#"+t+" NO");
			}else {
				System.out.println("#"+t+" YES");
			}
		}

	}

}
