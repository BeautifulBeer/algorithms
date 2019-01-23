import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Solution {
	public static void main(String[] args) throws Exception {
		int testCase, tmp;
		int[] c;
		String[] tokens;
		ArrayList<Integer> a, b;
		a = new ArrayList<>();
		b = new ArrayList<>();
		boolean flag, zero;

		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			flag = false;
			zero = true;
			a.clear();
			b.clear();
			tokens = reader.readLine().split("\\s");
			for(int j=0; j<tokens[0].length(); j++) {
				a.add(tokens[0].charAt(j) - '0');
			}
			for(int j=0; j<tokens[1].length(); j++) {
				b.add(tokens[1].charAt(j) - '0');
			}
			if(a.size() > b.size()) {
				for(int j=b.size(); j<a.size(); j++) {
					b.add(0, 0);
				}
			}else {
				for(int j=a.size(); j<b.size(); j++) {
					a.add(0, 0);
				}
			}
			c = new int[a.size()+1];
//			System.out.println(a.size() + " , " + b.size());
			for(int j=0; j<a.size(); j++) {
				c[j+1] = a.get(j) + b.get(j);
			}
			tmp = 0;
			for(int j=a.size(); j>=0; j--) {
				c[j] += tmp;
				tmp = c[j] / 10;
				c[j] = c[j] % 10;
			}
			
			System.out.print("#" + i + " ");
			for(int j=0; j<c.length; j++) {
				if(c[j] != 0) {
					flag = true;
				}
				if(flag)System.out.print(c[j]);
			}
			System.out.println();
		}
	}
}







