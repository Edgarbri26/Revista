#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wingdi.h>
#include "../DEFINICIONES.h"
//#include "../libreria/FUNCIONES.h"

int aciertos = 0;
int fallas = 0;
int l = 0, o = 0, g = 0, a = 0, r = 0, i = 0, t = 0, m = 0, h = 0;
int x,y; //tamño de la pantalla de la computadora
int poscX = 0;
int poscY = 0;


static HINSTANCE Instancia;


HWND hInicio, hReglas, juego, btn_salir_juego, btn_volver_juego;
HWND hImag = NULL;
HBITMAP  bActual,bFinal;

HWND hBase = NULL;
HBITMAP  bBase;

HWND hL = NULL;
HBITMAP  bL;

HMENU hmenuPrincipal;
LRESULT CALLBACK cInicio(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK cReglas(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK JUEGO(HWND, UINT, WPARAM, LPARAM);
//void crear_ventana_juego();
void crear_ventana_reglas();
void intentoFallido(int, HWND);
void cargar_imagen(const char*);
void cargar_img_letra(const char*,int x, HWND);
void ganar(HWND);

void crear_ventana_juego()
{
    juego = CreateWindowEx(0, "JUEGOCLSS", nombre[idio], WS_OVERLAPPED | WS_SYSMENU | WS_MAXIMIZE,
                               0, 0, x, y, NULL, NULL, NULL, NULL);

    ShowWindow(juego, SW_SHOW);
    UpdateWindow(juego);
}

void crear_ventana_reglas(){
    int anchoVentana = 800;

    hReglas = CreateWindowEx(0, "REGLASCLSS", reglas_juego[idio], WS_OVERLAPPED | WS_SYSMENU,
                               ((x - anchoVentana)/2), 0, anchoVentana , y, NULL, NULL, NULL, NULL);

    ShowWindow(hReglas, SW_SHOW);
    UpdateWindow(hReglas);

}

 void cargar_img_letra (const char* RUTA, int X, HWND hwnd){
     aciertos ++;
     bL = (HBITMAP) LoadImage(NULL, RUTA, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
     hL = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP , X, 100,0, 0,juego,NULL,Instancia,NULL);
     SendMessageW(hL,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)bL);
     ganar(hwnd);
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    //idio = cargar_Idioma (idio);
     x = GetSystemMetrics(SM_CXSCREEN);
     y = GetSystemMetrics(SM_CYSCREEN);

    WNDCLASSEX wcInicio = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW , cInicio,
                        0, 0, GetModuleHandle(NULL), LoadIcon(NULL, IDI_QUESTION),
                        LoadCursor(NULL, IDC_ARROW), CreateSolidBrush(RGB(208,183,116)),
                        NULL, "INICIOCLSS", LoadIcon(NULL, IDI_QUESTION)};

    RegisterClassEx(&wcInicio);

    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW , JUEGO,
                        0, 0, GetModuleHandle(NULL), LoadIcon(NULL, IDI_QUESTION),
                        LoadCursor(NULL, IDC_ARROW), CreateSolidBrush(RGB(208,183,116)),
                        NULL, "JUEGOCLSS", LoadIcon(NULL, IDI_QUESTION)};

    RegisterClassEx(&wc);

    WNDCLASSEX wcReglas = { sizeof(WNDCLASSEX), CS_HREDRAW | CS_VREDRAW , cReglas,
                        0, 0, GetModuleHandle(NULL), LoadIcon(NULL, IDI_QUESTION),
                        LoadCursor(NULL, IDC_ARROW), CreateSolidBrush(RGB(208,183,116)),
                        NULL, "REGLASCLSS", LoadIcon(NULL, IDI_QUESTION)};

    RegisterClassEx(&wcReglas);

    hInicio = CreateWindowEx(0, "INICIOCLSS", nombre[idio], WS_OVERLAPPED | WS_SYSMENU | WS_MAXIMIZE,
                               0, 0, x , y, NULL, NULL, NULL, NULL);

    PlaySound("C:/Revista/Ahorcado/Sounds/doom.wav", NULL, SND_FILENAME | SND_ASYNC);
    ShowWindow(hInicio, SW_SHOW);
    UpdateWindow(hInicio);


    //crear_ventana_juego();

    ShowWindow(GetConsoleWindow(), SW_HIDE);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK JUEGO(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

    switch (uMsg)
    {
       case WM_CREATE:
            {
                bActual = (HBITMAP) LoadImage(NULL, IMAGE_0,IMAGE_BITMAP, 570, y, LR_LOADFROMFILE);
                hImag = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP, 0,0,0,0,hwnd,NULL,Instancia,NULL);
                SendMessageW(hImag,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)bActual);

                bBase = (HBITMAP) LoadImage(NULL, IMG_BASE, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

                hBase = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP, (x-786), 180, 182, 8,hwnd,NULL,Instancia,NULL);
                SendMessageW(hBase,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)bBase);


            }
            break;

       case WM_COMMAND:
            {
                switch(wParam)
                {
                    case BTN_SALIR_JUEGO:
                    {
                        DestroyWindow(hwnd);
                        DeleteObject(bActual);
                        DeleteObject(bFinal);
                        PostQuitMessage(2);
                    }break;

                    case BTN_VOLVER_JUEGO:
                    {
                        DestroyWindow(hwnd);
                        crear_ventana_juego();
                        l = 0, o = 0, g = 0, a = 0, r = 0, i = 0, t = 0, m = 0, h = 0;
                        fallas = 0;
                        aciertos = 0;
                        PlaySound("C:/Revista/Ahorcado/Sounds/tetris.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);


                    }break;
                }
            }
            break;

        case WM_CHAR:
            {
                switch(wParam)
                {
                    case 'l':
                        {
                           if (l == 0)
                            {
                                cargar_img_letra(IMG_L, (x-786), hwnd);
                                l = 1;
                            }
                        }
                        break;

                    case 'o':
                        {
                            if (o == 0)
                            {
                                o = 1;
                                cargar_img_letra (IMG_O, (x-694), hwnd);

                                if(idio == 0)
                                    cargar_img_letra (IMG_O, (x-80), hwnd);
                            }
                        }
                        break;

                    case 'g':
                        {
                            if (g == 0)
                            {
                                cargar_img_letra (IMG_G, (x-602), hwnd);
                                g = 1;
                            }
                        }
                        break;

                    case 'a':
                        {
                            if (a == 0)
                            {
                                cargar_img_letra (IMG_A, (x-510), hwnd);
                                a = 1;
                            }
                        }
                        break;

                    case 'r':
                        {
                            if (r == 0)
                            {
                                cargar_img_letra (IMG_R, (x-418), hwnd);
                                r = 1;
                            }
                        }
                        break;

                    case 'i':
                            {
                                if (i == 0)
                                {
                                    cargar_img_letra (IMG_I, (x-326), hwnd);
                                    i = 1;
                                }
                            }
                            break;

                    case 't':
                        {
                            if (t == 0)
                            {
                                cargar_img_letra (IMG_T, (x-265), hwnd);
                                t = 1;
                            }
                        }
                        break;

                    case 'm':
                        {
                             if (m == 0)
                                {
                                    m = 1;
                                    if(idio == 0)
                                    {
                                        cargar_img_letra (IMG_M, (x-173), hwnd);
                                    }
                                    else
                                    {
                                        cargar_img_letra (IMG_M, (x-80), hwnd);
                                    }
                                }
                        }
                        break;

                    case 'h':
                        {
                            if(idio == 1)
                            {
                                if (h == 0)
                                {
                                     h = 1;
                                    cargar_img_letra (IMG_H, (x-173), hwnd);
                                }
                            }
                            else
                            {
                                fallas++;
                                intentoFallido(fallas, hwnd);
                            }
                        }
                        break;

                    default:
                        {
                            fallas++;
                            intentoFallido(fallas, hwnd);
                        }
                        break;
                }
            }
            break;
        case WM_CLOSE:
            {
                PostQuitMessage (0);
            }
            break;

        case WM_DESTROY:
            {
                //DeleteObject(bActual);
                //DeleteObject(bFinal);
                //PostQuitMessage (0);
            }
            break;

        default:
            return DefWindowProc (hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK cInicio(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CREATE:
        {
            CreateWindowEx(0, "BUTTON", iniciar_juego[idio], BS_CENTER | BS_FLAT | WS_VISIBLE| WS_CHILD, (x-110)/2, 420, 110, 35, hwnd, (HMENU)BTN_INICIAR_JUEGO, NULL, NULL);
            CreateWindowEx(0, "BUTTON", multijugador_juego[idio], BS_CENTER | BS_FLAT | WS_VISIBLE| WS_CHILD, (x-110)/2, 480, 110, 35, hwnd, (HMENU)BTN_MUL_JUEGO, NULL, NULL);
            CreateWindowEx(0, "BUTTON", reglas_juego[idio], BS_CENTER | BS_FLAT | WS_VISIBLE| WS_CHILD, (x-110)/2, 540, 110, 35, hwnd, (HMENU)BTN_REGLAS_JUEGO, NULL, NULL);
            CreateWindowEx(0, "BUTTON", salir_juego[idio], BS_CENTER | BS_FLAT | WS_VISIBLE| WS_CHILD, (x-110)/2, 700, 110, 35, hwnd, (HMENU)BTN_SALIR_JUEGO, NULL, NULL);

             bActual = (HBITMAP) LoadImage(NULL, IMG_6,IMAGE_BITMAP, 570, y, LR_LOADFROMFILE);
                hImag = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP, 0,0,0,0,hwnd,NULL,Instancia,NULL);
                SendMessageW(hImag,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)bActual);

            bActual = (HBITMAP) LoadImage(NULL, IMG_6_1,IMAGE_BITMAP, 570, y, LR_LOADFROMFILE);
                hImag = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP, x-570,0,0,0,hwnd,NULL,Instancia,NULL);
                SendMessageW(hImag,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)bActual);

                 bActual = (HBITMAP) LoadImage(NULL, IMG_TITULO[idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
                hImag = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP, (x-700)/2,100,0,0,hwnd,NULL,Instancia,NULL);
                SendMessageW(hImag,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)bActual);
        }
            break;

        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case BTN_INICIAR_JUEGO:
                    {
                        DestroyWindow(hwnd);
                        crear_ventana_juego();
                        PlaySound("C:/Revista/Ahorcado/Sounds/tetris.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

                    }break;

                case BTN_MUL_JUEGO:
                    {
                        MessageBox(NULL, mensaje_juego[idio], aviso_juego[idio], MB_OK | MB_ICONEXCLAMATION);

                    }break;

                case BTN_REGLAS_JUEGO:
                    {
                        crear_ventana_reglas();

                    }break;

                case BTN_SALIR_JUEGO:
                    {
                        DeleteObject(bActual);
                        DeleteObject(bFinal);
                        PostQuitMessage (0);

                    }break;


            }
        }
            break;
            case WM_CLOSE:
            {
                PostQuitMessage (0);
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

LRESULT CALLBACK cReglas(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_CREATE:
        {
            CreateWindowEx(0, "BUTTON", listo_juego[idio], BS_CENTER | BS_FLAT | WS_VISIBLE| WS_CHILD, ((x-(x/2))-100)/2, y-120, 120, 35, hwnd, (HMENU)BTN_LISTO_JUEGO, NULL, NULL);

            bActual = (HBITMAP) LoadImage(NULL, IMG_REGLAS[idio],IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            hImag = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP, 0,0,0,0,hwnd,NULL,Instancia,NULL);
            SendMessageW(hImag,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)bActual);
        }
            break;

        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {
                case BTN_LISTO_JUEGO:
                    {
                        DestroyWindow(hReglas);
                    }break;
            }
        }
            break;

        case WM_DESTROY:
            //PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
void ganar(HWND hwnd){


    if(aciertos == 9 &&  fallas == 0)
    {
        HBITMAP bFinal = (HBITMAP) LoadImage(NULL, IMG_GANO[idio], IMAGE_BITMAP, 1100, 405, LR_LOADFROMFILE);
        HWND hImagFinal = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP, (x-1050)/2, (y-400)/2, 0, 0,juego,NULL,Instancia,NULL);

        SendMessageW(hImagFinal, STM_SETIMAGE, IMAGE_BITMAP,(LPARAM)bFinal);
        cargar_imagen(IMAGE_0);
    }
    else if(aciertos == 9 &&  fallas == 1)
    {
        HBITMAP bFinal = (HBITMAP) LoadImage(NULL, IMG_GANO[idio], IMAGE_BITMAP, 1100, 405, LR_LOADFROMFILE);
        HWND hImagFinal = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP, (x-1050)/2, (y-400)/2, 0, 0,juego,NULL,Instancia,NULL);
        SendMessageW(hImagFinal, STM_SETIMAGE, IMAGE_BITMAP,(LPARAM)bFinal);

        cargar_imagen(IMG_1);
    }
     else if(aciertos == 9 &&  fallas == 2)
    {
        HBITMAP bFinal = (HBITMAP) LoadImage(NULL, IMG_GANO[idio], IMAGE_BITMAP, 1100, 405, LR_LOADFROMFILE);
        HWND hImagFinal = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP, (x-1050)/2, (y-400)/2, 0, 0,juego,NULL,Instancia,NULL);
        SendMessageW(hImagFinal, STM_SETIMAGE, IMAGE_BITMAP,(LPARAM)bFinal);

        cargar_imagen(IMG_2);
    }
     else if(aciertos == 9 &&  fallas == 3)
    {
        HBITMAP bFinal = (HBITMAP) LoadImage(NULL, IMG_GANO[idio], IMAGE_BITMAP, 1100, 405, LR_LOADFROMFILE);
        HWND hImagFinal = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP, (x-1050)/2, (y-400)/2, 0, 0,juego,NULL,Instancia,NULL);
        SendMessageW(hImagFinal, STM_SETIMAGE, IMAGE_BITMAP,(LPARAM)bFinal);

        cargar_imagen(IMG_3);
    }
     else if(aciertos == 9 &&  fallas == 4)
    {
        HBITMAP bFinal = (HBITMAP) LoadImage(NULL, IMG_GANO[idio], IMAGE_BITMAP, 1100, 405, LR_LOADFROMFILE);
        HWND hImagFinal = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP, (x-1050)/2, (y-400)/2, 0, 0,juego,NULL,Instancia,NULL);
        SendMessageW(hImagFinal, STM_SETIMAGE, IMAGE_BITMAP,(LPARAM)bFinal);

        cargar_imagen(IMG_4);
    }
    else if(aciertos == 9 &&  fallas == 5)
    {
        HBITMAP bFinal = (HBITMAP) LoadImage(NULL, IMG_GANO[idio], IMAGE_BITMAP, 1100, 405, LR_LOADFROMFILE);
        HWND hImagFinal = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP, (x-1050)/2, (y-400)/2, 0, 0,juego,NULL,Instancia,NULL);
        SendMessageW(hImagFinal, STM_SETIMAGE, IMAGE_BITMAP,(LPARAM)bFinal);

        cargar_imagen(IMG_5);
    }

    if(aciertos == 9)
    {
        bBase = (HBITMAP) LoadImage(NULL, IMG_BASE, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        hBase = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP, (x-786), 180, 182, 8,hwnd,NULL,Instancia,NULL);
        SendMessageW(hBase,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)bBase);

        btn_salir_juego = CreateWindowEx(0, "BUTTON", salir_juego[idio], BS_CENTER | BS_FLAT | WS_VISIBLE| WS_CHILD, (x-110)/2, 650, 110, 35, hwnd, (HMENU)BTN_SALIR_JUEGO, NULL, NULL);
        btn_volver_juego = CreateWindowEx(0, "BUTTON", volver_juego[idio], BS_CENTER | BS_FLAT | WS_VISIBLE | WS_CHILD, (x-110)/2, 700, 110, 35, hwnd, (HMENU)BTN_VOLVER_JUEGO, NULL, NULL);
        PlaySound("C:/Revista/Ahorcado/Sounds/mario_win.wav", NULL, SND_FILENAME | SND_ASYNC);
    }
}

void intentoFallido(int fallas, HWND hwnd){
    switch(fallas)
    {
         case 1:
            cargar_imagen(IMG_1);
            break;

        case 2:
            cargar_imagen(IMG_2);
            break;

        case 3:
            cargar_imagen(IMG_3 );
            break;

        case 4:
            cargar_imagen(IMG_4);
            break;

        case 5:
            cargar_imagen(IMG_5);
            break;

        case 6:
            {
                poscX = (x-560)/2;
                poscY = (y-280)/2;
                HBITMAP bFinal = (HBITMAP) LoadImage(NULL, IMG_7[idio],IMAGE_BITMAP, 560, 280, LR_LOADFROMFILE);
                HWND hImagFinal = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP, (x-560)/2, (y-280)/2, 0, 0,juego,NULL,Instancia,NULL);
                SendMessageW(hImagFinal,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)bFinal);

                cargar_imagen(IMG_6 );

                btn_salir_juego = CreateWindowEx(0, "BUTTON", salir_juego[idio], BS_CENTER | BS_FLAT | WS_VISIBLE| WS_CHILD, (x-110)/2, 650, 110, 35, hwnd, (HMENU)BTN_SALIR_JUEGO, NULL, NULL);
                btn_volver_juego = CreateWindowEx(0, "BUTTON", volver_juego[idio], BS_CENTER | BS_FLAT | WS_VISIBLE | WS_CHILD, (x-110)/2, 700, 110, 35, hwnd, (HMENU)BTN_VOLVER_JUEGO, NULL, NULL);
                PlaySound("C:/Revista/Ahorcado/Sounds/mario_gameover.wav", NULL, SND_FILENAME | SND_ASYNC);
            }
            break;
    }
}

void cargar_imagen(const char* RUTA){
    bActual = (HBITMAP) LoadImage(NULL, RUTA,IMAGE_BITMAP, 570, y, LR_LOADFROMFILE);
     if(bActual == NULL )
    {
        MessageBox(NULL,"NO SE PUDO CARGAr LA IMAGEN", "ERROR",MB_OKCANCEL | MB_ICONERROR);
    }
   if (hImag != NULL)
        DestroyWindow(hImag);// LA CONDICION SOLO AFECTA ESTA LINEA POR ESO NO TIEN {}

    hImag = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP, 0,0,0,0,juego,NULL,Instancia,NULL);
    SendMessageW(hImag,STM_SETIMAGE,IMAGE_BITMAP,(LPARAM)bActual);

     if(hImag == NULL )
    {
        MessageBox(NULL,"NO SE PUDO CARGAr el manupulador", "ERROR",MB_OKCANCEL | MB_ICONERROR);
    }
}
