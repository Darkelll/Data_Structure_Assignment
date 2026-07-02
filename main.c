#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Student name(string), StudentID(string), service type(string), and priroty
// level(urgent, normal) (int? because choose 0 | 1 based on the priority)

// Each user should select the data structure to work with????

// Queue

// Linked List

// Stack

// Menu
/*===== Smart Student Service Centre System =====
1. Add new student request
2. Serve next student
3. Display waiting queue
4. Display completed services
5. Search completed service by student ID
6. Undo last completed service
7. Display system summary
8. Exit
Enter your choice*/

typedef struct Node {
  char student_name[50];
  char student_id[11];
  char service_type[128];
  char priority_level[7]; // u/n
  struct Node *next;
} Node;

typedef struct Queue {
  Node *head;
  Node *tail;
  int size;
} Queue;

Queue *create_queue() {
  Queue *queue = malloc(sizeof(Queue));

  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;

  return queue;
};

void enqueue(Queue *queue, char *name, char *id, char *service, char *pLevel) {
  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL) {
    exit(1);
  }
  strcpy(new_node->student_name, name);
  strcpy(new_node->student_id, id);
  strcpy(new_node->service_type, service);
  strcpy(new_node->priority_level, pLevel);
  new_node->next = NULL;

  if (queue->head == NULL) {
    queue->head = new_node;
    queue->tail = new_node;
  } else {
    queue->tail->next = new_node;
    queue->tail = new_node;
  }
  queue->size++;
}

void dequeue(Queue *queue) {
  Node *temp_pointer = queue->head;
  Node *completed_list = malloc(sizeof(Node));
  if (queue->head == NULL) {
    printf("No Data in the waiting queue\n");
  } else {
    queue->head = queue->head->next;
    completed_list = temp_pointer;
    free(temp_pointer);
  }
}

// void display_size(Queue *queue) {
//   int size_queue = queue->size;
//   printf("%d\n", size_queue);
// }

void addNewStudent(Queue *queue) {

  // Node *root = NULL;
  char name[50];
  char id[11];
  char service[128];
  char pLevel[7];
  printf("1. Add new student request\n\n");
  while (getchar() != '\n')
    ;
  printf("Enter Student Name: ");
  fgets(name, 50, stdin);
  name[strcspn(name, "\n")] = '\0';
  printf("Enter Student ID: ");
  scanf("%s", id);

  while (getchar() != '\n')
    ;
  printf("Enter Service Type: ");
  fgets(service, 128, stdin);
  service[strcspn(service, "\n")] = '\0';
  printf("Pick and Type Priority Level: \n Urgent\n Normal\n Enter: ");
  scanf("%s", pLevel);
  enqueue(queue, name, id, service, pLevel);
}

int main() {

  int choice;

  Queue *waiting_queue = create_queue();

  do {
    printf("\n\n");
    printf("\t\t\t\t===== Smart Student Service Centre System =====\n");
    printf("\t\t\t\t1. Add new student request\n");
    printf("\t\t\t\t2. Serve next student\n");
    printf("\t\t\t\t3. Display waiting queue\n");
    printf("\t\t\t\t4. Display completed services\n");
    printf("\t\t\t\t5. Search completed service by student ID\n");
    printf("\t\t\t\t6. Undo last completed service\n");
    printf("\t\t\t\t7. Display system summary\n");
    printf("\t\t\t\t8. Exit\n\n");
    printf("Enter your choice (1-8): ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      addNewStudent(waiting_queue);
      break;
    case 2:
      dequeue(waiting_queue);
      break;
    case 3:
      displayWaitingList(waiting_queue);
      break;
    case 4:
      // displayServedList(served_list);
      break;
    case 5:
      printf("choice 2");
      break;
    case 6:
      printf("choice 2");
      break;
    case 7:
      printf("choice 2");
      break;
    case 8:
      return 0;
      break;
    default:
      printf("Please pick enter correct number\n");
    }
  } while (choice != 8);
  return 0;
}