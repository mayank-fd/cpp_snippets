// doubly linked list
template< typename T>
struct linked_list {
   struct node {
      T data;
      node* next;
      node* prev;
   };

   node* head; // first node of the list
   node* tail; // last node of the list, so we don't have to iterate before adding to rear everytime.

   public:
      linked_list() {
         head = NULL;
         tail = NULL;
      }
      
   void add_rear(T x) {
      node* newNode = new node;
      newNode->data = x;
      newNode->next = NULL;
      if (head == NULL) {
         newNode->prev = NULL; 
         head = newNode;
         tail = newNode;
      } else {
         tail->next = newNode;
         tail = tail->next;
      }
   }   

   void add_front (T x) {
      node* newNode = new node;
      newNode->data = x;
      newNode->prev = NULL;
      newNode->next = head;
      if (head == NULL) {
         tail = newNode;
      }
      head = newNode;
   }
};