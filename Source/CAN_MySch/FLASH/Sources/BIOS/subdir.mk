################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/BIOS/BIOS_Can.c" \
"../Sources/BIOS/BIOS_Can_Cfg.c" \
"../Sources/BIOS/BIOS_GPIO.c" \
"../Sources/BIOS/BIOS_PIT.c" \
"../Sources/BIOS/BIOS_bspimain.c" \
"../Sources/BIOS/BIOS_sysinit.c" \

C_SRCS += \
../Sources/BIOS/BIOS_Can.c \
../Sources/BIOS/BIOS_Can_Cfg.c \
../Sources/BIOS/BIOS_GPIO.c \
../Sources/BIOS/BIOS_PIT.c \
../Sources/BIOS/BIOS_bspimain.c \
../Sources/BIOS/BIOS_sysinit.c \

OBJS += \
./Sources/BIOS/BIOS_Can_c.obj \
./Sources/BIOS/BIOS_Can_Cfg_c.obj \
./Sources/BIOS/BIOS_GPIO_c.obj \
./Sources/BIOS/BIOS_PIT_c.obj \
./Sources/BIOS/BIOS_bspimain_c.obj \
./Sources/BIOS/BIOS_sysinit_c.obj \

OBJS_QUOTED += \
"./Sources/BIOS/BIOS_Can_c.obj" \
"./Sources/BIOS/BIOS_Can_Cfg_c.obj" \
"./Sources/BIOS/BIOS_GPIO_c.obj" \
"./Sources/BIOS/BIOS_PIT_c.obj" \
"./Sources/BIOS/BIOS_bspimain_c.obj" \
"./Sources/BIOS/BIOS_sysinit_c.obj" \

C_DEPS += \
./Sources/BIOS/BIOS_Can_c.d \
./Sources/BIOS/BIOS_Can_Cfg_c.d \
./Sources/BIOS/BIOS_GPIO_c.d \
./Sources/BIOS/BIOS_PIT_c.d \
./Sources/BIOS/BIOS_bspimain_c.d \
./Sources/BIOS/BIOS_sysinit_c.d \

OBJS_OS_FORMAT += \
./Sources/BIOS/BIOS_Can_c.obj \
./Sources/BIOS/BIOS_Can_Cfg_c.obj \
./Sources/BIOS/BIOS_GPIO_c.obj \
./Sources/BIOS/BIOS_PIT_c.obj \
./Sources/BIOS/BIOS_bspimain_c.obj \
./Sources/BIOS/BIOS_sysinit_c.obj \

C_DEPS_QUOTED += \
"./Sources/BIOS/BIOS_Can_c.d" \
"./Sources/BIOS/BIOS_Can_Cfg_c.d" \
"./Sources/BIOS/BIOS_GPIO_c.d" \
"./Sources/BIOS/BIOS_PIT_c.d" \
"./Sources/BIOS/BIOS_bspimain_c.d" \
"./Sources/BIOS/BIOS_sysinit_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/BIOS/BIOS_Can_c.obj: ../Sources/BIOS/BIOS_Can.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/BIOS/BIOS_Can.args" -o "Sources/BIOS/BIOS_Can_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/BIOS/%.d: ../Sources/BIOS/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/BIOS/BIOS_Can_Cfg_c.obj: ../Sources/BIOS/BIOS_Can_Cfg.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/BIOS/BIOS_Can_Cfg.args" -o "Sources/BIOS/BIOS_Can_Cfg_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/BIOS/BIOS_GPIO_c.obj: ../Sources/BIOS/BIOS_GPIO.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/BIOS/BIOS_GPIO.args" -o "Sources/BIOS/BIOS_GPIO_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/BIOS/BIOS_PIT_c.obj: ../Sources/BIOS/BIOS_PIT.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/BIOS/BIOS_PIT.args" -o "Sources/BIOS/BIOS_PIT_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/BIOS/BIOS_bspimain_c.obj: ../Sources/BIOS/BIOS_bspimain.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/BIOS/BIOS_bspimain.args" -o "Sources/BIOS/BIOS_bspimain_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/BIOS/BIOS_sysinit_c.obj: ../Sources/BIOS/BIOS_sysinit.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/BIOS/BIOS_sysinit.args" -o "Sources/BIOS/BIOS_sysinit_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


