################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
src/CONTROL.obj: C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src/CONTROL.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/Project_CCS/vending_machine" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/utils" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/include" --define=ccs="ccs" --define=UART_BUFFERED --define=ARM_PLATFORM --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/CONTROL.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/DATE_TIME.obj: C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src/DATE_TIME.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/Project_CCS/vending_machine" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/utils" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/include" --define=ccs="ccs" --define=UART_BUFFERED --define=ARM_PLATFORM --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/DATE_TIME.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/DISPLAY.obj: C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src/DISPLAY.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/Project_CCS/vending_machine" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/utils" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/include" --define=ccs="ccs" --define=UART_BUFFERED --define=ARM_PLATFORM --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/DISPLAY.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/FSM.obj: C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src/FSM.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/Project_CCS/vending_machine" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/utils" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/include" --define=ccs="ccs" --define=UART_BUFFERED --define=ARM_PLATFORM --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/FSM.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/GPIO_UC.obj: C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src/GPIO_UC.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/Project_CCS/vending_machine" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/utils" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/include" --define=ccs="ccs" --define=UART_BUFFERED --define=ARM_PLATFORM --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/GPIO_UC.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/IO.obj: C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src/IO.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/Project_CCS/vending_machine" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/utils" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/include" --define=ccs="ccs" --define=UART_BUFFERED --define=ARM_PLATFORM --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/IO.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/LCD_NHDC12864.obj: C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src/LCD_NHDC12864.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/Project_CCS/vending_machine" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/utils" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/include" --define=ccs="ccs" --define=UART_BUFFERED --define=ARM_PLATFORM --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/LCD_NHDC12864.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/LCD_UC.obj: C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src/LCD_UC.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/Project_CCS/vending_machine" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/utils" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/include" --define=ccs="ccs" --define=UART_BUFFERED --define=ARM_PLATFORM --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/LCD_UC.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/RTC_UC.obj: C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src/RTC_UC.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/Project_CCS/vending_machine" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/utils" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/include" --define=ccs="ccs" --define=UART_BUFFERED --define=ARM_PLATFORM --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/RTC_UC.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/TERMINAL.obj: C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src/TERMINAL.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/Project_CCS/vending_machine" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/utils" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/include" --define=ccs="ccs" --define=UART_BUFFERED --define=ARM_PLATFORM --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/TERMINAL.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/UART_UC.obj: C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src/UART_UC.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/Project_CCS/vending_machine" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/utils" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/include" --define=ccs="ccs" --define=UART_BUFFERED --define=ARM_PLATFORM --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/UART_UC.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/main.obj: C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src/main.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/Project_CCS/vending_machine" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/utils" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/include" --define=ccs="ccs" --define=UART_BUFFERED --define=ARM_PLATFORM --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/main.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/tm4c123gh6pm_startup_ccs.obj: ../src/tm4c123gh6pm_startup_ccs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/Project_CCS/vending_machine" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/utils" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/include" --define=ccs="ccs" --define=UART_BUFFERED --define=ARM_PLATFORM --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/tm4c123gh6pm_startup_ccs.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

src/uartstdio.obj: C:/ti/TivaWare_C_Series-2.1.4.178/utils/uartstdio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/Project_CCS/vending_machine" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/User/Dropbox/UFSC/2018.2/OO/Projeto_Final/fw/src" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/utils" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.9.0.STS/include" --define=ccs="ccs" --define=UART_BUFFERED --define=ARM_PLATFORM --define=TARGET_IS_TM4C123_RB1 --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="src/uartstdio.d_raw" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


