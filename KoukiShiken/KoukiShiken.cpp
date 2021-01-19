#include <iostream>
#include <ctime>
using namespace std;

struct Status
{
	char name[16];
	int lv;
	int hp;
	int at;
	int df;
	int money;
};

int main()
{
	srand((unsigned int)time(NULL));

	int push;

	Status status[] =
	{
		{"勇者",100,1000,500,500,0},
		{"０１",1,5,2,2,500},
		{"魔王",1,5000,2500,5,1000}
	};

	cout << "名前　　　　" << status[0].name << endl;
	cout << "レベル　　　" << status[0].lv << endl;
	cout << "体力　　　　" << status[0].hp << endl;
	cout << "攻撃力　　　" << status[0].at << endl;
	cout << "守備力　　　" << status[0].df << endl;

	int lv = status[0].lv;
	int hp = status[0].hp;
	int at = status[0].at;
	int df = status[0].df;
	int money = status[0].money;

	int lv1 = status[1].lv;
	int hp1 = status[1].hp;
	int at1 = status[1].at;
	int df1 = status[1].df;
	int money1 = status[1].money;

	int lv2 = status[2].lv;
	int hp2 = status[2].hp;
	int at2 = status[2].at;
	int df2 = status[2].df;
	int money2 = status[2].money;

	int redherb = 10;
	int blueherb = 10;
	int charm = 50;

	int redherbag = 0;
	int blueherbag = 0;
	int herosword = 0;
	int bronzesword = 0;
	int silversword = 0;
	int goldensword = 0;

	int equip = 0;

	int kingmoney = 1;

	while (true)
	{
		cout << "どこへ向かいますか？" << endl << "１：道具屋　２：宿屋　３：お城　４：ガチャガチャ　５：町の外" << endl;

		cin >> push;

		if (push == 1)
		{
			int chooseitem;

			cout << "何を買いますか？" << endl;
			cout << "１：赤い薬草（１０マネー）　２：青い薬草（１０マネー）　３：お守り（５０マネー）" << endl;

			cin >> chooseitem;


			if (chooseitem == 1)
			{
				if (money >= redherb)
				{
					money -= redherb;

					redherbag += 1;

					cout << status[0].name << "は赤い薬草を手に入れた！" << endl;
				}
				else
				{
					cout << "お金が足りません！" << endl;
				}
			}
			else if (chooseitem == 2)
			{
				if (money >= blueherb)
				{
					money -= blueherb;

					blueherbag += 1;

					cout << status[0].name << "は青い薬草を手に入れた！" << endl;
				}
				else
				{
					cout << "お金が足りません！" << endl;
				}
			}
			else if (chooseitem == 3)
			{
				if (money >= charm)
				{
					money -= charm;

					cout << status[0].name << "は小さなお守りを手に入れた！" << endl;
				}
				else
				{
					cout << "お金が足りません！" << endl;
				}
			}
			else
			{
				cout << "押す番号が違います" << endl;
			}
		}
		else if (push == 2)
		{
			int sleep;

			cout << "寝ますか？　１：はい　２：いいえ" << endl;

			cin >> sleep;

			if (sleep == 1)
			{
				int girl = rand() % 4;

				if (girl == 0)
				{
					cout << "謎の美女が現れた！" << endl;
					cout << "美女「？？？…」" << endl;

					hp = status[0].hp;

					cout << status[0].name << "は気持ちよくなった！" << endl;
					cout << "枕元に赤い薬草が残されていた！" << endl;
					cout << status[0].name << "は赤い薬草を手に入れた！" << endl;

					redherbag += 1;
				}
				else
				{
					cout << status[0].name << "はぐっすり眠った！" << endl;

					hp = status[0].hp;
				}
			}
		}
		else if (push == 3)
		{
			if (kingmoney == 1)
			{
				cout << "王様「よくぞ来た！勇者オ〇テガの息子よ！」" << endl;
				cout << "王様「冒険の旅はとても険しくとても長い…」" << endl;
				cout << "王様「じゃがお前なら大魔王ゾ〇マを倒せると信じているぞ！」" << endl;
				cout << "旅の贐としてこれをくれてしんぜよう！" << endl;
				cout << status[0].name << "は１００マネーを手に入れた！" << endl;

				money += 100;

				kingmoney = 0;
			}
			else
			{
				cout << "王様「さあ行くのじゃオ〇テガの息子よ！" << endl;
				cout << "王様「何じゃと？もっとお金が欲しい？」" << endl;
				cout << "王様「ならば町の外で旅人を襲う魔物を討伐しに行くのじゃ！」" << endl;
				cout << "王様「さすればお金も手に入りお主も強くなるであろう！」" << endl;
			}
		}
		else if (push == 4)
		{
			int gacha;

			cout << "１００マネーで１０回ガチャガチャを引くことができます　引いてみますか？　１：はい　２：いいえ" << endl;

			cin >> gacha;

			if (gacha == 1)
			{
				if (money >= 100)
				{
					money -= 100;

					for (int lucky = 1; lucky < 11; ++lucky)
					{
						int weapon = rand() % 10;

						if (weapon == 0)
						{
							herosword += 1;

							cout << "勇者のつるぎを手に入れた！" << endl;
						}
						else if (weapon == 1 || weapon == 2)
						{
							goldensword += 1;

							cout << "黄金の剣を手に入れた！" << endl;
						}
						else if (weapon == 3 || weapon == 4 || weapon == 5)
						{
							silversword += 1;

							cout << "白銀の剣を手に入れた！" << endl;
						}
						else if (weapon == 6 || weapon == 7 || weapon == 8 || weapon == 9)
						{
							bronzesword += 1;

							cout << "赤銅の剣を手に入れた！" << endl;
						}
					}

					if (bronzesword > 0)
					{
						equip = 4;
					}

					if (silversword > 0)
					{
						equip = 3;
					}

					if (goldensword > 0)
					{
						equip = 2;
					}

					if(herosword > 0)
					{
						equip = 1;
					}
				}
				else
				{
					cout << "お金が足りません！" << endl;
				}
			}
			else if (gacha == 2)
			{
				cout << "ガチャガチャを諦めました" << endl;
			}
		}
		else if (push == 5)
		{
			int travel;

			cout << "どこへ向かいますか？　１：町の中　２：平原　３：魔王城" << endl;

			cin >> travel;

			if (travel == 1)
			{
				cout << "町の中に戻りました" << endl;
			}
			else if (travel == 2)
			{
				cout << status[1].name << "が現れた！" << endl;

				while (true)
				{
					int herochoice;

					cout << status[0].name << "はどうする？" << endl;

					if (equip == 0)
					{
						cout << "１：攻撃　２：道具　３：逃走" << endl;

						cin >> herochoice;

						if (herochoice == 1)
						{
							hp1 -= at - df1;

							cout << status[0].name << "の攻撃！" << endl;

							cout << status[1].name << "は" << at / df1 << "ダメージを受けた！" << endl;
						}
						else if (herochoice == 2)
						{
							int itemchoice;

							cout << "何を使用しますか？　１：赤い薬草　２：青い薬草" << endl;

							cin >> itemchoice;

							if (itemchoice == 1)
							{
								if (redherbag <= 0)
								{
									cout << "赤い薬草が存在しません" << endl;
								}
								else
								{
									redherbag -= 1;

									cout << status[0].name << "は赤い薬草を使った！" << endl;

									hp += hp / 5;

									if (hp >= status[0].hp)
									{
										hp = status[0].hp;
									}

									cout << status[0].name << "の体力が" << hp / 5 << "回復した！" << endl;
								}
							}
							else if (itemchoice == 2)
							{
								if (blueherbag <= 0)
								{
									cout << "青い薬草が存在しません" << endl;
								}
								else
								{
									blueherbag -= 1;

									cout << status[0].name << "は青い薬草を使った！" << endl;

									hp1 -= at;

									cout << status[1].name << "は" << at << "ダメージを受けた！" << endl;
								}
							}
						}
						else if (herochoice == 3)
						{
							cout << status[0].name << "は逃げ出した！" << endl;

							break;
						}
					}
					else if (equip == 4)
					{
						cout << "１：渾身斬り　２：道具　３：逃走" << endl;

						cin >> herochoice;

						if (herochoice == 1)
						{
							hp1 -= (at * 3 / 2) / df1;

							cout << status[0].name << "の渾身斬り！" << endl;

							cout << status[1].name << "は" << (at * 3 / 2) / df1 << "ダメージを受けた！" << endl;
						}
						else if (herochoice == 2)
						{
							int itemchoice;

							cout << "何を使用しますか？　１：赤い薬草　２：青い薬草" << endl;

							cin >> itemchoice;

							if (itemchoice == 1)
							{
								if (redherbag <= 0)
								{
									cout << "赤い薬草が存在しません" << endl;
								}
								else
								{
									redherbag -= 1;

									cout << status[0].name << "は赤い薬草を使った！" << endl;

									hp += hp / 5;

									if (hp >= status[0].hp)
									{
										hp = status[0].hp;
									}

									cout << status[0].name << "の体力が" << hp / 5 << "回復した！" << endl;
								}
							}
							else if (itemchoice == 2)
							{
								if (blueherbag <= 0)
								{
									cout << "青い薬草が存在しません" << endl;
								}
								else
								{
									blueherbag -= 1;

									cout << status[0].name << "は青い薬草を使った！" << endl;

									hp1 -= at;

									cout << status[1].name << "は" << at << "ダメージを受けた！" << endl;
								}
							}
						}
						else if (herochoice == 3)
						{
							cout << status[0].name << "は逃げ出した！" << endl;

							break;
						}
					}
					else if (equip == 3)
					{
						cout << "１：全身全霊斬り　２：道具　３：逃走" << endl;

						cin >> herochoice;

						if (herochoice == 1)
						{
							hp1 -= (at * 2) / df1;

							cout << status[0].name << "の全身全霊斬り！" << endl;

							cout << status[1].name << "は" << (at * 2) / df1 << "ダメージを受けた！" << endl;
						}
						else if (herochoice == 2)
						{
							int itemchoice;

							cout << "何を使用しますか？　１：赤い薬草　２：青い薬草" << endl;

							cin >> itemchoice;

							if (itemchoice == 1)
							{
								if (redherbag <= 0)
								{
									cout << "赤い薬草が存在しません" << endl;
								}
								else
								{
									redherbag -= 1;

									cout << status[0].name << "は赤い薬草を使った！" << endl;

									hp += hp / 5;

									if (hp >= status[0].hp)
									{
										hp = status[0].hp;
									}

									cout << status[0].name << "の体力が" << hp / 5 << "回復した！" << endl;
								}
							}
							else if (itemchoice == 2)
							{
								if (blueherbag <= 0)
								{
									cout << "青い薬草が存在しません" << endl;
								}
								else
								{
									blueherbag -= 1;

									cout << status[0].name << "は青い薬草を使った！" << endl;

									hp1 -= at;

									cout << status[1].name << "は" << at << "ダメージを受けた！" << endl;
								}
							}
						}
						else if (herochoice == 3)
						{
							cout << status[0].name << "は逃げ出した！" << endl;

							break;
						}
					}
					else if (equip == 2)
					{
						cout << "１：アルテマソード　２：道具　３：逃走" << endl;

						cin >> herochoice;

						if (herochoice == 1)
						{
							hp1 -= (at * 5 / 2) / df1;

							cout << status[0].name << "のアルテマソード！" << endl;

							cout << status[1].name << "は" << (at * 5 / 2) / df1 << "ダメージを受けた！" << endl;
						}
						else if (herochoice == 2)
						{
							int itemchoice;

							cout << "何を使用しますか？　１：赤い薬草　２：青い薬草" << endl;

							cin >> itemchoice;

							if (itemchoice == 1)
							{
								if (redherbag <= 0)
								{
									cout << "赤い薬草が存在しません" << endl;
								}
								else
								{
									redherbag -= 1;

									cout << status[0].name << "は赤い薬草を使った！" << endl;

									hp += hp / 5;

									if (hp >= status[0].hp)
									{
										hp = status[0].hp;
									}

									cout << status[0].name << "の体力が" << hp / 5 << "回復した！" << endl;
								}
							}
							else if (itemchoice == 2)
							{
								if (blueherbag <= 0)
								{
									cout << "青い薬草が存在しません" << endl;
								}
								else
								{
									blueherbag -= 1;

									cout << status[0].name << "は青い薬草を使った！" << endl;

									hp1 -= at;

									cout << status[1].name << "は" << at << "ダメージを受けた！" << endl;
								}
							}
						}
						else if (herochoice == 3)
						{
							cout << status[0].name << "は逃げ出した！" << endl;

							break;
						}
					}
					else if (equip == 1)
					{
						cout << "１：覇王斬　２：道具　３：逃走" << endl;

						cin >> herochoice;

						if (herochoice == 1)
						{
							hp1 -= (at * 3) / df1;

							cout << status[0].name << "の覇王斬！" << endl;

							cout << status[1].name << "は" << (at * 3) / df1 << "ダメージを受けた！" << endl;
						}
						else if (herochoice == 2)
						{
							int itemchoice;

							cout << "何を使用しますか？　１：赤い薬草　２：青い薬草" << endl;

							cin >> itemchoice;

							if (itemchoice == 1)
							{
								if (redherbag <= 0)
								{
									cout << "赤い薬草が存在しません" << endl;
								}
								else
								{
									redherbag -= 1;

									cout << status[0].name << "は赤い薬草を使った！" << endl;

									hp += hp / 5;

									if (hp >= status[0].hp)
									{
										hp = status[0].hp;
									}

									cout << status[0].name << "の体力が" << hp / 5 << "回復した！" << endl;
								}
							}
							else if (itemchoice == 2)
							{
								if (blueherbag <= 0)
								{
									cout << "青い薬草が存在しません" << endl;
								}
								else
								{
									blueherbag -= 1;

									cout << status[0].name << "は青い薬草を使った！" << endl;

									hp1 -= at;

									cout << status[1].name << "は" << at << "ダメージを受けた！" << endl;
								}
							}
						}
						else if (herochoice == 3)
						{
							cout << status[0].name << "は逃げ出した！" << endl;

							break;
						}
					}

					int enemymove = rand() % 3;

					if (enemymove == 0)
					{
						int zarakiima = rand() % 5;

						cout << status[1].name << "のザラキーマ！" << endl;

						if (zarakiima == 0)
						{
							cout << status[0].name << "は死んでしまった…" << endl;

							break;
						}
						else
						{
							cout << status[0].name << "には効かなかった！" << endl;
						}
					}
					else if (enemymove == 1)
					{
						hp -= at1 / df;

						cout << status[1].name << "の攻撃！" << endl;

						cout << status[0].name << "は" << at1 / df << "ダメージ食らった！" << endl;

						if (hp <= 0)
						{
							cout << status[0].name << "は死んでしまった…" << endl;

							break;
						}
					}
				}
			}
		}
	}
}