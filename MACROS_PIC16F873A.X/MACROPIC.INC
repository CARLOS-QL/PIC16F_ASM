;********************************************************
;*     	Macropic.inc 1.2                        	*
;*    	Version:  1.0                                  	*                             
;********************************************************


;*********** Para cambiar de banco de memoria RAM **************

BANCO	macro	x
	if x == 0
		bcf	STATUS,RP0
		bcf	STATUS,RP1
	endif
	if x == 1
		bsf	STATUS,RP0
		bcf	STATUS,RP1
	endif
	if x == 2
		bcf	STATUS,RP0
		bsf	STATUS,RP1
	endif
	if x == 3
		bsf	STATUS,RP0
		bsf	STATUS,RP1
	endif
	endm

;*********** Para cambiar de página en memoria FLASH **************

PAGINA	macro	x
	if x == 0
		bcf	PCLATH,3
		bcf	PCLATH,4
	endif
	if x == 1
		bsf	PCLATH,3
		bcf	PCLATH,4
	endif
	if x == 2
		bcf	PCLATH,3
		bsf	PCLATH,4
	endif
	if x == 3
		bsf	PCLATH,3
		bsf	PCLATH,4
	endif
	endm

;********** Mover un dato a un registro ***************

MOV		macro	registro, literal
		movlw	literal
		movwf	registro
		endm

;********** Movrer el dato de un registro a otro **********

MOVR		macro	registro1,registro2
		movf	registro2,0
		movwf	registro1
		endm

;************* Compara y salta a la dirección si no es igual, el dato al registro *****************

CJNE	macro	registro,dato,direcc
	movlw	dato
	subwf	registro,0
	btfss	STATUS,Z
	goto	direcc
	endm

;************ Compara y salta a la dirección si es igual, el dato al registro *****************

CJE	macro	registro, dato, direcc
	movlw	dato
	subwf	registro,0
	btfsc	STATUS,Z
	goto	direcc
	endm

;************** Salta a la dirección si el Bit del Registro es  1 *********************

JBS	MACRO	Reg, Bit, Adr	;saltar si bit esta seteado
	btfsc	Reg, Bit
	goto	Adr	
	endm


;************** Salta a la dirección si el Bit del Registro es  0 *********************

JBC	MACRO	Reg, Bit, Adr	;saltar si bit esta aclarado
	btfss	Reg, Bit
	goto	Adr	
	endm


				