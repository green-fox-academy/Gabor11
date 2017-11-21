#include <iostream>
#include <iomanip>

using namespace std;


class Float {
    private:
        float mNum;
    public:
        void set(float _num)
        {
            mNum = _num;
        }
        float get()
        {
            return mNum;
        }
        Float()
        {
            mNum = 0.0f;
        }
        Float(float _num) :mNum(_num) {
        }

        // '&' means use by reference
        Float(Float& _other): mNum(_other.mNum) {
        }

        Float& operator += (float _num) {
            mNum += _num;
            return *this;
        }

        Float& operator += (Float& _other) {
            this->mNum += _other.mNum;
            return *this; // it returns with a class reference
        }

        Float& operator = (Float& _other) {
            mNum = _other.mNum;
            return *this;
        }

        Float& operator = (float _num) {
            mNum = _num;
            return *this;
        }
};

ostream& operator << (ostream& _os, Float& _float) {
    _os << _float.get();
    return _os;
}

int divideBy5(int _param)
{
    return _param/5;
}

float divideBy5(float _param)
{
    return (float) _param/5.0;
}

float gimmeFloat()
{
    return 3.14f;
}

double gimmeDouble()
{
    return 3.14;
}

int main()
{
    /*
    cout << "funct1: " << divideBy5(12) << "fucnt2: " << divideBy5(12.f) << endl;
    cout << "with returned value: " << divideBy5(gimmeFloat()) << endl;
    cout << "with returned value: " << divideBy5((float)gimmeDouble()) << endl;
    */

    Float a(12.f);
    Float b(3);
    Float c(24.0);
    Float d(c);

    cout << fixed;
    cout << setprecision(2) << a.get() << ", " << b.get() << ", "<< c.get() << ", "<< d.get() << endl;

    cout << "a += b: " << a += b << endl;
    cout << "a += 42.2: " << a += 42.2f << endl;

}
