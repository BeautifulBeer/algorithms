import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * 
 * @author Kwanwoong Yoon
 *
 */
public class Solution {
	
	static int maxTaste, ingre, limitCal;
	static int[] tasteArr, calArr;
	
	public static void Hamburger(int idx, int cal, int taste) {
//		System.out.println(cal + ", " + taste + ", " + idx);
		if(cal > limitCal) {
			return;
		}
		if(maxTaste < taste) {
			maxTaste = taste;
		}
		if(idx >= ingre) {
			return;
		}
		Hamburger(idx+1, cal, taste);
		Hamburger(idx+1, cal + calArr[idx], taste + tasteArr[idx]);
	}
	
	public static void main(String[] args) throws Exception{
		int testCase;
		BufferedReader reader = new BufferedReader(new FileReader("src\\sample_input.txt"));
		String[] tokens;
//		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		tasteArr = new int[20];
		calArr = new int[20];
		
		testCase = Integer.parseInt(reader.readLine());
		for(int i=1; i<=testCase; i++) {
			maxTaste = 0;
			tokens = reader.readLine().split("\\s");
			ingre = Integer.parseInt(tokens[0]);
			limitCal = Integer.parseInt(tokens[1]);
			//load data
			for(int j=0; j<ingre; j++) {
				tokens = reader.readLine().split("\\s");
				tasteArr[j] = Integer.parseInt(tokens[0]);
				calArr[j] = Integer.parseInt(tokens[1]);
			}
			Hamburger(0, 0, 0);
			System.out.println("#" + i + " " + maxTaste);
		}
	}
}