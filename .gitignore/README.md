# DS_hw1

To understand how an implementation of an ADT is used by an application program.
To become familiar with how to implement the Stack & Queue . 

Problem Definition

There are a stack of deque and a queue for saving deque temporarily. You have to store piles of cards as deques and put them into a stack in order. After getting data, you have to number the stack from top to bottom starting with 1 and ending with its size. We then give you two different indices, you have to take them from the stack and put the unused ones into queue one after another. 

Of the two deques, you take the first card of the second index deque comparing with the first card of first deque. Cards match if they are of the same suit or same rank, put second one before the first card of first deque; otherwise, put it as the last. 

Each moving causes the second deque decreasing by one card. Repeating the steps above, the second deque has no more cards, and there is one combining deque. Put the deque in queue according to the last card being first or not. Nevertheless, put the deque from queue first and then the combining one. After several iterations, there is only one deque in the stack. File out all cards starting from top of the deque. 
 
Detailed is in cpp file
