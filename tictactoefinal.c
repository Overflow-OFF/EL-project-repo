#include<stdio.h>
#include<conio.h>
void check(char,char);
char a[9]={'1','2','3','4','5','6','7','8','9'};
void game_name()
{
	printf("\t\t\tTIC-TAC-TOE GAME");
}
void show()
{
	printf("\n\n\t\t\t---|---|---\n");
	printf("\t\t\t %c | %c | %c \n",a[0],a[1],a[2]);
	printf("\t\t\t---|---|---\n");
	printf("\t\t\t %c | %c | %c \n",a[3],a[4],a[5]);
	printf("\t\t\t---|---|---\n");
	printf("\t\t\t %c | %c | %c \n",a[6],a[7],a[8]);
	printf("\t\t\t---|---|---\n");

}
void symbol()
{
	printf("\nPlayer 1 symbol : X\n");
	printf("Player 2 symbol : O\n");
}
void start()
{
	char n;
	printf("\nEnter who will star the game : player 1 or player 2?\n");
	scanf("%c",&n);
}
int count=0;
void play()
{
	char p,s;
	char cho;
	printf("\nEnter position and symbol for the player:");
	fflush(stdin);
	scanf("%c",&p);
	fflush(stdin);
	scanf("%c",&s);
	count++;
	check(p,s);
}
void check(char P,char S)
{
	int i;
	for(i=0;i<=8;i++)
	{
		if(a[i]==P)
		{
		a[i]=S;
		break;
		}
	}
}
void message()
{
	printf("\nEnter the position for player:\n");
}
int end()
{
	if((a[0]=='x'&& a[1]=='x'&& a[2]=='x')||(a[0]=='x'&& a[3]=='x'&& a[6]=='x')||(a[0]=='x'&& a[4]=='x'&& a[8]=='x'))
	return(100);
	else if((a[0]=='O'&& a[1]=='O'&& a[2]=='O')||(a[0]=='O'&& a[3]=='O'&& a[6]=='O')||(a[0]=='O'&& a[4]=='O'&& a[8]=='O'))
	return(200);
	else if(a[1]=='x'&& a[4]=='x'&& a[7]=='x')
	return(100);
	else if(a[1]=='O'&& a[4]=='O'&& a[7]=='O')
	return(200);
	else if(a[2]=='x'&& a[5]=='x'&& a[8]=='x')
	return(100);
    else if(a[2]=='O'&& a[5]=='O'&& a[8]=='O')
	return(200);
	else if(a[3]=='x'&& a[4]=='x'&& a[5]=='x')
	return(100);
	else if(a[3]=='O'&& a[4]=='O'&& a[5]=='O')
	return(200);
	else if(a[2]=='x'&& a[4]=='x'&& a[6]=='x')
	return(100);
	else if(a[2]=='O'&& a[4]=='O'&& a[6]=='O')
	return(200);
	else if(a[6]=='x'&& a[7]=='x'&& a[8]=='x')
	return(100);
	else if(a[6]=='O'&& a[7]=='O'&& a[8]=='O')
	return(200);
    return(300);
}
int main()
{   int k;
    char ch;
    labell:
	game_name();
	show();
	symbol();
	start();
	play();
	label:
	show();
	message();
	play();
	k=end();
 	show();
 	if(count<9)
 	{

	if(k==100)
	{
	printf("\nPlayer 1 Won!!!");
	count=0;
    }
	else if(k==200)
    {
	printf("\nPlayer 2 Won!!!");
    count=0;
    }
	else
	  goto label;
   }
    else
    {
    	printf("Game Draw!!\n");
    	count=0;
    }
	  printf("\nDo you want to continue the game?\nEnter y for Yes and n for No");
	  fflush(stdin);
	  scanf("%c",&ch);
	  if(ch=='y'||ch=='Y')
	  {
	  	a[0]='1';
	  	a[1]='2';
	  	a[2]='3';
	  	a[3]='4';
	  	a[4]='5';
	  	a[5]='6';
	  	a[6]='7';
	  	a[7]='8';
	  	a[8]='9';
	  	goto labell;
	  }
	  printf("\n\n\t\tPress any key to exit!!:");
	getch();
}
