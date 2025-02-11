🛠️ Projeto: Controle de Servomotor por PWM com RP2040

🐖 Sumário

🎯 Objetivos

👌 Descrição do Projeto

⚙️ Funcionalidades Implementadas

🛠️ Requisitos do Projeto

💂️ Estrutura do Repositório

🖥️ Como Compilar

🤝 Contribuições

🎦 Demonstração em Vídeo

💡 Considerações Finais

---

🎯 Objetivos

- Compreender o funcionamento do módulo PWM no microcontrolador RP2040.
- Aplicar conceitos de controle de servomotor por modulação por largura de pulso (PWM).
- Implementar uma rotina de movimentação periódica do servomotor.
- Explorar o uso da ferramenta educacional BitDogLab para experimentação com LEDs.

---

👌 Descrição do Projeto

Este projeto utiliza o **Raspberry Pi Pico W** para controlar um **servomotor** através de **PWM** no simulador de eletrônica online **Wokwi**. Os principais componentes simulados são:

- **Raspberry Pi Pico W**
- **Servomotor – motor micro servo padrão (Wokwi)**
- **LED RGB (GPIO 12) para experimentação no BitDogLab**

A configuração sugerida segue o esquema ilustrado na Figura 1 do enunciado da tarefa.

---

⚙️ Funcionalidades Implementadas

1. **Configuração da GPIO 22** para gerar PWM com frequência de **50Hz (período de 20ms)**.
2. **Definição do ciclo ativo do PWM** para diferentes posições do servomotor:
   - **2.400µs (0,12%)** – Ajusta para **180°**, aguardando 5s.
   - **1.470µs (0,0735%)** – Ajusta para **90°**, aguardando 5s.
   - **500µs (0,025%)** – Ajusta para **0°**, aguardando 5s.
3. **Movimentação contínua** da flange do servomotor entre **0° e 180°** de forma suave, com incrementos de **±5µs** e atraso de **10ms** por passo.
4. **Experimento com LED RGB (GPIO 12)** na ferramenta BitDogLab para observar o comportamento da iluminação durante a execução do código.

---

🛠️ Requisitos do Projeto

- **Ambiente de Desenvolvimento:** VS Code integrado ao simulador Wokwi.
- **Linguagem de Programação:** C, utilizando o **Pico SDK**.
- **Versionamento e Submissão:** Código disponível no GitHub.
- **Testes:** Implementação de testes básicos para validar funcionalidades.
- **Documentação:** Adição de README.md com instruções detalhadas.
- **Demonstração:** Produção de um vídeo apresentando a solução implementada.

---

💂️ Estrutura do Repositório

```
├── controle_pwm.c       # Código principal do projeto
├── README.md            # Este arquivo
├── pwm_config.h         # Configurações do PWM
├── pwm_control.c        # Implementação das funções PWM
├── pwm_control.h        # Cabeçalho com declarações de funções
└── ...                  # Demais arquivos necessários
```

---

🖥️ Como Compilar

1. Clone o repositório:
   ```sh
   https://github.com/zrcrd/Tarefa-ServomotorPWM.git
   ```
2. Acesse a pasta do projeto:
   ```sh
   cd seu-repositorio
   ```
3. Compile o projeto com o ambiente de desenvolvimento configurado para RP2040.
4. Carregue o código na placa Raspberry Pi Pico W ou simule no Wokwi.

### 🖥️ Método Alternativo:

1. Baixe o repositório como um arquivo ZIP.
2. Extraia o conteúdo para uma pasta acessível.
3. Importe o projeto no VS Code com a extensão Raspberry Pi Pico.
4. Compile o código e envie para o RP2040 em **modo boot select**.
5. Teste o funcionamento interagindo com o servomotor.

---

🧑‍💻 Autor

**José Ricardo de Souza Santos**

---

📝 Descrição

Este projeto foi desenvolvido como parte da **Tarefa Individual – Unidade 4 | Capítulo 7 – C7O123E** do curso, ministrado pelo **Prof. Dr. Ricardo Menezes Prates**. O objetivo é demonstrar o uso do **PWM** para controle de servomotores e experimentação com LEDs.

---

🤝 Contribuições

Contribuições são bem-vindas! Para contribuir, siga os passos abaixo:

1. Faça um **fork** do repositório.
2. Crie uma nova branch:
   ```sh
   git checkout -b minha-feature
   ```
3. Realize suas alterações e faça um commit:
   ```sh
   git commit -m 'Adicionando nova funcionalidade'
   ```
4. Envie suas alterações:
   ```sh
   git push origin minha-feature
   ```
5. Abra um **Pull Request**.

---

🎦 Demonstração em Vídeo

O vídeo de demonstração do projeto pode ser acessado pelo link:


---

💡 Considerações Finais

Este projeto proporciona um excelente aprendizado sobre **PWM no RP2040**, controle de **servomotores**, experimentação com **LEDs** e a importância da **documentação e versionamento** de código.

Se tiver dúvidas ou sugestões, sinta-se à vontade para contribuir!

---

