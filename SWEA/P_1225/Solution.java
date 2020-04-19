import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {
	public static void main(String[] args) throws Exception {
		int cycle;
		int tmp;
		boolean flag;
		int[] number = new int[8];
		Queue<Integer> queue = new LinkedList();
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
//		BufferedReader reader = new BufferedReader(new FileReader("src/input.txt"));
		String[] tokens;
		for(int i=1; i<=10; i++) {
			reader.readLine();
			flag = true;
			tokens = reader.readLine().split("\\s");
			for(int j=0; j<8; j++) {
				number[j] = Integer.parseInt(tokens[j]);
			}
			queue.clear();
//			for(int j=0; j<8; j++) {
//				queue.offer(Integer.parseInt(tokens[j]));
//			}
			for(int j=0; j<8; j++) {
				if(number[j] < 610) {
					flag = false;
					break;
				}
			}
			if(!flag) {
				for(int j=0; j<8; j++) {
					if(number[j] < 600) {
						queue.add(0);
					}else {
						queue.add(number[j] % 600);	
					}
				}	
			}else {
				for(int j=0; j<8; j++) {
					queue.add(number[j]);	
				}
			}
			
			cycle = 1;
			while(true) {
				tmp = queue.poll() - cycle;
				if(cycle == 5) {
					cycle = 1;
				}else {
					cycle++;
				}
				if(tmp <= 0) {
					queue.offer(0);
					break;
				}else {
					queue.offer(tmp);
				}
			}
			
			System.out.print("#" + i + " ");
			for(int j=0; j<8; j++) {
				System.out.print(queue.poll() + " ");
			}
			System.out.println();
		}
	}

}







