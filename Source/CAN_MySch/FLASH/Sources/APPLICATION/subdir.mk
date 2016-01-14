################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/APPLICATION/APP_Basic_Enhanced_Cmd_Telltale.c" \
"../Sources/APPLICATION/APP_Passenger_Seatbealt_Bassic.c" \
"../Sources/APPLICATION/APP_SBR_Driver.c" \
"../Sources/APPLICATION/APP_Sensors_Flags.c" \

C_SRCS += \
../Sources/APPLICATION/APP_Basic_Enhanced_Cmd_Telltale.c \
../Sources/APPLICATION/APP_Passenger_Seatbealt_Bassic.c \
../Sources/APPLICATION/APP_SBR_Driver.c \
../Sources/APPLICATION/APP_Sensors_Flags.c \

OBJS += \
./Sources/APPLICATION/APP_Basic_Enhanced_Cmd_Telltale_c.obj \
./Sources/APPLICATION/APP_Passenger_Seatbealt_Bassic_c.obj \
./Sources/APPLICATION/APP_SBR_Driver_c.obj \
./Sources/APPLICATION/APP_Sensors_Flags_c.obj \

OBJS_QUOTED += \
"./Sources/APPLICATION/APP_Basic_Enhanced_Cmd_Telltale_c.obj" \
"./Sources/APPLICATION/APP_Passenger_Seatbealt_Bassic_c.obj" \
"./Sources/APPLICATION/APP_SBR_Driver_c.obj" \
"./Sources/APPLICATION/APP_Sensors_Flags_c.obj" \

C_DEPS += \
./Sources/APPLICATION/APP_Basic_Enhanced_Cmd_Telltale_c.d \
./Sources/APPLICATION/APP_Passenger_Seatbealt_Bassic_c.d \
./Sources/APPLICATION/APP_SBR_Driver_c.d \
./Sources/APPLICATION/APP_Sensors_Flags_c.d \

OBJS_OS_FORMAT += \
./Sources/APPLICATION/APP_Basic_Enhanced_Cmd_Telltale_c.obj \
./Sources/APPLICATION/APP_Passenger_Seatbealt_Bassic_c.obj \
./Sources/APPLICATION/APP_SBR_Driver_c.obj \
./Sources/APPLICATION/APP_Sensors_Flags_c.obj \

C_DEPS_QUOTED += \
"./Sources/APPLICATION/APP_Basic_Enhanced_Cmd_Telltale_c.d" \
"./Sources/APPLICATION/APP_Passenger_Seatbealt_Bassic_c.d" \
"./Sources/APPLICATION/APP_SBR_Driver_c.d" \
"./Sources/APPLICATION/APP_Sensors_Flags_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/APPLICATION/APP_Basic_Enhanced_Cmd_Telltale_c.obj: ../Sources/APPLICATION/APP_Basic_Enhanced_Cmd_Telltale.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/APPLICATION/APP_Basic_Enhanced_Cmd_Telltale.args" -o "Sources/APPLICATION/APP_Basic_Enhanced_Cmd_Telltale_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/APPLICATION/%.d: ../Sources/APPLICATION/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/APPLICATION/APP_Passenger_Seatbealt_Bassic_c.obj: ../Sources/APPLICATION/APP_Passenger_Seatbealt_Bassic.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/APPLICATION/APP_Passenger_Seatbealt_Bassic.args" -o "Sources/APPLICATION/APP_Passenger_Seatbealt_Bassic_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/APPLICATION/APP_SBR_Driver_c.obj: ../Sources/APPLICATION/APP_SBR_Driver.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/APPLICATION/APP_SBR_Driver.args" -o "Sources/APPLICATION/APP_SBR_Driver_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/APPLICATION/APP_Sensors_Flags_c.obj: ../Sources/APPLICATION/APP_Sensors_Flags.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/APPLICATION/APP_Sensors_Flags.args" -o "Sources/APPLICATION/APP_Sensors_Flags_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


