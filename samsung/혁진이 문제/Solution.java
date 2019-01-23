import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.Stack;

/**
 * 
 * @author Kwanwoong Yoon
 *
 */
public class Solution {

	public static void main(String[] args) throws Exception{
		boolean exit;
		int testCase, r, c, ridx, cidx, instCount, limit;
		BufferedReader reader = new BufferedReader(new FileReader("src\\input.txt"));
		String[] tokens;
		String line;
		String result;
		int instruction, memory;
		int[] instructions = { 0x0000, 0x0001, 0x0002, 0x0003}; // left, right, up, down
		char[][] arr = new char[20][20];
		//		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			exit = false;
			memory = 0;
			instruction = instructions[1];
			result = "";
			ridx = 0;
			cidx = 0;
			instCount = 0;
			tokens = reader.readLine().split(" ");
			r = Integer.parseInt(tokens[0]);
			c = Integer.parseInt(tokens[1]);
			limit = r * c;
			// load data
			for(int j=0; j<r; j++) {
				line = reader.readLine();
				for(int k=0; k<c; k++) {
					arr[j][k] = line.charAt(k);
				}
			}

			while(!exit && instCount++ <= limit) {
				switch(arr[ridx][cidx]) {
				case '<': // left
					instruction = instructions[0];
					break;
				case '>': // right
					instruction = instructions[1];
					break;
				case '^': // up
					instruction = instructions[2]; 
					break;
				case 'v': // down
					instruction = instructions[3];
					break;
				case '_': // memory value is 0 --> right  1 --> left
					if(memory == 0) {
						instruction = instructions[1];
					}else {
						instruction = instructions[0];
					}
					break;
				case '|': // memory value is 0 --> down  1 --> up
					if(memory == 0) {
						instruction = instructions[3];
					}else {
						instruction = instructions[2];
					}
					break;
				case '?': // evenly random position
					instruction = instructions[(int)(Math.random() * 4)];
					break;
				case '.': // nothing
					break; 
				case '@': // halt
					exit = true;
					break;
				case '+': // add
					memory = (memory + 1) % 16;
					break;
				case '-': // minus
					memory = (memory - 1) % 16;
					break;
				default: // numbers
					memory = arr[ridx][cidx] - '0';
					break;
				}
				if(instruction == instructions[0]) {
					cidx = Math.abs((cidx-1) % c);
				}else if(instruction == instructions[1]){
					cidx = Math.abs((cidx+1) % c);
				}else if(instruction == instructions[2]){
					ridx = Math.abs((ridx+1) % r);
				}else if(instruction == instructions[3]){
					ridx = Math.abs((ridx-1) % r);
				}
			}
			if(exit) {
				result = "YES";
			}else {
				result = "NO";
			}
			System.out.println("#" + i + " " + result);
		}
	}
}