//
//  main.cpp
//  vgraph
//
//  Created by Владимир Еганов on 22.04.2018.
//  Copyright © 2018 Ульяна Сыроегина. All rights reserved.
//

#include <iostream>
#include "DenseGraph.h"
#include "costGraph.h"
int main(int argc, const char * argv[]) {
    
    DenseGRAPH notDAG(5 ,1);
    
    notDAG.insert(new Edge(0, 1, 2.0));
    notDAG.insert(new Edge(1, 2, 4.7));
    notDAG.insert(new Edge(2, 3, 2.3));
    notDAG.insert(new Edge(3, 4, 1.7));
    notDAG.insert(new Edge(4, 0, 3.14));
//    notDAG.insert(new Edge(0, 1, ));
//    notDAG.insert(new Edge(0, 5, ));
//    notDAG.insert(new Edge(0, 6, ));
//    notDAG.insert(new Edge(2, 0, ));
//    notDAG.insert(new Edge(2, 3, ));
//    notDAG.insert(new Edge(3, 2));
//    notDAG.insert(new Edge(3, 5));
//    notDAG.insert(new Edge(4, 2));
//    notDAG.insert(new Edge(4, 3));
//    notDAG.insert(new Edge(4, 11));
//
//    notDAG.insert(new Edge(5, 4));
//    notDAG.insert(new Edge(6, 4));
//    notDAG.insert(new Edge(6, 9));
//    notDAG.insert(new Edge(7, 6));
//    notDAG.insert(new Edge(7, 8));
//    notDAG.insert(new Edge(8, 7));
//    notDAG.insert(new Edge(8, 9));
//    notDAG.insert(new Edge(9, 10));
//    notDAG.insert(new Edge(9, 11));
//    notDAG.insert(new Edge(10, 12));
//    notDAG.insert(new Edge(11, 12));
//    notDAG.insert(new Edge(12, 9));
    draw_Cost_Graph<DenseGRAPH> drawGraph(notDAG);
    drawGraph.draw();
    return 0;
}
