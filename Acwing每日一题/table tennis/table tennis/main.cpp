//
//  main.cpp
//  table tennis
//
//  Created by Eunice on 2021/7/5.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct player {
    int ariTime,staTime,plaTime,vip;
}playerone;

struct tableNum {
    int endTime = 8 * 3600,num,vip;
};
bool cmp1(player a, player b);
bool cmp2(player a, player b);

void alloTable(int playerid,int tableid);
int nextVip(int vipid);
   
vector<player> players;
vector<tableNum> tables;


int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int k, m, viptable;
    for(int i = 0; i < n; i++){
        int hou, min, sen, temp, flag;
        scanf("%d:%d:%d %d %d",&hou,&min,&sen,&temp,&flag);
        playerone.ariTime = hou * 3600 + min * 60 + sen;
        playerone.staTime = 21 * 3600;
        if(playerone.ariTime >= 21 * 3600) continue;
        if(temp <= 120){
          playerone.plaTime =  temp*60;
        }else{
            playerone.plaTime = 7200;
        }
        if(flag == 1){
          playerone.vip =  1;
        }else{
          playerone.vip =  0;
        }
        players.push_back(playerone);
    }
    cin >> k >> m;
    tables.resize(k+1);
    for(int i = 0; i < m; i++){
        cin >> viptable;
        tables[viptable].vip = 1;
    }
    sort(players.begin(),players.end(),cmp1);
    int i = 0, vipid = -1;
    vipid = nextVip(vipid);
    while(i < players.size()){
        int in = -1, minEnd = 999999999;
        for(int j = 1; j <= k; j++){
            if(tables[j].endTime < minEnd){
                minEnd = tables[j].endTime;
                in = j;
            }
        }
        if(tables[in].endTime >= 21 * 3600) break;
        if(players[i].vip == 1 && i < vipid){
            i++;
            continue;
        }
        if(tables[in].vip == 1){
            if(players[i].vip == 1){
                alloTable(i,in);
                if(vipid == i) vipid = nextVip(vipid);
                i++;
            }else{
                if(vipid < players.size() && players[vipid].ariTime <= tables[in].endTime){
                    alloTable(vipid, in);
                    vipid = nextVip(vipid);
                }else {
                    alloTable(i,in);
                    i++;
                }
            }
        }else {
            if(players[i].vip == 0){
                alloTable(i,in);
                i++;
            }else{
                int vipindex = -1, minvipendtiome = 999999999;
                for(int j = 1; j <= k; j++){
                    if(tables[j].vip == 1 && tables[j].endTime < minvipendtiome){
                        minvipendtiome = tables[j].endTime;
                        vipindex = j;
                    }
                }
                if(vipindex != -1 && players[i].ariTime >= tables[vipindex].endTime) {
                    alloTable(i, vipindex);
                    if(vipid == i) vipid = nextVip(vipid);
                    i++;
                } else {
                    alloTable(i, in);
                    if(vipid == i) vipid = nextVip(vipid);
                    i++;
                }
            }
        }
    }
    sort(players.begin(), players.end(), cmp2);
      for(i = 0; i < players.size() && players[i].staTime < 21 * 3600; i++) {
          printf("%02d:%02d:%02d ", players[i].ariTime / 3600, players[i].ariTime % 3600 / 60, players[i].ariTime % 60);
          printf("%02d:%02d:%02d ", players[i].staTime / 3600, players[i].staTime % 3600 / 60, players[i].staTime % 60);
          printf("%.0f\n", round((players[i].staTime - players[i].ariTime) / 60.0));
      }
      for(int i = 1; i <= k; i++) {
          if(i != 1) printf(" ");
          printf("%d", tables[i].num);
      }
    return 0;
}
bool cmp1(player a, player b) {
    return a.ariTime < b.ariTime;
}
bool cmp2(player a, player b) {
    return a.staTime < b.staTime;
}
void alloTable(int playerid,int tableid) {
    if(players[playerid].ariTime <= tables[tableid].endTime){
        players[playerid].staTime = tables[tableid].endTime;
    }else{
        players[playerid].staTime = players[playerid].ariTime;
    }
    tables[tableid].endTime = players[playerid].staTime + players[playerid].plaTime;
    tables[tableid].num++;
}
int nextVip(int vipid){
    vipid++;
    while(vipid < players.size() && players[vipid].vip == 0) vipid++;
    return vipid;
}
