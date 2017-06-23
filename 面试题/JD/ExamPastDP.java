package JD;

/**
 * designed by Steve Ke on 2017/4/21.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/21
 */

import java.util.Scanner;

/**
 * 小明同学要参加一场考试，考试一共有n道题目，小明必须做对至少60%的题目才能通过考试。考试结束后，
 * 小明估算出每题做对的概率，p1,p2,...,pn。你能帮他算出他通过考试的概率吗？
 */
public class ExamPastDP {
    /**
     *
     * 概率dp
     *  通过每道题的概率:
     *      past[0...n-1]
     *  针对于当前第i道题目，小明做对的概率 past[i]  做错的概率 1-past[i]
     *  至少需要做对 Math.roud(0.6*n+0.5) rightNum道题目 小明才能通过考试
     *
     *  定义问题状态
     *      pastExam(i,j) 表示 ：第i道题 做对j道的概率
     *   方程
     *      pastExma(i,j)=pastExma(i-1,j-1)*past[i]+pastExam(i-1,j)*(1-past[i])
     *   方程解释：
     *      针对于当前的第i道题目，小明要确保做对j道分为两种情况：
     *          1.小明做对这道题，如果要确保总共做对j道，只要第i-1个题目做对j-1道即可
     *          2.小明做错这道题，如果要确保总共做对j道，只要第i-1个题目做对j道即可
     *   问题的解：
     *      第n个数 所有满足解大于正确数rightNum的解累加和
     *   问题边界
     *      针对于所有题目都做错的概率可以求解 (1-past[i])的迭乘 i:1-n
     */

    public static double solve(float[] past){
        int rightNum=(int) Math.round(past.length*0.6+0.5);
        double [][]pastExam=new double[past.length+1][past.length+1];
        //一开始所有的题目都没做对 past[0] 表示i为1的情况
        pastExam[1][0]=1-past[0]; //第1道题目做对0道的概率
        pastExam[1][1]=past[0];   //第1道题目做对1道的概率
        for(int i=2;i<past.length+1;i++){
            pastExam[i][0]=pastExam[i-1][0]*(1-past[i-1]);//第i道题目做对0道的概率
        }

        for(int i=2;i<=past.length;i++){
            for(int j=1;j<=i;j++){
                pastExam[i][j]=pastExam[i-1][j-1]*past[i-1]+pastExam[i-1][j]*(1-past[i-1]);
            }
        }
        double ans=0;
        for(int i=rightNum;i<pastExam.length;i++){
            ans+=pastExam[past.length][i];
        }
        return ans;
    }

    public static void main(String []args){
        Scanner scanner=new Scanner(System.in);
        int n=scanner.nextInt();
        float question[]=new float[n];
        for(int i=0;i<n;i++){
            question[i]=0.01f*scanner.nextInt();
        }
        System.out.println(solve(question));

    }

}
