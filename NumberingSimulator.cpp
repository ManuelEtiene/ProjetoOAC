#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// Funções de conversão
string DecimalParaBinario(int numero);
int BinarioParaDecimal(string binario);

string DecimalParaOctal(int decimal);
int OctalParaDecimal(string octal);

string DecimalParaHexadecimal(int decimal);
int HexadecimalParaDecimal(string hexa);

// Função de operação matemática
int fazerOperacao(int a, int b, char operador);

// Menu principal
void mostrarMenu();

int main() {
    mostrarMenu();
    return 0;
}

void mostrarMenu() {
    int opcao;

    do {
        cout << "\n=== SIMULADOR DE SISTEMAS DE NUMERAÇÃO ===\n";
        cout << "1. Conversões entre bases\n";
        cout << "2. Operações Aritméticas\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                int escolha;
                cout << "\n--- CONVERSÕES ---\n";
                cout << "1. Decimal para Binário, Octal e Hexadecimal\n";
                cout << "2. Binário para Decimal\n";
                cout << "3. Octal para Decimal\n";
                cout << "4. Hexadecimal para Decimal\n";
                cout << "Escolha: ";
                cin >> escolha;

                if (escolha == 1) {
                    int numeroDecimal;
                    cout << "Digite um número decimal: ";
                    cin >> numeroDecimal;
                    cout << "Binário: " << DecimalParaBinario(numeroDecimal) << endl;
                    cout << "Octal: " << DecimalParaOctal(numeroDecimal) << endl;
                    cout << "Hexadecimal: " << DecimalParaHexadecimal(numeroDecimal) << endl;
                } else if (escolha == 2) {
                    string numeroBinario;
                    cout << "Digite um número binário: ";
                    cin >> numeroBinario;
                    cout << "Decimal: " << BinarioParaDecimal(numeroBinario) << endl;
                } else if (escolha == 3) {
                    string numeroOctal;
                    cout << "Digite um número octal: ";
                    cin >> numeroOctal;
                    cout << "Decimal: " << OctalParaDecimal(numeroOctal) << endl;
                } else if (escolha == 4) {
                    string numeroHexa;
                    cout << "Digite um número hexadecimal: ";
                    cin >> numeroHexa;
                    cout << "Decimal: " << HexadecimalParaDecimal(numeroHexa) << endl;
                }
                break;
            }

            case 2: {
                int base;
                cout << "\n--- OPERAÇÕES ARITMÉTICAS ---\n";
                cout << "Escolha a base dos números:\n";
                cout << "1. Decimal\n2. Binário\n3. Octal\n4. Hexadecimal\n";
                cout << "Base: ";
                cin >> base;

                string numero1, numero2;
                char operador;

                cout << "Digite o primeiro número: ";
                cin >> numero1;
                cout << "Digite o operador (+ - * /): ";
                cin >> operador;
                cout << "Digite o segundo número: ";
                cin >> numero2;

                int valor1, valor2, resultado;
                switch (base) {
                    case 1: // Decimal
                        valor1 = stoi(numero1);
                        valor2 = stoi(numero2);
                        resultado = fazerOperacao(valor1, valor2, operador);
                        cout << "Resultado (Decimal): " << resultado << endl;
                        break;

                    case 2: // Binário
                        valor1 = BinarioParaDecimal(numero1);
                        valor2 = BinarioParaDecimal(numero2);
                        resultado = fazerOperacao(valor1, valor2, operador);
                        cout << "Resultado:\nDecimal: " << resultado << "\nBinário: " << DecimalParaBinario(resultado) << endl;
                        break;

                    case 3: // Octal
                        valor1 = OctalParaDecimal(numero1);
                        valor2 = OctalParaDecimal(numero2);
                        resultado = fazerOperacao(valor1, valor2, operador);
                        cout << "Resultado:\nDecimal: " << resultado << "\nOctal: " << DecimalParaOctal(resultado) << endl;
                        break;

                    case 4: // Hexadecimal
                        valor1 = HexadecimalParaDecimal(numero1);
                        valor2 = HexadecimalParaDecimal(numero2);
                        resultado = fazerOperacao(valor1, valor2, operador);
                        cout << "Resultado:\nDecimal: " << resultado << "\nHexadecimal: " << DecimalParaHexadecimal(resultado) << endl;
                        break;
                }
                break;
            }

            case 0:
                cout << "Encerrando o programa...\n";
                break;

            default:
                cout << "Opção inválida!\n";
        }

    } while (opcao != 0);
}

// --------- Funções de conversão ---------

string DecimalParaBinario(int numero) {
    if (numero == 0) return "0";
    string binario;
    while (numero > 0) {
        char bit = (numero % 2) + '0';
        binario = bit + binario;
        numero /= 2;
    }
    return binario;
}

int BinarioParaDecimal(string binario) {
    int decimal = 0;
    for (int i = 0; i < binario.size(); i++) {
        if (binario[i] == '1') {
            decimal += pow(2, binario.size() - 1 - i);
        }
    }
    return decimal;
}

string DecimalParaOctal(int decimal) {
    if (decimal == 0) return "0";
    string octal;
    while (decimal > 0) {
        octal = char((decimal % 8) + '0') + octal;
        decimal /= 8;
    }
    return octal;
}

int OctalParaDecimal(string octal) {
    int decimal = 0, potencia = 0;
    for (int i = octal.size() - 1; i >= 0; i--) {
        decimal += (octal[i] - '0') * pow(8, potencia++);
    }
    return decimal;
}

string DecimalParaHexadecimal(int decimal) {
    if (decimal == 0) return "0";
    string hexadecimal;
    char simbolos[] = "0123456789ABCDEF";
    while (decimal > 0) {
        hexadecimal = simbolos[decimal % 16] + hexadecimal;
        decimal /= 16;
    }
    return hexadecimal;
}

int HexadecimalParaDecimal(string hexa) {
    int decimal = 0;
    for (int i = 0; i < hexa.size(); i++) {
        char caractere = toupper(hexa[i]);
        int valor = (isdigit(caractere)) ? caractere - '0' : caractere - 'A' + 10;
        decimal = decimal * 16 + valor;
    }
    return decimal;
}

// --------- Função para realizar operações básicas ---------
int fazerOperacao(int a, int b, char operador) {
    switch (operador) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (b != 0) ? a / b : 0;
        default: return 0;
    }
}







/*#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Cabeçalho das funções.
string DecimalToBinary(int numero);
int BinaryToDecimal(string binario);

// int OctalToDecimal(string octal);
// string DecimalToOctal(int decimal);
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

while (numero > 0)
{
  
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
	
    //
    for (int i = 0; i < binario.size(); i++) {
        if (binario[i] == '1') {
            decimal += pow(2, binario.size() - 1 - i);
        }
    }
	return decimal;
}
*/
