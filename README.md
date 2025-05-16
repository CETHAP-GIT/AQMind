# 💧 AQMind – Inteligência que economiza cada gota.

**Tecnologia de monitoramento hídrico inteligente para uso doméstico, agrícola e pecuário.**

---

## 📌 Visão Geral

O **AQMind** é um dispositivo individual baseado em ESP32 que mede o **nível** e o **consumo de água** em tempo real. Ideal para residências, hortas, plantações e criações animais, o AQMind auxilia no uso consciente da água e no combate ao desperdício por meio de dados precisos, alertas e recomendações inteligentes.

---

## 🔧 Tecnologias Utilizadas (Stack)

### ⚙️ Sistema Embarcado
- ESP32 com Wi-Fi integrado
- Linguagem: C++ (Arduino Framework)
- Comunicação: HTTP para envio de dados ao backend

**Sensores Utilizados:**
- Sensor ultrassônico (nível de água)
- Sensor de fluxo (volume consumido)

---

### 🌐 Web Platform

#### Frontend (Interface Web/App)
- [React.js](https://reactjs.org/) (Vite)
- [Tailwind CSS](https://tailwindcss.com/) para estilização moderna
- [Recharts](https://recharts.org/en-US) para gráficos de consumo
- [Axios](https://axios-http.com/) para comunicação com a API
- PWA: uso como aplicativo em dispositivos móveis

#### Backend (API)
- [Node.js](https://nodejs.org/) + [Express](https://expressjs.com/)
- [TypeScript](https://www.typescriptlang.org/) (opcional)
- [MongoDB](https://www.mongodb.com/) com [Mongoose](https://mongoosejs.com/)
- Autenticação JWT
- Endpoints RESTful para gerenciamento de dispositivos, dados e usuários

#### Hospedagem / Deploy
- Frontend: [Vercel](https://vercel.com)
- Backend: [Render](https://render.com)
- Banco de dados: [MongoDB Atlas](https://www.mongodb.com/atlas)

---

## 🧪 Funcionalidades

### Dispositivo IoT
- Medição contínua do nível de água em caixas/reservatórios
- Monitoramento do consumo de água (litros por minuto)
- Envio de dados via HTTP
- Alertas por LED/buzzer em caso de consumo excessivo ou nível crítico

### Plataforma Web
- Dashboard com:
  - Volume total consumido por período
  - Nível atual do reservatório
  - Gráficos de consumo diário/semanal/mensal
- Alertas inteligentes e personalizados
- Sugestões práticas para reduzir desperdícios
- Cadastro de dispositivo com definição do **tipo de uso**:
  - Uso pessoal (banho, cozinha, higiene)
  - Uso agrícola (hortas, plantações)
  - Uso pecuário (consumo animal, limpeza de bebedouros)
- Relatórios e históricos de uso

---

## 🌱 Sustentabilidade e Educação

- Promove o uso consciente da água
- Reduz o desperdício em residências e áreas produtivas
- Ajuda famílias e produtores a economizar recursos
- Estimula a responsabilidade ambiental

---

## 🚀 Como Executar Localmente

### Backend
```bash
cd backend
npm install
npm run dev
```

### Frontend
```bash
cd frontend
npm install
npm run dev
```

---

## 🛡️ Segurança

- Autenticação segura via JWT
- Proteção de dados do usuário e dispositivo
- Controle de acesso por perfil

---

## 📘 Licença

Este projeto é aberto para fins educacionais, sociais e ambientais. Para fins comerciais, entre em contato com a equipe CETHAP.

---

## 📞 Contato

Para dúvidas, colaborações ou apoio ao projeto:

- E-mail: cethap.cont@gmail.com  
- Instagram: [@cethap.tech](https://instagram.com/_cethap)  
- Site oficial: https://cethap.onrender.com/

---
