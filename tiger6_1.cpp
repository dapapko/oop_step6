#include <string>
#include <iostream>
#include <fstream>


using namespace std;

class Cats {
protected:
    int age; // age of tiger
    int size; // size of  tiger
    bool isHungry; // A tiger is hungry(true) or not(false)
    string skinColour; // colour of skin
    string genus; // Genus: Felinae, Pantherinae, Proailurinae
    virtual void run(int speed = 60) {
        cout << "Running. Should be overriden in childs" << endl;
    }

public:
    virtual ~Cats() {
        cout << "Calling virtual destructor of cats" << endl;
    }

    virtual void hunt() {
        cout << "Hunting. Should be overriden in childs" << endl;
        run(40);
    }


    Cats(int age=5, int size=20, bool isHungry=true, string colourOfSkin="red", string colourOfEyes="white") :
            age(age), size(size), isHungry(isHungry), colourOfSkin(colourOfSkin), colourOfEyes(colourOfEyes)
    {}

    Cats(const Cats& c) : genus(c.genus), colourOfSkin(c.colourOfSkin), colourOfEyes(c.colourOfEyes),
                          isHungry(c.isHungry), age(c.age), size(c.size) {}
};

class Tiger : public Cats
{
    int fangLength; // length of fangs
    int speed; // Speed of a tiger
    string breed; // Breed of a tiger
    int averageDailyCourse; // Average Daily Course


    // running
    void run(int t_speed) {
        speed = t_speed;
        cout << "The tiger is running. Speed: " << t_speed << endl;
    }

public:
    // Friendly operator function
    friend ostream& operator<<(ostream& output, const Tiger& T);

    // hunting
    void hunt(int t_speed = 30) {
        if (!isHungry) cout << "Tiger is not hungry, so he don't hunt" << endl;
        else {
            if (age < 2) cout << "Tiger is hungry, he makes known about it tigress" << endl;
            else {
                cout << "Tiger is hungry, it begins to hunt." << endl;
                run(t_speed);
            }
        }
    }

    ~Tiger() {
        cout << "Calling tiger's dtor" << endl;
    }


    Tiger(int age=5, int size=10, bool isHungry=false, string colourOfSkin="orange", string colourOfEyes="brown",
          int fangLength=35, int speed=700, string breed="Amur", int averageDailyCourse=34) :
            Cats(age, size, isHungry, colourOfSkin, colourOfEyes), speed(speed),
            fangLength(fangLength), breed(breed), averageDailyCourse(averageDailyCourse)
    {}

    // copying constructor
    Tiger(Tiger const& instance):
    fangLength(instance.fangLength), speed(instance.speed), breed(instance.breed),
            averageDailyCourse(instance.averageDailyCourse), Cats(instance)
    {}
};

// Friendly operator function. Implementation.
ostream& operator<<(ostream& output, const Tiger& T) {
    output << "Breed: " << T.breed << endl;
    output << "Colour of skin: " << T.colourOfSkin << endl;
    output << "Colour of eyes: " << T.colourOfEyes << endl;
    output << "Age: " << T.age << endl;
    output << "Speed: " << T.speed << endl;
    output << "Size: " << T.size << endl;
    output << "Length of fangs: " << T.fangLength << endl;
    output << "Average daily course: " << T.averageDailyCourse << endl;
    output << (T.isHungry ? "The tiger is hungry" : "The tiger is not hungry") << endl;
    return output;
}


int main() {
    Tiger t1(15,20,true,"green","black",40,400);
    Tiger t2 = t1;
    cout << t1 << endl;
    cout << t2;
    t1.hunt(50);
}