package leetcode;

/**
 * designed by Steve Ke on 2017/4/16.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/16
 */
public class JavaExtends  {
    public static void main(String []args){
        System.out.println(new B().getValue());
    }

    static class A{
        protected int value;

        public A(int value) {
            setValue(value);
        }
        public void setValue(int value){
            this.value=value;
        }

        public int getValue(){
           try{
               value++;
               return value;
           } catch (Exception e){
               System.out.println(e.toString());
           }finally {
               this.setValue(value);
               System.out.println(value);
           }
           return value;
        }



    }


    static class B extends A{
        public B(){
            super(5);
            setValue(getValue()-3);
        }

        public void setValue(int value){
            super.setValue(2*value);
        }
    }





}
