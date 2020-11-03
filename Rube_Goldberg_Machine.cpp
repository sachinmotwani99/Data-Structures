#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <queue>
#include <iterator>
#include <string.h>
using namespace std;

/*-------------IMPLEMENTING THE QUEUE---------------------------*/

# define maxsize 1000
int front = -1, rear = -1;  
string queue_[maxsize];  


/*-------------ENQUEING AN ELEMENT INTO THE QUEUE-----------------*/
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

/*------------DELETING FROM A QUEUE--------------------------*/
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


/*-----------FUNCTION TO DISPLAY THE QUEUE----------------------*/      
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
  

/*-----------FUNCTION TO PUSH AN ELEMENT INTO THE STACK----------*/
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


/*-----------FUNCTION TO POP AN ELEMENT INTO THE STACK----------*/
string pop()   
{   
    string x = stack[top];
    if(top == -1)   
        printf("Underflow");  
    else  
        top = top -1;   
    return x;
}   


/*---------FUNCTION TO DIAPLAY THE STACK--------------*/
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

/*----------DEFINING THE NODE STRUCTURE----------------------*/
struct Node 
{
	string data;
	Node* left;
	Node* right;
};


/*----------------FUNCTION TO CREATE A SIMPLE NODE FROM GIVEN VALUE----------------*/
Node* CreateNode(string data)
{
	Node* newNode = new Node();
	if (!newNode) 
    {
		cout << "Memory error\n";
		return NULL;
	}
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}


/*------------------FUNCTION TO PRINT THE LIST----------------------------*/
void printList(Node *node) 
{ 
	while (node!=NULL) 
	{ 
		cout << node->data << " "; 
		node = node->right; 
	} 
} 

/*----------------------FUNCTION FOR INORDER TRAVERSAL OF THE TREE------------------------*/
void inorder(Node* temp)
{
	if (temp == NULL)
		return;

	inorder(temp->left);
	cout << temp->data << ' ';
	inorder(temp->right);
}

/*----------------------FUNCTION FOR PREORDER TRAVERSAL OF THE TREE------------------------*/
void preorder(Node* temp)
{
	if (temp == NULL)
		return;

	cout << temp->data << ' ';
    preorder(temp->left);
	preorder(temp->right);
    	
}


/*----------------------FUNCTION FOR POSTORDER TRAVERSAL OF THE TREE------------------------*/
void postorder(Node* temp)
{
	if (temp == NULL)
		return;

	postorder(temp->left);
	postorder(temp->right);
    cout << temp->data << ' ';	
}

/*---------CONVERTING THE BINARY TREE TO A LINKED LIST-------------------------*/

/*----------------------FUNCTION TO INSERT DATA INTO THE TREE------------------------*/
Node* InsertNode(Node* root, string data)
{
	if (root == NULL) 
    {
		root = CreateNode(data);
		return root;
	}
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) 
    {
		Node* temp = q.front();
		q.pop();

		if (temp->left != NULL)
			q.push(temp->left);
		else 
        {
			temp->left = CreateNode(data);
			return root;
		}

		if (temp->right != NULL)
			q.push(temp->right);
		else 
        {
			temp->right = CreateNode(data);
			return root;
		}
	}
}


/*----------------------FUNCTION TO CONVERT A BINARY TREE TO DOUBLY LINKED LIST------------------------*/
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


/*-----------FUNCTION DECLARATIONS FOR QUICKSORT-------------------*/


/*------------------FUNCTION TO SWAP VALUES OF TWO NODES---------------------------*/
void swap( string *a, string *b ) 
{ 
    string t = *a;
    *a = *b;
    *b = t;
 } 

/*-------------------FUNCTION TO FIND last node of list--------------------------*/
struct Node *lastNode(struct Node *root) 
{ 
	while (root && root->right) 
		root = root->right; 
	return root; 
} 


/*---------------------FUNCTION TO CREATE PARTITION USEFUL IN QUICK SORT------------------------*/
struct Node* partition(struct Node *l, struct Node *h) 
{ 
	string x = h->data; 
    struct Node *i = l->left; 
    for (struct Node *j = l; j != h; j = j->right) 
	{ 
		if (j->data <= x) 
		{ 
			i = (i == NULL) ? l : i->right; 
            swap((i->data), (j->data)); 
		} 
	} 
	i = (i == NULL) ? l : i->right;  
	swap((i->data), (h->data)); 
	return i; 
} 



/*---------------A RECURSIVE FUNCTION IMPLEMENTATION OF QUICK SORT------------------------------*/
void _quickSort(struct Node* l, struct Node *h) 
{ 
	if (h != NULL && l != h && l != h->right) 
	{ 
		struct Node *p = partition(l, h); 
		_quickSort(l, p->left); 
		_quickSort(p->right, h); 
	} 
} 


/*---------------------MAIN FUNCTION CALL FOR QUICKSORT------------------------*/
void quickSort(struct Node *head) 
{ 
	struct Node *h = lastNode(head); 
	_quickSort(head, h); 
}

/*----------------INSERTION IN A SORTED WAY-------------------------*/

struct Node* getNode(string data) 
{ 
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
	newNode->data = data; 
	newNode->left = newNode->right = NULL; 
	return newNode; 
} 

/*--------------------INSERTING NEW NODE IN SORTED MANNER-------------------------*/
void sortedInsert(struct Node** head_ref, struct Node* newNode) 
{ 
	struct Node* current; 
	if (*head_ref == NULL) 
		*head_ref = newNode;  
	else if ((*head_ref)->data >= newNode->data) 
    { 
		newNode->right = *head_ref; 
		newNode->right->left = newNode; 
		*head_ref = newNode; 
	}
	else 
    { 
		current = *head_ref; 
    	while (current->right != NULL && current->right->data < newNode->data) 
			current = current->right; 

		newNode->right = current->right; 

		if (current->right != NULL) 
			newNode->right->left = newNode; 

		current->right = newNode; 
		newNode->left = current; 
	} 
} 

/*-----------END OF ALL THE ADT DECLARATIONS AND FUNCTIONS IMPLEMENTATIONS---------------------*/

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
   cout << "Reading data from " << f << "......\n\n\n";
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
        cout << "   |     " << record ; 
        record = strtok(NULL,",");
     }
     n++;
     i++;
   }

   cout << "\n\nTotal number of entries read from the csv file:   " << n-1 << "\n\n\n";
   cout << "Press any key to continue enqueing the data into a queue\n\n\n";
   getch();


/*------------ENQUEUEING EACH DATA INTO THE QUEUE----------------*/
   cout << "Enqueing the data into a queue.........\n\n\n\n";
   for(int i=1;i<n;i++)
   {
     string s = r[i];
     insert(s);   
   }
  /*-----------------DISPLAYING THE QUEUE--------------------------*/ 
    cout << "Succesfully enqueued\n\nPress any key to display the queue\n\n\n";
    getch();
    display(); 

    cout << "\n\nNow we dequeue each element and add it back to the queue\n\n\n\n";
    cout << "\nPrint any key to display the queue:\n ";
    getch();
    display();
/*-----------------DEQUEUING EACH ELEMENT FROM THE QUEUE AND PUSHING IT INTO THE STACK------------*/
    cout << "\n\n\nPress any key to push the data from the queue to the stack\n\n:";
    getch();
    cout << "Pushing the data from queue to the stack...\n\n";
    for(int i=0;i<=n;i++)
    {
        push(queue_[i]);
    }
    cout << "\n\n\nPress any key to view the stack now:\n";
    getch();
    show();
    
    cout << "\nHence the stack element are printed\n\n";
    /*-----------NOW POPING ELEMENT FROM STACK AND INSERTING IT INTO THE BINSARY TREE--------------*/
    cout <<  "\n\n\nPress any key to pop each element and insert it into a binary tree in order:\n";
    cout << "Poping elements from stack to tree....\n\n\n";
    Node* root = CreateNode(pop());
    for(int i=0;i<n;i++)
    {
        string key = pop();
        root = InsertNode(root, key);

    }
    
    cout << "\n\nInssertion in tree successfull\n\n";
    cout << "\n\nPress anykey to display the pre order traversl aof the tren\n";
    getch();
    preorder(root);
    

    cout << "\n\nPress anykey to display the post order traversl aof the tren\n";
    getch();
    postorder(root);

    cout << "\n\nPress anykey to display the in order traversl aof the tren\n";
    getch();
    postorder(root);
        
    cout << "HHence the tree dispplayed\n";
    cout << "Now press any key to convert the binary tree into a doubly linked list\n";
    getch();
    Node *head = NULL; 
	BinaryTree2DoubleLinkedList(root, &head); 

    cout << "Conversion of tree to DLL successfull\n\n";
    cout << "Press any key to print the linked list\n";
    getch();
	printList(head); 
    
    cout << "Hence the linked list displayed\n";
    cout << "Press any key to sort the inked list by quik sort:\n";
    getch();

    cout << "\n\nSorting the list.....\n\n";
    quickSort(head); 
    
    cout << "Linked List Successfully sorted.\nPress any key to print the sorted list\n";
    getch();
	printList(head);

    cout << "\n\n\nEnter the new recordto be inderted\n\n";
     
                    string s,a,b,c,d;
                    cout << "Enter the first name:";
                    cin >> a;
                    cout << "Enter the last name:";
                    cin >> b;
                    cout << "Enter the age:";
                    cin >> c;
                    cout << "Enter the date of birth in DD-MM-YYY format:";
                    cin >> d;
                    s = a + ' ' + b + ',' + c + ',' + d + '\n';
                    
                    struct Node* new_node = getNode(s); 
                	sortedInsert(&head, new_node);

                    cout << "\nInsertion of record successfull\n\n";
        

        
    quickSort(head); 
    
        
    
    
    cout << "\n\n\n\nPrinting the final list after all the operatiosn....\n\n";
    printList(head); 

    
    cout << "\n\n--------End of the program------------";
    return 0 ;
 }
