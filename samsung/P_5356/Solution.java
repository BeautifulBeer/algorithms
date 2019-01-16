import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * 
 * @author Kwanwoong Yoon
 *
 */
public class Solution {

	public static void main(String[] args) throws Exception{
		int testCase;
		String result;
		char[] tmp_char;
		char[][] data = new char[5][];
//		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader reader = new BufferedReader(new FileReader("src\\sample_input.txt"));
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			result = "";
			for(int j=0; j<5; j++) {
				tmp_char = reader.readLine().toCharArray();
				data[j] = tmp_char;
			}
			for(int j=0; j<15; j++) {
				for(int k=0; k<5; k++) {
					if(j < data[k].length) {
						result += data[k][j];	
					}
				}
			}
			System.out.println("#" + i + " " + result);
		}
	}
}