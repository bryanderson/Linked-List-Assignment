#include <stdio.h>
#include <stdlib.h>

struct Node{
	int angka;
  Node *next;
} *head , *tail , *curr;

// Create NULL
Node *createNode(int angka){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->angka = angka;
    newNode->next  = NULL;
    return newNode;
}

// Insert
void pushTail(int angka){
    Node *temp = createNode(angka);
    if(!head){
        head = tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

// Sort
void sortDescLinkedList(){ // Descending
  int temp;
  Node *curr;
  Node *ptr = head;
  while(ptr!= NULL){
    curr = ptr-> next;
    while(curr!= NULL){
      if(ptr->angka < curr->angka){
        temp = ptr->angka;
        ptr->angka = curr->angka;
        curr->angka = temp;
      }
      curr = curr->next;
    }
    ptr = ptr->next;
  }
}

// Print
void printLinkedList(){
  
  Node *curr = head;
  while(curr != NULL){
  printf("%d ", curr-> angka);
    curr= curr-> next;
  }
}


int main(){
  int n , num;

  printf("Banyaknya angka pada list : "); scanf("%d" , &n);
  printf("Masukan list angka :\n");
  for(int i=0 ; i<n ; i++){
    scanf(" %d" , &num);
    pushTail(num);
  }

  printf("Hasil Descending :\n"); 
  	sortDescLinkedList();
  	printLinkedList();

printf("\n");
return 0;
}