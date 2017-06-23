/**
 * designed by Steve Ke on 2017/4/19.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/19
 */
public class SingletonObject {
    private static class LazyLolder {
        private static final SingletonObject INSTANCE = new SingletonObject();
    }
    private SingletonObject (){}
    public static final SingletonObject getInstance() {
        return LazyLolder.INSTANCE;
    }
}