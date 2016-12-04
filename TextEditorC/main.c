#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

struct harf{
    int veri;
    struct harf *onceki;
    struct harf *sonraki;
}*gezici;

struct satir{
    struct harf *ilk;
    struct harf *son;
    int satirUzunlugu;

    struct satir *onceki;
    struct satir *sonraki;
}*ilkSatir=NULL,*sonSatir=NULL,*geziciSatir=NULL;

void imlecTasi(char nereye);

void harfBasaEkle(int data){
    struct harf *yeni = malloc(sizeof(struct harf));
    int tmpy = wherey();
    yeni->veri = data;
if(geziciSatir->ilk == NULL){
    yeni->onceki = NULL;
    yeni->sonraki = NULL;
    geziciSatir->ilk = geziciSatir->son = gezici = yeni;
    geziciSatir->satirUzunlugu++;

    ekranaBas();
    gotoxy(2,tmpy);

}else{
    yeni->onceki = NULL;
    geziciSatir->ilk->onceki = yeni;
    yeni->sonraki = geziciSatir->ilk;
    geziciSatir->ilk = yeni;
    gezici = geziciSatir->ilk;
    geziciSatir->satirUzunlugu++;
   // gotoxy(wherex()-1,wherey());
    ekranaBas();
    gotoxy(1,tmpy);
    //imlecTasi('L');
}

}

void harfSonaEkle(int data){
    struct harf *yeni = malloc(sizeof(struct harf));
    yeni->veri = data;
int tmpx = wherex(); int tmpy = wherey();
    if(geziciSatir->son == gezici){
        if(gezici->veri == 10){
            if(gezici != geziciSatir->ilk){
            yeni->onceki = gezici->onceki;
            yeni->sonraki = gezici;
            gezici->onceki->sonraki = yeni;
            gezici->onceki = yeni;
            geziciSatir->satirUzunlugu++;
            //gotoxy(wherex()+1,wherey());
            ekranaBas();
            gotoxy(tmpx+1,tmpy);
            }else if(gezici == geziciSatir->ilk){
              yeni->onceki = NULL;
              yeni->sonraki = gezici;
              gezici->onceki = yeni;
              geziciSatir->ilk = yeni;
              geziciSatir->satirUzunlugu++;
              ekranaBas();
              gotoxy(tmpx+1,tmpy);
            }

        }else{
          yeni->sonraki = NULL;
          yeni->onceki = gezici;
          gezici->sonraki = yeni;
          geziciSatir->son = yeni;
          gezici = yeni;
          geziciSatir->satirUzunlugu++;

           ekranaBas();
        }

    }

}

void harfArayaEkle(int data){
    struct harf *yeni = malloc(sizeof(struct harf));
    yeni->veri = data;
    int tmpx = wherex(); int tmpy = wherey();
    if(gezici != geziciSatir->ilk && gezici != geziciSatir->son){
        yeni->onceki = gezici->onceki;
        yeni->sonraki = gezici;
        gezici->onceki->sonraki = yeni;
        gezici->onceki = yeni;
        geziciSatir->satirUzunlugu++;
        gezici = yeni;

         ekranaBas();
         gotoxy(tmpx,tmpy);

    }

}

void harfSil(){
    struct harf *silincek;

int tmpx = wherex(); int tmpy = wherey();
    if(gezici==geziciSatir->son && gezici->veri == 10 && gezici != NULL ){
       if(geziciSatir->satirUzunlugu>2){
        silincek = gezici->onceki;
        silincek->onceki->sonraki = gezici;
        gezici->onceki = silincek->onceki;
        free(silincek);
        geziciSatir->satirUzunlugu--;
        ekranaBas();
        gotoxy(tmpx-1,tmpy);
       }else if(geziciSatir->satirUzunlugu == 2){
        silincek = gezici->onceki;
        geziciSatir->ilk = gezici;
        geziciSatir->son = gezici;
        gezici->onceki = NULL;
        gezici->sonraki = NULL;
        geziciSatir->satirUzunlugu--;
        free(silincek);
        ekranaBas();
        gotoxy(tmpx-1,tmpy);
       }


    }else if(gezici == geziciSatir->son && gezici != geziciSatir->ilk && gezici->veri != 10){
        silincek = gezici;
        silincek->onceki->sonraki = NULL;
        gezici = silincek->onceki;
        geziciSatir->son = gezici;
        geziciSatir->satirUzunlugu--;
        free(silincek);
         ekranaBas();
        gotoxy(tmpx-1,tmpy);
    }else if(gezici == geziciSatir->ilk && gezici == geziciSatir->son && gezici->veri == 10 &&geziciSatir->satirUzunlugu == 1 && geziciSatir != ilkSatir){
        silincek = gezici;
        free(silincek);
        satirSil();

    }else if(gezici == geziciSatir->ilk && gezici->veri != 10){
        silincek = gezici;
        if(geziciSatir->satirUzunlugu != 1){
            silincek->sonraki->onceki = NULL;
            geziciSatir->ilk = silincek->sonraki;
            gezici=geziciSatir->ilk;
            geziciSatir->satirUzunlugu--;
            free(silincek);
            ekranaBas();
            gotoxy(tmpx,tmpy);
        }else if(geziciSatir->satirUzunlugu == 1){
            silincek->onceki = NULL;
            silincek->sonraki = NULL;
            gezici = NULL;
            geziciSatir->ilk = NULL;
            geziciSatir->son = NULL;
            geziciSatir->satirUzunlugu--;
            free(silincek);
            ekranaBas();
            gotoxy(tmpx-1,tmpy);
        }

    }else if (gezici != geziciSatir->ilk && gezici != geziciSatir->son && gezici!=NULL){
        silincek = gezici;
        silincek->onceki->sonraki = silincek->sonraki;
        silincek->sonraki->onceki = silincek->onceki;
        geziciSatir->satirUzunlugu--;
        gezici = gezici->onceki;
        ekranaBas();
        gotoxy(tmpx-1,tmpy);
        free(silincek);
    }

}

void satirBasaEkle(){
    struct satir *yeni = malloc(sizeof(struct satir));
    yeni->ilk = NULL;
    yeni->son = NULL;
    gezici = NULL;
    yeni->satirUzunlugu = 0;

    if(ilkSatir == NULL){
        yeni->onceki = NULL;
        yeni->sonraki = NULL;
        ilkSatir = sonSatir = geziciSatir = yeni;

    }else{
        yeni->onceki = NULL;
        yeni->sonraki = ilkSatir;
        ilkSatir->onceki = yeni;
        ilkSatir = yeni;
        geziciSatir = ilkSatir;
        imlecTasi('U');

    }

}

void satirSonaEkle(){
    struct satir *yeni = malloc(sizeof(struct satir));

int tmpy = wherey();
        yeni->ilk = NULL;
        yeni->son = NULL;
        gezici = NULL;
        yeni->satirUzunlugu = 0;
        yeni->onceki = geziciSatir;
        yeni->sonraki = NULL;
        geziciSatir->sonraki = yeni;
        sonSatir = yeni;
        geziciSatir = sonSatir;
        ekranaBas();

        //gotoxy(1,tmpy+1);
        //imlecTasi('D');


}

void satirArayaEkle(){
    struct satir *yeni = malloc(sizeof(struct satir));
int tmpx = wherex(); int tmpy = wherey();
    if(geziciSatir->sonraki != NULL){
      yeni->ilk = NULL;
      yeni->son = NULL;
      gezici = NULL;
      yeni->satirUzunlugu = 0;

      yeni->onceki = geziciSatir;
      yeni->sonraki = geziciSatir->sonraki;
      geziciSatir->sonraki->onceki = yeni;
      geziciSatir->sonraki = yeni;
      geziciSatir = yeni;
      harfBasaEkle(10);
       ekranaBas();
       gotoxy(1,tmpy+1);

     // imlecTasi('D');
    }

}

void satirSil(){
    struct satir *silincek;
int tmpy = wherey();
    if(geziciSatir == sonSatir && geziciSatir != ilkSatir && geziciSatir != NULL){
        silincek = geziciSatir;
        silincek->onceki->sonraki = NULL;

        geziciSatir = silincek->onceki;
        sonSatir = geziciSatir;
        free(silincek);
        gezici = geziciSatir->son;
        ekranaBas();
        gotoxy(geziciSatir->satirUzunlugu,tmpy-1);

    }else if(geziciSatir != sonSatir && geziciSatir !=ilkSatir && geziciSatir != NULL){
        silincek = geziciSatir;
        silincek->onceki->sonraki = silincek->sonraki;
        silincek->sonraki->onceki = silincek->onceki;

        geziciSatir = silincek->onceki;
        free(silincek);
        gezici = geziciSatir->son;
        ekranaBas();
        gotoxy(geziciSatir->satirUzunlugu,tmpy-1);
    }


}

void ekranaBas(){
    struct satir *geciciSatir = ilkSatir;
    struct harf  *geciciHarf;
    clrscr();

    while(geciciSatir != NULL){
       for(geciciHarf=geciciSatir->ilk;geciciHarf!=NULL;geciciHarf=geciciHarf->sonraki){
          if(geciciHarf->veri == 10)
             printf("\n");
           else
             printf("%c",geciciHarf->veri);
       }
       geciciSatir = geciciSatir->sonraki;
    }

}

void imlecTasi(char nereye){
int tmpx = wherex(); int tmpy = wherey();
    if(nereye == 'R'){
       if(gezici->sonraki != NULL){
        gezici = gezici->sonraki;
        gotoxy(tmpx+1,tmpy);
       }else if(gezici->sonraki == NULL && gezici == geziciSatir->son && tmpx == geziciSatir->satirUzunlugu){
        gotoxy(tmpx+1,tmpy);
       }
    }else if(nereye == 'L'){
       if(gezici == geziciSatir->ilk){
          if(geziciSatir != ilkSatir){
            geziciSatir = geziciSatir->onceki;
            gezici = geziciSatir->son;
            gotoxy(geziciSatir->satirUzunlugu,tmpy-1);
          }
       }else{
       if(gezici->onceki != NULL){
          if(gezici == geziciSatir->son && tmpx>geziciSatir->satirUzunlugu){
            gotoxy(wherex()-1,tmpy);
          }else{
            gezici = gezici->onceki;
            gotoxy(wherex()-1,tmpy);
           }
         }
       }
    }else if(nereye == 'U'){
         if(geziciSatir->onceki != NULL){

            if(tmpx>=geziciSatir->onceki->satirUzunlugu){
               geziciSatir = geziciSatir->onceki;
               gezici = geziciSatir->son;
               gotoxy(geziciSatir->satirUzunlugu,tmpy-1);
            }else{
               geziciSatir = geziciSatir->onceki;
               gezici = geziciSatir->ilk;
               for(int i = 1;i<tmpx;i++){
                gezici = gezici->sonraki;
                gotoxy(i+1,tmpy-1);
               }
            }
         }
    }else if(nereye == 'D'){
        if(geziciSatir->sonraki != NULL){

            if(tmpx>=geziciSatir->sonraki->satirUzunlugu){
               geziciSatir = geziciSatir->sonraki;
               gezici = geziciSatir->son;
               if(geziciSatir->satirUzunlugu == 0)
                gotoxy(1,tmpy+1);
               else
                gotoxy(geziciSatir->satirUzunlugu,tmpy+1);
            }else{
               geziciSatir = geziciSatir->sonraki;
               gezici = geziciSatir->ilk;
               for(int i = 1;i<tmpx;i++){
                gezici = gezici->sonraki;
                gotoxy(i+1,tmpy+1);
               }
            }
        }
    }

}


int main()
{
    _setcursortype(_SOLIDCURSOR);
   textbackground(WHITE);
   textcolor(BLACK);
    int tus;

    satirBasaEkle();

    while(1){

    tus = _getch();


    if(tus>31 && tus<127){

    if(GetAsyncKeyState(VK_LEFT)){
        imlecTasi('L');
        continue;
    }else if(GetAsyncKeyState(VK_RIGHT)){
        imlecTasi('R');
        continue;
    }else if(GetAsyncKeyState(VK_UP)){
        imlecTasi('U');
        continue;
    }else if(GetAsyncKeyState(VK_DOWN)){
       imlecTasi('D');
       continue;
    }else{

       if(gezici == geziciSatir->ilk && gezici == geziciSatir->son && geziciSatir->satirUzunlugu == 0){
           harfBasaEkle(tus);
        }else if(gezici == geziciSatir->ilk && gezici != geziciSatir->son && geziciSatir->satirUzunlugu!=0){
          harfBasaEkle(tus);
        }else if(gezici == geziciSatir->son){
          harfSonaEkle(tus);
        }else if(gezici != geziciSatir->ilk && gezici != geziciSatir->son){
          harfArayaEkle(tus);
        }
     }
    }

    if(tus == 8){
      if(gezici == NULL && geziciSatir != ilkSatir && gezici == geziciSatir->ilk && gezici == geziciSatir->son && geziciSatir != ilkSatir){
        satirSil();
      }else if(gezici->veri == 10 && gezici == geziciSatir->ilk && gezici == geziciSatir->son && geziciSatir != ilkSatir){
        satirSil();
      }else{
        harfSil();
      }

    }

    if(tus == 13){
       if(geziciSatir == ilkSatir){
          if(geziciSatir != sonSatir && gezici == geziciSatir->son){
            if(gezici->veri != 10)
            harfSonaEkle(10);

            satirArayaEkle();
          }else if(gezici == geziciSatir->ilk){
            harfSonaEkle(10);
            satirBasaEkle();
          }else if(geziciSatir == sonSatir && gezici == geziciSatir->son){
            if(gezici->veri != 10)
            harfSonaEkle(10);

            satirSonaEkle();
          }
       }else if(geziciSatir == sonSatir && gezici==geziciSatir->son){
          if(gezici->veri != 10)
            harfSonaEkle(10);

          satirSonaEkle();
       }else if(geziciSatir != ilkSatir && geziciSatir != sonSatir && gezici == geziciSatir->son){
          if(gezici->veri !=10)
            harfSonaEkle(10);

            satirArayaEkle();
       }

    }

tus = 0;
    } /// while bitis

    return 0;
}
