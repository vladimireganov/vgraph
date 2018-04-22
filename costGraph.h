//
//  costGraph.h
//  vgraph
//
//  Created by Владимир Еганов on 22.04.2018.
//  Copyright © 2018 Ульяна Сыроегина. All rights reserved.
//

#ifndef costGraph_h
#define costGraph_h

#include "DenseGraph.h"
#include <fstream>
template <class Graph>
class draw_Cost_Graph
{
private:
    const Graph &G;
    
public:
    draw_Cost_Graph(const Graph &_G) :G(_G)
    {
    }
    
    void draw()
    {
        char dir;
        ofstream myfile;
        myfile.open("graph");
        if(G.D()){
            myfile << "Graph ";
            dir='-';
        }
        else{
            myfile << "Digraph ";
            dir='>';
        }
        myfile << "G{\ngraph [overlap=scale sep=3.5];\nnode [shape=circle];\n";
        for (int i = 0; i < G.V(); i++)
        {
            typename Graph::adjiterrator A(G, i);
            for (Edge* j = A.begin(); !A.end(); j = A.next())
            {
                if ((i < j->second ) || !G.D())
                {
                    myfile << '\t' << i << " -" << dir << " " << j->second << "[label = \"" <<j->cost<<"\" len = "<<j->cost<<"];" << endl;
                }
            }
        }
        myfile << "}";
        myfile.close();
        system("/usr/local/bin/neato graph -Tpng -o graph.png && open graph.png");
    }
};
#endif /* costGraph_h */
