#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define H 12
#define W 19

struct point{int x;int y;int ys;int xs;};
void SLEEP(int);
void displayMap(char map[H][W]);
void ClearStep(struct point*,char t[H][W],int,int);
void MouseLogic(struct point*,char t[H][W]);
void TrapAvoid(char t[H][W],int,int,int*,int*);


int main(void){
struct point dot;
dot.x =2;dot.y = 1;dot.xs = 1;dot.ys=0;
char t[H][W] = 
{

"*******************",
"*                 *",
"****     **********",
"*        *    *   *",
"*****    *        *",
"*        ***      *",
"*                 *",
"******     *      *",
"*          *      *",
"*     ******      E",
"*          *      *",
"*******************"};

srand(time(0));

while(t[9][18] == 'E'){

t[dot.y][dot.x] = '.';
displayMap(t);

dot.x+=dot.xs;
dot.y+=dot.ys;
ClearStep(&dot,t,1,1);

MouseLogic(&dot,t);

SLEEP(5500);
system("clear");

	
	
}

printf("\nthe End\n");
SLEEP(20000);
	
	
	return 0;
}



void displayMap(char map[H][W]){
	int i,j;
	for(i =0;i<H;i++){
    	for(j =0;j<W;j++)
	      printf("%c",map[i][j]);
    printf("\n");
}
	
	
}


void SLEEP(int time){
int c, d;
   
   for (c = 1; c <= time; c++)
       for (d = 1; d <= time; d++)
       {}

       
	
}

void ClearStep(struct point *Point,char t[H][W],int stepY,int stepX){

 if((*(Point)).ys > 0){

  t[(*(Point)).y-stepY][(*(Point)).x] = ' ';
 }

  if((*(Point)).ys < 0){

  t[(*(Point)).y+stepY][(*(Point)).x] = ' ';
 }
 
 
 
 
 if((*(Point)).xs > 0){

  t[(*(Point)).y][(*(Point)).x-stepX] = ' ';
 }

  if((*(Point)).xs < 0){

  t[(*(Point)).y][(*(Point)).x+stepX] = ' ';
 }
 
 
 
 
}


void MouseLogic(struct point *Point,char t[H][W]){
	int x,y,*xs,*ys;
	int c[2] = {1,-1};
	x = (*(Point)).x;
	y = (*(Point)).y;
	xs = &(*(Point)).xs;
	ys = &(*(Point)).ys;
	


if(t[y][x+1] != 'E')
{ 
   
  	

TrapAvoid(t,y,x,xs,ys);
  	    

  	
	
   if(*xs != 0){
   	
  
 
	 if(t[y][x+1]=='*'){
	 	*xs = -1;
	 	
	 }	
	 
	 if(t[y][x-1]=='*'){
	 	*xs = 1;
	 	
	 }	
		
	 	
	 
	 if(t[y+1][x] != '*'){
	   *ys = 1;
	   *xs = 0;
	 	
     	}
   	 if(t[y-1][x] != '*'){
	   *ys = -1;
	   *xs =0;
	 	
	}

		
		
	 if(t[y+1][x] != '*' && t[y-1][x] != '*'){
	  	  
	      *ys = c[rand()%2]; 
		  *xs =0;	  
	  	
	  }
	  		
		
		
  }else{
  	
  	 
     
       
  	
  	if(t[y+1][x]=='*'){
	 	*ys = -1;
	 	
	 }	
	 
	 if(t[y-1][x]=='*'){
	 	*ys = 1;
	 	
	 }	
  	
	
	if(t[y][x+1] != '*'){
	   *ys = 0;
	   *xs = 1;
	 	
	}
	if(t[y][x-1] != '*'){
	   *ys = 0;
	   *xs =-1;
	 	
	}
		
		
	  if(t[y][x+1] != '*' && t[y][x-1] != '*'){
	  	  
	      *xs = c[rand()%2]; 
		  *ys =0;	  
	  	
	  }
}

}
else{
	
  *ys = 0;
  *xs = 1;
}
	

	
}



void TrapAvoid(char t[H][W],int y,int x,int*xs,int*ys){



if((t[y-1][x+1] == '*' && t[y][x+1] != '*' && t[y-1][x] == ' '))
          *xs = 2;
     
else if ((t[y+1][x+1] == '*' && t[y][x+1] != '*' && t[y-1][x] == ' '))
      
	       *xs = -2;
	       
	       

}
	

