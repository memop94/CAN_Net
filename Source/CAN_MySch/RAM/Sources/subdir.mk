################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/MemAlloc.c" \
"../Sources/MemAlloc_Cfg.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/MemAlloc.c \
../Sources/MemAlloc_Cfg.c \
../Sources/main.c \

OBJS += \
./Sources/MemAlloc_c.obj \
./Sources/MemAlloc_Cfg_c.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/MemAlloc_c.obj" \
"./Sources/MemAlloc_Cfg_c.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/MemAlloc_c.d \
./Sources/MemAlloc_Cfg_c.d \
./Sources/main_c.d \

OBJS_OS_FORMAT += \
./Sources/MemAlloc_c.obj \
./Sources/MemAlloc_Cfg_c.obj \
./Sources/main_c.obj \

C_DEPS_QUOTED += \
"./Sources/MemAlloc_c.d" \
"./Sources/MemAlloc_Cfg_c.d" \
"./Sources/main_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/MemAlloc_c.obj: ../Sources/MemAlloc.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/MemAlloc.args" -o "Sources/MemAlloc_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/MemAlloc_Cfg_c.obj: ../Sources/MemAlloc_Cfg.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/MemAlloc_Cfg.args" -o "Sources/MemAlloc_Cfg_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


