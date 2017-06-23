package leetcode;

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

import java.util.HashMap;
import java.util.Map;

/**
 3.Longest Substring Without Repeating Characters
 Given a string, find the length of the longest substring without repeating characters.

 Examples:
 Given "abcabcbb", the answer is "abc", which the length is 3.

 Given "bbbbb", the answer is "b", with the length of 1.

 Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring,
 "pwke" is a subsequence and not a substring.

 */

public class LSWithoutRC {
    public static int lengthOfLongestSubstring(String s) {
        int maxLength=0;
        int lastIndex=0;
        Map repeated=new HashMap();
        for(int i=0;i<s.length();i++){
            if(repeated.get(s.charAt(i))!=null){
                lastIndex=i;
            }else {
                repeated.put(s.charAt(i),"");
                maxLength=Math.max(maxLength,i-lastIndex+1);
            }
        }
        return maxLength;
    }

    public static void main(String []args){
        System.out.println(lengthOfLongestSubstring("abcabcbb"));
    }


}
