                                                                  # Rocket_Race#
                                                                  ==============
    This is a board game with (C++) between 2 players
   _____________________________________________________________
 **Rules of the game**:
 ======================
     1- You will be asked to enter your name ,and after this you will be asked to enter the number of board's
     dimension as you like (for example if you entered 5 , the board dimension will be 5 * 5).
     #########################
     2- Each player has (n - 2 --> for example if you enterd 5 then each of you will have 3 rockets).
    #########################
    3- Now let's talk about the game and let's take an example of 3 rockets for both players.
    #########################
    4- you have (1 , 2 , 3) as rocket numbers and your move will be choosing any rocket of the 3 to move.
    #########################
    5- If the rocket can move to the next cell then it will move.
    #########################
    6- If you choose a number of a rocket and you found a rocket of the enemy infront of it, your rocket will jump above this rocket and pass it
    to next cell of the enemy's rocket.
    *Like this:
                    
            This -->   X U U U X              will be this -->   X - U U X 
                       - > - - -                                 - > - - -                   
                       > - - - -                                 > U - - - 
                       > - - - -                                 > - - - - 
                       X - - - X                                 X - - - X
                       
                       
    #########################
    7- So when willnot it be allowed to move a rocket?
    --> When you choose a rocket and there are 2 rockets or more infront of it directly.
    *As you see rocket 1 of ("U") cannot move:

                                    X U U - X 
                                    - > - U -
                                    - > - - -
                                    > - - - -
                                    X - - - X
    #########################
  
      8- Winning case will be when any player will get all the rockets to their destinations.
    *Like This:
  
                        X - - - X 
                        - - - - >         Dest 1
                        - - - - >         Dest 2
                        - U - - >         Dest 3
                        X - U U X
    _____________________________________________________________
Thanks for playing :) :)
