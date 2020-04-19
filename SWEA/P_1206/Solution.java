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
        int testCase, numBuildings, idx, floor, tmp_max;
        int[] arr = new int[1000];
//        BufferedReader reader = new BufferedReader(new FileReader("src\\input.txt"));
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
//        testCase = Integer.parseInt(reader.readLine());
        for(int i=1; i<=10; i++) {
        	numBuildings = Integer.parseInt(reader.readLine());
        	st = new StringTokenizer(reader.readLine());
        	idx = 0;
        	floor = 0;
        	// load data
        	while(st.hasMoreTokens()) {
        		arr[idx] = Integer.parseInt(st.nextToken());
        		idx++;
        	}
        	for(int j=2; j<numBuildings-2; j++) {
        		tmp_max = arr[j-2];
        		if(tmp_max < arr[j-1]) {
        			tmp_max = arr[j-1];
        		}
        		if(tmp_max < arr[j+1]) {
        			tmp_max = arr[j+1];
        		}
        		if(tmp_max < arr[j+2]) {
        			tmp_max = arr[j+2];
        		}
        		if(arr[j] > tmp_max) {
        			floor += arr[j]-tmp_max;
        		}
        	}
        	System.out.format("#%d %d\n", i, floor);
        }
    }
}