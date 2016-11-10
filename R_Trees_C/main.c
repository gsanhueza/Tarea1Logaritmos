#include "rectangle.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>

void TestGreene(int initial);
void TestLinear(int numbers);

int main(int argc, char *argv[]) {
     /* Inicializa el random, si no se cambia el parametro lanzara siempre la misma secuencia */
    int initial = atoi(argv[1]);
    srand((unsigned int) initial%73);
    if (atoi(argv[2])>6)
        TestLinear(initial);
    else
        TestGreene(initial);




}

void TestGreene(int initial) {
    printf("begin test Greene for %d rectangles\n", initial);
    struct timespec start,finish,startMono,finishMono;
    double time_spent = 0, time_spent_mono= 0;

    Node *headerGreene = createNode();
    headerGreene->rectArray[0] = bateriaRectangulos(0);
    headerGreene->occupied = 1;
    headerGreene->this_node_filename = "Nodes/HeaderGreene.bin";
    char *node = writeToDisk(headerGreene);
    clock_gettime(CLOCK_REALTIME, &start);
    clock_gettime(CLOCK_MONOTONIC,&startMono);


    for(int i = 1; i < initial; i++) {
        Rectangle * rect = bateriaRectangulos(i);
        insertToRootGreene(node, rect);
    };

    clock_gettime(CLOCK_REALTIME, &finish);
    clock_gettime(CLOCK_MONOTONIC, &finishMono);
    time_spent =  (finish.tv_sec-start.tv_sec) + (double)(finish.tv_nsec-start.tv_nsec)/1000000000.0;
    time_spent_mono =     (finishMono.tv_sec-startMono.tv_sec) + (double)(finishMono.tv_nsec-startMono.tv_nsec)/1000000000.0;
    printf("Clock real time in Green insert: %f\n Clock mono time in Green insert, %f \n", time_spent, time_spent_mono);
    setAccessToDisk(0);
    clock_gettime(CLOCK_REALTIME, &start);
    clock_gettime(CLOCK_MONOTONIC,&startMono);

    for (int i = 0; i <(int)1.0*initial/10 ; i++ ) {
        Rectangle *rect = bateriaRectangulos(i);
        search(node, rect);
    }
    clock_gettime(CLOCK_REALTIME, &finish);
    clock_gettime(CLOCK_MONOTONIC, &finishMono);
    time_spent =  (finish.tv_sec-start.tv_sec) + (double)(finish.tv_nsec-start.tv_nsec)/1000000000.0;
    time_spent_mono =     (finishMono.tv_sec-startMono.tv_sec) + (double)(finishMono.tv_nsec-startMono.tv_nsec)/1000000000.0;
    printf("Clock real time spent in Greene Search : %f , access to Disk (write+read): %d \n", time_spent,getAccessToDisk());
    printf("Clock mono time spent in Greene Search : %f \n", time_spent_mono);
}


void TestLinear(int initial) {
    printf("begin test Linear for %d rectangles\n", initial);
    double time_spent = 0, time_spent_mono= 0;
    struct timespec start,finish,startMono,finishMono;

    Node *headerLinear = createNode();
    headerLinear->rectArray[0] = bateriaRectangulos(0);
    headerLinear->occupied = 1;
    headerLinear->this_node_filename = "Nodes/HeaderLinear.bin";
    char *node = writeToDisk(headerLinear);
    clock_gettime(CLOCK_REALTIME, &start);
    clock_gettime(CLOCK_MONOTONIC,&startMono);

    for(int i = 1; i < initial; i++) {
        Rectangle * rect = bateriaRectangulos(i);
        insertToRootLinear(node, rect);
    };
    clock_gettime(CLOCK_REALTIME, &finish);
    clock_gettime(CLOCK_MONOTONIC, &finishMono);
    time_spent =  (finish.tv_sec-start.tv_sec) + (double)(finish.tv_nsec-start.tv_nsec)/1000000000.0;
    time_spent_mono =     (finishMono.tv_sec-startMono.tv_sec) + (double)(finishMono.tv_nsec-startMono.tv_nsec)/1000000000.0;
    printf("Clock real time in Linear insert: %f\n Clock mono time in Linear insert, %f \n", time_spent, time_spent_mono);
    setAccessToDisk(0);

    clock_gettime(CLOCK_REALTIME, &start);
    clock_gettime(CLOCK_MONOTONIC,&startMono);

    for (int i = 0; i <(int)1.0*initial/10 ; i++ ) {
        Rectangle *rect = bateriaRectangulos(i);
        search(node, rect);

    }
    clock_gettime(CLOCK_REALTIME, &finish);
    clock_gettime(CLOCK_MONOTONIC, &finishMono);
    time_spent =  (finish.tv_sec-start.tv_sec) + (double)(finish.tv_nsec-start.tv_nsec)/1000000000.0;
    time_spent_mono =     (finishMono.tv_sec-startMono.tv_sec) + (double)(finishMono.tv_nsec-startMono.tv_nsec)/1000000000.0;
    printf("Clock real time spent in Linear Search : %f , access to Disk (write+read): %d \n", time_spent,getAccessToDisk());
    printf("Clock mono time spent in Linear Search : %f \n", time_spent_mono);

}
