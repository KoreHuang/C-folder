/**
 * designed by Steve Ke on 2017/3/26.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/3/26
 */
public class Derived extends Base {
    public int data=1;

    @Override
    public void func() {
        System.out.println("derived class func..."+data);
    }

    public static void main(String []args){
        Base temp=new Derived();
        temp.func();


    }
}
