import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {	
	
	static int N;
	static long UPPER_BOUNDARY = 9876543210L; 
	static long cache[][];
	static int map[][];
	
	static long TSP(int node, int visited) {
		if(visited == (1 << N) - 1) {
			if(map[node][0] != 0) {
				return map[node][0];
			}else {
				return UPPER_BOUNDARY;
			}
		}
		if(cache[node][visited] != 0)return cache[node][visited];
		long ret = UPPER_BOUNDARY;
		for(int i=0; i<N; i++) {
			if((visited & (1 << i)) == 0 && map[node][i] != 0) {
				ret = Math.min(ret,  TSP(i, visited | (1 << i)) + map[node][i]);
			}
		}
		return cache[node][visited] = ret;
		
	}
	
	public static void main(String[] args) throws IOException, NumberFormatException{
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(reader.readLine().trim());
		map = new int[N][N];
		cache = new long[N][1 << N];
		for(int i=0; i<N; i++) {
			Arrays.fill(cache[i], 0L);
			st = new StringTokenizer(reader.readLine().trim());
			for(int j=0; j<N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		long result = TSP(0, 1);
		System.out.println(result);
	}

}
