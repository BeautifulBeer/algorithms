import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;

public class Solution {
	
	public static void main(String[] args) throws Exception {
		int testCase, people;
		BufferedReader reader = new BufferedReader(
				new InputStreamReader(System.in));
		/*BufferedReader reader = new BufferedReader(
				new FileReader("src\\sample_input.txt"));*/
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			people = Integer.parseInt(reader.readLine());
			System.out.format("#%d ", i);
			for(int j=0; j<people; j++) {
				System.out.format("%d/%d ", 1, people);
			}
			System.out.println();
		}
	}

}
