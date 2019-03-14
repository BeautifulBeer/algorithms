import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static long result;
	static long[][][] cache = new long[3][32][32];
	static int[][] map = new int[32][32];
	
	
	public static void main(String[] args) throws IOException, NumberFormatException{
		// TODO Auto-generated method stub
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(reader.readLine());
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(reader.readLine());
			for(int j=0; j<N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		for(int i=1; i<N; i++) {
			if(map[0][i] == 1)break;
			cache[0][0][i] = 1;

		}
		for(int i=1; i<N; i++) {
			for(int j=1; j<N; j++) {
				if(map[i][j] == 1) {
					continue;
				}	
				
				cache[0][i][j] += cache[0][i][j-1] + cache[2][i][j-1];
				cache[1][i][j] += cache[1][i-1][j] + cache[2][i-1][j];					
				
				if(map[i-1][j] == 0 && map[i][j-1] == 0) {
					cache[2][i][j] += cache[2][i-1][j-1] + cache[1][i-1][j-1] + cache[0][i-1][j-1];	
				}
			}
		}

		result = cache[0][N-1][N-1] + cache[1][N-1][N-1] + cache[2][N-1][N-1];
		System.out.println(result);
	}

}
