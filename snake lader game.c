#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>


void draw();//FUNCTION CREATED FOR PRINTING THE BOUNDARY
void setup();//FUNCTION CREATED FOR CREATING FRUIT AND SNAKE POSITIONS
void direction();//FUNCTION CREATED FOR GIVING DIRECTION CONTROL IN GAME
void MAIN_LOGIC();//HERE THE SOUL OF THE CODE EXIST

int width=20,height=30,gameover;
int pos_x,pos_y,fruit_x,fruit_y,score,flag;
int tail_x[100];
int tail_y[100];
int counttail=0;

void setup()
{
    gameover=0;
    pos_x=width/2;
    pos_y=height/2;
    label1:
    fruit_x=rand()%20;//RANDOM FUNCRION IS USED SO TO PICK RANDOM VALUE AND THEN % BY 20 SO THAT THE VALUE IS LESS THAN 20 AND IS INSIDE THE BOUNDARY RANDOM FUNCION IS IN STDLIB LIBRARY
    if(fruit_x==0)
    {
        goto label1;//THIS IS CREATED SO THAT THEY DO NOT LIE ON THE BOUNDARIES
    }
    label2:
    fruit_y=rand()%20;
    if(fruit_y==0)
    {
        goto label2;//THIS IS CREATED SO THAT THEY DO NOT LIE ON THE BOUNDARIES
    }
    score=0;
}

void draw()
{
    system("cls");
    int i,j,k;
    for(i=0;i<width;i++)
    {
        for(j=0;j<height;j++)
        {
            if(i==0 || i==width-1 || j==0 || j==height-1)
            {
                printf("*");
            }
            else
            {
                //THIS IS CREATED SO THAT THE POSITION OF SNAKE AND FRUIT CAN BE LOCATED IN THE BOUNDARY AND THEY ALSO DO NOT LIE AT THE BOUNDARY
                if(i==pos_x && j==pos_y)
                {
                    printf("O");
                }
                else if(i==fruit_x &&j==fruit_y)
                {
                    printf("F");
                }

                else
                {
                    int ch=0;
                    for(k=0;k<counttail;k++)//TO INCREASE THE SIZE OF THE SANKE
                    {
                        if(i==tail_x[k] && j==tail_y[k])
                        {
                            printf("o");
                            ch=1;
                        }
                    }
                    if(ch==0)
                    printf(" ");
                }

            }
        }
        printf("\n");
    }
}

void direction()
{
    if (kbhit())
    {
        switch(getch())
        {
          case'w':
               flag=1;
               break;
          case's':
               flag=2;
               break;
          case'a':
               flag=3;
               break;
          case'd':
               flag=4;
               break;
          case'x':
               gameover=1;
               break;
        }
    }
}

void MAIN_LOGIC()
{
    int i;
    int prev_x=tail_x[0];
    int prev_y=tail_y[0];
    int prev_2x;
    int prev_2y;
    tail_x[0]=pos_x;
    tail_y[0]=pos_y;
    for(i=1;i<counttail;i++)//HERE BASICALLY INSERTING IN BEGINNING IN AN ARRAY PROCESS IS TAKING PLACE
    {
        prev_2x=tail_x[i];
        prev_2y=tail_y[i];
        tail_x[i]=prev_x;
        tail_y[i]=prev_y;
        prev_x=prev_2x;
        prev_y=prev_2y;
    }
   switch(flag)
   {
    case 1:
        pos_x--;
        break;
    case 2:
        pos_x++;
        break;
    case 3:
        pos_y--;
        break;
    case 4:
        pos_y++;
        break;
    default:
        break;
    }
    //HERE IF IS USED IN ODER TO FINISH GAME IF SBAKE TOUCHES THE BOUNDARY
    if (pos_x<0||pos_x>width||pos_y<0||pos_y>height)
        gameover=1;
        for(i=0;i<counttail;i++)
        {
            if(tail_x[i]==pos_x && pos_y==tail_y[i])//HERE IF IS USED TO FININSH GAME IF SNAKE TOUCHES ITSELF
                gameover=1;
        }
        if(pos_x==fruit_x&&pos_y==fruit_y)
        {
            label3:
            fruit_x=rand()%20;//RANDOM FUNCRION IS USED SO TO PICK RANDOM VALUE AND THEN % BY 20 SO THAT THE VALUE IS LESS THAN 20 AND IS INSIDE THE BOUNDARY RANDOM FUNCION IS IN STDLIB LIBRARY
            if(fruit_x==0)
            {
               goto label3;//THIS IS CREATED SO THAT THEY DO NOT LIE ON THE BOUNDARIES
            }
            label4:
            fruit_y=rand()%20;
            if(fruit_y==0)
            {
              goto label4;//THIS IS CREATED SO THAT THEY DO NOT LIE ON THE BOUNDARIES
            }
             score=score+5;
             counttail++;
         }

}

int main(void)
{
    int m,n;
    char choice;
    label5:
    system("COLOR 24");
    setup();
    while(1)
    {
      draw();
      direction();
      MAIN_LOGIC();
      for(m=0;m<1000;m++)
      {
          for(n=0;n<10000;n++)
          {

          }
      }
      for(m=0;m<1000;m++)
      {
          for(n=0;n<1000;n++)
          {

          }
      }

      if(gameover==1)
      {
          system("COLOR 40");
          Beep(100,500);//CREATE SOUND, RETURN TYPE BOOL IF SUCESS RETRUN NON ZERO VALUE FAIL RETURN ZERO
          Beep(500,500);
          Beep(800,200);
          Beep(1000,300);
          printf ("\n$GAMEOVER$\n");
          printf ("\nYOURS SCORE=%d\n",score);
          break;
      }
    }
     system("COLOR 24");
     printf("PRESS Y TO CONTINUE AGAIN");//TO REPEAT THE GAME
     scanf(" %c",&choice);
     if(choice=='y'||choice=='Y')
     {
        goto label5;
     }

    return 0;
}
