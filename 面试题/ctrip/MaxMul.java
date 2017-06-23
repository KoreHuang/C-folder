package ctrip;

import java.util.Scanner;

/**
 * designed by Steve Ke on 2017/4/11.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/11
 */
public class MaxMul {
    private static long result=0;
    private static int data[]=new int[50];
    public static int solve(int n){
        if(n<2){
            return 0;
        }
        int i = 0;
        for (int j = 2; j <= n; j++) {
            data[i++] = j;
            n=n-j;
        }

        if (n!=0) {
            if (n == i + 1) {
                data[i-1]++;
                n--;
            }
            for (int j = 0; j < n; j++) {
                data[i-j-1]++;
            }
        }
        int max = 1;
        for (int j = 0; j < i; j++) {
            max *= data[j];
        }

        return max;
    }
    public static void main(String []args){
        Scanner scanner=new Scanner(System.in);
        int n=scanner.nextInt();

        System.out.println(solve(n));
    }



}
