#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

void CreateMatrix(int arr[][4])
{
int n=15;
int num[n];
for(int i=0;i<15;i++)
{
 num[i]=i+1;// 1 to 15 will be in the matrix
}

srand(time(NULL));//for random number generation
int lastIndex= n-1,index;
int i,j;
for( i=0;i<4;i++)
{
   for( j=0;j<4;j++)
    {
     if(lastIndex>=0)
        {
        index=rand()%(lastIndex+1);    // idea : performing % operation by (lastIndex+1)
        arr[i][j]= num[index];          // will give index , so put that num[index] number in matrix
        num[index]=num[lastIndex--];   // and replace last number with this indexed positioned number
                                        //// and finally lastIndex--
        }
    }
}
 arr[i-1][j-1]=0;//last number is zero;

}
void showMatrix(int arr[][4])
{
int i,j;
printf("--------------------\n");
for(i=0;i<4;i++)
{
    printf("|");

for(int j=0;j<4;j++)
    {
     if(arr[i][j]!=0)
         printf("%2d | ",arr[i][j]);
     else
         printf("   |");

    }
    printf("\n");
}
 printf("--------------------");
 printf("\n");
}
int winner(int arr[][4])
{
int i,j,k=1;
for(i=0;i<4;i++)
{
    for(j=0;j<4;j++)
     {
        if(arr[i][j]!=k && k!=16)
             break;
     }
    if(j<4){break;}

}
    if(j<4)
        return 0;
    return 1;

}
void swap(int *x ,int *y)
{
*x=*x + *y;
*y=*x - *y;
*x=*x - *y;
printf(" ");
}


int ReadEnteredKey()
{
    char c;
    c = _getch();
    if (c == -32)
        c = _getch();

    return c;
}

void GameRule()
{
 system("cls");

 printf("                      MATRIX PUZZLE                  \n") ;
 printf("\n                    RULE OF THIS GAME                ");
 printf("\n");
 printf("\n");
 printf("1. You can move only one step at a time by arrow key\n");
 printf("       Move Up    :  By Up arrow key\n");
 printf("       Move Down  :  By Down arrow key\n");
 printf("       Move Left  :  By Left arrow key\n");
 printf("       Move Right :  By Right arrow key\n");
 printf("\n");
 printf("2. You can move number at empty position only\n");
 printf("3. for each valid move : your total number of moves decreased by 1\n");
 printf("4. winning situation   : Number in a 4*4 matrix should be in order from 1 to 15\n");
 printf("\n");
 printf("\n");
 printf("                       WINNING SITUATION :              \n");
 printf("-----------------\n");
 printf("| 1 | 2 | 3 | 4 |\n");
 printf("| 5 | 6 | 7 | 8 |\n");
 printf("| 9 | 10| 11| 12|\n");
 printf("| 13| 14| 15|   |\n");
 printf("-----------------\n");
 printf("5.you can exit the game at any time by pressing 'E' or 'e' \n");
 printf("So Try to win in minimum number of moves\n");
 printf("\n Enter any key to start\n");

 int x = ReadEnteredKey();
//system("cls");
// system("pause");//to print enter any key to continue ...
 //system("cls");
 //printf("Player name    : %s \n",name);
// printf("Move Remaining : %d \n",maxmove);

}
int shiftUp(int arr[][4])
{
int i,j;
for(int i=0;i<4;i++)
{
  for(j=0;j<4;j++)
    {
     if(arr[i][j]== 0)
        break;
    }
  if(j<4)
    break;
}
if(i==3)
  return 0;

swap(&arr[i][j],&arr[i+1][j]);
return 1;

}
int shiftDown(int arr[][4])
{
int i,j;
for(int i=0;i<4;i++)
{
  for(j=0;j<4;j++)
    {
     if(arr[i][j]== 0)
        break;
    }
  if(j<4)
    break;
}
if(i==3)
  return 0;

swap(&arr[i][j],&arr[i-1][j]);
return 1;
}
int shiftRight(int arr[][4])
{
int i,j;
for(int i=0;i<4;i++)
{
  for(j=0;j<4;j++)
    {
     if(arr[i][j]== 0)
        break;
    }
  if(j<4)
    break;
}
if(i==3)
  return 0;

swap(&arr[i][j],&arr[i][j-1]);
return 1;
}

int shiftLeft(int arr[][4])
{
int i,j;
for(int i=0;i<4;i++)
{
  for(j=0;j<4;j++)
    {
     if(arr[i][j]== 0)
        break;
    }
  if(j<4)
    break;
}
if(i==3)
  return 0;

swap(&arr[i][j],&arr[i][j+1]);
return 1;
}

int main()
{
 int arr[4][4];//matrix
 int maxmove = 300;//maximum move
 char name[20];// input the player name
 printf("Player Name : ");
 fgets(name,20,stdin);

 system("cls");//system("cls") is used to clear the screen;

 while(1)
{
   CreateMatrix(arr);// calling function to create matrix.
   GameRule(arr);//game rule function calling
 //system("cls");
// printf("Player name    : %s \n",name);
// printf("Move Remaining : %d \n",maxmove);
   while(!winner(arr))//winner situation
    {
     system("cls");
     if(!maxmove)//gor remaining zero move
         break;
     printf("\n\n player Name : %s, move remaining : %d \n\n",name,maxmove);

    showMatrix(arr);

    int key= ReadEnteredKey();//this will return ascii code of user enter value

    switch(key)//mapping
    {
    case 101 ://ascii of E

    case 69: //ascii of e
           printf("\a\a\a\a\n  Thanks for playing!! \n\a");
           printf("\n Hit ENTER to exit the game \n");
           key = ReadEnteredKey();
           return 0;
    case 72://arrow up
        if(shiftUp(arr))
            maxmove--;
        break;

    case 80://arrow down
         if(shiftDown(arr))
            maxmove--;
        break;

    case 77:
        if(shiftRight(arr))
           maxmove--;
        break;

    case 75:
        if(shiftLeft(arr))
           maxmove--;
        break;
    default:
        printf("\n\n\n Not allowed \a\a\n");
    }
  }
if(!maxmove)
    {
     printf("\a\a\a\n you lose!!!!!!\n\n");
    }
else
    {
    printf("\a\a\a\n congratulation!!!!! %s for win this game \a\a\a\n");
    }
fflush(stdin);//will clear the buffer
char check;
printf("\a\a\a\n want to play again ? \a\a\a");
printf("enter 'y' to play again: ");
scanf("%c",&check);
if((check!='y')&&(check!='Y'))
    break;

maxmove = 300;
}
return 0;
}
