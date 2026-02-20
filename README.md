# 🔵🔴 Ligue 4 - Programação Imperativa (UFS)

Este projeto é uma versão digital do jogo **Ligue 4**, desenvolvida em linguagem C para a disciplina de Programação Imperativa (Turma T03).

## 📋 Sobre o Jogo
O objetivo é alinhar quatro fichas na horizontal, vertical ou diagonal em um tabuleiro de 6x7. Se o tabuleiro lotar sem vencedores, ocorre um empate.

## 👥 Equipe

Projeto desenvolvido pelos discentes de Sistemas de Informação da Universidade Federal de Sergipe (UFS):

* **Eduardo Moreira de Miranda**
* **Larissa Cena dos Santos**
* **Leonardo Quintela Correia Lima**

---
## 🚀 Funcionalidades
* **Humano vs. Humano**: Dois jogadores locais.
* **Humano vs. Computador**: Contra a IA.
* **Computador vs. Computador**: Simulação automática com pausa para visualização.

### 🧠 Níveis de IA
1. **Baixa**: Jogadas aleatórias[cite: 34].
2. **Média**: Bloqueia vitórias imediatas do oponente.
3. **Alta**: Joga de forma estratégica e ofensiva.

## 🛠️ Organização do Código
O projeto utiliza **Programação Estruturada** dividida em módulos:
* `jogo.c`: Fluxo principal e menus.
* `interface.c`: Impressão do tabuleiro e mensagens visuais.
* `logica.c`: Regras, validações e detecção de vitória.
* `ia.c`: Lógicas de inteligência artificial.
* `include/funcoes.h`: Cabeçalhos e protótipos.



## ⚙️ Como Compilar e Executar

Siga estritamente a ordem dos comandos abaixo no seu terminal (dentro da pasta do projeto) para garantir que todos os módulos sejam vinculados corretamente:

### 1️⃣ Compilação
Este comando une o arquivo principal, a interface, a lógica e a inteligência artificial em um único executável:

```bash
gcc jogo.c interface.c logica.c ia.c -o teste.exe
```
### 2️⃣ Execução
Após a compilação ser concluída sem erros, utilize o comando abaixo para iniciar o jogo:
```bash
./teste
```
