import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		int max, tmp;
		int[][] arr;
		int N, M, K;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(reader.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		max = 0;
		arr = new int[N+1][M+1];
		for(int i=0; i<K; i++) {
			st = new StringTokenizer(reader.readLine());
			arr[Integer.parseInt(st.nextToken())
			    ][Integer.parseInt(st.nextToken())] = 1;
		}
		
//		printArr(arr, N, M);
		
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=M; j++) {
				if(arr[i][j] == 1) {
					tmp = dfs(arr, i, j);
					if(max < tmp) {
						max = tmp;
//						System.out.println("max : "+ max);
					}
//					printArr(arr, N, M);
				}
			}
		}
		System.out.println(max);
	}
	static void printArr(int[][] arr, int N, int M) {
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=M; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}
	static int dfs(int[][] arr, int ridx, int cidx) {
		if(ridx <= 0 || ridx >= arr.length ||
				cidx <= 0 || cidx >= arr[0].length || arr[ridx][cidx] != 1) {
			return 0;
		}
		arr[ridx][cidx] = -1;
		return 1 + dfs(arr, ridx-1, cidx) +
				dfs(arr, ridx+1, cidx) +
				dfs(arr, ridx, cidx+1) +
				dfs(arr, ridx, cidx-1);
	}

}