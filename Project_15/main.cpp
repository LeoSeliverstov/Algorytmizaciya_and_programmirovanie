#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

void keyboard (int M[3][6])
{
    int i, j;
    cout<<"\nVvedite elementy massiva: \n";
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 6; j++)
        {
            cin >> M[i][j];
        }
    }
    
    cout<<"\nMassiv: \n";
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 6; j++)
        {
            printf("%3d ", M[i][j]);
        }
        cout << endl;
    }
}

void file_enter(int M[3][6])
{
    int i, j;
    char name[20];
    cout<<"\nVvedite imya fayla: \n";
    cin>>name;
    std::ifstream file(name);
    for (i = 0; i <18; i++)
    {
        for(j = 0; j < 6; j++)
        {
            file >> M[i][j];
        }
    }
    
    cout<<"\nMassiv:\n";
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 6; j++)
        {
            printf("%3d ", M[i][j]);
        }
        cout << endl;
    }
}

void summa(int M[3][6])
{
    int a, j, sum;
    cout<<"\nVyberite stroku: \n";
    cin>>a;
    sum=0;
    for (j=0 ;j<6 ;j++)
    {
        sum+=M[a][j];
    }
    cout<<"\nSumma stroki: "<<sum;
}

void file_save(int M[3][6])
{
    char name[20];
    cout<<"\nVvedite imya fayla: \n";
    cin>>name;
    FILE *f1;
    f1=fopen(name, "w");
    for (int l=0; l<3; l++)
    {
        for (int k=0; k<6; k++)
        {
            fprintf(f1,"%3d  ", M[l][k]);
        }
        fprintf(f1, "\r\n");
    }
    fclose(f1);
    cout<<"\nProizvedena zapis v fayl.";
}

int main()
{
    int i, j, sw, sw1, sum, c1=1, a, M[3][6];
    char name[20];
    printf("\n\nMENU:\n1) Vvesti massiv s klaviatury\n2) Chtenie massiva iz fayla\n\n");
    
    while(c1)
    {
        cout<<"\nVvedite comandu: ";
        cin>>sw1;
        
        switch(sw1)
        {
            case 1:
                keyboard(M);
                c1=0;
            break;
            
            case 2:
                file_enter(M);
                c1=0;
            break;
            
            default: printf("\nOshibka: nepravilny symvol.\n\n");
        }
    }
    
    printf("\n\n\nMENU:\n1) Raschet summy elementov stroki\n2) Zapis dannyh v fayl\n3) Vyhod");
    
    while(1)
    {
        cout<<"\n\n\nVvedite comandu: ";
        cin>>sw;
        
        switch(sw)
        {
            case 1:
                summa(M);
            break;
            
            case 2:
                file_save(M);
            break;
            
            default: return 0;
        }
    }
}
