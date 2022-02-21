//---------------------------------------------------------------------------
// Разработайте приложение в соответствии с заданием.
// На форме предоставьте пользователю возможность вводить значения (в поле для ввода Edit).
// При нажатии на клавишу Enter (если поле не пусто) его содержимое автоматически
// заносится в список выбора (TListBox). Таким образом, пользователь может ввести
// последовательность значений. Добавьте на форму две кнопки, по нажатию на которые
// существляется:
//•	замена минимального значения максимальным;
//•	нахождение суммы значений.
//Обеспечьте контроль вводимых данных.

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
float a = 0;
float arr[20];
int score = 0;
int i = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
		if (Key == VK_RETURN)
		  {
			score += 1;
			a = StrToFloat(Edit1->Text);
			for (i; i < score; i++)
			{
				arr[i] = a;

			}
		  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
	ListBox1->Clear();

	int	min_ = arr[0];
	int max_ = arr[0];

	for (int j = 0; j < score; j++)
	{
		if (arr[j] < min_)
		{
			min_ = arr[j];
		}

		if (arr[j] > max_)
		{
			max_ = arr[j];
        }
	}


	for (int b = 0; b < score; b++)
	{   if (arr[b] == min_)
		{
			arr[b] = max_;
        }
		ListBox1->Items->Add(arr[b]);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
	ListBox1->Clear();

	int sum_ = 0;

	for (int i = 0; i < score; i++)
	{
		sum_ += arr[i];
	}

	ListBox1->Items->Add(sum_);
}
//---------------------------------------------------------------------------
