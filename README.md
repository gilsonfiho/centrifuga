# ⚙️ Centrífuga Automatizada com Arduino

> Projeto desenvolvido na disciplina de **Tópicos Especiais em Computação II (Nanotecnologia)** da UFC, sob orientação do professor **Ricardo Pires**.

Este repositório apresenta uma centrífuga de bancada automatizada desenvolvida com baixo custo e baseada em Arduino. O projeto foi idealizado para fins didáticos e laboratoriais, possibilitando o controle preciso de tempo e rotação.

---

## 🎯 Objetivo

Criar uma centrífuga funcional utilizando componentes acessíveis, permitindo:

- Controle preciso da rotação.
- Configuração de tempo de centrifugação.
- Visualização de dados em tempo real.
- Baixo custo e fácil replicação por outros estudantes e laboratórios.

---

## 🧰 Componentes Utilizados

| Componente             | Finalidade                              |
|------------------------|------------------------------------------|
| Arduino Uno            | Controlador principal do sistema         |
| Motor DC com driver    | Geração da rotação do rotor              |
| Sensor Hall / Encoder  | Monitoramento da rotação do motor        |
| Display LCD 16x2       | Interface visual com o usuário           |
| Botões (push-buttons)  | Navegação no menu e controle de entrada  |
| Fonte de 12V           | Alimentação de motor e circuito          |
| Estrutura física       | Base impressa em 3D ou adaptada manualmente |

---

## ✨ Funcionalidades

- [x] Controle de velocidade via sinal PWM
- [x] Monitoramento da rotação com feedback no LCD
- [x] Timer configurável para controle de tempo
- [x] Interface amigável com botões e display LCD
- [x] Parada automática ao fim do tempo programado
- [x] Sistema seguro com desligamento automático em caso de falha

---

## ▶️ Como Utilizar

1. **Monte o circuito físico** com base no esquema proposto (em breve no repositório).
2. **Faça upload** do código `Codigo_Centrifuga.ino` para a placa Arduino Uno.
3. **Ligue a fonte de alimentação** (12V) ao circuito.
4. Utilize os **botões** para configurar a rotação e tempo de centrifugação.
5. Pressione o botão de início e acompanhe os dados no **display LCD**.
6. O sistema irá **parar automaticamente** após o tempo definido.

---

## 📸 Imagens do Projeto (em breve)

> Aqui você pode adicionar fotos ou vídeos demonstrando o protótipo real.
>
> **Sugestão:**
> ```
> ![Protótipo da centrífuga](imagens/prototipo.jpg)
> ```

---

## 👨‍💻 Contribuidores

- [Gilson Filho](https://github.com/gilsonfiho) — Desenvolvimento do sistema, código e documentação
- José Wilson — Integração com hardware, testes e estrutura física

---

## 📜 Licença

Este projeto está licenciado sob os termos da **Licença MIT**.  
Consulte o arquivo [LICENSE](LICENSE) para mais detalhes.

---

## ☕ Agradecimentos

Agradecemos ao professor **Ricardo Pires** pela orientação, e à turma da disciplina de Nanotecnologia pelas discussões e feedbacks valiosos.

---

**Curtiu o projeto?** Dê uma ⭐ aqui no repositório para apoiar nosso trabalho!