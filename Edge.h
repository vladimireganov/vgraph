//
//  Edge.h
//  graph2
//
//  Created by Владимир Еганов on 18.03.2018.
//  Copyright © 2018 Ульяна Сыроегина. All rights reserved.
//

#ifndef Edge_h
#define Edge_h
struct Edge{
    //private:
    int first, second;
    double cost;
    //public:
    Edge(int start=-1,int finish=-1, double cost_=0.0){
        first = start;
        second = finish;
        cost = cost_;
    }
    bool operator== (const Edge& e )const{
        return (this->first==e.first)&&(this->second==e.second)&&(this->cost==e.cost);
    }
};
struct hash_edge{
    size_t operator() (const Edge& e )const{
        return std::hash<int> ()(e.first+e.second);
    }
};

#endif /* Edge_h */
