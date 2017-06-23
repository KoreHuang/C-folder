package com.beidou.campus;

import java.util.concurrent.Semaphore;
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
public class ThredPrint {


        private static Semaphore semaphore1 = new Semaphore(0);
        private static Semaphore semaphore2 = new Semaphore(0);
        private static Semaphore semaphore3 = new Semaphore(0);
        public Thread t1;
        public Thread t2;
        public Thread t3;

        int count = 10;

        public ThredPrint() {
            t1 = new Thread() {
                public void run() {
                    try {
                        semaphore3.release();
                        int i = 0;
                        while(i++ < count) {
                            semaphore3.acquire();
                            System.out.print("A");
                            semaphore1.release();
                        }
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            };
            t2 = new Thread() {
                public void run() {
                    try {
                        int i = 0;
                        while(i++ < count) {
                            semaphore1.acquire();
                            System.out.print("B");
                            semaphore2.release();
                        }
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            };
            t3 = new Thread() {
                public void run() {
                    try {
                        int i = 0;
                        while(i++ < count) {
                            semaphore2.acquire();
                            System.out.print("C");
                            semaphore3.release();
                        }
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            };

        }

        public void run() {
            t1.start();
            t2.start();
            t3.start();
        }

        public static void main(String args[]) throws Exception {
            ThredPrint t = new ThredPrint();
            t.run();
        }

}
