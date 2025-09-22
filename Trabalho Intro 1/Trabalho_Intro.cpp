#include <iostream>
#include <locale.h>
#include <iomanip>

using namespace std;

//Funcao de calculo de media aritmetica envolvendo os valores de 3 variaveis.
float mediaF (float X, float Y, float Z) {

    float MD;

    MD = (X + Y + Z) / 3;

    return MD;
}

int main () {

    setlocale(LC_ALL,"Portuguese");

    int cont = 0;
    float N1[5], N2[5], N3[5], MF[5];
    string aluno[5], situacao[5];
    string ordem[5] = {"primeiro(a)", "segundo(a)", "terceiro(a)", "quarto(a)", "quinto(a)"};

    //laco que pede ao usuario as entradas e armazena nos arrays de cada variavel correspondente.
    while (cont < 5) {
       cout << "Qual o nome do(a) " << ordem[cont] << " aluno(a)? ";
        cin >> aluno[cont];
        cout << "Digite as tres notas do(a) aluno(a): ";
        cin >> N1[cont] >> N2[cont] >> N3[cont];

        //realizo a call com a funcao "mediaF" e defino as 3 variaveis solicitadas pela funcao.
        MF[cont] = mediaF (N1[cont], N2[cont], N3[cont]); 

        cont++;
    }

    cont = 0;

    //laco para definir se o aluno foi reprovado ou aprovado, utilizando-se da variavel calculada pela funcao "mediaF".
    while (cont < 5) {

        //verificador se a media final esta entre 7 e 10 para definir a aprovacao do aluno.
        if (MF[cont] >= 7.0 && MF[cont] <= 10.0) {
            situacao[cont] = "Aprovado(a)";
        }
        else {
            situacao[cont] = "Reprovado(a)";
        }

        cont++;
    }

    cont = 0;

    //fixo as variaveis float com apenas 1 casa decimal.
    cout << fixed << setprecision(1);

    //Crio o cabecalho dos dados de saida em conjunto com o espacamento.
    cout << setw(15) << "Aluno(a)" << setw(8) << "M1" << setw(8) << "M2" << setw(8) << "M3" << setw(8) << "Media" << setw(15) << "Situacao" << endl;

    //laco que imprime os resultados tabulados de cada aluno em ordem crescente conforme a entrada dos dados.
    while (cont < 5) {
        cout << setw(15) << aluno[cont] << setw(8) << N1[cont] << setw(8) << N2[cont] << setw(8) << N3[cont] << setw(8) << MF[cont] << setw(15) << situacao[cont] << endl;
    
        cont++;
    }
    
    cont = 0;

    //laco que encontra o aluno com o a maior media (com base nas variaveis calculadas pela funcao "mediaF") e retorna o texto informando o aluno.
    while (cont < 5) {
        if (MF[cont] >= MF[0] && MF[cont] >= MF[1] && MF[cont] >= MF[2] && MF[cont] >= MF[3] && MF[cont] >= MF[4]) {
            cout << "A maior media da turma foi do(a) aluno(a): " << aluno[cont] << " com " << MF[cont] << " de media. ";
            cont = 5;
        }
        else{
            cont++;
        }
    }

    return 0;
}