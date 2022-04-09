
;============================================================
;		Cuenta pulsos de un buton en el RB4 e incrementa un contador
;		Con 5 pulsos se activa RB0 led rojo
;=============================================================
; __config 0xFF32
 __CONFIG _FOSC_HS & _WDTE_OFF & _PWRTE_ON & _BOREN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _CP_OFF
 
	    LIST	    p=16F873A
	    INCLUDE	    <P16F873A.INC>
	    INCLUDE	    <MACROPIC.INC>
	    
	    CBLOCK	    0x20
	    CONTADOR
	    ENDC

	    ORG 0
	
;--------------- Configuración Inicial ------------------

	    BANCO	    1	    
	    MOV		    TRISB, B'11110000'
	    BANCO	    0
	    
	    clrf	    PORTB
	    clrf	    CONTADOR

loop
	    btfsc	    PORTB,4		;Salta a incrementa si RB4 = 0
	    goto	    loop
	    
;****** Rutina para incrementar contador **********

	    btfss	    PORTB,4
	    goto	    $-.1		;Espera que suelten un pulsador
	  
	    incf	    CONTADOR,F		;Incrementa contador
	    
	    CJE		    CONTADOR, .5, encender_led
	    CJE		    CONTADOR, .10, encender_led1
	    goto	    loop

;************* Encender Led *******************
	    
encender_led
	    
	    bsf		    PORTB,0		;Activa RB0 y regresa
	    goto	    loop

encender_led1	    
	    
	      
	    bsf		    PORTB,1		;Activa RB0 y regresa
	    goto	    loop
	    
	    END