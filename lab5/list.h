// a recursive data type definition
// serves as the nodes of a list
typedef struct node
{
  int data;
  struct node* next;
} node;

// a new list is created by: node* head = NULL;

// add a new node to the front of the list
void add(node* *head, node* new_node);

// optional / if time permits
// remove / return the node at the head of the list (if there is one)
 node* yeet(node** head);

// return the number of nodes in the list
int list_len(const node* head);

