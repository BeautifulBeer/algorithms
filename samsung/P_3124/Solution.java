import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution {
	

	static class Edge implements Comparable<Edge>{
		int idx, weight;

		public Edge(int idx, int weight) {
			super();
			this.idx = idx;
			this.weight = weight;
		}

		@Override
		public int compareTo(Edge o) {
			// TODO Auto-generated method stub
			return (this.weight == o.weight)? this.idx - o.idx : this.weight - o.weight;
		}		
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		int T, V, E, start, end, weight, edgesCount;
		long sum;
		Edge temp = null;
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		boolean[] visited = new boolean[100000+1];
		ArrayList<Edge>[] edges;
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			sum = 0;
			edgesCount = 0;
			temp = null;
			pq.clear();
			st = new StringTokenizer(reader.readLine());
			V = Integer.parseInt(st.nextToken());
			E = Integer.parseInt(st.nextToken());
			edges = new ArrayList[V+1];
			Arrays.fill(visited, 0, V+1, false) ;
			for(int i=1; i<=V; i++) {
				edges[i] = new ArrayList<>();
			}
			for(int i=0; i<E; i++) {
				st = new StringTokenizer(reader.readLine());
				start = Integer.parseInt(st.nextToken());
				end = Integer.parseInt(st.nextToken());
				weight = Integer.parseInt(st.nextToken());
				//cycle loop check
				if(start == end)continue;
				temp = new Edge(end, weight);
				edges[start].add(temp);
				edges[end].add(new Edge(start, weight));
			}

			if(temp != null) {
				visited[temp.idx] = true;
				for(int i=0; i<edges[temp.idx].size(); i++) {
					pq.offer(edges[temp.idx].get(i));
				}
				
				while(!pq.isEmpty()) {
					temp = pq.poll();
					if(visited[temp.idx]) {
						continue;
					}
					visited[temp.idx] = true;
					sum += temp.weight;
					if(++edgesCount == V-1)break;
					for(int i=0; i<edges[temp.idx].size(); i++) {
						pq.offer(edges[temp.idx].get(i));
					}
				}
					System.out.println("#"+t+" "+sum);	
			//if no edges
			}else {
				System.out.println("#"+t+" "+0);
			}
		}
	}
}
