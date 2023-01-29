#include <stdint.h>
#include "../inc/tm4c1294ncpdt.h"

int
main(void)
{
    volatile uint32_t valor;
    volatile uint32_t ui32Loop;

    //
    // establecemos los puertos que abriremos en este caso los n,f y m
    //
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R12|SYSCTL_RCGCGPIO_R5|SYSCTL_RCGCGPIO_R11;

   
    ui32Loop = SYSCTL_RCGCGPIO_R;

   

    GPIO_PORTN_DIR_R = 0x01; //seleccionamos el puerto n numero 0
    GPIO_PORTN_DEN_R = 0x01;
    GPIO_PORTF_AHB_DIR_R = 0x02; //seleccionamos el puerto F numero 1
    GPIO_PORTF_AHB_DEN_R = 0x02;
    GPIO_PORTM_DIR_R = 0x02; //seleccionamos el puerto m numero 1
     GPIO_PORTM_DEN_R = 0x02;

//creacion del loop infinito

    while(1)
    {
       O_PORTF_AHB_DATA_R |= 0x02; //activamos el puerto f
         GPIO_PORTN_DATA_R &= ~(0x01); //apagamos el puerto n
         GPIO_PORTM_DATA_R &= ~(0x02); //apagamos el puerto m
      
        for(ui32Loop = 0; ui32Loop < valor; ui32Loop++) // creamos un loop de x microsegundos 
        //definido por el valor que asociemos a la varible valor
        {
        }

        
         GPIO_PORTN_DATA_R |= 0x01; //encendemos el puerto n
         GPIO_PORTF_AHB_DATA_R &= ~(0x02); //apagamos el puerto f
         GPIO_PORTM_DATA_R |= 0x02; //encendemos el puero m

 
        for(ui32Loop = 0; ui32Loop < valor; ui32Loop++)  //creamos un loop entre la operacion contraria a la pasada para 
   //que mientras unos esten encendidos los otros esten apagados
        {
        }
        
    }
}