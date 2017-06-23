import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static class Node{
        public int x;
        public int y;
        public Node(){

        }
        public Node(int x,int y){
            this.x=x;
            this.y=y;
        }
    }
    static class Speed{
        public int walk;
        public int taxi;
        public Speed(){

        }
        public Speed(int x,int y){
            this.walk=x;
            this.taxi=y;
        }
    }
    public static int resolve(){
        Scanner scanner=new Scanner(System.in);
        int taxiNum=scanner.nextInt();
        Node nodes[]=new Node[taxiNum];
        Node office=new Node();
        Speed speed=new Speed();
        int cost[]=new int[taxiNum+1];

        for(int i=0;i<taxiNum;i++){
            nodes[i]=new Node();
            nodes[i].x=scanner.nextInt();
        }
        for(int i=0;i<taxiNum;i++){
            nodes[i].y=scanner.nextInt();
        }
        office.x=scanner.nextInt();
        office.y=scanner.nextInt();
        speed.walk=scanner.nextInt();
        speed.taxi=scanner.nextInt();
        cost[taxiNum]=(Math.abs(office.x)+Math.abs(office.y))*speed.walk;   //全程步行所花费时间
        for(int i=0;i<taxiNum;i++){
            cost[i]=(Math.abs(nodes[i].x)+Math.abs(nodes[i].y))*speed.walk+
                        (Math.abs(nodes[i].x-office.x)+Math.abs(nodes[i].y-office.y))*speed.taxi;
        }
        Arrays.sort(cost);
        return cost[0];
    }
    public static void main(String []args){
        int x=resolve();
        System.out.println(x);
    }

}
