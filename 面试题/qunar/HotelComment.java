package qunar;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

/**
 * designed by Steve Ke on 2017/4/1.
 *
 * @author Steve Ke
 *         e-mail  huangke7296@foxmail.com
 *         github  https://github.com/KoreHuang
 *         oschina https://git.oschina.net/steveKe
 * @version JDK 1.8.0_111
 * @since 2017/4/1
 */

class Hotel{
    int no;
    int environment;
    int soft;
    int service;
    int equipment;
    int traffic;
    int min;
    double avg;
    public Hotel(int no, int environment, int soft, int service, int equipment, int traffic) {
        this.no = no;
        this.environment = environment;
        this.soft = soft;
        this.service = service;
        this.equipment = equipment;
        this.traffic = traffic;
        avg=(this.environment +
             this.soft+
             this.service +
             this.equipment+
             this.traffic)/5;
        min=getMinvalue(environment, soft,service, equipment, traffic);
    }


    public static int getMinvalue(int environment, int soft, int service, int equipment, int traffic){
        int data[]=new int[5];
        data[0] = environment;
        data[1] = soft;
        data[2] = service;
        data[3] = equipment;
        data[4] = traffic;
        int min=data[0];
        for(int i=1;i<5;i++){
            if(data[i]<min){
                min=data[i];
            }
        }
        return min;
    }

    public Hotel(){}

    public int getNo() {
        return no;
    }

    public void setNo(int no) {
        this.no = no;
    }

    public int getEnvironment() {
        return environment;
    }

    public void setEnvironment(int environment) {
        this.environment = environment;
    }

    public int getSoft() {
        return soft;
    }

    public void setSoft(int soft) {
        this.soft = soft;
    }

    public int getService() {
        return service;
    }

    public void setService(int service) {
        this.service = service;
    }

    public int getEquipment() {
        return equipment;
    }

    public void setEquipment(int equipment) {
        this.equipment = equipment;
    }

    public int getTraffic() {
        return traffic;
    }

    public void setTraffic(int traffic) {
        this.traffic = traffic;
    }
}
class HotelComparatorByMin implements Comparator<Hotel> {

    @Override
    public int compare(Hotel o1, Hotel o2) {
        return o1.min - o2.min;
    }
}
class HotelComparatorByAvg implements Comparator<Hotel> {

    @Override
    public int compare(Hotel o1, Hotel o2) {
        return (int)(o2.avg - o1.avg);
    }
}


public class HotelComment {
    public static void main(String []args){
        Scanner scanner=new Scanner(System.in);
        int n=scanner.nextInt();
        int environment;
        int soft;
        int service;
        int equipment;
        int traffic;

        Hotel hotels[]=new Hotel[n];

        for(int i=0;i<n;i++){
            environment=scanner.nextInt();
            soft=scanner.nextInt();
            service=scanner.nextInt();
            equipment=scanner.nextInt();
            traffic=scanner.nextInt();
            hotels[i]=new Hotel(i,environment,soft,service,equipment,traffic);
        }

        Hotel hotelsByMin[]=new Hotel[n];
        System.arraycopy(hotels,0,hotelsByMin,0,n);
        Arrays.sort(hotels,new HotelComparatorByAvg());
        Arrays.sort(hotelsByMin,new HotelComparatorByMin());
        for(int i=0;i<5;i++){
            System.out.println( hotels[i].getNo());
        }




    }
}
