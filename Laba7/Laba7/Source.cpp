#include <iostream>

using namespace std;

class MPa;

class KPa;

class Pa;

class Bar;

class Psi;

class Pa {

private:

	long double ln;

public:

	Pa() :ln(0) {}

	Pa(long double _ln) :ln(_ln) {}

	~Pa() {}

	operator MPa();

	operator KPa();

	operator Psi();

	operator Bar();

	void print() {

		cout << ln << endl;

	}

};

class KPa {

private:

	long double ln;

public:

	KPa() :ln(0) {}

	KPa(long double _ln) :ln(_ln) {}

	~KPa() {}

	operator Pa();

	operator MPa();

	operator Psi();

	operator Bar();

	void print() {

		cout << ln << endl;

	}

};

class MPa {

private:

	long double ln;

public:

	MPa() :ln(0) {}

	MPa(long double _ln) :ln(_ln) {}

	~MPa() {}

	operator Pa();

	operator KPa();

	operator Psi();

	operator Bar();
	void print() {

		cout << ln << endl;

	}

};

class Bar {

private:

	long double ln;

public:

	Bar() :ln(0) {}

	Bar(long double _ln) :ln(_ln) {}

	~Bar() {}

	operator Pa();

	operator MPa();

	operator KPa();

	operator Psi();

	void print() {

		cout << ln << endl;

	}

};

class Psi {

private:

	long double ln;

public:

	Psi() :ln(0) {}

	Psi(long double _ln) :ln(_ln) {}

	~Psi() {}

	operator Pa();

	operator MPa();

	operator KPa();

	operator Psi();

	operator Bar();

	void print() {

		cout << ln << endl;

	}

};

Pa::operator KPa() {

	return (ln / 1000);

}

Pa::operator MPa() {

	return (ln / 1000000);

}

Pa::operator Bar() {

	return (ln / 100000);

}

Pa::operator Psi() {

	return (ln / 6895);

}

MPa::operator Pa() {

	return (ln * 1000000);

}

MPa::operator KPa() {

	return (ln * 1000);

}

MPa::operator Bar() {

	return (ln * 10);

}

MPa::operator Psi() {

	return (ln / 6895 * 1000000);

}

KPa::operator Pa() {

	return (ln * 1000);

}

KPa::operator MPa() {

	return (ln / 1000);

}

KPa::operator Bar() {

	return (ln / 100);

}

KPa::operator Psi() {

	return (ln / 6895 * 1000);

}

Psi::operator Pa() {

	return (ln * 6895);

}

Psi::operator KPa() {

	return (ln * 6895 / 1000);

}

Psi::operator Bar() {

	return (ln * 6895 / 100000);

}

Psi::operator MPa() {

	return (ln * 6895 / 1000000);

}

Bar::operator Pa() {

	return (ln * 100000);

}

Bar::operator KPa() {

	return (ln * 100);

}

Bar::operator Psi() {

	return (ln / 6895 * 100000);

}

Bar::operator MPa() {

	return (ln / 10);

}

int main() {

	Pa a(1);

	KPa b(1);

	MPa c(1);

	Bar d(1);

	Psi e(1);

	b = a;

	c = e;

	e = d;

	cout << "Pa to KPa" << endl;

	b.print();

	cout << "Psi to Mpa" << endl;

	c.print();

	cout << "Bar to Psi" << endl;

	e.print();

}
