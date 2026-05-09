# 08/05/2026 - Estrutura básica do código

abaixo ha um exemplo de cógio minimo em C++, para um Hello World

```cpp
#include <iostream>

int main() {
  std::cout << "Hello World" << std::endl;
  return 0;
}
```

## Componentes estruturais explicitos

1, Diretiva de pŕe-processamento

As linhas que começam com o caracter `#` não são instruções executadas pelo processador em tempo de execução, elas são processadas pelo pŕe-processador antes da compilação propiamente dita

- `#include <iostream>`: essa diretiva instrui o compilador a copiar e colar o conteudo da biblioteca padrão de IO, entrada e saida, nesse ponto do arquivo. Ela é necessária para que possamos ultilizar objetos de fluxo de dados como `std::cout`.

2. O ponto de entrada global ( `int main() `)

Diferente de linguagens de script, C++ requer um ponto de entrada padronizado

- `int`: Indica o tipo de retorno da função. Por padrão, a função `main` deve retornar um número inteiro ao sistema operacional para sinalizar o status de encerramento do programa
- `main()`: É a assinatura da função principal. Todo programa executável em C++ precisa ter exatamente a função `main`,  É por qnde a CPU começa a executar as instruções do seu software
- `{ ... }`: Delimitam o escopo de execução da função (o inicio e o fim do código pertence à `main`)

3. O fluxo de saida e o namespace (`std::cout`)

- `std::`: Refere-se ao Namespace (espaço de nomes) standard da biblioteca padrão do C++. Ele funciona como um prefixo para evitar conflitos por nomes(por exemplo, se você criar uma variavel com o nome `cout`, ela não colidirá com da biblioteca padrão)
- `cout`: Significa Character Output. É o objeto de fluxo de saída padrão
- `<<`: É o operador de insersão de fluxo. Ele direciona os dados à sua direita (a string`"Hello World"`) para o objeto a sua esquerda (`std::cout`)
- `std::endl`: É um manipulador de fluxo que insere um caracter de nova linha (`\n`) e, crucialmente, força o esvaziamento do buffer de saida (flush), garantindo que o texto apareca imediatamente na tela

4. O ponto e vírgula (`;`)

Em C++, o ponto e vírgula é um **terminador de instrução**. Ele indica ao compilador onde termina uma unidade lógica de execução. A ausência dele é um dos erros de sintaxe mais comuns durante a compilação

5. Código de retorno (`return 0`)

- Retornar `0` ao final da função `main` é uma convenção universal em sistemas operacionais (como Linux e Windows) para indicar que o programa foi executado com sucesso, sem erros
- Qualquer valor diferente de zero (como `1` ou `-1`) geralmente sinaliza que ocorreu alguma falha ou comportamento inesperado durante a execução
