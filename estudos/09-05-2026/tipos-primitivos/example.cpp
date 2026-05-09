// 09/05/2026 - Tipos de dados
// Nome Pablo Gustavo (pardall-dev)

#include <iostream>
#include <memory>
#include <string>
#include <vector>

// ============================================================================
// 1. TIPOS DEFINIDOS PELO USUÁRIO (User-Defined Types)
// ============================================================================

// Enumeração fortemente tipada (Scoped Enum)
enum class StatusTarefa { Pendente, EmProgresso, Concluida };

// Estrutura (Membros públicos por padrão) - Ideal para agregados de dados
// simples
struct Coordenada {
  double latitude;
  double longitude;
};

// Classe (Membros privados por padrão) - Ideal para encapsulamento e lógica de
// negócios
class Funcionario {
private:
  std::string nome;
  double salario;

public:
  // Construtor
  Funcionario(std::string n, double s) : nome(std::move(n)), salario(s) {}

  // Método 'const' garante que o estado do objeto não será modificado
  void exibirDados() const {
    std::cout << "Funcionário: " << nome << " | Salário: R$" << salario << "\n";
  }
};

// União (Union) - Compartilha o mesmo espaço de memória para economia de
// recursos
union Medida {
  int valorInteiro;
  float valorFlutuante;
};

// ============================================================================
// FUNÇÃO AUXILIAR (Demonstração de 'void' e ponteiros)
// ============================================================================
void processarDados(const int *ponteiroConstante) {
  if (ponteiroConstante != nullptr) {
    std::cout << "Valor lido via ponteiro: " << *ponteiroConstante << "\n";
  }
}

// ============================================================================
// FUNÇÃO PRINCIPAL
// ============================================================================
int main() {
  // ------------------------------------------------------------------------
  // A. TIPOS FUNDAMENTAIS (Primitive Types)
  // ------------------------------------------------------------------------
  bool ativo = true;                // Booleano (1 byte)
  char inicial = 'A';               // Caractere (1 byte)
  int idade = 30;                   // Inteiro padrão (geralmente 4 bytes)
  unsigned int idpositivo = 42000U; // Inteiro sem sinal (apenas positivo)
  long long populacaoMundial =
      8000000000LL;          // Inteiro de 64 bits (pelo menos 8 bytes)
  float temperatura = 26.5f; // Ponto flutuante de precisão simples (4 bytes)
  double pi = 3.141592653589793; // Ponto flutuante de precisão dupla (8 bytes)

  // ------------------------------------------------------------------------
  // B. TIPOS COMPOSTOS (Compound Types)
  // ------------------------------------------------------------------------
  // Ponteiro (Armazena o endereço de memória de outra variável)
  int *ponteiroIdade = &idade;

  // Referência Lvalue (Alias/Apelido para uma variável existente)
  int &referenciaIdade = idade;
  referenciaIdade =
      31; // Alterar a referência altera a variável original ('idade')

  // Vetor tradicional (C-style Array - Tamanho fixo)
  int notas[3] = {8, 9, 10};

  // ------------------------------------------------------------------------
  // C. INSTANCIAÇÃO DE TIPOS DEFINIDOS PELO USUÁRIO
  // ------------------------------------------------------------------------
  // Instanciando Struct
  Coordenada local{-23.55052, -46.633308}; // São Paulo

  // Instanciando Classe
  Funcionario dev("Alice Oliveira", 8500.00);

  // Utilizando Enum Class
  StatusTarefa statusAtual = StatusTarefa::EmProgresso;

  // Utilizando Union
  Medida m;
  m.valorInteiro = 100; // Escreve no espaço de memória
  // m.valorFlutuante = 5.5f; // Se fizermos isso, o valorInteiro será
  // sobrescrito!

  // ------------------------------------------------------------------------
  // D. RECURSOS MODERNOS (C++11 em diante)
  // ------------------------------------------------------------------------
  // Dedução de Tipo automática com 'auto'
  auto nomeDoProjeto =
      std::string("Sistema de Tipagem"); // O compilador infere: std::string
  auto listaNumeros =
      std::vector<int>{1, 2, 3, 4, 5}; // O compilador infere: std::vector<int>

  // Referência Rvalue (&&) - Usada para movimentação de recursos temporários
  std::string &&textoTemporario = std::string("Texto Efêmero");

  // ============================================================================
  // EXIBIÇÃO DOS RESULTADOS NO CONSOLE
  // ============================================================================
  std::cout << "--- Tipos Fundamentais ---\n";
  std::cout << "Idade modificada via referência: " << idade << "\n";
  std::cout << "Pi (double): " << pi << "\n";
  std::cout << "Ativo: " << std::boolalpha << ativo << "\n\n";

  std::cout << "--- Tipos Compostos ---\n";
  processarDados(ponteiroIdade); // Passa o endereço de 'idade'
  std::cout << "Primeira nota do vetor: " << notas[0] << "\n\n";

  std::cout << "--- Tipos Definidos pelo Usuário ---\n";
  std::cout << "Coordenadas GPS: Lat " << local.latitude << " | Long "
            << local.longitude << "\n";
  dev.exibirDados();

  if (statusAtual == StatusTarefa::EmProgresso) {
    std::cout << "Status da tarefa: Em Progresso.\n";
  }

  std::cout << "Valor da Union (Inteiro): " << m.valorInteiro << "\n\n";

  std::cout << "--- C++ Moderno ---\n";
  std::cout << "Projeto (auto): " << nomeDoProjeto << "\n";
  std::cout << "Elemento do vector (auto): " << listaNumeros[0] << "\n";

  return 0;
}

// Copyright (c) 2026 Pablo Gustavo (pardall-dev). All Rights Reserved.
