import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	static int T, count, tmp, totalLength;
	static String A, B;
	
	public static void main(String[] args) throws IOException, NumberFormatException{
		StringTokenizer st;
//		System.setIn(new FileInputStream("src/sample_input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			st = new StringTokenizer(reader.readLine());
			A = st.nextToken(); B = st.nextToken();
			count = 0; tmp = 0;
			totalLength = A.length();
			int aIdx = 0, bIdx = 0;
			while(aIdx < totalLength) {
				if(A.charAt(aIdx) == B.charAt(bIdx)) {
					bIdx++;
					if(bIdx == B.length()) {
						count++; bIdx=0;
					}
				}else {
					aIdx -= bIdx;
					bIdx = 0;
				}
				aIdx++;
			}
			System.out.println("#"+t+" "+(totalLength - count*(B.length()-1)));
		}
	}

}
