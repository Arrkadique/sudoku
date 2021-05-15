//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <vcl.h>
TForm1 *Form1;
//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	ComboBox1->Items->Add("3x3");
	ComboBox1->Items->Add("6x6");
	ComboBox1->Items->Add("9x9");
	StringGrid1->Options = StringGrid1->Options << goEditing;
}
void randSort(int *m, int size)
{
	for(int i = 0; i < size; i++){
		m[i] = i + 1;
	}

}
void allsort(int **g, int* m, int size){
		for(int i = 0; i < size; i++){
			g[i][0] = m[i];;
		}
		if(size == 9){
		for(int i = 1; i < size; i++){
			for(int j = 0; j < size; j++){
			if(i < 3)
				switch(j){
					case 0:
					g[0][i] = g[size - 6][i - 1];break;
					case 1:
					g[1][i] = g[size - 5][i - 1];break;
					case 2:
					g[2][i] = g[size - 4][i - 1];break;
					case 3:
					g[3][i] = g[size - 3][i - 1];break;
					case 4:
					g[4][i] = g[size - 2][i - 1];break;
					case 5:
					g[5][i] = g[size - 1][i - 1];break;
					case 6:
					g[6][i] = g[size - size][i - 1];break;
					case 7:
					g[7][i] = g[size - 8][i - 1];break;
					case 8:
					g[8][i] = g[size - 7][i - 1];break;
				}
			if (i >= 3) {
				switch(j){
					case 0:
					g[0][i] = g[size - 8][i - 3];break;
					case 1:
					g[1][i] = g[size - 7][i - 3];break;
					case 2:
					g[2][i] = g[size - 6][i - 3];break;
					case 3:
					g[3][i] = g[size - 5][i - 3];break;
					case 4:
					g[4][i] = g[size - 4][i - 3];break;
					case 5:
					g[5][i] = g[size - 3][i - 3];break;
					case 6:
					g[6][i] = g[size - 2][i - 3];break;
					case 7:
					g[7][i] = g[size - 1][i - 3];break;
					case 8:
					g[8][i] = g[size - size][i - 3];break;
				}
			}
			}
		}
		}
		if(size == 6){
		for(int i = 1; i < size; i++){
			for(int j = 0; j < size; j++){
            if (i < 2) {
				switch(j){
					case 0:
					g[0][i] = g[size - 3][i - 1];break;
					case 1:
					g[1][i] = g[size - 2][i - 1];break;
					case 2:
					g[2][i] = g[size - 1][i - 1];break;
					case 3:
					g[3][i] = g[size - size][i - 1];break;
					case 4:
					g[4][i] = g[size - 5][i - 1];break;
					case 5:
					g[5][i] = g[size - 4][i - 1];break;
				}
			}
			if(i >= 2)
				switch(j){
					case 0:
					g[0][i] = g[size - 5][i - 2];break;
					case 1:
					g[1][i] = g[size - 4][i - 2];break;
					case 2:
					g[2][i] = g[size - 3][i - 2];break;
					case 3:
					g[3][i] = g[size - 2][i - 2];break;
					case 4:
					g[4][i] = g[size - 1][i - 2];break;
					case 5:
					g[5][i] = g[size - size][i - 2];break;
				}
			}
		}
		}
		if(size == 3){
			for(int i = 1; i < size; i++){
				for(int j = 0; j < size; j++){
					switch(j){
						case 0:
							g[0][i] = g[size - 2][i - 1];break;
						case 1:
							g[1][i] = g[size - 1][i - 1];break;
						case 2:
							g[2][i] = g[size - size][i - 1];break;
					}
				}
			}
		}
}
void sortsmallrow(int **g,int  size){
	int* buf = new int[size];
	int area;
	int line1, line2;
	if(size == 9){
		area = 1 + rand()% 3;
	} else if(size == 6){
		area = 1 + rand()% 3;
	} else {
		area = 1;
	}
	if(size != 6){
	if(area == 1){
		line1 = rand()% 3;
		line2 = rand()% 3;
		while(line1 == line2){
			line2 = rand()% 3;
		}
		for(int i = 0; i < size; i++){
			buf[i] = g[i][line1];
			g[i][line1] = g[i][line2];
			g[i][line2] = buf[i];
		}
	}
	if(area == 2){
		line1 = 3 + rand()% 3;
		line2 = 3 + rand()% 3;
		while(line1 == line2){
			line2 = 3 + rand()% 3;
		}
		for(int i = 0; i < size; i++){
			buf[i] = g[i][line1];
			g[i][line1] = g[i][line2];
			g[i][line2] = buf[i];
		}
	}
	if(area == 3){
		line1 = 6 + rand()% 3;
		line2 = 6 + rand()% 3;
		while(line1 == line2){
			line2 = 6 + rand()% 3;
		}
		for(int i = 0; i < size; i++){
			buf[i] = g[i][line1];
			g[i][line1] = g[i][line2];
			g[i][line2] = buf[i];
		}
	}
	} else {
		if(area == 1){
		line1 = rand()% 2;
		line2 = rand()% 2;
		while(line1 == line2){
			line2 = rand()% 2;
		}
		for(int i = 0; i < size; i++){
			buf[i] = g[i][line1];
			g[i][line1] = g[i][line2];
			g[i][line2] = buf[i];
		}
	}
	if(area == 2){
		line1 = 2 + rand()% 2;
		line2 = 2 + rand()% 2;
		while(line1 == line2){
			line2 = 2 + rand()% 2;
		}
		for(int i = 0; i < size; i++){
			buf[i] = g[i][line1];
			g[i][line1] = g[i][line2];
			g[i][line2] = buf[i];
		}
	}
    	if(area == 3){
		line1 = 4 + rand()% 2;
		line2 = 4 + rand()% 2;
		while(line1 == line2){
			line2 = 4 + rand()% 2;
		}
		for(int i = 0; i < size; i++){
			buf[i] = g[i][line1];
			g[i][line1] = g[i][line2];
			g[i][line2] = buf[i];
		}
	}
	}
}
void sortsmallcol(int **g,int  size){
	int* buf = new int[size];
	int area;
	int line1, line2;
	if(size == 9){
		area = 1 + rand()% 3;
	} else if(size == 6){
		area = 1 + rand()% 2;
	} else {
		area = 1;
	}
	if(area == 1){
		line1 = rand()% 3;
		line2 = rand()% 3;
		while(line1 == line2){
			line2 = rand()% 3;
		}
		for(int i = 0; i < size; i++){
			buf[i] = g[line1][i];
			g[line1][i] = g[line2][i];
			g[line2][i] = buf[i];
		}
	}
	if(area == 2){
		line1 = 3 + rand()% 3;
		line2 = 3 + rand()% 3;
		while(line1 == line2){
			line2 = 3 + rand()% 3;
		}
		for(int i = 0; i < size; i++){
			buf[i] = g[line1][i];
			g[line1][i] = g[line2][i];
			g[line2][i] = buf[i];
		}
	}
	if(area == 3){
		line1 = 6 + rand()% 3;
		line2 = 6 + rand()% 3;
		while(line1 == line2){
			line2 = 6 + rand()% 3;
		}
		for(int i = 0; i < size; i++){
			buf[i] = g[line1][i];
			g[line1][i] = g[line2][i];
			g[line2][i] = buf[i];
		}
	}
}
int size;
int** secondgen;

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(ComboBox1->ItemIndex == 0){
		size = 3;
		StringGrid1->ColCount=size;
		StringGrid1->RowCount=size;
		StringGrid1->Height = 81;
		StringGrid1->Width = 81;
		int* firstgen = new int[size];
		randSort(firstgen, size);
		secondgen = new int*[size];
		for(int i = 0; i < size; i++){
			secondgen[i] = new int[size];
		}
		allsort(secondgen, firstgen, size);
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				StringGrid1->Cells[i][j] = secondgen[i][j];
			}
		}

	}
	if(ComboBox1->ItemIndex == 1){
		size  = 6;
		StringGrid1->ColCount=size;
		StringGrid1->RowCount=size;
		StringGrid1->Height = 159;
		StringGrid1->Width = 159;
		int* firstgen = new int[size];
		randSort(firstgen, size);
		for(int i = 0; i < size; i++){
			StringGrid1->Cells[i][0] = firstgen[i];
		}
		secondgen = new int*[size];
		for(int i = 0; i < size; i++){
			secondgen[i] = new int[size];

		}
		allsort(secondgen, firstgen, size);
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				StringGrid1->Cells[i][j] = secondgen[i][j];
			}
		}
	}
	if(ComboBox1->ItemIndex == 2){
		size  = 9;
		StringGrid1->ColCount=size;
		StringGrid1->RowCount=size;
		StringGrid1->Height = 237;
		StringGrid1->Width = 237;
		int* firstgen = new int[size];
		randSort(firstgen, size);
		for(int i = 0; i < size; i++){
			StringGrid1->Cells[i][0] = firstgen[i];
		}
		secondgen = new int*[size];
		for(int i = 0; i < size; i++){
			secondgen[i] = new int[size];

		}
		allsort(secondgen, firstgen, size);
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				StringGrid1->Cells[i][j] = secondgen[i][j];
			}
		}
	}

}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button2Click(TObject *Sender)
{
	sortsmallrow(secondgen, size);
	sortsmallcol(secondgen, size);
	for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				StringGrid1->Cells[i][j] = secondgen[i][j];
			}
		}
}
//---------------------------------------------------------------------------

