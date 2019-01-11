import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * 
 * @author Kwanwoong Yoon
 *
 */
public class Solution {

	public static void initArr(boolean[] arr) {
		for(int i=0; i<arr.length; i++) {
			arr[i] = false;
		}
	}

	public static void main(String[] args) throws Exception{
		boolean isValid;
		int testCase;
		boolean[] checkNumber = new boolean[10];
		int[][] sdoku = new int[9][9];
		String[] tokens;
		BufferedReader reader = new BufferedReader(new FileReader("src\\input.txt"));
		//    	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			isValid = true;
			for(int j=0; j<9; j++) {
				tokens = reader.readLine().split(" ");
				for(int k=0; k<9; k++) {
					sdoku[j][k] = Integer.parseInt(tokens[k]);
				}
			}			
			
			//row
			for(int j=0; j<9; j++) {
				if(!isValid)break;
				initArr(checkNumber);
				for(int k=0; k<9; k++) {
					if(!isValid)break;
					if(!checkNumber[sdoku[j][k]]) {
						checkNumber[sdoku[j][k]]= true;
					}else {
						isValid = false;
					}
				}
			}
			
			//col
			for(int j=0; j<9; j++) {
				if(!isValid)break;
				initArr(checkNumber);
				for(int k=0; k<9; k++) {
					if(!isValid)break;
					if(!checkNumber[sdoku[k][j]]) {
						checkNumber[sdoku[k][j]]= true;
					}else {
						isValid = false;
					}
				}
			}
			
			//square
			for(int j=0; j<9; j+=3) {
				if(!isValid)break;
				for(int k=0; k<9; k+=3) {
					if(!isValid)break;
					initArr(checkNumber);
					for(int l=j; l<j+3; l++) {
						if(!isValid)break;
						for(int m=k; m<k+3; m++) {
							if(!isValid)break;
							if(!checkNumber[sdoku[l][m]]) {
								checkNumber[sdoku[l][m]]= true;
							}else {
								isValid = false;
							}
						}
					}
				}
			}
			if(isValid) {
				System.out.println("#" + i + " " +  1);	
			}else {
				System.out.println("#" + i + " " +  0);
			}
			
		}
	}
}