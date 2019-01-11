import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
/**
 * 
 * @author Kwanwoong Yoon
 *
 */
public class Solution {
	

    public static void main(String[] args) throws Exception{
    	int testCase, arraySize = 100;
    	String[] tokens;
    	BufferedReader reader = new BufferedReader(new FileReader("src\\input.txt"));
//    	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    	int[][] arr = new int[arraySize][arraySize];
    	int max, tmp;
    	testCase = Integer.parseInt(reader.readLine());
    	for(int i=1; i<=testCase; i++) {
    		max = 0;
    		// load data
    		for(int j=0; j<arraySize; j++) {
    			tokens = reader.readLine().split("\\s");
    			for(int k=0; k<arraySize; k++) {
    				arr[j][k] = Integer.parseInt(tokens[k]);
    			}
    		}
    		
    		// row
    		for(int j=0; j<arraySize; j++) {
    			tmp = 0;
    			for(int k=0; k<arraySize; k++) {
//    				System.out.println(j + ", " + k);
    				tmp += arr[j][k];
    			}
    			if(max < tmp) {
    				max = tmp;
    			}
    		}
    		
    		// col
    		for(int j=0; j<arraySize; j++) {
    			tmp = 0;
    			for(int k=0; k<arraySize; k++) {
//    				System.out.println(k + ", " + j);
    				tmp += arr[k][j];
    			}
    			if(max < tmp) {
    				max = tmp;
    			}
    		}
    		
    		// leftup_rightdown
    		tmp = 0;
    		for(int j=0; j<arraySize; j++) {
//    			System.out.println(j + ", " + j);
    			tmp += arr[j][j];    			
    		}
    		if(max < tmp) {
    			max = tmp;
    		}
    		
    		// leftdown_rightup
    		tmp = 0;
    		for(int j=0; j<arraySize; j++) {
//    			System.out.println(j + ", " + (arraySize-j-1));
    			tmp += arr[j][arraySize-j-1];    			
    		}
    		if(max < tmp) {
    			max = tmp;
    		}
    		System.out.println("#" + i + " " + max);
    	}
    }
}