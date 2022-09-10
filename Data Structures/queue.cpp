// Using lists
template<typename T>
struct queue {
   struct node {
      T data;
      node* next;
   };
   int cur_size;
   node* head;
   node* tail;
   public:
      queue () {
         cur_size = 0;
         head = NULL;
         tail = NULL;
      }
   void enqueue (T x) {
      node* newNode = new node;
      newNode->data = x;
      newNode->next = NULL;
      if (head == NULL) {
         head = newNode;
      } else {
         tail->next = newNode;
      }
      tail = newNode;
      cur_size++;
   }
   void dequeue () {
      if (cur_size == 1) {
         head = NULL;
         tail = NULL;
      } else {
         head = head->next;
      }
      cur_size--;
   }
   T front () {
      return head->data; // front of the hypothetical queue is just the head node of our list.
   }
   T back () {
      return tail->data;
   }
   bool empty () {
      return (cur_size == 0);
   }
   int size () {
      return cur_size;
   }
};


// Using stacks
template<typename T>
struct queue {
   int cur_size;
   stack<T> inbox;
   stack<T> outbox;
   public:
      queue () {
         cur_size = 0;
      }
   void enqueue (T x) {
      inbox.push(x);
      cur_size++;
   }   
   T dequeue () {
      if (outbox.empty()) {
         while (!inbox.empty()) {
            outbox.push(inbox.top());
            inbox.pop();
         }
      }
      cur_size--;
      T x = outbox.top();
      outbox.pop();
      return x;
   }
   bool empty () {
      return (cur_size == 0);
   }
   int size () {
      return cur_size;
   }
};


// Using array
template<typename T>
struct queue {
   int last, first, cur_size, capacity;
   T *arr;
   public:
      queue () {
         last = first = -1;
         cur_size = 0;
         capacity = (int)1e5;
         arr = new T[capacity]; // assume a max capacity or pass it as constructor parameter
      }
      queue (int c) {
         last = first = -1;
         arr = new T[c];
         capacity = c;
         cur_size = 0;
      }
   ~queue() {delete[] arr;}
   void enqueue (T x) { // push
      if (cur_size == capacity) {
         exit(1);
      }
      if (last == -1 && first == -1) {
         last = 0;
         first = 0;
      } else {
         last++;
      }
      arr[last] = x;
      cur_size++;
   }
   void dequeue () { // pop
      if (first == -1) {
         exit(1);
      }
      // T x = arr[first];
      if (cur_size == 1) {
         first = last = -1;
      } else {
         first++;
      }
      cur_size--;
      // return x;
   }
   T front () {
      return arr[first];
   }
   T back () {
      return arr[last];
   }
   bool empty () {
      return (cur_size == 0);
   }
   int size () {
      return cur_size;
   }
};


// A modification
struct minqueue {
   stack<pair<int, int>> s1, s2; // add elements to s1 and remove from s2 (s1, s2 are min stacks)
   
   int minimum () {
      int minimum;
      if (s1.empty() || s2.empty()) 
         minimum = s1.empty() ? s2.top().second : s1.top().second;
      else
         minimum = min(s1.top().second, s2.top().second);
      return minimum;   
   }

   void add (int v) {
      int minimum = s1.empty() ? v : min(v, s1.top().second);
      s1.push({v, minimum});
   }

   void remove () {
      if (s2.empty()) { // reversing the order
         // not O(n) bro. bcz all the elements already moved would get deleted in this order only.
         while (!s1.empty()) {
            int element = s1.top().first;
            s1.pop();
            int minimum = s2.empty() ? element : min(element, s2.top().second);
            s2.push({element, minimum});
         }
      }
      int remove_element = s2.top().first;
      s2.pop();
   }
   // we perform all operations in O(1) on average (each element will be once added to stack s1, once transferred to s2, and once popped from s2)
};