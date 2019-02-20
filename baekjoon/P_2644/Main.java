

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

	static LinkedList<Integer>[] arr;
	
	public static void main(String[] args) throws Exception{
		int n, a, b, m, level=0, qSize, v, result=-1;
		String[] tokens;
		boolean[] visited;
		Queue<Integer> queue = new LinkedList<>();
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(reader.readLine());
		tokens = reader.readLine().split("\\s");
		a = Integer.parseInt(tokens[0]);
		b = Integer.parseInt(tokens[1]);
		m = Integer.parseInt(reader.readLine());
		arr = new LinkedList[n+1];
		visited = new boolean[n+1];
		for(int i=1; i<=n; i++) {
			arr[i] = new LinkedList<>();
		}
		for(int i=0; i<m; i++) {
			tokens = reader.readLine().split("\\s");
			arr[Integer.parseInt(tokens[0])].add(Integer.parseInt(tokens[1]));
			arr[Integer.parseInt(tokens[1])].add(Integer.parseInt(tokens[0]));
		}
		queue.offer(a);
		visited[a] = true;
		loop: while(!queue.isEmpty()) {
			qSize = queue.size();
			for(int i=0; i<qSize; i++) {
				v = queue.poll();
				if(v == b) {
					result = level;
					queue.clear();
					continue loop;
				}
				for(int j=0; j<arr[v].size(); j++) {
					if(!visited[arr[v].get(j)]) {
						visited[arr[v].get(j)] = true;
						queue.offer(arr[v].get(j));
					}
				}
			}
			level++;
		}
		System.out.println(result);
	}
}
