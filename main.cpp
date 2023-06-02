//ALGORITMOS GENETICOS

#include <iostream>
#include <vector>

using namespace std;



class person{
    public:
        vector<char> PERSON;

        void calcFitness();
        person();
        ~person();
};

person::person(){
    PERSON.push_back(' ');
}

person::~person(){
    PERSON.clear();
}

void person::calcFitness(){

}

class people{
    public:
        vector<person> PEOPLE;
};


int main(){

    cout<<"Parametros:\n"
    "- Cantidad de Individuos: 50\n"
    "- Cantidad de Genes por Individuo: 10\n"
    "- Selección por Ruleta\n"
    "- Probabilidad de Cruzamiento: 0.9\n"
    "- Cruzamiento PBX\n"
    "- Probabilidad de Mutación: 0.5\n"
    "- Mutación de Intercambio\n"
    "- Cantidad de Iteraciones: 2000"<<endl;

    vector<vector<

    return 0;
}