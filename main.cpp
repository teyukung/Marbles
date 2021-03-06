#include<stdio.h>
#include<time.h>
#include<math.h>
#include<windows.h>
#include<conio.h>

#define N 10

int map[15][16]={{2,3,3,3,3,3,3,3,3,3,3,3,3,3,2,7},//0
					{2,0,0,0,0,0,0,0,0,0,0,0,0,0,2,7},//1
					{2,0,0,0,0,0,0,0,0,0,0,0,4,0,2,7},//2
					{2,4,0,0,0,0,0,0,0,0,0,0,0,4,2,7},//3
					{2,0,4,0,0,0,0,0,0,0,0,0,4,0,2,7},//4
					{2,0,5,0,5,0,5,0,5,0,5,0,2,0,2,7},//5
					{2,5,0,6,0,6,0,5,0,5,0,5,2,0,2,7},//6
					{2,0,0,6,6,6,0,0,5,0,6,0,2,0,2,7},//7
					{2,5,0,5,0,5,0,6,0,0,6,6,2,0,2,7},//8
					{2,0,5,0,5,0,6,6,6,0,5,0,2,0,2,7},//9
					{2,5,0,5,0,5,0,5,0,5,0,5,2,0,2,7},//10
					{2,0,0,0,0,0,0,0,0,0,0,0,2,0,2,7},//11
					{2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,7},//12
					{2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,7},//13
					{2,3,3,3,3,3,3,3,3,3,3,3,3,3,2,7}//14	
					};
int ball[15][16];
int output[15][16];
int x,y;
int score=0;
int l;

void ball_position(int,int);

int main (void){
	char start;
	int i,j,k,light1,light2,x1,x2;
	int ball_start_x=13/*球的初始x座標*/,ball_start_y=13/*球的初始x座標*/;
	
	srand(time(NULL));
	y=ball_start_y;
	x=ball_start_x;
	ball[y][x]=1;

	light1=rand()%6;
	do{
		light2=rand()%6;
	}while(light1==light2);

	for(j=0;j<=14;j++){
			for(k=0;k<=15;k++){
				output[j][k]=map[j][k];
				if(ball[j][k]==1&&map[j][k]==0) 
				output[j][k]=1;
			}
		}
	switch(light1){
		case 0:output[12][1]= -1;x1=1;break;
		case 1:output[12][3]= -1;x1=3;break;
		case 2:output[12][5]= -1;x1=5;break;
		case 3:output[12][7]= -1;x1=7;break;
		case 4:output[12][9]= -1;x1=9;break;
		case 5:output[12][11]= -1;x1=11;break;
	}
	
	switch(light2){
		case 0:output[12][1]= -1;x2=1;break;
		case 1:output[12][3]= -1;x2=3;break;
		case 2:output[12][5]= -1;x2=5;break;
		case 3:output[12][7]= -1;x2=7;break;
		case 4:output[12][9]= -1;x2=9;break;
		case 5:output[12][11]= -1;x2=11;break;
	}
			
	for(j=0;j<15;j++){
		for(k=0;k<16;k++){
			switch(output[j][k]){
			case 0: printf(" ");break;
			case 1: printf("@");break;
			case 2: printf("|");break;
			case 3: printf("-");break;
			case 4: printf("\\");break;
			case 5: printf(".");break;
			case 6: printf("*");break;
			case 7: printf("\n");break;
			case -1:printf("$");break;
			}
		}
	}
	y=ball_start_y;
	x=ball_start_x;
	for(i=1;i<=N;i++){
		printf("第%d次\n",i);
		printf("\n分數:%d\n\n",score);
		printf("發射彈珠(ENTER)");
		while(1){
			start=getch();
			if(start=='\n'||start=='\r'){
				system("CLS");
				break;
			}
		}
		output[13][13]=0;
		y=ball_start_x;
		x=ball_start_y;
		l=rand()%7+3;
		while(output[13][13]!=1){
			
			//把y和x現在所在的座標傳入ball_position(y,x)函式，
			//得到新的x和y座標，並且把 ball陣列 改動成新的 ball陣列。 
			ball_position(y,x);
			
			if (ball[y][x]==1&&output[y][x]==-1)
			score=score+100;
						
			//把 map和 ball陣列 結果比較後存入 output陣列 。 
			for(j=0;j<15;j++){
				for(k=0;k<16;k++){
					output[j][k]=map[j][k];
					if(ball[j][k]==1&&map[j][k]==0) 
					output[j][k]=1;
				}
			}
			
			switch(light1){
				case 0:output[12][1]= -1;break;
				case 1:output[12][3]= -1;break;
				case 2:output[12][5]= -1;break;
				case 3:output[12][7]= -1;break;
				case 4:output[12][9]= -1;break;
				case 5:output[12][11]= -1;break;
			}
	
			switch(light2){
				case 0:output[12][1]= -1;break;
				case 1:output[12][3]= -1;break;
				case 2:output[12][5]= -1;break;
				case 3:output[12][7]= -1;break;
				case 4:output[12][9]= -1;break;
				case 5:output[12][11]= -1;break;
			}
		
			for(j=0;j<15;j++){
				for(k=0;k<16;k++){
					switch(output[j][k]){
						case 0: printf(" ");break;
						case 1: printf("@");break;
						case 2: printf("|");break;
						case 3: printf("-");break;
						case 4: printf("\\");break;
						case 5: printf(".");break;
						case 6: printf("*");break;
						case 7: printf("\n");break;
						case -1:printf("$");break;
					}
				}
			}
			printf("第%d次\n",i);
			printf("\n分數:%d\n\n",score);
			if(output[13][x]==1&&x>0&&x<13)
			system("pause");
			if(output[6][4]==1)
			system("pause");
			if(output[7][11]==1)
			system("pause");
			Sleep(30);
			system("CLS");
		}
		
		y=ball_start_y;
		x=ball_start_x;
		ball[y][x]=1;
		for(j=0;j<=14;j++){
				for(k=0;k<=15;k++){
					output[j][k]=map[j][k];
					if(ball[j][k]==1&&map[j][k]==0) 
						output[j][k]=1;
				}
		}
		output[12][x1]=0;
		output[12][x2]=0;
		light1=rand()%6;
	
		do{
			light2=rand()%6;
		}while(light1==light2);
	
		switch(light1){
			case 0:output[12][1]= -1;x1=1;break;
			case 1:output[12][3]= -1;x1=3;break;
			case 2:output[12][5]= -1;x1=5;break;
			case 3:output[12][7]= -1;x1=7;break;
			case 4:output[12][9]= -1;x1=9;break;
			case 5:output[12][11]= -1;x1=11;break;
		}
	
		switch(light2){
			case 0:output[12][1]= -1;x2=1;break;
			case 1:output[12][3]= -1;x2=3;break;
			case 2:output[12][5]= -1;x2=5;break;
			case 3:output[12][7]= -1;x2=7;break;
			case 4:output[12][9]= -1;x2=9;break;
			case 5:output[12][11]= -1;x2=11;break;
		}
	
		for(j=0;j<15;j++){
			for(k=0;k<16;k++){
				switch(output[j][k]){
				case 0: printf(" ");break;
				case 1: printf("@");break;
				case 2: printf("|");break;
				case 3: printf("-");break;
				case 4: printf("\\");break;
				case 5: printf(".");break;
				case 6: printf("*");break;
				case 7: printf("\n");break;
				case -1:printf("$");break;
				}
			}
		}
		
	}
	printf("\n恭喜你!你總共得到 %d 分\n\n",score);
	system("pause");
	return 0;
}		
	
//球的運動軌跡 
void ball_position(int ys,int xs){
	int dir;
	if(xs==13&&ys>4){ 
		ball[y][x]=0;//球原本位置變成 0 在原來位置的球消失 
		y--;
		ball[y][x]=1;//目標位置改成 1 在目標位置球出現 
		return;
	} 
	if(xs<=13&&xs>=11&&ys<=4&&ys>=2){
		ball[y][x]=0;
		x--;y--;
		ball[y][x]=1;
		return;
	} 
	if(ys==1&&xs<=10&&xs>=6){
		ball[y][x]=0;
		x--;
		ball[y][x]=1;
		return;
	} 
	if(xs<=5&&xs>=4&&ys>=1&&ys<=2){
		ball[y][x]=0;
		x--;y++;
		ball[y][x]=1;
		return;
	} 
	if(ys==3&&xs>=3&&xs<l){
		ball[y][x]=0;
		x++;
		ball[y][x]=1;
		return;
	} 
	if(ys==3&&xs==l){ 
		ball[y][x]=0;
		x++;y++;
		ball[y][x]=1;
		return;
	} 
	if(ys>=4&&xs>=0&&xs<13){
		if (map[y+1][x]==0){ 
		ball[y][x]=0;
		y++;
		ball[y][x]=1;
		return;
		} 
		if(map[y+1][x]!=0){
			dir=rand()%2;
			if(dir==0){
				if(map[y+1][x-1]==0){
					ball[y][x]=0;
					y++;x--;
					ball[y][x]=1;
					return;
				} 
				if(map[y+1][x-1]!=0){
					if(map[y+1][x+1]==0){ 
						ball[y][x]=0;
						y++;x++;
						ball[y][x]=1;
						return;
					} 
					if(map[y+1][x+1]!=0){
						ball[y][x]=0;
						y=13;x=13;
						ball[y][x]=1;
						return;
					}
				}
			}
			if(dir==1){
				if(map[y+1][x+1]==0){
					ball[y][x]=0;
					y++;x++;
					ball[y][x]=1;
					return;
				}
				if(map[y+1][x+1]!=0){
					if(map[y+1][x-1]==0){
						ball[y][x]=0;
						y++;x--;
						ball[y][x]=1;
						return;
					}
					if(map[y+1][x-1]!=0){
						ball[y][x]=0;
						y=13;x=13;
						ball[y][x]=1;
						return;
					}
				}
			}
		}
	}
	if(y==13&&x>=0&&x<13){
		ball[y][x]=0;
		y=13;x=13;
		ball[y][x]=1;
		return;
	}
	
}
