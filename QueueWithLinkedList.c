# implementation for the Queue with the use of the Linked List.

typedef struct Node {
  int data;
  struct Node* next;
}Node;

// enqueue will create a node and add the node to the head
typedef struct Queue {
 struct Node* add_ptr;
 struct Node* remove_ptr ;
 int count;
}Queue;

Queue global_queue;

void initialize_queue () {
  global_queue.add_ptr = NULL;
  global_queue.remove_ptr = NULL;
  global_queue.count = 0;
}

void enqueue_data (int data) {
  Node* new_node = (Node*)malloc(sizeof(Node));
  new_node.data = data;
  new_node.next = NULL; 
  
  // If queue is empty 
  if ( global_queue.add_ptr == NULL) {
    global_queue.add_ptr = new_node;
    global_queue.remove_ptr = new_node;
    return;
  }
   global_queue.add_ptr->next = new_node;
   global_queue.add_ptr = new_node;
}

int dequeue_data () {
  int data;
  Node* temp;
  temp = global_queue.remove_ptr
  data = temp->data;
  global_queue.remove_ptr = global_queue.remove_ptr->next;
  free (temp);
  if (global_queue.remove_ptr == NULL) {
    global_queue.add_ptr = NULL;
  }
}
