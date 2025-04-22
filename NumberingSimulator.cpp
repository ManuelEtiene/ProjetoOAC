#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>

using namespace std;

//Cabeçalho das funções.
string DecimalToBinary(int numero);
int BinaryToDecimal(string binario);

double OctalToDecimal(double octal); // Petronilo Bion
double DecimalToOctal(double decimal); // Petronilo Bion

// int HexadecimalToDecimal(string hexa);
// string DecimalToHexadecimal(int decimal);

// string BinaryToOctal(string binary);
// string BinaryToHexadecimal(string binary);

int main (){

    //Menu a ser implementado, contendo: opções de conversão e operações.
  
    //Recebe o número decimal, converte para binario e mostra na tela.
    cout << "Digite um número decimal: ";
    int decimal;
    cin >> decimal;

    string binario = DecimalToBinary(decimal);
    cout << "Binario: " << binario << endl;
	
	
    //Recebe o número binario, converte para decimal e mostra na tela.
	  cout << "Digite um numero binario: ";
    cin >> binario;

    decimal = BinaryToDecimal(binario);
    cout << "Decimal de " << binario << ": " << decimal << endl;
  
    return 0;
}

//Função para converter um numero decimal em binario.
string DecimalToBinary(int numero)
{
    string binario;

    while (numero > 0) {
        if (numero == 0) return "0";
        //Divisão do número por 2, e o resto da divisão é armazenado em uma variável char, através do auxílio da soma com o char de zero.
        char bit = (numero % 2) + '0';  
        binario = bit + binario; // Coloca o bit encontrado à esquerda no numero binario que estamos encontrando, para a correta ordem do numero binario.
        numero /= 2; // Divide o número por 2 e armazena nele mesmo.
    }
    return binario; 
}

//Função para converter um numero binario em decimal.
int BinaryToDecimal(string binario) {
    int decimal = 0;
    for (int i = 0; i < binario.size(); i++) {
        if (binario[i] == '1') {
            decimal += pow(2, binario.size() - 1 - i);
        }
    }
	  return decimal;
}

double OctalToDecimal(double octal) {
    int i = 0, resto;
    double decimal = 0.0;
    int inteiro = (int)octal;
    double fracao = octal - inteiro;

    // Conversão da parte inteira
    while (inteiro != 0)
    {
        resto = inteiro%10;
        inteiro/=10;
        decimal += resto*pow(8,i++);
    }
    i = 1;

    // Conversão da parte fracionária
    while(fracao != 0 && i <= 6){ // Limite de precisão: 6 dígitos
        fracao *= 10;
        resto = round(fracao);
        decimal += resto*pow(8,-i++);
        fracao -= resto;
    }
    return decimal;
}

double DecimalToOctal(double decimal) {
    int i = 0, resto;
    double octal = 0.0;
    int inteiro = (int)decimal;
    double fracao = decimal - inteiro;

    // Conversão da parte inteira
    while (inteiro != 0) {
        resto = inteiro%8;
        inteiro /= 8;
        octal += resto * pow(10, i++);
    }

    // Conversão da parte fracionária
    i = 1;
    while (fracao != 0.0 && i <= 6) { // Limite de precisão: 6 dígitos
        fracao *= 8;
        resto = round(fracao);
        octal += resto*pow(10, -i++);
        fracao -= resto;
    }

    return octal;
}
