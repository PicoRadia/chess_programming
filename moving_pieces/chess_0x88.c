/*
 * ---------------------------
	Chess programming 
	         BY 
	     FAST DEV
	     (0x88)
	
 * -----------------------------  
*/

// headers 

#include <stdio.h>

// piece encoding
  //Majuscule => White pieces & miniscule => black pieces .
  //enum is a data type that contains constants and maps them to an integer starting at 0.

enum {e , P , N , B , R , Q , K , p , n , b , r , q , k , o};

// ascii pieces
char ascii_pieces[] = ".PNBRQKpnbrqko";


// unicode pieces
char* unicode_pieces[] = {" . "," ♙ "," ♘ "," ♗ "," ♖ "," ♕ "," ♔ "," ♟︎ "," ♞ "," ♝ "," ♜ "," ♛ "," ♚ "};

// chess board representation 
  // file is the column and rank is the line
int board[128] = {
	r , n , b , q , k , b , n , r , o , o , o , o , o , o , o , o ,  
	p , p , p , p , p , p , p , p , o , o , o , o , o , o , o , o ,
        e , e , e , e , e , e , e , e , o , o , o , o , o , o , o , o ,	
        e , e , e , e , e , e , e , e , o , o , o , o , o , o , o , o ,
        e , e , e , e , e , e , e , e , o , o , o , o , o , o , o , o ,
        e , e , e , e , e , e , e , e , o , o , o , o , o , o , o , o ,
        P , P , P , P , P , P , P , P , o , o , o , o , o , o , o , o , 
	R , N , B , Q , K , B , N , R , o , o , o , o , o , o , o , o , 
};

// print board function 
void print_board()
{
	// pint new line
	printf("\n\n\n");


	// loop over board ranks
	for (int rank = 0 ; rank < 8 ; rank++){
	 	for( int file = 0 ; file <16 ; file++){
			// init square
			int square = rank * 16 + file ;

			// print ranks
			if(file == 0){
				printf("%d   " , 8-rank);
			};
			
			// print only on board square
			if(!(square & 0x88)){

				printf("%s" ,unicode_pieces[board[square]]);
			}
		}
		// print new line everytime a new rank is encountered
		printf("\n");
	}

	// print file 
	printf("\n     a  b  c  d  e  f  g  h \n\n\n");
	
}

// main driver

int main()
{
	print_board();
	printf("♞");
	return 1;
}




