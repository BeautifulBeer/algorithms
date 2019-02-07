import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {

	public static void main(String[] args) throws Exception{
		int N;
		double sum;
		Node node;
		Node[] vertex = new Node[1000 + 1];
		String[] tokens;
//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		for(int j=0; j<=1000; j++) {
			vertex[j] = new Node();
		}
		for(int i=1; i<=10; i++) {
			sum = 0;
			N = Integer.parseInt(reader.readLine());
			for(int j=0; j<N; j++) {
				tokens = reader.readLine().split("\\s");
				node = vertex[Integer.parseInt(tokens[0])];
				if(tokens.length > 2) {
					node.ch = tokens[1].charAt(0);
					node.left = vertex[Integer.parseInt(tokens[2])];
					node.right = vertex[Integer.parseInt(tokens[3])];
				}else {
					node.ch = '.';
					node.v = Integer.parseInt(tokens[1]);
				}
			}
			sum = inorder(vertex[1]);
			System.out.println("#" + i + " " + (int)sum);
		}
	
	}
	
	static double inorder(Node v) {
		switch(v.ch) {
		case '+':
			return inorder(v.left) + inorder(v.right);
		case '-':
			return inorder(v.left) - inorder(v.right);
		case '*':
			return inorder(v.left) * inorder(v.right);
		case '/':
			return inorder(v.left) / inorder(v.right);
		default:
			return v.v;
		}
	}
	
	static class Node{
		char ch;
		double v;
		Node left, right;
		Node(){
			this.left = null;
			this.right = null;
		}
	}
}







