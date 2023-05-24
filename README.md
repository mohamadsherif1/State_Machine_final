# State_Machine_final

1) State Machine:
ECU 1 has the following functionality: 
a. Read the input switches (the on-board switches). 
b. Send a command on the CAN network based on the switch's states. 
c. SW1 & 2controls ECU2. 
d. ECU 1 sends a message each 500 ms
ECU 2 has the following functionality 
a. ECU 2 State machine are periodic tasks with 10ms periodicities
b. Read the commands from the CAN networks. 
c. Execute the state machine as the following: 
- Move to the next state (clockwise) whenever the SW1 is pressed
- Move to the next state (anticlockwise) whenever the SW2 is pressed
- If both are pressed. The output on both ECUs will return to (RED)
d. If no state change was identified for more than 5 seconds ECU should go to IDLE state(WHITE)
NOTE: 
I. you are not allowed to use delay functions
II. Switch debouncing is required
ECUs have periodicities of 1 second so they cannot change colors unless after the 1 second window. 


GPIO requirements:
1. Upon reading any switch it is required to use “Dio_ReadChannel” API
2. When turning on/off any Led you must use “Dio_WriteChannel” API
3. Write the needed configurations in Dio such as “DioChannel” container and other needed 
configuration containers.
4. Dio file hierarchy to be followed strictly with the exclusion of “Compiler.h” , “Platform_Types.h”, 
“SchM_Dio.h”, “Det.h”, “Dio_MemMap.h”
5. All dio apis are expected to be implemented (full DIO driver should be present)
Note: The “Dio_Lbcfg.c” will be specific to your application(the static code will not be changed)
