# DS_hw1

To understand how an implementation of an ADT is used by an application program.
To become familiar with how to implement the Stack & Queue . 

Pseudo code
1.	Store the piles of cards with a stack Deck.
2.	Store the indices with deque Orderi.
3.	While(Deck.size() !=1) do
4.	 	Read two different indices from Orderi as t1 and t2.
5.	 	Take out the deques from 1 and max(t1,t2) in the stack and put the t1th deque and the t2th deque into two deques(Deck1, Deck2) respectively and put the others into a queue(Temp).
6.	 	For(every cards in the Deck2)
7.	 		If(the card in the Deck2 is the same as the first card in the Deck1) then
8.	 			Push the card in the Deck2 before the first card in the Deck1.
9.	 		Else
10.	 			Push the card in the Deck2 after the last card in the Deck1.
11.	 	If(the last card in the Deck2 is at first in the Deck1) then
12.	 		Push Deck1 into the Deck first and push Temp into the Deck later.
13.	 	Else
14.	 		Push Temp into the Deck first and Push Deck1 into the Deck later.
15.	 Return Deck

Detailed is in cpp file
