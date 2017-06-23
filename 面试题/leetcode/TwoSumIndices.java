package leetcode;

import java.util.HashMap;
import java.util.Map;

/**
 * designed by Steve Ke on 2017/4/15.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/15
 */

/**
     1.Given an array of integers, return indices of the two numbers such that they add up to a specific target.
       You may assume that each input would have exactly one solution, and you may not use the same element twice.
       Example:
       Given nums = [2, 7, 11, 15], target = 9,
       Because nums[0] + nums[1] = 2 + 7 = 9,
       return [0, 1].
 */
public class TwoSumIndices {

        public static int[] twoSum(int[] nums, int target) {
            int result[]=new int[2];
            int tmp=0;
            Map datas=new HashMap();
            for(int i=0;i<nums.length;i++){
                datas.put(nums[i],i);
            }

            for(int i=0;i<nums.length;i++){
                result[0]=i;
                tmp=target-nums[result[0]];
                if(datas.containsKey(tmp)&&(int)datas.get(tmp)!=i){
                    result[1]=(int)datas.get(target-nums[result[0]]);
                    return result;
                }
            }
            return null;

        }

    public static void main(String []args){
            int []nums={2, 7, 11, 15};
            int target=9;

        System.out.println(twoSum(nums,target)[0]+" "+twoSum(nums,target)[1]);


    }


}
