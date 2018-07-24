// Find out all the nodes which are at distance ‘3’ from the given node 5.


// Find the height of the given node 5 is -3. say x = 3.

// For all the nodes which are at distance 3 and exist below node 5, consider 5 as root node and problem will reduce to “Print all the nodes which are at distance x from the root”. Agree?.

// But what about the other nodes, go one level up ( at the path from root to node 5), which is node 2. since you have gone up by one level, x will be x = x-1 = 3-1 = 2.

// So now consider node 2 as root and again problem will reduce to, Print all the nodes which are at distance 2 from the root. remember one thing when considering the node 2 as root, you dont check the direction of node 5 .(Why,?? because if you check nodes at distance 2 from node 2, you will get 9, 7. Node 9 is at distance 3 from Node 5 which is right but Node 7 is at distance 1 from Node 5 which is wrong.)

// How would you stop your program to check in the direction of Node 5, when you go one level up, means at Node 2, after processing the Node 5, return Node 5 to Node 2 and at Node 2 check whether Node 5 is right child or left child of Node 2, based on that don’t check that direction.

// Now recursivley go one more level up, now x = x-1 = 2-1 =1. It will be Node 1, consider Node 1 as root and again problem will reduce to, Print all the nodes which are at distance 1 from the root and don’t check the direction of Node 2, with the same logic explained earlier.


#include <iostream>

using namespace std;

typedef struct Node * nodeptr;

struct Node
{
  int data;
  nodeptr left;
  nodeptr  right;
};

nodeptr newNode(int x);
void insert(nodeptr &root, int x);
void inorder(nodeptr root);
int pathLength(nodeptr root, int n);


int main()
{
  nodeptr root;
  root = NULL;
  int number;

  cout << "Enter number to the tree : " << endl;
  while(true)
  {
    cin >> number;
    if(number == -1)
    {
      cout << "input done! " << endl;
      break;
    }

    insert(root, number);
  }

  inorder(root);
  
  cout << "!!!" << endl;
  cout << pathLength(root, 5) << endl;
  return 0;
}

nodeptr newNode(int x)
{
  nodeptr temp; //temporary pointer

  temp = new Node;

  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

void insert(nodeptr &root, int x)
{
  nodeptr p; //traversal pointer

  nodeptr temp = newNode(x);

  if(root == NULL)
  {
    root = temp;
    return;
  }

  p = root;

  while(p != NULL)
  {
      if(p->left == NULL && p->data > x)
      {
        p->left = temp;
        return;
      }
      else if(p->right == NULL && p->data < x)
      {
        p->right = temp;
        return;
      }
      else if(p->data < x)
      {
        p = p->right;
      }
      else if(p->data > x)
      {
        p = p->left;
      }
  }
}

void inorder(nodeptr root)
{
  if(root == NULL)
  {
    return;
  }

  inorder(root->left);
  cout << root->data << ", ";
  inorder(root->right);
}

int pathLength(nodeptr root, int n)
{
  if(root == NULL)
  {
      return 0;
  }

  int x = 0;
  if(root->data == n || ((x = pathLength(root->left, n)) > 0) || ((x = pathLength(root->right, n)) > 0))
  {
    cout << "I am at level " << x << endl;
    return x + 1;
  }

  return 0;
}
