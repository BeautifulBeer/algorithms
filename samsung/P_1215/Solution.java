import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;

public class Solution {
	static char[][] data;
	static Deque<Character> deque; 
	
	public static void loadParlinString(int rcIdx, int start, int end, boolean isRow) {
		if(isRow) {
			for(int i=start; i<end; i++) {
				deque.add(data[rcIdx][i]);
			}
		}else {
			for(int i=start; i<end; i++) {
				deque.add(data[i][rcIdx]);
			}
		}
	}
	
	public static boolean isParlinString() {
		while(deque.size() > 1 && deque.getFirst() == deque.getLast()) {
			deque.removeFirst();
			deque.removeLast();
		}
		if(deque.size() <= 1) {
			return true;
		}
		return false;
	}
	
	public static void main(String[] args) throws Exception {
		int palinLength, total;
		String line;
		data = new char[8][8];
		deque = new LinkedList<Character>();
//		BufferedReader reader = new BufferedReader(new FileReader("src\\input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		for(int i=1; i<=10; i++) {
			// load data
			total = 0;
			palinLength = Integer.parseInt(reader.readLine());
			for(int j=0; j<8; j++) {
				line = reader.readLine();
				for(int k=0; k<8; k++) {
					data[j][k] = line.charAt(k);
				}
			}
			// process row
			for(int j=0; j<8; j++) {
				for(int k=0; k<=8-palinLength; k++) {
//					System.out.println("k : " + k);
					loadParlinString(j, k, k+palinLength, true);	
//					for(char ch : deque) {
//						System.out.print(ch + " ");
//					}
//					System.out.println();
					if(isParlinString()) {
//						System.out.println("True");
//						k += palinLength-1;
						total++;
					}
					deque.clear();
				}
			}
			
			// process col
			for(int j=0; j<8; j++) {
				for(int k=0; k<=8-palinLength; k++) {
					loadParlinString(j, k, k+palinLength, false);	
//					for(char ch : deque) {
//						System.out.print(ch + " ");
//					}
//					System.out.println();
					if(isParlinString()) {
//						System.out.println("True");
//						k += palinLength-1;
						total++;
					}
					deque.clear();
				}
			}
			
			System.out.format("#%d %d\n", i, total);
		}
	}

}
