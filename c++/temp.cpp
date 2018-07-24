typedef struct Node * nodeptr;

struct Node
{
    int value;
    nodeptr next;
};

nodeptr insert(nodeptr start, int value);
void printList(nodeptr start);
void mergeSort(nodeptr *source);
void partition(nodeptr head, nodeptr *a, nodeptr *b);
nodeptr mergeLists(nodeptr a, nodeptr b);

Node *insert(Node *start, int value)
{
  Node *p = start; //iterating pointer
  Node *temp;
  temp = new Node;
  temp->value = value;
  temp->next = NULL;

  if(p == NULL)
  {
    start = temp;
    return start;
  }

  while(p->next != NULL)
  {
    p = p->next;
  }

  p->next = temp;
  return start;
}


void printList(Node *start)
{
  Node *p = start;

  while(p != NULL)
  {
    cout << p->value << "->";
    p = p->next;
  }

  cout << "!!!" << endl;
}

void mergeSort(nodeptr *source)
{
  nodeptr head = *source;
  nodeptr a = NULL;
  nodeptr b = NULL;

  if(head == NULL || head->next == NULL)
  {
    return;
  }

  partition(head, &a, &b);

  mergeSort(&a);
  mergeSort(&b);

  *source = mergeLists(a, b);
}

void partition(nodeptr head, nodeptr *front, nodeptr *back)
{
  nodeptr fast;
  nodeptr slow;

  if(head == NULL || head->next == NULL)
  {
    *front = head;
    *back = NULL;
  }
  else
  {
    slow = head;
    fast = head->next;

    while(fast != NULL)
    {
      fast = fast->next;
      if(fast != NULL)
      {
          slow = slow->next;
          fast = fast->next;
      }
    }
    *front = head;
    *back = slow->next;
    slow->next = NULL;
  }
}

nodeptr mergeLists(nodeptr a, nodeptr b)
{
   nodeptr mergedList = NULL;

   if(a == NULL)
   {
     return b;
   }
   else if(b == NULL)
   {
     return a;
   }

   if(a->value <= b->value)
   {
     mergedList = a;
     mergedList->next = mergeLists(a->next, b);
   }
   else
   {
     mergedList = b;
     mergedList->next = mergeLists(a, b->next);
   }

   return mergedList;

}
