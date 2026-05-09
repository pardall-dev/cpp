# 09/05/2026 - Tipos primitivos

## 1. Tipos fundamentais (Primitive / built-in Types)

São os tipos nativos da linguagem, fornecidos diretamente pelo compilador. Eles são a base para construir qualquer outra estrutura de dados

### - Tipos inteiros (`Integral Types`)

  - `char`: Representa um caracter (geralmente 1 byte). Pode ser `signed char` ou `unsigned char`
  - `int`: O tipo inteiro padrão (geralmente 4 bytes)

  - Modificadores de tamanho:

    - `short int` (garante pelo menos 16 bits)
    - `long int` (garante pelo menos 32 bits)
    - `long long int` (garante pelo menos 64 bits)

  - Modificadores de Sinal:

    - `signed` Permite valores negativos e positivos (padrão)
    - `unsigned` Apenas valores maiores ou iguais a zero, dobrando a capacidade positiva do tipo

### - Tipos de ponto flutuantes (`Floating-Point Types`)
  
Utilizados para representar números reais (com precisão decimal) seguindo o padrão IEE 754
  
  - `float`: Precisão simples (geralmente 4 bytes)
  - `double`: Precisão dupla (geralmente 8 bytes) - é o padrão para literais inteiros decimais em C++
  - `long double`: Precisão estendida (geralmente 8, 12 ou 16 bytes, dependendo da arquitetura)

### - Tipo Booleano e Vazio

  - `bool`: representa valores lógicos (`true` ou `false`)
  - `void`; Representa a ausência de tipo ou de valor. É usado principalmente como retorno de função que não retorna nada ou em ponteiros genéricos (`void*`)

## 2. Tipos Compostos (Compoud Types)

Tipos compostos são criados a partir dos tipos fundamentais ou de outros tipos compostos 

### - Referências e ponteiros

  - **Ponteiros (`T*`)**: Armazenam o endereço de memória de um objeto de tipo `T`. Podem ser reassociados e assumir o valor nulo (`nullptr`)
  - **Referências (`T$` ou `T&&`)**: Funciona como aliases (apelidos) para variaveis existentes

    - `Lvalue reference` (`T&`): Aponta para um objeto com identidade na memória
    - `Rvalue reference` (`T&&`): Intruduzido no C++11, estende a vida útil de objetos temporarios e viabiliza a semântica do movimento (essencial para performance)

### - Vetores (Arrays C-Style)

  - Representam sequências contiguas de elementos de tamanho fixo na mémoria. Na prática pratica profissional moderna, são amplamentes substituidos por `std::array` ou `std::vector`

## 3. Tipos definidos pelo usuários (User-Defined Types)

### - Classes e Estruturas

Em C++, a unica diferença técnica entre `class` e `struct` é o acesso padrão: membros de uma `struct` são públicos por padrão, enquanto os de uma `class` são privados. Ambos suportam herança, polimorfismo e emcapsulamento

```cpp
struct Ponto {
	double x; // Público por padrão
	double y;
};

class ContaBancaria {
	private:
		double saldo;
	public:
		void depositar(double valor);
};
```

### - Uniões (`union`)

Uma estrutura de dados onde todos os membros ocupam o mesmo espaço de memória.
O tamanho de uma `union` é o tamanho do seu maior membro. É usada para otimização de memória em sistemas embarcados ou de baixo nível

### - Enumerações (`enum` e `enum class`)

- `enum`tradicional (Unscoped): Exporta seus enumeradores para o escobo global, o que pode causar conflitos por nomes, e converte-se implicitamente para inteiro
- `enum class` (Scoped): Introduzido no C++11, fortemente tipado. não se converte para inteiro e exige escopo (ex: `Cor::Azul`), sendo a a escolha padrão no desenvolvimento moderno.

## 4. O sistema de tipos modernos (C++11 em diante)

o C++ moderno trouxe recursos que mudaram a forma como lidamos com a tipagem no dia a dia

### - Dedução de Tipos(`auto` e `decltype`)

- `auto`: Permite que o compilador indira o tipo de uma váriavel com base na sua inicialização, reduzindo verbosidade sem perder a segurança da tipagem estática 
- `decltype`: Extrai o tipo de uma expressão em tempo de compilação sem executá-la

### - Qualificadores de tipos (`const` e `validade`)

- `const`: Garante que o valor do objeto não pode ser alterado após a inicialização. No C++, a correção de const(`const correctness`) é uma boa pŕatica crucial para a segurança do código
- `validadte`: Informa ao compilador que o valor de uma variavel pode ser alterado por fatores externos ao programa, como hardware, impedindo otimizações indesejadas no registro da mémoria