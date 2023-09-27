#include <iostream>
#include <random>

using namespace std;
int main()
{
    const int MAX = 100;
    const int MIN = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(MIN, MAX);

    int numero_secreto = dist(gen);
    int chute;
    int numero_tentativas = 0;
    bool nao_acertou = true;
    float pontuacao = 1000;

    cout << "**************************************" << endl;
    cout << "* Bem-vindos ao jogo de adivinhacao! *" << endl;
    cout << "**************************************" << endl;

    cout << "" << endl;

    cout << "****************" << endl;
    cout << "** Instrucoes **" << endl;
    cout << "****************" << endl;
    cout << "" << endl;

    cout << "1) O jogo gera um numero de 1 a 100." << endl;
    cout << "2) O objetivo eh voce chutar para acertar." << endl;
    cout << "3) Quanto mais vezes você errar sua pontuacao sera diminuida." << endl;
    cout << "4) A pontuacao eh calculada atraves da distancia entre o numero chutado e o numero secreto." << endl;

    while (nao_acertou) {
        cout << "" << endl;
        cout << "Tentativa " << numero_tentativas << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Pontuacao: " << pontuacao << endl;
        cout << "" << endl;
        cout << "Digite seu chute: ";
        cin >> chute;
        cout << "O valor do seu chute foi: " << chute << "." << endl;
        bool acertou = chute == numero_secreto;
        bool maior = chute > numero_secreto;
        float distanciaAcerto = abs(numero_secreto - chute);
        float pontuacaoOffset = 0;
        numero_tentativas++;

        if (distanciaAcerto <= 20) pontuacaoOffset = distanciaAcerto * 1.5f;
        else if (distanciaAcerto <= 40) pontuacaoOffset = distanciaAcerto * 2.5f;
        else if (distanciaAcerto <= 60) pontuacaoOffset = distanciaAcerto * 3.0f;
        else if (distanciaAcerto <= 80) pontuacaoOffset = distanciaAcerto * 3.5f;
        else pontuacaoOffset = distanciaAcerto * 5.0f;

        pontuacao -= pontuacaoOffset;

        if (acertou) {
            cout << "Parabens, voce acertou o numero secreto!" << endl;
            cout << "Foram utilizadas: " << numero_tentativas << endl;
            cout.precision(2);
            cout << fixed;
            cout << "Sua pontuacao foi de: " << pontuacao << "pontos" << endl;
            acertou = true;
            break;
        }
        else if (maior) {
            cout << "Seu chute foi maior que o numero secreto!" << endl;
        }
        else {
            cout << "Seu chute foi menor que o numero secreto!" << endl;
        };

    }
;}

