import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;

public class P_1215 {
	
	// true is row false is col
	public static int rfind(char[][] data, char target, boolean isRow, int rcIdx, int start) {
		if(isRow) {
			for(int i=start; i>=0; i--) {
				if(target == data[rcIdx][i]) {
					return i;
				}
			}
		}else {
			for(int i=start; i>=0; i--) {
				if(target == data[i][rcIdx]) {
					return i;
				}
			}
		}
		return -1;
	}

	
	public static void main(String[] args) throws Exception {
		int testCase, palinLength, size=8;
		int front, end;
		boolean palinFlag;
		String line;
		char[][] data = new char[8][8];
		BufferedReader reader = new BufferedReader(
				new InputStreamReader(System.in));
		/*BufferedReader reader = new BufferedReader(
				new FileReader("src\\sample_input.txt"));*/
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			palinLength = Integer.parseInt(reader.readLine());
			for(int j=0; j<size; j++) {
				palinFlag = false;
				front = j;
				end = rfind(data, data[j][front], true, j, size-1);
				while(data[j][front] == data[j][end]) {
					if(front == end + 1 || front == end) {
						palinFlag = true;
						break;
					}
					front++;
					end = rfind(data, data[j][front], true, j, end-1);
				}
			}
			for(int j=0; j<size; j++) {
				
			}
		}
	}

}
