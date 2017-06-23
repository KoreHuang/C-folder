package com.beidou.campus;

import java.util.Scanner;

/**
 * designed by Steve Ke on 2017/4/6.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/6
 */
public class FindNMinGap {

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int n=scanner.nextInt();

        int A[] = new int[2*n];

        for(int i=0;i<A.length;i++){
            A[i]=scanner.nextInt();
        }

        resolve(A);
    }

    static void resolve(int A[]) {
        int i;
        int j;
        int n2 = A.length;
        int n = n2 / 2;
        int sum = 0;
        // 计算数组总和
        for (i = 0; i < A.length; i++) {
            sum += A[i];
        }

        boolean flag[][] = new boolean[A.length + 1][sum / 2 + 1];
        for (i = 0; i < A.length; i++)
            for (j = 0; j < sum / 2 + 1; j++)
                flag[i][j] = false;

        flag[0][0] = true;
        for (int k = 0; k < n2; k++) {
            for (i = k > n ? n : k; i >= 1; i--) {
                for (j = 0; j <= sum / 2; j++) {
                    if (j >= A[k] && flag[i - 1][j - A[k]])
                        flag[i][j] = true;
                }
            }
        }
        for (j = sum / 2; j >= 0; j--) {
            if (flag[n][j]) {
                System.out.println("The minimum gap is " + Math.abs(2 * j - sum));
                break;
            }
        }
    }

}
