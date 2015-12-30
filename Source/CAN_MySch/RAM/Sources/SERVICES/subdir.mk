################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/SERVICES/SERV_Can_Manager.c" \
"../Sources/SERVICES/SERV_Exceptions.c" \
"../Sources/SERVICES/SERV_IntcInterrupts.c" \
"../Sources/SERVICES/SERV_SchM.c" \
"../Sources/SERVICES/SERV_SchM_Cfg.c" \
"../Sources/SERVICES/SERV_SchM_Tasks.c" \
"../Sources/SERVICES/SERV_ivor_branch_table.c" \

C_SRCS += \
../Sources/SERVICES/SERV_Can_Manager.c \
../Sources/SERVICES/SERV_Exceptions.c \
../Sources/SERVICES/SERV_IntcInterrupts.c \
../Sources/SERVICES/SERV_SchM.c \
../Sources/SERVICES/SERV_SchM_Cfg.c \
../Sources/SERVICES/SERV_SchM_Tasks.c \
../Sources/SERVICES/SERV_ivor_branch_table.c \

OBJS += \
./Sources/SERVICES/SERV_Can_Manager_c.obj \
./Sources/SERVICES/SERV_Exceptions_c.obj \
./Sources/SERVICES/SERV_IntcInterrupts_c.obj \
./Sources/SERVICES/SERV_SchM_c.obj \
./Sources/SERVICES/SERV_SchM_Cfg_c.obj \
./Sources/SERVICES/SERV_SchM_Tasks_c.obj \
./Sources/SERVICES/SERV_ivor_branch_table_c.obj \

OBJS_QUOTED += \
"./Sources/SERVICES/SERV_Can_Manager_c.obj" \
"./Sources/SERVICES/SERV_Exceptions_c.obj" \
"./Sources/SERVICES/SERV_IntcInterrupts_c.obj" \
"./Sources/SERVICES/SERV_SchM_c.obj" \
"./Sources/SERVICES/SERV_SchM_Cfg_c.obj" \
"./Sources/SERVICES/SERV_SchM_Tasks_c.obj" \
"./Sources/SERVICES/SERV_ivor_branch_table_c.obj" \

C_DEPS += \
./Sources/SERVICES/SERV_Can_Manager_c.d \
./Sources/SERVICES/SERV_Exceptions_c.d \
./Sources/SERVICES/SERV_IntcInterrupts_c.d \
./Sources/SERVICES/SERV_SchM_c.d \
./Sources/SERVICES/SERV_SchM_Cfg_c.d \
./Sources/SERVICES/SERV_SchM_Tasks_c.d \
./Sources/SERVICES/SERV_ivor_branch_table_c.d \

OBJS_OS_FORMAT += \
./Sources/SERVICES/SERV_Can_Manager_c.obj \
./Sources/SERVICES/SERV_Exceptions_c.obj \
./Sources/SERVICES/SERV_IntcInterrupts_c.obj \
./Sources/SERVICES/SERV_SchM_c.obj \
./Sources/SERVICES/SERV_SchM_Cfg_c.obj \
./Sources/SERVICES/SERV_SchM_Tasks_c.obj \
./Sources/SERVICES/SERV_ivor_branch_table_c.obj \

C_DEPS_QUOTED += \
"./Sources/SERVICES/SERV_Can_Manager_c.d" \
"./Sources/SERVICES/SERV_Exceptions_c.d" \
"./Sources/SERVICES/SERV_IntcInterrupts_c.d" \
"./Sources/SERVICES/SERV_SchM_c.d" \
"./Sources/SERVICES/SERV_SchM_Cfg_c.d" \
"./Sources/SERVICES/SERV_SchM_Tasks_c.d" \
"./Sources/SERVICES/SERV_ivor_branch_table_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/SERVICES/SERV_Can_Manager_c.obj: ../Sources/SERVICES/SERV_Can_Manager.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/SERVICES/SERV_Can_Manager.args" -o "Sources/SERVICES/SERV_Can_Manager_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/SERVICES/%.d: ../Sources/SERVICES/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/SERVICES/SERV_Exceptions_c.obj: ../Sources/SERVICES/SERV_Exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/SERVICES/SERV_Exceptions.args" -o "Sources/SERVICES/SERV_Exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/SERVICES/SERV_IntcInterrupts_c.obj: ../Sources/SERVICES/SERV_IntcInterrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/SERVICES/SERV_IntcInterrupts.args" -o "Sources/SERVICES/SERV_IntcInterrupts_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/SERVICES/SERV_SchM_c.obj: ../Sources/SERVICES/SERV_SchM.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/SERVICES/SERV_SchM.args" -o "Sources/SERVICES/SERV_SchM_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/SERVICES/SERV_SchM_Cfg_c.obj: ../Sources/SERVICES/SERV_SchM_Cfg.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/SERVICES/SERV_SchM_Cfg.args" -o "Sources/SERVICES/SERV_SchM_Cfg_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/SERVICES/SERV_SchM_Tasks_c.obj: ../Sources/SERVICES/SERV_SchM_Tasks.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/SERVICES/SERV_SchM_Tasks.args" -o "Sources/SERVICES/SERV_SchM_Tasks_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/SERVICES/SERV_ivor_branch_table_c.obj: ../Sources/SERVICES/SERV_ivor_branch_table.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/SERVICES/SERV_ivor_branch_table.args" -o "Sources/SERVICES/SERV_ivor_branch_table_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


