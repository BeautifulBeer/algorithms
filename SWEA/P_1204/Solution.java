import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;

public class Solution {
	
	public static void main(String[] args) throws Exception {
		int testCase;
		int numTestCase, maxFreq, maxIdx;
		String[] tokens;
		int[] counter = new int[100 + 1]; // 0 to 100
//		BufferedReader reader = new BufferedReader(new FileReader("src\\input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		testCase = Integer.parseInt(reader.readLine());
		while(testCase-- > 0) {
			maxFreq = 0;
			maxIdx = 0;
			numTestCase = Integer.parseInt(reader.readLine());
			// init array
			for(int i=0; i<101; i++) {
				counter[i] = 0;
			}
			tokens = reader.readLine().split("\\s");
			for(int i=0; i<tokens.length; i++) {
				counter[Integer.parseInt(tokens[i])]++;
			}
			for(int i=0; i<101; i++) {
				if(maxFreq <= counter[i]) {
					maxFreq = counter[i];
					maxIdx = i;
				}
			}
			System.out.format("#%d %d\n", numTestCase, maxIdx);
		}
		
	}

}
