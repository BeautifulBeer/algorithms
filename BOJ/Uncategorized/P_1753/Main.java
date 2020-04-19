

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	
	static class Edge implements Comparable<Edge>{
		int v, weight;
		public Edge(int v, int weight) {
			super();
			this.v = v;
			this.weight = weight;
		}
		@Override
		public int compareTo(Edge o) {
			// TODO Auto-generated method stub
			return weight - o.weight;
		}
	}
	
	public static void main(String[] args) throws Exception{
		boolean flag;
		boolean[] visited;
		ArrayList<Edge>[] vertexes;
		int[] minWeight;
		int INF = Integer.MAX_VALUE;
		PriorityQueue<Edge> ts = new PriorityQueue<>();
		int V,E, start, begin, end, weight;
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(reader.readLine());
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		begin = Integer.parseInt(reader.readLine());
		vertexes = new ArrayList[V+1];
		visited = new boolean[V+1];
		minWeight = new int[V+1];
		for(int i=0; i<=V; i++) {
			minWeight[i] = INF;
		}
		minWeight[begin] = 0;
		for(int i=1; i<=V; i++) {
			vertexes[i] = new ArrayList<>();
		}
		for(int i=0; i<E; i++) {
			st = new StringTokenizer(reader.readLine());
			start = Integer.parseInt(st.nextToken());
			end = Integer.parseInt(st.nextToken());
			weight = Integer.parseInt(st.nextToken());
			flag = true;
			for(int j=0; j<vertexes[start].size(); j++) {
				if(end == vertexes[start].get(j).v) {
					if(weight < vertexes[start].get(j).weight) {
						vertexes[start].get(j).weight = weight;
					}
					flag = false;
					break;
				}
			}
			if(flag) {
				vertexes[start].add(new Edge(end, weight));
			}
		}
		ts.add(new Edge(begin, 0));
		Edge temp;
		while(!ts.isEmpty()) {
			temp = ts.poll();
			if(visited[temp.v]) {
				continue;
			}
			visited[temp.v] = true;
			for(int i=0; i<vertexes[temp.v].size(); i++) {
				if(minWeight[vertexes[temp.v].get(i).v] > temp.weight + vertexes[temp.v].get(i).weight) {
					minWeight[vertexes[temp.v].get(i).v] = temp.weight + vertexes[temp.v].get(i).weight;
					ts.add(new Edge(vertexes[temp.v].get(i).v, minWeight[vertexes[temp.v].get(i).v]));
				}
			}
		}
		for(int i=1; i<=V; i++) {
			if(minWeight[i] == INF) {
				System.out.println("INF");
			}else {
				System.out.println(minWeight[i]);	
			}
		}
	}
}
