#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


struct myStruct
{
    char isim[10];
    int giris_sayisi;
    int girisler[3];
    char giris_isim[3];
    int cikis;
    char cikis_isim[2];
    int gecikme;
} kapilar[20];

void swap(char *str1, char *str2)
{
    char *temp = (char *)malloc((strlen(str1) + 1) * sizeof(char));
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
    free(temp);
}
void giris5yap()
{
    for (int i = 0; i < 20 ; i++)      //// Tüm giriþler 5 oldu
    {
        for (int j = 0; j < 3 ; j++)
        {
            kapilar[i].girisler[j] = 5;
            kapilar[i].giris_isim[j]= ' ';
        }
    }
}

int not(int deger)
{
    int cikis = -1;
    if  (deger == 0)
    {
        cikis = 1;
    }
    else if  (deger == 1)
    {
        cikis = 0;
    }
    return cikis;
}

int and (int giris1, int giris2, int giris3)
{
    if  (giris1 == 0 ||giris2 == 0 ||giris3 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int or (int giris1, int giris2, int giris3)
{
    if  (giris1 == 1 ||giris2 == 1 ||giris3 == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int nand (int giris1, int giris2, int giris3)
{
    if  (giris1 == 0 ||giris2 == 0 ||giris3 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int nor (int giris1, int giris2, int giris3)
{
    if  (giris1 == 1 ||giris2 == 1 ||giris3 == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int xor (int giris1, int giris2, int giris3)
{

    if  (giris3 == 5)
    {
        if  (giris1 == 0 && giris2 == 0)
        {
            return 0;
        }
        if  (giris1 == 1 && giris2 == 1)
        {
            return 0;
        }
        if  (giris1 == 1 && giris2 == 0)
        {
            return 1;
        }
        if  (giris1 == 0 && giris2 == 1)
        {
            return 1;
        }
    }
    else
    {
        if  (giris1 == 0 && giris2 == 0 && giris3 == 0)
        {
            return 0;
        }
        if  (giris1 == 0 && giris2 == 0 && giris3 == 1)
        {
            return 1;
        }
        if  (giris1 == 0 && giris2 == 1 && giris3 == 0)
        {
            return 1;
        }
        if  (giris1 == 1 && giris2 == 0 && giris3 == 0)
        {
            return 1;
        }
        if  (giris1 == 0 && giris2 == 1 && giris3 == 1)
        {
            return 0;
        }
        if  (giris1 == 1 && giris2 == 1 && giris3 == 1)
        {
            return 1;
        }
        if  (giris1 == 1 && giris2 == 1 && giris3 == 0)
        {
            return 0;
        }
        if  (giris1 == 1 && giris2 == 0 && giris3 == 1)
        {
            return 0;
        }
    }
}



void yenile(int kapi_sayisi)  // deger deðiþtikden sonra kullanýlýr devreyi simule eder
{

    for (int i = 0; i < kapi_sayisi; i++)     // kapý    sayýsý kadar dödürülecek
    {
        if  (strcmp(kapilar[i].isim, "NOR") == 0)
        {
            kapilar[i].cikis = nor(kapilar[i].girisler[0], kapilar[i].girisler[1], kapilar[i].girisler[2]);
        }
        else if (strcmp(kapilar[i].isim, "XOR") == 0)
        {
            kapilar[i].cikis = xor(kapilar[i].girisler[0], kapilar[i].girisler[1], kapilar[i].girisler[2]);
        }
        else if (strcmp(kapilar[i].isim, "NAND") == 0)
        {
            kapilar[i].cikis = nand(kapilar[i].girisler[0], kapilar[i].girisler[1], kapilar[i].girisler[2]);
        }
        else if (strcmp(kapilar[i].isim, "OR") == 0)
        {
            kapilar[i].cikis = or(kapilar[i].girisler[0], kapilar[i].girisler[1], kapilar[i].girisler[2]);
        }
        else if (strcmp(kapilar[i].isim, "AND") == 0)
        {
            kapilar[i].cikis = and(kapilar[i].girisler[0], kapilar[i].girisler[1], kapilar[i].girisler[2]);
        }
        else if (strcmp(kapilar[i].isim, "NOT") == 0)
        {
            kapilar[i].cikis = not(kapilar[i].girisler[0]);

        }

        for (int j = i+1; j < kapi_sayisi ; j++)
        {
            if (kapilar[i].cikis_isim[0] == kapilar[j].giris_isim[0])
            {
                kapilar[j].girisler[0] = kapilar[i].cikis;
            }
            if (kapilar[i].cikis_isim[0] == kapilar[j].giris_isim[1])
            {
                kapilar[j].girisler[1] = kapilar[i].cikis;
            }
            if (kapilar[i].cikis_isim[0] == kapilar[j].giris_isim[2])
            {
                kapilar[j].girisler[2] = kapilar[i].cikis;
            }
        }
    }

}

void yazdir(int kapi_sayisi)
{
    for (int i = 0; i < kapi_sayisi; i++)
    {
        printf("%-5s  %c,%d  %c,%d  %c,%d  %c,%d       %d  %d",kapilar[i].isim, kapilar[i].cikis_isim[0], kapilar[i].cikis, kapilar[i].giris_isim[0],  kapilar[i].girisler[0], kapilar[i].giris_isim[1], kapilar[i].girisler[1], kapilar[i].giris_isim[2], kapilar[i].girisler[2], kapilar[i].giris_sayisi, kapilar[i].gecikme);
        printf("\n");
    }
}



int main()
{

    giris5yap();
    int gereksiz=0;
    int sayma=0;
    char secim[100];//secim yapmaseysi
    char buf[100];//devre ve deger satir alma
    char buf1[100];//satir alma  baska dosya seysi
    char buf2[100];//komuttan alma
    int DevreSatirSayisi=0;
    int BaskaSatirSayisi=0;
    int DegerSatirSayisi=0;
    int KomutSatirSayisi=0;
    int i,j;
    char command[30][100];
    char devre[30][100];//devre.txt icindekileri alma seysi
    char baska[30][100];//baska_dosya.txt icindekileri alma seysi
    char deger[30][100];
    char ana_girisler[30];
    int p = 0;//ana giris sayisi
    FILE *devredosya;
    FILE *komutdosya;
    FILE *degerdosya;
    FILE *baskadosya;
    FILE *logdosya;
    time_t rawtime;
    struct tm *info;

    logdosya=fopen("log.txt","w");
selection:


    printf(">");
    fgets(secim,50,stdin);
    secim[strlen(secim)-1]='\0';

    time( &rawtime );
    info = localtime( &rawtime );
    fprintf(logdosya,"\n%-60s KOMUT:%s\n\n",asctime(info),secim);
    fprintf(logdosya,"\n*CIKTI\n");


    if(!strcmp(secim,"Y devre.txt")||!strcmp(secim,"y devre.txt"))
    {
        printf("devre.txt yuklendi\n");
        fprintf(logdosya,"devre.txt yuklendi\n");
        devredosya=fopen("devre.txt","r");
        DevreSatirSayisi=0;

        if((baskadosya=fopen("baska_dosya.txt","r"))!=NULL)
        {
            while(fgets(buf,100,devredosya)!=NULL)
            {
                gereksiz++;
                if(gereksiz==1)
                {
                    continue;
                }
                sprintf(devre[DevreSatirSayisi],"%s",buf);
                DevreSatirSayisi++;
            }
            BaskaSatirSayisi=0;
            while(fgets(buf1,100,baskadosya)!=NULL)
            {
                sprintf(baska[BaskaSatirSayisi],"%s",buf1);
                BaskaSatirSayisi++;
            }
            strcpy(devre[DevreSatirSayisi-1],baska[BaskaSatirSayisi-2]);
            DevreSatirSayisi++;
            strcpy(devre[DevreSatirSayisi-1],baska[BaskaSatirSayisi-1]);
            swap(devre[DevreSatirSayisi-2],devre[DevreSatirSayisi-3]);

        }


        if((baskadosya=fopen("baska_dosya.txt","r"))==NULL)
        {
            while(fgets(buf,100,devredosya)!=NULL)
            {
                sprintf(devre[DevreSatirSayisi],"%s",buf);
                DevreSatirSayisi++;
            }

        }


        ////////////////////////////////////

        for(int i = 0; i < strlen(devre[0]); i++)
        {
            char x = devre[0][i];
            if  (isalpha(x) && (devre[0][i+1] == '\t') && (devre[0][i -1] == '\t'))
            {
                ana_girisler[p] = devre[0][i];
                p++;
            }
        }
        for(int i = 0; i < strlen(baska[0]); i++)
        {
            sayma=0;
            char x = baska[0][i];
            if  (isalpha(x) && (baska[0][i+1] == '\t') && (baska[0][i -1] == '\t'))
            {
                for(int j=0; j<p; j++)
                {
                    if(baska[0][i]==ana_girisler[j])
                    {
                        sayma++;
                    }
                }
                if(sayma==0)
                {
                    ana_girisler[p]=baska[0][i];
                    p++;
                }

            }
        }


        for (int i = 0; i < DevreSatirSayisi - 3; i++)
        {
            int d = i + 2;

            const char *ayrac = "\t"; // bosluk, nokta ve virgul, noktali virgul...
            char *kelime = strtok(devre[d], ayrac);
            int sayac = 0;
            while (kelime != NULL)
            {
                char s = kelime[0];
                if  (sayac == 1)
                {
                    strcpy(kapilar[i].isim, kelime);
                }
                if  (sayac == 2)
                {
                    kapilar[i].giris_sayisi = atoi(kelime);
                }
                if  (sayac == 3)
                {
                    kapilar[i].cikis_isim[0] = kelime[0];
                }
                if  (sayac == 4 && isalpha(s))
                {
                    kapilar[i].giris_isim[0] = kelime[0];
                }
                if  (sayac == 5 && isalpha(s))
                {
                    kapilar[i].giris_isim[1] = kelime[0];
                }
                if  (sayac == 6 && isalpha(s))
                {
                    kapilar[i].giris_isim[2] = kelime[0];
                }
                if  (sayac > 3 && isdigit(s))
                {
                    kapilar[i].gecikme = atoi(kelime);
                }

                sayac++;
                kelime = strtok(NULL, ayrac);
            }

        }

        ///////////////////////////////////////

        fclose(devredosya);
        fclose(baskadosya);

        goto selection;
    }




    if(!strcmp(secim,"i deger.txt")||!strcmp(secim,"I deger.txt"))
    {
        printf("deger.txt yuklendi degerler atandi\n");
        fprintf(logdosya,"deger.txt yuklendi\n");
        degerdosya=fopen("deger.txt","r");
        DegerSatirSayisi=0;
        while(fgets(buf,100,degerdosya)!=NULL)
        {
            sprintf(deger[DegerSatirSayisi],"%s",buf);
            DegerSatirSayisi++;
        }
        ////////////////////////////////////

        for (int i =0; i < DegerSatirSayisi; i++)
        {
            for (int j = 0; j < DevreSatirSayisi - 3; j++)
            {
                char *s = &deger[i][2];
                if  (kapilar[j].cikis_isim[0] == deger[i][0])
                {
                    kapilar[j].cikis = atoi(s);
                }
                if  (kapilar[j].giris_isim[0] == deger[i][0])
                {
                    kapilar[j].girisler[0] = atoi(s);
                }
                if  (kapilar[j].giris_isim[1] == deger[i][0])
                {
                    kapilar[j].girisler[1] = atoi(s);
                }
                if  (kapilar[j].giris_isim[2] == deger[i][0])
                {
                    kapilar[j].girisler[2] = atoi(s);
                }

            }

        }
        yazdir(DevreSatirSayisi - 3);

        ////////////////////////////////////

        fclose(degerdosya);
        goto selection;
    }





    if(!strcmp(secim,"s")||!strcmp(secim,"S"))
    {
        yenile(DevreSatirSayisi - 3);
        printf("\n");
        yazdir(DevreSatirSayisi - 3);

        printf("devre simule edildi\n");
        fprintf(logdosya,"devre simule edildi\n");

        goto selection;
    }





    if(secim[0] == 'H' || secim[0] == 'h' )
    {

        for (int i = 0; i < p ; i++)    /*p = ana giris sayisi*/
        {
            if  (secim[2] == ana_girisler[i])
            {
                printf("%c girisi 1 lendi.\n",ana_girisler[i]);
                fprintf(logdosya,"%c girisi 1 lendi.\n",ana_girisler[i]);
                for (int j = 0; j < DevreSatirSayisi -3; j++)
                {
                    if  (kapilar[j].giris_isim[0] == ana_girisler[i])
                    {
                        kapilar[j].girisler[0] = 1;
                    }
                    if  (kapilar[j].giris_isim[1] == ana_girisler[i])
                    {
                        kapilar[j].girisler[1] = 1;
                    }
                    if  (kapilar[j].giris_isim[2] == ana_girisler[i])
                    {
                        kapilar[j].girisler[2] = 1;
                    }
                }
            }
        }
        goto selection;
    }




    if(secim[0] == 'L' || secim[0] == 'l' )
    {

        for (int i = 0; i < p ; i++)    /*p = ana giris sayisi*/
        {
            if  (secim[2] == ana_girisler[i])
            {
                for (int j = 0; j < DevreSatirSayisi -3; j++)
                {
                    if  (kapilar[j].giris_isim[0] == ana_girisler[i])
                    {
                        kapilar[j].girisler[0] = 0;
                    }
                    if  (kapilar[j].giris_isim[1] == ana_girisler[i])
                    {
                        kapilar[j].girisler[1] = 0;
                    }
                    if  (kapilar[j].giris_isim[2] == ana_girisler[i])
                    {
                        kapilar[j].girisler[2] = 0;
                    }
                }
            }
        }
        goto selection;
    }






    if(!strcmp(secim,"g*")||!strcmp(secim,"G*"))
    {
        for(int i=0; i<DevreSatirSayisi-3; i++)
        {
            printf("%c:%d\n",kapilar[i].cikis_isim[0],kapilar[i].cikis);
            fprintf(logdosya,"%c:%d\n",kapilar[i].cikis_isim[0],kapilar[i].cikis);

        }
        for(int i=0; i<DevreSatirSayisi-3; i++)
        {
            for(j=0; j<3; j++)
            {
                for(int k=0; k<strlen(ana_girisler); k++)
                {
                    if(kapilar[i].giris_isim[j]==ana_girisler[k])
                    {
                        printf("%c:%d\n",kapilar[i].giris_isim[j],kapilar[i].girisler[j]);
                        fprintf(logdosya,"%c:%d\n",kapilar[i].giris_isim[j],kapilar[i].girisler[j]);
                    }
                }
            }
        }
        printf("Tum uclar gosterildi\n");
        fprintf(logdosya,"Tum uclar gosterildi\n");
        goto selection;
    }






    if(secim[0] == 'g' || secim[0] == 'G' )
    {
        for(int i=0; i<DevreSatirSayisi-3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(kapilar[i].giris_isim[j]==secim[2])
                {
                    printf("%c:%d\n",kapilar[i].giris_isim[j],kapilar[i].girisler[j]);
                    fprintf(logdosya,"%c:%d\n",kapilar[i].giris_isim[j],kapilar[i].girisler[j]);
                    goto selection;
                }
            }
            if(kapilar[i].cikis_isim[0]==secim[2])
            {
                printf("%c:%d\n",kapilar[i].cikis_isim[0],kapilar[i].cikis);
                fprintf(logdosya,"%c:%d\n",kapilar[i].cikis_isim[0],kapilar[i].cikis);
                goto selection;
            }
        }
    }





    if(!strcmp(secim,"k komut.txt")||!strcmp(secim,"K komut.txt"))
    {
        komutdosya=fopen("komut.txt","r");

        while(fgets(buf2,100,komutdosya)!=NULL)
        {
            sprintf(command[KomutSatirSayisi],"%s",buf2);

            KomutSatirSayisi++;
        }
        for(int i=0; i<KomutSatirSayisi; i++)
        {
            command[i][(strlen(command[i])-1)]='\0';
            printf("%s\n",command[i]);
        }
        fclose(komutdosya);

        for(int u=0; u<KomutSatirSayisi; u++)
        {
            printf("\n%s\n",command[u]);
            fprintf(logdosya,"\n%s\n\n",command[u]);
            fprintf(logdosya,"\n*CIKTI\n");



            if((command[u][0]=='y' || command[u][0]=='Y')&& (!strcmp(&command[u][2],"devre.txt")))
            {
                printf("devre.txt yuklendi\n");
                fprintf(logdosya,"devre.txt yuklendi\n");
                devredosya=fopen("devre.txt","r");
                gereksiz=0;
                DevreSatirSayisi=0;
                BaskaSatirSayisi=0;
                if((baskadosya=fopen("baska_dosya.txt","r"))!=NULL)
                {
                    while(fgets(buf,100,devredosya)!=NULL)
                    {
                        gereksiz++;
                        if(gereksiz==1)
                        {
                            continue;
                        }
                        sprintf(devre[DevreSatirSayisi],"%s",buf);
                        DevreSatirSayisi++;
                    }
                    BaskaSatirSayisi=0;
                    while(fgets(buf1,100,baskadosya)!=NULL)
                    {
                        sprintf(baska[BaskaSatirSayisi],"%s",buf1);
                        BaskaSatirSayisi++;
                    }
                    strcpy(devre[DevreSatirSayisi-1],baska[BaskaSatirSayisi-2]);
                    DevreSatirSayisi++;
                    strcpy(devre[DevreSatirSayisi-1],baska[BaskaSatirSayisi-1]);
                    swap(devre[DevreSatirSayisi-2],devre[DevreSatirSayisi-3]);

                }


                if((baskadosya=fopen("baska_dosya.txt","r"))==NULL)
                {
                    while(fgets(buf,100,devredosya)!=NULL)
                    {
                        sprintf(devre[DevreSatirSayisi],"%s",buf);
                        DevreSatirSayisi++;
                    }

                }


                ////////////////////////////////////

                for(int i = 0; i < strlen(devre[0]); i++)
                {
                    char x = devre[0][i];
                    if  (isalpha(x) && (devre[0][i+1] == '\t') && (devre[0][i -1] == '\t'))
                    {
                        ana_girisler[p] = devre[0][i];
                        p++;
                    }
                }
                for(int i = 0; i < strlen(baska[0]); i++)
                {
                    sayma=0;
                    char x = baska[0][i];
                    if  (isalpha(x) && (baska[0][i+1] == '\t') && (baska[0][i -1] == '\t'))
                    {
                        for(int j=0; j<p; j++)
                        {
                            if(baska[0][i]==ana_girisler[j])
                            {
                                sayma++;
                            }
                        }
                        if(sayma==0)
                        {
                            ana_girisler[p]=baska[0][i];
                            p++;
                        }

                    }
                }


                for (int i = 0; i < DevreSatirSayisi - 3; i++)
                {
                    int d = i + 2;

                    const char *ayrac = "\t"; // bosluk, nokta ve virgul, noktali virgul...
                    char *kelime = strtok(devre[d], ayrac);
                    int sayac = 0;
                    while (kelime != NULL)
                    {
                        char s = kelime[0];
                        if  (sayac == 1)
                        {
                            strcpy(kapilar[i].isim, kelime);
                        }
                        if  (sayac == 2)
                        {
                            kapilar[i].giris_sayisi = atoi(kelime);
                        }
                        if  (sayac == 3)
                        {
                            kapilar[i].cikis_isim[0] = kelime[0];
                        }
                        if  (sayac == 4 && isalpha(s))
                        {
                            kapilar[i].giris_isim[0] = kelime[0];
                        }
                        if  (sayac == 5 && isalpha(s))
                        {
                            kapilar[i].giris_isim[1] = kelime[0];
                        }
                        if  (sayac == 6 && isalpha(s))
                        {
                            kapilar[i].giris_isim[2] = kelime[0];
                        }
                        if  (sayac > 3 && isdigit(s))
                        {
                            kapilar[i].gecikme = atoi(kelime);
                        }

                        sayac++;
                        kelime = strtok(NULL, ayrac);
                    }

                }

                ///////////////////////////////////////
                fclose(baskadosya);
                fclose(devredosya);

            }






            if((command[u][0]=='i' || command[u][0]=='I')&& (!strcmp(&command[u][2],"deger.txt")))
            {
                printf("deger.txt yuklendi\n");
                fprintf(logdosya,"deger.txt yuklendi\n");
                degerdosya=fopen("deger.txt","r");
                DegerSatirSayisi=0;
                while(fgets(buf,100,degerdosya)!=NULL)
                {
                    sprintf(deger[DegerSatirSayisi],"%s",buf);
                    DegerSatirSayisi++;
                }
                ////////////////////////////////////

                for (int i =0; i < DegerSatirSayisi; i++)
                {
                    for (int j = 0; j < DevreSatirSayisi - 3; j++)
                    {
                        char *s = &deger[i][2];
                        if  (kapilar[j].cikis_isim[0] == deger[i][0])
                        {
                            kapilar[j].cikis = atoi(s);
                        }
                        if  (kapilar[j].giris_isim[0] == deger[i][0])
                        {
                            kapilar[j].girisler[0] = atoi(s);
                        }
                        if  (kapilar[j].giris_isim[1] == deger[i][0])
                        {
                            kapilar[j].girisler[1] = atoi(s);
                        }
                        if  (kapilar[j].giris_isim[2] == deger[i][0])
                        {
                            kapilar[j].girisler[2] = atoi(s);
                        }

                    }

                }
                yazdir(DevreSatirSayisi - 3);

                ////////////////////////////////////

                fclose(degerdosya);
            }





            if(!strcmp(command[u],"s")||!strcmp(command[u],"S"))
            {
                yenile(DevreSatirSayisi - 3);
                printf("\n");
                yazdir(DevreSatirSayisi - 3);

                printf("devre simule edildi\n");
                fprintf(logdosya,"devre simule edildi\n");
            }



            if(!strcmp(command[u],"g*")||!strcmp(command[u],"G*"))
            {
                for(int i=0; i<DevreSatirSayisi-3; i++)
                {
                    printf("%c:%d\n",kapilar[i].cikis_isim[0],kapilar[i].cikis);
                    fprintf(logdosya,"%c:%d\n",kapilar[i].cikis_isim[0],kapilar[i].cikis);

                }
                for(int i=0; i<DevreSatirSayisi-3; i++)
                {
                    for(j=0; j<3; j++)
                    {
                        for(int k=0; k<strlen(ana_girisler); k++)
                        {
                            if(kapilar[i].giris_isim[j]==ana_girisler[k])
                            {
                                printf("%c:%d\n",kapilar[i].giris_isim[j],kapilar[i].girisler[j]);
                                fprintf(logdosya,"%c:%d\n",kapilar[i].giris_isim[j],kapilar[i].girisler[j]);
                            }
                        }
                    }
                }
                printf("Tum uclar gosterildi\n");
                fprintf(logdosya,"Tum uclar gosterildi\n");


            }



            if(command[u][0] == 'H' || command[u][0] == 'h' )
            {

                for (int i = 0; i < p ; i++)    /*p = ana giris sayisi*/
                {
                    if  (command[u][2] == ana_girisler[i])
                    {
                        printf("%c girisi 1 lendi.\n",ana_girisler[i]);
                        fprintf(logdosya,"%c girisi 1 lendi.\n",ana_girisler[i]);
                        for (int j = 0; j < DevreSatirSayisi -3; j++)
                        {
                            if  (kapilar[j].giris_isim[0] == ana_girisler[i])
                            {
                                kapilar[j].girisler[0] = 1;
                            }
                            if  (kapilar[j].giris_isim[1] == ana_girisler[i])
                            {
                                kapilar[j].girisler[1] = 1;
                            }
                            if  (kapilar[j].giris_isim[2] == ana_girisler[i])
                            {
                                kapilar[j].girisler[2] = 1;
                            }
                        }
                    }
                }

            }




            if(command[u][0] == 'L' || command[u][0] == 'l' )
            {

                for (int i = 0; i < p ; i++)    /*p = ana giris sayisi*/
                {
                    if  (command[u][2] == ana_girisler[i])
                    {
                        printf("%c girisi 0 landi.",ana_girisler[i]);
                        fprintf(logdosya,"%c girisi 0 landi.",ana_girisler[i]);
                        for (int j = 0; j < DevreSatirSayisi -3; j++)
                        {
                            if  (kapilar[j].giris_isim[0] == ana_girisler[i])
                            {
                                kapilar[j].girisler[0] = 0;
                            }
                            if  (kapilar[j].giris_isim[1] == ana_girisler[i])
                            {
                                kapilar[j].girisler[1] = 0;
                            }
                            if  (kapilar[j].giris_isim[2] == ana_girisler[i])
                            {
                                kapilar[j].girisler[2] = 0;
                            }
                        }
                    }
                }

            }
            if(command[u][0] == 'g' || command[u][0] == 'G' )
            {
                for(int i=0; i<DevreSatirSayisi-3; i++)
                {
                    for(int j=0; j<3; j++)
                    {
                        if(kapilar[i].giris_isim[j]==command[u][2])
                        {
                            printf("%c:%d\n",kapilar[i].giris_isim[j],kapilar[i].girisler[j]);
                            fprintf(logdosya,"%c:%d\n",kapilar[i].giris_isim[j],kapilar[i].girisler[j]);

                        }
                    }
                    if(kapilar[i].cikis_isim[0]==command[u][2])
                    {
                        printf("%c:%d\n",kapilar[i].cikis_isim[0],kapilar[i].cikis);
                        fprintf(logdosya,"%c:%d\n",kapilar[i].cikis_isim[0],kapilar[i].cikis);

                    }
                }
            }







            if(!strcmp(command[u],"c")||!strcmp(command[u],"C"))
            {
                fclose(logdosya);
                exit(1);
            }
        }



        goto selection;
    }








    if(!strcmp(secim,"c")||!strcmp(secim,"C"))
    {
        fclose(logdosya);
        exit(1);
    }
    else
    {
        printf("Gecersiz komut\n");
        fprintf(logdosya,"Gecersiz komut\n");
        goto selection;
    }

    return 0;
}

