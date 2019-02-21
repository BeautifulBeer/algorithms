import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution {
	static int parent[] = new int[1000];
	static class Edge implements Comparable<Edge>{
		int start, end;
		double weight;
		
		public Edge(int start, int end, double weight) {
			super();
			this.start = start;
			this.end = end;
			this.weight = weight;
		}
		
		@Override
		public int compareTo(Edge o) {
			// TODO Auto-generated method stub
			if(weight > o.weight) {
				return 1;
			}else if(weight == o.weight){
				return 0;
			}else {
				return -1;
			}
		}		
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		int T,x,y,N;
		double e, result;
		int map[][] = new int[1000][2];
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		StringTokenizer stX;
		StringTokenizer stY;
//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			pq.clear();
			result = 0;
			N = Integer.parseInt(reader.readLine());
			System.out.println(N);
			for(int i=0; i<N; i++) {
				makeSet(i);
			}
			stX = new StringTokenizer(reader.readLine());
			stY = new StringTokenizer(reader.readLine());
			for(int i=0; i<N; i++) {
				x = Integer.parseInt(stX.nextToken());
				y = Integer.parseInt(stY.nextToken());
				map[i][0] = x;
				map[i][1] = y;
			}
			e = Double.parseDouble(reader.readLine());
			for(int i=0; i<N; i++) {
				for(int j=0; j<N; j++) {
					pq.offer(new Edge(
							i,
							j,
							Math.pow(map[i][0] - map[j][0], 2) + Math.pow(map[i][1] - map[j][1], 2)));					
				}
			}
			Edge temp;
			int count = 0;
			while(count != N-1) {
				temp = pq.poll();
				if(findSet(temp.start) != findSet(temp.end)) {
					unionSet(temp.start, temp.end);
					result += temp.weight;
					count++;
				}
			}
			System.out.println("#"+t+" "+Math.round(result * e));
		}
	}
	
	public static void makeSet(int x) {
		parent[x] = x;
	}
	
	public static void unionSet(int x, int y) {
		int a = findSet(x);
		int b = findSet(y);
		if(a == b) {
			return;
		}
		parent[b] = a; 
	}
	
	public static int findSet(int x) {
		if(parent[x] == x) {
			return x;
		}
		int a = findSet(parent[x]);
		parent[x] = a;
		return a;
	}
}
