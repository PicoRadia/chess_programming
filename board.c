// Print the board to the console
void show_board(){
	
	 for(int square = 0; square < 128; square++)
    	{
		if(!(square % 16)) printf(" %d  ", 8 - (square / 16));    
		printf(" %s", ((square & 8) && (square += 7)) ? "\n" : chess_pieces[board[square] & 15]);  		
    	}
	printf("\n     a b c d e f g h \n\n\n"); // print files
	printf("\n Enter a valid move : \n");
	
	
}




// reset the board => remove all the pieces
void reset(){
	for(int i = 0 ; i<8 ; i++){//loop over the ranks
		for(int j=0;j<16;j++ ){// loop over the files
			int square = 16 * i + j; 

			// print the board's valid quares
			if(!(square & 0x88)){
				board[square] = e;
			}
		}
		
	}

}

