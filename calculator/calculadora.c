#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>




double base;
double argumento;
double acum_operaciones;
double acum_argumento = 0;
double b_potencia = 0;
double resultado = 0;
int opcion_menu_base = 0;
int opcion_menu_argumento = 0;
int opcion_submenu_argumento = 0;
int operacion_add = 0;
int selector_operacion = 0;
int mul_log = 0;
int opcion_mul = 0;
int salir = 0;
int continua;
int result;

void continuar()
{   printf("__________________________________________\n \n");
    printf("Hubo un error?:\n \n");
    printf("[1] No.\n");
    printf("[0] Si.\n");
    printf("__________________________________________\n \n");
    printf("Ingrese una opcion: ");
    scanf("%d", &continua);
    printf("__________________________________________\n \n");
}
void salir_calculadora(){
    printf("\nPresione [1] para salir: ");
    scanf("%d", &salir);
}

void menu_base() {
    setlocale(LC_ALL, "");

    int valor_valido = 0;

    while(valor_valido == 0)
    {
        //do{

        printf("__________________________________________\n \n");
        printf("Seleccione una opción para la base:\n \n");
        printf("[1] Raíz cuadrada.\n");
        printf("[2] Raiz con indice cualquiera.\n");
        printf("[3] Potencia.\n");
        printf("[4] fraccion.\n");
        printf("[5] Normal.\n");
        printf("__________________________________________\n \n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion_menu_base);
        printf("__________________________________________\n \n");
        while (getchar() != '\n');
        //}hile(result!= 1);
        if(opcion_menu_base > 0 && opcion_menu_base <6)
            {
                valor_valido = 1;
            }
        else
            {
            printf("__________________________________________\n \n");
            printf("Opcion Inavalida Intente de nuevo \n");
            printf("__________________________________________\n \n");
            }

    }
}

void menu_argumento()
{
    int valor_valido = 0;

    while(valor_valido == 0){
        printf("__________________________________________\n \n");
        printf("Seleciones una opcion para el argumento:\n \n");
        printf("[1] Raiz cuadrada.\n");
        printf("[2] Raiz con indice cualquiera.\n");
        printf("[3] Potencia.\n");
        printf("[4] fraccion.\n");
        printf("[5] Normal.\n");
        printf("__________________________________________\n \n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion_menu_argumento);
        printf("__________________________________________\n \n");
        while (getchar() != '\n');

        if( opcion_menu_argumento > 0 && opcion_menu_argumento <6){
            valor_valido = 1;
        }else{
            printf("__________________________________________\n \n");
            printf("Opcion Inavalida Intente de nuevo \n");
            printf("__________________________________________\n \n");
        }

    }

}

void menu_argumento_extra(){
    int valor_valido = 0;

    while (valor_valido == 0){
	 printf("__________________________________________\n \n");
        printf("Quieres agregar otro termino al argumento?\n \n");
        printf("[1]Sumar.\n");
        printf("[2]restar.\n");
        printf("[3]multiplicar.\n");
        printf("[4]Continuar sin agregar.\n");
        printf("__________________________________________\n \n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion_submenu_argumento);
        printf("__________________________________________\n \n");
        while (getchar() != '\n');

        if(opcion_submenu_argumento > 0 && opcion_submenu_argumento <5){
            valor_valido = 1;
        }else{

            printf("__________________________________________\n \n");
            printf("Opcion Inavalida Intente de nuevo \n");
            printf("__________________________________________\n \n");

        }
    }
}

void multiplicacion_logaritmo(){
    int valor_valido = 0;

    while(valor_valido == 0){
	printf("__________________________________________\n \n");
     printf("El logaritmo esta siendo multiplicado?\n \n");
     printf("[1] Si.\n");
     printf("[2] No.\n");
     printf("__________________________________________\n \n");
     printf("Ingrese una opcion: ");
     scanf("%d", &opcion_mul);
     while (getchar() != '\n');

     if(opcion_mul > 0 && opcion_mul < 3){
        valor_valido = 1;
     }else{

        printf("__________________________________________\n \n");
        printf("Opcion Inavalida Intente de nuevo \n");
        printf("__________________________________________\n \n");

        }
    }
}

void operacion_extra(){

    int valor_valido = 0;

    while(valor_valido == 0){
	printf("__________________________________________\n \n");
     printf("Haras otra operacion con el logaritmo?\n \n");
     printf("[1] Sumar con otro logaritmo.\n");
     printf("[2] Restar con otro logaritmo.\n");
     printf("[3] Mostrar resultado y salir.\n");
	printf("__________________________________________\n \n");

     printf("Ingrese una opcion: ");
     scanf("%d", &operacion_add);
     while (getchar() != '\n');

     if(operacion_add > 0 && operacion_add < 4){
        valor_valido = 1;
     }else{

        printf("__________________________________________\n \n");
        printf("Opcion Inavalida Intente de nuevo \n");
        printf("__________________________________________\n \n");

     }
    }
}

void base_invalida(){

    if (base == 1 || base <= 0) {
        printf("__________________________________________\n \n");
        printf("Base no valida para logaritmos\n");
         exit(0);
    }

}

void argumento_invalido(){

	 if (acum_argumento <= 0) {
            printf("__________________________________________\n \n");
            printf("Argumento no valido para logaritmos\n");
        	exit(0);
        }
}

int main() {

    float deno, divi;
    float num2, indice, expon;

    do//desde aqui inicia todo el codigo en general
    {
        menu_base();

        switch(opcion_menu_base) // desde aqui trabaja el menu de la base
        {
            case 1:
                {
                    do{
                    printf("Ingrese la base del logaritmo: ");
                    scanf("%lf", &base);
                    while (getchar() != '\n');

                    if(base > 0)
                    {
                        base = sqrt(base);
                    }
                    else
                    {
                        printf("Error: Valor no valido para una raiz.\n ");
                        salir_calculadora();
                        return 0;
                    }
                     continuar();
                    }while(continua != 1);
                }break;

            case 2:
                {
                    do{
                    printf("Ingrese el indice de la raiz: ");
                    scanf("%f", &indice);
                    while (getchar() != '\n');

                    printf("Ingrese el numero dentro de la raiz: ");
                    scanf("%f", &num2);
                    while (getchar() != '\n');

                    printf("Ingrese el exponente del numero dentro de la raiz: ");
                    scanf("%f", &expon);
                    while (getchar() != '\n');

                    if(num2 != 1 && num2 > 0 && indice != 0)
                    {
                        base = pow(num2, expon / indice);
                    }
                    else
                    {
                        printf("Error: Valor no valido para una raiz.\n");
                        salir_calculadora();
                        return 0;
                    }
                     continuar();
                    }while(continua != 1);

                }break;

            case 3:
                {
                    do{
                    printf("Ingrese la base del logaritmo: ");
                    scanf("%lf", &base);
                    while (getchar() != '\n');

                    printf("Ingrese la potencia: ");
                    scanf("%lf", &b_potencia);
                    while (getchar() != '\n');
                    base = pow(base, b_potencia);

                    printf("%.2lf\n", base);

                     continuar();
                    }while(continua != 1);

                }break;

            case 4:
                {
                    do{
                    printf("Ingrese el numerador: ");
                    scanf("%f", &deno);
                    while (getchar() != '\n');
                    printf ("Ingrese el denominador: ");
                    scanf("%f", &divi);
                    while (getchar() != '\n');

                    if(divi != 0)
                    {
                    	base = deno/divi;
                    }
                    else
                    {
                        printf("Error: La dvision entre 0 no es valida.\n");
                        salir_calculadora();
                        return 0;
                    }
                     continuar();
                    }while(continua != 1);

                }break;

            case 5:
                {
                    do{
                    printf("Ingrese la base del logaritmo: ");
                    scanf("%lf", &base);
                    while (getchar() != '\n');

                     continuar();
                    }while(continua != 1);
                }break;
        }

        do{

        menu_argumento();

        switch(opcion_menu_argumento)//desde aqui trabaja el menu del argumento
        {
            case 1:
                {
                    do{
                    printf("Ingrese el argumento del logaritmo: ");
                    scanf("%lf", &argumento);
                    while (getchar() != '\n');

                    if(base > 0)
                    {
                        argumento = sqrt(argumento);
                    }
                    else
                    {
                        printf("Error: Valor no valido para una raiz.\n ");
                        salir_calculadora();
                        return 0;
                    }
                     continuar();
                    }while(continua != 1);

              }break;

            case 2:
                {
                    do{
                    printf("Ingrese el indice de la raiz: ");
                    scanf("%f", &indice);
                    while (getchar() != '\n');

                    printf("Ingrese el numero dentro de la raiz: ");
                    scanf("%f", &num2);
                    while (getchar() != '\n');

                    printf("Ingrese el exponente del numero dentro de la raiz: ");
                    scanf("%f", &expon);
                    while (getchar() != '\n');

                    if(num2 != 1 && num2 > 0 && indice != 0)
                    {
                        argumento = pow(num2, expon / indice);
                    }
                    else
                    {
                        printf("Error: Valor no valido para una raiz.\n");
                        salir_calculadora();
                        return 0;
                    }
                     continuar();
                    }while(continua != 1);

                }break;

            case 3:
                {
                    do{
                    printf("Ingrese el argumento del logaritmo: ");
                    scanf("%lf", &argumento);
                    while (getchar() != '\n');

                    printf("Ingrese la potencia: ");
                    scanf("%lf", &b_potencia);
                    while (getchar() != '\n');

                    argumento = pow(argumento, b_potencia);

                    printf("%.2lf\n", argumento);

                     continuar();
                    }while(continua != 1);

                }break;

            case 4:
                {
                    do{
                    printf("Ingrese el numerador: ");
                    scanf("%f", &deno);
                    while (getchar() != '\n');
                    printf ("Ingrese el denominador: ");
                    scanf("%f", &divi);
                    while (getchar() != '\n');

                    if(divi != 0)
                    {
                    	argumento = deno/divi;
				    }
				    else
                    {
                        printf("Error: La dvision entre 0 no es valida.\n");
                        salir_calculadora();
                        return 0;
                    }
                     continuar();
                    }while(continua != 1);

                }break;

                case 5:
                {
                    do{
                    printf("Ingrese el argumento del logaritmo: ");
                    scanf("%lf", &argumento);
                    while (getchar() != '\n');

                     continuar();
                    }while(continua != 1);

                }break;

         }

        //aqui se acumula el resultado del argumento para operarlo luego como un solo termino en el logaritmo
        if(opcion_submenu_argumento == 0)
            {
                acum_argumento+= argumento;
            }
        else if(opcion_submenu_argumento == 1)
            {
                acum_argumento+= argumento;
            }
        else if(opcion_submenu_argumento == 2)
            {
                acum_argumento -= argumento;
            }
        else if(opcion_submenu_argumento == 3)
            {
                acum_argumento = acum_argumento * argumento;
            }

			//prgunta si se quiere agregar un termino mas al argumento
        menu_argumento_extra();

        }while(opcion_submenu_argumento != 4);

        //determina la validez de el argumento y la base
        base_invalida();
        argumento_invalido();

        //se optiene el resultado del logaritmo
        resultado = log(acum_argumento)/ log(base);

        //se pregunta si el logaritmo esta siendo multiplicado
        multiplicacion_logaritmo();

        switch(opcion_mul)//se agrega el numero que multiplica el logaritmo
        {
            case 1:
                {
                    do{
                    printf("Ingrese el numero que multiplica el logaritmo: ");
                    scanf("%d", &mul_log);
                    while (getchar() != '\n');
                     continuar();
                    }while(continua != 1);
                    resultado = resultado * mul_log;

                }break;
        }

        //se acumula el resultado del logaritmo y se va guardado en dado caso que se quiera restar o sumar otro logaritmo
        if(selector_operacion == 0)
            {
                acum_operaciones += resultado;
            }
        else if(selector_operacion == 1)
            {
                acum_operaciones += resultado;
            }
        else if(selector_operacion == 2)
            {
                acum_operaciones -= resultado;
            }

        //se pregunta que se hara con el logaritmo
        operacion_extra();

        switch(operacion_add)//aqui se devuelve el valor para realizar otra operacion o finalizar el codigo
        {
            case 1:
                {
                    selector_operacion = 1;
                    acum_argumento = 0;
                    opcion_submenu_argumento = 0;

                }break;

            case 2:
                {
                    selector_operacion = 2;
                    acum_argumento = 0;
                    opcion_submenu_argumento = 0;

                }break;

            case 3:
                {
                    printf("__________________________________________\n \n");
                    printf("Resultado: %.2lf\n", acum_operaciones);

                    salir_calculadora();

                }break;
        }


    } while (salir == 0);

    salir_calculadora();
    return 0;
}
