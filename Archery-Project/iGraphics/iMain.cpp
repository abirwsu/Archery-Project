# include "iGraphics.h"
#include <stdio.h>

int board_x,board_y,dx,dy;
int ax,ay,g,h,a_x,a_y,i;
int t1 = 1200;
int t2 = 410;
int t3 = 1000;
int t4 = 410;
int z =0;
int x =0;
int switch_counter = 0;
int counter = 0;
int arr_counter = 0,mis_arrow,arr_remain=5;
int score=0,level=1;
int mode,m=0;
char str[3],str2[3];
void gameover();
void boardchange2();
void arr(int p,int q,int r,int y){	
	
	iSetColor(0,0,0);
	iLine(p,q,r,y);
	double xa[]={r,r+15,r+15};
	double ya[]={y,y+4,y-4};
	iFilledPolygon(xa,ya,3);
	double xa1[]={p-15,p-10,p+5,p,p+5,p-10};
	double ya1[]={y,y+4,y+4,y,y-4,y-4};
	iFilledPolygon(xa1,ya1,6);
	sprintf(str,"%d",score);
	sprintf(str2,"%d",arr_remain);
	iSetColor(15,15,15);
	iText(600,600,"SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(690,600,str,GLUT_BITMAP_TIMES_ROMAN_24);
	iText(550,550,"ARROW REMAINING:",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(800,550,str2,GLUT_BITMAP_TIMES_ROMAN_24);

	if(level==1 && mode==1)
		iText(605,650,"LEVEL 1",GLUT_BITMAP_TIMES_ROMAN_24);
	else if(level==2 && mode==1)
		iText(605,650,"LEVEL 2",GLUT_BITMAP_TIMES_ROMAN_24);
	else if(level==3 && mode==1)
		iText(605,650,"LEVEL 3",GLUT_BITMAP_TIMES_ROMAN_24);



	if(mis_arrow==3){
		mode=2;
		mis_arrow=0;
		arr_counter=0;
	}

	
	
	
	
}


void gameover(){
    if(mis_arrow==3){
		mode=2;
		mis_arrow=0;
		arr_counter=0;
		arr_remain=5;
		score=0;
	}
//mode 2 for missing arrow 3 times
	if(mode==2){
           iClear();
		  iShowBMP(0,0,"gameover.bmp");
		  score=0;
		  
	}

	if(score>280 && arr_counter==5 && level==1){
	  mode=3;
	  mis_arrow=0;
	  arr_counter=0;
	  arr_remain=5;
	  score=0;
	  level=2;
	  dy=15;
	  
	}

	if(mis_arrow<3 && arr_counter==5){
	  mode=4;
	  mis_arrow=0;
	  arr_counter=0;
	  arr_remain=5;
	  
	  
	  
	  
	}

	if(score>280 && arr_counter==5 && level==2){
	  mode=3;
	  mis_arrow=0;
	  arr_counter=0;
	   arr_remain=5;
	  score=0;
	  level=3;
	  dy=25;
	  
	}

	if(mode==3){
	  iClear();
	  iShowBMP(0,0,"nextlvl.bmp");
	}

	if(mode==4){
	  iClear();
	  iShowBMP(0,0,"nrml.bmp");
	  iSetColor(255,255,255);
	  iText(587,554,"SCORE:",GLUT_BITMAP_TIMES_ROMAN_24);
	  iText(677,554,str,GLUT_BITMAP_TIMES_ROMAN_24);
	  score=0;
	}
}


void arrow(){
	switch(switch_counter){
	case 0:
		{
			if(board_y > 230 && board_y < 410 && t3 ==10){
				
				switch_counter = 2;
				score+=50;
				break;

			}
		   else if(board_y > 250 && (board_y+20) < 410 && t3 ==20){
				
				switch_counter = 3;
				score+=60;
				break;

			}
		   else if(board_y > 270 && (board_y+40) < 410 && t3==30){
				
				switch_counter = 5;
				score+=70;
				break;

			}
		   else if(board_y > 290 && (board_y+60) < 410 && t3 ==40){
				
				switch_counter = 6;
				score+=80;
				break;

			}
		    else if(board_y > 305 && (board_y+75) < 410 && t3==50){
				
				switch_counter = 7;
				score+=100;
				break;

			}
			else if(t1 < 5){
				arr_counter++;
				arr_remain--;
				mis_arrow++;
				switch_counter = 1;
				break;

			}else{
				
				t1 = t1 - z;
				t3 = t3 - x;
				break;

			}
		}
	case 1:
		{
			t1 = 1200;
			t3 = 1000;
			z = 0;
			x = 0;
		
			break;
		}
	case 2:
		{
			t1 = 210;
			t3 = 10;
			counter++;
			if(counter > 15){
			arr_counter++;
			arr_remain--;
				switch_counter = 4;
				counter = 0;

			}
			break;
		}
		case 3:
		{
			t1 = 220;
			t3 = 20;
			counter++;
			if(counter > 15){
			arr_counter++;
			arr_remain--;
				switch_counter = 4;
				counter = 0;

			}
			break;
		}
		case 5:
		{
			t1 = 230;
			t3 = 30;
			counter++;
			if(counter > 15){
			arr_counter++;
			arr_remain--;
				switch_counter = 4;
				counter = 0;

			}
			break;
		}
		case 6:
		{
			t1 = 240;
			t3 = 40;
			counter++;
			if(counter > 15){
			arr_counter++;
			arr_remain--;
				switch_counter = 4;
				counter = 0;

			}
			break;
		}
		case 7:
		{
			t1 = 250;
			t3 = 50;
			counter++;
			if(counter > 15){
			arr_counter++;
			arr_remain--;
				switch_counter = 4;
				counter = 0;

			}
			break;
		}
	case 4:
		{
			t1 = 1200;
			t3 = 1000;
			z = 0;
			x = 0;
			
			switch_counter = 0;
			break;
		}
	default:
		{
			switch_counter++;
			break;
		}
	}
}

void iDraw(){	
	//mode 0 for menu
	if(mode==0){
	iClear();
	iShowBMP(0,0,"fm.bmp");
	}
//mode 1 for game starting
	else if(mode==1){
    iClear();
	iShowBMP(0,0,"1350.bmp");
	iSetColor(150,96,159);
	iFilledRectangle(board_x,board_y,10,180);
	iSetColor(255,150,100);
	iFilledRectangle(board_x+10,board_y+20,10,140);
	iSetColor(0,0,255);
	iFilledRectangle(board_x+20,board_y+40,10,100);
	iSetColor(255,255,0);
	iFilledRectangle(board_x+30,board_y+60,10,60);
	iSetColor(255,10,0);
	iFilledRectangle(board_x+40,board_y+75,10,30);
	
	iSetColor(0,255,255);
	iText(1150,50,"COPYRIGHT",GLUT_BITMAP_9_BY_15);
	iText(1150,38,"Abir(14-01-04-069)",GLUT_BITMAP_9_BY_15);
	iText(1150,26,"Rhythm(14-01-04-070)",GLUT_BITMAP_9_BY_15);

    

	arr(t1, t2, t3, t4);
    }
	
	gameover();


		
	
	
}



void iMouseMove(int mx, int my){
	
}

void iMouse(int button, int state, int mx, int my){
	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("%d %d\n", mx, my);	
		if(mx >= 728 && mx <= 985 && my >= 400 && my <= 454 && mode == 0)
			mode = 1;
		else if(mx >= 731 && mx <= 988 && my >= 269 && my <= 314 && mode == 0)
			exit(0);
		else if(mx >= 553 && mx <= 793 && my >= 320 && my <= 374 && mode == 2)
			mode=1;
		else if(mx >= 553 && mx <= 793 && my >= 234 && my <= 296 && mode == 2)
			exit(0);
		else if(mx >= 526 && mx <= 758 && my >= 340 && my <= 390 && mode == 3)
			mode=1;
		else if(mx >= 526 && mx <= 760 && my >= 2271 && my <= 321 && mode == 3)
			exit(0);
		else if(mx >= 512 && mx <= 781 && my >= 312 && my <= 379 && mode == 4)
			mode=1;
		else if(mx >= 515 && mx <= 781 && my >= 234 && my <= 296 && mode == 4)
			exit(0);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

void iKeyboard(unsigned char key){
	
	if(key == 'p')
	{
		iPauseTimer(0);
	//	iPauseTimer(1);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	//	iResumeTimer(1);
	}
    if(key == 'c')
	{
		if(mode==1){
		z = 10;
		x = 10;
		switch_counter = 0;
		
		}
	}
	
}
void iSpecialKeyboard(unsigned char key){

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}
void boardchange(){
    if(mode==1){
	board_y+=dy;
	 if(board_y >520 || board_y < 0)dy = -dy;
	}
}




int main(){ 

	mode=0;
    
	dy=10;

	iSetTimer(100, boardchange);
	
	

	
	
	iSetTimer(5, arrow);
	iInitialize(1350, 699, "Archery");
  
	return 0;
}	