#include <bits/stdc++.h>
using namespace std;
class bird
{
  /* data */
public:
  int legs;
  int eyes;
  string color;
  string name;

  void eat()
  {
    cout << "eating" << endl;
  };
  void fly()
  {
    cout << "flying" << endl;
  };
  void sleep()
  {
    cout << "sleeping" << endl;
  };
};

class Sparrow : public bird
{
private:
  int age;

public:
  Sparrow(int legs, int eyes, string color, string name, int age)
  {
    this->legs = legs;
    this->eyes = eyes;
    this->color = color;
    this->name = name;
    this->age = age;
  }
  Sparrow(const Sparrow &srcobj)
  {

    cout << "Student copy ctor called" << endl;
    this->legs = srcobj.legs;
    this->eyes = srcobj.eyes;
    this->color = srcobj.color;
    this->name = srcobj.name;
  }

  int getage()
  {
    return this->age;
  }
  void chirping()
  {
    cout << "chirping" << endl;
  }

  int getlegs()
  {
    return this->legs;
  }
};
int main()
{
  Sparrow S(2, 2, "blue", "Parrow", 200);
  Sparrow V = S;
  cout << V.name << endl;
  cout << S.getage() << endl; 

  // S.eat();
  // S.sleep();
  S.chirping();
  cout << S.getlegs();
  // cout<<S.name<<"  "<<endl;
  // cout<<S.color<<"  "<<endl;
  // cout<<S.eyes<<" "<<endl;
  return 0;
}