#include <iostream>
#include <fstream>
#include <random>
#include <chrono>

using namespace std; 
using namespace chrono;

class ChanceGame {
private:
    int chance;
    char choice;

public:
    ChanceGame() {
        
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
           default_random_engine generator(seed);

        
        uniform_int_distribution<int> distribution(1, 100);
        chance = distribution(generator);
    }

    void displayChance() {
        cout << "your chance :  " << chance << endl;
    }

    void getChoice() {
         cout << "Do you bilive your team  (Y/N): ";
         cin >> choice;
    }

    void saveResultToFile() {
        
        ofstream outputFile("confidence_result.txt");
        if (outputFile.is_open()) {
            outputFile << "your chance : " << chance << endl;
            outputFile << "Do you bilive your team " << ((choice == 'Y' || choice == 'y') ? "Y" : "N") << endl;
            outputFile.close();
        } 
        else {
            cout << "erorr open file !" << endl;
        }
    }
};

int main() {
    ChanceGame game;

    game.displayChance();
    game.getChoice();
    game.saveResultToFile();

    return 0;
}
