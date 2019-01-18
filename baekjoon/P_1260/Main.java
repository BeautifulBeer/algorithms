import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;

public class Main {

	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int N, M, V;
		int tmp_a, tmp_b;
		boolean[] visited = new boolean[1000+1];
		boolean[][] links = new boolean[1000+1][1000+1];
		String[] tokens;
		Deque<Integer> dq = new LinkedList<Integer>();
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		tokens = reader.readLine().split("\\s");
		N = Integer.parseInt(tokens[0]);
		M = Integer.parseInt(tokens[1]);
		V = Integer.parseInt(tokens[2]);
		for(int i=0; i<M; i++) {
			tokens = reader.readLine().split("\\s");
			tmp_a = Integer.parseInt(tokens[0]);
			tmp_b = Integer.parseInt(tokens[1]);
			links[tmp_a][tmp_b] = true;
			links[tmp_b][tmp_a] = true;
		}
		//DFS
		dq.addFirst(V);
		while(!dq.isEmpty()) {
			tmp_a = dq.removeFirst();
			if(!visited[tmp_a]) {
				System.out.print(tmp_a + " ");
				visited[tmp_a] = true;
			}
			for(int i=1; i<visited.length; i++) {
				if(!visited[i] && links[tmp_a][i]) {
					dq.addFirst(tmp_a);
					dq.addFirst(i);
					break;
				}
			}
		}
		System.out.println();
		for(int i=1; i<visited.length; i++) {
			visited[i] = false;
		}
		
		dq.clear();

		//BFS
		dq.addLast(V);
		while(!dq.isEmpty()) {
			tmp_a = dq.removeFirst();
			if(!visited[tmp_a]) {
				System.out.print(tmp_a + " ");
				visited[tmp_a] = true;
			}
			for(int i=1; i<visited.length; i++) {
				if(!visited[i] && links[tmp_a][i]) {
					dq.addLast(i);
				}
			}
		}
	}
	
}
