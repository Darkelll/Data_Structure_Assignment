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

// Node Struct
typedef struct Node {
  char student_name[50];
  char student_id[11];
  char service_type[128];
  char priority_level[7]; // u/n
  struct Node *next;
} Node;

// Queue
typedef struct Queue {
  Node *head;
  Node *tail;
  int size;
} Queue;

// Queue init for main
Queue *create_queue() {
  Queue *queue = malloc(sizeof(Queue));

  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;

  return queue;
};

// Linked List
typedef struct LinkedList {
  Node *root;
  int size;
} LinkedList;

// Init do not need to repeat why
LinkedList *create_list() {
  LinkedList *served_list = malloc(sizeof(LinkedList));
  served_list->root = NULL;
  served_list->size = 0;

  return served_list;
}

// Stack
typedef struct Stack {
  Node *top;
  int size;
} Stack;

Stack *create_stack() {
  Stack *stack = malloc(sizeof(Stack));
  stack->top = NULL;
  stack->size = 0;

  return stack;
}

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

Node *dequeue(Queue *queue) {
  if (queue->head == NULL) {
    printf("No Data in the waiting queue\n");
    return NULL;
  }
  Node *temp_pointer = queue->head;

  queue->head = queue->head->next;

  queue->size--;
  return temp_pointer;
}

void displayWaitingList(Queue *queue) {

  if (queue->head == NULL) {
    printf("No Data\n");
  }

  int i = 1;

  Node *curr = queue->head;

  while (curr != NULL) {
    printf("%d. %s %s %s %s\n", i, curr->student_name, curr->student_id,
           curr->service_type, curr->priority_level);
    curr = curr->next;
    i++;
  }

  free(curr);
}

void push(Stack *stack, Node *served_node) {
  if (served_node == NULL) {
    return;
  }
  Node *new_node_stack = malloc(sizeof(Node));
  if (new_node_stack == NULL) {
    printf("Stack Overflow,Out of memory!\n");
    return;
  }

  strcpy(new_node_stack->student_id, served_node->student_id);
  strcpy(new_node_stack->student_name, served_node->student_name);
  strcpy(new_node_stack->service_type, served_node->service_type);
  strcpy(new_node_stack->priority_level, served_node->priority_level);

  new_node_stack->next = stack->top;

  stack->top = new_node_stack;
  stack->size++;
}

void removeFromLinkedList(LinkedList *served_list, char *student_id) {
  if (served_list->root == NULL) {
    exit(1);
  }

  Node *curr = served_list->root;
  Node *prev = NULL;

  // Loop and compare student ID in linked List
  while (curr != NULL) {
    if (strcmp(curr->student_id, student_id) == 0) { // if match found
      if (prev == NULL) {
        served_list->root = curr->next;
      } else {
        prev->next = curr->next;
      }

      free(curr);
      served_list->size--;
      return;
    }

    prev = curr;
    curr = curr->next;
  }
}

void undoService(Stack *stack, LinkedList *served_list, Queue *queue) {
  if (stack->top == NULL) {
    printf("No previus data\n");
    return;
  }

  // hold top element of stack
  Node *popped_stack_node = stack->top;

  stack->top = stack->top->next;
  stack->size--;

  // destroy the record of service in linked list
  removeFromLinkedList(served_list, popped_stack_node->student_id);

  enqueue(queue, popped_stack_node->student_name, popped_stack_node->student_id,
          popped_stack_node->service_type, popped_stack_node->priority_level);

  printf("Undo Successful!\n");
  printf("The following student has been returned to the waiting queue:\n");
  printf("%s %s %s\n", popped_stack_node->student_id,
         popped_stack_node->student_name, popped_stack_node->service_type);
  free(popped_stack_node);
}

void displayServedList(LinkedList *served_list) {
  if (served_list->size == 0 || served_list->root == NULL) {
    printf("No Data\n");
  }

  int i = 1;
  Node *curr = served_list->root;

  while (curr != NULL) {
    printf("%d. %s %s %s Completed\n", i, curr->student_name, curr->student_id,
           curr->service_type);
    curr = curr->next;
    i++;
  }
}

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

void serveNextStudent(LinkedList *served_list, Queue *queue,
                      Stack *undo_stack) {
  Node *new_node = dequeue(queue);
  if (new_node == NULL) {
    exit(1);
  }

  new_node->next = served_list->root;
  served_list->root = new_node;
  served_list->size++;

  push(undo_stack, new_node);

  printf("Student %s successfully served!\n", new_node->student_name);
}

void searchCompletedService(LinkedList *served_list) {
  char input[11];
  printf("Enter ID of completed service: ");
  scanf("%s", input);

  int found = 0;

  for (Node *curr = served_list->root; curr != NULL; curr = curr->next) {
    if (strcmp(curr->student_id, input) == 0) {
      printf("ID Found!\n");
      printf("%s %s %s Completed\n", curr->student_name, curr->student_id,
             curr->service_type);
      found = 1;
    }
  }

  if (found == 0) {
    printf("Could not find completed service\n");
  }
}

void displaySummary(Queue *queue, LinkedList *served_list, Stack *stack) {
  printf(" - Current Waiting Students : %d\n", queue->size);
  printf(" - Total Students Served    : %d\n", served_list->size);
  printf(" - Actions Available to Undo: %d\n", stack->size);
  printf(" - Total System Volume      : %d\n",
         (served_list->size + served_list->size));
}
int main() {

  int choice;

  Queue *waiting_queue = create_queue();
  LinkedList *served_list = create_list();
  Stack *undo_stack = create_stack();

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
      serveNextStudent(served_list, waiting_queue, undo_stack);
      break;
    case 3:
      displayWaitingList(waiting_queue);
      break;
    case 4:
      displayServedList(served_list);
      break;
    case 5:
      searchCompletedService(served_list);
      break;
    case 6:
      undoService(undo_stack, served_list, waiting_queue);
      break;
    case 7:
      displaySummary(waiting_queue, served_list, undo_stack);
      break;
    case 8:
      break;
    default:
      printf("Please pick enter correct number\n");
    }
  } while (choice != 8);
  return 0;
}