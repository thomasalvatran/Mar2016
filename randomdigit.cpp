//home/tovantran/Ctest/randomdigit.cpp --> 2014-07-07 by ./.tv  owner: tovantran
//http://www.geeksforgeeks.org/merge-sort-for-linked-list/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct node* SortedMerge(node* a, node* b);
void FrontBackSplit(node* source, node** frontRef, node** backRef);


static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

struct node{
	int data;
	node *next;
};
void MergeSort(struct node** headRef)

    {
        node* head = *headRef;
        node* a;
        node* b;
        if ((head == NULL) || (head->next == NULL))
        {
            return;
        }
        FrontBackSplit(head, &a, &b);
        MergeSort(&a);
        MergeSort(&b);
        *headRef = SortedMerge(a, b);
    }
node* SortedMerge(node* a, node* b)
{
  node* result = NULL;
 
  /* Base cases */
  if (a == NULL)
     return(b);
  else if (b==NULL)
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->data <= b->data)
  {
     result = a;
     result->next = SortedMerge(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMerge(a, b->next);
  }
  return(result);
}
 void FrontBackSplit(node* source, node** frontRef, node** backRef)

    {
        node *fast, *slow;
        
        if (source==NULL || source->next==NULL)
        {
            *frontRef = source;
            *backRef = NULL;
        }
        else
        {
            slow = source;
            fast = source->next;
		/* Advance 'fast' two nodes, and advance 'slow' one node */
            while (fast != NULL)
            {
                fast = fast->next;       //fast is double of slow
                if (fast != NULL)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            /* 'slow' is before the midpoint in the list, so split it in two
      at that point. */
            *frontRef = source;
            *backRef = slow->next;
            slow->next = NULL;
        }
    }

//void swap (node *i, node *j)
//{	int temp;
//	temp = i ->data;
//	j->data = i->data;
//	j->data = temp;
//}
int stringLength = sizeof(alphanum) - 1;

char genRandom()
{

	return alphanum[rand() % stringLength];
}
string getrandomstr()
{
	string Str;

	unsigned j = rand() % 20 + 1;
	cout << j << endl;
	for(unsigned int i = 0; i < j; ++i)
	{
		Str += genRandom();

	}
	return Str;
}
int main()
{
	srand(time(0));
	node *ptr, *head;

	head = new node;
	head-> next = 0;
	head->data = 12;
	ptr = head;

	ptr -> next = new node;
	ptr = ptr -> next;
	ptr ->data = 9;

	ptr -> next = new node;
	ptr = ptr -> next;
	ptr ->data = 2;

	ptr -> next = new node;
	ptr = ptr -> next;
	ptr ->data = 11;
	
	ptr -> next = new node;
	ptr = ptr -> next;
	ptr ->data = 100;
	
	ptr -> next = new node;
	ptr = ptr -> next;
	ptr ->data = 90;
	
	ptr -> next = new node;
	ptr = ptr -> next;
	ptr ->data = 999;
	
	ptr->next = 0; // end
	ptr = head;
	int count = 0;
	while (ptr -> next != 0){
		cout << ptr->data << endl;
		ptr = ptr -> next;
		count++;	
	}
	cout << ptr->data << endl;
	node *l, *r;
	  FrontBackSplit(head, &l, &r); // slip linked link head into left and right

//		
cout << "----split 1---" << endl;
ptr = l;
int i = (r - head)/2 + (head -r) % 2;
while (i > 0){
    i--;
		cout << ptr->data << endl;
		ptr = ptr -> next;	
	}

cout << "----split 2---" << endl;
ptr = r;
i = count - ((r - head)/2 + (head -r) % 2) + 1;

while (i > 0){
    i--;
		cout << ptr->data << endl;
		ptr = ptr -> next;	
}
//

	MergeSort(&l);					        //sort left and sort right
	MergeSort(&r);

	cout << "----Sorted----" << endl;
	node *temp = SortedMerge(l, r);   //merger left and right
    ptr = temp;
	
	while (ptr->next != 0){
	  cout << ptr ->data << endl;
	  ptr = ptr -> next;
	}
	cout << ptr->data << endl;

	return 0;
}






