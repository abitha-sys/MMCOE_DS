#include <iostream> 
using namespace std; 
int main () { 
    	int player1[5]; 
  	int player2[5]; 
   	int a; 
    	cout << "Enter the scores of 5 rounds for Player 1: " << endl; 
    	for (int i=0; i < 5; i++) { 
        	cin >> player1[i]; 
    	}  
    	cout << "\n\nEnter scores of 5 rounds for Player 2: " << endl; 
    	for (int i=0; i < 5; i++) { 
        	cin >> player2[i]; 
    	} 
    	for (int pass=0; pass < 5; pass++) { 
        	for (int i=0; i < (5-pass-1); i++) { 
            		if (player1[i] < player1[i+1]) { 
                			a = player1[i]; 
                			player1[i] = player1[i+1]; 
                			player1[i+1] = a; 
            		} 
        	} 
   	 } 
    	for (int pass=0; pass < 5; pass++) { 
       		for (int i=0; i < (5-pass-1); i++) { 
            		if (player2[i] < player2[i+1]) { 
                			a = player2[i]; 
                			player2[i] = player2[i+1]; 
                			player2[i+1] = a; 
            		} 
        	} 
    	} 
    	cout << "Swapping scores and leveling up!!!" << endl; 
    	cout << "Scores have been swapped!" << endl; 
    	cout << "The sorted scores are: " << endl; 
    	cout << "Scores of Player 1: "; 
    	for (int i=0; i < 5; i++) { 
       	 	cout << player1[i] << ", "; 
    	} 
    	cout << endl; 
    	cout << "Scores of Player 2: "; 
    	for (int i=0; i < 5; i++) { 
        	cout << player2[i] << ", "; 
    	} 
    	cout << endl; 
    	if (player1[0] > player2[0]) { 
       	 	cout << "Player 1 is the winner!" << endl; 
    	} else if (player2[0] > player1[0]) { 
        	cout << "Player 2 is the winner!" << endl; 
    	}  else { 
       		 cout << "Its a tie!" << endl; 
    	} 
    	return 0; 
} 
