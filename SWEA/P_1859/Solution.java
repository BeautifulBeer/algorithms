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
		int[] freq = new int[10000 + 1]; // to count frequency of input price data
		int[] data = new int[1000000]; // array for input data
		int testCase, N, tmp_idx, count;
		long totalProfit, totalCost;
		StringTokenizer st;
//		BufferedReader reader = new BufferedReader(new FileReader("src\\input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			totalCost = 0;
			totalProfit = 0;
			count = 0;
			N = Integer.parseInt(reader.readLine());
			st = new StringTokenizer(reader.readLine());
			tmp_idx = 0;
			// init frequency array
			for(int j=0; j<10001; j++) {
				freq[j] = 0;
			}
			while(st.hasMoreTokens()) {
				data[tmp_idx] = Integer.parseInt(st.nextToken());
//				System.out.println(data[tmp_idx]);
				freq[data[tmp_idx]]++;
				tmp_idx++;
			}
			tmp_idx = 0;
			for(int j=10000; j>0; j--) {
				while(freq[j] != 0) {
					for(int k=tmp_idx; k<N; k++) {
						if(j == data[k]) {
							if(count != 0)totalProfit += data[k] * count - totalCost;
//							System.out.println("totalProfit : " + totalProfit + "," + data[k] + "," + count + "," + totalCost);
							tmp_idx = k + 1;
							count = 0;
							totalCost = 0;
							freq[data[k]]--;
							break;
						}
						totalCost += data[k];
						count++;
						freq[data[k]]--;
					}
				}
			}
			System.out.format("#%d %d\n",i,totalProfit);
		}
	}
}
