################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/comment.c \
../src/filtros.c \
../src/header.c \
../src/image.c \
../src/mallocc.c \
../src/mask.c \
../src/matrix.c \
../src/particiona.c \
../src/prog.c \
../src/quicksort.c 

OBJS += \
./src/comment.o \
./src/filtros.o \
./src/header.o \
./src/image.o \
./src/mallocc.o \
./src/mask.o \
./src/matrix.o \
./src/particiona.o \
./src/prog.o \
./src/quicksort.o 

C_DEPS += \
./src/comment.d \
./src/filtros.d \
./src/header.d \
./src/image.d \
./src/mallocc.d \
./src/mask.d \
./src/matrix.d \
./src/particiona.d \
./src/prog.d \
./src/quicksort.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


