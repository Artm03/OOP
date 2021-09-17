#include <iostream>

using namespace std;

class TransNumber {
public:
	TransNumber() { a = 0; b = 0; }
	TransNumber(long double c, long double d) { a = c; b = d; }
	void set(long double c, long double d) {
		a = c;
		b = d;
	}
	void print() {
		cout << a << " " << b << "\n";
	}
	pair<long double, long double> get() {
		return { a, b };
	}
	long double get_a() {
		return a;
	}
	long double get_b() {
		return b;
	}
	void add(TransNumber t1, TransNumber t2) {
		a = t1.a + t2.a;
		b = t1.b + t2.b;
	}
	void sub(TransNumber t1, TransNumber t2) {
		a = t1.a - t2.a;
		b = t1.b - t2.b;
	}
	void mul(TransNumber t1, TransNumber t2) {
		a = t1.a * t2.a - t1.b * t2.b;
		b = t1.a * t2.b + t1.b * t2.a;
	}
	void div(TransNumber t1, TransNumber t2) {
		a = (t1.a * t2.a + t1.b * t2.b) / (t2.a * t2.a + t2.b * t2.b);
		b = (t1.b * t2.a - t1.a * t2.b) / (t2.a * t2.a + t2.b * t2.b);
	}
	bool equ(TransNumber t1, TransNumber t2) {
		return t1.a == t2.a && t1.b == t2.b;
	}
	void conj(TransNumber t) {
		a = t.a;
		b = -t.b;
	}
private:
	long double a;
	long double b;
};

bool operator<(TransNumber t1, TransNumber t2) {
	return (t1.get_a() + t1.get_b()) < t2.get_a() + t2.get_b();
}

bool operator>(TransNumber t1, TransNumber t2) {
	return (t1.get_a() + t1.get_b()) > t2.get_a() + t2.get_b();
}

bool operator==(TransNumber t1, TransNumber t2) {
	return (t1.get_a() + t1.get_b()) == t2.get_a() + t2.get_b();
}

int main() {
	TransNumber t1;
	TransNumber t2;
	t1.set(10, 2.5);
	t2.set(12.6, 3.4);
	TransNumber t;
	t.conj(t1);
	cout << (t1 < t2);
	return 0;
}