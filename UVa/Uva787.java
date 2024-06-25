import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

class Uva787 {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		ArrayList<Integer> nums = new ArrayList<Integer>(); //creating a list
		while(sc.hasNext()) {//while End of File isn't encountered
		int cur = sc.nextInt();
		if(cur == -999999) {
			BigInteger ans = BigInteger.valueOf(cur);
			//big min value -999999 value initially

			BigInteger pre = BigInteger.valueOf(1);
            BigInteger suf = BigInteger.valueOf(1);
			//initial value

			for(int i = 0; i < nums.size(); i++) {
				if(pre==BigInteger.valueOf(0))pre=BigInteger.valueOf(1);
                if(suf==BigInteger.valueOf(0))suf=BigInteger.valueOf(1);
                pre=pre.multiply(BigInteger.valueOf(nums.get(i)));
                suf=suf.multiply(BigInteger.valueOf(nums.get(nums.size()-i-1)));
                ans=ans.max(pre.max(suf));
			}
			System.out.println(ans);
			nums.clear();
			continue;
		}nums.add(cur);
    
	}sc.close();
}
}