################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/APPLICATION/APP_dummy.c" \

C_SRCS += \
../Sources/APPLICATION/APP_dummy.c \

OBJS += \
./Sources/APPLICATION/APP_dummy_c.obj \

OBJS_QUOTED += \
"./Sources/APPLICATION/APP_dummy_c.obj" \

C_DEPS += \
./Sources/APPLICATION/APP_dummy_c.d \

OBJS_OS_FORMAT += \
./Sources/APPLICATION/APP_dummy_c.obj \

C_DEPS_QUOTED += \
"./Sources/APPLICATION/APP_dummy_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/APPLICATION/APP_dummy_c.obj: ../Sources/APPLICATION/APP_dummy.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/APPLICATION/APP_dummy.args" -o "Sources/APPLICATION/APP_dummy_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/APPLICATION/%.d: ../Sources/APPLICATION/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


