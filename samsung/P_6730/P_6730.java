import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;

public class Solution {
	
	public static void main(String[] args) throws Exception {
		String[] tokens;
		int testCase, N, plusMax, minusMin, prev, cur, tmp;
		BufferedReader reader = new BufferedReader(
				new InputStreamReader(System.in));
		/*BufferedReader reader = new BufferedReader(
				new FileReader("src\\s_input.txt"));*/
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			plusMax = 0;
			minusMin = 0;
			N = Integer.parseInt(reader.readLine());
			tokens = reader.readLine().split("\\s");
			prev = Integer.parseInt(tokens[0]);
			for(int j=1; j<N; j++) {
				cur = Integer.parseInt(tokens[j]);
				tmp = cur-prev;
				if(tmp > 0) {
					if(plusMax < tmp) {
						plusMax = tmp;
					}
				}else if(tmp < 0){
					if(minusMin > tmp) {
						minusMin = tmp;
					}
				}
				prev = cur;
			}
			System.out.format("#%d %d %d\n", i, plusMax, Math.abs(minusMin));
			
		}
	}

}
