import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Solution {

	public static void main(String[] args) throws Exception{
		int v;
		Node tmp;
		String[] tokens;
		Node[] vts;
//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		for(int i=1; i<=10; i++) {
			v = Integer.parseInt(reader.readLine());
			vts = new Node[v+1];
			for(int j=0; j<vts.length; j++) {
				vts[j] = new Node();
			}
			for(int j=0; j<v; j++) {
				tokens = reader.readLine().split("\\s");
//				System.out.println(Arrays.toString(tokens));
				tmp = vts[Integer.parseInt(tokens[0])];
				tmp.ch = tokens[1].trim().charAt(0);
				if(tokens.length >= 3) {
					tmp.left = vts[Integer.parseInt(tokens[2])];
				}
				if(tokens.length >= 4) {
					tmp.right = vts[Integer.parseInt(tokens[3])];
				}
			}
			System.out.print("#" + i + " ");
			inorder(vts[1]);
			System.out.println();
		}
	}
	
	static void inorder(Node v) {
		if(v.left != null) {
			inorder(v.left);
		}
		System.out.print(v.ch);
		if(v.right != null) {
			inorder(v.right);
		}
	}
	
	static class Node{
		char ch;
		Node left, right;
		
		Node(){
			this.left = null;
			this.right = null;
		}
	}
}







