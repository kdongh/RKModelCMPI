//
// Created by DongHoon Kim on 11/24/20.
//

#include "tdSch.h"

tdSch::tdSch(int numOfNode, int numOfSite, double *parameterIn) {
    //MPI Setting
    int rank;

    //Basis call per rank

    //time loop
    double startTimeAU, endTimeAU, dTimeAU;
    double currentTImeAU;

    int maxTimeLengthInteger;

    maxTimeLengthInteger = int((endTimeAU - startTimeAU) / dTimeAU);

    for (auto iTime = 0;iTime<maxTimeLengthInteger;iTime++){

        currentTImeAU = iTime*dTimeAU;

        if(rank == 0){

        }

        //  rungeKutta

        //      k1
        //          hamiltonian
        //          sharing
        //              in each node, between nodes
        //      k2
        //      k3
        //      k4

        //dataOut or Out in each time step

    }

}