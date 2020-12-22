#include <stdio.h> // i/o
#include <string.h> // strcpy
#include <stdlib.h> // dynamic memory allocation

// CRUD: create, read, update, delete

struct Profile {
  int ID;
};

struct Mentor {
  Profile p; // nested struct
  // int ID; // 4
  char name[255]; // 255
  int age; // 4
  double gpa; // 8
};

// Function return sebuah integer
// Function menerima parameter a dan b
// int plus(int a, int b) {
//   return a+b;
// }

// Function return pointer yang menunjuk ke Mentor yang baru dibuat
// Function menerima parameter nama, age, gpa
// char name[] sama saja dengan char *name
Mentor *createMentor(const char *name, int age, double gpa) {
  // malloc return void* dicast jadi mentor*
  // malloc sebesar ukuran struct mentor
  Mentor *newMentor = (Mentor*)malloc(sizeof(Mentor));
  strcpy(newMentor->name, name); // strcpy untuk string
  newMentor->age = age; // (*newMentor).age = age;
  newMentor->gpa = gpa;
  newMentor->p.ID = 5;
  return newMentor; // return mentor baru
}

void printData(Mentor *m) {
  printf("Name: %s\n", m->name);
  printf("Age: %d\n", m->age);
  printf("GPA: %.2lf\n", m->gpa);
}

void deleteMentor(Mentor *m) {
  free(m); // free allocated memory 
}

int main() {
  // Static memory allocation
  // Mentor mentorStatic;
  // mentorStatic.age = 10;
  // mentorStatic.gpa = 3.90;
  // strcpy(mentorStatic.name, "Elvan");
  // printf("%d", mentorStatic.age);

  // Dynamic memory allocation
  Mentor *m = createMentor("Kevice", 20, 3.85);
  printData(m);
  deleteMentor(m);
printf("haloo ngab");
  // printData will show null values BUT might still
  // show some data due to undefined behavior (accessing illegal memory)
  // printData(m);

  return 0;
}

struct Node {
  int value; // store node's value
  Node *next; // node's next pointer
} *head, *tail, *curr; // global head, tail, and current

Node *createNode(int value) {
  // allocate memory with size of node to temp
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->value = value;
  temp->next = NULL; // next pointer is NULL by default
  return temp;
}

void pushHead(int value) {
  // create a new node
  Node *temp = createNode(value);

  if(!head) { // if there's no head (0 node)
    head = tail = temp;
  } else { // >= 1 node
    temp->next = head; // node points to head
    head = temp; // node becomes head
  }
}

void pushTail(int value) {
  // create a new node
  Node *temp = createNode(value);

  if(!head) { // if there's no head (0 node)
    head = tail = temp;
  } else { // >= 1 node
    tail->next = temp; // tail points to node
    tail = temp; // node becomes tail
  }
}
void popHead() {
  if(!head) {
    return; // no nodes
  } else if(head == tail) {
    head = tail = NULL; // only 1 node
    free(head);
  } else {
    Node *temp = head->next; // set new head candidate
    head->next = NULL; // cut next
    free(head); // remove head
    head = temp; // initialize new head
  }
}

void popTail() {
  if(!head) {
    return; // no nodes
  } else if(head == tail) {
    head = tail = NULL; // only 1 node
    free(head);
  } else {
    curr = head; // set curr to head
    while(curr) { // while there's still node
      if(curr->next == tail) { // if next node is tail
        curr->next = NULL; // cut next
        free(tail); // remove tail
        tail = curr; // initialize new tail
        break;
      }
      curr = curr->next;
    }
  }
}