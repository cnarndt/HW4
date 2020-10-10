#include <iostream>
#include<vector>
#include<ctime>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

void createSecretVec(vector<int>& secretVec)
{
    int num;
    bool flag = false;
    secretVec.push_back(rand()%10);
    while(secretVec.size()<4) {
        num = rand()%10;
        flag = true;
        for(int i = 0; i < secretVec.size();++i) {
            if(num == secretVec[i])
                flag = false;
        }
        if(flag) {
            secretVec.push_back(num); // then num insert in vector
        }
    }
}

void playGame(vector<int> secretVec, vector<char> guessVec, int& bulls, int& cows) {

    bulls =cows= 0;
    for(int i = 0; i < 4; ++i)
    {
        if(secretVec[i]==int(guessVec[i])-48) //find number of bulls
            bulls++;
        else
        {
            for(int j = 0; j < guessVec.size(); j++)
            {
                if(secretVec[i] == int(guessVec[j])-48)//find number of cows
                {
                    cows++;
                }
            }
        }

    }

}


int main()
{

    vector<int> secretVec;
    srand(time(0));
    createSecretVec(secretVec);

    cout<<"\nSecret Vector: ";
    for(int i = 0; i < 4; ++i)
        cout<< secretVec[i];

    int bulls=0, cows=0;
    vector<char> guessVec(4);
    while(bulls != 4) {

        cout << "\nEnter a 4-digit guess: ";
        for(int i = 0; i < 4; ++i)
            cin >> guessVec[i];

        playGame(secretVec, guessVec, bulls, cows);

        if(bulls == 4)
        {
            cout<<"\nCongratulation! you guessed the ";
            for(int i = 0; i < 4; ++i)
                cout<< secretVec[i];
            return 0;
        }
        else
            cout << "\nGuess again.";
        cout << "\nThat's " << bulls << " bulls, and " << cows << " cows;";

    }

    return 0;
}