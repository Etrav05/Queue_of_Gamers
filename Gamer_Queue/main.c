#include <stdio.h>
#include <stdbool.h>

#define NAME_LEN			10
#define NUM_OF_USERS		20

// Evan Travis - Prog72370xW25 - assignment 1 - queues

// - Create a struct to represent users in a game [X]
// - Each person has unique username              [X]
// - their level (levels can range from 1 – 60)   [X]
// - their faction (red, blue or green)           [X]

// - The queue should be created as a struct containing two node pointers : for the head and tail of the queue [X]
// - The queue should be created from a set of linked nodes											           [X]
// - Use any code from week04 (or before).The queue will require at minimum :

//		- A function to initialize a blank queue    [X]
//		- A function to check if the queue is empty [X]
//		- A function to enqueue a node              [X]
//		- A function to dequeue a node              [X]
//		- Create a struct to represent a queue node [ ]
//		- This structure contains a node pointer and a user struct as its data [ ]

// - Write a function to enqueue the queue with a number of randomly created users [ ]
// - You will need to pass this function a pointer to an initialized queue         [ ]
// - and the number of users to add to the queue.                                  [ ]
// - The number of users is passed to the program as a command line arg            [ ]
// - Each user will be randomly generated 10 characters in length (ints and char)  [ ]
// - name func returns 0 if it succeeds, and non - zero if something goes wrong    [ ]

// - Write a testing main() function which initializes the queue					     [ ]
// - calls the function to add users to the queue(and reports if an error occurred)		 [ ]
// - then dequeues from the function one at a time until the queue is empty				 [ ]
// - After each dequeue, print on the screen the username, level and faction of the user [ ]


// for random colours -> make an array of the colours and get a random number 0-2 to chose the index [ ]
// properties -> debugging -> command line arg -> number of users you want                           [ ]

typedef struct user {
	char name[NAME_LEN];
	char faction[5];
	int level;
} USER;

typedef struct queue {
	USER* arr;	  // array of users
	int head;	  // first in line
	int tail;     // back of the line
	int capacity; // maximum capacity of the queue
	int size;     // current number of elements in the queue
}QUEUE;

bool isEmpty(QUEUE* q) { 
	return (q->head == q->tail - 1); // this will return -1 if the queue is empty (because head and tail will == -1)
}

bool isFull(QUEUE* q) { 
	return (q->tail == NUM_OF_USERS); 
}

USER enqueue(QUEUE* q, USER u) {
	if (isFull(q)) { // check if the queue is full
		printf("Queue is full\n");
		return;
	}

	q->arr[q->tail] = u; // if not, then add user to queue at the tail
	q->tail = (q->tail + 1); // % q->capacity; // move the tail pointer
	q->size++; // move the tail pointer to the next item
}

USER dequeue(QUEUE* q) {
	USER emptyUser = { "", "", 0}; // default empty User to return

	if (isEmpty(q)) { // check if the queue is empty 
		printf("Queue is empty\n");
		return emptyUser;
	}

	USER user = q->arr[q->head]; // take the item at the front of the queue
	q->head++; // move the head pointer to the next item

	return user; // return item that was dequeued
}

void initializeQueue(QUEUE* q, int capacity) {
	q->capacity = capacity;
	q->arr = (USER*)malloc(capacity * sizeof(USER)); // allocate memory for the queue

	if (q->arr == NULL) { // error handling
		printf("Problem occured while allocating memory\n");
		exit(1); // exit the if the memory allocation fails
	}

	q->head = -1;
	q->tail = 0;
	q->size = 0;
}

int main(int argc, char* argv[]) { // accept commandlin args (this will be the amount of users) --> 20)
	QUEUE q;
	int capacity = atoi(argv[1]); // the command line arg (20) = capacity

	initializeQueue(&q, capacity);

}