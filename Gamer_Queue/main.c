#include <stdio.h>
#include <stdbool.h>
#include <random>
#include <time.h>

#define FACTION				5
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
//		- Create a struct to represent a queue node [X]
//		- This structure contains a node pointer and a user struct as its data [X]

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
	char faction[FACTION];
	int lvl;
} USER;

typedef struct queueNode {
	USER user;                // user data
	struct queueNode* next;  // pointer to the next node in the queue
} QUEUENODE, *PQUEUENODE;

typedef struct queue {
	PQUEUENODE head;    // pointer to the head of the queue
	PQUEUENODE tail;    // pointer to the tail of the queue
	int capacity;        // maximum capacity of the queue
	int size;            // current number of elements in the queue
} QUEUE;

bool isEmpty(QUEUE* q) { 
	return q->size == 0; // this will return -1 if the queue is empty (because head and tail will == -1)
}

bool isFull(QUEUE* q) { 
	return (q->tail == q->capacity); 
}

USER enqueue(QUEUE* q, USER u) {
	if (isFull(q)) { // check if the queue is full
		printf("Queue is full\n");
		return;
	}

	PQUEUENODE newNode = (PQUEUENODE)malloc(sizeof(QUEUENODE));
	if (!newNode) {
		printf("Error allocating memory to queue node\n");
		exit(1);
	}

	newNode->user = u;  // assign user to new node
	newNode->next = NULL;

	if (isEmpty(q)) { // if the queue is empty this new node will be both the tail and head
		q->head = newNode;
		q->tail = newNode;
	}
	else { // if the queue already has stuff in it, then the tail will now be this new node
		q->tail->next = newNode; 
		q->tail = newNode;
	}

	q->size++; // the queue has grown
}

USER dequeue(QUEUE* q) {
	USER emptyUser = { "", "", 0}; // default empty User to return

	if (isEmpty(q)) { // check if the queue is empty 
		printf("Queue is empty\n");
		return emptyUser;
	}

	PQUEUENODE temp = q->head; // if queue isnt empty then get the node at the head
	USER user = temp->user;

	q->head = q->head->next; // after dequeuing, move the head pointer to the node behind head

	if (q->head == NULL) { // if the queue has now become empty, then the tail should be set to NULL
		q->tail = NULL;
	}

	free(temp);

	q->size--; // the queue has decreased
	return user; // return item that was dequeued
}

QUEUE* initializeQueue(int capacity) {
	QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE)); // allocate memory for the queue

	if (!q) { // error handling
		printf("Error allocating memory to queue\n");
		exit(1); // exit the if the memory allocation fails
	}

	q->head = NULL;
	q->tail = NULL;
	q->capacity = capacity;
	q->size = 0;
}

void randomUser(char* str) { // make a random username 
	char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; // list off all the characters to choose from
	int charsetSize = sizeof(charset) - 1; // exclude the null terminator

	srand(time(NULL)); // seed the random function

	for (int i = 0; i < NAME_LEN; i++) {
		int randI = rand() % charsetSize; // choose a random element of the character set
		str[i] = charset[randI]; // create a string of these choices
	};

	USER user = { " " };

	enqueue(q, );

	str[NAME_LEN] = '\0'; // add null-terminator to the string
}

USER createRandomUser(char name[], char faction[], int lvl) {



}

int main(int argc, char* argv[]) { // accept commandlin args (this will be the amount of users) --> 20)
	QUEUE* q = initializeQueue(argv[1]); 



	free(q);

	return 0;
}