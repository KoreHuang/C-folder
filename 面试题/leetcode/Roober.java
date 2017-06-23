package leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * designed by Steve Ke on 2017/4/7.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/7
 */
public class Roober {
    public int solve(int currentStep,int []treasure,Map past){
        if(past.get(currentStep)!=null){
            return (Integer)past.get(currentStep);
        }
        if(currentStep<0){
            return 0;
        }
        int max=Math.max(treasure[currentStep]+solve(currentStep-2,treasure,past),
                            solve(currentStep-1,treasure,past));
        past.put(currentStep,max);
        return max;
    }
    public static int []result;
    public int rob(int nums[]){
        if(nums==null||nums.length==0){
            return 0;
        }
        if(nums.length==1){
            return nums[0];
        }
        result=new int[nums.length];

        result[0]=nums[0];

        result[1]=nums[0]>nums[1]?nums[0]:nums[1];

        for(int i=2;i<nums.length;i++){
            result[i]=Math.max(result[i-2]+nums[i],result[i-1]);
        }

        return result[nums.length-1];
    }
    public static void main(String []args){
        Roober roober=new Roober();
        int a[]={1,2,3,4,5,6,7,8};

        int result=roober.solve(a.length-1,a,new HashMap());
        System.out.println(result);


    }
}
