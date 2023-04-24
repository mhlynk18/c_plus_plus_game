#include"Header.h"
#include"Source.h"

int main()
{

	//Create_Backgroud();



	/*for (int i = 0; i < 4; i++)
	{
		Create_box(50, 5 + (i * 2), 20, 2);

	}
	for (int i = 1; i < 4; i++)
	{
		gotoXY(50, 5 + (i * 2));
		cout << char(195);
		gotoXY(50 + 20, 5 + (i * 2));
		cout << char(180);
	}*/
	/*thread t1(flow1);
	thread t2(Menu2);
	t1.join();
	t2.join();*/
	/*int c = 0, a = 0 , i = 0;
	TextColor(14);
	while(c < 200)
	{
		TextColor(i);
		gotoXY(i, 10);
		cout << "Hung" << endl;
		Sleep(200);
		clrscr();
		if (a == 0) i++;
		if (a == 1) i--;
		if (i == 80) a = 1;
		if (i == 0) a = 0;
		c++;

	}*/
	//thread t(Start_game1 );
	//thread t2(Check1);

	//t2.join();
	//t.join();
	//thread t1(Game);
	//thread t2(Check);
	Start_game1();
	//Game();
	//Introduce();
	//Check();
	
	_getch();
	return 0;
}