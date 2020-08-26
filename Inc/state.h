#ifndef __STATE
#define __STATE

#define FilterLength 16
typedef struct state
{
    uint64_t uptime;
    uint8_t timer_1s_flag;

    uint8_t error;
    uint8_t cmd;
    uint8_t cmdLoop;
    uint8_t UART_RX_BUFF[UART_RX_BUFFER_LENGTH];

    uint8_t ADC_Channel;
    uint8_t ADC_Updated;
    uint32_t ADC_Values[16];
    uint32_t ADC_ValuesBuffer[FilterLength][16];
    uint32_t ADC_ValuesFiltered[16];
    uint8_t ADC_Filter_Iteration;
    uint8_t ADC_Filter_Valid;

    //PHASE PIDS

    int8_t PD1_Slope;
    int8_t PD2_Slope;
    int8_t PD3_Slope;
    int8_t PD4_Slope;
    int64_t PD1_PD2_SetPoint;
    uint32_t PD1_PD2_Offset; //offset dac value
    int64_t PD1_PD2_MSE;
    int64_t PD3_PD4_SetPoint;
    uint32_t PD3_PD4_Offset; //offset dac value
    int64_t PD3_PD4_MSE;

    uint32_t PID_352_Output;
    int64_t PID_352_P;
    int64_t PID_352_I;
    int64_t PID_352_T;
    int64_t PID_352_P_error;
    int64_t PID_352_I_error;
    int8_t PID_352_LOCK;

    uint32_t PID_704_Output;
    int64_t PID_704_P;
    int64_t PID_704_I;
    int64_t PID_704_T;
    int64_t PID_704_P_error;
    int64_t PID_704_I_error;
    int8_t PID_704_LOCK;

    //POWER PIDS:

    uint32_t POWER_PID_352_SetPoint;
    uint32_t POWER_PID_704_SetPoint;

    uint32_t POWER_PID_352_Output;

    int64_t POWER_PID_352_P;
    int64_t POWER_PID_352_I;
    int64_t POWER_PID_352_T;
    int64_t POWER_PID_352_P_error;
    int64_t POWER_PID_352_I_error;
    int8_t POWER_PID_352_LOCK;

    uint32_t POWER_PID_704_Output;
    uint32_t POWER_PID_704_OutputFINE;

    int64_t POWER_PID_704_P;
    int64_t POWER_PID_704_I;
    int64_t POWER_PID_704_T;
    int64_t POWER_PID_704_P_error;
    int64_t POWER_PID_704_I_error;
    int8_t POWER_PID_704_LOCK;

} state;

#endif /* __STATE */
