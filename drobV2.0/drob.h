#pragma once
#include <iostream>

using namespace std;

class Drob {
	int x, y;
public:
	Drob(int x = 0, int y = 1) {
		this->setX(x);
		this->setY(y);
		this->reduce();
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		if (y == 0)
			this->y = 1;
		else
			this->y = y;
	}
	//��������� +=, -=, *=, /=
	Drob& operator+=(const Drob& right) {
		this->x = this->x * right.y + right.x * this->y;
		this->y *= right.y;
		this->reduce();
		return *this;
	}
	Drob& operator-=(const Drob& right) {
		this->x = this->x * right.y - right.x * this->y;
		this->y *= right.y;
		this->reduce();
		return *this;
	}
	Drob& operator*=(const Drob& right) {
		this->x *= right.x;
		this->y *= right.y;
		this->reduce();
		return *this;
	}
	Drob& operator/=(const Drob& right) {
		this->x *= right.y;
		this->y *= right.x;
		this->reduce();
		return *this;
	}

	//���������� ���������
	Drob& operator++() {
		this->x += this->y;
		return *this;
	}
	//����������� ���������
	Drob operator++(int) {
		Drob tmp = *this;
		this->x += this->y;
		return tmp;
	}

	void reduce() { //��������
		for (int i = this->x; i > 1; i--) {
			if (this->x % i == 0 && this->y % i == 0) {
				this->x /= i;
				this->y /= i;
			}
		}
	}


	int getX() const {
		return  this->x;
	}

	int getY() const {
		return this->y;
	}

	void print() const {
		cout << this->x << " / " << this->y << " = " << (double)this->x / (double)this->y << endl;
	}

	friend ostream& operator<< (ostream& out, const Drob& a);
	friend istream& operator>> (istream& in, Drob& a);
	friend Drob operator+ (const Drob& a, const Drob& b);
	friend Drob operator+ (const Drob& a, int b);
	friend Drob operator+ (int a, const Drob& b);
	friend Drob operator- (const Drob& a, const Drob& b);
	friend Drob operator- (const Drob& a, int b);
	friend Drob operator- (int a, const Drob& b);
	friend Drob operator- (const Drob& a);
	friend Drob operator* (const Drob& a, const Drob& b);
	friend Drob operator* (const Drob& a, int b);
	friend Drob operator* (int a, const Drob& b);
	friend Drob operator/ (const Drob& a, const Drob& b);
	friend Drob operator/ (const Drob& a, int b);
	friend Drob operator/ (int a, const Drob& b);

};
//��������� + ��������
Drob operator+ (const Drob& a, const Drob& b) {
	Drob tmp = a;
	tmp += b;	
	tmp.reduce();
	return tmp;
}
Drob operator+ (const Drob& a, int b) {
	Drob tmp = a;
	tmp += Drob(b);
	tmp.reduce();
	return tmp;
}
Drob operator+ (int a, const Drob& b) {
	Drob tmp = b;
	tmp += Drob(a);
	tmp.reduce();
	return tmp;
}

//��������� ����� (��������)
Drob operator- (const Drob& a, const Drob& b) {
	Drob tmp = a;
	tmp -= b;
	tmp.reduce();
	return tmp;
}
Drob operator- (const Drob& a, int b) {
	Drob tmp = a;
	tmp -= Drob(b);
	tmp.reduce();
	return tmp;
}
Drob operator- (int a, const Drob& b) {
	Drob tmp1 = b;
	Drob tmp2 = Drob(a);
	tmp2 -= tmp1;
	tmp2.reduce();
	return tmp2;
}

//������� �����
Drob operator- (const Drob& a) {
	Drob tmp = (-a.getX(), a.getY());
	return tmp;
}

//��������� ���������
Drob operator* (const Drob& a, const Drob& b) {
	Drob tmp = a;
	tmp *= b;
	tmp.reduce();
	return tmp;
}
Drob operator* (const Drob& a, int b) {
	Drob tmp = a;
	tmp *= Drob(b);
	tmp.reduce();
	return tmp;
}
Drob operator* (int a, const Drob& b) {
	Drob tmp = b;
	tmp *= Drob(a);
	tmp.reduce();
	return tmp;
}

//��������� �������
Drob operator/ (const Drob& a, const Drob& b) {
	Drob tmp = a;
	tmp /= b;
	tmp.reduce();
	return tmp;
}
Drob operator/ (const Drob& a, int b) {
	Drob tmp = a;
	tmp /= Drob(b);
	tmp.reduce();
	return tmp;
}
Drob operator/ (int a, const Drob& b) {
	Drob tmp1 = b;
	Drob tmp2 = Drob(a);
	tmp2 /= tmp1;
	tmp2.reduce();
	return tmp2;
}

//�������� ������
ostream& operator<< (ostream& out, const Drob& a) {
	out << a.x << " / " << a.y << " = " << (double)a.x / a.y;
	return out;
}

//�������� �����
istream& operator>> (istream& in, Drob& a) {
	cout << "Input X: " << endl;
	in >> a.x;
	cout << "Input Y: " << endl;
	int temp;
	in >> temp;
	a.setY(temp);
	a.reduce();
	return in;
}