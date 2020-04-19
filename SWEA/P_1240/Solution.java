import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Solution {

	
	public static void main(String[] args) throws Exception{
		int testCase;
		int result;
		int w, h;
		String str;
		StringBuilder sb;
		String[] tokens;
		char[][] ciphers;
		Map<String, Character> cipher = new HashMap<String, Character>();
		cipher.put("0001101", '0');
		cipher.put("0011001", '1');
		cipher.put("0010011", '2');
		cipher.put("0111101", '3');
		cipher.put("0100011", '4');
		cipher.put("0110001", '5');
		cipher.put("0101111", '6');
		cipher.put("0111011", '7');
		cipher.put("0110111", '8');
		cipher.put("0001011", '9');
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			result = 0;
			sb = new StringBuilder();
			tokens = reader.readLine().split("\\s");
			w = Integer.parseInt(tokens[0]);
			h = Integer.parseInt(tokens[1]);
//			System.out.println(w + " , " + h);
			for(int j=0; j<w; j++) {
				str = reader.readLine();
				if(sb.length() == 8) {
					continue;
				}
//				System.out.println(str);
				for(int k=0; k<str.length()-6; k++) {
					sb.setLength(0);
					for(int l=0; l<8; l++) {
						if(cipher.containsKey(str.substring(k+l*7, k+l*7+7))) {
//							System.out.println(str.substring(k+l*7, k+l*7+7));
							sb.append(cipher.get(str.substring(k+l*7, k+l*7+7)));
						}else {
							break;
						}
					}
					if(sb.length() == 8) {
						break;
					}
				}
			}
			str = sb.toString();
//			System.out.println(str);
			int parity = (str.charAt(0) - '0' + str.charAt(2) - '0' +
					str.charAt(4) - '0' + str.charAt(6) - '0') * 3 + 
					(str.charAt(1) - '0' + str.charAt(3) - '0' + str.charAt(5) - '0') +
					str.charAt(7) - '0';
//			System.out.println(parity);
			if(parity % 10 == 0) {
				for(int j=0; j<str.length(); j++) {
					result += str.charAt(j) - '0';
				}
				System.out.println("#" + i + " " + result);
			}else {
				System.out.println("#" + i + " " + 0);
			}
		}
	}
}
