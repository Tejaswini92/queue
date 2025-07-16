# Implementation of Queue 

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_CAPACITY 10
struct Queue {
  int add_index;
  int remove_index;
  int count;
  int array[ARRAY_CAPACITY];
}

struct Queue global_queue;

void initialize_queue () {
  global_queue.add_index = -1;
  global_queue.remove_index = -1;
  global_queue.count = 0;
}

bool enqueue_data (int data) {
  if (global_queue.count == ARRAY_CAPACITY) {
    return false;
  }
  global_queue.array[++global_queue.add_index] = data;
  global_queue.count++;
}

int dequeue_data () {
  int data;
  if (global_queue.count == 0) {
    return -1;
  }
  data = global_queue.array[++global_queue.remove_index];
  global_queue.count-- ;

  if (global_queue.add_index == global_queue.remove_index)  {
    initialize_queue();
  }
}

