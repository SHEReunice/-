//
//  main.cpp
//  201912-2	回收站选址
//
//  Created by Eunice on 2021/7/21.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
struct node{
    int x;
    int y;
}node[1010];
int score[5]={0};
int cnt=0;

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> node[i].x >> node[i].y;
    }
    for(int i = 0; i < n; i++){
        cnt = 0;
        int flag = 0;
        int sx = node[i].x,sy = node[i].y;
        for(int j = 0; j < n; j++){
            if(node[j].x == sx && node[j].y == sy+1){
                for(int k = 0; k < n; k++){
                    if(node[k].x == sx && node[k].y == sy-1){
                        for(int m = 0; m < n; m++){
                            if(node[m].x == sx+1 && node[m].y == sy){
                                for(int q = 0; q < n; q++){
                                    if(node[q].x == sx-1 && node[q].y == sy){
                                        flag = 1;
                                        for(int o = 0; o < n; o++){
                                            if(node[o].x == sx+1 && node[o].y == sy+1){
                                                cnt++;
                                            }else if(node[o].x == sx+1 &&  node[o].y == sy-1){
                                                cnt++;
                                            }else if(node[o].x == sx-1 && node[o].y == sy+1){
                                                cnt++;
                                            }else if(node[o].x == sx-1 && node[o].y == sy-1){
                                                cnt++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(flag == 1){
            score[cnt]++;
        }
    }
    for(int i = 0; i < 5; i++){
        cout << score[i] << endl;
    }
    return 0;
}
