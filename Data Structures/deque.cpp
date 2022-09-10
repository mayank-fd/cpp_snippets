// Using array
template<typename T>
struct deque {
   int front;
   int rear;
   T* arr;
   int capacity;
   int cur_size;
   public:
      deque () {
         capacity = (int)1e5;
         front = rear = -1;
         arr = new T[capacity];
         cur_size = 0;
      }
      deque (int c) {
         capacity = c;
         front = rear = -1;
         arr = new T[capacity];
         cur_size = 0;
      }
   ~deque() { delete[] arr; }   
   void insertFront(T x) { // Adds an item at the front of Deque
      if (cur_size == capacity) {
         exit(1);
      }
      if (front == -1) {
         front = rear = 0;
      } else if (front == 0) {
         front = capacity - 1;
      } else {
         front--;
      }
      arr[front] = x;
      cur_size++;
   } 
   void insertRear(T x) { // Adds an item at the rear of Deque
      if (cur_size == capacity) {
         exit(1);
      }
      if (rear == -1) {
         front = rear = 0;
      } else if (rear == capacity - 1) {
         rear = 0;
      } else {
         rear++;
      }
      arr[rear] = x;
      cur_size++;
   } 
   void deleteFront() { // Deletes an item from front of Deque.
      if (cur_size == 0) {
         exit(1);
      }
      if (front == rear) {
         front = rear = -1;
      } else if (front == capacity - 1) {
         front = 0;
      } else {
         front++;
      }
      cur_size--;
   }  
   void deleteRear() { // Deletes an item from rear of Deque.
      if (cur_size == 0) {
         exit(1);
      }
      if (front == rear) {
         front = rear = -1;
      } else if (rear == 0) {
         rear = capacity - 1;
      } else {
         rear--;
      }
      cur_size--;
   } 
   T getFront() { // Gets the front item from queue. 
      if (cur_size == 0) {
         exit(1);
      }
      return arr[front];
   } 
   T getRear() { // Gets the last item from queue. 
      if (cur_size == 0) {
         exit(1);
      }
      return arr[rear];
   } 
   bool isEmpty() { // Checks whether Deque is empty or not.
      return (cur_size == 0);
   }  
   bool isFull() { // Checks whether Deque is full or not.
      return (cur_size == capacity);
   }    
   int size () {
      return cur_size;
   }
};


// Using linked list
template<typename T>
struct deque {
   struct node {
      T data;
      node* next;
      node* prev;
   };
   int cur_size;
   node* front;
   node* rear;
   deque() : cur_size(0), front(nullptr), rear(nullptr) {}
   void insertFront(T x) { // Adds an item at the front of Deque
      node* newNode = new node;
      newNode->data = x;
      newNode->next = nullptr;
      if (cur_size == 0) {
         newNode->prev = nullptr;
         front = newNode;
         rear = newNode; // this important to keep in the mind the recursive step
      } else {
         front->next = newNode;
         newNode->prev = front; // this link reversibly
         front = newNode;
      }   
      cur_size++;
   } 
   void insertRear(T x) { // Adds an item at the rear of Deque
      node* newNode = new node;
      newNode->data = x;
      newNode->prev = nullptr;
      if (cur_size == 0) {
         newNode->next = nullptr;
         front = newNode;
         rear = newNode;
      } else {
         rear->prev = newNode;
         newNode->next = rear;
         rear = newNode;
      }   
      cur_size++;
   } 
   void deleteFront() { // Deletes an item from front of Deque.
      if (cur_size == 0) {
         exit(1);
      }
      front = front->prev;
      front->next = nullptr;
      cur_size--;
   }  
   void deleteRear() { // Deletes an item from rear of Deque.
      if (cur_size == 0) {
         exit(1);
      }
      rear = rear->next;
      rear->prev = nullptr;
      cur_size--;
   } 
   T getFront() { // Gets the front item from queue. 
      return front->data;
   } 
   T getRear() { // Gets the last item from queue. 
      return rear->data;
   } 
   bool isEmpty() { // Checks whether Deque is empty or not.
      return (cur_size == 0);
   }  
   int size () {
      return cur_size;
   }
};
