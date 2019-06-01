#include <stdio.h>
#include <stdlib.h>

int sayisalLoto_istatistik(int x, int y, int z);
int sansTopu_istatistik(int x, int y, int z);
int on_numara_istatistik(int x, int y, int z);
int super_loto_istatistik(int x, int y, int z);

int main()
{
    int menuSecimi;
    char cikis_ana;

    printf("ANA MENU\n1.Sans Oyunlari\n2.Cekilis Istatistikleri\n3.Cikis Islemleri\n");
    printf("Bir sayi giriniz:");
    do{scanf("%d",&menuSecimi);
    switch(menuSecimi){
    case 1:
       altMenuFonk();
        break;
    case 2:
        cekilisler();
        break;
    case 3:
      printf("Cikis yapmak istediginizden emin misiniz? (E / H)\n");
      do{
            cikis_ana =getch();
      if(cikis_ana=='h' || cikis_ana=='H'){
            main();
            break;
        }
      if(cikis_ana=='e' || cikis_ana=='E'){
            return 0;
         }
         if(cikis_ana!='e' || cikis_ana!='E' || cikis_ana!='h' ||cikis_ana!='H')
            printf("Yanlis karekter secimi! Yeni bir karakter girin:\n");
      }while(cikis_ana!='e' || cikis_ana!='E' || cikis_ana!='h' ||cikis_ana!='H');

      break;

      }
      if(menuSecimi<1 || menuSecimi>3)
        printf("Yanlis sayi girdiniz!Yeni bir sayi giriniz:\n");
  }while(menuSecimi<1 || menuSecimi>3);

    return 0;


}
void altMenuFonk()
{
    int altMenu;
     printf("SANS OYUNLARI ALT MENUSU\n1.Sayisal Loto\n2.Sans Topu\n3.On Numara\n4.Super Loto\n5.Ana Menu\n");
     printf("Bir sayi giriniz:");

     do{
        scanf("%d",&altMenu);
        switch(altMenu){
    case 1:
        sayisalLoto();
        break;
    case 2:
        sansTopu();
        break;
    case 3:
        on_numara();
        break;
    case 4:
        super_loto();
        break;
    case 5:
        main();
        break;
        }
        if(altMenu<1 || altMenu>5)
            printf("Yanlis sayi girdiniz. Yeni bir sayi giriniz\n");
    }while(altMenu<1 || altMenu>5);


}

void sayisalLoto()
{
    int i,girilenSayi,j,sayiTut1,tutturmaSayi=0,sayisalPuan=0,toplam=0;
    char cikis_sayisal;
     printf("6 adet sayi giriniz(Sayilar 1 ile 49 arasinda olmalidir).\n");

            int diziSayisal[6],randdiziSayisal[6];

            for(i=0; i<6; i++)
            {
                do{
                    scanf("%d",&girilenSayi);
                    if(girilenSayi<1 || girilenSayi>49){
                        printf("Yanlis sayi girdiniz. Yeni bir sayi giriniz.\n");
                    }
                } while(girilenSayi<1 || girilenSayi>49);

                diziSayisal[i] = girilenSayi;
                randdiziSayisal[i] = 1 + rand()%48;
                sayisalLoto_istatistik(randdiziSayisal[i]-1,0,1);
                sayisalLoto_istatistik(randdiziSayisal[i]-1,1,randdiziSayisal[i]);
            }

             for(i=0; i<6; i++){
                for(j=0; j<5; j++){
                    if(diziSayisal[j]>diziSayisal[j+1]){
                    sayiTut1=diziSayisal[j];
                    diziSayisal[j]=diziSayisal[j+1];
                    diziSayisal[j+1]=sayiTut1;
                    }

                     if(randdiziSayisal[j]>randdiziSayisal[j+1]){
                    sayiTut1=randdiziSayisal[j];
                    randdiziSayisal[j]=randdiziSayisal[j+1];
                    randdiziSayisal[j+1]=sayiTut1;
                    }
                }
            }
            printf("Girilen sayilar:\n");
            for(i=0; i<6; i++){
                printf("%d,",diziSayisal[i]);
            }
            printf("\nLotodaki sayilar:\n");
            for(i=0; i<6; i++){
                printf("%d,",randdiziSayisal[i]);

            }



            for(i=0; i<6; i++){
              for(j=0; j<6; j++){
               if(diziSayisal[i]==randdiziSayisal[j]){
                printf("\nTutturdugunuz sayi=%d\n",diziSayisal[i]);

                tutturmaSayi++;

            }
        }
    }


          printf("\nTutturdugunuz sayi miktari=%d\n",tutturmaSayi);

           switch(tutturmaSayi){
           case 1:
           case 2:
            printf("Puan almaniz icin en az 3 sayi tutturmalisiniz.\n");
            break;
           case 3:
            printf("Tebrikler. 32 puan kazandiniz.");
            sayisalPuan+=32;
            break;
           case 4:
            printf("Tebrikler. 64 puan kazandiniz.");
            sayisalPuan+=64;
            break;
           case 5:
            printf("Tebrikler. 128 puan kazandiniz.");
            sayisalPuan+=128;
            break;
           case 6:
            printf("Tebrikler 256 puan kazandiniz.");
            sayisalPuan+=256;
            break;
           }
           printf("\nSimdiye kadar kazandiginiz toplam puan=%d\n",sayisalPuan);

           tutturmaSayi=0;
           printf("Yeni bir sayisal loto oyunu oynamak istermisiniz? (E / H)\n");
           do{cikis_sayisal = getch();

           if(cikis_sayisal=='h' || cikis_sayisal=='H'){
             altMenuFonk();
             break;
            }
           if(cikis_sayisal=='e' || cikis_sayisal=='E'){
             sayisalLoto();
             break;
           }
             if(cikis_sayisal!='e' || cikis_sayisal!='E' || cikis_sayisal!='h' ||cikis_sayisal!='H')
                printf("Yanlis karakter secimi! Yeni bir karakter giriniz:\n");

        }while(cikis_sayisal!='e' || cikis_sayisal!='E' || cikis_sayisal!='h' ||cikis_sayisal!='H');


}
void sansTopu()
{
int i,girilenSayi,j,sayiTut1,tutturmaSayi=0,sansTopuPuan=0,cikis1,artibir=0;
char cikis_sanstopu;
     printf("5 adet sayi giriniz(Sayilar 1 ile 34 arasinda olmalidir).\n");

            int diziSansTopu[5],randdiziSansTopu[5],SansTopu,randSansTopu;

            for(i=0; i<5; i++)
            {
                do{
                    scanf("%d",&girilenSayi);
                    if(girilenSayi<1 || girilenSayi>34)
                        printf("Yanlis sayi girdiniz. Yeni bir sayi giriniz.\n");

                } while(girilenSayi<1 || girilenSayi>34);

                diziSansTopu[i] = girilenSayi;
                randdiziSansTopu[i] = 1 + rand()%33;
            }

    printf("1 adet sayi giriniz(Sayi 1 ile 14 arasinda olmalidir).\n");

                do{
                    scanf("%d",&SansTopu);
                    if(SansTopu<1 || SansTopu>34)
                        printf("Yanlis sayi girdiniz. Yeni bir sayi giriniz.");

                    }while(SansTopu<1 || SansTopu>34);

                    randSansTopu= 1 + rand()%13;

                    sansTopu_istatistik(randdiziSansTopu[i]-1,0,1);
                    sansTopu_istatistik(randdiziSansTopu[i]-1,1,randdiziSansTopu[i]);



             for(i=0; i<5; i++){
                for(j=0; j<4; j++){
                    if(diziSansTopu[j]>diziSansTopu[j+1]){
                    sayiTut1=diziSansTopu[j];
                    diziSansTopu[j]=diziSansTopu[j+1];
                    diziSansTopu[j+1]=sayiTut1;
                    }

                     if(randdiziSansTopu[j]>randdiziSansTopu[j+1]){
                    sayiTut1=randdiziSansTopu[j];
                    randdiziSansTopu[j]=randdiziSansTopu[j+1];
                    randdiziSansTopu[j+1]=sayiTut1;
                    }
                }
            }
            printf("Girilen sayilar:\n");
            for(i=0; i<5; i++){
                printf("%d,",diziSansTopu[i]);
            }
            printf(" Yazdiginiz +1 sayi:%d",SansTopu);

            printf("\nSans topunda cikan sayilar:\n");
            for(i=0; i<5; i++){
                printf("%d,",randdiziSansTopu[i]);
            }
            printf("Sans topundaki +1 sayi:%d",randSansTopu);

            for(i=0; i<5; i++){
              for(j=0; j<5; j++){
               if(diziSansTopu[i]==randdiziSansTopu[j]){
                printf("\nTutturdugunuz sayi=%d\n",diziSansTopu[i]);
            tutturmaSayi++;
            }
        }
    }
          printf("\nTutturdugunuz sayi miktari=%d",tutturmaSayi);
          if(SansTopu==randSansTopu){
            printf("+1\n");
            artibir=1;
          }
          else
            printf("+0\n");

           switch(tutturmaSayi){
           case 1:
               if(artibir==1){
                printf("1+1 den 2 puan kazandiniz.");
                sansTopuPuan+=2;
               }
               else
               printf("Uzgunuz. Puan alamadiniz.");
               break;
           case 2:
            if(artibir==1){
                printf("2+1 den 4 puan kazandiniz.");
                sansTopuPuan+=4;
              }
              else
                printf("Uzgunuz. Puan alamadiniz.");
            break;
           case 3:
            if(artibir==1){
                printf("3+1 den 16 puan kazandiniz.");
                sansTopuPuan+=16;
            }
            else{
                printf("3 den 8 puan kazandiniz.");
                sansTopuPuan+=8;
            }
            break;
           case 4:
            if(artibir==1){
                printf("4+1 den 64 puan kazandiniz.");
                sansTopuPuan+=64;
            }
            else{
                printf("4 den 32 puan kazandiniz.");
                sansTopuPuan+=32;
            }
            break;
           case 5:
            if(artibir==1){
                printf("5+1 den 256 puan kazandiniz.");
                sansTopuPuan+=256;
            }
            else{
                printf("5 den 128 puan kazandiniz.");
                sansTopuPuan+=128;
            }
            break;
           }
           printf("\nSimdiye kadar kazandiginiz toplam puan=%d\n",sansTopuPuan);

           tutturmaSayi=0;

           printf("Yeni bir Sans Topu Oyunu oynamak ister misiniz?(E/H)\n");
           do{cikis_sanstopu = getch();

           while(cikis_sanstopu=='h' || cikis_sanstopu=='H'){
           altMenuFonk();
           break;
          }
           while(cikis_sanstopu=='e' || cikis_sanstopu=='E'){
           sansTopu();
           break;
          }
          if(cikis_sanstopu!='e' || cikis_sanstopu!='E' || cikis_sanstopu!='h' ||cikis_sanstopu!='H')
          printf("Yanlis karakter secimi! Yeni bir karakter girin:\n");
        }while(cikis_sanstopu!='e' || cikis_sanstopu!='E' || cikis_sanstopu!='h' ||cikis_sanstopu!='H');
}

void on_numara()
{
    int sayi,randdizi_onnumara[22],girilendizi_onnumara[10],i,j,sayi_tut1,sayi_tut2,tutturmaSayi=0,sayisalPuan=0;
    char cikis_onnumara;

    printf("Lutfen 1-80 araliginda 10 farkli sayi giriniz:\n");
    for(i=0;i<10;i++)
    {
        do
       {
        scanf("%d",&sayi);
        if(sayi<1 || sayi>80){
            printf("Yanlis sayi girdiniz! Lutfen 1-80 araliginda bir sayi giriniz:\n");
          }
       }while(sayi<1 || sayi>80);
       girilendizi_onnumara[i]=sayi;

    }
    for(i=0;i<22;i++){
            randdizi_onnumara[i]=rand()%79+1;
        }
        on_numara_istatistik(randdizi_onnumara[i]-1,0,1);
        on_numara_istatistik(randdizi_onnumara[i]-1,1,randdizi_onnumara[i]);



   for(i=0;i<10;i++){
        for(j=0;j<9;j++){
            if(girilendizi_onnumara[j]>girilendizi_onnumara[j+1]){
                sayi_tut1=girilendizi_onnumara[j];
                girilendizi_onnumara[j]=girilendizi_onnumara[j+1];
                girilendizi_onnumara[j+1]=sayi_tut1;
              }

            }
        }

        if(randdizi_onnumara[i]>1 || randdizi_onnumara[i]<80){
        for(i=0;i<22;i++){
            for(j=0;j<21;j++){
                if(randdizi_onnumara[j]>randdizi_onnumara[j+1]){
                sayi_tut2=randdizi_onnumara[j];
                randdizi_onnumara[j]=randdizi_onnumara[j+1];
                randdizi_onnumara[j+1]=sayi_tut2;
              }
            }
        }
    }


   printf("\n");
   printf("Girilen Sayilar=\n");
   for(i=0;i<10;i++){
    printf("%d\t",girilendizi_onnumara[i]);
   }
   printf("\n");
   printf("On numara oyunu sonucu cikan sayilar=\n");
    for(i=0;i<22;i++){
    printf("%d\t",randdizi_onnumara[i]);
   }
   for(i=0;i<10;i++){
    for(j=0;j<22;j++){
        if(girilendizi_onnumara[i]==randdizi_onnumara[j]){
            printf("\nTutturdugunuz Sayilar=%4d\n",girilendizi_onnumara[i]);
            tutturmaSayi++;
        }
    }
   }
   printf("\n Tuturdugunuz sayi miktari=%2d\n",tutturmaSayi);

           switch(tutturmaSayi){
       case 0:
           printf("Tebrikler 8 puan kazandiniz.\n");
           sayisalPuan+=8;
           break;
       case 1:
       case 2:
       case 3:
       case 4:
       case 5:
        printf("Puan kazanamaniz icin en az 6 sayi tutturmalisiniz.\n");
        break;
       case 6:
        printf("Tebrikler 16 puan kazandiniz.\n");
        sayisalPuan+=16;
        break;
       case 7:
        printf("Tebrikler 32 puan kazandiniz.\n");
        sayisalPuan+=32;
        break;
       case 8:
        printf("Tebrikler 64 puan kazandiniz.\n");
        sayisalPuan+=64;
        break;
       case 9:
        printf("Tebrikler 128 puan kazandiniz.\n");
        sayisalPuan+=128;
        break;
       case 10:
        printf("Tebrikler 256 puan kazandiniz.\n");
        sayisalPuan+=256;
           }
           printf("\nSimdiye kadar kazandiginiz toplam puan=%d\n",sayisalPuan);

           tutturmaSayi=0;
           printf("Yeni bir on numara oyunu oynamak istermisiniz? (E / H)\n");
           do{cikis_onnumara = getch();

           while(cikis_onnumara=='h' || cikis_onnumara=='H'){
           altMenuFonk();
           break;
          }
           while(cikis_onnumara=='e' || cikis_onnumara=='E'){
           on_numara();
           break;
          }
          if(cikis_onnumara!='e' || cikis_onnumara!='E' || cikis_onnumara!='h' ||cikis_onnumara!='H')
            printf("Yanlis karakter secimi! Yeni bir karakter girin:\n");
        }while(cikis_onnumara!='e' || cikis_onnumara!='E' || cikis_onnumara!='h' ||cikis_onnumara!='H');

}
void super_loto()
{
    int sayi,randdizi_superloto[6],girilendizi_superloto[6],i,j,sayiTut,sayiTut2,tutturmaSayi=0,lotoPuan=0;
    char cikis_super;
    printf("Lutfen 1-54 araliginda 6 farkli sayi  giriniz:\n");
    for(i=0;i<6;i++){
        do{
            scanf("%d",&sayi);
            if(sayi<1 || sayi>54){
                printf("Yanlis sayi girdiniz!Lutfen 1-54 arasinda bir sayi giriniz.\n");
            }
        }while(sayi<1 || sayi>54);
        girilendizi_superloto[i]=sayi;
    }
    for(i=0;i<6;i++){
        randdizi_superloto[i]=rand()%53+1;
    }

    super_loto_istatistik(randdizi_superloto[i]-1,0,1);
    super_loto_istatistik(randdizi_superloto[i]-1,1,randdizi_superloto[i]);

       for(i=0;i<6;i++){
        for(j=0;j<5;j++){
            if(girilendizi_superloto[j]>girilendizi_superloto[j+1]){
                sayiTut=girilendizi_superloto[j];
                girilendizi_superloto[j]=girilendizi_superloto[j+1];
                girilendizi_superloto[j+1]=sayiTut;
              }

            }
        }

        if(randdizi_superloto[i]>1 || randdizi_superloto[i]<80){
        for(i=0;i<6;i++){
            for(j=0;j<5;j++){
                if(randdizi_superloto[j]>randdizi_superloto[j+1]){
                sayiTut2=randdizi_superloto[j];
                randdizi_superloto[j]=randdizi_superloto[j+1];
                randdizi_superloto[j+1]=sayiTut2;
              }
            }
        }
    }
    printf("\n");
    for(i=0;i<6;i++){
                printf("%4d",girilendizi_superloto[i]);
    }
    printf("\n");
    printf("Super Lotoda Cikan Sayilar:\n");
    for(i=0;i<6;i++){
        printf("%4d",randdizi_superloto[i]);
    }
for(i=0;i<6;i++){
    for(j=0;j<6;j++){
        if(girilendizi_superloto[i]==randdizi_superloto[j]){
            printf("\nTutturdugunuz Sayilar=%4d\n",girilendizi_superloto[i]);
            tutturmaSayi++;
        }
    }
   }
   printf("\nTutturdugunuz sayi miktari=%d\n",tutturmaSayi);

           switch(tutturmaSayi){
           case 1:
           case 2:
            printf("Puan almaniz icin en az 3 sayi tutturmalisiniz.\n");
            break;
           case 3:
            printf("Tebrikler. 32 puan kazandiniz.");
            lotoPuan+=32;
            break;
           case 4:
            printf("Tebrikler. 64 puan kazandiniz.");
            lotoPuan+=64;
            break;
           case 5:
            printf("Tebrikler. 128 puan kazandiniz.");
            lotoPuan+=128;
            break;
           case 6:
            printf("Tebrikler 256 puan kazandiniz.");
            lotoPuan+=256;
            break;
           }
           printf("\nSimdiye kadar kazandiginiz toplam puan=%d\n",lotoPuan);

           tutturmaSayi=0;

           printf("Yeni bir super loto oyunu oynamak istermisiniz? (E / H)\n");
           do{cikis_super = getch();

           while(cikis_super=='h' || cikis_super=='H'){
           altMenuFonk();
           break;
          }
           while(cikis_super=='e' || cikis_super=='E'){
           super_loto();
           break;
          }
          if(cikis_super!='e' || cikis_super!='E' || cikis_super!='h' ||cikis_super!='H')
          printf("Yanlis karakter secimi! Yeni bir karakter girin:\n");

        }while(cikis_super!='e' || cikis_super!='E' || cikis_super!='h' ||cikis_super!='H');
}
int sayisalLoto_istatistik(int x, int y, int z)
{
    static int dizi[49][2],oyun=0;
    int i;
    if(oyun==0)
        for(i=0;i<49;i++)
            dizi[i][0]=0;
    oyun=1;
    if(y==0)
        dizi[x][y] +=z;
    else if(z!=0)
        dizi[x][y] =z;

    return dizi[x][y];
}
int sansTopu_istatistik(int x,int y,int z)
{
    static int dizi[34][2],oyun=0;
    int i;
    if(oyun==0)
        for(i=0;i<34;i++)
        dizi[i][0]=0;
    oyun=1;
    if(y==0)
        dizi[x][y] +=z;
    else
        dizi[x][y] =z;

    return dizi[x][y];

}

int on_numara_istatistik(int x,int y,int z)
{

    static int dizi[80][2],oyun=0;
    int i;
    if(oyun==0)
        for(i=0;i<80;i++)
        dizi[i][0]=0;
    oyun=1;
    if(y==0)
        dizi[x][y] +=z;
    else
        dizi[x][y] =z;

    return dizi[x][y];

}
int super_loto_istatistik(int x, int y, int z)
{

    static int dizi[54][2],oyun=0;
    int i;
    if(oyun==0)
        for(i=0;i<54;i++)
        dizi[i][0]=0;
    oyun=1;
    if(y==0)
        dizi[x][y] +=z;
    else
        dizi[x][y] =z;

    return dizi[x][y];

}
void cekilisler()
{
    int secim;
    printf("1.Sayisal Loto Istatistikleri\n");
    printf("2.Sans Topu Istatistikleri\n");
    printf("3.On Numara Istatistikler\n");
    printf("4.Super Loto Istatistikler\n");
    printf("Seciminizi Girin:\n");
    scanf("%d",&secim);

    switch(secim){
case 1:
    sayisalLoto_ist();
        break;

case 2:
    sansTopu_ist();
 break;
case 3:
    on_numara_ist();
        break;


case 4:
    super_loto_ist();
        break;


    }
}

void sayisalLoto_ist()
{
    int i,j;
        int a[49][2];
        for(i=0;i<49;i++)
            a[i][0]=sayisalLoto_istatistik(i,0,0);
        for(i=0;i<49;i++)
            a[i][1]=sayisalLoto_istatistik(i,1,0);
        for(i=0;i<49;i++)
        {
            for(j=0;j<48;j++)
            {
                if(a[j][0]<a[j+1][0]){
                    int gecici;
                    gecici = a[j][0];
                    a[j][0] = a[j+1][0];
                    a[j+1][0] = gecici;
                    gecici = a[j][1];
                    a[j][1] = a[j+1][1];
                    a[j+1][1] = gecici;
                }
            }
        }
        printf("Sayisal Loto Istatistik:\n");
        for(i=0;i<6;i++){
            printf("%d\t%d\n",a[i][1],a[i][0]);
        }


}

void sansTopu_ist()
{
           int i,j;
        int b[34][2];
        for(i=0;i<34;i++)
            b[i][0]=sansTopu_istatistik(i,0,0);
        for(i=0;i<34;i++)
            b[i][1]=sansTopu_istatistik(i,1,0);
        for(i=0;i<34;i++)
        {
            for(j=0;j<34;j++)
            {
                if(b[j][0]<b[j+1][0]){
                    int gecici;
                    gecici = b[j][0];
                    b[j][0] = b[j+1][0];
                    b[j+1][0] = gecici;
                    gecici = b[j][1];
                    b[j][1] = b[j+1][1];
                    b[j+1][1] = gecici;
                }
            }
        }
        printf("Sans Topu  Istatistik:\n");
            for(i=0;i<5;i++){
            printf("%d\t%d\n",b[i][1],b[i][0]);
            }


}
void on_numara_ist()
{
    int i,j;
        int a[80][2];
        for(i=0;i<80;i++)
            a[i][0]=on_numara_istatistik(i,0,0);
        for(i=0;i<80;i++)
            a[i][1]=on_numara_istatistik(i,1,0);
        for(i=0;i<80;i++)
        {
            for(j=0;j<80;j++)
            {
                if(a[j][0]<a[j+1][0]){
                    int gecici;
                    gecici = a[j][0];
                    a[j][0] = a[j+1][0];
                    a[j+1][0] = gecici;
                    gecici = a[j][1];
                    a[j][1] = a[j+1][1];
                    a[j+1][1] = gecici;
                }
            }
        }
        printf("On Numara Istatistik:\n");
        for(i=0;i<10;i++){
            printf("%d\t%d\n",a[i][1],a[i][0]);
        }

}
void super_loto_ist()
{
    int i,j;
        int a[54][2];
        for(i=0;i<54;i++)
            a[i][0]=super_loto_istatistik(i,0,0);
        for(i=0;i<54;i++)
            a[i][1]=super_loto_istatistik(i,1,0);
        for(i=0;i<54;i++)
        {
            for(j=0;j<54;j++)
            {
                if(a[j][0]<a[j+1][0]){
                    int gecici;
                    gecici = a[j][0];
                    a[j][0] = a[j+1][0];
                    a[j+1][0] = gecici;
                    gecici = a[j][1];
                    a[j][1] = a[j+1][1];
                    a[j+1][1] = gecici;
                }
            }
        }
        printf("Super Loto Istatistik:\n");
        for(i=0;i<6;i++){
            printf("%d\t%d\n",a[i][1],a[i][0]);
        }

}

