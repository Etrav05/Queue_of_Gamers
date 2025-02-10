
// Evan Travis - Prog72370xW25 - assignment 1 - queues

// - Create a struct to represent users in a game [ ]
// - Each person has unique username              [ ]
// - their level (levels can range from 1 – 60)   [ ]
// - their faction (red, blue or green)           [ ]

// - The queue should be created as a struct containing two node pointers : for the head and tail of the queue [ ]
// - The queue should be created from a set of linked nodes											           [ ]
// Use any code from week04 (or before).The queue will require at minimum :

// - A function to initialize a blank queue    [ ]
// - A function to check if the queue is empty [ ]
// - A function to enqueue a node              [ ]
// - A function to dequeue a node              [ ]
// - Create a struct to represent a queue node [ ]
// - This structure contains a node pointer and a user struct as its data [ ]

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