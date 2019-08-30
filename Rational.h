#ifndef _RATIONAL_HPP_
#define _RATIONAL_HPP_

#include <iostream>

//Declaration de la classe Rational
class Rational {
private:
    int m_den;
    int m_num;

    void simplify() {
        int resultPgcd = pgcd(m_num, m_den);

        if(m_den < 0) {
            m_num = -m_num;
            m_den = -m_den;
        }
        if(m_num > (m_num/resultPgcd)) {
            m_num = m_num/resultPgcd;
        }
        if(m_den > (m_den/resultPgcd)) {
            m_den = m_den/resultPgcd;
        }
    }

public:
    int getDen() const;
    int getNum() const;
    int pgcd(int, int);
    Rational& operator=(int);
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);

    Rational(int numerator) {
        m_num = numerator;
        m_den = 1;
        simplify();
    }
    Rational(int numerator, int denominator) {
        m_num = numerator;
        m_den = denominator;
        simplify();
    }

    friend Rational operator+(const Rational& r1, const Rational& r2) {
        int num = 0;
        int den = 0;

        if(r1.getDen() == 1) {
            den = r1.getDen() * r2.getDen();
            num = (r1.getNum() * r2.getDen()) + r2.getNum();
        }

        if(r2.getDen() == 1) {
            den ‌​‌﻿‌​​‍‌= r1.getDen() * r2.getDen();
            num = (r1.getNum() + r2.getNum() * r1.getNum());

        } else if (r1.getDen() != 1 && r2.getDen() != 1) {
            den = r1.getDen() * r2.getDen();
            int computeNum1 = r1.getNum() * r2.getDen();
            int computeNum2 = r2.getNum() * r1.getDen();

            num = computeNum1 + computeNum2;
        }

        // simplify();

        return Rational(num, den);
    }

    friend Rational operator+=(const Rational& r1, int number) {
        int num;
        int den;

        number = 1;

        num = r1.getNum() + number * r1.getDen();
        den = r1.getDen() * number;

        return Rational(num, den);
    }

    friend Rational operator+=(const Rational& r1, const Rational& r2) {
        int num;
        int den;

        if(r1.getDen() != r2.getDen()) {
            den = r1.getDen() * r2.getDen();
            int computeNum1 = r1.getNum() * r2.getDen();
            int computeNum2 = r2.getNum() * r1.getDen();

            num = computeNum1 + computeNum2;
        } else {
            den = r1.getDen();
            num = r1.getNum() + r2.getNum();
        }

        return Rational(num, den);
    }
};

#endif
