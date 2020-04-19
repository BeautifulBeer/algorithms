import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;

public class Main {

	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		boolean flag = false;;
		int N, result = 0, tmp = 0, digit = 0;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(reader.readLine());
		for(int i=1; i<=N; i++) {
			result = i;
			tmp = i;
			digit = i % 10;
			result += digit;
			while((tmp = tmp / 10) != 0) {
				digit = tmp % 10;
				result += digit;
			}
			if(result == N) {
				result = i;
				flag = true;
				break;
			}
		}
		if(!flag) {
			result = 0;
		}
		System.out.println(result);
	}
	
}
