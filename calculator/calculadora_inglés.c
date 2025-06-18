#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

void salir_calculadora(){
    printf("\nPress [1] to exit: ");
    scanf("%d", &salir);
}

void menu_base() {

    int valor_valido = 0;

    while(valor_valido == 0){
    printf("__________________________________________\n \n");
    printf("Select an option for the base:\n \n");
    printf("[1] Square root.\n");
    printf("[2] Root with any index.\n");
    printf("[3] Power.\n");
    printf("[4] Fraction.\n");
    printf("[5] Normal.\n");
    printf("__________________________________________\n \n");
    printf("Enter an option: ");
    scanf("%d", &opcion_menu_base);
    printf("__________________________________________\n \n");

        if( opcion_menu_base > 0 && opcion_menu_base <6){
            valor_valido = 1;
        }else{
            printf("__________________________________________\n \n");
            printf("Invalid option, try again \n");
            printf("__________________________________________\n \n");
        }

    }
}

void menu_argumento()
{
    int valor_valido = 0;

    while(valor_valido == 0){
       printf("__________________________________________\n \n");
	printf("Select an option for the argument:\n \n");
	printf("[1] Square root.\n");
	printf("[2] Root with any index.\n");
	printf("[3] Power.\n");
	printf("[4] Fraction.\n");
	printf("[5] Normal.\n");
	printf("__________________________________________\n \n");
	printf("Enter an option: ");
	scanf("%d", &opcion_menu_argumento);
	printf("__________________________________________\n \n");

        if( opcion_menu_argumento > 0 && opcion_menu_argumento <6){
            valor_valido = 1;
        }else{
            printf("__________________________________________\n \n");
            printf("invalid option, try again \n");
            printf("__________________________________________\n \n");
        }

    }

}

void menu_argumento_extra(){
    int valor_valido = 0;

    while (valor_valido == 0){
	 	printf("__________________________________________\n \n");
	printf("Do you want to aggregate another term to the argument?\n \n");
	printf("[1] Add.\n");
	printf("[2] Subtract.\n");
	printf("[3] Multiply.\n");
	printf("[4] Continue without adding.\n");
	printf("__________________________________________\n \n");
	printf("Enter an option: ");
	scanf("%d", &opcion_submenu_argumento);
	printf("__________________________________________\n \n");

        if(opcion_submenu_argumento > 0 && opcion_submenu_argumento <5){
            valor_valido = 1;
        }else{

            printf("__________________________________________\n \n");
            printf("invalid option, try again \n");
            printf("__________________________________________\n \n");

        }
    }
}

void multiplicacion_logaritmo(){
    int valor_valido = 0;

    while(valor_valido == 0){
	printf("__________________________________________\n \n");
	printf("Is the logarithm being multiplied?\n \n");
	printf("[1] Yes.\n");
	printf("[2] No.\n");
	printf("__________________________________________\n \n");
	printf("Enter an option: ");
	scanf("%d", &opcion_mul);

     if(opcion_mul > 0 && opcion_mul < 3){
        valor_valido = 1;
     }else{

        printf("__________________________________________\n \n");
        printf("Invalid option, try again \n");
        printf("__________________________________________\n \n");

        }
    }
}

void operacion_extra(){

    int valor_valido = 0;

    while(valor_valido == 0){
	printf("__________________________________________\n \n");
	printf("Will you perform another operation with the logarithm?\n \n");
	printf("[1] Add with another logarithm.\n");
	printf("[2] Subtract with another logarithm.\n");
	printf("[3] Show result and exit.\n");
	printf("__________________________________________\n \n");
	printf("Enter an option: ");
	scanf("%d", &operacion_add);

     if(operacion_add > 0 && operacion_add < 4){
        valor_valido = 1;
     }else{

        printf("__________________________________________\n \n");
        printf("Invalid option, try again \n");
        printf("__________________________________________\n \n");

     }
    }
}

void base_invalida(){

    if (base == 1 || base <= 0) {
    printf("__________________________________________\n \n");
    printf("Invalid base for logarithms\n");
    exit(0);
}

}

void argumento_invalido(){

	if (acum_argumento <= 0) {
    printf("__________________________________________\n \n");
    printf("Invalid argument for logarithms\n");
    exit(0);
}
}

int main() {

    float deno, divi;
    float num2, indice;

    do//desde aqui inicia todo el codigo en general
    {
        menu_base();

        switch(opcion_menu_base) // desde aqui trabaja el menu de la base
        {
            case 1:
                {
                    printf("Enter the base of the logarithm: ");
                    scanf("%lf", &base);

                    if(base >= 0){

                    	base = sqrt(base);
				} else {

					printf("Error: Invalid value for a root.\n ");

				return 0;
				}

                }break;

            case 2:
                {
               	printf("Enter the index of the root: ");
				scanf("%f", &indice);

				printf("Enter the number inside the root: ");
				scanf("%f", &num2);


				if (num2 >= 0 && indice != 0) {
    				base = pow(num2, 1 / indice);
				} else {
    				printf("Error: Invalid value for a root.\n");
    				return 0;
				}


                }break;
            case 3:
                {

                   printf("Enter the base of the logarithm: ");
				scanf("%lf", &base);

				printf("Enter the power: ");
				scanf("%lf", &b_potencia);

				base = pow(base, b_potencia);

				printf("%.2lf\n", base);

                } break;
            case 4:
                {
                   printf("Enter the numerator: ");
				scanf("%f", &deno);
				printf("Enter the denominator: ");
				scanf("%f", &divi);

				if (divi != 0) {
   				 base = deno / divi;
				} else {
    				printf("Error: Division by 0 is not valid.\n");
    				return 0;
				}


                }break;
            case 5:
                {
                    printf("Enter the base of the logarithm: ");
                    scanf("%lf", &base);

                }break;

        }

        do{

        menu_argumento();

        switch(opcion_menu_argumento)//desde aqui trabaja el menu del argumento
        {
            case 1:
                {
                  printf("Enter the argument of the logarithm: ");
				scanf("%lf", &argumento);

				if (argumento >= 0) {
  				  argumento = sqrt(argumento);
				} else {
   				 printf("Error: Invalid value for a root.\n ");
    				return 0;
				}

                }break;
            case 2:
                {
          		printf("Enter the index of the root: ");
				scanf("%f", &indice);

				printf("Enter the number inside the root: ");
				scanf("%f", &num2);

				if (num2 >= 0 && indice != 0) {
   				 argumento = pow(num2, 1 / indice);
				} else {
   				 printf("Error: Invalid value for a root.\n");
  				  return 0;
				}


                }break;

            case 3:
                {

               printf("Enter the argument of the logarithm: ");
			scanf("%lf", &argumento);

			printf("Enter the power: ");
			scanf("%lf", &b_potencia);

			argumento = pow(argumento, b_potencia);

			printf("%.2lf\n", argumento);


                }break;

            case 4:
                {
                  printf("Enter the numerator: ");
				scanf("%f", &deno);
				printf("Enter the denominator: ");
				scanf("%f", &divi);

				if (divi != 0) {
  				  argumento = deno / divi;
				} else {
   				 printf("Error: Division by 0 is not valid.\n");
   				 return 0;
				}

                }break;

                case 5:
                {
                    printf("Enter the argument for the logarithm: ");
                    scanf("%lf", &argumento);


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
                    printf("Enter the number that multiplies the logarithm: ");
                    scanf("%d", &mul_log);

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
                }break;
            case 2:
                {
                    selector_operacion = 2;
                }break;

            case 3:
                {
                    printf("__________________________________________\n \n");
                    printf("Result: %.2lf\n", acum_operaciones);
                    salir_calculadora();
                }break;
        }

    } while (salir == 0);

    return 0;
}
