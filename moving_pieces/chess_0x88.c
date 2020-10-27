/* ---------------------------------------------------------
============================================================

			Chess Engine in C Language
			==========================

				8 |_|#|_|#|_|#|_|#|
				7 |#|_|#|_|#|_|#|_|
				6 |_|#|_|#|_|#|_|#|
				5 |#|_|#|_|#|_|#|_|
				4 |_|#|_|#|_|#|_|#|
				3 |#|_|#|_|#|_|#|_|
				2 |_|#|_|#|_|#|_|#|
				1 |#|_|#|_|#|_|#|_|
				   a b c d e f g h

-----------------------------------------------------------
						BY
				Radia EL HAMDOUNI
				
				MLOD - Mini-Projet 
				
				
					
====================================================					
\---------------------------------------------------*/

/************************************************************\
;------------------------------------------------------------;
;                 Chess engine in C                          ;
;                                                            ;
;------------------------------------------------------------;
;    TODO :                                                  ;
;           [x] Bitboard representation                      ;
			[x]  Moving pieces                               ;
;           []  Move generator                               ;
;           []  Search                                       ;
;           []  Evaluation                                   ;
\************************************************************/




/*
 	Compile and run the program 
 		$gcc chess_engine.c -o chess_engine && ./chess_engine

*/


// Libraries
#include<stdio.h>


// Upper Case letters => White pieces .
// Lower Case letters => Black pieces .

// for the mapping
enum pieces{
e, // empty square
P, // white pond
N, // white knight
B, // white bishop
R, // white rook
Q, // white queen
K, // white king
p, // black pond
n, // black knight
b, // black bishop
r, // black rook 
q, // black queen 
k, // black king
o, // board limit
};


// unicode pieces
char* chess_pieces[] = {" . "," ♙ "," ♘ "," ♗ "," ♖ "," ♕ "," ♔ "," ♟︎ "," ♞ "," ♝ "," ♜ "," ♛ "," ♚ "};

// character indexes
int char_pieces[] = {
    ['P'] = P,
    ['N'] = N,
    ['B'] = B,
    ['R'] = R,
    ['Q'] = Q,
    ['K'] = K,
    ['p'] = p,
    ['n'] = n,
    ['b'] = b,
    ['r'] = r,
    ['q'] = q,
    ['k'] = k,
};


// chess board representation 0x88
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

// mapping the board to algebraic notation
char *algebraic_board[] = {
    "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8", "i8", "j8", "k8", "l8", "m8", "n8", "o8", "p8",
    "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7", "i7", "j7", "k7", "l7", "m7", "n7", "o7", "p7",
    "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6", "i6", "j6", "k6", "l6", "m6", "n6", "o6", "p6",
    "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5", "i5", "j5", "k5", "l5", "m5", "n5", "o5", "p5",
    "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4", "i4", "j4", "k4", "l4", "m4", "n4", "o4", "p4",
    "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3", "i3", "j3", "k3", "l3", "m3", "n3", "o3", "p3",
    "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2", "i2", "j2", "k2", "l2", "m2", "n2", "o2", "p2",
    "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1", "i1", "j1", "k1", "l1", "m1", "n1", "o1", "p1"
};



// valid squares in algebraic notation
enum squares {
    a8 = 0, b8, c8, d8, e8, f8, g8, h8,
    a7 = 16, b7, c7, d7, e7, f7, g7, h7,
    a6 = 32, b6, c6, d6, e6, f6, g6, h6,
    a5 = 48, b5, c5, d5, e5, f5, g5, h5,
    a4 = 64, b4, c4, d4, e4, f4, g4, h4,
    a3 = 80, b3, c3, d3, e3, f3, g3, h3,
    a2 = 96, b2, c2, d2, e2, f2, g2, h2,
    a1 = 112, b1, c1, d1, e1, f1, g1, h1
};


// Print the board to the console
void show_board(){
	// pint new line
	printf("\n\n\n");
	
	// A rank is a line
	// A file is a column
	for(int i = 0 ; i<8 ; i++){//loop over the ranks
		for(int j=0;j<16;j++ ){// loop over the files
			int square = 16 * i + j; 
		
			if(j == 0){
				printf("%d   " , 8-i); // print ranks
			}
			
			// print the board's valid quares
			if(!(square & 0x88)){

				printf("%s" ,chess_pieces[board[square]]);
			}
		}
		printf("\n");
	}
	printf("\n     a  b  c  d  e  f  g  h \n\n\n"); // print files
	
	
}




// Main
int main(){
	
	// moving chess pieces
	board[e2] = e;
	board[e4] = p;
	show_board();	
	return 1;	
}





