#include <string>
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;


class Mammal {
protected:
    int size;
    bool predator;
    bool herbivorous;
    int weight;
    int age;
    bool isHungry;
    fstream file;

    virtual void run() {
        cout << "Should be overriden in childs" << endl;
    }
public:

    virtual ~Mammal() {
        cout << "Calling virtual destuctor of mammals" << endl;
    }



    Mammal() {
        file.open("coffee.txt");
        if (file.is_open())
        {
            file >> weight;
            file >> size;
            file >> predator >> herbivorous;
            file >> age;
            file >> isHungry;
            cout << "Call mammal constructor" << endl;
        }
    }

};

class Cats: public Mammal {
protected:
    string genus;
    string colourOfSkin;
    string colourOfEyes;
    virtual void run(int speed=60) {
        cout << "Running. Should be overriden in childs" << endl;
    }
public:
    ~Cats() {
        cout << "Calling non-virtual destructor of cats" << endl;
    }

    virtual void hunt() {
        cout << "Hunting. Should be overriden in childs" << endl;
        run(40);
    }

    Cats(): Mammal()
    {
        // Move to another string
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(file, genus);
        getline(file, colourOfSkin);
        getline(file, colourOfEyes);
        cout << "Call cats constructor" << endl;
    }


};

class Tiger: public Cats {
private:
    int speed;
    int fangLength;

    void run(int t_speed) {
        speed = t_speed;
        cout << "Tiger is running. Speed:" << speed << endl;
    }


public:
    friend ostream &operator<<( ostream &output, const Tiger& T );
    friend istream &operator>>( istream &input, const Tiger& T );
    Tiger(): Cats() {
        if (file.is_open()) {
            file >> speed;
            file >> fangLength;
        }
    }
    void hunt() {
        cout << "Tiger is hunting" << endl;
        run(70);
    }

    ~Tiger() {
        cout << "Tiger died" << endl;
        if (file.is_open()) file.close();
    }


};

// Friendly operator function for output. Implementation.
ostream &operator<<( ostream &output, const Tiger& T ) {
    output << "Out: " << endl;
    output << "Genus: " << T.genus << endl;
    output << "Eyes: " << T.colourOfEyes << endl;
    output << "Colour of skin: " << T.colourOfSkin << endl;
    output << "Speed: " << T.speed << endl;
    output << "Size: " << T.size << endl;
    output << "Fangs: " << T.fangLength << endl;
    return output;
}



int main() {
    Tiger t1;
    cout << t1;
    t1.hunt();
}
