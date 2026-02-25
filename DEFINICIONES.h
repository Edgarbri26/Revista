#ifndef DEFINICIONES_H_INCLUDED
#define DEFINICIONES_H_INCLUDED

void probar(){
    MessageBox(NULL,"FUNCIONA","MENSAGE",MB_ICONINFORMATION | MB_OK);
}

#define LINEAS 50

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ruta musica

#define MUSICA "MUSICA\\elevador .wav"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//variables externas

extern int idio = 0;// idioma

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//RUTA PARA ABRIRI CON EL SHELL

const char *RUTA_CREDITOS[] = {"https://youtu.be/c0jsZw-lSAg?si=vjDechk11ZnDZ7nH","https://youtu.be/EaFux-PeXVI?si=X4lRKUzkXaQ8ixwy"};
const char *RUTA_CALCULADORA[] = {"calculator\\calculadora.exe","calculator\\calculadora_inglés.exe"};
#define RUTA_JUEGO "Ahorcado\\bin\\Debug\\Ahorcado.exe"

 // links de los videos
#define LINKS_SAMUEL "https://www.youtube.com/watch?v=wMW2xnkXeCw"
#define LINKS_EDGAR "https://www.youtube.com/watch?v=cuzp1RvjjVU"
#define LINKS_SARA "https://youtube.com/shorts/N6OAxBk9a6k?si=zGwbrRNLQzl8dw9Y"
#define LINKS_KARLA "https://youtube.com/shorts/aj9Da_yFhNQ?si=BDVJSYjkvEmHu7Yq"
#define LINKS_KEYLER "https://youtube.com/shorts/AFkFWhqTZh0?si=4cAAii5ku45-mZsp"
#define LINKS_HUMBERT "https://youtube.com/shorts/YjwdgSVznTo?si=JGEG7levDd5pQRF2"
#define LINKS_WILLI "https://youtube.com/shorts/DpeNIZPcQYg?si=grkmb-ImnhqOQR3P"
const char *LINKS_SANTI [] = {"https://youtu.be/LkTF_B1HFwE?si=tJIbGPDxDcvMIp2c","https://www.youtube.com/watch?si=ZeE4cpFKAyQLndLE&v=EOtQIodnlP0&feature=youtu.be"};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//RUTAS ICONOS
#define RUTA_ICO_BARRA "./img/icono/iujo.ico"
#define RUTA_ICO_VENT "./img/icono/icoVent.ico"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//NOMBRE DE LAS VENTANAS

const char *nombVentana[] = {"Revista", "Magazine"};
const char *Ayuda[] = {"Ayuda del sistema", "System help"};
const char *nombre[] = {"Juego", "Game"};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//RUTA A IMAGENES DE LA REVISTA

const char *IMAGE_PORTADA[] = {"./img/portada.bmp", "./img_ingles/portada_i.bmp"};
const char *IMG_EDITORIAL[] = {"./img/editorial.bmp", "./img_ingles/editorial_i.bmp"};
const char *IMG_AYUDA1[] = {"./img/Ayudasist/ayuda1.bmp", "./img_ingles/helpsist/help1.bmp"};
const char *IMG_AYUDA2[] = {"./img/Ayudasist/ayuda2.bmp", "./img_ingles/helpsist/help2.bmp"};

const char *ART_CIENT[4][2] = {// IMAGENES DEL ARTICULO CIENTIFICO
    {"./img/cientifico/CIENT_1.bmp", "./img_ingles/cientifico/CIENT_1i.bmp"},
    {"./img/cientifico/CIENT_2.bmp", "./img_ingles/cientifico/CIENT_2i.bmp"},
    {"./img/cientifico/CIENT_3.bmp", "./img_ingles/cientifico/CIENT_3i.bmp"},
    {"./img/cientifico/CIENT_4.bmp", "./img_ingles/cientifico/CIENT_4i.bmp"}
};

const char *ART_OPI1[2][2] = {//IMAGENES DEL ARTICULO DE OPINION1
    {"./img/opinion1/OPIN1_1.bmp", "./img_ingles/opinion1/OPIN1_1i.bmp"},
    {"./img/opinion1/OPIN1_2.bmp", "./img_ingles/opinion1/OPIN1_2i.bmp"}
};

const char *ART_OPI2[2][2] = {//IMAGENES DEL ARTICULO DE OPINION2
    {"./img/opinion2/OPIN2_1.bmp", "./img_ingles/opinion2/OPIN2_1i.bmp"},
    {"./img/opinion2/OPIN2_2.bmp", "./img_ingles/opinion2/OPIN2_2i.bmp"}
};

const char *ART_REPORTAJ[2][2] = { //IMAGENES DEL ARTICULO DE REPORTE
    {"./img/reportaje/REPORTJ_1.bmp", "./img_ingles/reportaje/REPORTJ_1i.bmp"},
    {"./img/reportaje/REPORTJ_2.bmp", "./img_ingles/reportaje/REPORTJ_2i.bmp"}
};

const char *ART_TDI[4][2] = { // ARTICULO DE TECNICAS
    {"./img/tdi/TDI_1.bmp", "./img_ingles/tdi/TDI_1i.bmp"},
    {"./img/tdi/TDI_2.bmp", "./img_ingles/tdi/TDI_2i.bmp"},
    {"./img/tdi/TDI_3.bmp", "./img_ingles/tdi/TDI_3i.bmp"},
    {"./img/tdi/TDI_4.bmp", "./img_ingles/tdi/TDI_4i.bmp"}
};


const char *ART_MAT[5][2] = {
    {"./img/Articulos matematicas/MAT_1.bmp", "./img_ingles/Matematicas/MAT_1i.bmp"},
    {"./img/Articulos matematicas/MAT_2.bmp", "./img_ingles/Matematicas/MAT_2i.bmp"},
    {"./img/Articulos matematicas/MAT_3.bmp", "./img_ingles/Matematicas/MAT_3i.bmp"},
    {"./img/Articulos matematicas/MAT_4.bmp", "./img_ingles/Matematicas/MAT_4i.bmp"},
    {"./img/Articulos matematicas/MAT_5.bmp", "./img_ingles/Matematicas/MAT_5i.bmp"}
};

const char *IMG_REPORTE[5][2] = {
    {"./img/reporte/reporte_1.bmp", "./img_ingles/reporte/reporte_1i.bmp"},
    {"./img/reporte/reporte_2.bmp", "./img_ingles/reporte/reporte_2i.bmp"},
    {"./img/reporte/reporte_3.bmp", "./img_ingles/reporte/reporte_3i.bmp"},
    {"./img/reporte/reporte_4.bmp", "./img_ingles/reporte/reporte_4i.bmp"},
    {"./img/reporte/reporte_5.bmp", "./img_ingles/reporte/reporte_5i.bmp"}
};




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//NOMBRE DE BOTONES


 //nombre botones del menu
    const char *portada[] = {"Portada","Cover"};
    const char *indice[] = {"Indice:","Index:"};
    const char *creditos[] = {"Creditos","Credits"};
    const char *salir[] = {"Salir","Exit"};
    const char *ayuda[] = {"Ayuda","Help"};
    const char *instruc[] = {"Instruciones","Instructions"};
    const char *idiona[] = {"Idioma","Lenguaje"};
    const char *indiceStatic[] = {"Indice:","Index:"};

    //nombre botones del indice
    //const char *Editorial[] = {"Editorial","Editorial"};
    const char *Articulos[] = {"Articulos","Articles"};
    const char *Reporte[] = {"Reporte","Report"};
    const char *Juego[] = {"Juego","Game"};
    const char *Volver[] = {"Volver","Back"};

    const char *unAula[] = {"Un Aula","A classrom"};


 //nombre de BTN de los articulos


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ID DE LOS BOTONES


//BOTONES 100 A 149 // BOTONES VENTANA MENU
//#define BTN_SPN 101
#define BTN_EDITORIAL 102
#define BTN_PORTADA 103
#define BTN_INDICE 104
#define BTN_SALIR 105
#define BTN_OCULTAR 106
#define BTN_PGN1 107
#define BTN_PGN2 108
#define BTN_INDICE_CALCU 109


//BOTONES INDICE del 150 a 200
#define BTN_VOLVER 150
#define BTN_INDICE_EDITORIAL 151
#define BTN_INDICE_ARTICULOS 152
#define BTN_INDICE_REPORTE 153
#define BTN_INDICE_JUEGO 154


//#define BTN_INDICE_VOLVER 155
#define BTN_ARTICULO_ART1 156
#define BTN_ART_CIENT 157
#define BTN_ART_OPI1 158
#define BTN_ART_OPI2 159
#define BTN_ART_REPOT 160
#define BTN_ART_TDI 161
#define BTN_ART_MAT 162


//MENUS DE LA VENTANA PRINCIPAL // menus del 201 a 220
#define MN_AYUDA_INTRUCCIONES 202
#define MN_AYUDA_TIPS 203
#define MN_IDIOMA_ESP 204
#define MN_IDIOMA_ING 205
#define MN_CREDITOS 206

//SUB MENU LINKS
#define MN_LINKS_SAMUEL 207
#define MN_LINKS_EDGAR 208
#define MN_LINKS_SANTI 209
#define MN_LINKS_SARA 210
#define MN_LINKS_KARLA 211
#define MN_LINKS_KEYLER 212
#define MN_LINKS_HUMBERT 213
#define MN_LINKS_WILLI 214


//BOTONES DE NAVEGACION 250 300
#define BTN_ATRAS 250
#define BTN_SIGUIENTE 251

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//BOTONES DEL JUEGO 300 350
#define BTN_SALIR_JUEGO 301
#define BTN_VOLVER_JUEGO 302
#define BTN_LISTO_JUEGO 303
#define BTN_REGLAS_JUEGO 304
#define BTN_MUL_JUEGO 305
#define BTN_INICIAR_JUEGO 306


//NOMBRE DE BOTONES DEL JUEGO
const char *reglas_juego[] = {"Reglas", "Rules"};
const char *iniciar_juego[] = {"Iniciar juego", "Start game"};
const char *multijugador_juego[] = {"Multijugador", "Multiplayer"};
const char *salir_juego[] = {"Salir del juego", "Exit the game"};
const char *mensaje_juego[] = {"Los servidores del multijuagor todavia están en desarrollo. Por favor, espere hasta la próxima actualización", "Multiplayer servers are still in under development. Please wait until the next update"};
const char *aviso_juego[] = {"Advertencia", "Warning"};
const char *listo_juego[] = {"Listo para jugar", "Ready to play"};
const char *volver_juego[] = {"Volver a jugar", "Replay"};


//Imagenes del juego del juego
/*#define IMAGE_0 "C:/revista/Ahorcado/AhorcadoFinal - bmp/Ahorcado7.bmp"
#define IMG_1   "C:/revista/Ahorcado/AhorcadoFinal - bmp/Ahorcado6.bmp"
#define IMG_2 "C:/revista/Ahorcado/AhorcadoFinal - bmp/Ahorcado5.bmp"
#define IMG_3 "C:/revista/Ahorcado/AhorcadoFinal - bmp/Ahorcado4.bmp"
#define IMG_4 "C:/revista/Ahorcado/AhorcadoFinal - bmp/Ahorcado3.bmp"
#define IMG_5 "C:/revista/Ahorcado/AhorcadoFinal - bmp/Ahorcado2.bmp"
#define IMG_6 "C:/revista/Ahorcado/AhorcadoFinal - bmp/Ahorcado1.bmp"
#define IMG_6_1 "C:/revista/Ahorcado/AhorcadoFinal - bmp/Ahorcado1.01.bmp"

const char *IMG_7[] = {"C:/revista/Ahorcado/AhorcadoFinal - bmp/termino.bmp", "C:/revista/Ahorcado/AhorcadoFinal - bmp/gameover.bmp"};
const char *IMG_GANO[] = {"C:/revista/Ahorcado/AhorcadoFinal - bmp/ganaste.bmp", "C:/revista/Ahorcado/AhorcadoFinal - bmp/youwon.bmp"};
const char *IMG_REGLAS[] = {"C:/revista/Ahorcado/AhorcadoFinal - bmp/reglas.bmp", "C:/revista/Ahorcado/AhorcadoFinal - bmp/rules.bmp"};
const char *IMG_TITULO[] = {"C:/revista/Ahorcado/AhorcadoFinal - bmp/titulo.bmp", "C:/revista/Ahorcado/AhorcadoFinal - bmp/title.bmp"};
#define IMG_BASE "C:/revista/Ahorcado/AhorcadoFinal - bmp/BASE.bmp"
#define IMG_L "C:/revista/Ahorcado/AhorcadoFinal - bmp/L.bmp"
#define IMG_O "C:/revista/Ahorcado/AhorcadoFinal - bmp/O.bmp"
#define IMG_G "C:/revista/Ahorcado/AhorcadoFinal - bmp/G.bmp"
#define IMG_A "C:/revista/Ahorcado/AhorcadoFinal - bmp/A.bmp"
#define IMG_R "C:/revista/Ahorcado/AhorcadoFinal - bmp/R.bmp"
#define IMG_I "C:/revista/Ahorcado/AhorcadoFinal - bmp/I.bmp"
#define IMG_T "C:/revista/Ahorcado/AhorcadoFinal - bmp/T.bmp"
#define IMG_M "C:/revista/Ahorcado/AhorcadoFinal - bmp/M.bmp"
#define IMG_H "C:/revista/Ahorcado/AhorcadoFinal - bmp/H.bmp"*/

//Imagenes del juego del juego
#define IMAGE_0 "Ahorcado\\AhorcadoFinal - bmp\\Ahorcado7.bmp"
#define IMG_1   "Ahorcado\\AhorcadoFinal - bmp\\Ahorcado6.bmp"
#define IMG_2 "Ahorcado\\AhorcadoFinal - bmp\\Ahorcado5.bmp"
#define IMG_3 "Ahorcado\\AhorcadoFinal - bmp\\Ahorcado4.bmp"
#define IMG_4 "Ahorcado\\AhorcadoFinal - bmp\\Ahorcado3.bmp"
#define IMG_5 "Ahorcado\\AhorcadoFinal - bmp\\Ahorcado2.bmp"
#define IMG_6 "Ahorcado\\AhorcadoFinal - bmp\\Ahorcado1.bmp"
#define IMG_6_1 "Ahorcado\\AhorcadoFinal - bmp\\Ahorcado1.01.bmp"

const char *IMG_7[] = {"Ahorcado\\AhorcadoFinal - bmp\\termino.bmp", "Ahorcado\\AhorcadoFinal - bmp\\gameover.bmp"};
const char *IMG_GANO[] = {"Ahorcado\\AhorcadoFinal - bmp\\ganaste.bmp", "Ahorcado\\AhorcadoFinal - bmp\\youwon.bmp"};
const char *IMG_REGLAS[] = {"Ahorcado\\AhorcadoFinal - bmp\\reglas.bmp", "Ahorcado\\AhorcadoFinal - bmp\\rules.bmp"};
const char *IMG_TITULO[] = {"Ahorcado\\AhorcadoFinal - bmp\\titulo.bmp", "Ahorcado\\AhorcadoFinal - bmp\\title.bmp"};
#define IMG_BASE "Ahorcado\\AhorcadoFinal - bmp\\BASE.bmp"
#define IMG_L "Ahorcado\\AhorcadoFinal - bmp\\L.bmp"
#define IMG_O "Ahorcado\\AhorcadoFinal - bmp\\O.bmp"
#define IMG_G "Ahorcado\\AhorcadoFinal - bmp\\G.bmp"
#define IMG_A "Ahorcado\\AhorcadoFinal - bmp\\A.bmp"
#define IMG_R "Ahorcado\\AhorcadoFinal - bmp\\R.bmp"
#define IMG_I "Ahorcado\\AhorcadoFinal - bmp\\I.bmp"
#define IMG_T "Ahorcado\\AhorcadoFinal - bmp\\T.bmp"
#define IMG_M "Ahorcado\\AhorcadoFinal - bmp\\M.bmp"
#define IMG_H "Ahorcado\\AhorcadoFinal - bmp\\H.bmp"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// registrar las clases
BOOL RegistrarClaseEx(UINT Estilo,HINSTANCE Instancia,LPCSTR NombreClase,LPCSTR NombreMenu,WNDPROC Procedimiento,HBRUSH Color){
    WNDCLASSEX cl;
    HICON hIconBarra = (HICON) LoadImage(NULL, "./img/icono/iujo.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    HICON hIconVent = (HICON) LoadImage(NULL, "./img/icono/icoVent.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    if(hIconVent == NULL || hIconBarra == NULL)
    {
        MessageBox(NULL,"NO SE PUDO CARGAR ICONO", "ERROR",MB_OKCANCEL | MB_ICONERROR);
    }

    cl.cbSize = sizeof(WNDCLASSEX);
    cl.cbClsExtra = 0;
    cl.cbWndExtra = 0;
    cl.style = Estilo;
    cl.hInstance = Instancia;
    cl.lpszClassName = NombreClase;
    cl.lpszMenuName = NombreMenu;
    cl.hIcon = hIconBarra;
    cl.hIconSm = hIconVent;
    cl.hCursor = LoadCursor(NULL,IDC_ARROW);
    cl.lpfnWndProc = Procedimiento;
    cl.hbrBackground = Color;

    if(!RegisterClassEx(&cl)){
        return FALSE;
    }
    return TRUE;
}

#endif // DEFINICIONES_H_INCLUDED
