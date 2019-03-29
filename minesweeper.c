#include<iostream>
#include<vector>
#include<utility>
#include<time.h>
#include<stdlib.h>
#include<stack>

using namespace std;

int display(vector<vector<int> >target, vector<vector<bool> >target2, int panjang, int lebar)
{
	int flag=0;
	int n=0;
	printf("X/Y\t");
    while(n<panjang){
        if(n<10)
        printf(" %d ",n);
        else
        printf("%d ",n);
        n++;
    }
    cout<<"\n";
	for(int i=0;i<lebar;i++)
	{
		printf("%d\t",i);
		for(int j=0;j<panjang;j++)
		{
			if(target2[i][j]==true)
			{
//					printf("%d",target[i][j]);
				printf("|-|");
			}
			else
			{
				if(target[i][j]==-1)
				{
					printf("|B|");
					flag = 1;
				}
				else if (target[i][j]==0)
				{
					printf("| |");
				}
				else
				{
					printf("|%d|",target[i][j]);
				}	
			}

		}
		printf("\n");
	}
	return flag;
}

pair<vector<vector<int> >,vector<vector<bool> > > initialize (int panjang,int lebar)
{
	vector<vector<int> > layerBelakang;
	vector<vector<bool> > layerDepan;
	
	for(int i=0;i<lebar;i++)
	{
		vector<int> layerBelakangTemp;
		vector<bool> layerDepanTemp;
		for(int j=0;j<panjang;j++)
		{
			layerBelakangTemp.push_back(0);
			layerDepanTemp.push_back(true);
		}
		layerBelakang.push_back(layerBelakangTemp);
		layerDepan.push_back(layerDepanTemp);
		
		layerBelakangTemp.clear();
		layerDepanTemp.clear();
	}
	return make_pair(layerBelakang,layerDepan);
}

void menu(int pilihan)
{
		printf("==================================MINESWEEPER==================================\n");
		printf("                  Wasilatul D.N.  Putri E.P.S.  Philip A.S.\n");
		printf("                      17-0004       17-0039       17-0111\n\n");
		if(pilihan==1)
		printf("Level : beginner 10x8 10 bom\n\n");
		if(pilihan==2)
		printf("Level : intermediate 16x16 40 bom\n\n");
		if(pilihan==3)
		printf("Level : expert 25x25 99 bom\n\n");
		if(pilihan==4)
		printf("Level : custom\n\n");
}

int main()
{
	int pilihan=0;
	int panjang,lebar;
	
	
	while(1)
	{
		menu(pilihan);
		printf("Pilih menu :\n");
		printf("1. Beginner\n");
		printf("2. Intermediate\n");
		printf("3. Expert\n");
		printf("4. Custom\n");
		printf("5. Keluar\n\n");
		printf("Masukkan pilihan > ");
		scanf("%d",&pilihan);
		if(pilihan == 5)
		{
			break;
		}
		switch(pilihan)
		{
			case 1:
				{
					panjang = 8;
					lebar = 10;
					break;
				}
			case 2:
				{
					panjang = 16;
					lebar = 16;
					break;
				}
			case 3:
				{
					panjang = 25;
					lebar = 25;
					break;
				}
			case 4:
				{
					printf("ukuran (x * x) maksimal 40 : ");
					scanf("%d",&panjang);
					lebar = panjang;
					
					break;
				}
		
		}
		
		pair<vector<vector<int> >,vector<vector<bool> > > res;
		res=initialize(panjang,lebar);
		vector<vector<int> > layerBelakang = res.first;
		vector<vector<bool> > layerDepan = res.second;
		menu(pilihan);
		display(layerBelakang,layerDepan,panjang,lebar);
		system("pause");
		system("cls");
	}
return 0;
}
