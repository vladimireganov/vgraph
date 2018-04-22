//
//  DenseDraph.h
//  vgraph
//
//  Created by Владимир Еганов on 22.04.2018.
//  Copyright © 2018 Ульяна Сыроегина. All rights reserved.
//

#ifndef DenseDraph_h
#define DenseDraph_h

#include "Edge.h"
#include <vector>
using namespace std;
class DenseGRAPH
{
private:
    vector<vector<Edge*>> adj;
    bool dir;
    int vCount,eCount;
public:
    DenseGRAPH(){
        vCount=0;
        eCount=0;
    }
    DenseGRAPH(DenseGRAPH& G){
        dir=G.D();
        vCount=G.V();
        eCount=G.E();
        adj = vector<vector<Edge*>>(vCount,vector<Edge*>(vCount,0));
        for (int i = 0; i < G.V()-1; i++) {
            for (int k = 0; k < G.V(); k++) {
                if (G.way(i, k)) {
                    adj[i][k]=G.way(i, k);
                }
            }
        }
    }
    DenseGRAPH(int ver,bool twoside){
        vCount = ver;
        eCount = 0;
        adj = vector<vector<Edge*>>(ver,vector<Edge*>(ver,0));
        dir = twoside;
        
    }
    int V()const{return vCount;}
    int E()const{return eCount;}
    bool D()const{return dir;}
    void insert(Edge* e){
        if (!adj[e->first][e->second]) {
            eCount++;
        }
        adj[e->first][e->second]=e;
        
        if (dir) {
            adj[e->second][e->first]=new Edge(e->second,e->first,e->cost);
        }
    }
    void remove(Edge* e){
        if (adj[e->first][e->second]) {
            eCount--;
        }
        adj[e->first][e->second]=NULL;
        
        if (dir) {
            adj[e->second][e->first]=NULL;
        }
    }
    Edge* way(int first, int second)const{
        return adj[first][second];
    }
    class adjiterrator;
    friend class adjiterrator;
    
};
class DenseGRAPH::adjiterrator{
private:
    const DenseGRAPH &G;
    int i=-1,v;
public:
    adjiterrator(const DenseGRAPH &Gr,int _v):G(Gr),v(_v){}
    Edge* next(){
        for (i++; i<G.V(); i++) {
            if (G.adj[v][i]) {
                return G.adj[v][i];
            }
        }
        return NULL;
    }
    Edge* begin(){
        i=-1;
        return next();
    }
    bool end(){
        return i >= G.V();
    }
};

#endif /* DenseDraph_h */
