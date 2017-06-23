package Alibaba;

import java.util.Scanner;
import java.util.Stack;

/**
 * designed by Steve Ke on 2017/4/26.
 *
 * @author Steve Ke
 * e-mail  huangke7296@foxmail.com
 * github  https://github.com/KoreHuang
 * oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/26
 */

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String line = in.nextLine();
        if (line != null && !line.isEmpty()) {
            int res = solve(line.trim());
            System.out.println(String.valueOf(res));
        }
    }

    public static int solve(String expr) {
        String[] list = expr.split(" ");
        Stack<Integer> last = new Stack<Integer>();
        Integer a;
        Integer b;
        int size = 0;
        for (String str : list) {
            if (str.matches("\\d+")) {
                last.add(Integer.parseInt(str));
                if (++size > 16) {
                    return -2;
                }

            } else {
                switch (str) {
                    case "^": {
                        if (--size < 0) {
                            return -1;
                        }
                        a = last.pop();
                        last.push(++a);
                        size++;
                        break;
                    }
                    case "+": {
                        size -= 2;
                        if (size < 0) {
                            return -1;
                        }
                        a = last.pop();
                        b = last.pop();
                        last.push(a + b);
                        size++;
                        break;
                    }
                    case "*": {
                        size -= 2;
                        if (size < 0) {
                            return -1;
                        }
                        a = last.pop();
                        b = last.pop();
                        last.push(a * b);
                        size++;
                        break;
                    }
                }
            }
        }
        return last.pop();
    }
}