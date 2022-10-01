#include <bits/stdc++.h>
using namespace std;

template <typename T, typename V>

class Pair
{
    T x;
    V y;

public:
    void setX(T element)
    {
        this->x = element;
    }
    void setY(V element)
    {
        this->y = element;
    }
    V getY()
    {
        return y;
    }
    T getX()
    {
        return x;
    }
};

int main()
{
    Pair<Pair<int, int>, int> p;
    p.setY(10);
    Pair<int, int> p1;
    p1.setX(20);
    p1.setY(20);
    p.setX(p1);

    cout << p.getY() << endl;
    cout << p.getX().getX() << endl;
    cout << p.getX().getY() << endl;
}
