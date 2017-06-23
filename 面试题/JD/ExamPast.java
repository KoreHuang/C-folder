package JD;

import java.util.Scanner;

/**
 * designed by Steve Ke on 2017/4/7.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/7
 */
public class ExamPast {
    public static int rightNum=0;

    public static double clac(float[] past,boolean []vtag){
        double res=1.0;
        for(int i=0;i<past.length;i++){
            if(vtag[i]){
                res*=past[i];
            }else {
                res*=(1-past[i]);
            }
        }
        return res;
    }
    public static boolean trigger(boolean []vtag){
        int cnt=0;
        for(int i=0;i<vtag.length;i++){
            if(vtag[i]) cnt++;
        }
        return cnt>=rightNum;
    }
    public static double getAnswer(int currentStep,boolean vtag[],boolean tag,float[] past){
        if(currentStep<0){
            if(trigger(vtag)&&tag){
                return clac(past,vtag);
            }else {
                return 0;
            }
        }


        int cnt=0;
        for(int i=vtag.length-1;i>currentStep;i--){
            if(!vtag[i])    cnt++;
            if(cnt>past.length-rightNum) return 0;
        }

        vtag[currentStep]=tag;
        return getAnswer(currentStep-1,vtag,true,past)+getAnswer(currentStep-1,vtag,false,past);
    }
    public static void main(String []args){
        Scanner scanner=new Scanner(System.in);
        int n=scanner.nextInt();
        float question[]=new float[n];
        boolean [] vtag=new boolean[n];
        for(int i=0;i<n;i++){
            question[i]=0.01f*scanner.nextInt();
            vtag[i]=true;
        }
        rightNum=(int)Math.round(n*0.6+0.5);
        System.out.printf("%#.5f",getAnswer(question.length-1,vtag,true,question)+
                getAnswer(question.length-1,new boolean[question.length],false,question));
    }
}
