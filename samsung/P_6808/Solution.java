import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {

	static int[] guCards;
	static int[] cards;
	static int tmp, gu, in, win, lose;

	public static void main(String[] args) throws Exception{
		int testCase;
		boolean[] card = new boolean[18 + 1];
		String[] tokens;
		guCards = new int[9];
		cards = new int[9];
		//		BufferedReader reader = new BufferedReader(new FileReader("src/s_input.txt"));
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			for(int j=1; j<=18; j++) {
				card[j] = false;
			}
			win=0;
			lose=0;
			tokens = reader.readLine().split("\\s");
			tmp = 0;
			for(int j=0; j<tokens.length; j++) {
				card[Integer.parseInt(tokens[j])] = true;
				guCards[tmp] = Integer.parseInt(tokens[j]);
				tmp++;
			}
			tmp = 0;
			for(int j=1; j<=18; j++) {
				if(!card[j]) {
					cards[tmp] = j;
					tmp++;
				}
			}
			//			for(int j=0; j<cards.length; j++) {
			//				System.out.print(cards[j] + " ");
			//			}
			//			System.out.println();
			search(0, 0, 0);
			lose = 362880-win;
			System.out.println("#" + i + " " + win + " " + lose);
		}
	}

	static void search(int depth, int guSum, int inSum) {
		if(depth == cards.length) {
			if(guSum > inSum) {
				win++;
			}
			return;
		}
		if(depth > 3) {
			int maxInSum = inSum;
			for(int i=depth; i<cards.length; i++) {
				maxInSum += cards[i] + 18;
			}
			if(guSum > maxInSum) {
				win += factorial(cards.length - depth);
				return;
			}
		}
		for(int i=depth; i<cards.length; i++) {
			swap(depth, i);
			if(cards[depth] > guCards[depth]) {
				search(depth+1, guSum, inSum + cards[depth] + guCards[depth]);	
			}else {
				search(depth+1, guSum + cards[depth] + guCards[depth], inSum);
			}
			swap(depth, i);
		}
	}

	static int factorial(int n) {
		int result = 1;
		for(int i=n; i>1; i--) {
			result *= i;
		}
		return result;
	}

	static void swap(int x, int y) {
		tmp = cards[x];
		cards[x] = cards[y];
		cards[y] = tmp;
	}
}







