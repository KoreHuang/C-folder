package leetcode;



/**
 * designed by Steve Ke on 2017/4/15.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/15
 */

/**

 2.You are given two non-empty linked lists representing two non-negative integers. The digits are stored
 in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as
 a linked list.You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8

 */


public class ListAddNum {

    static class ListNode{
        int val;
        ListNode next;
        ListNode(int x){
            val=x;
        }
    }
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result=new ListNode(0);
        ListNode p1=l1;
        ListNode p2=l2;
        ListNode p=result;
        int c=0,s;
        while (p1!=null&&p2!=null){
            s=(p1.val+p2.val+c)%10;
            p=p.next=new ListNode(s);
            c=(p1.val+p2.val+c)/10;
            p1=p1.next;
            p2=p2.next;
        }
        if(p1==null&&p2==null&&c==1){
            p.next=new ListNode(c); return result.next;
        }
        if(p1==null){
            while (p2!=null){
                s=(p2.val+c)%10;
                p=p.next=new ListNode(s);
                c=(p2.val+c)/10;
                p2=p2.next;
            }
        }else {
            while (p1!=null){
                s=(p1.val+c)%10;
                p=p.next=new ListNode(s);
                c=(p1.val+c)/10;
                p1=p1.next;
            }
        }
        if(c==1){
            p.next=new ListNode(c); return result.next;
        }
        return result.next;
    }
}
