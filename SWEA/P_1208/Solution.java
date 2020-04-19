import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
 
/**
 * 
 * @author Kwanwoong Yoon
 *
 */
public class Solution {
	
    public static void main(String[] args) throws Exception{
    	int cntDumps, min_idx, max_idx, tmpDumps;
    	StringTokenizer st;
    	int[] counts = new int[100 + 1]; // 0 to 100
//    	BufferedReader reader = new BufferedReader(new FileReader("src\\input.txt"));
    	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    	BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    	for(int i=1; i<=10; i++) {
    		max_idx = 0;
    		min_idx = 0;
    		cntDumps = Integer.parseInt(reader.readLine());
    		st = new StringTokenizer(reader.readLine(), " ");
    		for(int j=1; j<=100; j++) {
    			counts[j] = 0;
    		}
    		while(st.hasMoreTokens()) {
    			counts[Integer.parseInt(st.nextToken())]++;
    		}
    		//down
    		tmpDumps = cntDumps;
    		for(int j=counts.length-1; j>1; j--) {
    			if(counts[j] != 0) {
    				if(tmpDumps - counts[j] >= 0) {
    					tmpDumps -= counts[j];
    					counts[j-1] += counts[j];
//    					counts[j] = 0;
    				}else {
    					max_idx = j;
    					break;
    				}
    			}
    		}
    		//up
    		tmpDumps = cntDumps;
    		for(int j=1; j<counts.length; j++) {
    			if(counts[j] != 0) {
    				if(tmpDumps - counts[j] >= 0) {
    					tmpDumps -= counts[j];
    					counts[j+1] += counts[j];
//    					counts[j] = 0;
    				}else {
    					min_idx = j;
    					break;
    				}
    			}
    		}
    		bw.write("#" + i + " " + (max_idx - min_idx) + "\n");
    	}
    	bw.close();
    	reader.close();    	
    }
}