import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {

	public static void main(String[] args) throws Exception {
		String line;
		int total, sticks, numStick;
		int testCase;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			total = 0;
			sticks = 1;			
			line = reader.readLine();
			numStick = (line.charAt(0) == '(')? 1:0;
			for(int j=1; j<line.length(); j++) {
				if(line.charAt(j) == '(') {
					sticks++;
					numStick++;
				}else {
					sticks--;
					if(line.charAt(j-1) == '(' && line.charAt(j) == ')') {
						total+=sticks;
						numStick--;
					}
				}
			}
			total += numStick;
			System.out.println("#" + i + " " + total);
		}
	}
}



 



