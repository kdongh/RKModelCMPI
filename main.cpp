//
// Created by DongHoon Kim on 11/16/20.
//

#include <iostream>
#include <fstream> //file I/O
#include <cstdlib> //atoi,atof...

#include <mpi.h>
#include <pthread.h>

//#include "modules/atomicUnit.h"
#include "complexNumber.h"
#include "basis.h"

int num_thread = 16;

void* Hello(void *multiArgPara);

struct MultipleArg{
    int rank;
    int MPI_rank;
};

int main(int argc, char** argv){

    SDMap_t input_parameter_si;

    //-------------------Insert Conditions-----------------------

    input_parameter_si.insert(std::pair<std::string,double>("NumberOfSite",atof(argv[1])));

    input_parameter_si.insert(std::pair<std::string,double>("NumberOfGrid",atof(argv[2])));
    input_parameter_si.insert(std::pair<std::string,double>("GridDistance",atof(argv[3])));
    input_parameter_si.insert(std::pair<std::string,double>("SiteDistance",atof(argv[4])));

    input_parameter_si.insert(std::pair<std::string,double>("ElasticConstant",atof(argv[5])));
    input_parameter_si.insert(std::pair<std::string,double>("PotentialV",atof(argv[6])));
    input_parameter_si.insert(std::pair<std::string,double>("PotentialFreq",atof(argv[7])));
    input_parameter_si.insert(std::pair<std::string,double>("ParticleMass",atof(argv[8])));

    input_parameter_si.insert(std::pair<std::string,double>("PulseAmp",atof(argv[9])));
    input_parameter_si.insert(std::pair<std::string,double>("PulseFreq",atof(argv[10])));
    input_parameter_si.insert(std::pair<std::string,double>("PulseAveT",atof(argv[11])));
    input_parameter_si.insert(std::pair<std::string,double>("PulseDelay",atof(argv[12])));


    int num_of_thread, num_of_process, current_rank;
    num_of_thread = 30;
    //-------------------pthread initialize-----------------------

    pthread_t* thread_handles;

    thread_handles = ;

    //-------------------MPI initialize-----------------------
    MPI_Init(NULL,NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &num_of_process);
    MPI_Comm_rank(MPI_COMM_WORLD, &current_rank);


    //-------------------MPI Datatype setting-----------------------
    MPI_Datatype mpi_complex_type;
    MPI_Type_contiguous(2, MPI_DOUBLE, &mpi_complex_type);
    MPI_Type_commit(&mpi_complex_type);

    int number_of_wavefunction_point = input_parameter_si.find("NumberOfGrid")->second;
    complexNumber send_to_right_wavefunction[number_of_wavefunction_point];
    complexNumber send_to_left_wavefunction[number_of_wavefunction_point];
    //-------------------rank 0-----------------------

    if(current_rank == 0){


    } else{

    }

    MPI_Finalize();
}