package Alibaba;

import java.util.Scanner;
import java.util.regex.Pattern;

/**
 * designed by Steve Ke on 2017/4/26.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/26
 */
public class WordFilter {

    public static boolean filter(String src,String pattern){

        String patterns_one=pattern.replaceAll("\\?","\\.").replaceAll("\\*","(\\.\\*)");
        return Pattern.matches(patterns_one,src);
    }
    public static void main(String []args){
        Scanner scanner=new Scanner(System.in);

        String src=scanner.nextLine();
        String p=scanner.nextLine();
        System.out.print(filter("200-trade-done","200-?*-done")?1:0);

    }




}
