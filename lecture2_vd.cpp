#include <string>
#include <iostream>
using namespace std;


class Mammal {
protected:
    int size;
    bool predator;
    bool herbivorous;
    int weight;
public:
    virtual ~Mammal() {
        cout << "Calling virtual destuctor of mammals" << endl;
    }

    Mammal(int weight, int size, bool predator, bool herbivorous):
    weight(weight), size(size), predator(predator), herbivorous(herbivorous) {
        cout << "Call mammal constructor" << endl;
    }

};

class Cats: public Mammal {
protected:
    string genus;
    string colourOfSkin;
    string colourOfEyes;
public:
      ~Cats() {
        cout << "Calling non-virtual destructor of cats" << endl;
    }
public:
    Cats(string genus="g", string colourOfSkin="e", string colourOfEyes="e", int weight=0, int size=9, bool predator=true, bool herbivorous=true):
    Mammal(weight, size, predator, herbivorous), colourOfEyes(colourOfEyes),colourOfSkin(colourOfSkin),genus(genus)
    {
        cout << "Call cats constructor" << endl;
    }


};

class Tiger: public Cats {
private:
    int speed;
    int fangLength;
public:
    Tiger(int speed=10, int fang=10, string genus="g", string colourOfSkin="e", string colourOfEyes="e", int weight=0, int size=9, bool predator=true, bool herbivorous=true):
    Cats(genus, colourOfSkin, colourOfEyes, weight, size, predator, herbivorous), speed(speed), fangLength(fangLength) {
        cout << "Call tiger constructor" << endl;
    }
     ~Tiger() {
        cout << "Tiger died" << endl;
    }

};


int main() {
   Mammal* t1 = new Tiger();
   delete t1;
}