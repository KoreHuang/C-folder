package DiDi;

import java.util.Scanner;

/**
 * designed by Steve Ke on 2017/4/22.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/22
 */

/**
 * 单词反转
 *  输入：
 *      I have a dream!
 *  输出：
 *      I evah a !maerd
 */
public class WordReverse {

    public static String reverse(String orig)
    {
        char[] s = orig.toCharArray();
        int n = s.length - 1;
        int halfLength = n / 2;
        for (int i = 0; i <= halfLength; i++) {
            char temp = s[i];
            s[i] = s[n - i];
            s[n - i] = temp;
        }
        return new String(s);
    }
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        String s=scanner.nextLine();

        StringBuilder sb=new StringBuilder();
        String target[]=s.split(" ");
        for(String str:target){
            sb.append(reverse(str)+" ");
        }
        s=sb.toString();
        System.out.println(s.substring(0,s.length()));

    }


}
