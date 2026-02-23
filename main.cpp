#include <cstring>
#include "graphics.h"

using namespace std;

int lit[5];
char cuv[5], word[7][5], c;

void continua()
{
    setcolor(WHITE);
    settextstyle(8, 0 ,3);
    int X=getmaxx()/2;
    int w=textwidth((char *)"Apasa orice tasta pentru a continua");
    outtextxy(X-w/2, 700, (char *)"Apasa orice tasta pentru a continua");
    getch();
    cleardevice();
}

void introducere()
{
    int X=getmaxx()/2;
    int Y=getmaxy()/2;
    settextstyle(8, 0, 4);
    int w=textwidth((char *)"mini");
    int h=textheight((char *)"mini");
    outtextxy(X-w/2-100, Y-h/2-40, (char *)"mini");
    settextstyle(10, 0, 5);
    w=textwidth((char *)"WORDLE");
    h=textheight((char *)"WORDLE");
    outtextxy(X-w/2, Y-h/2, (char *)"WORDLE");
    setlinestyle(SOLID_LINE, 0, 2);
    for(int i=0;i<=3;i++)
    {
        rectangle(200+i*100,200,300+i*100,300);
        rectangle(200+i*100,450,300+i*100,550);
        delay(2000);
    }
    continua();
}

void citire()
{
    c= (char)getch();
    int X=getmaxx()/2;
    settextstyle(8, 0, 3);
    int w=textwidth((char *)"                                                                                    ");
    outtextxy(X-w/2, 700, (char *)"                                                                              ");
    if(c>=97 && c<=122) c= (char)(static_cast<int>(c)-32);
    if(!(c>=65 && c<=90) && c!=8)
    {
        X=getmaxx()/2;
        w=textwidth((char *)"Caracterul nu este valid. Reintroduceti litera.");
        setcolor(RED);
        outtextxy(X-w/2, 700, (char *)"Caracterul nu este valid. Reintroduceti litera.");
        delay(100);
        setcolor(WHITE);
        outtextxy(X-w/2, 700, (char *)"Caracterul nu este valid. Reintroduceti litera.");
        delay(100);
        setcolor(RED);
        outtextxy(X-w/2, 700, (char *)"Caracterul nu este valid. Reintroduceti litera.");
        delay(100);
        setcolor(WHITE);
        outtextxy(X-w/2, 700, (char *)"Caracterul nu este valid. Reintroduceti litera.");
        citire();
    }//sclipici
}

void reguli()
{
    int X=getmaxx()/2;
    settextstyle(10, 0, 5);
    int w=textwidth((char *)"Reguli");
    outtextxy(X-w/2, 50, (char *)"Reguli");
    settextstyle(8, 0, 2);
    w=textwidth((char *)"Un jucator introduce un cuvant de 4 litere.");
    outtextxy(X-w/2, 100, (char *)"Un jucator introduce un cuvant de 4 litere.");
    w=textwidth((char *)"Alt jucator va avea 6 incercari sa afle cuvantul.");
    outtextxy(X-w/2, 125, (char *)"Alt jucator va avea 6 incercari pentru a afla cuvantul.");
    w=textwidth((char *)"Dupa fiecare incercare se va marca fiecare litera cu o culoare:");
    outtextxy(X-w/2, 150, (char *)"Dupa fiecare incercare se va marca fiecare litera cu o culoare:");
    settextstyle(10, 0, 3);
    setcolor(12);
    w=textwidth((char *)"ROSU - litera nu se gaseste in cuvant");
    outtextxy(X-w/2, 200, (char *)"ROSU - litera nu se gaseste in cuvant");
    setcolor(14);
    w=textwidth((char *)"GALBEN - litera exista in cuvant, dar pe alta pozitie");
    outtextxy(X-w/2, 250, (char *)"GALBEN - litera exista in cuvant, dar pe alta pozitie");
    setcolor(10);
    w=textwidth((char *)"VERDE - litera exista si e pe pozitia corecta");
    outtextxy(X-w/2, 300, (char *)"VERDE - litera exista si e pe pozitia corecta");
    continua();
}

void cuvant()
{
    settextstyle(8, 0, 2);
    setlinestyle(SOLID_LINE, 0, 2);
    int X=getmaxx()/2;
    int w=textwidth((char *)"Introduceti un cuvant valid de 4 litere, apoi apasati ENTER");
    outtextxy(X-w/2, 400, (char *)"Introduceti un cuvant valid de 4 litere, apoi apasati ENTER");
    for(int i=0;i<=3;i++)
        rectangle(200+i*100,200,300+i*100,300);
    for(int i=0;i<=4;i++)
    {
        if(i!=4) citire();
        else c= (char)getch();
        if(c!=8)
        {
            if(i!=4)
            {
                settextstyle(10, 0, 4);
                cuv[i]=c;
                outtextxy(250+i*100,250,(char *)"*");
            }
        }
        else
        {
            if(i!=0)
            {
                i--;
                outtextxy(250+i*100,250,(char *)" ");
                i--;
            }
            else i--;
        }
    }
    for(int t=0;t<=3;t++)
        for(int s=0;s<=3;s++)
            if(cuv[t]==cuv[s]) lit[t]++;
    cleardevice();
}

void joc()
{
    setlinestyle(SOLID_LINE, 0, 2);
    for(int i=0;i<=5;i++)
        for(int j=0;j<=3;j++)
            rectangle(200+j*100,50+i*100,300+j*100,150+i*100);
        //int X=getmaxx()/2;
    settextstyle(10, 0, 5);
    outtextxy(100, 200, (char *)"m");
    outtextxy(100, 300, (char *)"i");
    outtextxy(100, 400, (char *)"n");
    outtextxy(100, 500, (char *)"i");

    outtextxy(700, 225, (char *)"W");
    outtextxy(700, 275, (char *)"O");
    outtextxy(700, 325, (char *)"R");
    outtextxy(700, 375, (char *)"D");
    outtextxy(700, 425, (char *)"L");
    outtextxy(700, 475, (char *)"E");

}

void castig()
{
    cleardevice();
    int X=getmaxx()/2;
    settextstyle(8, 0, 5);
    int w=textwidth((char *)"Felicitari!");
    outtextxy(X-w/2, 350, (char *)"Felicitari!");
    w=textwidth((char *)"Ai gasit cuvantul :D");
    outtextxy(X-w/2, 400, (char *)"Ai gasit cuvantul :D");
    continua();
}

void pierdut()
{
    cleardevice();
    int X=getmaxx()/2;
    settextstyle(8, 0, 5);
    int w=textwidth((char *)"Ai pierdut! Cuvantul era:");
    outtextxy(X-w/2, 350, (char *)"Ai pierdut! Cuvantul era:");
    settextstyle(10, 0, 8);
    w=textwidth(cuv);
    outtextxy(X-w/2, 450, cuv);
    continua();
}

void incercare()
{
    int i;
    for(i=0;i<=5;i++)
    {
        setcolor(WHITE);
        int v=0;
        for(int j=0;j<=4;j++)
        {
            if(j!=4) citire();
            else c = (char)getch();
            if(c!=8)
            {
                if(j!=4)
                {
                    settextstyle(10,0,4);
                    word[i][j]=c;
                    char sch[2];
                    sch[0]=c; sch[1]='\0';
                    outtextxy(250+j*100,100+i*100,sch);
                }
            }
            else
            {
                if(j!=0)
                {
                    j--;
                    outtextxy(250+j*100,100+i*100,(char *)"  ");
                    j--;
                }
                else j--;
            }
        }
        int clit[5];
        for(int j=0;j<=3;j++)
            clit[j]=lit[j];
        char cword[5], cul[5]="0000";
        strcpy_s(cword,word[i]);
        for(int j=0;j<=3;j++)
        {
            if(cuv[j]==cword[j])
            {
                cul[j]='1';
                clit[j]--;
                cword[j]='*';
            }
        }
        for(int j=0;j<=3;j++)
        {
            int ok=0;
            for(int t=0;t<=3 && !ok;t++)
            {
                if(cuv[t]==cword[j] && clit[t]!=0)
                {
                    cul[j]='2';
                    clit[t]--;
                    cword[j]='*';
                    ok=1;
                }
            }
        }
        for(int j=0;j<=3;j++)
        {
            if(cul[j]=='1')
            {
                setfillstyle(SOLID_FILL,GREEN);
                floodfill(250+j*100,100+i*100,WHITE);
                v++;
            }
            if(cul[j]=='2')
            {
                setfillstyle(SOLID_FILL,6);
                floodfill(250+j*100,100+i*100,WHITE);
            }
            if(cul[j]=='0')
            {
                setfillstyle(SOLID_FILL,RED);
                floodfill(250+j*100,100+i*100,WHITE);
            }
            delay(500);
        }
        //cout<<cul<<" "<<word[i]<<endl;
        if(v==4)
        {
            castig();
            i=6;
        }
    }
    if(i!=7) pierdut();
}

void testfont()
{
    getch();
    for(int i=1;i<=16;i++)
    {
        setcolor(i);
        settextstyle(8, 0 ,3);
        outtextxy(200, 200+i*25, (char *)"Apasa orice tasta pentru a continua");
    }
}

int main()
{
    initwindow(800,800);
    introducere();
    reguli();
    cuvant();
    joc();
    incercare();
    //testfont();
    closegraph();
    return 0;
}
