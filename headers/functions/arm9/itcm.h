#ifndef HEADERS_FUNCTIONS_ARM9_ITCM_H_
#define HEADERS_FUNCTIONS_ARM9_ITCM_H_
void OSi_DoResetSystem(void);
void OSi_DoBoot(void);
void OSi_CpuClear32(undefined4 param_1, undefined4* param_2, int32_t param_3);
void OSi_ReloadRomData(void);
void OSi_ReadCardRom32(unsigned int param_1, int param_2, int param_3);
void MIi_DmaSetParams(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);
void MIi_DmaSetParams_wait(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);
void MIi_DmaSetParams_src32(int param_1, undefined4 param_2, undefined4 param_3,
                            undefined4 param_4);
undefined4 MIi_DmaSetParams_wait_src32(int param_1, undefined4 param_2, undefined4 param_3,
                                       undefined4 param_4);
void MI_SendGXCommand(int param_1, int param_2, unsigned int param_3, undefined4 param_4);
void OSi_DoResetSystem(void);
void OSi_DoBoot(void);
void OSi_CpuClear32(undefined4 param_1, undefined4* param_2, int param_3);
void OSi_ReloadRomData(void);
void OSi_ReadCardRom32(unsigned int param_1, int param_2, int param_3);
void MIi_DmaSetParams(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);
void MIi_DmaSetParams_wait(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4);
undefined4 MIi_DmaSetParams_wait_src32(int param_1, undefined4 param_2, undefined4 param_3,
                                       undefined4 param_4);
#endif