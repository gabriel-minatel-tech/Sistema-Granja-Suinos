#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

typedef struct SUINO {
    int ID;
    int raca;
    int idade;
    double pesoAtual; 
    char sexo;
} T_suino;
 
const int MAX = 10;
int buscarPorBrinco(T_suino animais[], int total, int idProcurado);
void cadastrarSuino(T_suino vetor[], int *total);
void listarRebanho(T_suino vetor[], int total);
void atualizarAnimal(T_suino vetor[], int total);
void menu();
void gerarPainelEstatistico(T_suino vetor[], int total);

int main() {
    setlocale(LC_ALL, "Portuguese");
    cout << "--------- Granja de Suinos ---------" << endl;
    menu();
    
    return 0;
}

void cadastrarSuino(T_suino vetor[], int *total) {
    if (*total < MAX) {
        cout << "\n ID: ";
        cin >> vetor[*total].ID;
        
        cout << "\n Raca: ";
        cout << "\n 1 - Landrace";
        cout << "\n 2 - Large White";
        cout << "\n 3 - Duroc";
        cout << "\n 4 - Outra";
        cout << "\n Informe a raca: ";
        cin >> vetor[*total].raca;
        
        while(vetor[*total].raca < 1 || vetor[*total].raca > 4) {
            cout << "Raca Invalida - Digite Novamente: ";
            cin >> vetor[*total].raca;
        }
        
        cout << "\n Idade do Animal (em anos): ";
        cin >> vetor[*total].idade;
        while(vetor[*total].idade < 0) {
            cout << "Idade Invalida - Digite Novamente: ";
            cin >> vetor[*total].idade;
        }
        
        cout << "\n Peso do Animal (kg): ";
        cin >> vetor[*total].pesoAtual;
        while(vetor[*total].pesoAtual < 0) {
            cout << "Peso Invalida - Digite Novamente: ";
            cin >> vetor[*total].pesoAtual;
        }
        
        cout << "\n Sexo do Animal ( M - Macho | F - Fêmea ): ";
        cin >> vetor[*total].sexo;
        vetor[*total].sexo = toupper(vetor[*total].sexo);
        
        while((vetor[*total].sexo != 'M') && (vetor[*total].sexo != 'F')) {
            cout << "\n Sexo Invalida - Digite Novamente: ";
            cin >> vetor[*total].sexo;
            vetor[*total].sexo = toupper(vetor[*total].sexo);
        }
		
        (*total)++;
        
    } else {
        cout << "Vetor atingiu capacidade máxima";
    }
}

void listarRebanho(T_suino vetor[], int total) {
    // Cabeï¿½alho
    cout << left 
         << "| " << setw(7)  << "ID" 
         << "| " << setw(9)  << "Raca" 
         << "| " << setw(8)  << "Idade" 
         << "| " << setw(9)  << "Peso" 
         << "| " << setw(9)  << "Sexo" 
         << "|" << endl;

    cout << "----------------------------------------------------" << endl;

    // Vetor
    for(int i = 0; i < total; i++) {
        cout << left 
             << "| " << setw(7)  << vetor[i].ID 
             << "| " << setw(9)  << vetor[i].raca 
             << "| " << setw(8)  << vetor[i].idade 
             << "| " << setw(9)  << vetor[i].pesoAtual 
             << "| " << setw(9)  << vetor[i].sexo 
             << "|" << endl;
    }
}

int buscarPorBrinco(T_suino animais[], int total, int idProcurado) {
    
    for(int i = 0; i < total; i++) {
        if (idProcurado == animais[i].ID)
            return i;
    }
    return -1;
    
}

void atualizarAnimal(T_suino vetor[], int total) {
    int idProcurado, result;
    cout << "\n Digite o ID do brinco que busca: ";
    cin >> idProcurado;
    result = buscarPorBrinco(vetor, total, idProcurado);
    if(result != -1)
        cout << "Posicao [" << result << "] do animal procurado" << endl; 
        cout << "Peso do animal " << vetor[result].pesoAtual << endl;
    cout << "Informe o valor do peso atualizado do animal: ";
    cin >> vetor[result].pesoAtual;
}

void menu() {
    T_suino Animais[MAX];
    int total = 0;
    int idProcurado, result;
    int op, continuar;
    
    do {
        cout << "================= Menu =================" << endl;
        cout << endl;
        cout << "1 - Cadastro de Suino: " << endl;
        cout << "2 - Relatorio de Suino: " << endl;
        cout << "3 - Pesquisa por ID: " << endl;
        cout << "4 - Atualizar Status de Peso: " << endl;
        cout << "5 - Painel Estatistico: " << endl;
        cout << endl;
        cout << "========================================" << endl;
        cout << "\n Escolha: ";
        cin >> op;
        
        switch(op) {
            case 1: 
                cadastrarSuino(Animais, &total);
                break;
            case 2: 
                listarRebanho(Animais, total);
                break;
            case 3: 
                cout << "\n Digite o ID do brinco que busca: ";
                cin >> idProcurado;
                result = buscarPorBrinco(Animais, total, idProcurado);
                if(result != -1)
                    cout << "Posicao [" << result << "] do animal procurado" << endl; 
                break;
            case 4: 
                atualizarAnimal(Animais, total);
                break;
            case 5: 
                gerarPainelEstatistico(Animais, total);
                break;
            default:
                cout << "Opicao escolhida erra";
                break;
        }
        
        cout << "\n Deseja continuar (1 - SIM | 0 - NAO): ";
        cin >> continuar;
        system("cls");
    } while(continuar == 1);
    
}

void gerarPainelEstatistico(T_suino vetor[], int total)
{
	cout << "========== Painel Estatistico ==========" << endl;
    cout << endl;
    cout << "1 - Media de Peso por Sexo" << endl;
    cout << "------------------------------------" << endl;	
    
	// Mï¿½dia Peso / Sexo
 	float mediaM = 0.0, mediaF = 0.0;
 	int somaM = 0, somaF = 0 ;
 	float pesoM = 0, pesoF = 0;
 	somaM = somaF = 0;
	for(int i = 0; i < total; i++) {
		if( vetor[i].sexo == 'M' ) {
			somaM++;
			pesoM += vetor[i].pesoAtual;
		} else if (vetor[i].sexo == 'F') {
			somaF++;
			pesoF += vetor[i].pesoAtual;
		}
	}   
	if (somaM > 0) {
        mediaM = pesoM / somaM;
        cout << "Media de Peso ( Machos ) = " << mediaM << " kg" << endl;
    } else {
        cout << "Media de Peso ( Machos ) = Sem machos para calcular" << endl;
    }

    if (somaF > 0) {
        mediaF = pesoF / somaF;
        cout << "Media de Peso ( Fêmeas ) = " << mediaF << " kg" << endl;
    } else {
        cout << "Media de Peso ( Fêmeas ) = Sem fï¿½meas para calcular" << endl;
    }
    cout << endl;
    cout << "\n ==========================================================" << endl;
    cout << "2 - Porcentagem de Animais (Sexo / Raca) " << endl;
    cout << "--------------------------------------------" << endl;
    
    // Sexo / Raï¿½a
	float landraceM = 0, largeM = 0, durocM = 0, outroM = 0;
    float landraceF = 0, largeF = 0, durocF = 0, outroF = 0;

    for (int i = 0; i < total; i++) {
        if (vetor[i].sexo == 'M') {
            if (vetor[i].raca == 1) landraceM++;
            else if (vetor[i].raca == 2) largeM++;
            else if (vetor[i].raca == 3) durocM++;
            else outroM++;
        } else if (vetor[i].sexo == 'F') {
            if (vetor[i].raca == 1) landraceF++;
            else if (vetor[i].raca == 2) largeF++;
            else if (vetor[i].raca == 3) durocF++;
            else outroF++;
        }
    }  

    if (total > 0) {
        cout << fixed << setprecision(2);
        cout << "Machos - Landrace:    " << (landraceM / total) * 100 << "%" << endl;
        cout << "Machos - Large White: " << (largeM / total) * 100 << "%" << endl;
        cout << "Machos - Duroc:       " << (durocM / total) * 100 << "%" << endl;
        cout << "Machos - Outras:      " << (outroM / total) * 100 << "%" << endl;
        cout << endl;
        cout << "Femeas - Landrace:    " << (landraceF / total) * 100 << "%" << endl;
        cout << "Femeas - Large White: " << (largeF / total) * 100 << "%" << endl;
        cout << "Femeas - Duroc:       " << (durocF / total) * 100 << "%" << endl;
        cout << "Femeas - Outras:      " << (outroF / total) * 100 << "%" << endl;
    } else {
        cout << "Sem animais cadastrados para calcular porcentagens." << endl;
    }
    
    cout << "\n ==========================================================" << endl;
    cout << "3 - Identificacao do Campeao em Peso " << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl;
    
    // Peso Campeï¿½o
    if(total > 0) {
	    int idxCampeao = 0;
	    for(int i = 1; i < total; i++) {
	    	if(vetor[i].pesoAtual > vetor[idxCampeao].pesoAtual) idxCampeao = i;
		}
		cout << "MAIOR PESO CADASTRADO - posicao [" << idxCampeao << "]" << endl;
	    cout << left 
	         << "| " << setw(7)  << "ID" 
	         << "| " << setw(9)  << "Raca" 
	         << "| " << setw(9)  << "Peso" 
	         << "|" << endl;
	
	    cout << "----------------------------------------------------" << endl;
	
	    cout << left 
	        << "| " << setw(7)  << vetor[idxCampeao].ID 
	        << "| " << setw(9)  << vetor[idxCampeao].raca 
	        << "| " << setw(9)  << vetor[idxCampeao].pesoAtual 
	        << "|" << endl;
	} else {
		cout << "Nenhum animal cadastrado para identificar o campeao." << endl;
	}
}
