import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Solution {
	public static void main(String[] args) throws Exception {
		int n, a, b;
		String str;
		Stack<Integer> stack = new Stack<>();
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		for(int i=1; i<=10; i++) {
			stack.clear();
			n = Integer.parseInt(reader.readLine());
			str = reader.readLine();
			str = transPostFix(str);
			for(int j=0; j<str.length(); j++) {
				if(Character.isDigit(str.charAt(j))) {
					stack.push(str.charAt(j) - '0');
				}else {
					switch(str.charAt(j)) {
					case '+':
						b = stack.pop();
						a = stack.pop();
						stack.push(a+b);
						break;
					case '*':
						b = stack.pop();
						a = stack.pop();
						stack.push(a*b);
						break;
					}
				}
			}
			System.out.println("#" + i + " " + stack.pop());
		}
		
	}
	
	static int priority(char ch) {
		if(ch == '+' || ch == '-') {
			return 1;
		}else if(ch == '*' || ch == '/') {
			return 2;
		}
		return 0;
	}
	
	static String transPostFix(String s) {
		String result = "";
		Stack<Character> stack = new Stack<>();
		char[] arr = s.toCharArray();
		for(int i=0; i<s.length(); i++) {
			if(Character.isDigit(arr[i])) {
				result += arr[i];
			}else if(arr[i] == '('){
				stack.push(arr[i]);
			}else if(arr[i] == ')') {
				while(!stack.isEmpty() && stack.peek() != '(') {
					result += stack.pop();
				}
				stack.pop();
			}else {
				while(!stack.isEmpty() && priority(arr[i]) <= priority(stack.peek())) {
					result += stack.pop();
				}
				stack.push(arr[i]);
			}
		}
		while(!stack.isEmpty())result += stack.pop();
		return result;
	}
	
	
	
	
}







