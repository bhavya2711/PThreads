#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct thread_struct{
//struct to store thread values like thread in index and total number of threads
	int thread_count;
	int current_thread;
};
// function that each thread will access to print the required statement
void* print_func(void* p){
//pointer to the struct
 thread_struct *thread_pointer = (thread_struct*)p;

printf("I am thread %d in %d \n", thread_pointer->current_thread,thread_pointer->thread_count);

}



int main (int argc, char* argv[]) {

  if (argc < 2) {
    std::cerr<<"usage: "<<argv[0]<<" <nbthreads>"<<std::endl;
    return -1;
  }


 //user input value of no of threads
 
int noOfThreads = std::atoi(argv[1]);

 struct thread_struct thread_pointer[noOfThreads];
 pthread_t nbthread[noOfThreads];


 for(int i=0; i < noOfThreads; i+=1){
  thread_pointer[i].thread_count = noOfThreads;
  thread_pointer[i].current_thread = i; 
//creating threads
  pthread_create(&nbthread[i], NULL, print_func , (void*) &thread_pointer[i]);
 }


 for(int i=0; i < noOfThreads; i+=1){
  pthread_join(nbthread[i], NULL);
 }


  return 0;

}
