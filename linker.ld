ENTRY(Reset_Handler)
MEMORY{

    FLASH(rx): ORIGIN = 0x08000000, LENGTH = 512K /*Flash Memory address*/
    SRAM(rwx): ORIGIN = 0x20000000, LENGTH = 128K /*SRAM Memory address*/
}

SECTIONS{

        /* the order of defining sections matters  dependent on the microcontroller memory map  */
        /* then names of the sections is user defined */

        .text : /* section name is .text in the final executable */
       {    /* the order in which sections are emerging matters dependent on the microcontroller memory map */
            *(.isr_vec) 
            *(.text)    /*to merge all .text section from all .o files */
            *(.rodata)
            . = ALIGN(4);  /*used to allign the memory address*/
            _etext = .; /* linker counter stores the address  of this section */
        }>FLASH AT> FLASH

        .data :
        { 
            _sdata = .; /* start address of the .data section */
            *(.data)
            _edata = .; /* end address of the .data section */
          . = ALIGN(4); /*used to allign the memory address*/
        }> SRAM AT> FLASH

        .bss :
        { 
            _sbss = .;
            *(.bss)
            _ebss = .;
         . = ALIGN(4);
        }>SRAM AT> SRAM
  
}
