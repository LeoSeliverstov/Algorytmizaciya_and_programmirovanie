#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

void keyboard_enter(float M[3][6])
{
    int i, j;
    cout<<"\nVvedite elementy massiva: \n";
    for (i = 0; i < 3; i++)
    {
        for(j = 0; j < 6; j++)
        {
            cin >> M[i][j];
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%.0f  ", M[i][j]);
        }
        cout << endl;
    }
}

void file_enter(float M[3][6])
{
    int i, j;
    std::ifstream file("massiv1.txt");
    for (i = 0; i <3; i++)
    {
        for (j = 0; j < 6; j++)
        {
            file >> M[i][j];
        }
    }
    cout<<"\nMassiv: \n";
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 6; j++)
        {
            printf("%.0f   ", M[i][j]);
        }
        cout << endl;
    }
}

void otr(float s1, int i, int j, float M[3][6])
{
    s1=0;
    for (i = 0; i <3; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (M[i][j]<0)
                s1=s1+1;
        }
    }
    cout<<"\nChislo otricatelnuh elementov: "<<s1;
}

int pol(int i, int j, float M[3][6])
{
    int s2=0;
    for (i = 0; i <3; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if (M[i][j]>0)
                s2=s2+1;
        }
    }
    cout<<"\nchislo polojitelnyh elementov: "<<s2;
    return s2;
}

int nul (int i, int j, float M[3][6])
{
    int s3=0;
    for (i = 0; i <3; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if (M[i][j]==0)
                s3++;
        }
    }
    cout<<"\nChislo nulevyh elementov: "<<s3;
}

void save(int i, int j, int s1, int s2, int s3, float M[3][6])
{
    s1=0;
    for (i = 0; i <3; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if (M[i][j]<0)
                s1=s1+1;
        }
    }
    
    s2=0;
    for (i = 0; i <3; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if (M[i][j]>0)
                s2=s2+1;
        }
    }
    
    s3=0;
    for (i = 0; i <3; i++)
    {
        for(j = 0; j < 6; j++)
        {
            if (M[i][j]==0)
                s3++;
        }
    }
    
    FILE *f1, *f2;
    f1=fopen("massiv2.txt", "w");
    f2=fopen("S.txt", "w");
    for (int l=0; l<3; l++)
    {
        for (int k=0; k<6; k++)
        {
            fprintf(f1,"%.5f  ", M[l][k]);
        }
        fprintf(f1, "\r\n");
    }
    fprintf(f2,"\n %d %d %d", s1, s2, s3);
    fclose(f1);
    fclose(f2);
    cout<<"\nDannye zapisany v fayl.";
}

int main()
{
    int i, j, sw, sw1, c1=1, s1, s2, s3;
    float M[3][6];
    printf("\n\nMENU:\n1) Vvesti massiv s klaviatury\n2) Chtenie massiva iz fayla\n\n");
    
    while(c1)
    {
        cout<<"\nVvedite comandu: ";
        cin>>sw1;
        switch(sw1)
        {
            case 1:
                keyboard_enter(M);
                c1=0;
            break;
            
            case 2:
                file_enter(M);
                c1=0;
            break;
            
            default: printf("\nОOshibka: nepravilny symvol.\n\n");
        }
    }
    
    printf("\n\n\nМMENU:\n1) Chislo otricatelnyh elementov\n2) Chislo polojitelnyh elementov\n3) Chislo nulevyh elementov\n4) Zapis dannyh v fayl\n5) Vyhod");
    while(1)
    {
        cout<<"\n\n\nVvedite comandu: ";
        cin>>sw;
        switch(sw)
        {
            case 1:
                otr(s1, i, j, M);
                break;
        
            case 2:
                pol(i, j, M);
                break;
            
            case 3:
                nul(i, j, M);
                break;
            
            case 4:
                save(i, j, s1, s2, s3, M);
                break;
           
            default: return 0;
        }
    }
}
