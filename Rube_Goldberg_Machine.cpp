#include <iostream>
#include <sstream>
#include <fstream>
#include <queue>
#include <iterator>
#include <string.h>
using namespace std;

/*-------------IMPLEMENTING THE QUEUE---------------------------*/

# define maxsize 1000
int front = -1, rear = -1;  
string queue_[maxsize];  

void insert(string item)  
{  
    if(rear == maxsize-1)  
    {  
        printf("\nOVERFLOW\n");  
        return;  
    }  
    if(front == -1 && rear == -1)  
    {  
        front = 0;  
        rear = 0;  
    }  
    else   
    {  
        rear = rear+1;  
    }  
    queue_[rear] = item;     
}  
void del()  
{  
    string item;   
    if (front == -1 || front > rear)  
    {  
        printf("\nUNDERFLOW\n");  
        return;  
              
    }  
    else  
    {  
        item = queue_[front];  
        if(front == rear)  
        {  
            front = -1;  
            rear = -1 ;  
        }  
        else   
        {  
            front = front + 1;  
        }  
          
    }  
      
      
}  
      
void display()  
{  
    int i;  
    if(rear == -1)  
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   
        for(i=front;i<=rear;i++)  
        {  
            cout << queue_[i];  
        }     
    }  
}  

/*---------------FUNCTIONS FOR THE STACK---------------------*/
string stack[100];
int i,j,n=1024,top=-1;
  
void push (string val)  
{  
    if (top == n )   
    printf("\n Overflow");   
    else   
    {  
        top = top +1;   
        stack[top] = val;   
    }   
}   
  
string pop()   
{   
    string x = stack[top];
    if(top == -1)   
        printf("Underflow");  
    else  
        top = top -1;   
    return x;
}   
void show()  
{  
    for (i=top;i>=0;i--)  
    {  
        cout << stack[i];  
    }  
    if(top == -1)   
    {  
        printf("Stack is empty");  
    }  
} 

/*---------------IMPLEMENTING THE BINARY TREE----------------------------------*/

struct Node 
{
	string data;
	Node* left;
	Node* right;
};

Node* CreateNode(string data)
{
	Node* newNode = new Node();
	if (!newNode) {
		cout << "Memory error\n";
		return NULL;
	}
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}


void printList(Node *node) 
{ 
	while (node!=NULL) 
	{ 
		cout << node->data << " "; 
		node = node->right; 
	} 
} 


void inorder(Node* temp)
{
	if (temp == NULL)
		return;

	inorder(temp->left);
	cout << temp->data << ' ';
	inorder(temp->right);
}


void preorder(Node* temp)
{
	if (temp == NULL)
		return;

	cout << temp->data << ' ';
    preorder(temp->left);
	preorder(temp->right);
    	
}


void postorder(Node* temp)
{
	if (temp == NULL)
		return;

	postorder(temp->left);
	postorder(temp->right);
    cout << temp->data << ' ';	
}

/*---------CONVERTING THE BINARY TREE TO A LINKED LIST-------------------------*/

Node* InsertNode(Node* root, string data)
{
	if (root == NULL) {
		root = CreateNode(data);
		return root;
	}
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp->left != NULL)
			q.push(temp->left);
		else {
			temp->left = CreateNode(data);
			return root;
		}

		if (temp->right != NULL)
			q.push(temp->right);
		else {
			temp->right = CreateNode(data);
			return root;
		}
	}
}



void BinaryTree2DoubleLinkedList(Node *root, Node **head) 
{ 
	if (root == NULL) return; 
    static Node* prev = NULL; 
    BinaryTree2DoubleLinkedList(root->left, head); 
    if (prev == NULL) 
		*head = root; 
	else
	{ 
		root->left = prev; 
		prev->right = root; 
	} 
	prev = root; 
    BinaryTree2DoubleLinkedList(root->right, head); 
} 


/*---------------THE MAIN FUNCTION-----------------------------*/

int main()
{
   char buffer[1024] ;
   char *record,*line;
   int i=0,j=0;
   string r[100];
   char f[24]; 
   int n=0;
   cout << "Kindly Enter the name of the csv file with externsion\nPLease make sure that the file is in the same directory;-)\n";
   cin >> f;
   FILE *fstream = fopen(f,"r");
   if(fstream == NULL)
   {
      printf("\n file opening failed ");
      return -1 ;
   }
   while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL)
   {
     r[i] = line;
     /*-----------PRINTING EACH RECORD LINE BY LNE--------------------*/
     record = strtok(line,",");
     while(record != NULL)
     {
     record = strtok(NULL,",");
     }
     n++;
     i++;
   }

/*------------ENQUEUEING EACH DATA INTO THE QUEUE----------------*/

   for(int i=1;i<n;i++)
   {
     string s = r[i];
     insert(s);   
   }
  /*-----------------DISPLAYING THE QUEUE--------------------------*/ 
    display(); 

/*-----------------DEQUEUING EACH ELEMENT FROM THE QUEUE AND PUSHING IT INTO THE STACK------------*/
    for(int i=0;i<=n;i++)
    {
        push(queue_[i]);
    }
    show();

    /*-----------NOW POPING ELEMENT FROM STACK AND INSERTING IT INTO THE BINSARY TREE--------------*/
    Node* root = CreateNode(pop());
    for(int i=0;i<n;i++)
    {
        string key = pop();
        root = InsertNode(root, key);

    }
    inorder(root);
    Node *head = NULL; 
	BinaryTree2DoubleLinkedList(root, &head); 

	printList(head); 
    
    string s,a,b,c,d;
    cout << "Enter the first name:";
    cin >> a;
    cout << "Enter the last name:";
    cin >> b;
    cout << "Enter the age:";
    cin >> c;
    cout << "Enter the date of birth in DD-MM-YYY format";
    cin >> d;
    s = a + ' ' + b + ',' + c + ',' + d;
    cout << s;

    string myText;

    ifstream MyReadFile("abc.csv");
    while (getline (MyReadFile, myText)) {
          cout << myText;
 }

MyReadFile.close();
  ofstream MyFile("abc.csv");
myText += s;
  MyFile << myText;
  MyFile.close(); 
   
    return 0 ;
 }
