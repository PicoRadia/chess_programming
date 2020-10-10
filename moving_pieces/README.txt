----------------------------------------------------------------------

  - author : Fast Dev .
  - date   : October 20th , 2020.
  - description : 
        - The file chess_0x88.c contains the source code of the representation 
        of the chess board in the terminal using ascii characters or unicode
        characters . 
        - To compile the file use the command : 
          $ gcc chess_0x88.c -o chess_0x88
        - To run the executable , call the name of the file :
          $ chess_0x88
        - To both compile and run the executable in the terminal : 
          $ gcc chess_0x88.c -o chess_0x88 && chess_0x88
        - The white pieces are referenced with Majuscule letters while the black pieces 
        are referenced in miniscule letters (in the code).
        - To move a piece :
            first empty it's square. Example ==> board[e2]=e;
            then move it . Example => board[e4] = P;


Test Example : 
            8    ♜  ♞  ♝  ♛  ♚  ♝  ♞  ♜ 
            7    ♟︎  ♟︎  ♟︎  ♟︎  ♟︎  ♟︎  ♟︎  ♟︎ 
            6    .  .  .  .  .  .  .  . 
            5    .  .  .  .  .  .  .  . 
            4    .  .  .  .  ♙  .  .  . 
            3    .  .  .  .  .  .  .  . 
            2    ♙  ♙  ♙  ♙  .  ♙  ♙  ♙ 
            1    ♖  ♘  ♗  ♕  ♔  ♗  ♘  ♖ 

                 a  b  c  d  e  f  g  h 

            8    ♜  ♞  ♝  ♛  ♚  ♝  ♞  ♜ 
            7    ♟︎  ♟︎  ♟︎  ♟︎  ♟︎  .  ♟︎  ♟︎ 
            6    .  .  .  .  .  ♟︎  .  . 
            5    .  .  .  .  .  .  .  . 
            4    .  .  .  .  ♙  .  .  . 
            3    .  .  .  .  .  .  .  . 
            2    ♙  ♙  ♙  ♙  .  ♙  ♙  ♙ 
            1    ♖  ♘  ♗  ♕  ♔  ♗  ♘  ♖ 

                 a  b  c  d  e  f  g  h 


            8    ♜  ♞  ♝  ♛  ♚  ♝  ♞  ♜ 
            7    ♟︎  ♟︎  ♟︎  ♟︎  ♟︎  .  ♟︎  ♟︎ 
            6    .  .  .  .  .  ♟︎  .  . 
            5    .  .  .  .  .  .  .  . 
            4    .  .  .  .  ♙  .  .  . 
            3    .  .  .  .  .  ♘  .  . 
            2    ♙  ♙  ♙  ♙  .  ♙  ♙  ♙ 
            1    ♖  ♘  ♗  ♕  ♔  ♗  .  ♖ 

                 a  b  c  d  e  f  g  h 

            8    ♜  ♞  ♝  ♛  ♚  ♝  ♞  ♜ 
            7    ♟︎  ♟︎  ♟︎  ♟︎  ♟︎  .  ♟︎  . 
            6    .  .  .  .  .  ♟︎  .  . 
            5    .  .  .  .  .  .  .  ♟︎ 
            4    .  .  .  .  ♙  .  .  . 
            3    .  .  .  .  .  ♘  .  . 
            2    ♙  ♙  ♙  ♙  .  ♙  ♙  ♙ 
            1    ♖  ♘  ♗  ♕  ♔  ♗  .  ♖ 

                 a  b  c  d  e  f  g  h 



            

----------------------------------------------------------------------
