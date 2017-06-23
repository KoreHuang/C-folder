package toutiao;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;
import java.util.regex.Pattern;

/**
 * designed by Steve Ke on 2017/3/30.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/3/30
 */
public class PatternMatch {


    public static void resolve(String []segment,String []matchStr){

        int []commenWordCnt=new int[segment.length];

        for(int i=0;i<matchStr.length;i++){
            String [] words=matchStr[i].split(" ");
            Set<String> wordSet=getUniqueWord(words);
            commenWordCnt=new int[segment.length];
            for(int k=0;k<segment.length;k++) {
                Iterator<String> iterator = wordSet.iterator();
                while (iterator.hasNext()) {
                    if (Pattern.matches(".*\\s"+iterator.next()+"\\s.*", " "+segment[k].toLowerCase()+" ")) {
                        commenWordCnt[k]++;
                    }
                }
            }
            System.out.println(segment[getMaxIndex(commenWordCnt)]);
        }

    }


    //获取最大值的下标
    public static int getMaxIndex(int[] arr){
        int maxIndex = 0;   //获取到的最大值的角标
        for(int i=0; i<arr.length; i++){
            if(arr[i] > arr[maxIndex]){
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    public static Set<String> getUniqueWord(String []words){
        Set<String> wordSet=new HashSet<String>();
        for(int i=0;i<words.length;i++) {
            wordSet.add(words[i].toLowerCase());
        }
        return wordSet;
    }


    public static void main(String []args){
        Scanner scanner=new Scanner(System.in);

        int N,M;
        N=scanner.nextInt();
        M=scanner.nextInt();

        String segment[]=new String[N];
        String matchStr[]=new String[M];

        scanner.nextLine();

        for(int i=0;i<N;i++){
            segment[i]=scanner.nextLine();
        }
        for(int i=0;i<M;i++){
            matchStr[i]=scanner.nextLine();
        }

        resolve(segment,matchStr);


    }


}
