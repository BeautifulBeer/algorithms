import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		int N, max, acc, tmp;
		String tokens[];
		int[] data = new int[100000];
		//		BufferedReader reader = new BufferedReader(new FileReader("src\\input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(reader.readLine());
		
		tokens = reader.readLine().split("\\s");
		acc = Integer.parseInt(tokens[0]);
        max = acc;
		for(int i=1; i<tokens.length; i++) {
			tmp = Integer.parseInt(tokens[i]);
			if(tmp > tmp + acc) {
				acc = tmp;
			}else {
				acc += tmp;
			}
			if(max < acc) {
				max = acc;
			}
		}
		System.out.println(max);

	}

}
