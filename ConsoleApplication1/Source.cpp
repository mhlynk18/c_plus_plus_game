#include"Source.h"

#include"Header.h"



void Create_Backgroud()
{
	int i = 20 , j = 0 , loading_x = 45;
	while (PlaySound(TEXT("C:\\Users\\COMPUTER\\Downloads\\4.wav"), NULL, SND_FILENAME))
	{
		for (int i = 20; i <= 120; i++)
		{
			ShowCur(false);
			//i = i + 20;
			TextColor(14);
			gotoXY(i, 10);
			cout << "#";
			gotoXY(i, 30);
			cout << "#";
			//Sleep(100);
			//i++;
		}

		int ix = 20;
		for (int j = 0; j < 30; j++)
		{
			ShowCur(false);
			TextColor(15);
			gotoXY(ix, j);
			cout << "#";
			gotoXY(ix + 100, j);
			cout << "#";
			//Sleep(100);
			//j++;
		}


		string str;
		ifstream filein;
		filein.open("hinh.txt", ios::in);
		ShowCur(false);
		int tx = 38, ty = 18;
		while (getline(filein, str).good())
		{

			gotoXY(tx, ty++);
			cout << str;
		}
		gotoXY(tx, ty++);
		cout << str;
		filein.close();
		//}

		// create loading...
		while (loading_x <= 90)
		{
			TextColor(12);
			gotoXY(64, 27);
			cout << "Loading...";


			gotoXY(loading_x++, 25);
			TextColor(97);
			cout << " ";
			Sleep(50);
		}
	}
		


}

void high_light(int x, int y, int w, int h, string str, int color_hl)
{
	for (int j = y + 1; j < y + h; j++)
	{
		for (int i = x + 1; i < x + w; i++)
		{
			TextColor(color_hl);
			gotoXY(i, j);
			cout << " ";
		}
	}
	SetColor(color_hl);
	gotoXY(x + 1, y + 1);
	cout << str;
}

void Create_box(int toadoX , int toadoY , int w , int h)
{
	if (h <= 1 || w <= 1) return;
	for (int j = toadoY + 1; j < toadoY + h; j++)
	{
		for (int i = toadoX + 1; i < toadoX + w ; i++)
		{
			TextColor(34);
			gotoXY(i, j); 
			cout << " ";
		}
	}
	SetColor(11);
	gotoXY(toadoX + 1, toadoY + 1);
	cout << "Start";
	for (int i = toadoX; i <= toadoX + w; i++)
	{
		gotoXY(i, toadoY);
		cout << char(196);
		gotoXY(i, toadoY + h);
		cout << char(196);
	}

	for (int j = toadoY; j <= toadoY + h; j++)
	{
		gotoXY(toadoX, j);
		cout << char(179);
		gotoXY(toadoX + w, j);
		cout << char(179);
	}

	gotoXY(toadoX, toadoY);
	cout << char(218);
	gotoXY(toadoX, toadoY + h);
	cout << char(192);
	gotoXY(toadoX + w, toadoY);
	cout << char(191);
	gotoXY(toadoX+w, toadoY + h);
	cout << char(217);

}
void n_box(int x, int y, int w, int h, int t_color, int b_color, string str, int sl)
{
	for (int i = 0; i < sl; i++)
	{
		Create_box(50, 5 + (i * 2), 20, 2);
		if (i != 0)
		{
			gotoXY(50, 5 + (i * 2));
			cout << char(195);
			gotoXY(50 + 20, 5 + (i * 2));
			cout << char(180);
		}
	}
}

void Menu()
{
	ShowCur(false);
	int w = 20;
	int h = 2;
	int t_color = 11;
	int b_color = 1;
	int color_hl = 75;
	string str = "Start";
	int sl = 4;
	n_box(50, 5, w, h, t_color, b_color, str, sl);
	high_light(50, 5, w, h, str, color_hl);

	int toadoXSang = 50, toadoYSang = 5;
	int	old_toadoX = toadoXSang, old_toadoY = toadoYSang;
	bool button = true;
	while (true)
	{
		if (button == true)
		{
			gotoXY(old_toadoX, old_toadoY);
			high_light(old_toadoX, old_toadoY, w, h, str, b_color);

			old_toadoX = toadoXSang;
			old_toadoY = toadoYSang;

			high_light(toadoXSang, toadoYSang, w, h, str, color_hl);
			button = false;
		}

		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				button = true;
				c = _getch();
				if (c == 72)
				{
					if (toadoYSang != 5)
					{
						toadoYSang -= 2;
					}
					else
					{
						toadoYSang = 5 + h * (sl - 1);
					}
				}
				else if (c == 80)
				{
					if (toadoYSang != (5 + h * (sl - 1)))
					{
						toadoYSang += 2;
					}
					else
					{
						toadoYSang = 5;
					}
				}
			}
		}
	}

}

void soundbt()
{
	PlaySound(TEXT("C:\\Users\\COMPUTER\\Downloads\\button-10.wav"),NULL , SND_NODEFAULT);
}



void Menu1()
{
	ShowCur(false);
	int w = 20;
	int h = 2;
	int t_color = 11;
	int b_color = 1;
	int color_hl = 75;
	string str = "Start";
	int sl = 4;
	n_box(50, 5, w, h, t_color, b_color, str, sl);
	high_light(50, 5, w, h, str, color_hl);

	int toadoXSang = 50, toadoYSang = 5;
	int	old_toadoX = toadoXSang, old_toadoY = toadoYSang;
	bool button = true;
	while (true)
	{
		if (button == true)
		{
			gotoXY(old_toadoX, old_toadoY);
			high_light(old_toadoX, old_toadoY, w, h, str, b_color);

			old_toadoX = toadoXSang;
			old_toadoY = toadoYSang;

			high_light(toadoXSang, toadoYSang, w, h, str, color_hl);
			button = false;
		}

		if (GetAsyncKeyState(VK_UP))
		{
			//soundbt();
			button = true;
			if (toadoYSang != 5)
			{
				toadoYSang -= 2;
			}
			else
			{
				toadoYSang = 5 + h * (sl - 1);
			}
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			//soundbt();
			button = true;
			if (toadoYSang != (5 + h * (sl - 1)))
			{
				toadoYSang += 2;
			}
			else
			{
				toadoYSang = 5;
			}
		}
	}

}

void flow1()
{

	while (true)
	{
		if (_kbhit())
		{

			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 72)
				{
					/*mutex m;
					m.lock();*/
					soundbt();
					//m.unlock();
				}
				else if (c == 80)
				{
					/*mutex m;
					m.lock();*/
					soundbt();
					//m.unlock();
				}
			}
		}
	}

}




void Menu2()
{
	ShowCur(false);
	int w = 20;
	int h = 2;
	int t_color = 11;
	int b_color = 1;
	int color_hl = 75;
	string str = "Start";
	int sl = 4;
	n_box(50, 5, w, h, t_color, b_color, str, sl);
	high_light(50, 5, w, h, str, color_hl);

	int toadoXSang = 50, toadoYSang = 5;
	int	old_toadoX = toadoXSang, old_toadoY = toadoYSang;
	bool button = true;
	while (true)
	{
		if (button == true)
		{
			gotoXY(old_toadoX, old_toadoY);
			high_light(old_toadoX, old_toadoY, w, h, str, b_color);

			old_toadoX = toadoXSang;
			old_toadoY = toadoYSang;

			high_light(toadoXSang, toadoYSang, w, h, str, color_hl);
			button = false;
		}


		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				button = true;
				c = _getch();
				if (c == 72)
				{
					if (toadoYSang != 5)
					{
						toadoYSang -= 2;
					}
					else
					{
						toadoYSang = 5 + h * (sl - 1);
					}
				}
				else if (c == 80)
				{
					if (toadoYSang != (5 + h * (sl - 1)))
					{
						toadoYSang += 2;
					}
					else
					{
						toadoYSang = 5;
					}
				}
			}
		}
		
	}

}


// create menu start game 

void draw_arrow(int x , int y)
{
	TextColor(11);
	gotoXY(x, y);
	cout << ">>-->>";

	TextColor(11);
	gotoXY(x + 30, y);
	cout << "<<--<<";
}


void inPut_frame( int len1 , int x , int y , int xarr_left , int xarr_right  , int color_arr , int color_text , string setting_start[])
{


		TextColor(color_arr);
		gotoXY(xarr_left, y);
		cout << ">>->";

		TextColor(color_text);
		gotoXY(x, y);
		cout << setting_start[len1];

		TextColor(color_arr);
		gotoXY(xarr_right, y);
		cout << "<-<<";

}

void Start_game()
{
	mutex m;
	m.lock();
	ShowCur(1);

	string setting_start[4] = { "Start" , "Introduce" , "More" ,  "Exit" };
	int len = setting_start->length();

	int j = 0;

	ifstream filein;
	filein.open("egde_frame.txt", ios::in);
	if (!filein.is_open())
	{
		cout << "Don't exist file" << endl;
		return;
	}
	string tmp_str;
	int y_file = 17;
	while (getline(filein, tmp_str))
	{
		TextColor(9);
		gotoXY(40, y_file++);
		cout << tmp_str;

	}
	filein.close();

	for (int i = 0; i < len - 1; i++)
	{
		TextColor(11);
		gotoXY(50, 22 + j);
		cout << ">>->";

		TextColor(12);
		gotoXY(65 , 22 + j);
		cout << setting_start[i];

		TextColor(11);
		gotoXY(58 + 25, 22 + j);
		cout << "<-<<";
		j += 2;

	}
	m.unlock();


	ifstream filein1;
	filein1.open("cat1.txt", ios::in);
	if (!filein1.is_open())
	{
		cout << "Don't exist file" << endl;
		return;
	}
	string tmp_str1;
	int y_file1 = 5;

	while (getline(filein1, tmp_str1))
	{
		TextColor(13);
		gotoXY(115, y_file1++);
		cout << tmp_str1;

	}

	filein1.close();



}

void choose_button(int x, int y,int xarr_left , int xarr_right  , string setting_start[])
{

	int b_color = 0;
	int normal_text_cl = 12;
	int new_text_cl = 6;
	int new_arr_cl = 11;
	int y_change = y;



	int old_x = x, old_y = y;
	bool button = true;
	int vitri = 0;
	int vitri_old = vitri;
	bool t = false , enter = false;
	int a = 0,  b = 0 , c =0 , e =0;
	while (true)
	{
		if (a <= 49)
		{
			SetColor(a++);
			gotoXY(0, b++);
			cout << "|__|_|";
			SetColor(a);
			gotoXY(c+=3, 0);
			cout << ")-(";
			SetColor(a);
			gotoXY(e+=3, 39);
			cout << "<=>";
			

		}


		if (button == true)
		{
			gotoXY(old_x, old_y);
			inPut_frame(vitri_old, old_x, old_y, xarr_left, xarr_right, b_color, normal_text_cl , setting_start);

			old_x= x;
			old_y = y_change;
			inPut_frame(vitri, x, y_change, xarr_left, xarr_right, new_arr_cl, new_text_cl , setting_start);
			if ( t )
			{ 
				soundbt();
			}
			t = true;


			button = false;
		}
		if (_kbhit())
		{

			char c = _getch();
			button = true;
			if (c == -32)
			{
				c = _getch();
				if (c == 72)
				{
					//soundbt();
					if (y_change != y)
					{
						y_change -= 2;
						vitri_old = vitri;
						vitri -= 1;
					}
					else
					{
						y_change = y + 2 * (4 - 1);

						vitri_old = vitri;
						vitri = 3;
					}
				}
				else if (c == 80)
				{
					//soundbt();
					if (y_change != y + 2 * 3)
					{
						y_change += 2;

						vitri_old = vitri;
						vitri += 1;
					}
					else
					{
						y_change = y;

						vitri_old = vitri;
						vitri = 0;
					}
				}
			}
			else if (c == 13 && vitri == 0)
			{
				vitri_old = vitri;
				soundbt();
				clrscr();
				thread music(Check1);
				thread t2(Game);
				Check();
				music.join();
				t2.join();
				//t1.join();
			}
			else if (c == 13 && vitri == 1)
			{
				vitri_old = vitri;
				enter = true;
			}
			else if (c == 13 && vitri == 2)
			{
				vitri_old = vitri;
			}
			else if (c == 13 && vitri == 3)
			{
				vitri_old = vitri;
				soundbt();
				clrscr();
				TextColor(11);
				gotoXY(60, 20);

				cout << "Exit game . GoodBye!!!";
				TextColor(14);
				gotoXY(60, 22);

				cout << "Please press any button on keyboard to out.";
				cout << " \n\n\n\n                                         ";
				cout << "                                          ";
				cout << "                                          ";
				cout << "                                          ";
				cout << "                                          ";
				//soundbt();
				return;
			}
		}
		if (enter == true)
		{
			break;
		}
	}
	soundbt();
	clrscr();
	Introduce();
}
void Start_game1();

void Game()
{
	ShowCur(0);
	int a = 5;
	while (a <= 35)
	{
		TextColor(11);
		gotoXY(120, a);
		cout << char(195);

		TextColor(11);
		gotoXY(40, a++);
		cout << char(180);
	}



	int b = 40;
	while (b <= 120)
	{

		TextColor(12);
		gotoXY(b, 5);
		cout << char(247);
		if (b < 80 || b >  90)
		{

			TextColor(12);
			gotoXY(b,35 );
			cout << char(247);

		}
		else if (b == 80)
		{
			TextColor(12);
			gotoXY(b, 35);
			cout << ">";
		}
		else if (b == 90)
		{
			TextColor(12);
			gotoXY(b, 35);
			cout << "<";
		}
		
		b++;
	}

	int vitri_gunX = 42, vitri_gunY = 28 , vitri1 = 0  , vitri2 = 0 , vitri3 = 0 , vitri4 = 0;
	int vitri_gunX1 = 42, vitri_gunY1 = 22, vitri11 = 0, vitri21= 0, vitri31 = 0, vitri41 = 0;
	int vitri51 = 0, vitri61 = 0, vitri71 = 0, vitri81 = 0;
	int vitri_gunX2 = 42, vitri_gunY2 = 12, vitri12 = 0, vitri22 = 0, vitri32 = 0, vitri42 = 0;
	int vitri_gunX2_af = 42, vitri12_af = 0, vitri22_af = 0, vitri32_af = 0, vitri42_af = 0;
	int mid_located = 80;
	int mau = 0 ,mau1 = 1 , mau2 = 2 , mau3 = 3;
	while (true)
	{
		//--------- ----------- Hinh ------------------
		ifstream filein;
		filein.open("bocanhcung.txt", ios::in);
		if (!filein.is_open())
		{
			cout << "Don't exist file" << endl;
			return;
		}
		string tmp_str;
		int y_file = 15;
		while (getline(filein, tmp_str))
		{
			if (mau >= 15)
			{
				mau = 0;
			}
			TextColor(mau++);
			gotoXY(0, y_file++);
			cout << tmp_str;

		}
		filein.close();

		// -------------------Name game------------------------
		ifstream filein1;
		filein1.open("namegame1.txt", ios::in);
		if (!filein1.is_open())
		{
			cout << "Don't exist file" << endl;
			return;
		}
		string tmp_str1;
		int y_file1 = 0;
		while (getline(filein1, tmp_str1))
		{
			if (mau1 >= 15)
			{
				mau1 = 0;
			}
			TextColor(mau1++);
			gotoXY(20, y_file1++);
			cout << tmp_str1;

		}
		filein1.close();



		// -------------------Name game------------------------
		ifstream filein2;
		filein2.open("namegame2.txt", ios::in);
		if (!filein2.is_open())
		{
			cout << "Don't exist file" << endl;
			return;
		}
		string tmp_str2;
		int y_file2 = 0;
		while (getline(filein2, tmp_str2))
		{
			if (mau2 >= 15)
			{
				mau2 = 0;
			}
			TextColor(mau2++);
			gotoXY(90, y_file2++);
			cout << tmp_str2;

		}
		filein2.close();


		// -------------------Right picture------------------------
		ifstream filein3;
		filein3.open("tamgiac2.txt", ios::in);
		if (!filein3.is_open())
		{
			cout << "Don't exist file" << endl;
			return;
		}
		string tmp_str3;
		int y_file3 = 15;
		while (getline(filein3, tmp_str3))
		{
			if (mau3 >= 15)
			{
				mau3 = 0;
			}
			TextColor(mau3++);
			gotoXY(130, y_file3++);
			cout << tmp_str3;

		}
		filein3.close();



		mutex h;
		h.lock();
		if (vitri_gunX >= 116)
		{
			vitri_gunX = 43;
		}



		TextColor(0);
		gotoXY(vitri1, vitri_gunY);
		cout << "     ";

		vitri1 += 4;
		TextColor(0);
		gotoXY(vitri1, vitri_gunY);
		cout << "     ";





		vitri1 = vitri_gunX;


		TextColor(14);
		gotoXY(vitri_gunX , vitri_gunY);
		cout << char(233);

		vitri_gunX++;
		gotoXY(vitri_gunX, vitri_gunY);
		cout << char(233);

		vitri_gunX++;
		gotoXY(vitri_gunX, vitri_gunY);
		cout << char(233);

		vitri_gunX++;
		gotoXY(vitri_gunX, vitri_gunY);
		cout << char(233);

		vitri_gunX += 2;


		TextColor(14);
		gotoXY(vitri_gunX, vitri_gunY);
		cout << char(233);

		vitri_gunX++;
		gotoXY(vitri_gunX, vitri_gunY);
		cout << char(233);

		vitri_gunX++;
		gotoXY(vitri_gunX, vitri_gunY);
		cout << char(233);

		vitri_gunX++;
		gotoXY(vitri_gunX, vitri_gunY);
		cout << char(233);

		vitri_gunX += 3;


		Sleep(80);
		h.unlock();

		//--------------------------------

		mutex h1;
		h1.lock();
		if (vitri_gunX1 >= 112)
		{
			vitri_gunX1 = 43;
		}
		TextColor(0);
		gotoXY(vitri11, vitri_gunY1);
		cout << " ";

		vitri11++;
		gotoXY(vitri11, vitri_gunY1);
		cout << " ";

		vitri11 += 2;
		gotoXY(vitri11, vitri_gunY1);
		cout << " ";

		vitri11++;
		gotoXY(vitri11, vitri_gunY1);
		cout << " ";

		vitri11++;
		gotoXY(vitri11, vitri_gunY1);
		cout << " ";

		vitri11++;
		gotoXY(vitri11, vitri_gunY1);
		cout << " ";



		vitri11 = vitri_gunX1;


		TextColor(14);
		gotoXY(vitri_gunX1, vitri_gunY1);
		cout << char(233);

		vitri_gunX1++;
		gotoXY(vitri_gunX1, vitri_gunY1);
		cout << char(233);

		vitri_gunX1 += 2;

		gotoXY(vitri_gunX1, vitri_gunY1);
		cout << char(233);

		vitri_gunX1++;
		gotoXY(vitri_gunX1, vitri_gunY1);
		cout << char(233);

		vitri_gunX1++;
		gotoXY(vitri_gunX1, vitri_gunY1);
		cout << char(233);

		vitri_gunX1++;
		gotoXY(vitri_gunX1, vitri_gunY1);
		cout << char(233);


		Sleep(40);
		h1.unlock();

		//-------------------------- Stage 3 -------------
		
		/// ------------------- left --------------------- 
		mutex h2;
		h2.lock();
		if (vitri_gunX2 >= 75)
		{
			vitri_gunX2 = 43;
		}
		TextColor(0);
		gotoXY(vitri12, vitri_gunY2);
		cout << " ";

		vitri12++;
		gotoXY(vitri12, vitri_gunY2);
		cout << " ";

		vitri12++;
		gotoXY(vitri12, vitri_gunY2);
		cout << " ";

		vitri12++;
		gotoXY(vitri12, vitri_gunY2);
		cout << " ";

		vitri12++;
		gotoXY(vitri12, vitri_gunY2);
		cout << " ";



		vitri12 = vitri_gunX2;

		TextColor(14);
		gotoXY(vitri_gunX2, vitri_gunY2);
		cout << char(233);

		vitri_gunX2++;
		gotoXY(vitri_gunX2, vitri_gunY2);
		cout << "=";

		vitri_gunX2++;
		gotoXY(vitri_gunX2, vitri_gunY2);
		cout << "=";

		vitri_gunX2++;
		gotoXY(vitri_gunX2, vitri_gunY2);
		cout << char(233);

		vitri_gunX2++;
		gotoXY(vitri_gunX2, vitri_gunY2);
		cout << char(233);

		Sleep(20);
		h2.unlock();

		/// --------------- right ------------------
		mutex h3;
		h3.lock();
		if (vitri_gunX2_af <= 85)
		{
			vitri_gunX2_af = 119;
		}
		TextColor(0);
		gotoXY(vitri12_af, vitri_gunY2);
		cout << " ";

		vitri12_af--;
		gotoXY(vitri12_af, vitri_gunY2);
		cout << " ";

		vitri12_af--;
		gotoXY(vitri12_af, vitri_gunY2);
		cout << " ";

		vitri12_af--;
		gotoXY(vitri12_af, vitri_gunY2);
		cout << " ";

		vitri12_af--;
		gotoXY(vitri12_af, vitri_gunY2);
		cout << " ";



		vitri12_af = vitri_gunX2_af;




		TextColor(14);
		gotoXY(vitri_gunX2_af, vitri_gunY2);
		cout << char(233);

		vitri_gunX2_af--;
		gotoXY(vitri_gunX2_af, vitri_gunY2);
		cout << char(233);

		vitri_gunX2_af--;
		gotoXY(vitri_gunX2_af, vitri_gunY2);
		cout << "=";

		vitri_gunX2_af--;
		gotoXY(vitri_gunX2_af, vitri_gunY2);
		cout << "=";

		vitri_gunX2_af--;
		gotoXY(vitri_gunX2_af, vitri_gunY2);
		cout << char(233);

		Sleep(10);

		h3.unlock();
	}
}

void Introduce()
{
	ShowCur(0);
	ifstream filein;
	filein.open("pokemon1.txt", ios::in);
	if (!filein.is_open())
	{
		cout << "Don't exist file" << endl;
		return;
	}
	string tmp_str;
	int y_file = 5;
	int color = 2;
	while (getline(filein, tmp_str))
	{
		if (color == 15)
		{
			color = 2;
		}
		TextColor(color++);
		gotoXY(85, y_file++);
		cout << tmp_str;

	}
	filein.close();
	int a = 0, b = 0, c = 0, e = 0;
	while (a <= 49)
	{
		SetColor(a++);
		gotoXY(0, b++);
		cout << "_|";

	}
	a = 0, b = 0, c = 0, e = 0;
	while ( a <= 24)
	{
		SetColor(a++);
		gotoXY(c += 3, 0);
		cout << ")-(";
		SetColor(a);
		gotoXY(e += 3, 39);
		cout << "<=>";
	}


	ifstream filein1;
	filein1.open("introduce.txt", ios::in);
	if (!filein1.is_open())
	{
		cout << "Don't exist file" << endl;
		return;
	}
	string tmp_str1;
	int y_file1 = 5;
	int color1 = 2;
	while (getline(filein1, tmp_str1))
	{
		if (color1 == 15)
		{
			color1 = 2;
		}
		TextColor(color1++);
		gotoXY(20, y_file1++);
		cout << tmp_str1;

	}
	filein1.close();

	bool enter = false;

	while (true)
	{
		

		ifstream filein2;
		filein2.open("canhan.txt", ios::in);
		if (!filein2.is_open())
		{
			cout << "Don't exist file" << endl;
			return;
		}
		string tmp_str2;
		int y_file2 = 18;
		int color2 = 2;
		while (getline(filein2, tmp_str2))
		{
			if (color2 == 15)
			{
				color2 = 2;
			}
			TextColor(color2++);
			gotoXY(0, y_file2++);
			cout << tmp_str2;

			Sleep(100);
		}
		filein2.close();


		ifstream filein3;
		filein3.open("canhan1.txt", ios::in);
		if (!filein3.is_open())
		{
			cout << "Don't exist file" << endl;
			return;
		}
		string tmp_str3;
		int y_file3 = 18;
		int color3 = 2;
		while (getline(filein3, tmp_str3))
		{
			if (color3 == 15)
			{
				color3 = 2;
			}
			TextColor(color3++);
			gotoXY(0, y_file3++);
			cout << tmp_str3;

			Sleep(100);
		}
		filein3.close();

		if (_kbhit())
		{
			char c = _getch();
			if (c == 27)
			{
				enter = true;
			}
		}
		if (enter == true)
		{
			break;
		}
	}
	soundbt();
	clrscr();
	Start_game1();
	

}
void Check1()
{
	PlaySound(TEXT("D:\\đồ án\\test\\ConsoleApplication1\\music\\2.wav"), NULL, SND_LOOP);

}

void Start_game1()
{
	//mutex m;
	ShowCur(0);
	//m.lock();

	string setting_start[4] = { "Start" , "Introduce" , "More" ,  "Exit" };
	int len = setting_start->length();

	int j = 0;

	ifstream filein;
	filein.open("egde_frame.txt", ios::in);
	if (!filein.is_open())
	{
		cout << "Don't exist file" << endl;
		return;
	}
	string tmp_str;
	int y_file = 17;
	while (getline(filein, tmp_str))
	{
		TextColor(9);
		gotoXY(40, y_file++);
		cout << tmp_str;

	}
	filein.close();

	for (int i = 0; i < len - 1; i++)
	{
		TextColor(11);
		gotoXY(50, 22);
		cout << ">>->";

		TextColor(12);
		gotoXY(65, 22 + j);
		cout << setting_start[i];

		TextColor(11);
		gotoXY(58 + 25, 22);
		cout << "<-<<";
		j += 2;

	}
	//m.unlock();


	ifstream filein1;
	filein1.open("cat1.txt", ios::in);
	if (!filein1.is_open())
	{
		cout << "Don't exist file" << endl;
		return;
	}
	string tmp_str1;
	int y_file1 = 5;

	while (getline(filein1, tmp_str1))
	{
		TextColor(13);
		gotoXY(115, y_file1++);
		cout << tmp_str1;

	}

	filein1.close();


	TextColor(6);
	gotoXY(65, 22);
	cout << setting_start[0];

	int x  = 65, y = 22, xarr_left = 50, xarr_right = 83 ;
	choose_button(x, y, xarr_left, xarr_right , setting_start);

}

void test()
{

	string setting_start[4] = { "Start" , "Introduce" , "More" ,  "Exit" };
	int len = setting_start->length();

	int j = 0;

	ifstream filein;
	filein.open("egde_frame.txt", ios::in);
	if (!filein.is_open())
	{
		cout << "Don't exist file" << endl;
		return;
	}
	string tmp_str;
	int y_file = 17;
	while (getline(filein, tmp_str))
	{
		TextColor(9);
		gotoXY(40, y_file++);
		cout << tmp_str;

	}
	filein.close();
}

void Docfile(string filename ,int x , int y )
{
	ifstream filein;
	filein.open(filename, ios::in);
	if (!filein.is_open())
	{
		cout << "Don't exist file" << endl;
		return;
	}
	string tmp_str;
	while (getline(filein, tmp_str))
	{
		TextColor(9);
		gotoXY(x, y++);
		cout << tmp_str;

	}
	filein.close();
}

void Check()
{
	mutex m;
	m.lock();
	string filename = "nhanvat1.txt";
	Docfile(filename, 82, 33);

	bool button = true;
	int x = 82, y = 33;
	int old_vitriX = x, old_vitriY = y;

	while (true)
	{
		if (button == true)
		{
			mutex h;

			ifstream filein1;
			filein1.open("nhanvatan.txt", ios::in);
			if (!filein1.is_open())
			{
				cout << "Don't exist file" << endl;
				return;
			}
			string tmp_str1;
			while (getline(filein1, tmp_str1))
			{
				TextColor(0);
				old_vitriX -= 2;
				gotoXY(old_vitriX, old_vitriY++);
				cout << tmp_str1;

			}
			filein1.close();



			h.lock();

			old_vitriX = x, old_vitriY = y;
			Docfile(filename, x, y);
			button = false;
			h.unlock();
		}
		if (_kbhit())
		{
			char c = _getch();
			button = true;
			if (c == -32)
			{
				c = _getch();
				if (c == 72)
				{
					y--;

				}
				else if (c == 80)
				{
					if (y != 33)
					{
						y++;

					}
				}
				else if (c == 75)
				{
					if (x != 41)
					{
						x--;

					}
				}
				else if (c == 77)
				{
					if (x != 120 - 8)
					{
						x++; 

					}
				}
			}
		}
		if (y == 5)
		{
			m.unlock();

			clrscr();
			
			mutex h1;
			h1.lock();
			TextColor(11);
			gotoXY(60, 20);

			cout << "Win Game . GoodBye!!!";
			TextColor(14);
			gotoXY(60, 22);
			h1.unlock();

			cout << "Please press any button on keyboard to out.";
			cout << " \n\n\n\n                                         ";
			cout << "                                          ";
			cout << "                                          ";
			cout << "                                          ";
			cout << "                                          ";
			//soundbt();
			return;
		}
	}


}