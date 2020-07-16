#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void logaEkleme(char bufT[]);
void logaEkleme2();
void anlamlandirma();
void degerek();
void degerArti(char degisecek);
void degerEksi(char degisecek);
void degerYazma(char gosterilecek);
struct veriler
{
    char harf;
    int deger;

} degerler[12];

struct kapilar
{
    char girisler[2];
    char devreGiris[2];
    char devreCikis;
    char cikis;
    int girisSayisi;
    int cevap;
    char tur[5];
} kapi[100];
int main()
{

    char temp[100];
    FILE *dosya=fopen("D:\\prolab2\\devre.txt","r");
    FILE *dosya1=fopen("D:\\prolab2\\baska_dosya.txt","r");
    FILE *log=fopen("D:\\prolab2\\log.txt","w");
    FILE *deger=fopen("D:\\prolab2\\deger.txt","r");

    fclose(log);

    char logic;
    char komut[2];
    char kontrol[2];

    printf("Y: Devreyi Yukler\n");
    printf("I: Degerleri ilklendirir\n");
    printf("H: Lojik 1 Yapar\n");
    printf("L: Lojik 0 Yapar\n");
    printf("S: Simule Eder\n");
    printf("G: Ilgili ucun degerini gosterir\n");
    printf("G*: Tum uclarin degerlerini gosterir\n");
    printf("K: 'komut.txt' deki komutlari icra eder \n");
    printf("C: Cikis\n");
    printf(">");



    scanf("%c",&kontrol[0]);
    kontrol[0]=toupper(kontrol[0]);
    if(kontrol[0]=='Y')
    {

        printf("'devre.txt' DOSYASINDAN DEVRE YUKLENDI!\n");
        char nbr[2];
        nbr[0]='Y';
        nbr[1]='\0';
        logaEkleme(nbr);
        char Y[100]= {"'devre.txt' DOSYASINDAN DEVRE YUKLENDI!"};
        logaEkleme2(Y);
        anlamlandirma();

        printf(">");
        fflush(stdin);
        scanf("%c",&kontrol[1]);

        kontrol[1]=toupper(kontrol[1]);
        fflush(stdin);

        if(kontrol[1]=='I')
        {
            printf("'deger.txt' ICINDEKI DEGERLERLE DEVRE DEVRE ILKLENDIRILDI!\n");
            char I[100]= {"'deger.txt' ICINDEKI DEGERLERLE DEVRE ILKLENDIRILDI!"};
            char nbr2[2];
            nbr2[0]='I';
            nbr2[1]='\0';

            logaEkleme(nbr2);
            logaEkleme2(I);
            degerek();
            goto op;
        }
        else exit(1);

    }
    else exit(1);

    while(1)
    {

op:
        printf(">");
        gets(temp) ;


        logaEkleme(temp);
        komut[0]=temp[0];
        komut[1]=temp[1];
        komut[0] = toupper(komut[0]);

        switch(komut[0])
        {

        case 'H':
        {
            char logic3;
            printf(">");
            scanf("%c",&logic3) ;


            degerArti(logic3);

            break;

        }
        case 'L':
        {
            char logic2;
            printf(">");
            scanf("%c",&logic2);

            degerEksi(logic2);

            break;

        }
        case 'S':
        {

            break;

        }
        case 'G':
        {
            if(komut[1]=='*')
            {

                int i;
                char Z[50]= {"Tum Degerler Gosterildi"};
                logaEkleme2(Z);
                for(i=0; i<6; i++)
                {

                    printf("%c %d\n",degerler[i].harf,degerler[i].deger);

                }

            }
            else
            {
                printf(">");
                scanf("%c",&logic) ;


                degerYazma(logic);
            }
            break;

        }

        case 'K':
        {

            break;

        }
        case 'C':
        {
            char J[25]= {"PROGRAM SONLANDIRILDI"};
            logaEkleme2(J);
            goto kacis;
            break;
        }
        default:
            printf("Yanlis Secim\n");
            char J[15]= {"Yanlis Secim"};
            logaEkleme2(J);
        };
        fflush(stdin);
    }

kacis:

    fclose(dosya);
    fclose(dosya1);
    fclose(deger);
    return 0;
}
void logaEkleme(char bufT[])
{
    FILE *log=fopen("D:\\prolab2\\log.txt","a+");

    time_t rawtime;
    struct tm *info;
    char buffer[80];

    time( &rawtime );

    info = localtime( &rawtime );

    strftime(buffer,80,"%x %I:%M%p", info);

    fprintf(log,"%s\t", buffer );
    fprintf(log,"%s\t",bufT);
    fclose(log);

}

void logaEkleme2(char bufT[])
{
    FILE *log=fopen("D:\\prolab2\\log.txt","a+");
    fprintf(log,"%s",bufT);
    fputc('\n',log );
    fclose(log);
}

void anlamlandirma()
{

    FILE *dosya=fopen("D:\\prolab2\\devre.txt","r");
    char buf[100];
    //char buf1[100];
    char buf3;
    int buf2;
    int i=0;
    while(!feof(dosya))
    {

        fscanf(dosya,"%s",buf);
        if(strcmp(buf,".include")==0)
        {

            FILE *dosya1=fopen("D:\\prolab2\\baska_dosya.txt","r");

            while(!feof(dosya1))
            {
                fscanf(dosya1,"%s",buf);
                if(strcmp(buf,".giris")==0)
                {
                    while(1)
                    {
                        fscanf(dosya1," %c",&buf3);
                        if(buf3=='#')
                        {
                            i=0;
                            break;

                        }
                        kapi[i].devreGiris[i]=buf3;
                   //     printf("%c\n", kapi[i].devreGiris[i]);
                        i++;

                    }

                }
             //   printf("'buf->%s'\n",buf);
                if(strcmp(buf,".cikis")==0)
                {
                    while(1)
                    {
                        fscanf(dosya1," %c",&buf3);
                        if(buf3=='#')
                        {
                            i=0;
                            break;

                        }
                        kapi[i].devreCikis=buf3;
                     //   printf("%c\n", kapi[i].devreCikis);
                        i++;

                    }

                }


                int a=0;

                while(1)
                {
                    if(strcmp(buf,".kapi")==0)
                    {


                        fscanf(dosya1," %s",buf);
                        strcpy(kapi[i].tur,buf);
                      //  printf("DEBUG1 '%s'\n",kapi[i].tur);

                        fscanf(dosya1,"%d",&buf2);
                        kapi[i].girisSayisi=buf2;
                     //   printf("DEBUG2 '%d'\n",kapi[i].girisSayisi);

                        fscanf(dosya1," %c",&buf3);
                        kapi[i].cikis=buf3;
                     //   printf("%c\n",kapi[i].cikis);


                        fscanf(dosya1," %c",&buf3);
                        kapi[i].girisler[0]=buf3;
                    //    printf("%c\n",kapi[i].girisler[0]);


                        fscanf(dosya1," %c",&buf3);
                        kapi[i].girisler[1]=buf3;
                     //   printf("%c\n",kapi[i].girisler[1]);
                        a++;



                        fscanf(dosya1," %d",&buf2);
                        kapi[i].cevap=buf2;
                    //    printf("%d\n",buf2);



                    }
                    fscanf(dosya1," %s",buf);
                    if(strcmp(buf,".son")==0)

                        break;
                }

            }

        }

        i=0;


        if(strcmp(buf,".giris")==0)
        {
            while(1)
            {
                fscanf(dosya," %c",&buf3);
                if(buf3=='#')
                {
                    i=0;
                    break;

                }
                kapi[i].devreGiris[i]=buf3;
            //    printf("%c\n", kapi[i].devreGiris[i]);
                i++;

            }

        }


        if(strcmp(buf,".cikis")==0)
        {

            fscanf(dosya," %c",&buf3);
            kapi[i].devreCikis=buf3;
          //  printf("%c\n", kapi[i].cikis);
            i++;
            if(buf3=='#')
            {
                i=0;
                break;
            }


        }

        int a=0;

        while(1)
        {
            if(strcmp(buf,".kapi")==0)
            {


                fscanf(dosya," %s",buf);
                strcpy(kapi[i].tur,buf);
              //  printf("DEBUG1 '%s'\n",kapi[i].tur);

                fscanf(dosya,"%d",&buf2);
                kapi[i].girisSayisi=buf2;
           //     printf("DEBUG2 '%d'\n",kapi[i].girisSayisi);

                fscanf(dosya," %c",&buf3);
                kapi[i].cikis=buf3;
              //  printf("%c\n",kapi[i].cikis);


                fscanf(dosya," %c",&buf3);
                kapi[i].girisler[0]=buf3;
             //   printf("%c\n",kapi[i].girisler[0]);



                fscanf(dosya," %c",&buf3);
                kapi[i].girisler[1]=buf3;
            //    printf("%c\n",kapi[i].girisler[1]);




                fscanf(dosya," %d",&buf2);
                kapi[i].cevap=buf2;
             //   printf("%d\n",kapi[i].cevap);

                a++;

            }
            fscanf(dosya," %s",buf);
            if(strcmp(buf,".son")==0)

                break;
        }

    }
}


void degerek()
{
    FILE *deger=fopen("d:\\prolab2\\deger.txt","r");
    char buf[100];
    char bufe;
    int bufte,i;
    fgets(buf, 100, deger);
    fseek(deger, 0, SEEK_SET);

    for(i=0; i<6; i++)
    {
        fscanf(deger," %c",&bufe);
        degerler[i].harf=bufe;

        fscanf(deger," %d",&bufte);
        degerler[i].deger=bufte;

    }
    fclose(deger);
}

void degerArti(char degisecek)
{

    switch(degisecek)
    {

    case 'a':
    {


        degerler[0].deger=1;
        printf("a -> 1\n");
        char Z[10]= {"a -> 1"};
        logaEkleme2(Z);
        break;

    }
    case 'b':
    {


        degerler[1].deger=1;

        printf("b -> 1\n");
        char Z[10]= {"b -> 1"};
        logaEkleme2(Z);
        break;




    }
    case 'c':
    {

        degerler[2].deger=1;

        printf("c -> 1\n");
        char Z[10]= {"c -> 1"};
        logaEkleme2(Z);
        break;

    }
    case 'd':
    {

        degerler[3].deger=1;
        printf("d -> 1\n");
        char Z[10]= {"d -> 1"};
        logaEkleme2(Z);
        break;



    }
    case 'e':
    {


        degerler[4].deger=1;
        printf("e -> 1\n");
        char Z[10]= {"e -> 1"};
        logaEkleme2(Z);
        break;



    }
    case 'f':
    {

        degerler[5].deger=1;
        printf("f -> 1\n");
        char Z[10]= {"f -> 1"};
        logaEkleme2(Z);
        break;



    }

    default:
        return ;
    };

}

void degerEksi(char degisecek)
{

    switch(degisecek)
    {

    case 'a':
    {


        degerler[0].deger=0;
        printf("a -> 0\n");
        char Z[10]= {"a -> 0"};
        logaEkleme2(Z);
        break;
    }
    case 'b':
    {


        degerler[1].deger=0;
        printf("b -> 0\n");
        char Z[10]= {"b -> 0"};
        logaEkleme2(Z);
        break;



    }
    case 'c':
    {

        degerler[2].deger=0;
        printf("c -> 0\n");
        char Z[10]= {"c -> 0"};
        logaEkleme2(Z);
        break;


    }
    case 'd':
    {

        degerler[3].deger=0;
        printf("d -> 0\n");
        char Z[10]= {"d -> 0"};
        logaEkleme2(Z);
        break;



    }
    case 'e':
    {


        degerler[4].deger=0;
        printf("e -> 0\n");
        char Z[10]= {"e -> 0"};
        logaEkleme2(Z);
        break;



    }
    case 'f':
    {

        degerler[5].deger=0;

        printf("f -> 0\n");
        char Z[10]= {"f -> 0"};
        logaEkleme2(Z);
        break;


    }

    default:
        return ;
    };


}


void degerYazma(char gosterilecek)
{

    switch(gosterilecek)
    {

    case 'a':
    {


        printf("a ->%d \n",degerler[0].deger);
        if(degerler[0].deger==1)
        {
            char Z[10]= {"a -> 1"};
            logaEkleme2(Z);
        }
        else if(degerler[0].deger==0)
        {
            char Z[10]= {"a -> 0"};
            logaEkleme2(Z);
        }
        break;

    }

    case 'b':
    {


        printf("b ->%d \n",degerler[1].deger);
        if(degerler[1].deger==1)
        {
            char Z[10]= {"b -> 1"};
            logaEkleme2(Z);
        }
        else if(degerler[1].deger==0)
        {
            char Z[10]= {"b -> 0"};
            logaEkleme2(Z);
        }
        break;



    }
    case 'c':
    {

        printf("c ->%d \n",degerler[2].deger);
        if(degerler[2].deger==1)
        {
            char Z[10]= {"c -> 1"};
            logaEkleme2(Z);
        }
        else if(degerler[2].deger==0)
        {
            char Z[10]= {"c -> 0"};
            logaEkleme2(Z);
        }
        break;


    }
    case 'd':
    {

        printf("d ->%d \n",degerler[3].deger);
        if(degerler[3].deger==1)
        {
            char Z[10]= {"d -> 1"};
            logaEkleme2(Z);
        }
        else if(degerler[3].deger==0)
        {
            char Z[10]= {"d -> 0"};
            logaEkleme2(Z);
        }
        break;



    }
    case 'e':
    {


        printf("e ->%d \n",degerler[4].deger);
        if(degerler[4].deger==1)
        {
            char Z[10]= {"e -> 1"};
            logaEkleme2(Z);
        }
        else if(degerler[4].deger==0)
        {
            char Z[10]= {"e -> 0"};
            logaEkleme2(Z);
        }
        break;



    }
    case 'f':
    {

        printf("f ->%d \n",degerler[5].deger);
        if(degerler[5].deger==1)
        {
            char Z[10]= {"f -> 1"};
            logaEkleme2(Z);
        }
        else if(degerler[5].deger==0)
        {
            char Z[10]= {"f -> 0"};
            logaEkleme2(Z);
        }
        break;


    }

    default:
        return ;
    };


}
