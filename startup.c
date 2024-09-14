#include<stdint.h>
#define SRAM_START  0x20000000U
#define SRAM_END    (SRAM_START + 128*1024)
void Reset_Handler(void);
void NMI_Handler(void)   __attribute__ ((weak,alias("Default_Handler")));
int main(void);

extern uint32_t _edata;
extern uint32_t _sdata;
extern uint32_t _etext;
extern uint32_t _sbss;
extern uint32_t _ebss;

/*__attribute__ ((section(".isr_vec"))) will create a section .isr_vec(user dependent) stores their instead of storing in .data*/
uint32_t InterruptVectorTable[101] __attribute__ ((section(".isr_vec"))) = {

        SRAM_START,
        (uint32_t)&Reset_Handler,
        (uint32_t)&NMI_Handler,
      /* rest need to add refering to microcontroller Interrupt vector table */

};

void Reset_Handler(void){

    /* copy the data from .data(FLASH) to .data(SRAM) */
    uint32_t size = &_edata - &_sdata;
    uint32_t * ptrSrc = &_etext;
    uint32_t * ptrDes = &_sdata;
    for(int i=0;i<size;i++){
        ptrDes[i] = ptrSrc[i];
    }
    size = &_ebss - &_sbss;
    ptrDes = &_sbss;

    /* Initialise the .bss section */
      for(int i=0;i<size;i++){
        ptrDes[i] = 0 ;
    }

    /*Calling main function*/
    main();

}

void Default_Handler(void){
    while(1);
}



