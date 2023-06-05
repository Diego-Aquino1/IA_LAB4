//ALGORITMOS GENETICOS
#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class person{
    public:
        vector<char> PERSON;
        int fitness;

        void calcFitness(vector<vector<int>>&, vector<char>);
        void print();
        person(vector<char>);
        ~person();
};

void person::print(){
    for(int i=0; i<this->PERSON.size(); i++)
        cout<<PERSON[i]<<" ";
}

person::person(vector<char> permutation){
    this->fitness = 0;
    int numal;
    random_device rd;
    mt19937 gen(rd());
    shuffle(permutation.begin(), permutation.end(), gen);
    this->PERSON = permutation;
}

person::~person(){
    PERSON.clear();
}

void person::calcFitness(vector<vector<int>>& matrix, vector<char> base){
    int distance = 0;
    unordered_map<char, int> nodeindex;
    for (int i = 0; i < base.size(); i++){
        nodeindex[base[i]] = i;
    }

    int prev = nodeindex[PERSON[0]];
    for (int i = 1; i < PERSON.size(); i++){
        int curr = nodeindex[PERSON[i]];
        distance += matrix[prev][curr];
        prev = curr;
    }
    this->fitness=distance;
}

/////////////////////////////////////////////////////////////////

class people{
    public:
        vector<person> PEOPLE;

        void print();
        people(int, vector<char>, vector<vector<int>>&);
        ~people();
};

void people::print(){
    for (int i = 0; i < this->PEOPLE.size(); i++){
        PEOPLE[i].print();
        cout<<" - "<<PEOPLE[i].fitness<<endl;
    }
    
}

people::people(int num_individuos, vector<char> nodos, vector<vector<int>>& matrix){
    for(int i=0; i < num_individuos; i++){
        PEOPLE.push_back(person(nodos));
        PEOPLE.back().calcFitness(matrix, nodos);
    }
}

people::~people(){
    PEOPLE.clear();
}

int main(){

    int num_individuos = 30;
    cout<<"Parametros:\n"
    "- Cantidad de Individuos: "<<num_individuos<<"\n"
    "- Cantidad de Genes por Individuo: 10\n"
    "- Selección por Ruleta\n"
    "- Probabilidad de Cruzamiento: 0.9\n"
    "- Cruzamiento PBX\n"
    "- Probabilidad de Mutación: 0.5\n"
    "- Mutación de Intercambio\n"
    "- Cantidad de Iteraciones: 2000"<<endl;

    vector<char> nodos;
    nodos.push_back('D');
    nodos.push_back('I');
    nodos.push_back('E');
    nodos.push_back('G');
    nodos.push_back('O');
    nodos.push_back('A');
    nodos.push_back('Q');
    nodos.push_back('U');
    nodos.push_back('N');
    nodos.push_back('S');

    vector<vector<int>> matrix = {
        { 0,  7,  4,  1, 55,  9, 11, 35, 22, 33},
        { 7,  0, 45, 67, 10, 88, 12, 32, 44, 45},
        { 4, 45,  0, 64,  3, 47, 56, 89, 67, 76},
        { 1, 67, 64,  0, 21,  8, 54, 99, 78, 87},
        {55, 10,  3, 21,  0, 77,  2, 13, 25, 52},
        { 9, 88, 47,  8, 77,  0,  1,  6, 36, 63},
        {11, 12, 56, 54,  2,  1,  0,  3, 47, 74},
        {35, 32, 89, 99, 13,  6,  3,  0, 62, 26},
        {22, 44, 67, 78, 25, 36, 47, 62,  0, 92},
        {33, 45, 76, 87, 52, 63, 74, 26, 92,  0}
    };

    people P1(num_individuos, nodos, matrix);
    P1.print();

    return 0;
}