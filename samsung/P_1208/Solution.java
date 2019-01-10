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
	
	public static void printArr(int[] arr) {
		for(int i=0; i<arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
	
    public static void main(String[] args) throws Exception{
    	int cntDumps, min_idx, max_idx, cnt, tmp;
    	StringTokenizer st;
    	int[] counts = new int[100 + 1]; // 0 to 100
    	BufferedReader reader = new BufferedReader(new FileReader("src\\input.txt"));
//    	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    	for(int i=1; i<=1; i++) {
    		cntDumps = Integer.parseInt(reader.readLine());
    		st = new StringTokenizer(reader.readLine(), " ");
    		for(int j=1; j<=100; j++) {
    			counts[j] = 0;
    		}
    		while(st.hasMoreTokens()) {
    			counts[Integer.parseInt(st.nextToken())]++;
    		}
    		printArr(counts);
    		tmp = 0;
    		for(int j=counts.length-1; j>0; j--) {
    			if(counts[j] != 0) {
    				if(tmp + counts[j] < cntDumps) {
    					tmp += counts[j];	
    				}
    			}
    			
    		}
    		
    		min_idx = 0;
    		max_idx = counts.length-1;
    		while(counts[min_idx] == 0 && min_idx <= 100) {
    			min_idx++;
    		}
    		while(counts[max_idx] == 0 && max_idx > 0) {
    			min_idx--;
    		}
    		
    		System.out.println("#" + i + " " + (max_idx - min_idx));
    	}
    }
}