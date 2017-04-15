#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
    int i, j, sw, sw1, c1=1, a1, a2, M[4][5];
    char name_file[20];
    printf("\n\nMENU:\n1) Vvesti massiv s klaviatury\n2) Chtenie massiva iz fayla\n\n");
    
    while(c1)
    {
        cout<<"\nVvedite comandu: ";
        cin>>sw1;
        
        switch(sw1)
        {
            case 1:
            {
                cout<<"\nVvedite elementy massiva: \n";
                for(i = 0; i < 4; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        cin >> M[i][j];
                    }
                }
                
                cout<<"\nMassiv: \n";
                for(i = 0; i < 4; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        cout<< M[i][j] <<"  ";
                    }
                    cout << endl;
                }
                c1=0;
            }
            break;
            
            case 2:
            {
                std::ifstream file("massiv1.txt");
                for (i = 0; i <20; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        file >> M[i][j];
                    }
                }

                cout<<"\nMassiv: \n";
                for(i = 0; i < 4; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        cout<<M[i][j] << "  ";
                    }
                    cout << endl;
                }
                c1=0;
            }
            break;
            
            default: printf("\nOshibka: nepravilny symvol.\n\n");
        }
    }
    
    printf("\n\n\nMENU:\n1) Izmenenie elementa massiva\n2) Zapis dannyh v fayl\n3) Vyhod");
    
    while(1)
    {
        cout<<"\n\n\nVvedite comandu: ";
        cin>>sw;
        
        switch(sw)
        {
            case 1:
            {
                cout<<"\nVyberite stroku: \n";
                cin>>a1;

                cout<<"\nVyberite stolbec: \n";
                cin>>a2;


                cout<<"\nVvedite novoe znacenie elementa: \n";
                cin >> M[a1][a2];
                cout<<"\nMassiv: \n";
                for(i = 0; i < 4; i++)
                {
                    for(j = 0; j < 5; j++)
                    {
                        cout<<M[i][j] << "  ";
                    }
                    cout << endl;
                }
            }
            break;
            
            case 2:
            {
                FILE *f1, *f2;
                cout<<"Vvedie imya fayla: ";
                cin>>name_file;
                f1=fopen(name_file, "w");             
                for (int l=0; l<4; l++)
                {
                    for (int k=0; k<5; k++)
                    {
                        fprintf(f1,"  %d", M[l][k]);
                    }
                    fprintf(f1, "\r\n");
                }
                fclose(f1);
                
                cout<<"\nDannye zapisany v fayl.";
            }
            break;
           
            default: return 0;
        }
    }
}
