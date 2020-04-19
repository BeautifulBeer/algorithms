import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {

	public static void main(String[] args) throws Exception{
		int N;
		boolean valid;
		String[] tokens;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		for(int i=1; i<=10; i++) {
			valid = true;
			N = Integer.parseInt(reader.readLine());
			for(int j=0; j<N; j++) {
				if(valid) {
					tokens = reader.readLine().split("\\s");	
				}else {
					reader.readLine();
					continue;
				}
				if(tokens.length > 2) {
					try {
						Integer.parseInt(tokens[1]);
						valid = false;
					}catch(NumberFormatException e) {
						
					}
				}else {
					try {
						Integer.parseInt(tokens[1]);
					}catch(NumberFormatException e) {
						valid = false;
					}
				}
			}
			if(valid) {
				System.out.println("#" + i + " 1");	
			}else {
				System.out.println("#" + i + " 0");
			}

		}

	}
}







