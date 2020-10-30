/******************************************************************************************************\								
;												      ;
; 	  +- author       : Radia EL HAMDOUNI .							      ;
;	  +- start date   : October 26th , 2020.						      ;
;	  +- deadline     : November 3rd , 2020.				                      ;
;	  +- Goal         : Program the computer to play chess.	                                      ;
;	  +- Licence      : MIT licence.                         				      ;
;-----------------------------------------------------------------------------------------------------;
;	  +- description  : 						                              ;
;	    - The user can play against the chess engine that will predict                            ;
;	    the best moves to win the game.	                                                      ;
;	                                                                                              ;
;												      ;			
/*****************************************************************************************************/
 
/******************************************************************************************************\								
;												      ;
;  To compile and run the program :                                                                   ;
;                                                                                                     ;
;	+- Using the makefile :                                                                       ;
;	   // compile the progam								      ;
;	   $make  							  			      ;
;	   // run the program								              ;
;          $./chess_engine 								  	      ;
;	   // both compile and run the program 							      ;
;	   $ make && ./chess_engine                                                                   ;
;  		                                                                                      ;
/*****************************************************************************************************/

/*****************************************************************************************************\								
;												      ;
; 	+- How to play the game:							              ;
;               First compile and run the program(see the corresponding section)                      ;   	          
;           											      ;
;			/****** Start ******/		                                              ;     
;												      ;	
;												      ;
;			 8   ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜ 					                      ;
;			 7   ♟︎ ♟︎ ♟︎ ♟︎ ♟︎ ♟︎ ♟︎ ♟︎   					                      ;
;			 6   . . . . . . . . 					                      ;
;			 5   . . . . . . . . 							      ;
;			 4   . . . . . . . . 						              ;
;			 3   . . . . . . . . 					                      ;
;			 2   ♙ ♙ ♙ ♙ ♙ ♙ ♙ ♙ 						              ;
;			 1   ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖ 							      ;
;												      ;	
;			     a b c d e f g h 							      ;	
;										                      ; 
;--------------------// The user needs to enter a valid move a string of 4 characters // -------------;
;    #---------------- the string is composed of the square source piece that the user waants to move ;
;    	                and the destination square without spaces.			              ;
;-----------// example e2e4 => move the piece in e2 to e4	                                      ;
;							                                              ;
;			 Enter a valid move : 			                                      ;
;			e2e4                                                                          ;
;			 8   ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜ 							      ;	 
;			 7   ♟︎ ♟︎ ♟︎ ♟︎ ♟︎ ♟︎ ♟︎ ♟︎ 							      ;
;			 6   . . . . . . . . 							      ;
;			 5   . . . . . . . . 							      ;	 
;			 4   . . . . ♙ . . . 						              ;  
;			 3   . . . . . . . . 							      ;
;			 2   ♙ ♙ ♙ ♙ . ♙ ♙ ♙ 							      ;	
;			 1   ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖ 							      ;
;												      ;	
;			     a b c d e f g h 						  	      ;	
;												      ;
;-------------------// the chess engine will make the next move and it will be shown on the board     ;	 
;								                                      ;
;			 Enter a valid move : 							      ;	
;			 8   ♜ ♞ ♝ ♛ ♚ ♝ ♞ ♜ 							      ;
;			 7   ♟︎ ♟︎ ♟︎ . ♟︎ ♟︎ ♟︎ ♟︎ 							      ;
;			 6   . . . . . . . . 						  	      ;	
;			 5   . . . ♟︎ . . . . 						 	      ;	
;			 4   . . . . ♙ . . . 							      ;
;			 3   . . . . . . . . 						              ;  			
;			 2   ♙ ♙ ♙ ♙ . ♙ ♙ ♙ 					                      ;
;			 1   ♖ ♘ ♗ ♕ ♔ ♗ ♘ ♖ 				                              ;
;										                      ;
;			     a b c d e f g h 							      ;	
; 												      ; 	
;--------------------// then it's the players  turn		                                      ;
/*****************************************************************************************************/


/*****************************************************************************************************\								
;												     ;
;	+- Functionnlities :        						                     ;
; 	     + 0x88 board representation with unicode encoding of the chess pieces. 	             ;
;            + Move generation .   		                                                     ;
;		+ Pawn promotion .								     ;
;	     + Search algorithm 							             ;
;	     	+- Alpha Beta Search .					                             ;
;                                                             					     ;	
;            +- Evaluation function .                                                                 ;
;	                                                                                              ;
;	   								                              ;
;-----------------------------------------------------------------------------------------------------;			
;	+- Possible improvements :      							      ;	
;		- Let the user choose the color. 				                      ;
;               - Implement Fen representation .	                                              ;
;	       	- Implement castling .                                                                ;
;                - Implement en pasant .                                                              ;               
;	        - Change the board representation => Instead of using 0x88 and store the board in an  ;
;		array with the size 128 , we can implement the bitboard representation with a computer; 
;		with the architecture 64 bits and use 12 integers to store the 			      ;
;		state of the chess board .			        			      ;
;		- Make the chess engine play itself for test purposes .                               ;
;		- Add opening book .                                                                  ;
;		- Implement Do and Undo moves                                                         ;
;		- Add a GUI for a better playing experience .                                         ;
;		- Implement a Neural Networks in the evaluation function . This will make our         ;
;		  ELO rating higher.								      ;
;		- We can integrte  NNUE to the  chess engine which is the stockfish's Neural Network  ;
;		  Or we can write our own Neural Network .                                            ;
;           								  	                      ;
;	                                                                                              ;
/*****************************************************************************************************/




/******************************************************************************************************\								
;												      ;
;  Files present in the program                                                                       ;
;                                                                                                     ;
;	+- makefile           // to compile the file                                                  ;            
;	+- README.txt         // cotains the description of the project				      ;
;	+- board.h            // contains the main data structures (board,pieces encoding..)          ;
;	+- board.c	      // contains the show and reset board functions	      		      ;
;	+- move_generation.c  // contains the tree search function using the alpha beta search algo   ;
;	+- play_chess.c       // deals with player interaction and moves pieces according to the      ;
;			      // best moves generated by the search function .Also checks for checkMate;
;	+-chess_engine.c      // contains the main driver 	                                      ;
;						                                                      ;		
/*****************************************************************************************************/
		
		

/****************************************************************************************************\
;												      ;	
;	 +- Chess board representation :   => 0X88 board representation . 			      ;
;           											      ;	
;           --------------------------						                      ;
;            Ressources/documentation: 							              ;
;            -------------------------							  	      ;	
;            											      ; 
;            *  https://web.archive.org/web/20130212063528/http://www.cis.uab.edu/hyatt/boardrep.html ;
;            *  https://en.wikipedia.org/wiki/0x88				                      ;
;            *  https://decimal.info/hex-to-decimal/8/how-to-convert-0X88-to-decimal.html	      ;
;					                                                              ;
;												      ;	
;	    - Chess board in bash console :  							      ;	
;		                                                                                      ;
; 	                8    ♜  ♞  ♝  ♛  ♚  ♝  ♞  ♜ 		                                      ;
;	                7    ♟︎  ♟︎  ♟︎  ♟︎  ♟︎  ♟︎  ♟︎  ♟︎ 						      ;		
;	                6    .  .  .  .  .  .  .  .  						      ;	
;	                5    .  .  .  .  .  .  .  . 					              ;
;	                4    .  .  .  .  .  .  .  . 	 					      ;
;	                3    .  .  .  .  .  .  .  . 			  			      ;
;	                2    ♙  ♙  ♙  ♙  ♙  ♙  ♙  ♙ 						      ;
;	                1    ♖  ♘  ♗  ♕  ♔  ♗  ♘  ♖ 						      ;
;	    										              ;
;	                     a  b  c  d  e  f  g  h 						      ;
;											              ;
;										                      ;
;												      ;
/*****************************************************************************************************/	
			
		
		
		
/****************************************************************************************************\
;	+-Ressources :						                                      ;
;						                                                      ;
;		+- ASCII art for chess:								      ;
;		    *   https://www.asciiart.eu/sports-and-outdoors/chess			      ;	 	
;							                                              ;
;		+- ASCII Table : 			                                              ;
		   *	 http://www.asciitable.com/			                              ;
;					                                                              ; 	
;		+- Inspiration :								      ; 	
;		    Micro-max minimalist chess 							      ;			
;		    *	https://home.hccnet.nl/h.g.muller/max-src2.html                               ;
;			                                                                              ;
;		+- Chess symbols in Unicode :                                                         ;
;		   *    https://en.wikipedia.org/wiki/Chess_symbols_in_Unicode                        ;
;                                                                                                     ;
;		+- Chess board notation :     						              ;
; 										                      ;
;			  =>  Algebraic notation .		                                      ;
;			                                                                              ;
;			    --------------------------                                                ;
;			    Ressources/documentation:                                                 ;
;			    -------------------------     		                              ;
;			    *  https://en.wikipedia.org/wiki/Algebraic_notation_(chess)               ; 
;		+- ELO rating system : 						                      ;
;			* https://en.wikipedia.org/wiki/Elo_rating_system		              ;
;		+- FEN notation(Forsyth–Edwards Notation) : 					      ;
;			* 	https://en.wikipedia.org/wiki/Forsyth%E2%80%93Edwards_Notation        ;
;		+- Bitwise operations :								      ;
;			*        https://fr.wikipedia.org/wiki/Op%C3%A9ration_bit_%C3%A0_bit 	      ;		
; 												      ;
;		+- Alpha Beta Search :					                              ; 	
;*http://web.archive.org/web/20070704121716/http://www.brucemo.com/compchess/programming/alphabeta.html;	
;		+- Special chess moves : 			                                      ;
;			+-En passant :                                                                ;
;			*    https://www.youtube.com/watch?v=1q7lZilVy04                              ;
;			                                                                              ;							
;		+- Bitwise with 0x88 :								      ;
;			*https://stackoverflow.com/questions/16184092/if-index-0x88-0-how-this-works  ;
;		+- comparaison of chess engines :  						      ;		
;			* https://www.youtube.com/watch?v=wljgxS7tZVE		                      ;
;		+- How do chess engines work BY Oliver Zeigermann : 				      ;
;			* https://www.youtube.com/watch?v=P0jd8AHwjXw				      ;
;	        +- Computer chess how it thinks :						      ;	
;	        	* https://www.youtube.com/watch?v=CFkhUajb8c8				      ;
; 						                                                      ;	
/*****************************************************************************************************/

/****************************************************************************************************\
;	+- Vocabulary :                                                                              ;
;		+- file is the column .		 			                             ;
;		+- rank is the line .                                                                ;
; 				 								     ;
;	+- Notation :			                                                             ;
;		+- Black pieces are referenced in the code with lower case letters .                 :
;		+- White pieces are referenced in the code with Upper case letters .  		     ;	
;		+ Standard Algebraic notation 'SAN' :					             ;  	
;			P : pawn 						                     ;
;			R : rook  								     ;
;			N : Knight 							             ;
;			B : Bishop              				                     ;
;			Q : Queen 	 				                             ; 
;			K : King                                                                     ;
;	+- Fen Notation 'Forsyth–Edwards Notation' :	           				     ;
;												     ;
;	  A string that stores the state of the board and contains the following data                ;
;	  example : "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2"	             ;
;			+ Board State => Piece placements.                                           ;
;			+ Active turn => Next color to make a move (w,b)                             ;
;			+ Castling => KQkq .				            		     ;
;			+ En passant .								     ;
;			+ Halfmove clock .						             ;
;			+ Fullmove number . 					 		     ;
;							   				             ;
; 												     ;		
;												     ;
/*****************************************************************************************************/








 
