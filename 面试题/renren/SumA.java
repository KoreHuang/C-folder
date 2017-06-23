package renren;

import java.util.Scanner;

/**
 * designed by Steve Ke on 2017/4/9.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/9
 */
public class SumA {
    public static boolean judge(int[] nums,int index){
        int left=0;
        int right=0;
        for(int i=0;i<index;i++){
            left+=nums[i];
        }
        for(int i=index;i<nums.length;i++){
            right+=nums[i];
        }
        return right==left;
    }

    public static int solve(int []nums){
        int cnt=0;
        for(int i=1;i<nums.length;i++){
            if(judge(nums,i)){
                cnt++;
            }
        }
        return cnt;
    }

    public static void main(String []args){
        Scanner scanner=new Scanner(System.in);
        while (scanner.hasNext()){
            int n=scanner.nextInt();
            int nums[]=new int[n];
            for(int i=0;i<n;i++){
                nums[i]=scanner.nextInt();
            }
            System.out.println(solve(nums));

        }
    }
}
