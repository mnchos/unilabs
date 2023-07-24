#include <iostream>

#include <string>

using namespace std;
class transport {

protected:

	string name;
	int ser_num;
	int age_vip;

public:
	transport* next;

	transport* first;
	transport() {};
	transport(string c_name, int c_ser_num, int c_age_vip) :

		name(c_name), ser_num(c_ser_num), age_vip(c_age_vip) {}
	virtual void info() {

		cout << "Название: " << name << endl;

		cout << "Серийный номер: " << ser_num << endl;

		cout << "Год выпуска: " << age_vip << endl;


	}
};

class avtomobil : public transport {

protected:

	string specavt;

public:
	avtomobil() {};
	avtomobil(string d_name, int d_ser_num, int d_age_vip, string d_spec) :

		transport(d_name, d_ser_num, d_age_vip), specavt(d_spec) {}
	void info() {

		cout << "Название: " << name << endl;

		cout << "Серийный номер: " << ser_num << endl;

		cout << "Год выпуска: " << age_vip << endl;

		cout << "Назначение ТС: " << specavt << endl;

		cout << "----------------" << endl;
	}
};
class train : public transport {

protected:

	string spec;

public:
	train() {};
	train(string dc_name, int dc_ser_num, int dc_age_vip, string dc_spec) :

		transport(dc_name, dc_ser_num, dc_age_vip), spec(dc_spec) {}
	void info() {

		cout << "Название: " << name << endl;

		cout << "Серийный номер: " << ser_num << endl;

		cout << "Год выпуска: " << age_vip << endl;

		cout << "Тип поезда: " << spec << endl;

		cout << "----------------" << endl;
	}
};
class exprass : public train {

protected:

	bool ismetrotrain;

public:

	exprass() {};

	exprass(string dcs_name, int dcs_ser_num, int dcs_age_vip, string dcs_spec, bool ismetro)
		:train(dcs_name, dcs_ser_num, dcs_age_vip, dcs_spec), ismetrotrain(ismetrotrain) {};

	void info() {

		cout << "Название: " << name << endl;

		cout << "Серийный номер: " << ser_num << endl;

		cout << "Год выпуска: " << age_vip << endl;

		cout << "Тип поезда: " << spec << endl;

		if (ismetrotrain == true)
			cout << "Экспресс обслуживает метрополитен " << endl;
		else
			cout << "Экспресс обслуживает пригородные станции " << endl;

		cout << "----------------" << endl;
	}

};

void main()

{
	setlocale(LC_ALL, "rus");

	transport* arr[3];

	train a("Ласточка", 2942, 1998, "Грузовой");

	exprass b("Синица", 3000, 2009, "Пассажирский", true);

	avtomobil c("Volkswagen Passat", 2242, 1993, "Личное ТС");

	arr[0] = &a;

	arr[1] = &b;

	arr[2] = &c;

	arr[0]->info();

	arr[0]->first;

	arr[1]->info();

	arr[1]->first;

	arr[2]->info();

}
