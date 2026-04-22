# include <iostream>
using namespace std;

struct Node
{
    int index;
    int data;
    Node *next;
};

Node *A = NULL; //stores the first vec
Node *B = NULL; // stores the second vec
Node *result = NULL; //stores the result

void AddNode(Node * & listpointer, int a, int b) {
// add a new node to the TAIL of the list
  Node *current;
  current=listpointer;
  if(current!=NULL){
    while (current->next!=NULL){
      current=current->next;
    }
  }// now current points to the last element
  Node *temp;
  temp = new Node;
  temp->index = a;
  temp->data = b;
  temp->next = NULL;
  if(current!=NULL) current->next = temp;
  else listpointer=temp;
}

// the code prints the addition of the two vectors
// first I looped through the result listpointer to count the total number of nodes as they are our n 
// after finding the count I looped again to then print every node's index and data with a space b/w them 
void PrintLL(Node *listpointer){
    Node *current;
    current = listpointer;
    int count = 0;
    while (true){
        if (current==NULL){
            break;
        }
        count++;
        current = current->next;
     }
    
    cout << count << " ";
    current = listpointer;

    while (true){
        if (current == NULL){
            break;
        }
        cout << current->index << " " << current->data << " ";
        current = current -> next;
    }
    cout << endl;
}

// the function does the addition of the two vectors
// I made two nodes that point to head of vector A and vector B

void add(Node *&result, Node *listpointer, Node *listpointer2){
    Node *curr1, *curr2;
    curr1 = listpointer;
    curr2 = listpointer2;

    // The while loop first checks if the current for any of the vector has become NULL, if that's the case then the loop gets terminated
    // There there is a if, elseif and a else. The if checks if the curr1(vector A)'s index is smaller than of curr2's index. If that's the case then we add
    // the index and value of curr1 in the result vector and then skips to the next index, and similarly vice-versa. Lastly the else is the real addition
    // if inside the else index of curr 1 = curr2, then it checks if after adding the values is it equal to 0, if it's zero ignore and if not then
    // add the data of two and add another node into the result vector and lastly move both curr1 and curr2 to next position in their own vectors.
    while(true){
        if (curr1==NULL){
            break;
        }
        if (curr2==NULL){
            break;
        }
        if(curr1->index < curr2->index){
            AddNode(result,curr1->index,curr1->data);
            curr1 = curr1->next;
        }
        else if(curr1->index > curr2->index){
            AddNode(result,curr2->index,curr2->data);
            curr2 = curr2->next;
        }
        else{
            if(curr1->data + curr2->data != 0){
                AddNode(result,curr1->index, curr1->data + curr2->data);
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }
    // these two while loops checks if the curr1 or curr2 is not equal to null; these 2 are required because in some cases the above while loop will end if either of the curr gets
    // equal to NULL and it that happens then the one who had more nodes while not able to add node into the result vectors
    // these two while make sure that if there is still some nodes left then it get's added onto the result vector
    while(curr1!=NULL){
        AddNode(result,curr1->index,curr1->data);
        curr1 = curr1->next;
    }
    while(curr2!=NULL){
        AddNode(result,curr2->index,curr2->data);
        curr2 = curr2->next;
    }



}

int main(){
    // to read the first vector A
    int n, ind, value;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin>> ind;
        cin>> value;
        AddNode(A, ind, value);
    }
    // to read the second vector B
    int n2;
    n2 = 0;
    ind = 0;
    value = 0;

    cin >> n2;
    for(int i = 1; i <= n2; i++){
        cin>> ind;
        cin>> value;
        AddNode(B, ind, value);
    }
    // Function call to add the two vectors and display result
    add(result, A,B);
    PrintLL(result);
}


