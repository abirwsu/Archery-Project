# include "iGraphics.h"

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

void arr(int p,int q,int r,int y){	
	
	iSetColor(255,255,255);
	iLine(p,q,r,y);
	double xa[]={r,r+12,r+12};
	double ya[]={y,y+4,y-4};
	iFilledPolygon(xa,ya,3);
	
}
void arrow(){
	switch(switch_counter){
	case 0:
		{
			if(board_y > 230 && board_y < 410 && t3 == 10){
				
				switch_counter = 2;
				break;

			}
		   else if(board_y > 250 && (board_y+20) < 410 && t3 < 19 && t3 >30){
				
				switch_counter = 3;
				break;

			}
		   else if(board_y > 270 && (board_y+40) < 410 && t3 == 30){
				
				switch_counter = 5;
				break;

			}
		   else if(board_y > 290 && (board_y+60) < 410 && t3 == 40){
				
				switch_counter = 6;
				break;

			}
		    else if(board_y > 305 && (board_y+75) < 410 && t3 == 50){
				
				switch_counter = 7;
				break;

			}
			else if(t1 < 5){
				
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
	
	iClear();
	
	iShowBMP(0,0,"1234.bmp");
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
//	iText(1150,50,"COPYRIGHT",GLUT_BITMAP_9_BY_15);
	iText(1150,38,"Abir(14-01-04-069)",GLUT_BITMAP_9_BY_15);
	iText(1150,26,"Rhythm(14-01-04-070)",GLUT_BITMAP_9_BY_15);

	arr(t1, t2, t3, t4);
		iShowBMP(1094,260,"windd.bmp");
	
	
}


void iMouseMove(int mx, int my){
	
}

void iMouse(int button, int state, int mx, int my){
	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
			
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
		z = 15;
		x = 15;
		switch_counter = 0;
	}
	if (key == 'v'){
		}
}
void iSpecialKeyboard(unsigned char key){

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
}
void boardchange(){
     board_y+=dy;
	 if(board_y >520 || board_y < 0)dy = -dy;
}

int main(){ 
	
	iSetTimer(100, boardchange);
	dy=10;
	iSetTimer(1, arrow);
	iInitialize(1350, 699, "Archery");
  
	return 0;
}	