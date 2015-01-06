#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
//PLAY BÖLÜMÜNE GEÇÝLDÝKTEN SONRA OK TUÞLARINA BASILDIGI GÝBÝ ÇÝZDÝRME BAÞLAR
int main (void)
{
FILE *dhiz,*dyon,*test,*highscore;
srand(time(NULL));
int rastgele=0,rastgele2=0,i=0;
char kat1[8];
char satir[4],satir2[4];
char *psatir = satir;
int player1lives=3,player2lives=3;
int bina1x=0;
int bina1y=0;
int bina2x=0;
int bina2y=0;
int width = 800;
int height = 600;
int x = 0;
int y = 0;
int gosterge = 0;
int yon = 0;
int hiz = 0;
int sayac = 0;

bool quit = false;
bool pass = true;
bool ciz = false;
bool kontrol = false;
bool tekrar = true;
bool atesle = false;
bool giris = true;



al_init();//allegro addonlarýnýn eklenmesi
al_init_primitives_addon();
al_install_mouse();
al_install_keyboard();
al_init_image_addon();
al_init_font_addon();
al_init_ttf_addon();
al_install_audio();
al_init_acodec_addon();
al_reserve_samples(1);

ALLEGRO_DISPLAY *display = NULL;//allegro deðiþkenlerinin tanýmlanmasý
ALLEGRO_SAMPLE *sample=NULL;
ALLEGRO_EVENT_QUEUE *event;
ALLEGRO_TIMER *timer = 0;
ALLEGRO_SAMPLE *hitSound;
ALLEGRO_FONT *Font;
ALLEGRO_BITMAP *background1,*background2,*background3,*player1,*player2,*bina1,*bina2,*top;

	
Font = al_load_font("Hachicro.ttf", 20, 0);//deðiþkenlerin yüklenmesi
event = al_create_event_queue();
display = al_create_display(width, height);
sample = al_load_sample( "bsound.wav" );
background1 = al_load_bitmap("background.jpg");
background2 = al_load_bitmap("background2.jpg");
background3 = al_load_bitmap("background3.jpg");
player1 = al_load_bitmap("player1.png");
player2 = al_load_bitmap("player2.png");
top = al_load_bitmap("top.png");

al_register_event_source(event, al_get_mouse_event_source());//register hazýrlanmasý
al_register_event_source(event, al_get_keyboard_event_source());
al_register_event_source(event, al_get_display_event_source(display));

/////////////////////////ATIS DEGÝSKENLERÝ
double topx = 100.0;
double topy = 100.0;//baþlangýç degerleri
double ay;
float xsurat =(float) (hiz * cos(yon));//
float ysurat =(float) (hiz * sin(yon));//45 derece kalsýn sabit y 
double zamandegisimi = 0.1;


///////////////////////////////////////7


al_draw_bitmap(background1, 0, 0, 0);
al_flip_display();

while(!quit)//Ýþlemlerin çalýþtýgý döngü
{
	ALLEGRO_EVENT ev;//olay tanýmlanýyor listenerlarýmýz için
	al_wait_for_event(event, &ev);//olay için bekleniyor
	
	al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);//sarký caldýrýlýyor.
	
	//KONTROLLER	
	
	if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
		{
			quit = true;
		} 
		
	if(giris==true){//Bir ekrana gidildiðinde bir daha gidilmemesi için olan bool
		
	 if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (ev.mouse.button & 2)
				quit = true;
		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			x = ev.mouse.x;
			y = ev.mouse.y;
		}
				
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) 
    	{
    		switch(ev.keyboard.keycode)
    		{
    			case ALLEGRO_KEY_ESCAPE:
                quit=true;
				break;
				
            	case ALLEGRO_KEY_DOWN:
          	    hiz-=5;
          	    dhiz = fopen("hiz.txt","w");
          	    fprintf(dhiz,"%d\n",hiz%100);
          	    fclose(dhiz);
          	    kontrol=true;
				break;   
				              
          	  	case ALLEGRO_KEY_UP:
                hiz+=5;
				dhiz = fopen("hiz.txt","w");
          	    fprintf(dhiz,"%d\n",hiz%100);
          	    fclose(dhiz);
				kontrol=true;  
				break;    
				          
         	   	case ALLEGRO_KEY_LEFT:
               	yon+=5;
				dyon = fopen("yon.txt","w");  
				fprintf(dyon,"%d\n",yon%180);  
				fclose(dyon);
				kontrol=true;  
			   	break;     
				          
        		case ALLEGRO_KEY_RIGHT://dosyalarý açýp bilgileri güncelle
                yon-=5;
                dyon = fopen("yon.txt","w");  
				fprintf(dyon,"%d\n",yon%180);  
				fclose(dyon);
				kontrol=true;  
				break;     
				            
         	   	case ALLEGRO_KEY_SPACE://ateþle
				atesle=true;
				break; 
					
    		}
		}
		else if(kontrol==true)
		{
			dhiz = fopen("hiz.txt","r");
			dyon = fopen("yon.txt","r");  
			al_clear_to_color(al_map_rgb(255, 255, 255));
   			al_flip_display();
   				
   			al_draw_bitmap(background2, 0, 0, 0);
			al_flip_display();  
			
			
   				
   			for(i=0;i<2;i++)
			{
   				fscanf(dhiz, "%[^\n]", satir);
   				fscanf(dyon,"%[^\n]", satir2);
   				
   				if(strcmp(kat1,"kat1.png")==0)
			{
				al_draw_bitmap(bina1,bina1x,525,0);
				al_flip_display();
				
				al_draw_bitmap(bina2,bina2x,525,0);
				al_flip_display();
				
				al_draw_bitmap(player1,bina1x+32,440,0);
				al_flip_display();
				
				al_draw_bitmap(player2,bina2x+32,440,0);
				al_flip_display();
				bina1y=440;
				bina2y=440;
			}
			else if(strcmp(kat1,"kat2.png")==0){
				al_draw_bitmap(bina1,bina1x,450,0);
				al_flip_display();
				
				al_draw_bitmap(bina2,bina2x,450,0);
				al_flip_display();	
				
				al_draw_bitmap(player1,bina1x+32,365,0);
				al_flip_display();
				
				al_draw_bitmap(player2,bina2x+32,365,0);
				al_flip_display();
				bina1y=365;
				bina2y=365;			
			}
			else if(strcmp(kat1,"kat3.png")==0){
				al_draw_bitmap(bina1,bina1x,375,0);
				al_flip_display();
				
				al_draw_bitmap(bina2,bina2x,375,0);
				al_flip_display();		
				
				al_draw_bitmap(player1,bina1x+32,290,0);
				al_flip_display();
				
				al_draw_bitmap(player2,bina2x+32,290,0);
				al_flip_display();
				bina1y=290;
				bina2y=290;		
			}
			else if(strcmp(kat1,"kat4.png")==0){
				al_draw_bitmap(bina1,bina1x,300,0);
				al_flip_display();
				
				al_draw_bitmap(bina2,bina2x,300,0);
				al_flip_display();
				
				al_draw_bitmap(player1,bina1x+32,215,0);
				al_flip_display();
				
				al_draw_bitmap(player2,bina2x+32,215,0);
				al_flip_display();
				bina1y=215;
				bina2y=215;
				}	
   				
   				
   				
   			
    			al_draw_text(Font,al_map_rgb(255,255,255),0,0,0,satir);//HIZ
    			al_flip_display();
    			al_draw_text(Font,al_map_rgb(255,255,255),0,20,0,satir2);//Yon
    			al_flip_display();
   			}
			fclose(dhiz);
			fclose(dyon);
			remove("hiz.txt");
			remove("yon.txt");
			kontrol=false;
			
			
		}
	}
	while(atesle==true)//space e basýnca tetiklenen kýsým
	{
		topx=topx+xsurat;
		ay=(double)ysurat/zamandegisimi;
		topy+=topy*zamandegisimi+(0.5*ay*zamandegisimi*zamandegisimi);
				//al_draw_bitmap(top, topx, topy, 0);
	
		al_draw_circle(topx,topy,4,al_map_rgb(255,255,255),10);
		al_flip_display();
		
		
		if(topx>800 || topy>600){
		atesle=false;
		break;
		}
	}
	
	if(pass==true && x>300 && x<475 && y>150 && y<185)//PLAY BÖLÜMÜ
	{
		if(ev.mouse.button & 1)
		{
			pass=false;
			
			
			bina1x=rand()%250;//Elimizdeki bina xleri 150 oldugundan tam ortadan 400 er piksel kalýr iki binaya da soldaki bina 400 - 150 = 250. piksele kadar gelir maksimum.
   			bina2x=rand()%300+350;
   			
   			
			
			if(tekrar==true)
			{
			tekrar=false;
			al_clear_to_color(al_map_rgb(255, 255, 255));
   			al_flip_display();
   			
			al_draw_bitmap(background2, 0, 0, 0);
			al_flip_display();
			
			rastgele=rand()%4 + 1;
			sprintf(kat1,"kat%d.png",rastgele);
			
			bina1 = al_load_bitmap(kat1);
			bina2 = al_load_bitmap(kat1);
			
			}
			
			
			
			
			
			
		}
	}
	
	else if(pass==true && x>235 && x<570 && y>250 && y<285)//HIGHSCORE BÖLÜMÜ
	{
		if(ev.mouse.button & 1){
		pass=false;
		kontrol=false;
		giris=false;
		al_clear_to_color(al_map_rgb(255, 255, 255));
   		al_flip_display();
		al_draw_bitmap(background3, 0, 0, 0);
		al_flip_display();
		
		highscore = fopen("highscore.txt","r");
		
		for(i=0;i<2;i++)//Highscore.txt den bilgilerin çekilmesi
		{
			fscanf(highscore, "%[^\n]", psatir);
			al_draw_text(Font,al_map_rgb(255,255,255),325,300,0,satir);
			al_flip_display();
		}
		
		
		}
		
	}
	
	else if(pass==true && x>300 && x<475 && y>350 && y<385)//EXIT!
	{
		if(ev.mouse.button & 1)
		quit = true;
	}
	
	




}
remove("hiz.txt");
remove("yon.txt");
al_destroy_event_queue(event);
al_destroy_bitmap(background1);
al_destroy_display(display);

return 0;
}
