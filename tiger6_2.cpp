#include <string>
#include <iostream>


using namespace std;
class Mammal {
protected:
    int age; // Age of a mammal
    int size; // Size of a mammal
    bool isHungry; // A mammal can be hungry or not
    string family; // family: like cats or bears
public:
    // Default constructor
    Mammal(int age=10, int size=20, bool isHungry=false, string family=""):
            age(age), size(size), isHungry(isHungry), family(family) {}
// Copy constructor
    Mammal(const Mammal& m):
            age(m.age), size(m.size), isHungry(m.isHungry), family(m.family) {}
// Virtual destructor
    virtual ~Mammal() {
        cout << "Calling virtual destructor of Mammal" << endl;
    }
};
class Cats: public Mammal {
protected:
    string colourOfSkin;
    string colourOfEyes;
    string genus; // Genus: Felinae, Pantherinae, Proailurinae
    virtual void run(int speed = 60) {
        cout << "Running. Should be overriden in childs" << endl;
    }

public:
    ~Cats() {
        cout << "Calling virtual destructor of cats" << endl;
    }

    virtual void hunt() {
        cout << "Hunting. Should be overriden in childs" << endl;
        run(40);
    }


    // Default constructor
    Cats(int age=5, int size=20, bool isHungry=true, string colourOfSkin="red", string colourOfEyes="white", string genus=" "):
            Mammal(age, size, isHungry, "cats"), colourOfSkin(colourOfSkin), colourOfEyes(colourOfEyes), genus(genus)
    {}

    // Copy constructor
    Cats(const Cats& c):
    Mammal(c), genus(c.genus), colourOfSkin(c.colourOfSkin), colourOfEyes(c.colourOfEyes)
    {}
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
    // Friendly operator function for output. Definition.
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
            Cats(age, size, isHungry, colourOfSkin, colourOfEyes, "tiger"), speed(speed),
            fangLength(fangLength), breed(breed), averageDailyCourse(averageDailyCourse)
    {}

    // copying constructor
    Tiger(Tiger const& instance):
    fangLength(instance.fangLength), speed(instance.speed), breed(instance.breed),
            averageDailyCourse(instance.averageDailyCourse), Cats(instance)
    {}
};

// Friendly operator function for output. Implementation.
ostream& operator<<(ostream& output, const Tiger& T) {
    output << "Breed: " << T.breed << endl;
    output << "Colour of skin: " << T.colourOfSkin << endl;
    output << "Colour of eyes: " << T.colourOfEyes << endl;
    output << "Age: " << T.age << endl;
    output << "Speed: " << T.speed << endl;
    output << "Size: " << T.size << endl;
    output << "Length of fangs: " << T.fangLength << endl;
    output << "Average daily course: " << T.averageDailyCourse << endl;
    output << "Family: " << T.family << endl;
    output << "Genus: " << T.genus << endl;
    output << (T.isHungry ? "The tiger is hungry" : "The tiger is not hungry") << endl;
    return output;
}


int main() {
    // Calling default constructor
    Tiger t1(15,20,true,"green","black",40,400);
    // Tiger t2 is a copy of t1
    Tiger t2 = t1;
    // Visualization
    cout << t1 << endl;
    cout << t2;
    // Calling method of the class
    //t1.hunt(50);
}