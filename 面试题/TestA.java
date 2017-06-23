import java.util.Scanner;

/**
 * designed by Steve Ke on 2017/3/25.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/3/25
 */
public class TestA {
    public static int count=0;
    public static void countEven(String str){
        if(str.length()==1){
            return ;
        }
        char[] chars=str.toCharArray();
        int temp[]=new int[255];
        for(int i=0;i<chars.length;i++){
            temp[chars[i]-0]+=1;
        }
        boolean tag=true;
        for(int i=0;i<temp.length;i++){
            if((temp[i]%2)!=0){
                tag=false;
            }
        }
        if(tag)
            count++;
        countEven(str.substring(1));
    }
    public static void main(String []args){
        Scanner scanner=new Scanner(System.in);
        String str=scanner.nextLine();
        countEven(str);
        System.out.println(count);
    }

}
