import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 
 * @author Kwanwoong Yoon
 *
 */
public class Solution {

	public static void main(String[] args) throws Exception{
		int testCase, N, idx;
		StringTokenizer st;
		int[][] arr = new int[7][7];
//		BufferedReader reader = new BufferedReader(new FileReader("src\\input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			N = Integer.parseInt(reader.readLine());
			// load data
			for(int j=0; j<N; j++) {
				st = new StringTokenizer(reader.readLine());
				idx = 0;
				while(st.hasMoreTokens()) {
					arr[j][idx] = Integer.parseInt(st.nextToken());
					idx++;
				}
			}
			System.out.println("#"+i);
			for(int j=0; j<N; j++) {
				for(int k=N-1; k>=0; k--) {
					System.out.print(arr[k][j]);
				}
				System.out.print(" ");
				
				for(int k=N-1; k>=0; k--) {
					System.out.print(arr[N-(j+1)][k]);
				}
				System.out.print(" ");
				
				for(int k=0; k<N; k++) {
					System.out.print(arr[k][N-(j+1)]);
				}
				System.out.println();
			}
		}
	}
}
