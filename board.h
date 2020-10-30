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
;			[x]  Moving pieces                   ;
;	    [x]  Fen implementation                           ;
;           [x]  Move generator                               ;
;           [x]  Search                                       ;
;           [x]  Evaluation                                   ;
\************************************************************/




/*
 	Compile and run the program 
 		$gcc chess_engine.c -o chess_engine && ./chess_engine

*/


// libraries
#include<stdio.h>



/* Piece encoding */

// unicode pieces
char *chess_pieces[] = {".","-","♟︎","♚","♞","♝","♜","♛","-","♙","-","♔","♘","♗","♖","♕"};

enum pieces{
	e, 	// empty square 0
	P,	 // white pond  1
	N, 	// white knight 2
	B, 	// white bishop
	R, 	// white rook
	Q, 	// white queen
	K, 	// white king
	p, 	// black pond
	n, 	// black knight
	b, 	// black bishop
	r, 	// black rook 
	q, 	// black queen 
	k, 	// black king
	o, 	// board limit
};



// chess board representation 0x88

int board[128] = {                 

    22, 20, 21, 23, 19, 21, 20, 22,    0,  0,  5,  5,  0,  0,  5,  0, 
    18, 18, 18, 18, 18, 18, 18, 18,    5,  5,  0,  0,  0,  0,  5,  5,
     0,  0,  0,  0,  0,  0,  0,  0,    5, 10, 15, 20, 20, 15, 10,  5,
     0,  0,  0,  0,  0,  0,  0,  0,    5, 10, 20, 30, 30, 20, 10,  5,    
     0,  0,  0,  0,  0,  0,  0,  0,    5, 10, 20, 30, 30, 20, 10,  5,
     0,  0,  0,  0,  0,  0,  0,  0,    5, 10, 15, 20, 20, 15, 10,  5,
     9,  9,  9,  9,  9,  9,  9,  9,    5,  5,  0,  0,  0,  0,  5,  5,
    14, 12, 13, 15, 11, 13, 12, 14,    0,  0,  5,  5,  0,  0,  5,  0

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


int piece_weights[] = { 0, 0, -100, 0, -300, -350, -500, -900, 0, 100, 0, 0, 300, 350, 500, 900 };


enum side_to_play{ WHITE = 8, BLACK = 16};// white 1000 and black is 10000



int move_offsets[] = {
     15,  16,  17,   0,                           // white pawns
     -15, -16, -17,   0,                           // black pawns
     1,  16,  -1, -16,   0,                      // rooks
     1,  16,  -1, -16,  15, -15, 17, -17,  0,    // queens, kings and bishops
    14, -14,  18, -18,  31, -31, 33, -33,  0,    // knights
    3,  -1,  12,  21,  16,   7, 12              
                                                                  
};


int depth = 3;    
int source, destination;   
int best_src, best_dst; 


// show the board 
void show_board();


// reset the state of the board 
void reset();


//Alpha beta search
int alpha_beta_search(int side, int depth, int alpha, int beta) ;






