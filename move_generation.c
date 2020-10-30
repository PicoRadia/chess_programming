// search => Alpha beta search  + Evaluation function
// recursive function

int alpha_beta_search(int side, int depth, int alpha, int beta) 
{
	if(depth == 0)   
	{	        
		int score1 = 0, score2 = 0, pce, evaluation = 0;
		for(int square = 0; square < 128; square++)    
		{
			    if(!(square & 0x88))    
			    {
				if(pce = board[square])    
				{
				    score1 += piece_weights[pce & 15]; 
				    (pce & 8) ? (score2 += board[square + 8]) : (score2 -= board[square + 8]); 
				}
			    }
			}
			
			
			evaluation = score1 + score2;

			return (side == 8) ? evaluation : -evaluation;   
	}
	
	int old_alpha = alpha;    
	int temp_src;            
	int temp_dst;             
	int score = -10000;  // minus infinity
	int piece, type, directions, dst_square, captured_square, captured_piece, step_vector; 	   

	for(int src_square = 0; src_square < 128; src_square++)    // loop over board squares
	{
	if(!(src_square & 0x88))    // check if square where piece to generate moves for stands is on board
	{
	    piece = board[src_square];    // store current piece code (might be empty square if no piece)
		                        
	    if(piece & side)    // if piece belongs to the moving side
	    {
		type = piece & 7;  
		directions = move_offsets[type + 30];    // init current piece's move offsets list pointer
		
		while(step_vector = move_offsets[++directions])    // loop over move offsets
		{
		    dst_square = src_square;    // init destination square (to square)
		    
		    do                          // loop over destination squares within one ray (for sliders)
		    {           
		        dst_square += step_vector;    // get next destination square
		        captured_square = dst_square;    // init square where piece capture occurs
		        
		        if(dst_square & 0x88) break;    // break out of loop if destination square is off board

		        captured_piece = board[captured_square];    // init captured piece

		        if(captured_piece & side) break;    // break if captured own piece
		        if(type < 3 && !(step_vector & 7) != !captured_piece) break;    // pawns captures only diagonally
		        if((captured_piece & 7) == 3) return 10000;    /* score move on king capture,
		                                                          we are at the illegal branch now, so no
		                                                          need to keep searching any further
		                                                       */
		        // make move
		        board[captured_square] = 0;    // clear captured square
		        board[src_square] = 0;         // clear source square (from square where piece was)
		        board[dst_square] = piece;     // put piece to destination square (to square)

		        // pawn promotion
		        if(type < 3)    // if pawn
		        {
		            if(dst_square + step_vector + 1 & 0x80)    // goes to the 1th/8th rank
		                board[dst_square]|=7;    // convert it to queen
		        }
		        
		        score = -alpha_beta_search(24 - side, depth - 1, -beta, -alpha);  
		                              
		        board[dst_square] = 0;   
		        board[src_square] = piece;     
		        board[captured_square] = captured_piece;    

		        best_src = src_square;
		        best_dst = dst_square;
	       
		        if(score > alpha)
		        {
		            if(score >= beta)
		                return beta;
		            alpha = score;     
		            temp_src = src_square;
		            temp_dst = dst_square;
		        }              	        
		        captured_piece += type < 5; 	       
		        if(type < 3 & 6*side + (dst_square & 0x70) == 0x80)captured_piece--;
		    }

		    while(!captured_piece);   
		}
	    }
	}
	}

	if(alpha != old_alpha)
	{
	best_src = temp_src;
	best_dst = temp_dst;
	}

	return alpha;   
}
