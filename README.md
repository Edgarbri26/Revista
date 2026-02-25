# Revista Digital / Digital Magazine

Bienvenido a la **Revista Digital**, una aplicación interactiva de escritorio desarrollada en C utilizando la API de Windows (Win32). Este proyecto ofrece una experiencia de lectura bilingüe (Español e Inglés) con artículos de interés y herramientas integradas como juegos y utilidades.

Welcome to the **Digital Magazine**, an interactive desktop application developed in C using the Windows API (Win32). This project offers a bilingual reading experience (Spanish and English) with interesting articles and integrated tools like games and utilities.

## 📋 Características / Features

- **Contenido Bilingüe / Bilingual Content**:
  - Cambia fácilmente entre Español e Inglés.
  - Easily switch between Spanish and English.
- **Artículos Variados / Varied Articles**:
  - Matemáticas / Mathematics
  - Científico / Scientific
  - Opinión / Opinion
  - Reportaje / Reportage
- **Herramientas Interactivas / Interactive Tools**:
  - **Calculadora / Calculator**: Una utilidad integrada para cálculos rápidos. / An integrated utility for quick calculations.
  - **Juego del Ahorcado / Hangman Game**: Un divertido juego para desafiar tu vocabulario. / A fun game to challenge your vocabulary.
- **Multimedia**:
  - Música de fondo / Background music (`MUSICA/elevador .wav`).
  - Enlaces a contenido externo (YouTube videos).

## 🚀 Requisitos / Requirements

- **Sistema Operativo / Operating System**: Windows (Windows 2000 o superior / Windows 2000 or higher).
- **Compilador / Compiler**: MinGW o cualquier compilador de C compatible con Windows API.
- **IDE Recomendado / Recommended IDE**: Code::Blocks (Archivos de proyecto `.cbp` incluidos).

## 🛠️ Instalación y Ejecución / Installation and Execution

1. **Clonar o Descargar / Clone or Download**:
   Descarga el código fuente en tu equipo. / Download the source code to your computer.

2. **Compilar / Compile**:
   - Abre el archivo `ProResvista.cbp` en Code::Blocks.
   - Compila y corre el proyecto (`Build and Run`).
   - *Nota*: Asegúrate de compilar también las herramientas auxiliares si es necesario:
     - `Ahorcado/Ahorcado.cbp` para el juego.
     - `calculator/calculadora.c` para la calculadora.

3. **Estructura de Carpetas / Folder Structure**:
   Asegúrate de mantener la estructura de carpetas para que la aplicación encuentre los recursos (imágenes, sonidos, etc.).
   Ensure you maintain the folder structure so the application can find resources (images, sounds, etc.).

   - `img/`, `img_ingles/`: Imágenes de los artículos e interfaz.
   - `MUSICA/`: Archivos de audio.
   - `Ahorcado/`: Código y ejecutable del juego.
   - `calculator/`: Código y ejecutable de la calculadora.
   - `idioma.txt`: Archivo de configuración del idioma.

## 🎮 Controles / Controls

- Usa el ratón para navegar por el menú y leer los artículos. / Use the mouse to navigate the menu and read articles.
- Botones de navegación para cambiar de página o artículo. / Navigation buttons to change pages or articles.
- Accede a las herramientas (Calculadora, Juego) desde el menú principal. / Access tools (Calculator, Game) from the main menu.

## 👥 Créditos / Credits

Este proyecto incluye enlaces a contenido de video de los siguientes colaboradores:
This project includes links to video content from the following collaborators:

- Samuel
- Edgar
- Sara
- Karla
- Keyler
- Humbert
- Willi
- Santi

---
*Desarrollado con / Developed with C & Win32 API.*
