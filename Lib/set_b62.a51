NAME	SETB_62

;?PR?set_b62?SET_B62    SEGMENT CODE
        PUBLIC	set_b62

;        RSEG    ?PR?set_b62?SET_B62
        
        CSEG    AT      18H
set_b62:
        MOV     DPTR,#8B62h
        MOVX    A,@DPTR	  
        ORL     A,#01h
        MOVX    @DPTR,A
        RET

        END
