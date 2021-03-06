
#include "pch.h"
#include <iostream>
#define max_dog 9
#define long_trac 60

using namespace std;

class dog {
private:
	int speed;
	int rand_val;
public:
	void set_dog(int speed, int rand_val) {
		this->speed = speed;
		this->rand_val = rand_val - speed*12;
	}
	int get_speed()
	{
		return this->speed;
	}
	int get_rand()
	{
		return this->rand_val;
	}
};

struct grade {
	int grade_val;
	int grade_dog[max_dog];
};

int main()
{
	srand(time(0));
	vector<int> score_print_val;
	int street[max_dog];
	memset(street, 0, sizeof(int) * max_dog);
	dog m_dog[max_dog];
	grade m_grade;
	m_grade.grade_val = 1;
	memset(m_grade.grade_dog, 0, sizeof(int)*max_dog);
	for (int i = 0; i < max_dog; i++)
	{
		m_dog[i].set_dog(rand() % 4 + 1, rand() % 30 + 82);
	}
	while (true)
	{
		system("cls");
		cout << "개경주" << endl;
		for (int i = 0; i < max_dog; i++)
			cout << i + 1 << "번개 속도: " << m_dog[i].get_speed() << " 활동력: " << m_dog[i].get_rand() << endl;
		for (int i = 0; i < max_dog; i++)
		{
			if(street[i] < long_trac)
			{
				int rand_val = rand() % 100 + m_dog[i].get_rand();
				if (rand_val > 100 && long_trac - street[i] >= m_dog[i].get_speed())
				{
					street[i] += m_dog[i].get_speed();
				}
				else if (rand_val > 100 && long_trac - street[i] < m_dog[i].get_speed())
				{
					street[i] = long_trac;
				}
				else if (rand_val <= 100 && street[i] > m_dog[i].get_speed())
				{
					rand_val = rand() % 100;
					if (rand_val < 30)
						street[i] -= m_dog[i].get_speed();
					else if(rand_val > 80)
						street[i] -= 1;
				}		
			}
			else
			{
				if (m_grade.grade_dog[i] == 0)
				{
					m_grade.grade_dog[i] = m_grade.grade_val;
					m_grade.grade_val++;
					score_print_val.push_back(i + 1);
				}
			}
		
			
			for (int j = 0; j <= long_trac; j++)
			{
				if (j < street[i])
				{
					cout << "-";
				}
				else if(street[i] == j)
				{
					cout << i+1;
				}
				else
				{
					if(j< long_trac)
						cout << "-";
				}

			}
			cout<< endl;
		}
		
		for(int i = 0; i<score_print_val.size(); i ++)
				cout << score_print_val.at(i) << "번개가 " << i+1 << "등으로 도착했습니다~!" << endl;
		Sleep(500);
	}

}

