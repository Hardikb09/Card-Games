#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<string.h>
typedef struct pile pile;
struct pile
{
  int val;
  char suit;
  pile *next;

};
typedef struct
{ int val;
  char suit;
}card;

COORD coord = {0, 0};
//gotoxy function
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void peekabootitle();                                       //peekaboo title page
int peekaboo();                                             //peekaboo game
int position(int array[],int size,int key);                 //returns the position of a key in array;
int positioncard(card array[],int size,card key);           //find position of a card in deck
int positioncardval(card array[],int size,int key);         //find the position of a value in a deck
int find_in_array(int array[],int size,int key);            //find whether an element is present in an array or not
int find_in_cardarray(card array[],int size,int key);       //find whether an element is present in an array of cards or not
void remove_from_array(int array[],int key,int *cnt);       //removes the element key from array
void remove_from_cardarray(card array[],card key,int *cnt); //removes the card from array of cards
void display_value(card c,int i);                           //display the value of a card
void display_blank(card c,int i);                           //displays a blank card when card is paired
void disp_code(int i);                                      //displays card upside down
void assign(card c[]);                                      //assign random values to card
void shuffle(card c[],int n);                               //shuffles the card
void blindthrowtitle();                                     //blind throw title page
int blindthrow();                                           //blind throw game
void addcard(pile **front,pile **rear,card c);              //adds a card to the queue i.e. the pile
card removecard(pile **front,pile **rear);                  //removes a card from the queue i.e. the pile
int size(pile **front,pile **rear);                         //returns the size of the pile of cards
void displayvalue(card c,int i);                            //displays cards on the current board
int titlepage();                                            //title page of the game CARTES DE CHANCE


//peekaboo title page
void peekabootitle()
{ system("cls");
printf("________________________________________________________________________________________________________________________");
printf("                                                                                                                        \n");
printf("                    ******                             PEEK-A-BOO                             ******                    \n");
printf("________________________________________________________________________________________________________________________");

printf("\n GAME RULES:\n\n\n");
printf(" You are playing against the computer. Each of you will get an alternate turn to pick up a random card which would be\n");
printf(" displayed upside down. Each card has a code number written on it. You can pick any code number and that card will   \n");
printf(" open up. If the value of the card you opened matches the value of any of the already open cards, You get 2 points. \n");
printf(" If your card matches up, You get another chance to pick a card. If you score more than the computer's score, You win !\n");
printf("\n\n\t\t\t\t\t        CHOOSE YOUR CARDS WISELY !! ");
printf("  \n\t\t\t\t\t                GOOD LUCK !!          \n\n");
printf("************************************************************************************************************************");

printf("\n Press any key to continue.....    ");
getch();
}

//returns the position of a key in array;
int position(int array[],int size,int key)
{  int t=0;
   for(t=0;t<size;t++)
     if(array[t]==key)
        return t;
}

//find position of a card in deck
int positioncard(card array[],int size,card key)
{  int t=0;
   for(t=0;t<size;t++)
     if(array[t].val==key.val && array[t].suit==key.suit)
        return t;
}

//find the position of a value in a deck
int positioncardval(card array[],int size,int key)
{  int t=0;
   for(t=0;t<size;t++)
     if(array[t].val==key)
        return t;
}

//find whether an element is present in an array or not
int find_in_array(int array[],int size,int key)
{  int t=0;
   for(t=0;t<size;t++)
   {
       if(array[t]==key)
        return 1;

   }
   return 0;

}

//find whether an element is present in an array of cards or not
int find_in_cardarray(card array[],int size,int key)
{  int t=0;
   for(t=0;t<size;t++)
   {
       if(array[t].val==key)
        return 1;

   }
   return 0;

}

//removes the element key from array
void remove_from_array(int array[],int key,int *cnt)
{ int r,flag,pos;
  for (r=0;r<(*cnt);r++)
    if (array[r] == key)
            {   flag=1;
                pos=r;
                break;
            }

    if (flag==1)
       for (r=pos;r<(*cnt)-1;r++)
          array[r]=array[r + 1];

    (*cnt)=(*cnt)-1;

}

//removes the card from array of cards
void remove_from_cardarray(card array[],card key,int *cnt)
{ int r,flag,pos;
  for (r=0;r<(*cnt);r++)
    if (array[r].val==key.val)
            {   flag=1;
                pos=r;
                break;
            }

    if (flag==1)
       for (r=pos;r<(*cnt)-1;r++)
          {array[r].val=array[r+1].val;
           array[r].suit=array[r+1].suit;
          }
    (*cnt)=(*cnt)-1;

}

//display the value of a card
void display_value(card c,int i)
{   int x=i%13 ;
    int y=i/13;
    gotoxy(x*9,4*y+3);
    printf("        ");
    gotoxy(x*9,4*y+4);
    printf("        ");
    gotoxy(x*9,4*y+5);
    printf("  %2d %c  ",c.val,c.suit);
    gotoxy(x*9,4*y+6);
    printf("        ");
}

//displays a blank card when card is paired
void display_blank(card c,int i)
{
    int x=i%13 ;
    int y=i/13;
    gotoxy(x*9,4*y+3);
    printf("        ");
    gotoxy(x*9,4*y+4);
    printf("        ");
    gotoxy(x*9,4*y+5);
    printf("        ");
    gotoxy(x*9,4*y+6);
    printf("        ");
    }

//displays cards on the current board
void displayvalue(card c,int i)
{   int x=i%13 ;
    int y=i/13;
    gotoxy(x*9,4*y+9);
    printf(" _______");
    gotoxy(x*9,4*y+10);
    printf("|       |");
    gotoxy(x*9,4*y+11);
    printf("| %2d %c  |",c.val,c.suit);
    gotoxy(x*9,4*y+12);
    printf("|_______|");
}

//displays card upside down
void disp_code(int i)
{   int x=i%13 ;
    int y=i/13;
    gotoxy(x*9,4*y+3);
    printf(" ______ ");
    gotoxy(x*9,4*y+4);
    printf("|      |");
    gotoxy(x*9,4*y+5);
    printf("| *%02d* |",i+1);
    gotoxy(x*9,4*y+6);
    printf("|______|");
}

//assign random values to card
void assign(card c[])
{  int a[13]={1,2,3,4,5,6,7,8,9,10,11,12,13};
       int i;
           for(i=0;i<52;i++)
            {   if(i<13)
                    c[i].suit='H';
                else if(i<26)
                    c[i].suit='D';
                else if(i<39)
                    c[i].suit='S';
                else if(i<52)
                    c[i].suit='C';
                c[i].val=a[i%13];
            }
  }

//shuffles the card
void shuffle(card c[],int n)
{  int i=0,r,t;
   char p;
   srand(time(NULL));
    for(;i<52;i++)
    {  r=rand()%52;
       t=c[i].val;
       c[i].val=c[r].val;
       c[r].val=t;

       p=c[i].suit;
       c[i].suit=c[r].suit;
       c[r].suit=p;
    }
}

//blind throw title page
void blindthrowtitle()
{
system("cls");
printf("________________________________________________________________________________________________________________________");
printf("                                                                                                                        \n");
printf("                    ******                             BLIND THROW                            ******                    \n");
printf("________________________________________________________________________________________________________________________");

printf("\n GAME RULES:\n\n\n");
printf(" You are playing against the computer. Each of you will get an alternate turn to throw the card that is on the top of \n");
printf(" your pile. Initially each of you will have 26 cards. Your Aim is to collect all the cards at the end and win the game.\n");
printf(" If the card you throw matches with the card below it, You get all the cards in the current pile. \n");
printf("\n\n\t\t\t\t\t         THROW YOUR CARDS WISELY !! ");
printf("  \n\t\t\t\t\t                GOOD LUCK !!          \n\n");
printf("************************************************************************************************************************");

printf("\n Press any key to continue.....    ");

getch();
}

//adds a card to the queue i.e. the pile
void addcard(pile **front,pile **rear,card c)
{
    pile *newcard;
    newcard=(pile*)malloc(sizeof(pile));
    if(newcard==NULL)
    {
        printf("memory allocation failed..");
        return;
    }
    newcard->val=c.val;
    newcard->suit=c.suit;
    newcard->next==NULL;

    if(*front==NULL)
    {
        *front=*rear=newcard;
    }
    else
    {
        (*rear)->next=newcard;
        *rear=newcard;
    }
}

//removes a card from the queue i.e. the pile
card removecard(pile **front,pile **rear)
{   card deleted;
    deleted.suit='0';
    deleted.val=0;
    pile *temp;
    temp=*front;
    if(*front==NULL)
        return deleted;

    deleted.suit=(*front)->suit;
    deleted.val=(*front)->val;

    if(*front==*rear)
    {
        *front=NULL;
        *rear=NULL;
        free(temp);
        return deleted;
    }
    *front=temp->next;

    free(temp);
    return deleted;
}

//returns the size of the pile of cards
int size(pile **front,pile **rear)
{ int cnt=1;
  pile *temp;
  temp=*front;
  if(temp==NULL)
    return 0;

  while(temp!=(*rear))
  {
      cnt ++;
      temp=temp->next;
  }
  return cnt;

}

//peekaboo game
int peekaboo()
{  int choice;
   peekabootitle();
   int cardsavailable[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52};
   card cardsvalue[13];
   int cards_matched[52];
   int cards_open[52];           //array storing the values of open cards
   card deck[52];                //variable holding the card values
   int cntopen=0;                //counter for cards open
   int cntavailable=52;          //counter for available cards
   int cntmatch=0;               //counter for matched cards
   int cntval=0;                 //counter for value of cards;
   assign(deck);
   shuffle(deck,52);
   int computerscore=0,playerscore=0;   //to keep track of scores
   int usercard;
   int turn=0;                          //to keep track of player's chance
   int i,m;                             //to access the members of deck
   int err=0;                           //to check error
   do
   {  system("cls");

          gotoxy(0,0);
          printf("COMPUTER SCORE: %d",computerscore);
          gotoxy(101,0);
          printf("PLAYERSCORE: %d",playerscore);

            gotoxy(53,1);
            if(turn%2==0)
            printf("YOUR TURN !!");
            else
            printf("COMPUTER\'S TURN !!");

            for(i=1;i<=52;i++)
            {  if(find_in_array(cards_matched,cntmatch,i-1))
                  display_blank(deck[i-1],i-1);
                else if(find_in_array(cards_open,cntopen,i))
                  display_value(deck[i-1],i-1);
                else
                  disp_code(i-1);
            }

          gotoxy(1,21);
          if(turn%2==0)
          {
             printf("\n\n ENTER THE CARD NUMBER YOU WANT TO OPEN :    ");
             scanf("%d",&usercard);
          }
          else
          {   srand(time(NULL));
              usercard=cardsavailable[(rand()%cntavailable)] ;
              printf("\n\n COMPUTER CHOSE CARD NUMBER %d",usercard);
              getch();
          }

              if(find_in_array(cards_open,cntopen,usercard))
                err=1;
              if(usercard>52 || usercard<1)
                err=2;

            if(err==0)
            {   cards_open[cntopen]=usercard;
                cntopen++;

                if(find_in_cardarray(cardsvalue,cntval,deck[usercard-1].val))
                {
                  if(turn%2==0)
                   {  playerscore+=2;
                      printf("MATCH FOUND !! POINTS INCREASED !! ANOTHER TURN !!");
                   }
                  else
                   { computerscore+=2;
                     printf("\nCOMPUTER OPENED A MATCH !! ANOTHER TURN FOR COMPUTER !!");
                   }

                  cards_matched[cntmatch]=usercard-1;
                  cntmatch++;
                  m=positioncardval(cardsvalue,cntval,deck[usercard-1].val);

                  cards_matched[cntmatch]=positioncard(deck,52,cardsvalue[m]);

                  cntmatch++;


                  remove_from_cardarray(cardsvalue,deck[usercard-1],&cntval);
                  getch();

                }
                else
                {  turn++;
                   cardsvalue[cntval].val=deck[usercard-1].val;
                   cardsvalue[cntval].suit=deck[usercard-1].suit;
                   cntval++;

                }
            }
           else if(err==1)
            {   gotoxy(30,2);
                printf("!! ERROR MESSAGE:  CARD ALRADY OPEN...  CHOOSE ANOTHER !!");
                Beep(1000,500);
            }
           else if(err==2)
            {   gotoxy(30,2);
                printf("!! ERROR MESSAGE:  CARD OUT OF LIMIT... CHOOSE ANOTHER!!");
                Beep(1000,500);
            }

           err=0;


        remove_from_array(cardsavailable,cards_open[cntopen-1],&cntavailable);



   }while(playerscore+computerscore != 52);

   if(playerscore>computerscore)
   {    system("cls");
        gotoxy(49,5);
        printf("FINAL SCORES");
        gotoxy(48,7);
        printf("COMPUTER   : %d",computerscore);
        gotoxy(48,8);
        printf("YOUR SCORE : %d",playerscore);
        gotoxy(45,10);
        printf("YOU WIN!!! CONGRATS !!");
   }
   else if(playerscore<computerscore)
   {    system("cls");
        gotoxy(52,5);
        printf("FINAL SCORES");
        gotoxy(51,7);
        printf("COMPUTER   : %d",computerscore);
        gotoxy(51,8);
        printf("YOUR SCORE : %d",playerscore);
        gotoxy(41,10);
        printf("YOU LOSE!!! BETTER LUCK NEXT TIME!!");
   }
   else
   {
        system("cls");
        gotoxy(51,5);
        printf("FINAL SCORES");
        gotoxy(50,7);
        printf("COMPUTER   : %d",computerscore);
        gotoxy(50,8);
        printf("YOUR SCORE : %d",playerscore);
        gotoxy(51,10);
        printf("GAME TIE !!");
   }
        char playername[20];
        FILE *fp;
        char name[5][100];
        name[0][0]='1';
        int score[5],j,b;
        i=0;
        fp=fopen("peekabooscores.txt","r");
        while(!feof(fp))
        {   for(j=0;name[i][j-1]!=32;j++)
        fscanf(fp,"%c",&name[i][j]);

        name[i][j]=0;
        fscanf(fp,"%d",&score[i]);
        i++;

        }
        int t;char temp[100];
        for(i=0;i<5-1;i++)
        { for(j=0;j<5-1-i;j++)
          {
            if(score[j]<score[j+1])
            { t=score[j];
              score[j]=score[j+1];
              score[j+1]=t;

            strcpy(temp,name[j]);
            strcpy(name[j],name[j+1]);
            strcpy(name[j+1],temp);

            }
          }
        }

        fclose(fp);

        for(j=0;j<4;j++)
        {
            if(playerscore>=score[j] && playerscore>=computerscore)
             {   gotoxy(36,10);
                printf("CONGRATULATIONS !! YOU MADE A HIGH SCORE !!");
                gotoxy(44,11);
                printf("ENTER YOUR NAME :  ");
                score[4]=playerscore;
                scanf("%s",playername);
                strcat(playername," ");
                strcpy(name[4],playername);



                for(i=0;i<5-1;i++)
                { for(j=0;j<5-1-i;j++)
                    {
                    if(score[j]<score[j+1])
                    { t=score[j];
                      score[j]=score[j+1];
                      score[j+1]=t;

                      strcpy(temp,name[j]);
                      strcpy(name[j],name[j+1]);
                      strcpy(name[j+1],temp);
                    }
                    }
                }

                fp=fopen("peekabooscores.txt","w");
                for(i=0;i<5;i++)
                fprintf(fp,"%s%d",name[i],score[i]);
                fclose(fp);
                break;
            }
        }

        fp=fopen("peekabooscores.txt","r");
        char names[5][100];
        names[0][0]='1';
        int scored[5];
        i=0;
        while(!feof(fp))
        {   for(j=0;names[i][j-1]!=32;j++)
                fscanf(fp,"%c",&names[i][j]);

            names[i][j]=0;
            fscanf(fp,"%d",&scored[i]);
            i++;
        }


        fclose(fp);
        gotoxy(50,14);
        printf("TOP SCORES");
        for(i=0;i<5;i++)
        {  gotoxy(47,15+i);
           printf("%-12s : %d",names[i],scored[i]);
        }

        gotoxy(92,28);
        printf("Enter \'1\' to play again");
        gotoxy(92,29);
        printf("Enter \'0\' to go back   ");
        scanf("%d",&choice);


return choice;

}

//blind throw game
int blindthrow()
{
  blindthrowtitle();
  pile *playerfront=NULL,*playerend=NULL,*computerfront=NULL,*computerend=NULL;
  card deck[52];                //variable holding the card values
  assign(deck);
  shuffle(deck,52);
  card market[52],tempcard;
  int marketsize=0,turn =0,choice;
  int i;
  for(i=0;i<26;i++)
  { addcard(&playerfront,&playerend,deck[i]);
    addcard(&computerfront,&computerend,deck[51-i]);
  }

  do
  {
      system("cls");
      printf("________________________________________________________________________________________________________________________\n");
      gotoxy(48,2);
      printf("****    BLIND THROW    ****\n");
      printf("________________________________________________________________________________________________________________________");
      printf("\n\nCOMPUTER CARDS LEFT IN PILE : %d",size(&computerfront,&computerend));
      gotoxy(85,5);
      printf("YOUR CARDS LEFT IN PILE : %d",size(&playerfront,&playerend));

      gotoxy(55,7);
      printf("CURRENT BOARD\n\n");

      for(i=0;i<marketsize;i++)
        displayvalue(market[i],i);

      gotoxy(3,28);
      if(turn %2==0)
      { printf("YOUR TURN.. ENTER ANY KEY TO THROW YOUR CARD ");
        getch();
          tempcard=removecard(&playerfront,&playerend);
          market[marketsize].val= tempcard.val;
          market[marketsize].suit= tempcard.suit;
          marketsize++;
          turn ++;
      }
      else if(turn %2 !=0)
      {
          printf("COMPUTER'S TURN.. COMPUTER IS PLAYING ITS TURN NOW ");
          tempcard=removecard(&computerfront,&computerend);
          market[marketsize].val= tempcard.val;
          market[marketsize].suit= tempcard.suit;
          marketsize++;
          Beep(20000000,300);
          turn ++;
      }

      if(marketsize>1 && market[marketsize-1].val==market[marketsize-2].val)
      {
          if(turn %2==0)
           { gotoxy(20,26);
             printf("    **  COMPUTER THREW A MATCH... ALL CARDS IN THE PILE ARE COLLECTED BY COMPUTER  **");
             displayvalue(market[marketsize-1],marketsize-1);
           getch();
             for(i=0;i<marketsize;i++)
             {
               addcard(&computerfront,&computerend,market[i]);
             }

             marketsize=0;
             turn--;

           }
          else if(turn %2!=0)
           { gotoxy(20,26);
             printf("    **  YOU THREW A MATCH... ALL CARDS IN THE PILE ARE NOW YOURS  **");
             displayvalue(market[marketsize-1],marketsize-1);
             getch();
             for(i=0;i<marketsize;i++)
             {
               addcard(&playerfront,&playerend,market[i]);
             }

             marketsize=0;
             turn--;

           }

      }

  }while(size(&computerfront,&computerend)>0 && size(&playerfront,&playerend)>0);

  system("cls");
  gotoxy(53,13);
  if(size(&computerfront,&computerend)-size(&playerfront,&playerend)==1 || size(&computerfront,&computerend)-size(&playerfront,&playerend)==-1 )
     printf("!!  GAME TIE  !!");
  else if(size(&computerfront,&computerend)==0)
    printf("!!  YOU WIN  !!");
  else
    { gotoxy(48,13);
      printf("!! YOU RAN OUT OF CARDS  !! ");
      gotoxy(48,14);
      printf("!! BETTER LUCK NEXT TIME !!");
    }

        gotoxy(92,28);
        printf("Enter \'1\' to play again");
        gotoxy(92,29);
        printf("Enter \'0\' to go back");
        scanf("%d",&choice);

        return choice;
}

//title page of the game CARTES DE CHANCE
int titlepage()
{ system("cls");
printf("    ________________________________________________________________________________________________________________\n");
printf("   |                                                                                                                |\n");
printf("   |     ****   **   ****   *****  ****  ****        ***   ****        ****  *  *   **   *   *  ****  ****  ****    |\n");
printf("   |     *     *  *  *   *    *    *     *           *  *  *           *     *  *  *  *  **  *  *     *     *       |\n");
printf("   |     *     ****  ****     *    ***   ****        *  *  ***         *     ****  ****  * * *  *     ***   ****    |\n");
printf("   |     *     *  *  *  *     *    *        *        *  *  *           *     *  *  *  *  *  **  *     *        *    |\n");
printf("   |     ****  *  *  *   *    *    ****  ****        ***   ****        ****  *  *  *  *  *   *  ****  ****  ****    |\n");
printf("   |________________________________________________________________________________________________________________|\n");

printf("________________________________________________________________________________________________________________________");

printf("\n\t\t\t\t\t    WELCOME TO THE GAME OF LUCK!!!");
printf("\n\nTHE GAME IS PURELY BASED ON LUCK. IT IS AN EFFORT TO BRING BACK THE MEMORIES OF CHILDHOOD WHEN SIMPLE CARD GAMES RULED");
printf("\nOUR HEARTS. THE GAME FEATURES TWO GAME MODES BOTH OF WHICH ARE SIMPLE TO UNDERSTAND AND PLAY. IT IS AN INTERACTIVE GAME");
printf("\nWHERE YOU PLAY WITH THE COMPUTER. THE GAME IS SUITABLE FOR CHILDREN OF ALL AGES AND ADULTS AS WELL. ");
printf("\n\nTHE GAME STORES HIGH SCORES AS WELL SO COMPETE WITH YOURSELF AND TRY TO BEAT YOUR OWN HIGHSCORE.");
printf("\n\n\t\t\t\t\t\t!! ENJOY THE GAME !!");

printf("\n\n");
printf("________________________________________________________________________________________________________________________\n");

printf("\tGame Modes:\n");
printf("\t\t\t\t 1. PEEK-A-BOO \t\t\t\t\t 2. BLIND THROW\n");
printf("________________________________________________________________________________________________________________________");
printf("\n > Enter Your Choice :\t");
int mode_choice;
gotoxy(77,29);
printf("Enter \'0\' if you want to quit the game");
gotoxy(24,23);
scanf("%d",&mode_choice);
return mode_choice;
}


int main()
{int m;
 int modechoice;
 while(1)
 { modechoice= titlepage();
   if(modechoice==0)
      {   system("cls");
          gotoxy(45,10);
          printf("THANK YOU !!! HAVE A NICE DAY !!!");
          gotoxy(20,20);
          break;
      }
   else if(modechoice==1)
      {  A:
         m=peekaboo();
         if(m==0)
            continue;
         else if(m==1)
             goto A;
      }
    else if(modechoice==2)
    {     B:
         m=blindthrow();
         if(m==0)
            continue;
         else if(m==1)
             goto B;

    }
    else
    {
       printf("PLEASE ENTER A VALID CHOICE");
       Beep(1000,400);
    }
}
return 0;
}
