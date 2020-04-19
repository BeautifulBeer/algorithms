import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {	
	static long a, b, c;
	static HashMap<Long, Long> memo = new HashMap<>();
	
	static long multiply(long num) {
		if(memo.containsKey(num)) {
			return memo.get(num);
		}
		if(num % 2 == 0) {
			memo.put(num, (multiply(num/2) % c * multiply(num/2) % c) % c);
		}else {
			memo.put(num, (multiply((num-1)/2) % c * multiply((num-1)/2) % c * multiply(1)) % c);
		}
		return memo.get(num);
		
	}
	
	public static void main(String[] args) throws IOException, NumberFormatException{
		StringTokenizer st;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		st = new StringTokenizer(reader.readLine());
		a = Long.parseLong(st.nextToken());
		b = Long.parseLong(st.nextToken());
		c = Long.parseLong(st.nextToken());
		memo.put(1L, a%c);
		memo.put(0L, 1L);
		multiply(b);
		System.out.println(memo.get(b));
	}

}
