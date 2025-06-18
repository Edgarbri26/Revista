#define _WIN32_WINNT 0x0500 // Definimos la versión de Windows a partir de la cual se puede utilizar el prograna (Windows 2000)
#include <Windows.h> // Biblioteca para interactuar con el sistema operativo Windows, la cual usamos para crear la interfaz grafica
#include <shellapi.h> // Biblioteca para interactuar con el shell de Windows, que usamos para abrir los links y los .exe del jugeo y la calcyuladora
#include <stdio.h> // Biblioteca para realizar operaciones de entrada y salida
#include <stdlib.h>
#include <string.h>

#include "DEFINICIONES.h" // Archivo de cabecera personalizado donde tenemos las rutas de todas las imagenes y definiciones de los botones

HINSTANCE Instancia; // Variable para almacenar la instancia de la aplicación
int idio; // Variable para almacenar el idioma seleccionado
int cont_pag_mate = 0; // Variable para saver en que pagina del articulo de matematicas se esta mostrando
int cont_pag_aul = 0; // Variable para saver en que pagina del articulo de aulas virtuales se esta mostrando
int cont_reporte = 0; // Variable para comprovar si el reporte esta activo
int selector_art = 0; // Variable para seleccionar el articulo actual
int cont_indice = 0; // Variable para comprovar si el indice esta activo
int cont_articulo = 0; // Variable para comprovar si el boton del los artuculos esta activo
int tamax, tamay;//para guardar el tamaño de la pantalla

 int yPosPrev,yPosActual,xPosActual; // posicion del scroll
 int bSize, bScroll;

int cont_pag = 0;


// handles de las ventanas
HWND hVentMenu, hAyuda, hImag, hScroll;
HMENU hmenuPrincipal;
HBITMAP bimag; // el manipulador de bitmap donde cargamos las imagenes
static HBITMAP bmInfo;
//incializaci�n de los handles de los botones
HWND btn_edi, btn_art, btn_repor, btn_juego, btn_calculadora, art1, art2, art3, art4, art5, art6, btn_atras, btn_siguiente;

//prototipo de los callback
LRESULT CALLBACK cProcediementoMenu(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK cScroll(HWND hwnd , UINT msg , WPARAM wParam, LPARAM lParam );
LRESULT CALLBACK cAyuda(HWND, UINT, WPARAM , LPARAM);

//prototipo de funciones
int cargar_Idioma ();
void guardar_idioma (int);
void crear_ventana_menu();//funciones par la creacion de la ventana en un idioma
void crear_ventana_ayuda(HWND hwnd);
void ocul_btn_articulos();
void cargar_imagen();
void crear_menu(HWND);
void destruir_btn_navegacion();
void crear_botones_navegacion ();
void botones_navegacion_siguiente();
void botones_navegacion_atras();

int tamanoMenuy;
int tamanoMenux;
int anchoAyuda;
int altoAyuda;

void crear_ventana_menu(){


    tamanoMenuy = tamay - 35;
    tamanoMenux = 900;
    int posicionx = ((tamax-tamanoMenux)/2);//para centrar la ventana

    hVentMenu = CreateWindow("IdentificadorMenu", nombVentana[idio], WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX | WS_VSCROLL ,
                          posicionx, 0,tamanoMenux , tamanoMenuy, NULL, NULL, NULL, NULL);


    ShowWindow(hVentMenu, SW_SHOW);
    UpdateWindow(hVentMenu);

}

void crear_ventana_ayuda(HWND hwnd){

    anchoAyuda = 1100;
    altoAyuda = tamay-40;
    hAyuda = CreateWindow("IdentificadorAyuda", Ayuda[idio], WS_SYSMENU ,
                             ((tamax-anchoAyuda)/2), 0, anchoAyuda , altoAyuda, NULL, NULL, NULL, NULL);

    if(hAyuda == NULL )
    {
        MessageBox(NULL,"NO SE PUDO CARGAR la ventana ayuda", "ERROR",MB_OKCANCEL | MB_ICONERROR);
    }

    ShowWindow(hAyuda, SW_SHOW);
    UpdateWindow(hAyuda);

}

int cargar_Idioma (){
    int idiom;
    FILE *idioma = fopen("idioma.txt","r");
    if (idioma != NULL){
        fscanf(idioma,"%d",&idiom);
        fclose(idioma);
    }else {
        MessageBox(NULL,"no se pudo abrir el archivo para cargar el idioma","ERROR",MB_ICONERROR | MB_OK);
    }

    return idiom;
}

void guardar_idioma (int idiom){
    FILE *idioma = fopen("idioma.txt","w");
    if (idioma != NULL){
        fprintf(idioma,"%d",idiom);
        fclose(idioma);
    }else {
        MessageBox(NULL,"no se pudo abrir el archivo para guardar el idioma","ERROR",MB_ICONERROR | MB_OK);
    }
}

void ocul_btn_articulos(){

    ShowWindow(art1,SW_HIDE);
    ShowWindow(art2,SW_HIDE);
    ShowWindow(art3,SW_HIDE);
    ShowWindow(art4,SW_HIDE);
    ShowWindow(art5,SW_HIDE);
    ShowWindow(art6,SW_HIDE);
}

void destruir_btn_navegacion (){
    //pasar_articulo
    ShowWindow(btn_atras,SW_HIDE);
    ShowWindow(btn_siguiente,SW_HIDE);
}

int cargar;
void cargar_imagen(){
    cargar = 1;
    RECT rect;
    GetClientRect(hScroll, &rect);
    InvalidateRect(hScroll, &rect,TRUE);
}

void crear_botones_navegacion (){
    //int posy = ((tamanoMenuy - 25)/2);
    btn_atras = CreateWindowEx(0,"BUTTON", "<", BS_CENTER  | BS_FLAT | WS_CHILD, 725, 390 , 40,20, hVentMenu, (HMENU)BTN_ATRAS, NULL, NULL);
    btn_siguiente = CreateWindowEx(0,"BUTTON", ">", BS_CENTER  | BS_FLAT | WS_CHILD, 725, 370, 40,20, hVentMenu, (HMENU)BTN_SIGUIENTE, NULL, NULL);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    SetConsoleOutputCP(65001);
    idio = cargar_Idioma ();
    tamax = GetSystemMetrics(SM_CXSCREEN);
    tamay = GetSystemMetrics(SM_CYSCREEN);
    Instancia = hInstance;

    if(!RegistrarClaseEx(CS_HREDRAW | CS_VREDRAW, hInstance, "IdentificadorAyuda", NULL,  cAyuda,CreateSolidBrush(RGB(215,210,205))))
       {
            MessageBox(NULL,"Error :\n\tNo se pudo cargar la clase ayuda","ERROR",MB_OK|MB_ICONERROR);
       }

    if(!RegistrarClaseEx(CS_HREDRAW | CS_VREDRAW, hInstance, "IdentificadorMenu", NULL,  cProcediementoMenu,CreateSolidBrush(RGB(171,205,239))))
       {
            MessageBox(NULL,"Error :\n\tNo se pudo cargar la clase principal","ERROR",MB_OK|MB_ICONERROR);
       }

 if(!RegistrarClaseEx(CS_HREDRAW | CS_VREDRAW, hInstance, "scrollClass", NULL,  cScroll, CreateSolidBrush(RGB(171,0,239))))
       {
            MessageBox(NULL,"Error :\n\tNo se pudo cargar la clase del scroll","ERROR",MB_OK|MB_ICONERROR);
       }


    ShowWindow(GetConsoleWindow(), SW_HIDE);

    crear_ventana_menu();

    MSG mensage;
    while (GetMessage(&mensage, NULL, 0, 0)) {
        TranslateMessage(&mensage);
        DispatchMessage(&mensage);
    }

    guardar_idioma (idio);
    return 0;
}


LRESULT CALLBACK cProcediementoMenu(HWND hwnd, UINT mensage, WPARAM wParam, LPARAM lParam){
    SCROLLINFO si;
    static int cxCliente,cyCliente;



    switch(mensage)
    {
        case WM_ACTIVATE:
            {
                if (wParam == WA_ACTIVE)
                {
                    PlaySound(MUSICA, NULL, SND_LOOP | SND_ASYNC);
                }
                else if(wParam == WA_INACTIVE)
                    PlaySound(NULL , NULL, SND_PURGE);
            }
            break;

        case WM_CREATE:
        {
            bimag = (HBITMAP) LoadImageA(NULL, IMAGE_PORTADA[idio], IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            GetObject(bimag,sizeof(BITMAP),&bmInfo); // obtenemos informacion del bitmap

            yPosActual = 0;
            xPosActual = 0;

            bSize = 0;
            bScroll = 0;

            crear_menu(hwnd); // se crea el menu de la parte superior

            int posx = cxCliente - 90;

             hScroll = CreateWindow("scrollClass", "", WS_VISIBLE | WS_CHILD , 0, 0, 720, 1019,
                                           hwnd, NULL, Instancia, NULL);
            if(!hScroll)
                MessageBox(NULL,"Error :\n\tNo se pudo crear la ventana scroll","ERROR",MB_OK|MB_ICONERROR);

            //botones del menu
            CreateWindowEx(0, "BUTTON", portada[idio], BS_CENTER | BS_FLAT | WS_VISIBLE | WS_CHILD, posx , 70, 80, 25, hwnd, (HMENU)BTN_PORTADA, NULL, NULL);
            CreateWindowEx(0, "BUTTON", indice[idio], BS_CENTER | BS_FLAT | WS_VISIBLE| BS_DEFPUSHBUTTON | BS_PATTERN | WS_CHILD, posx, 100, 80, 25, hwnd, (HMENU)BTN_INDICE, NULL, NULL);
            CreateWindowEx(0, "BUTTON", salir[idio], BS_CENTER  | BS_FLAT |  WS_VISIBLE | WS_CHILD, posx, (cyCliente - 35), 80, 25, hwnd, (HMENU)BTN_SALIR, NULL, NULL);

            //Botones del indice
            btn_edi =  CreateWindowEx(0, "BUTTON", "Editorial", BS_CENTER | BS_FLAT | WS_CHILD, posx, 130, 80, 25, hwnd, (HMENU)BTN_EDITORIAL, NULL, NULL);
            btn_art =  CreateWindowEx(0, "BUTTON", Articulos[idio], BS_CENTER | BS_FLAT | BS_DEFPUSHBUTTON | BS_PATTERN | WS_CHILD, posx, 160, 80, 25, hwnd, (HMENU)BTN_INDICE_ARTICULOS, NULL, NULL);
            btn_repor =  CreateWindowEx(0, "BUTTON", Reporte[idio]  , BS_CENTER | BS_FLAT | WS_CHILD, posx, 190, 80, 25, hwnd, (HMENU)BTN_INDICE_REPORTE, NULL, NULL);
            btn_juego =  CreateWindowEx(0, "BUTTON", Juego[idio]    , BS_CENTER | BS_FLAT | WS_CHILD, posx, 220, 80, 25, hwnd, (HMENU)BTN_INDICE_JUEGO, NULL, NULL);
            btn_calculadora =  CreateWindowEx(0, "BUTTON", "Calcul"  , BS_CENTER | BS_FLAT | WS_CHILD, posx, 250, 80, 25, hwnd, (HMENU)BTN_INDICE_CALCU, NULL, NULL);

            //botones del art�culo
            art1 =  CreateWindowEx(0, "BUTTON", "CIENT", BS_CENTER | BS_FLAT | WS_CHILD, posx, 190, 80, 25, hwnd, (HMENU)BTN_ART_CIENT, NULL, NULL);
            art2 =  CreateWindowEx(0, "BUTTON", "OPI1", BS_CENTER | BS_FLAT | WS_CHILD, posx, 220, 80, 25, hwnd, (HMENU)BTN_ART_OPI1, NULL, NULL);
            art3 =  CreateWindowEx(0, "BUTTON", unAula[idio], BS_CENTER | BS_FLAT | WS_CHILD, posx, 250, 80, 25, hwnd, (HMENU)BTN_ART_OPI2, NULL, NULL);
            art4 =  CreateWindowEx(0, "BUTTON", "REPRT", BS_CENTER | BS_FLAT | WS_CHILD, posx, 280, 80, 25, hwnd, (HMENU)BTN_ART_REPOT, NULL, NULL);
            art5 =  CreateWindowEx(0, "BUTTON", "TDI", BS_CENTER | BS_FLAT | WS_CHILD, posx, 310, 80, 25, hwnd, (HMENU)BTN_ART_TDI, NULL, NULL);
            art6 =  CreateWindowEx(0, "BUTTON", "MAT", BS_CENTER | BS_FLAT | WS_CHILD, posx, 340, 80, 25, hwnd, (HMENU)BTN_ART_MAT, NULL, NULL);

        }
        break;

        case WM_SIZE:
            {
                cxCliente = LOWORD(lParam);
                cyCliente = HIWORD(lParam);

                si.cbSize = sizeof(SCROLLINFO);
                si.fMask = SIF_ALL ;
                si.nMin = 0; // EL PUNTO MAS ALTO
                si.nMax = 1019;//HAZTA DONDE SE PUEDE SCROLLEAR
                si.nPage = cyCliente;
                si.nPos = 0;
                SetScrollInfo(hwnd, SB_VERT, &si, TRUE);// SE GUARDA LA INFORMACION DE LA SCROLLBARD

                bSize = 1;
                InvalidateRect(hwnd,NULL,FALSE);///INVALIDAR TODA EL AREA CLIENTE
            }
            break;

        /*case WM_KEYDOWN:
            {
                switch(wParam)
                {
                case VK_LEFT:
                    {
                        MessageBox(NULL,"mover a la izquierda","mensaje", MB_OK);
                       botones_navegacion_atras();
                    }
                    break;


                case VK_RIGHT:
                    {
                        MessageBox(NULL,"mover a la derecha","mensaje", MB_OK);
                        botones_navegacion_siguiente();
                    }


                    break;
                }
            }
            break;*/

        case WM_COMMAND:
            {
                switch (LOWORD(wParam))
                {
                    case BTN_PORTADA:
                        {
                            bimag = (HBITMAP) LoadImageA(NULL, IMAGE_PORTADA[idio], IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                             cargar_imagen();
                             destruir_btn_navegacion();
                        }
                        break;

                    case BTN_EDITORIAL:
                        {
                             bimag = (HBITMAP) LoadImageA(NULL, IMG_EDITORIAL[idio] ,IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                             cargar_imagen();
                             ocul_btn_articulos();
                             destruir_btn_navegacion();
                        }
                        break;

                    case BTN_INDICE:
                            {
                                if (cont_indice  == 0)
                                    {
                                        ShowWindow(btn_edi, SW_SHOW);
                                        ShowWindow(btn_art, SW_SHOW);
                                        ShowWindow(btn_repor, SW_SHOW);
                                        ShowWindow(btn_juego, SW_SHOW);
                                        ShowWindow(btn_calculadora, SW_SHOW);
                                        cont_indice  = 1;
                                        crear_botones_navegacion();
                                    }
                                else
                                    { // se esconde todo y se vuelve a la portada
                                        ShowWindow(btn_edi, SW_HIDE);
                                        ShowWindow(btn_art, SW_HIDE);
                                        ShowWindow(btn_repor, SW_HIDE);
                                        ShowWindow(btn_juego, SW_HIDE);
                                        ShowWindow(btn_calculadora, SW_HIDE);
                                        destruir_btn_navegacion();
                                        bimag = (HBITMAP) LoadImageA(NULL, IMAGE_PORTADA[idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                        cargar_imagen();

                                        //destruir_btn_navegacion();
                                        ocul_btn_articulos();
                                        cont_indice  = 0;
                                    }
                            }
                            break;

                    case BTN_INDICE_ARTICULOS:
                        {
                            if(cont_articulo  == 0)
                                { // aqui se muestran todos los botones de los articulos
                                    ShowWindow(art1,SW_SHOW);
                                    ShowWindow(art2,SW_SHOW);
                                    ShowWindow(art3,SW_SHOW);
                                    ShowWindow(art4,SW_SHOW);
                                    ShowWindow(art5,SW_SHOW);
                                    ShowWindow(art6,SW_SHOW);
                                    ShowWindow(btn_repor,SW_HIDE);
                                    ShowWindow(btn_juego,SW_HIDE);
                                    ShowWindow(btn_edi, SW_HIDE);
                                    ShowWindow(btn_calculadora, SW_HIDE);
                                    crear_botones_navegacion();

                                    cont_articulo  = 1;
                                    break;
                                }
                            else if(cont_articulo == 1)
                                { // aqui se ocultan todos los botones de los articulos
                                    ShowWindow(btn_repor,SW_SHOW);
                                    ShowWindow(btn_juego,SW_SHOW);
                                    ShowWindow(btn_edi, SW_SHOW);
                                    ShowWindow(btn_calculadora, SW_SHOW);
                                    // aqui se carga la imagen de portada y de ocultan y destruyen botones relacionados a los articulos
                                    bimag = (HBITMAP) LoadImageA(NULL, IMAGE_PORTADA[idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                                    cargar_imagen();
                                    destruir_btn_navegacion();
                                    ocul_btn_articulos();
                                    cont_articulo = 0;
                                    break;
                                }
                        }
                        break;

                    case BTN_ART_CIENT:
                        {
                            cont_pag = 0;
                            selector_art = 1;

                            //botones de navegacion
                            ShowWindow(btn_atras,SW_HIDE);
                            ShowWindow(btn_siguiente,SW_SHOW);
                            bimag = (HBITMAP) LoadImageA(NULL, ART_CIENT[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            cargar_imagen();

                        }
                        break;

                    case BTN_ART_OPI1:
                        {
                            cont_pag = 0;
                            selector_art = 2;

                            //botones de navegacion
                            ShowWindow(btn_atras,SW_HIDE);
                            ShowWindow(btn_siguiente,SW_SHOW);
                            bimag = (HBITMAP) LoadImageA(NULL, ART_OPI1[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            cargar_imagen();

                        }
                        break;

                    case BTN_ART_OPI2:
                        {
                            cont_pag = 0;
                            selector_art = 3;

                            //botones de navegacion
                            ShowWindow(btn_atras,SW_HIDE);
                            ShowWindow(btn_siguiente,SW_SHOW);
                            bimag = (HBITMAP) LoadImageA(NULL, ART_OPI2[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            cargar_imagen();

                        }
                        break;

                    case BTN_ART_REPOT:
                        {
                            cont_pag = 0;
                            selector_art = 4;

                            //botones de navegacion
                            ShowWindow(btn_atras,SW_HIDE);
                            ShowWindow(btn_siguiente,SW_SHOW);
                            bimag = (HBITMAP) LoadImageA(NULL, ART_REPORTAJ[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            cargar_imagen();

                        }
                        break;

                    case BTN_ART_TDI:
                        {
                            cont_pag = 0;
                            selector_art = 5;

                            //botones de navegacion
                            ShowWindow(btn_atras,SW_HIDE);
                            ShowWindow(btn_siguiente,SW_SHOW);
                            bimag = (HBITMAP) LoadImageA(NULL, ART_TDI[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            cargar_imagen();

                        }
                        break;

                    case BTN_ART_MAT:
                        {
                            cont_pag = 0 ;
                            selector_art = 6;
                            //botones de navegacion
                            ShowWindow(btn_atras,SW_HIDE);
                            ShowWindow(btn_siguiente,SW_SHOW);
                            bimag = (HBITMAP) LoadImageA(NULL, ART_MAT[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            cargar_imagen();

                        }
                        break;

                    case BTN_SIGUIENTE:
                            botones_navegacion_siguiente();
                        break;

                    case BTN_ATRAS:
                            botones_navegacion_atras();
                        break;

                    case BTN_INDICE_REPORTE:
                        {
                            crear_botones_navegacion();
                            cont_pag = 0;
                            selector_art = 7;

                            //botones de navegacion
                            ShowWindow(btn_atras,SW_HIDE);
                            ShowWindow(btn_siguiente,SW_SHOW);
                            bimag = (HBITMAP) LoadImageA(NULL, IMG_REPORTE[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                            cargar_imagen();
                        }
                        break;

                    case BTN_INDICE_JUEGO:
                            ShellExecute(NULL, "open", RUTA_JUEGO, NULL, NULL, SW_NORMAL);
                        break;

                    case BTN_INDICE_CALCU:
                            ShellExecute(NULL, "open", RUTA_CALCULADORA[idio], NULL, NULL, SW_NORMAL);
                        break;

                    case MN_IDIOMA_ESP:
                        {
                            if (idio == 0)
                                break;

                            cont_articulo = 0;
                            cont_indice = 0;
                            idio = 0;
                            DestroyWindow(hwnd);
                            crear_ventana_menu();
                            DestroyWindow(hImag);
                            cont_indice = 0;
                            guardar_idioma(idio);
                        }
                        break;


                    case MN_IDIOMA_ING:
                        {
                            MessageBeep(BM_CLICK);
                            if (idio == 1)
                                break;

                            cont_articulo = 0;
                            cont_indice = 0;
                            idio = 1;
                            DestroyWindow(hwnd);
                            crear_ventana_menu();
                            DestroyWindow(hImag);
                            cont_indice = 0;
                            guardar_idioma(idio);
                        }
                        break;

                    case MN_CREDITOS:
                        ShellExecute(NULL,"open", RUTA_CREDITOS[idio], NULL, NULL, SW_NORMAL);
                        break;


                    case MN_AYUDA_TIPS:
                            crear_ventana_ayuda(hwnd);
                        break;

                    case MN_LINKS_EDGAR:
                            ShellExecute(NULL,"open", LINKS_EDGAR, NULL, NULL, SW_NORMAL);
                        break;

                    case MN_LINKS_SAMUEL:
                            ShellExecute(NULL,"open", LINKS_SAMUEL, NULL, NULL, SW_NORMAL);
                        break;

                    case MN_LINKS_HUMBERT:
                            ShellExecute(NULL,"open", LINKS_HUMBERT, NULL, NULL, SW_NORMAL);
                        break;

                    case MN_LINKS_KARLA:
                            ShellExecute(NULL,"open", LINKS_KARLA , NULL, NULL, SW_NORMAL);
                        break;

                    case MN_LINKS_KEYLER:
                            ShellExecute(NULL,"open", LINKS_KEYLER , NULL, NULL, SW_NORMAL);
                        break;

                    case MN_LINKS_SANTI:
                            ShellExecute(NULL,"open", LINKS_SANTI[idio] , NULL, NULL, SW_NORMAL);
                        break;

                    case MN_LINKS_SARA:
                            ShellExecute(NULL,"open", LINKS_SARA , NULL, NULL, SW_NORMAL);
                        break;

                    case MN_LINKS_WILLI:
                            ShellExecute(NULL,"open", LINKS_WILLI , NULL, NULL, SW_NORMAL);
                        break;


                    case BTN_SALIR:
                        {
                        DestroyWindow(hwnd);
                        DestroyWindow(hImag);
                        DeleteObject(bimag);
                        PostQuitMessage (0);
                        }
                        break;
                }
            }
            break;

            case WM_VSCROLL:{

                si.cbSize = sizeof(SCROLLINFO);
                si.fMask = SIF_ALL;
                GetScrollInfo(hwnd,SB_VERT,&si);
                yPosPrev = si.nPos;

                switch(LOWORD(wParam)){
                    case SB_TOP:{
                        si.nPos = 0;
                        break;
                    }
                    case SB_BOTTOM:{
                        si.nPos = si.nMax;
                        break;
                    }
                    case SB_LINEUP:{
                        si.nPos--;
                        break;
                    }
                    case SB_LINEDOWN:{
                        si.nPos++;
                        break;
                    }
                    case SB_PAGEUP:{
                        si.nPos -= si.nPage;
                        break;
                    }
                    case SB_PAGEDOWN:{
                        si.nPos += si.nPage;
                        break;
                    }
                    case SB_THUMBTRACK:
                    case SB_THUMBPOSITION:{
                        si.nPos = si.nTrackPos;
                        break;
                    }
                    default:{
                        break;
                    }
                }

                si.fMask = SIF_POS;
                SetScrollInfo(hwnd,SB_VERT ,&si,TRUE);
                GetScrollInfo(hwnd,SB_VERT,&si);
                yPosActual = si.nPos;

                if(yPosPrev != yPosActual){ ///POSICION ANTERIOR DISTINTA A LA ACTUAL
                    bScroll = 1;

                    ScrollWindow(hScroll,0,(yPosPrev - yPosActual),NULL,NULL);
                    UpdateWindow(hScroll);
                }
                break;
        }

        case WM_CLOSE:
            {
                DestroyWindow(hwnd);
                DestroyWindow(hImag);
                DeleteObject(bimag);
                PostQuitMessage(0);
            }break;

        case WM_DESTROY:
            //PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, mensage, wParam, lParam);
    }
    return FALSE;
}

LRESULT CALLBACK cAyuda(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static HINSTANCE Instancia;
    switch (msg)
    {
        case WM_CREATE:
        {
            CreateWindowEx(0, "BUTTON", Volver[idio], BS_CENTER | BS_FLAT | WS_VISIBLE | WS_CHILD,  (anchoAyuda - 95), (altoAyuda-60), 80, 25, hwnd, (HMENU)BTN_VOLVER, NULL, NULL);

            bimag = (HBITMAP) LoadImageA(NULL, IMG_AYUDA1[idio], IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hImag = CreateWindowW(L"Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 50, (tamanoMenuy - 730)/2, 0, 0, hwnd, NULL, Instancia, NULL);
            SendMessageW(hImag, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bimag);

            bimag = (HBITMAP) LoadImageA(NULL, IMG_AYUDA2[idio], IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hImag = CreateWindowW(L"Static", NULL,  WS_VISIBLE | WS_CHILD | SS_BITMAP, anchoAyuda - 550, (tamanoMenuy - 730)/2, 0, 0, hwnd, NULL, Instancia, NULL);
            SendMessageW(hImag, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bimag);
        }
            break;


        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
            case BTN_VOLVER:
                {
                    DestroyWindow(hwnd);
                }break;
            }
        }
            break;

        case WM_DESTROY:
           // PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}


LRESULT CALLBACK cScroll(HWND hwnd , UINT msg , WPARAM wParam, LPARAM lParam ){
    PAINTSTRUCT ps;
    HDC hdcCliente = NULL;
    HDC hdcTemporal;
    SCROLLINFO si;

    static int cxCliente,cyCliente;
    //static int bSize, bScroll;

    switch (msg)
    {
        case WM_CREATE:
            {
                yPosActual = 0;
                xPosActual = 0;

                bSize = 0;
                bScroll = 0;
            }
            break;

        case WM_SIZE:
            {
                cxCliente = LOWORD(lParam);
                cyCliente = HIWORD(lParam);

                si.cbSize = sizeof(SCROLLINFO);
                si.fMask = SIF_ALL ;
                si.nMin = 0; // EL PUNTO MAS ALTO
                si.nMax = 1019 ;//HAZTA DONDE SE PUEDE SCROLLEAR
                si.nPage = cyCliente;
                si.nPos = 0;
                SetScrollInfo(hVentMenu, SB_VERT, &si, TRUE);// SE GUARDA LA INFORMACION DE LA SCROLLBARD

                bSize = 1;
                InvalidateRect(hVentMenu,NULL,FALSE);///INVALIDAR TODA EL AREA CLIENTE
            }
            break;

        case WM_PAINT:
            {

               // int posx =  100;//(cxCliente - 720)/2 ;
                hdcCliente = BeginPaint(hwnd,&ps);
                hdcTemporal = CreateCompatibleDC(hdcCliente);
                SelectObject(hdcTemporal,bimag);

                 if(bSize)
                    {
                        BitBlt(hdcCliente,0,0,cxCliente,cyCliente,
                               hdcTemporal,xPosActual,yPosActual,SRCCOPY);
                        bSize = 0;
                    }
                else if(bScroll)
                    {// SI SE HACE SCROLL
                        BitBlt(hdcCliente,
                               ps.rcPaint.left,ps.rcPaint.top,
                               ps.rcPaint.right,ps.rcPaint.bottom,
                               hdcTemporal,
                               xPosActual+ps.rcPaint.left,
                               yPosActual+ps.rcPaint.top,
                               SRCCOPY);

                        bScroll = 0;
                    }
                else{// PARA CUENDO SE ESCONDE LA VENTANA
                    BitBlt(hdcCliente,ps.rcPaint.left,ps.rcPaint.top,ps.rcPaint.right,ps.rcPaint.bottom,
                           hdcTemporal,xPosActual + ps.rcPaint.left,yPosActual + ps.rcPaint.top,SRCCOPY);
                    }

                DeleteDC(hdcTemporal);
                EndPaint(hwnd,&ps);
            }
            break;

        case WM_COMMAND:
            break;

        case WM_DESTROY:
           // PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}



void crear_menu(HWND hwnd){
    hmenuPrincipal = CreateMenu();//menu principañ

    HMENU hAyuda = CreateMenu();//sub menu del ayuda
    AppendMenu(hAyuda, MF_STRING, MN_AYUDA_TIPS, instruc[idio]);
    AppendMenu(hAyuda, MF_SEPARATOR, 0, NULL);
    AppendMenu(hAyuda, MF_STRING, BTN_SALIR, salir[idio]);

    HMENU hLinks = CreateMenu();//sub menu del links
    if(idio == 0)
    {
        AppendMenu(hmenuPrincipal, MF_POPUP, (UINT_PTR)hLinks, "Links");

        AppendMenu(hLinks, MF_STRING, MN_LINKS_SAMUEL, "Samuel");
        AppendMenu(hLinks, MF_STRING, MN_LINKS_EDGAR, "Edgar");
        AppendMenu(hLinks, MF_STRING, MN_LINKS_SARA, "Sara");
        AppendMenu(hLinks, MF_STRING, MN_LINKS_KARLA, "Karla");
        AppendMenu(hLinks, MF_STRING, MN_LINKS_SANTI, "Santiago");
        AppendMenu(hLinks, MF_STRING, MN_LINKS_KEYLER, "Keyler");
        AppendMenu(hLinks, MF_STRING, MN_LINKS_HUMBERT, "Humberto");
        AppendMenu(hLinks, MF_STRING, MN_LINKS_WILLI, "Williangel");
    }
    else
        AppendMenu(hmenuPrincipal, MF_STRING, MN_LINKS_SANTI, "Links");

    HMENU hIdioma = CreateMenu();// sub menu del aidioma
    AppendMenu(hIdioma, MF_STRING, MN_IDIOMA_ESP,"Castellano");
    AppendMenu(hIdioma, MF_SEPARATOR, 0, NULL);
    AppendMenu(hIdioma, MF_STRING, MN_IDIOMA_ING,"English");

    //menus principales agregados al menu
    AppendMenu(hmenuPrincipal, MF_POPUP, (UINT_PTR)hAyuda ,ayuda[idio]);
    AppendMenu(hmenuPrincipal, MF_POPUP, (UINT_PTR)hIdioma, idiona[idio]);
    AppendMenu(hmenuPrincipal, MF_STRING, MN_CREDITOS , creditos[idio]);

    SetMenu(hwnd,hmenuPrincipal);
}

void botones_navegacion_siguiente(){
    cont_pag ++;

    if(cont_pag == 1)
        ShowWindow(btn_atras, SW_SHOW);

    switch(selector_art)
    {
        case 1:
        {
            if(cont_pag == 3)
            {
                ShowWindow(btn_siguiente, SW_HIDE);
            }

            bimag = (HBITMAP) LoadImageA(NULL, ART_CIENT[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            cargar_imagen();
        }
        break;

        case 2:
        {
            if(cont_pag == 1)
            {
                ShowWindow(btn_siguiente, SW_HIDE);
            }

            bimag = (HBITMAP) LoadImageA(NULL, ART_OPI1[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            cargar_imagen();
        }
        break;

        case 3:
        {
            if(cont_pag == 1)
            {
                ShowWindow(btn_siguiente, SW_HIDE);
            }

            bimag = (HBITMAP) LoadImageA(NULL, ART_OPI2[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            cargar_imagen();
        }
        break;

        case 4:
        {
            if(cont_pag == 1)
            {
                ShowWindow(btn_siguiente, SW_HIDE);
            }

            bimag = (HBITMAP) LoadImageA(NULL, ART_REPORTAJ[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            cargar_imagen();
        }
        break;

        case 5:
        {
            if(cont_pag == 3)
            {
                ShowWindow(btn_siguiente, SW_HIDE);
            }

            bimag = (HBITMAP) LoadImageA(NULL, ART_TDI[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            cargar_imagen();
        }
        break;

        case 6:
        {

            if(cont_pag == 4)
            {
                ShowWindow(btn_siguiente, SW_HIDE);
            }

            bimag = (HBITMAP) LoadImageA(NULL, ART_MAT[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            cargar_imagen();
        }break;

        case 7:
        {

            if(cont_pag == 4)
            {
                ShowWindow(btn_siguiente, SW_HIDE);
            }

            bimag = (HBITMAP) LoadImageA(NULL, IMG_REPORTE[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            cargar_imagen();
        }break;

        default: break;
    }
}

void botones_navegacion_atras(){
    cont_pag --;

    switch(selector_art)
    {
        case 1:
        {
            if(cont_pag < 4)
            {
                ShowWindow(btn_siguiente, SW_SHOW);
            }

             bimag = (HBITMAP) LoadImageA(NULL, ART_CIENT[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            cargar_imagen();

        }break;

        case 2:
        {
            if(cont_pag < 1)
            {
                ShowWindow(btn_siguiente, SW_SHOW);
            }

             bimag = (HBITMAP) LoadImageA(NULL, ART_OPI1[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            cargar_imagen();

        }break;

        case 3:
        {
            if(cont_pag < 1)
            {
                ShowWindow(btn_siguiente, SW_SHOW);
            }

             bimag = (HBITMAP) LoadImageA(NULL, ART_OPI2[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            cargar_imagen();

        }break;

        case 4:
        {
            if(cont_pag < 1)
            {
                ShowWindow(btn_siguiente, SW_SHOW);
            }

             bimag = (HBITMAP) LoadImageA(NULL, ART_REPORTAJ[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            cargar_imagen();

        }break;

        case 5:
        {
            if(cont_pag < 4)
            {
                ShowWindow(btn_siguiente, SW_SHOW);
            }

             bimag = (HBITMAP) LoadImageA(NULL, ART_TDI[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            cargar_imagen();

        }break;


        case 6:
        {
            if(cont_pag < 5)
            {
                ShowWindow(btn_siguiente, SW_SHOW);
            }

             bimag = (HBITMAP) LoadImageA(NULL, ART_MAT[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            cargar_imagen();
        }
        break;

        case 7:
        {
            if(cont_pag < 5)
            {
                ShowWindow(btn_siguiente, SW_SHOW);
            }

             bimag = (HBITMAP) LoadImageA(NULL, IMG_REPORTE[cont_pag][idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            cargar_imagen();
        }
        break;

        default:break;
    }

    if(cont_pag == 0)
     {
         ShowWindow(btn_atras, SW_HIDE);
     }
}


