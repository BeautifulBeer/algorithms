
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

	static int N, start, from, to;
	static boolean[][] connected = new boolean[100+1][100+1];
	static boolean[] visited = new boolean[100+1];
	static PriorityQueue<Contact> pq = new PriorityQueue<>();
	static Queue<Contact> bfs = new LinkedList<>();
	
	static class Contact implements Comparable<Contact>{
		int x, length;

		public Contact(int x, int length) {
			super();
			this.x = x;
			this.length = length;
		}

		@Override
		public int compareTo(Contact o) {
			// TODO Auto-generated method stub
			return (length == o.length) ? o.x-x : o.length-length;
		}
	}
	
	public static void main(String[] args) throws IOException, NumberFormatException{
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		for(int t=1; t<=10; t++) {
			pq.clear(); bfs.clear();
			st = new StringTokenizer(reader.readLine());
			N = Integer.parseInt(st.nextToken()); start = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(reader.readLine());
			for(int i=1; i<=100; i++) {
				visited[i] = false;
				for(int j=1; j<=100; j++) {
					connected[i][j] = false;
				}
			}
			for(int i=0; i<N/2; i++) {
				from = Integer.parseInt(st.nextToken());
				to = Integer.parseInt(st.nextToken());
				connected[from][to] = true;
			}
			bfs.offer(new Contact(start, 0));
			pq.offer(new Contact(start, 0));
			visited[start] = true;
			Contact tmp, tmp2;
			while(!bfs.isEmpty()) {
				tmp = bfs.poll();
//				System.out.println("visited : " + tmp.x);
				for(int i=1; i<=100; i++) {
					if(connected[tmp.x][i] && !visited[i]) {
						tmp2 = new Contact(i, tmp.length+1);
						bfs.offer(tmp2);
						pq.offer(tmp2);
						visited[i] = true;
					}
				}
			}
			System.out.println("#"+t+" "+pq.poll().x);
		}
	}

}
