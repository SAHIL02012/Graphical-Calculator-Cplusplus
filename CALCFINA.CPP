#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
void showptr();
void getmousepos(int *,int*,int*);
int button,x,y,x1,y1,x2,y2,s;
long double num=0,get,num1=0,result=0,num2=0;
long double addnum(int);
char opr;
int a,b,r,i1,count,c,sq,newnum=1,d=0;
union REGS i,o;
void main()
{
  int driver=DETECT,mode;
  int q,p[12];
  char input;
   char *inpu[5][5]={"1","2","3","4",
	  "5","6","7","8",
	  "9","0","+","-" ,
	  "*","/","clr","=","sin","cos","log","!","^","pi","sq","sqrt","e"};
  char inp[5][5]={'1','2','3','4',
	  '5','6','7','8',
	  '9','0','+','-' ,
	  '*','/','l','=','i','c','o','!','r','p','q','s','e'};
  initgraph(&driver,&mode,"C:\\TC\\BGI");
  cleardevice();
  setfillstyle(1,GREEN);
  bar(236,82,490,350);             //calc body
  setcolor(GREEN);
  rectangle(238,50,488,80);        //calc display line
  rectangle(237,49,489,81);
  rectangle(236,48,490,82);
  c=240;
  d=100;
  s=0;
   for(a=0;a<5;a++)                           ///calc buttons
  {
    c=240;
    for(b=0;b<5;b++)
    {
      setfillstyle(1,RED);
      bar(c,d,c+40,d+40);
      setcolor(YELLOW);
      outtextxy(c+10,d+14,inpu[a][b]);
      c+=50;
    }
    d+=50;
  }
  showptr();
  num=0;
  gotoxy(41,5);
  printf("%18.1Lf",num);                     //initialize the cursor
  count=0;
while(!kbhit())
{
  outtextxy(30,20,"Press any key to exit..");
  i1=0;
  c=240;
  d=100;
  rectangle(0,0,638,478);
  getmousepos(&button,&x,&y);
  for(a=0;a<5;a++)                       //make buttons clickable
  {
    c=240;
    for(b=0;b<5;b++)
    {
      if((x>=c&&x<=c+40)&&(y>=d&&y<=d+40))
      {
       if((button&1)==1)
       {
     while((button&1)==1)
     {
       setcolor(10);
       rectangle(c,d,c+40,d+40);
       rectangle(c-1,d-1,c+41,d+41);
       rectangle(c-2,d-2,c+42,d+42);
       break;
     }
     delay(100);
     setcolor(GREEN);
     rectangle(c,d,c+40,d+40);
     rectangle(c-1,d-1,c+41,d+41);
     rectangle(c-2,d-2,c+42,d+42);
     input=inp[a][b];
     switch(input)
     {
     case '.':

     case '1':
	 get=addnum(1);
	 gotoxy(41,5);
	 printf("%18.3Lf",get);
	 break;
     case '2':
	 get=addnum(2);
	 gotoxy(41,5);
	 printf("%18.3Lf",get);
	 break;
      case '3':
	 get=addnum(3);
	 gotoxy(41,5);
	 printf("%18.3Lf",get);
	 break;
       case '4':
	 get=addnum(4);
	 gotoxy(41,5);
	 printf("%18.3Lf",get);
	 break;
     case '5':
	 get=addnum(5);
	 gotoxy(41,5);
	 printf("%18.3Lf",get);
	 break;
     case '6':
	 get=addnum(6);
	 gotoxy(41,5);
	 printf("%18.3Lf",get);
	 break;
     case '7':
	 get=addnum(7);
	 gotoxy(41,5);
	 printf("%18.3Lf",get);
	 break;
   case '8':
	 get=addnum(8);
	 gotoxy(41,5);
	 printf("%18.3Lf",get);
	 break;
   case '9':
	 get=addnum(9);
	 gotoxy(41,5);
	 printf("%18.3Lf",get);
	 break;
   case '0':
	 get=addnum(0);
	 gotoxy(41,5);
	 printf("%18.3Lf",get);
	 break;
   case 'i':
	 gotoxy(38,5);
	 char ss[3]="sin";
	 opr='i';
	 printf("%s",ss);
	 break;
   case 'o':
	 gotoxy(38,5);
	 char ll[3]="log";
	 opr='o';
	 printf("%s",ll);
	 break;
   case 'c':
	 num1=num;
	 num=0;
	 gotoxy(38,5);
	 char cc[3]="cos";
	 opr='c';
	 printf("%s",cc);
	 break;
   case '!':
	num1=num;
	result=1;
	if(num1==0)
	{
	result=1;
	gotoxy(41,5);
	 printf("%18.3Lf",result);
	}
	else
	{
	for(int i=1;i<=num1;i++)
	{
	result=i*result;
	}
	gotoxy(41,5);
	 printf("%18.3Lf",result);
	}
	break;
   case 's':
	num1=num;
	result=sqrt(num1);
	gotoxy(41,5);
	 printf("%18.3Lf",result);
	break;
   case 'e':
	num=2.718;
	gotoxy(41,5);
	printf("%18.3Lf",num);
	break;
   case 'p':
	num=3.141;
	gotoxy(41,5);
	 printf("%18.3Lf",num);
	break;
   case 'q':
	num1=num;
	result=num1*num1;
	gotoxy(41,5);
	 printf("%18.3Lf",result);
	break;
   case 'r':
	 num1=num;
	 num=0;
	 opr='r';
	 gotoxy(41,5);
	 printf("%18.3Lf",num);
	 break;
  case '+':
	 num1=num;
	 num=0;
	 opr='+';
	 gotoxy(41,5);
	 printf("%18.3Lf",num);
	 break;
     case '-':
	 num1=num;
	 num=0;
	 opr='-';
	 gotoxy(41,5);
	 printf("%18.3Lf",num);
	break;
     case '*':
	 num1=num;
	 num=0;
	 opr='*';
	 gotoxy(41,5);
	 printf("%18.3Lf",num);
	break;
     case '/':
	 num1=num;
	 num=0;
	 opr='/';
	 gotoxy(41,5);
	 printf("%18.3Lf",num);
	break;
     case 'l':
	 num=0;
	 num1=0;
	 result=0;
	 count=0;
	 gotoxy(41,5);
	 printf("%18.3Lf",num);
	 break;
     case '=':
	 switch(opr)
	 {
	   case '+':
		 if(count<1)
		 {
		   result=num+num1;
		 }
	 else
		 {
		   result=result+num;
		 }
		 gotoxy(41,5);
		 printf("%18.3Lf",result);
		 count+=1;
		 break;
	   case '-':
		 if(count<1)
		 {
		   result=num1-num;
		 }
		 else
		 {
		   result=result-num;
		 }
		 gotoxy(41,5);
		 printf("%18.3Lf",result);
		 count+=1;
		 break;


	   case 'r':
		if(count<1)

		 {
		 result=1;
		if(num==1 || num1==1)
		{
			result=1;
			gotoxy(41,5);
		 printf("%18.3Lf",result);
		 num=result;
		}
		else
		{
		for(int i=1;i<=num;i++)
		{
			result*=num1;
		}
		num=result;
		gotoxy(41,5);
		 printf("%18.3Lf",result);
		 num=result;
		}
		num=result;
		 }
		 else
		 {
		 result=1;
		if(result==1 || num1==1)
		{
			result=1;
			gotoxy(41,5);
		 printf("%18.3Lf",result);
		 num=result;
		}
		else
		{
		for(int i=1;i<=result;i++)
		{
			result*=num1;
		}
		gotoxy(41,5);
		 printf("%18.3Lf",result);
		 num=result;
		}
		 }
		 count+=1;
		 break;

	   case 'i':
		num2=num*(3.14/180);
		result=sin(num2);
		gotoxy(38,5);
		printf("   ");
		gotoxy(41,5);
		printf("%18.3Lf",result);
		num=result;
		count+=1;
		break;
		case 'o':
		result=log10(num);
		gotoxy(38,5);
		printf("   ");
		gotoxy(41,5);
		printf("%18.3Lf",result);
		num=result;
		count+=1;
		break;
   case 'c':

		num2=num*(3.14/180);
		result=cos(num2);
		gotoxy(38,5);
		printf("   ");
		gotoxy(41,5);
		printf("%18.3Lf",result);
		result;
		count+=1;
		num=result;
		break;
	   case '*':
		 if(count<1)
		 {
		  result=num1*num;
		 }
		 else
		 {
		  result=result*num;
		 }
		 gotoxy(41,5);
		 printf("%18.3Lf",result);
		 count+=1;
		 break;

	   case '/':
		 if(count<1)
		 {
		  result=num1/num;
		 }
		 else
		 {
		  result=result/num;
		 }
		 gotoxy(41,5);
		 printf("%18.3Lf",result);
		 count+=1;
		 break;
	 }
     }
       }
      }
      c+=50;
    }
    d+=50;
  }
  setcolor(YELLOW);
  delay(150);

}
  getch();

}
long double addnum(int getnum)
{
    num=num*10+getnum;
    return(num);
}
void showptr()
{
   i.x.ax=1;
   int86(0x33,&i,&o);
}
void getmousepos(int *button,int *x,int *y)
{
  i.x.ax=3;
  int86(0x33,&i,&o);
  *button=o.x.bx;
  *x=o.x.cx;
  *y=o.x.dx;
}