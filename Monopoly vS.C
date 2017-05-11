#include<graphics.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int check_arr[]={0,0,0,0};
void buy(int num);
void sell(int num);
void rent(int num,int a) ;
void buyhouse(int num) ;
int jail(int j);
void play();
void display();
void initialize();
void createmulti();
void tax();
void uiPawn();
void uiDraw();
void uiMenuPlayerOptions();
void errorCode(char*);
void uiMenuGameOptions(int);
void uiMenuTrackOptions();
void uiBackground();
int dice(int);
char *stringValidate();
void uiMainScreen();
void uiWrite();
int check();

int countj[4]={0,0,0,0};
static int posLast_arr[]={0,0,0,0};

struct player{
		char playername[20];
		int playerno;
		int balance;
		int jail;
		struct player *down;
		struct node *right;
		};
struct player *pstart,*pptr,*ptemp;

struct node{
		char name[20]  ;
		int price ;
		int nhouse;
		struct node *next1;
		};
struct node *nptr,*ntemp,*ntemp1;

struct track{
		char placename[20];
		int placecost;
		int placeowner;
		int rent,rent1,rent2,rent3;
		int nhouses;
		int housecost;
		int type;
		struct track *next;
		}*start,*ptr,t,*p[4],*temp;

int main(){
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	createmulti();
	cleardevice();
	setbkcolor(BLACK);
	uiBackground();
	uiDraw();
	uiWrite();
	uiMenuGameOptions(8);
	play();
	//getch();
	return 0;
}


void uiWrite(/*struct node *head*/){
	int x1=0,y1=-40,x2=0,y2=0,count=0,count1=0,count2=0,count3=0,count4=0;
	char temp[5];
	struct track *trav;
	initialize();
	trav=start;
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	//2:bottom
	x1=-40;y1=0;x2=0;y2=0;
	while(x1<400){
		count4++;
		x1+=50;y1=410;x2+=50;y2=450;
		setcolor(WHITE);
		setfillstyle(CLOSE_DOT_FILL,8);
		settextstyle(SMALL_FONT,HORIZ_DIR,4);
		if(count4==1){
			count++;
			//outtextxy((x1+x2)/2,(y1+y2)/2,"temp");
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			outtextxy((x1+x2)/2,(y1+y2)/2,trav->placename);
			trav=trav->next;
		}
		else if(count4==2){
			count++;
			//outtextxy((x1+x2)/2,(y1+y2)/2,"temp");
			//settextstyle(SMALL_FONT,HORIZ_DIR,1);
			outtextxy((x1+x2)/2,(y1+y2)/2+34,trav->placename);
			trav=trav->next;
		}
		else{
			count++;
			//outtextxy((x1+x2)/2,(y1+y2)/2,"Temp");
			outtextxy((x1+x2)/2,(y1+y2)/2+28,trav->placename);
			trav=trav->next;
		}
		delay(10);
	}
	//3:right
	x1=0;y1=450;x2=0;y2=410;
	while(y1>10){
		count3++;
		x1=410;y1-=50;x2=450;y2-=50;
		setcolor(WHITE);
		setfillstyle(CLOSE_DOT_FILL,8);
		settextstyle(SMALL_FONT,VERT_DIR,4);
		if(count3<8){
			count++;
			//outtextxy((x1+x2)/2,(y1+y2)/2,"temp");
			outtextxy((x1+x2)/2+22,(y1+y2)/2,trav->placename);
			trav=trav->next;
		}else if(count3==8){
			count++;
			//outtextxy((x1+x2)/2,(y1+y2)/2,"temp");
			settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
			outtextxy((x1+x2)/2,(y1+y2)/2,trav->placename);
			trav=trav->next;
		}
		delay(10);
	}
	//4:top
	x1=500;y1=0;x2=460;y2=0;
	while(x1>0&&count2<8){
		count2++;
		x1-=50;y1=10;x2-=50;y2=50;
		setcolor(WHITE);
		setfillstyle(CLOSE_DOT_FILL,8);
		settextstyle(SMALL_FONT,HORIZ_DIR,4);
		if(count2>1&&count2<9){
			count++;
			//outtextxy((x1+x2)/2,(y1+y2)/2,"temp");
			outtextxy((x1+x2)/2,(y1+y2)/2-28,trav->placename);
			trav=trav->next;
		}
		delay(10);
	}
	//1:left
	x1=0;y1=-40;x2=0;y2=0;
	while(y1<400){
		count1++;
		x1=10;y1+=50;x2=50;y2+=50;
		setcolor(WHITE);
		setfillstyle(CLOSE_DOT_FILL,8);
		settextstyle(SMALL_FONT,VERT_DIR,4);
		if(count1<=8){
			count++;
			//outtextxy((x1+x2)/2,(y1+y2)/2,"temp");
			outtextxy((x1+x2)/2-28,(y1+y2)/2,trav->placename);
			trav=trav->next;
		}
		delay(10);
	}
	delay(100);
}

void play(){
	int j,ch,i,b,count[4]={0,0,0,0},x;
	char loop[10];
	while(1){
		pptr=pstart;
		c:
		for(j=0;j<4;j++){
//			uiMenuPlayerOptions(j+1,j+1,pptr->playername,pptr->balance);
			uiMenuGameOptions(j+1);
			if(count[j]>32){
					pptr->balance+=150;
					count[j]=(count[j]-32);
				}
			if(jail(j)==1){
					pptr=pptr->down;
					//continue;
					goto c;
				}
			x=dice(j+1);
			if(check_arr[j]==0){
				check_arr[j]=1;
//				uiPawn(j+1,j+1,x+1,0);
				}
			else{
//				uiPawn(j+1,j+1,x+1,posLast_arr[j+1]);
				}
			for(i=0;i<x;i++){
					p[j]=p[j]->next;
				}

			if(p[j]->type==0){
				if(p[j]->placeowner==0){
						a:
//						uiMenuTrackOptions(j+1,p[j]->placename,p[j]->placecost,1);
//						ch=inputMenuTrackOptions(1);
						switch(ch){
							case 49:{
								buy(j);
								goto a;
								break;
							}
					       case 50:{
								sell(j);
								goto a;
								break;
							}
							case 52:{
								continue;
							}
						}
				}
			}else if(p[j]->placeowner==j+1){
						b:
//						uiMenuTrackOptions(j+1,p[j]->placename,p[j]->placecost,2);
//						ch=inputMenuTrackOptions(4);
						switch(ch){
							case 49:{
								buyhouse(j);
								goto b;
								break;
								}
							case 50:{
							       sell(j);
							       goto b;
							       break;
							       }
							case 51:{
							       //continue;
							       goto c;
							       }
							case 53:	{
								exit(0);
								}
							}
			}else if(p[j]->type==2){
				countj[j]=3;
		}else if(p[j]->type==3){
//				tax(j);
		}else{
				rent(j,p[j]->placeowner-1);
			}
		pptr=pptr->down;
		sprintf(loop,"%d",i);
		errorCode(loop);
		getch();
		setfillstyle(SOLID_FILL,BLACK);
		setcolor(BLACK);
		bar(464,440,639,479);
		rectangle(464,440,639,479);
		floodfill(470,445,BLACK);
		}
	}
}

void initialize()
{
	int i;
	FILE *fp;
	fp=fopen("monopoly.txt","r");
	for(i=1;i<=32;i++)
	{
	ptr=(struct track*)malloc(sizeof(struct track));
	fflush(stdin);
	fscanf(fp,"%s %d %d %d %d %d %d %d %d %d\n",&t.placename,&t.type,&t.placecost,&t.placeowner,&t.rent,&t.rent1,&t.rent2,&t.rent3,&t.housecost,&t.nhouses);
	strcpy(ptr->placename,t.placename);
	ptr->placecost=t.placecost;
	ptr->placeowner=t.placeowner;
	ptr->rent=t.rent;
	ptr->rent1=t.rent1;
	ptr->rent2=t.rent2;
	ptr->rent3=t.rent3;
	ptr->housecost=t.housecost;
	ptr->nhouses=t.nhouses;
	ptr->type=t.type;
	if(start==NULL)
	{
		start=ptr;
		ptr->next=NULL;
		temp=ptr;
	}
	else
	{
		temp->next=ptr;
		ptr->next=NULL;
		temp=ptr;
	}
	temp->next=start;

	}
	fclose(fp);

	p[0]=p[1]=p[2]=p[3]=start;
}

void createmulti()
{
	int i;
		for(i=0;i<4;i++)
		{
//			uiMainScreen(i+1);
			pptr=(struct player*)malloc(sizeof(struct player));
//			strcpy(pptr->playername,stringValidate(pptr->playername,i,i+5));
			pptr->playerno=(i+1);
			pptr->balance=2000;
			pptr->down=NULL;
			if(pstart==NULL)
			{
				pstart=pptr;
				ptemp=pstart;
				ptemp->down=NULL;
			}
			else
			{
				 ptemp->down=pptr;
				 ptemp=ptemp->down;
				 ptemp->down=NULL;
			}
			pptr->right=NULL;
			cleardevice();
		}

}

void buy(int num)
{
	int i;

	pptr=pstart ;

	for(i=0;i<num;i++)
	{
		pptr=pptr->down;
	}

	pptr->balance=pptr->balance-p[num]->placecost;

	if(pptr->balance<=0)
	{
		errorCode("Insufficient Balance");
		pptr->balance=pptr->balance+p[num]->placecost;
		return;
	}
	else
	{
		nptr=(struct node*)malloc(sizeof(struct node));
		strcpy(nptr->name,p[num]->placename) ;
		nptr->price=p[num]->placecost;
		nptr->nhouse=0;
		p[num]->placeowner=num+1;
		nptr->next1=NULL;

		if(pptr->right==NULL)
		{
			pptr->right=nptr;

		}
		else
		{
			ntemp=pptr->right;
			while(ntemp->next1!=NULL)
			{
				ntemp=ntemp->next1;
			}
			ntemp->next1=nptr;
		}
	}

}

void rent(int num,int a)
{
       int i;

       pptr=pstart;

       for(i=0;i<num;i++)
       {
		pptr=pptr->down;
       }

       if(p[num]->nhouses==0)
       pptr->balance=pptr->balance-p[num]->rent;

       else if(p[num]->nhouses==1)
       pptr->balance=pptr->balance-p[num]->rent1;

       else if(p[num]->nhouses==2)
       pptr->balance=pptr->balance-p[num]->rent2;

       else
       pptr->balance=pptr->balance-p[num]->rent3;

       pptr=pstart ;

       for(i=0;i<a;i++)
       {
		pptr=pptr->down;
       }

       if(p[num]->nhouses==0)
       pptr->balance=pptr->balance+p[num]->rent;

       else if(p[num]->nhouses==1)
       pptr->balance=pptr->balance+p[num]->rent1;

       else if(p[num]->nhouses==2)
       pptr->balance=pptr->balance+p[num]->rent2;

       else
       pptr->balance=pptr->balance+p[num]->rent3;
}

void sell(int num)
{
	int i,j=1,pos;

	pptr=pstart ;

	for(i=0;i<num;i++)
	{
		pptr=pptr->down;
	}
	if(pptr->right==NULL)
	{
		errorCode("Nothing");
	}
	else
	{
		int i=80;
		ntemp=pptr->right;

	       while(ntemp)
		{
		char price[6];
		//printf("%d %s\t%d\n",j,ntemp->name,ntemp->price);
		outtextxy(((400)+(639-5))/2,70+i,ntemp->name);
		i+=10;
		sprintf(price,"%d",ntemp->price);
		outtextxy(((400)+(639-5))/2,70+i,price);
		i+=20;
		j++;
		ntemp=ntemp->next1;
		}

	errorCode("Which you want to sell");
//	pos=inputMenuTrackOptions(2);
	scanf("%d",&pos);
	ntemp=pptr->right;
	if(pos>j-1)
	{
		errorCode("Invalid");
	}
	else
	{
		if(pos==1)
		{

			pptr->right=ntemp->next1;
		}
		else
		{
			for(i=0;i<pos-1;i++)
			{
				ntemp1=ntemp;
				ntemp=ntemp->next1;
			}
			ntemp1->next1=ntemp->next1;
		}
		if(ntemp->nhouse==0)
		pptr->balance=pptr->balance+ntemp->price;

		else if(ntemp->nhouse==1)
		pptr->balance=pptr->balance+ntemp->price+150;


		else if(ntemp->nhouse==2)
		pptr->balance=pptr->balance+ntemp->price+300;


		else
		pptr->balance=pptr->balance+ntemp->price+450;

		ntemp=NULL;
		free(ntemp);
	}


    }

}

int jail(int j)
{
	if(countj[j]==0)
	{
		return 0;
	}
	else
	{
		countj[j]--;
		return 1;
	}
}

void buyhouse(int num)
{
	int i,n,pos;
	pptr=pstart;

	for(i=0;i<num;i++)
	{
		pptr=pptr->down;
	}

	ntemp=pptr->right;

	while(strcmp(p[num]->placename,ntemp->name)==0)
	{
		ntemp=ntemp->next1;
	}

	if(ntemp->nhouse==3)
	{
		errorCode("Limit reached!");
	}
	else
	{
		pptr->balance-=p[num]->housecost;
		if(pptr->balance<0)
		{
			errorCode("Insufficient balance!");
			pptr->balance+=p[num]->housecost;
			return;
		}
		else
		{
		ntemp->nhouse++;
		p[num]->nhouses++;
		errorCode("Successfull!");
		}
	}
}

void tax(int num)
{
     int i;
     pptr=pstart;

     for(i=0;i<num;i++)
     {
	pptr=pptr->down;
     }

     pptr->balance-=100;
}

int dice(int color){
	int array[]={1,2,3,4,5,6};
	int val,i=0,ch;
	char digit[2];
	setcolor(WHITE);
	setfillstyle(CLOSE_DOT_FILL,8);
	circle(230,479/2,50);
	floodfill(230,479/2,WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	while(1){
		setcolor(color);
		bar(230-20,479/2-20,230+20,479/2+20);
		sprintf(digit,"%d",array[i]);
		outtextxy(232,479/2+2,digit);
		i++;
		if(kbhit()){
			//ch=getch();
//			ch=inputMenuTrackOptions(3);
		}
		if(ch==100){
			i-=1;
			return array[i];
		}
		if(i==6){
			i=0;
		}
		delay(80);
	}
}

void uiDraw(int color){
	int x1=0,y1=-40,x2=0,y2=0,count1=0,count2=0,count3=0,count4=0;
	//2:bottom
	x1=-40;y1=0;x2=0;y2=0;
	while(x1<400){
		count4++;
		x1+=50;y1=410;x2+=50;y2=450;
		setcolor(WHITE);
		setfillstyle(CLOSE_DOT_FILL,4);
		if(count4==1){
			rectangle(x1-5,y1-5,x2+5,y2+5);
			floodfill((x1+x2)/2,(y1+y2)/2,WHITE);
		}
		else{
			rectangle(x1,y1,x2,y2);
			floodfill((x1+x2)/2,(y1+y2)/2,WHITE);
		}
		delay(10);
	}
	//3:right
	x1=0;y1=450;x2=0;y2=410;
	while(y1>10){
		count3++;
		x1=410;y1-=50;x2=450;y2-=50;
		setcolor(WHITE);
		setfillstyle(CLOSE_DOT_FILL,4);
		if(count3<8){
			rectangle(x1,y1,x2,y2);
			floodfill((x1+x2)/2,(y1+y2)/2,WHITE);
		}else if(count3==8){
			rectangle(x1-5,y1+5,x2+5,y2-5);
			floodfill((x1+x2)/2,(y1+y2)/2,WHITE);
		}
		delay(10);
	}
	//4:top
	x1=500;y1=0;x2=460;y2=0;
	while(x1>0&&count2<8){
		count2++;
		x1-=50;y1=10;x2-=50;y2=50;
		setcolor(WHITE);
		setfillstyle(CLOSE_DOT_FILL,4);
		if(count2>1&&count2<9){
			rectangle(x1,y1,x2,y2);
			floodfill((x1+x2)/2,(y1+y2)/2,WHITE);
		}
		delay(10);
	}
	//1:left
	x1=0;y1=-40;x2=0;y2=0;
	while(y1<400){
		count1++;
		x1=10;y1+=50;x2=50;y2+=50;
		setcolor(WHITE);
		setfillstyle(CLOSE_DOT_FILL,4);
		if(count1<9){
			rectangle(x1,y1,x2,y2);
			floodfill((x1+x2)/2,(y1+y2)/2,WHITE);
		}
		delay(10);
	}
	delay(100);
}

void uiMenuPlayerOptions(int color,int playerID,char *playerName,int balance){
	int i=10;
	char playerDetails[20];
	setfillstyle(CLOSE_DOT_FILL,color);
	setcolor(color);
	rectangle(464,0,639,60);
	floodfill(464+1,0+1,color);
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	setcolor(WHITE);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	sprintf(playerDetails,"Player ID: %d",playerID);
	outtextxy((464+639)/2,(0+18)/2+i,playerDetails);
	i+=10;
	outtextxy((464+639)/2,(0+18)/2+i,playerName);
	i+=10;
	sprintf(playerDetails,"%d",balance);
	outtextxy((464+639)/2,(0+18)/2+i,playerDetails);
}

void errorCode(char str[20]){
	bar(464-1,440-1,639-1,479-1);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	setfillstyle(CLOSE_DOT_FILL,8);
	setcolor(WHITE);
	rectangle(464,440,639,479);
	floodfill(470,445,WHITE);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy((464+639)/2,(440+479)/2,str);
}

void uiMenuGameOptions(int color){
	int i=10;
	setcolor(color);
	setfillstyle(CLOSE_DOT_FILL,color);
	rectangle(450+18,310,639-5,430);
	floodfill(450+18+1,330+1,color);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	setcolor(WHITE);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	outtextxy(((450+18)+(639-5))/2,330+i,"Game Options");
	i+=10;
	outtextxy(((450+18)+(639-5))/2,330+i,"(esc) for EXIT");
}

void uiMenuTrackOptions(int color,char *propertyName,int propertyCost,int flag){
	int i=20;
	char *cost;
	setcolor(color);
	setfillstyle(CLOSE_DOT_FILL,color);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	rectangle(450+18,70,639-5,300);
	floodfill(450+18+2,200+2,color);
	settextjustify(LEFT_TEXT,CENTER_TEXT);
	setcolor(WHITE);
	outtextxy(((400)+(639-5))/2,70+i,propertyName);
	i+=10;
	sprintf(cost,"%d",propertyCost);
	outtextxy(((400)+(639-5))/2,70+i,cost);
	}


int inputMenuTrackOptions(int flag){
	int i=50;
	static char ch[2];
	ch[1]='\0';
	trackA:
	switch(flag){
		case 1:{
			int ch;
			scanf("%d",&ch);
			outtextxy(((400)+(639-5))/2,70+i,"1. Buy");
			i+=10;
			outtextxy(((400)+(639-5))/2,70+i,"2. Sell");
			i+=10;
			//outtextxy(((400)+(639-5))/2,70+i,"3. Build House");
			//i+=10;
			outtextxy(((400)+(639-5))/2,70+i,"4. Pass On");
			//ch[0]=check();
			scanf("%d",&ch);
			//errorCode(ch);
			setfillstyle(SOLID_FILL,BLACK);
			setcolor(BLACK);
			bar(464,440,639,479);
			rectangle(464,440,639,479);
			floodfill(470,445,BLACK);
			switch(ch){
				case 1:
				case 2:
				case 3:
				case 4:{
					return ch;
				}
				default:{
					errorCode("Wrong Input");
					goto trackA;
				}
			}
		}
		case 4:{
			int ch;
			outtextxy(((400)+(639-5))/2,70+i,"1. Build House");
			i+=10;
			outtextxy(((400)+(639-5))/2,70+i,"2. Sell House");
			i+=10;
			scanf("%d",&ch);
			setfillstyle(SOLID_FILL,BLACK);
			setcolor(BLACK);
			bar(464,440,639,479);
			rectangle(464,440,639,479);
			floodfill(470,445,BLACK);
			switch(ch){
				case 1:
				case 2:{
					return ch;
				}
				default:{
					goto trackA;
				}
			}
		}
		case 2:{
			outtextxy(((400)+(639-5))/2,70+i,"Confirm?");
//			gotoxy(1,1);
			ch[0]=check();
			setfillstyle(SOLID_FILL,BLACK);
			setcolor(BLACK);
			bar(464,440,639,479);
			rectangle(464,440,639,479);
			floodfill(470,445,BLACK);
			switch(ch[0]){
				case 'y':
				case 'Y':
				case 'n':
				case 'N':{
					return ch[0];
				}
				default:{
					errorCode("Wrong Input");
					goto trackA;
				}
			}
		}
		case 3:{
			ch[0]=check();
			setfillstyle(SOLID_FILL,BLACK);
			setcolor(BLACK);
			bar(464,440,639,479);
			rectangle(464,440,639,479);
			floodfill(470,445,BLACK);
			switch(ch[0]){
				case 'd':
				case 'D':{
					return ch[0];
				}
				default:{
					goto trackA;
				}
			}
		}
	}
}

void uiBackground(){
	setviewport(0,0,639,679,1);
	setfillstyle(CLOSE_DOT_FILL,5);
	setcolor(7);
	rectangle(0,0,460,479);
	floodfill(459,478,7);
	}

void uiMainScreen(int foreground){
	setbkcolor(foreground);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL,WHITE);
	rectangle(0,480/2-6,640,480/2+12);
	floodfill(0+1,480/2-6+1,8);
	outtextxy(640/2,480-30,"Designed at (c) DEDSEC in INDIA");
}

char *stringValidate(char *string,int foreground,int background){
	char temp[2];
	int i=0,count=0,flag=1,x=640/2,xMin=640/2,y=480/2,size=10;
	stringV:
	strcpy(string,'\0');
	setbkcolor(background);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	setcolor(foreground);
	outtextxy(x,y,"What's first name?");
	temp[0]=getch();
	setcolor(8);
	setfillstyle(SOLID_FILL,WHITE);
	rectangle(0,480/2-6,640,480/2+12);
	floodfill(0+1,480/2-6+1,8);
	temp[1]='\0';
	setcolor(foreground);
	if(temp[0]==13){
		outtextxy(x,y+40,"Enter Something");
		delay(200);
		cleardevice();
		goto stringV;
	}
	while(temp[0]!=13){
		setcolor(foreground);
		if(i>=size){
			outtextxy(640/2,480/2+40,"MAX Char Limit Reached!");
			delay(100);
			cleardevice();
			temp[0]=getch();
		}
		if(temp[0]==27){
			char ch;
			strcpy(string,'\0');
			cleardevice();
			outtextxy(640/2,y,"EXIT?");
			ch==getch();
			if(ch=='y'||ch=='Y'){
				exit(0);
			}else{
				cleardevice();
				temp[0]=getch();
			}
		}else if(temp[0]==8){
			count++;
			if(count>=5){
				cleardevice();
				strcpy(string,'\0');
				i=0;
				count=0;
				flag=1;
				temp[0]=getch();
			}else{
				setcolor(WHITE);
				temp[0]=*(string+(--i));
				*(string+i)='\0';
				if(x<=xMin){
					x=xMin;
					strcpy(string,'\0');
					i=0;
					flag=1;
				}
				outtextxy(x,y,temp);
				x-=8;
				if(temp[0]==32){
					flag=1;
					temp[0]=getch();
				}else{
					temp[0]=getch();
				}
			}
		}else if(temp[0]==32){
			flag=1;
			count=0;
			*(string+(i++))=temp[0];
			x+=16;
			temp[0]=getch();
		}else if(temp[0]>=65&&temp[0]<=90){
			count=0;
			temp[0]=tolower(temp[0]);
			*(string+(i++))=temp[0];
			x+=8;
			outtextxy(x,y,temp);
			temp[0]=getch();
		}else if(temp[0]>=97&&temp[0]<=122){
			count=0;
			if(flag==1){
				temp[0]=toupper(temp[0]);
				flag=0;
			}else{
				temp[0]=tolower(temp[0]);
				flag=0;
			}
			*(string+(i++))=temp[0];
			x+=8;
			outtextxy(x,y,temp);
			temp[0]=getch();
		}/*if(strcpy(string," \0")==0){
			outtextxy(x,y+40,"Messed Up!");
			delay(400);
			cleardevice();
			stringValidate(x,y,xMin,size,string);
		}*/else{
			count=0;
			outtextxy(640/2,y+40,"Not Accepted");
			delay(100);
			setcolor(background);
			outtextxy(640/2,y+40,"Not Accepted");
			temp[0]=getch();
		}
	}strcpy(string+i,'\0');
	if(strcmp(string,'\0')==0){
		cleardevice();
		goto stringV;
	}else
		return string;
}

int check(){
	char ch,temp;
	kbhit:
	if(kbhit){
		ch=getch();
		setfillstyle(SOLID_FILL,BLACK);
		setcolor(BLACK);
		bar(464,440,639,479);
		rectangle(464,440,639,479);
		floodfill(470,445,BLACK);
		if(ch==27){
			errorCode("Exit?");
			setcolor(WHITE);
			outtextxy((464+639)/2,(440+479)/2+10,"y/n");
			temp=getch();
			if(temp=='y'||temp=='Y'){
				exit(0);
			}
		}else{
				return ch;
			}
	}else{
		goto kbhit;
	}
}











void uiPawn(int playerID,int playerColor,int pos,int posLast){

	int count=0,turn=posLast;
	int steps=abs(pos-posLast);

	if(playerID>=1&&playerID<=4)
	{
		int x1,x2,y1,y2;

		switch(playerID)
		{
			case 1:{

				if(posLast>=0&&posLast<=8){

					x1=10,x2=50,y1=410,y2=450;

					while(count!=posLast-1)
					{count++;}

					y1-=(count*50),y2-=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<=8){
							y1-=50,y2-=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=10,x2=50,y1=10,y2=50;       	}
								else
								x1+=50,x2+=50;
							}
							else if(turn>=16&&turn<24){
								if(turn==16)
								{	x1=410,x2=450,y1=10,y2=50;	}
								else
								y1+=50,y2+=50;
							}
							else if(turn>=24&&turn<=31){
								if(turn==24)
								{   	x1=410,x2=450,y1=410,y2=450; 	}
								else
								x1-=50,x2-=50;
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;

						delay(50);
					}
				}

				else if(posLast>=9&&posLast<=16){

					x1=10,x2=50,y1=10,y2=50;

				  while(count!=posLast-9)
					{count++;}
					count--;
					x1+=(count*50),x2+=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<8){
								y1-=50,y2-=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=10,x2=50,y1=10,y2=50; 	}
								else
								{	x1+=50,x2+=50;			}
							}
							else if(turn>=16&&turn<24){
								if(turn==16)
								{	x1=410,x2=450,y1=10,y2=50;	}
								else
								{	y1+=50,y2+=50;			}
							}
							else if(turn>=24&&turn<=31){
								if(turn==24)
								{   	x1=410,x2=450,y1=410,y2=450; 	}
								else
								{	x1-=50,x2-=50;			}
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;
						delay(50);
					}
				}

				else if(posLast>=16&&posLast<=24){

				x1=410,x2=450,y1=10,y2=50;

				  while(count!=posLast-16)

					{count++;}
					count--;

					y1+=(count*50),y2+=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<8){
							y1+=50,y2+=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=60,x2=110,y1=10,y2=50;	}
								else
								x1+=50,x2+=50;
							}
							else if(turn>=16&&turn<24){
								if(turn==16)
								{	x1=410,x2=450,y1=10,y2=50;	}
								else
								y1+=50,y2+=50;
							}
							else if(turn>=24&&turn<=31){
								if(turn==24)
								{   x1=410,x2=450,y1=410,y2=450; }
								else
								x1-=50,x2-=50;
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;

						delay(50);
					}
				}

				else if(posLast>=25&&posLast<=31){

					x1=410,x2=450,y1=410,y2=450;

				  while(count!=posLast-24)
					{count++;}
					 count--;
					x1-=(count*50),x2-=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<8){
							y1-=50,y2-=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=10,x2=50,y1=10,y2=50;	}
								else
								x1+=50,x2+=50;
							}
							else if(turn>=16&&turn<24){
								if(turn==17)
								{	x1=410,x2=450,y1=60,y2=110;	}
								else
								y1+=50,y2+=50;
							}
							else if(turn>=24&&turn<=32){
								if(turn==24)
								{   x1=410,x2=450,y1=410,y2=450; }
								else
								x1-=50,x2-=50;
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;

						delay(50);
					}
				}
				posLast_arr[playerID-1]+=pos;
				break;
			}

			case 2:{
				if(posLast>=0&&posLast<=8){

					x1=10,x2=50,y1=410,y2=450;

					while(count!=posLast-1)
					{count++;}

					y1-=(count*50),y2-=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<=8){
							y1-=50,y2-=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=10,x2=50,y1=10,y2=50;       	}
								else
								x1+=50,x2+=50;
							}
							else if(turn>=16&&turn<24){
								if(turn==16)
								{	x1=410,x2=450,y1=10,y2=50;	}
								else
								y1+=50,y2+=50;
							}
							else if(turn>=24&&turn<=31){
								if(turn==24)
								{   	x1=410,x2=450,y1=410,y2=450; 	}
								else
								x1-=50,x2-=50;
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;

						delay(50);
					}
				}

				else if(posLast>=9&&posLast<=16){

					x1=10,x2=50,y1=10,y2=50;

				  while(count!=posLast-9)
					{count++;}
					count--;
					x1+=(count*50),x2+=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<8){
								y1-=50,y2-=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=10,x2=50,y1=10,y2=50; 	}
								else
								{	x1+=50,x2+=50;			}
							}
							else if(turn>=16&&turn<24){
								if(turn==16)
								{	x1=410,x2=450,y1=10,y2=50;	}
								else
								{	y1+=50,y2+=50;			}
							}
							else if(turn>=24&&turn<=31){
								if(turn==24)
								{   	x1=410,x2=450,y1=410,y2=450; 	}
								else
								{	x1-=50,x2-=50;			}
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;
						delay(50);
					}
				}

				else if(posLast>=16&&posLast<=24){

				x1=410,x2=450,y1=10,y2=50;

				  while(count!=posLast-16)

					{count++;}
					count--;

					y1+=(count*50),y2+=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<8){
							y1+=50,y2+=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=60,x2=110,y1=10,y2=50;	}
								else
								x1+=50,x2+=50;
							}
							else if(turn>=16&&turn<24){
								if(turn==16)
								{	x1=410,x2=450,y1=10,y2=50;	}
								else
								y1+=50,y2+=50;
							}
							else if(turn>=24&&turn<=31){
								if(turn==24)
								{   x1=410,x2=450,y1=410,y2=450; }
								else
								x1-=50,x2-=50;
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;

						delay(50);
					}
				}

				else if(posLast>=25&&posLast<=31){

					x1=410,x2=450,y1=410,y2=450;

				  while(count!=posLast-24)
					{count++;}
					 count--;
					x1-=(count*50),x2-=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<8){
							y1-=50,y2-=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=10,x2=50,y1=10,y2=50;	}
								else
								x1+=50,x2+=50;
							}
							else if(turn>=16&&turn<24){
								if(turn==17)
								{	x1=410,x2=450,y1=60,y2=110;	}
								else
								y1+=50,y2+=50;
							}
							else if(turn>=24&&turn<=32){
								if(turn==24)
								{   x1=410,x2=450,y1=410,y2=450; }
								else
								x1-=50,x2-=50;
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y1+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;

						delay(50);
					}
				}
				posLast_arr[playerID-1]+=pos;
				break;
			}

			case 3:{
				if(posLast>=0&&posLast<=8){

					x1=10,x2=50,y1=410,y2=450;

					while(count!=posLast-1)
					{count++;}

					y1-=(count*50),y2-=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<=8){
							y1-=50,y2-=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=10,x2=50,y1=10,y2=50;       	}
								else
								x1+=50,x2+=50;
							}
							else if(turn>=16&&turn<24){
								if(turn==16)
								{	x1=410,x2=450,y1=10,y2=50;	}
								else
								y1+=50,y2+=50;
							}
							else if(turn>=24&&turn<=31){
								if(turn==24)
								{   	x1=410,x2=450,y1=410,y2=450; 	}
								else
								x1-=50,x2-=50;
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;

						delay(50);
					}
				}

				else if(posLast>=9&&posLast<=16){

					x1=10,x2=50,y1=10,y2=50;

				  while(count!=posLast-9)
					{count++;}
					count--;
					x1+=(count*50),x2+=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<8){
								y1-=50,y2-=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=10,x2=50,y1=10,y2=50; 	}
								else
								{	x1+=50,x2+=50;			}
							}
							else if(turn>=16&&turn<24){
								if(turn==16)
								{	x1=410,x2=450,y1=10,y2=50;	}
								else
								{	y1+=50,y2+=50;			}
							}
							else if(turn>=24&&turn<=31){
								if(turn==24)
								{   	x1=410,x2=450,y1=410,y2=450; 	}
								else
								{	x1-=50,x2-=50;			}
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;
						delay(50);
					}
				}

				else if(posLast>=16&&posLast<=24){

				x1=410,x2=450,y1=10,y2=50;

				  while(count!=posLast-16)

					{count++;}
					count--;

					y1+=(count*50),y2+=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<8){
							y1+=50,y2+=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=60,x2=110,y1=10,y2=50;	}
								else
								x1+=50,x2+=50;
							}
							else if(turn>=16&&turn<24){
								if(turn==16)
								{	x1=410,x2=450,y1=10,y2=50;	}
								else
								y1+=50,y2+=50;
							}
							else if(turn>=24&&turn<=31){
								if(turn==24)
								{   x1=410,x2=450,y1=410,y2=450; }
								else
								x1-=50,x2-=50;
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;

						delay(50);
					}
				}

				else if(posLast>=25&&posLast<=31){

					x1=410,x2=450,y1=410,y2=450;

				  while(count!=posLast-24)
					{count++;}
					 count--;
					x1-=(count*50),x2-=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<8){
							y1-=50,y2-=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=10,x2=50,y1=10,y2=50;	}
								else
								x1+=50,x2+=50;
							}
							else if(turn>=16&&turn<24){
								if(turn==17)
								{	x1=410,x2=450,y1=60,y2=110;	}
								else
								y1+=50,y2+=50;
							}
							else if(turn>=24&&turn<=32){
								if(turn==24)
								{   x1=410,x2=450,y1=410,y2=450; }
								else
								x1-=50,x2-=50;
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x1+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;

						delay(50);
					}
				}
				posLast_arr[playerID-1]+=pos;
				break;
			}

			case 4:{
				if(posLast>=0&&posLast<=8){

					x1=10,x2=50,y1=410,y2=450;

					while(count!=posLast-1)
					{count++;}

					y1-=(count*50),y2-=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<=8){
							y1-=50,y2-=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=10,x2=50,y1=10,y2=50;       	}
								else
								x1+=50,x2+=50;
							}
							else if(turn>=16&&turn<24){
								if(turn==16)
								{	x1=410,x2=450,y1=10,y2=50;	}
								else
								y1+=50,y2+=50;
							}
							else if(turn>=24&&turn<=31){
								if(turn==24)
								{   	x1=410,x2=450,y1=410,y2=450; 	}
								else
								x1-=50,x2-=50;
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;

						delay(50);
					}
				}

				else if(posLast>=9&&posLast<=16){

					x1=10,x2=50,y1=10,y2=50;

				  while(count!=posLast-9)
					{count++;}
					count--;
					x1+=(count*50),x2+=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<8){
								y1-=50,y2-=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=10,x2=50,y1=10,y2=50; 	}
								else
								{	x1+=50,x2+=50;			}
							}
							else if(turn>=16&&turn<24){
								if(turn==16)
								{	x1=410,x2=450,y1=10,y2=50;	}
								else
								{	y1+=50,y2+=50;			}
							}
							else if(turn>=24&&turn<=31){
								if(turn==24)
								{   	x1=410,x2=450,y1=410,y2=450; 	}
								else
								{	x1-=50,x2-=50;			}
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;
						delay(50);
					}
				}

				else if(posLast>=16&&posLast<=24){

				x1=410,x2=450,y1=10,y2=50;

				  while(count!=posLast-16)

					{count++;}
					count--;

					y1+=(count*50),y2+=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<8){
							y1+=50,y2+=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=60,x2=110,y1=10,y2=50;	}
								else
								x1+=50,x2+=50;
							}
							else if(turn>=16&&turn<24){
								if(turn==16)
								{	x1=410,x2=450,y1=10,y2=50;	}
								else
								y1+=50,y2+=50;
							}
							else if(turn>=24&&turn<=31){
								if(turn==24)
								{   x1=410,x2=450,y1=410,y2=450; }
								else
								x1-=50,x2-=50;
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;

						delay(50);
					}
				}

				else if(posLast>=25&&posLast<=31){

					x1=410,x2=450,y1=410,y2=450;

				  while(count!=posLast-24)
					{count++;}
					 count--;
					x1-=(count*50),x2-=(count*50);

					count=0;

					while(count<=steps){

						if(count==steps){

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);

						}
						else if(count<steps){

							if(turn<8){
							y1-=50,y2-=50;}

							else if(turn>=8&&turn<16){
								if(turn==8)
								{	x1=10,x2=50,y1=10,y2=50;	}
								else
								x1+=50,x2+=50;
							}
							else if(turn>=16&&turn<24){
								if(turn==17)
								{	x1=410,x2=450,y1=60,y2=110;	}
								else
								y1+=50,y2+=50;
							}
							else if(turn>=24&&turn<=32){
								if(turn==24)
								{   x1=410,x2=450,y1=410,y2=450; }
								else
								x1-=50,x2-=50;
							}

							setfillstyle(SOLID_FILL,playerColor);
							setcolor(playerColor);
							circle((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),playerColor);
							delay(40);
							setfillstyle(CLOSE_DOT_FILL,BLUE);
							setcolor(BLUE);
							circle((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),4);
							floodfill((x2+(x1+x2)/2)/2,((y2+(y1+y2)/2)/2),BLUE);
						}

						turn++,count++;

						delay(50);
					}
				}
				posLast_arr[playerID-1]+=pos;
				break;
			}
		}
	}
else
	{
		errorCode("Invalid Player ID");
	}
}
