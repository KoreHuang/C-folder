package qunar;

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
public class NearlestTrace {
    public static final int INF=65535;

    static class AdjMtrix{
        int cost;
        String data;
    }



//    public static int Dijkstra(AdjMtrix Arcs[][Max_CityNum],CiType StartCity,CiType EndCity){
//        int i,j,k = 0,min;
//        int []dist=new int[];
//        boolean []Tag=new int[];
//            memset(Tag,0,CityNum*sizeof(int));
//            for(i=0;i<CityNum;i++){
//                dist[i]=Arcs[StartCity][i].cost;
//                if(dist[i]!=INF){
//                    Path[i].city=StartCity;
//                    Path[i].TrafficNo=Arcs[StartCity][i].TrafficNo;
//                }
//            }
//            Tag[StartCity]=1;
//            while(Tag[EndCity]==0){
//                min=INF;
//                for(j=0;j<CityNum;j++){
//                    if(!Tag[j]&&dist[j]<min){
//                        min=dist[j];
//                        k=j;
//                    }
//                }
//                if(min==INF) return 0;
//                Tag[k]=1;
//                for(j=0;j<CityNum;j++){
//                    if(!Tag[j]&&(dist[k]+Arcs[k][j].cost<dist[j])){
//                        Path[j].city=k;
//                        Path[j].TrafficNo=Arcs[k][j].TrafficNo;
//                        dist[j]=Arcs[k][j].cost+dist[k];
//                    }
//                }
//            }
//            free(dist);
//            free(Tag);
//            return 1;
//    }








}
