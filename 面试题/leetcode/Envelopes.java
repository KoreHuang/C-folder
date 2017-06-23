package leetcode;

import java.util.Arrays;
import java.util.Comparator;

/**
 * designed by Steve Ke on 2017/4/23.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/23
 */

/**
 * You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope
 * can fit into another if and only if both the width and height of one envelope is greater than the width
 * and height of the other envelope.
 * What is the maximum number of envelopes can you Russian doll? (put one inside other)
 *
 *  原问题：
 *    envelopes : [[5,4] [6,4] [6,7] [2,3]]
 *  输出:
 *     3
 *  分析：
 *      问题规模二维度，整体分析很复杂。因此我们先看高度上满足套娃条件的数据是如何排布的，再来规划整体上的最优解
 *      envelopes按照高度排序后：   [[2,3] [5,4] [6,4] [6,7]]
 *          每个套娃最多套的数目：   [  1  ,  2  ,  2  ,  3  ]
 *      状态定义：max[1->n] 针对于第i个套娃，能套的最大的数目
 *      状态转移方程：(比较复杂)
 *              i:1->n
 *                max[i]=1
 *                  j:1->i-1
 *                      max[i]=(envelopes[j]<<envelopes[i]) ? Math.max(envelopes[j] j:1->i-1)+1:max[i];
 *      方程解释：
 *           每个套娃能套自身，max数组初始值都为 1
 *                如果第j个套娃能够套进当前套娃i  则 max[i] 的值为前 i-1 个套娃能套进第i个中的最大值加一 否则维持max[i]原值
 *      问题的解：
 *           max数组中的最大值
 *
 *
 */
public class Envelopes {
    public int maxEnvelopes(int[][] envelopes) {
        if(envelopes==null||envelopes.length==0) return 0;
        //按照高度排序
        Comparator<int[]> comparator=new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0]-o2[0];
            }
        };
        Arrays.sort(envelopes,comparator);
        int ans=1;
        int max[]=new int[envelopes.length];
        int tmp;
        for(int i=0;i<max.length;i++){
            max[i]=1;
            tmp=0;
            for(int j=0;j<i;j++){
                if(envelopes[j][0]<envelopes[i][0]&&envelopes[j][1]<envelopes[i][1]){
                    tmp=max[j]>tmp?max[j]:tmp;
                    max[i]=tmp+1;
                }
            }
            ans=Math.max(ans,max[i]);
        }
        return ans;
    }
    public static void main(String []args){
        Envelopes envelopes=new Envelopes();
        int src[][]={{5,4},{6,4},{6,7},{2,3},{1,1}};
        System.out.println(envelopes.maxEnvelopes(src));
    }
}
