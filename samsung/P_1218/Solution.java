import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Solution {

	public static void main(String[] args) throws Exception {
		char tmp;
		int length;
		char[] arr;
		boolean flag;
		String line;
		Stack<Character> st = new Stack<>();
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		for(int i=1; i<=10; i++) {
			st.clear();
			flag = true;
			length = Integer.parseInt(reader.readLine());
			for(char ch : reader.readLine().toCharArray()) {
				if(ch == '(' || ch == '[' || ch == '{' || ch == '<') {
					st.push(ch);
				}else {
					tmp = st.pop();
					if(tmp == '(' && ch != ')') {
						flag = false;
						break;
					}else if(tmp == '[' && ch != ']') {
						flag = false;
						break;
					}else if(tmp == '{' && ch != '}') {
						flag = false;
						break;
					}else if(tmp == '<' && ch != '>') {
						flag = false;
						break;
					}
				}				
			}
			if(flag) {
				System.out.println("#" + i + " " + 1);	
			}else {
				System.out.println("#" + i + " " + 0);
			}
		}
	}
}







