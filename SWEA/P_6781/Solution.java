import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Solution {
	
	static int convertCard(char num, char color) {
		if(color == 'R') {
			return num - '0';
		}else if(color == 'G') {
			return 10 + (num - '0');
		}else{
			return 20 + (num - '0');
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		int T, result, idx;
		int[] cards = new int[9];
		int[] counts = new int[30+1];
		String cardNum, cardColor;
//		BufferedReader reader = new BufferedReader(new FileReader("src/sample_input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		for(int t=1; t<=T; t++) {
			result = 0;
			cardNum = reader.readLine();
			cardColor = reader.readLine();
			Arrays.fill(counts, 0);
//			System.out.println(Arrays.toString(counts));
			for(int i=0; i<9; i++) {
				cards[i] = convertCard(cardNum.charAt(i), cardColor.charAt(i));
				counts[cards[i]]++;
			}
			Arrays.sort(cards);
//			System.out.println(Arrays.toString(cards));
//			System.out.println(Arrays.toString(counts));
			idx = 1;
			while(idx < counts.length-2) {
				if(counts[idx] >= 3) {
					counts[idx] -= 3;
					result++;
				}else if(counts[idx] >= 1 && counts[idx+1] >= 1 && counts[idx+2] >= 1) {
					counts[idx] -= 1;
					counts[idx+1] -= 1;
					counts[idx+2] -= 1;
					result++;
				}else {
					idx++;
				}
			}
			if(result == 3) {
				System.out.println("#" + t + " Win");	
			}else {
				System.out.println("#" + t + " Continue");
			}
			
		}
	}
	
}
