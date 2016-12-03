///Ufuk Demir - Mert eroglu Prolab
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
///---------------------------------------------------------///

#define max_lenght 120
#define max_height 30

///---------------------------------------------------------///

typedef struct node{
    char data;
    struct node *onceki;
    struct node *sonraki;
};

typedef struct satirlar{
    struct node *ilk;
    struct node *son;
    int satirUzunlugu;

    struct satirlar *onceki;
    struct satirlar *sonraki;

};

void Listele(struct satirlar *ilksatir);

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
        (*bas)->onceki = yeni;
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

void Listele(struct satirlar *ilksatir){
    struct node *gecici = (struct node*)malloc(sizeof(struct node));
    struct satirlar *satirGecici = malloc(sizeof(struct satirlar));
    satirGecici = ilksatir;

    while(satirGecici != NULL){
        for(gecici=satirGecici->ilk;gecici!=NULL;gecici=gecici->sonraki){
            if(gecici->data == 10){
                printf("\n");
            }else{
                printf("%c",gecici->data);
            }

        }
        satirGecici = satirGecici->sonraki;
    }

    /*
    while(gecici != NULL){
        printf("%c",gecici->data);
        gecici = gecici->sonraki;
    }
    */

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

void elemansil(struct node **silinecek,struct node **bas,struct node **son,int counter){

    struct node *temp = malloc(sizeof(struct node));
    temp=*silinecek;

    if((*silinecek)->onceki!=NULL&&(*silinecek)->sonraki!=NULL){
        (*silinecek)=(*silinecek)->onceki;
        (*silinecek)->sonraki=temp->sonraki;
        (*silinecek)->sonraki->onceki=temp->onceki;
        free(temp);
    }
    else if((*silinecek)==(*bas)&&(counter==2)){
        (*silinecek)=temp->sonraki;
        (*bas)=(*silinecek);
        (*bas)->onceki=NULL;
        (*silinecek)->onceki=NULL;
        (*silinecek)->sonraki=NULL;
        (*silinecek)->onceki=NULL;
        (*bas)=(*son)=(*silinecek);
        free(temp);
    }
    else if((*silinecek)==(*son)&&(counter==2)){
        (*silinecek)=temp->onceki;
        (*son)=(*silinecek);
        (*son)->sonraki=NULL;
        (*silinecek)->sonraki=NULL;
        (*silinecek)->onceki=NULL;
        (*silinecek)->sonraki=NULL;
        (*bas)=(*son)=(*silinecek);
        free(temp);
    }
    else if((*silinecek)==(*son)&&(counter>2)){
        (*silinecek)=temp->onceki;
        (*son)=(*silinecek);
        (*son)->sonraki=NULL;
        (*silinecek)->sonraki=NULL;
        (*silinecek)->onceki=temp->onceki->onceki;
        (*silinecek)->onceki->sonraki=(*silinecek);
        free(temp);
    }
    else if((*silinecek)==(*bas)&&(counter>2)){
        (*silinecek)=temp->sonraki;
        (*bas)=(*silinecek);
        (*bas)->onceki=NULL;
        (*silinecek)->onceki=NULL;
        (*silinecek)->sonraki=temp->sonraki->sonraki;
        (*silinecek)->sonraki->onceki=(*silinecek);
        free(temp);
    }
    else if (*silinecek == NULL) {

	}
	else if (*bas == *son) {
	    (*silinecek)->sonraki=NULL;
		(*silinecek)->onceki=NULL;
		free(*silinecek);
		*silinecek=*bas = *son = NULL;
	}

}

void satirBasaEkle(struct node **ilk,struct node **son,struct satirlar **ilkSatir,struct satirlar **sonSatir){
    struct satirlar *yeni = malloc(sizeof(struct satirlar));
    yeni->ilk = (*ilk);
    yeni->son = (*son);
    if(*ilkSatir == NULL){
        yeni->onceki = NULL;
        yeni->sonraki = NULL;
        (*ilkSatir) = (*sonSatir) = yeni;
    }else{
        yeni->sonraki = (*ilkSatir);
        yeni->onceki = NULL;
        (*ilkSatir)->onceki = yeni;
        (*ilkSatir) = yeni;
    }
}

void satirSonaEkle(struct node **ilk,struct node **son,struct satirlar **ilkSatir,struct satirlar **sonSatir){
    struct satirlar *yeni = malloc(sizeof(struct satirlar));

    yeni->ilk = (*ilk);
    yeni->son = (*son);

    if(*ilkSatir == NULL){
        yeni->onceki = NULL;
        yeni->sonraki = NULL;
        (*ilkSatir) = (*sonSatir) = yeni;
    }else{
        yeni->onceki = *sonSatir;
        yeni->sonraki = NULL;
        (*sonSatir)->sonraki = yeni;
        (*sonSatir) = yeni;
    }
}

void satirArdinaEkle(struct node **ilk,struct node **son,struct satirlar **suankiSatir){
    struct satirlar *yeni = malloc(sizeof(struct satirlar));
    yeni->ilk = (*ilk);
    yeni->son = (*son);

    yeni->sonraki = (*suankiSatir)->sonraki;
    yeni->onceki = (*suankiSatir);
    (*suankiSatir)->sonraki->onceki = yeni;
    (*suankiSatir)->sonraki = yeni;
    (*suankiSatir) = yeni;
}

void imlecTasi(struct satirlar **suanKiSatir,struct node **yeniIlk,struct node **yeniSon,struct node **yeniGezici,int suanKiX,int suanKiY,boolean yukariMi){

    if(yukariMi == true){
        *suanKiSatir = (*suanKiSatir)->onceki;
        (*yeniIlk) = (*suanKiSatir)->ilk;
        (*yeniSon) = (*suanKiSatir)->son;
        (*yeniGezici) = (*yeniIlk);
        gotoxy(1,wherey()-1);

        for(int i = 2;i<=suanKiX;i++){

            if((*suanKiSatir)->satirUzunlugu==i){
                break;
            }

            if((*yeniGezici)->sonraki == NULL || ((*yeniGezici)->data) == 10)
                break;

            (*yeniGezici) = (*yeniGezici)->sonraki;
             gotoxy(i,wherey());
       }

    }else{
             ///UFUK DEMİR OZEL MULKU ISGAL EDİLDİ

        *suanKiSatir = (*suanKiSatir)->sonraki;
        (*yeniIlk) = (*suanKiSatir)->ilk;
        (*yeniSon) = (*suanKiSatir)->son;
        (*yeniGezici) = (*yeniIlk);
        gotoxy(1,wherey()+1);

        for(int i = 2;i<=suanKiX;i++){

            if((*suanKiSatir)->satirUzunlugu==i){
                break;
            }
            if((*yeniGezici)->sonraki == NULL || ((*yeniGezici)->data) == 10)
                break;

            (*yeniGezici) = (*yeniGezici)->sonraki;
            gotoxy(i,wherey());

       }

    }

}

void main(){
    Ekrani_Ciz(); /// Test Amacli Sonra kaldirabiliriz
    _setcursortype(_SOLIDCURSOR);
    struct node *ilk = NULL;
    struct node *son = NULL;
    struct node *gezici = NULL;
    struct satirlar *ilkSatir = NULL;
    struct satirlar *sonSatir = NULL;

    satirBasaEkle(&ilk,&son,&ilkSatir,&sonSatir);


    struct satirlar *geziciSatir = ilkSatir;
    geziciSatir->satirUzunlugu = 0;


    int tus=0; /// basilan tusu alacagimiz degisken
    int tus2=0; /// ilk tus shift ctrl gibi ise bunu kullanycaz

    while(1){

        tus = _getch(); /// ilk tusu al

        if(tus==0) /// Kontrol et eger shift ctrl gibi ise ikinci tusu bekle
            tus2 = _getch();

        if(tus==0 && tus2 == 45) /// kisa cizgi basildiysa kapat
            exit(0);


        if(tus > 31 && tus < 127 )  {

            if(GetAsyncKeyState(VK_LEFT)){

                if(wherex()>0 && gezici->onceki != NULL){
                    if(gezici == son && wherex()>geziciSatir->satirUzunlugu){
                        gotoxy(wherex()-1,wherey());
                    }else{
                        gezici = gezici->onceki;
                        gotoxy(wherex()-1,wherey());
                    }
                }

            }else if(GetAsyncKeyState(VK_RIGHT)){
                if(wherex()<120 && gezici->sonraki != NULL){
                    gotoxy(wherex()+1,wherey());
                    gezici = gezici->sonraki;
                }

            }else if(GetAsyncKeyState(VK_UP)){
                if(geziciSatir == ilkSatir)
                    continue;

                if(wherey()>1){
                   imlecTasi(&geziciSatir,&ilk,&son,&gezici,wherex(),wherey(),true);
                    //gotoxy(wherex(),wherey()-1);
                     //geziciSatir = geziciSatir->onceki;
                    //ilk = geziciSatir->ilk;
                    //son = geziciSatir->son;
                    //gezici = son;
                }

            }else if(GetAsyncKeyState(VK_DOWN)){
                if(geziciSatir == sonSatir)
                    continue;

              imlecTasi(&geziciSatir,&ilk,&son,&gezici,wherex(),wherey(),false);

            }else{

                if(ilk==NULL && son==NULL){
                    sonaEkle(&ilk,&son,tus);
                    geziciSatir->satirUzunlugu++;
                    gezici=son;
                    geziciSatir->ilk = ilk ;
                    geziciSatir->son = son;
                    clrscr();
                    Listele(ilkSatir);
                    continue;
                }

                if(gezici == son && gezici->data != 10){ /// Gezici yeri kontrolu ozel yerler bas ve son ise ona gore islem yap
                    sonaEkle(&ilk,&son,tus);
                    geziciSatir->satirUzunlugu++;
                    gezici=son;
                    geziciSatir->son = son;
                    clrscr();
                    Listele(ilkSatir);
                } else if(gezici == ilk && gezici->data != 10){
                    int x,y;
                    x = wherex();
                    y = wherey();
                    basaEkle(&ilk,&son,tus);
                    geziciSatir->satirUzunlugu++;
                    gezici = ilk;
                    geziciSatir->ilk = ilk;
                    clrscr();
                    Listele(ilkSatir);
                    gotoxy(x,y);
                }else if(gezici == ilk && gezici->data == 10){
                    int x,y;
                    x = wherex();
                    y = wherey();
                    basaEkle(&ilk,&son,tus);
                    geziciSatir->satirUzunlugu++;
                    geziciSatir->ilk = ilk;
                    clrscr();
                    Listele(ilkSatir);
                    gotoxy(x+1,y);

                }else{
                    int x,y;
                    x = wherex();
                    y = wherey();
                    arayaEkle(&gezici,tus);
                    geziciSatir->satirUzunlugu++;
                    clrscr();
                    Listele(ilkSatir);
                    // gezici = gezici->onceki;
                    gotoxy(x+1,y);
                }

   // printf("%c",tus);

            } /// en son else in bitisi
        } /// Tus 31-127 aralik kontrol bitisi

        if(geziciSatir->satirUzunlugu != 0){
            if(tus == 8){   /// backspace e bastıysa
                int x,y;
                x = wherex();
                y = wherey();
                elemansil(&gezici,&ilk,&son,geziciSatir->satirUzunlugu);
                geziciSatir->satirUzunlugu--;
                clrscr();
                Listele(ilkSatir);
                if(gezici==ilk)
                    gotoxy(x,y);
                else
                    gotoxy(x-1,y);
            }
        }

         if(tus == 13){ ///Enter basildiysa
            if(gezici == son && geziciSatir->sonraki == NULL){
                sonaEkle(&ilk,&son,10);
                geziciSatir->satirUzunlugu++;
                geziciSatir->son = son;
                ilk = son = gezici = NULL;
                satirSonaEkle(&ilk,&son,&ilkSatir,&sonSatir);
                geziciSatir = sonSatir;
                gotoxy(1,wherey()+1);
                geziciSatir->satirUzunlugu = 0;
            }else if(gezici == son && geziciSatir->sonraki != NULL){
                int tmpx,tmpy;
                tmpx = wherex();
                tmpy = wherey();
                ilk = son = gezici = NULL;
                satirArdinaEkle(&ilk,&son,&geziciSatir);

                geziciSatir->satirUzunlugu = 0;

                sonaEkle(&ilk,&son,10);
                geziciSatir->satirUzunlugu++;
                gezici=son;
                geziciSatir->ilk = ilk ;
                geziciSatir->son = son;
                clrscr();
                Listele(ilkSatir);
                gotoxy(1,tmpy+1);

            }
        }

    } /// While bitis
    _getch();
}
