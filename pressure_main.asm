_InitTimer2:
;pressure_main.c,24 :: 		void InitTimer2(){
SUB	SP, SP, #4
STR	LR, [SP, #0]
;pressure_main.c,25 :: 		RCC_APB1ENR.TIM2EN = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(RCC_APB1ENR+0)
MOVT	R0, #hi_addr(RCC_APB1ENR+0)
_SX	[R0, ByteOffset(RCC_APB1ENR+0)]
;pressure_main.c,26 :: 		TIM2_CR1.CEN = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(TIM2_CR1+0)
MOVT	R0, #hi_addr(TIM2_CR1+0)
_SX	[R0, ByteOffset(TIM2_CR1+0)]
;pressure_main.c,27 :: 		TIM2_PSC = 279;
MOVW	R1, #279
MOVW	R0, #lo_addr(TIM2_PSC+0)
MOVT	R0, #hi_addr(TIM2_PSC+0)
STR	R1, [R0, #0]
;pressure_main.c,28 :: 		TIM2_ARR = 59999;
MOVW	R1, #59999
MOVW	R0, #lo_addr(TIM2_ARR+0)
MOVT	R0, #hi_addr(TIM2_ARR+0)
STR	R1, [R0, #0]
;pressure_main.c,29 :: 		NVIC_IntEnable(IVT_INT_TIM2);
MOVW	R0, #44
BL	_NVIC_IntEnable+0
;pressure_main.c,30 :: 		TIM2_DIER.UIE = 1;
MOVS	R1, #1
SXTB	R1, R1
MOVW	R0, #lo_addr(TIM2_DIER+0)
MOVT	R0, #hi_addr(TIM2_DIER+0)
_SX	[R0, ByteOffset(TIM2_DIER+0)]
;pressure_main.c,31 :: 		TIM2_CR1.CEN = 1;
MOVW	R0, #lo_addr(TIM2_CR1+0)
MOVT	R0, #hi_addr(TIM2_CR1+0)
_SX	[R0, ByteOffset(TIM2_CR1+0)]
;pressure_main.c,32 :: 		}
L_end_InitTimer2:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _InitTimer2
_systemInit:
;pressure_main.c,35 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;pressure_main.c,40 :: 		mikrobus_logInit( _MIKROBUS1, 9600 );
MOVW	R1, #9600
MOVS	R0, #0
BL	_mikrobus_logInit+0
;pressure_main.c,41 :: 		mikrobus_logWrite("--- System Init ---", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_pressure_main+0)
MOVT	R0, #hi_addr(?lstr1_pressure_main+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;pressure_main.c,42 :: 		Delay_ms( 100 );
MOVW	R7, #29438
MOVT	R7, #85
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;pressure_main.c,43 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;pressure_main.c,45 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;pressure_main.c,50 :: 		InitTimer2();
BL	_InitTimer2+0
;pressure_main.c,51 :: 		ADC1_Init();
BL	_ADC1_Init+0
;pressure_main.c,52 :: 		ADC_Set_Input_Channel( _ADC_CHANNEL_4);
MOVW	R0, #16
BL	_ADC_Set_Input_Channel+0
;pressure_main.c,53 :: 		Delay_ms(200);
MOVW	R7, #58878
MOVT	R7, #170
NOP
NOP
L_applicationInit2:
SUBS	R7, R7, #1
BNE	L_applicationInit2
NOP
NOP
NOP
;pressure_main.c,54 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_bingkai:
;pressure_main.c,56 :: 		void bingkai(unsigned dat)
SUB	SP, SP, #8
STR	LR, [SP, #0]
STRH	R0, [SP, #4]
;pressure_main.c,58 :: 		x = 350;y = 110;
MOVW	R2, #350
SXTH	R2, R2
MOVW	R1, #lo_addr(_x+0)
MOVT	R1, #hi_addr(_x+0)
STRH	R2, [R1, #0]
MOVS	R2, #110
SXTH	R2, R2
MOVW	R1, #lo_addr(_y+0)
MOVT	R1, #hi_addr(_y+0)
STRH	R2, [R1, #0]
;pressure_main.c,59 :: 		TFT_Set_Pen(CL_BLACK, 1);
MOVS	R1, #1
MOVW	R0, #0
BL	_TFT_Set_Pen+0
;pressure_main.c,60 :: 		TFT_Set_Brush(1, 0,0, LEFT_TO_RIGHT, CL_BLACK, CL_BLACK);
MOVW	R2, #0
MOVW	R1, #0
PUSH	(R2)
PUSH	(R1)
MOVS	R3, #1
MOVS	R2, #0
MOVS	R1, #0
MOVS	R0, #1
BL	_TFT_Set_Brush+0
ADD	SP, SP, #8
;pressure_main.c,61 :: 		TFT_Rectangle(x, y, x+110, y+100);
MOVW	R2, #lo_addr(_y+0)
MOVT	R2, #hi_addr(_y+0)
LDRSH	R1, [R2, #0]
ADDW	R5, R1, #100
MOVW	R4, #lo_addr(_x+0)
MOVT	R4, #hi_addr(_x+0)
LDRSH	R1, [R4, #0]
ADDW	R3, R1, #110
MOV	R1, R2
LDRSH	R2, [R1, #0]
MOV	R1, R4
LDRSH	R1, [R1, #0]
SXTH	R0, R1
SXTH	R1, R2
SXTH	R2, R3
SXTH	R3, R5
BL	_TFT_Rectangle+0
;pressure_main.c,62 :: 		TFT_Set_Pen(CL_WHITE, 5);
MOVS	R1, #5
MOVW	R0, #65535
BL	_TFT_Set_Pen+0
;pressure_main.c,63 :: 		TFT_Set_Font(Tahoma26x33_Regular, CL_WHITE, FO_HORIZONTAL);
MOVW	R1, #lo_addr(_Tahoma26x33_Regular+0)
MOVT	R1, #hi_addr(_Tahoma26x33_Regular+0)
MOVS	R2, #0
MOV	R0, R1
MOVW	R1, #65535
BL	_TFT_Set_Font+0
;pressure_main.c,64 :: 		FloatToStr(dat, text );
LDRH	R1, [SP, #4]
VMOV	S0, R1
VCVT.F32	#0, S0, S0
MOVW	R0, #lo_addr(_text+0)
MOVT	R0, #hi_addr(_text+0)
BL	_FloatToStr+0
;pressure_main.c,65 :: 		TFT_Write_Text(text, x, y);
MOVW	R1, #lo_addr(_y+0)
MOVT	R1, #hi_addr(_y+0)
LDRSH	R2, [R1, #0]
MOVW	R1, #lo_addr(_x+0)
MOVT	R1, #hi_addr(_x+0)
LDRSH	R1, [R1, #0]
MOVW	R0, #lo_addr(_text+0)
MOVT	R0, #hi_addr(_text+0)
BL	_TFT_Write_Text+0
;pressure_main.c,66 :: 		Delay_ms(10);
MOVW	R7, #35710
MOVT	R7, #8
NOP
NOP
L_bingkai4:
SUBS	R7, R7, #1
BNE	L_bingkai4
NOP
NOP
NOP
;pressure_main.c,67 :: 		}
L_end_bingkai:
LDR	LR, [SP, #0]
ADD	SP, SP, #8
BX	LR
; end of _bingkai
_applicationTask:
;pressure_main.c,69 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;pressure_main.c,71 :: 		readADC = ADC1_Get_Sample(4);
MOVS	R0, #4
BL	_ADC1_Get_Sample+0
VMOV	S1, R0
VCVT.F32	#0, S1, S1
MOVW	R0, #lo_addr(_readADC+0)
MOVT	R0, #hi_addr(_readADC+0)
VSTR	#1, S1, [R0, #0]
;pressure_main.c,72 :: 		press = (float)(readADC*(3.3/4095));
MOVW	R0, #16487
MOVT	R0, #14931
VMOV	S0, R0
VMUL.F32	S1, S1, S0
MOVW	R0, #lo_addr(_press+0)
MOVT	R0, #hi_addr(_press+0)
VSTR	#1, S1, [R0, #0]
;pressure_main.c,74 :: 		PressureData = (press/3.3)*25.0;
MOVW	R0, #13107
MOVT	R0, #16467
VMOV	S0, R0
VDIV.F32	S1, S1, S0
VMOV.F32	S0, #25
VMUL.F32	S0, S1, S0
MOVW	R0, #lo_addr(_PressureData+0)
MOVT	R0, #hi_addr(_PressureData+0)
VSTR	#1, S0, [R0, #0]
;pressure_main.c,76 :: 		FloatToStr(PressureData, demoText);
VMOV.F32	S0, S0
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;pressure_main.c,77 :: 		bingkai(   PressureData  );
MOVW	R0, #lo_addr(_PressureData+0)
MOVT	R0, #hi_addr(_PressureData+0)
VLDR	#1, S0, [R0, #0]
VCVT	#1, .F32, S0, S0
VMOV	R0, S0
UXTH	R0, R0
BL	_bingkai+0
;pressure_main.c,83 :: 		mikrobus_logWrite(" Pressure data : ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr2_pressure_main+0)
MOVT	R0, #hi_addr(?lstr2_pressure_main+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;pressure_main.c,84 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;pressure_main.c,85 :: 		mikrobus_logWrite(" mBar", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr3_pressure_main+0)
MOVT	R0, #hi_addr(?lstr3_pressure_main+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;pressure_main.c,86 :: 		Delay_ms( 1000 );
MOVW	R7, #32254
MOVT	R7, #854
NOP
NOP
L_applicationTask6:
SUBS	R7, R7, #1
BNE	L_applicationTask6
NOP
NOP
NOP
;pressure_main.c,87 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_Timer2_interrupt:
;pressure_main.c,89 :: 		void Timer2_interrupt() iv IVT_INT_TIM2 {
;pressure_main.c,90 :: 		TIM2_SR.UIF = 0;
MOVS	R1, #0
SXTB	R1, R1
MOVW	R0, #lo_addr(TIM2_SR+0)
MOVT	R0, #hi_addr(TIM2_SR+0)
_SX	[R0, ByteOffset(TIM2_SR+0)]
;pressure_main.c,92 :: 		}
L_end_Timer2_interrupt:
BX	LR
; end of _Timer2_interrupt
_main:
;pressure_main.c,94 :: 		void main() {
;pressure_main.c,95 :: 		Start_TP();
BL	_Start_TP+0
;pressure_main.c,96 :: 		systemInit();
BL	_systemInit+0
;pressure_main.c,97 :: 		applicationInit();
BL	_applicationInit+0
;pressure_main.c,99 :: 		while (1) {
L_main8:
;pressure_main.c,101 :: 		applicationTask();
BL	_applicationTask+0
;pressure_main.c,102 :: 		}
IT	AL
BAL	L_main8
;pressure_main.c,103 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
