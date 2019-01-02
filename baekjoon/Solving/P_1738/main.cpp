#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    int intersection_cnt, edge_cnt, depart_edge, dest_edge, edge_weight;
    bool disconnected_flag = false;
    cin >> intersection_cnt >> edge_cnt;
    auto **intersection = new int*[intersection_cnt];
    for(int i=0; i<intersection_cnt; i++){
        intersection[i] = new int[intersection_cnt]();
    }
    // -1001 : not connected
    for(int i=0; i<intersection_cnt; i++){
        for(int j=0; j<intersection_cnt; j++){
            intersection[i][j] = 1001;
        }
    }
    for(int i=0; i<edge_cnt; i++){
        cin >> depart_edge >> dest_edge >> edge_weight;
        if(intersection[depart_edge][dest_edge] < edge_weight){
            intersection[depart_edge][dest_edge] = edge_weight;
        }
    }



}