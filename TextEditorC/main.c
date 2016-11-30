///Ufuk Demir - Mert eroglu Prolab
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

///---------------------------------------------------------///

#define max_lenght 120
#define max_height 30

///---------------------------------------------------------///

typedef struct node{
char data;
struct node *onceki;
struct node *sonraki;
};


void Listele(struct node *bas);

void basaEkle(struct node **bas,struct node **son,char veri){
struct node *yeni = malloc(sizeof(struct node));
yeni->data = veri;
 if(*bas == NULL){  /// Listede eleman yoksa
    yeni->sonraki = NULL;
    yeni->onceki = NULL;
    *bas=*son=yeni;
 }else{
 yeni->sonraki = *bas;
 yeni->onceki = NULL;
 *bas = yeni;
 }

}

void sonaEkle(struct node **bas,struct node **son,char veri){
struct node *yeni = malloc(sizeof(struct node));
yeni->data = veri;
  if(*bas == NULL){ /// Liste bos ise
    yeni->sonraki = NULL;
    yeni->onceki = NULL;
    *bas=*son=yeni;
  }else{
  yeni->sonraki = NULL;
  yeni->onceki = (*son);
  (*son)->sonraki = yeni;
  (*son) = yeni;
  }
}

void arayaEkle(struct node **ara,char veri){
    struct node *yeni = malloc(sizeof(struct node));
    yeni->data = veri;
    yeni->onceki = (*ara)->onceki;
    yeni->sonraki = (*ara);
    (*ara)->onceki->sonraki = yeni;
    (*ara)->onceki = yeni;
}


void Listele(struct node *bas){
struct node *gecici = (struct node*)malloc(sizeof(struct node));
gecici = bas;
while(gecici != NULL){
  printf("%c",gecici->data);
    gecici = gecici->sonraki;
}

}

void Ekrani_Ciz(){
gotoxy(0,0);
printf("%c",201);
for(int i = 1;i<119;i++){
    gotoxy(i,0);
    printf("%c",205);
}
gotoxy(0,119);
printf("%c",187);

gotoxy(1,0);
printf("%c",186);
gotoxy(1,3);
printf("%c",186);
gotoxy(1,4);
printf("%c",186);



gotoxy(120,2);
printf("%c",186);
gotoxy(120,3);
printf("%c",186);
gotoxy(120,4);
printf("%c",186);


gotoxy(0,5);
printf("%c",200);
gotoxy(120,5);
printf("%c",188);

for(int i = 2;i<120;i++){
    gotoxy(i,5);
    printf("%c",205);
}


gotoxy(2,3);
printf("F1-Open");

gotoxy(10,3);
printf("F2-Save");

gotoxy(1,6);
}



void main()
{
Ekrani_Ciz(); /// Test Amacli Sonra kaldirabiliriz

struct node *ilk = NULL;
struct node *son = NULL;
struct node *gezici = NULL;

//ilk = (struct node*)malloc(sizeof(struct node));
//ilk->sonraki = NULL;
//son = ilk;
//gezici = son;

int tus=0; /// basilan tusu alacagimiz degisken
int tus2=0; /// ilk tus shift ctrl gibi ise bunu kullanýcaz



while(1){

tus = _getch(); /// ilk tusu al

if(tus==0) /// Kontrol et eger shift ctrl gibi ise ikinci tusu bekle
  tus2 = _getch();




if(tus==0 && tus2 == 45) /// kisa cizgi basildiysa kapat
    exit(0);


if(tus > 31 && tus < 127 )  {

      if(GetAsyncKeyState(VK_LEFT)){

        if(wherex()>0 && gezici->onceki != NULL){
            gezici = gezici->onceki;
            gotoxy(wherex()-1,wherey());
        }

      }else if(GetAsyncKeyState(VK_RIGHT)){

        if(wherex()<120 && gezici->sonraki != NULL){
            gotoxy(wherex()+1,wherey());
            gezici = gezici->sonraki;
        }

      }else if(GetAsyncKeyState(VK_UP)){

          if(wherey()>6){  /// Daha sonra satirlari baglama gelince kontrol geliscek :D
         gotoxy(wherex(),wherey()-1);
          }

      }else if(GetAsyncKeyState(VK_DOWN)){

         gotoxy(wherex(),wherey()+1);

      }else{

      if(gezici == son){ /// Gezici yeri kontrolu ozel yerler bas ve son ise ona gore islem yap
        sonaEkle(&ilk,&son,tus);
        gezici=son;
        clrscr();
        Listele(ilk);
      } else if(gezici == ilk){
        int x,y;
          x = wherex();
          y = wherey();
        basaEkle(&(ilk->sonraki),&son,tus);
        gezici = ilk;
        clrscr();
        Listele(ilk);
        gotoxy(x,y);
      }else{
          int x,y;
          x = wherex();
          y = wherey();
       arayaEkle(&(gezici->sonraki),tus);
         clrscr();
      Listele(ilk);
      // gezici = gezici->onceki;
      gotoxy(x,y);
      }

   // printf("%c",tus);

    } /// en son else in bitisi
} /// Tus 31-127 aralik kontrol bitisi

if(tus == 128){   /// C nin noktalisi :D
    printf("\n");
    Listele(ilk); /// bagli liste ne durumda kontrol icin
}




} /// While bitis




_getch();
}

