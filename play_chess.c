
void play_chess(){

	    // storing user input (format: e2e4, queening is automatical)
	
	int side = WHITE;    // user starts first with the color white
	
	char move[5];
	show_board();
	while(1)  
	{
	memset(&move[0], 0, sizeof(move));   
	if(!fgets(move, 5, stdin)) continue;   
	if(move[0] == '\n') continue;    
	
	for(int square = 0; square < 128; square++)    // loop over board squares
	{
	    if(!(square & 0x88))    // if square is onboard
	    {
		if(!strncmp(move, algebraic_board[square], 2))    
		    source = square;                         

		if(!strncmp(move + 2, algebraic_board[square], 2))    
		    destination = square;                            
	    }
	}

	 
        // make user move
        board[destination] = board[source];
        board[source] = 0;

        // if pawn promotion
        if(((board[destination] == 9) && (destination >= 0 && destination <= 7)) ||
           ((board[destination] == 18) && (destination >= 112 && destination <= 119)))
            board[destination] |= 7;

        show_board();

        side = 24 - side;   // change side
              
        int score = alpha_beta_search(side, depth, -10000, 10000);

        // make AI move
        board[best_dst] = board[best_src];
        board[best_src] = 0;

        // if pawn promotion
        if(((board[best_dst] == 9) && (best_dst >= 0 && best_dst <= 7)) ||
           ((board[best_dst] == 18) && (best_dst >= 112 && best_dst <= 119)))
            board[best_dst] |= 7;

        side = 24 - side;   

        show_board();
        if(score == 10000 || score == -10000) {printf("Checkmate!\n"); break;}
        

    }

}
