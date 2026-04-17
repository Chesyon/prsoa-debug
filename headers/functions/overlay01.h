#ifndef HEADERS_FUNCTIONS_OVERLAY01_H_
#define HEADERS_FUNCTIONS_OVERLAY01_H_
struct battle_struct* Overlay1EntryPoint(struct battle_struct* param_1, struct megastruct* param_2);
undefined4 BattleStateManager(struct battle_struct* param_1, undefined4 param_2, int param_3,
                              int* param_4);
undefined4 BattleBannerGraphicFrameUpdate(struct battle_struct* param_1);
undefined4 BattleActiveFrameUpdate(struct battle_struct* param_1, undefined4 param_2,
                                   undefined4 param_3, undefined4 param_4);
undefined4 BattleVerifyFleeFrameUpdate(struct battle_struct* param_1);
undefined4 BattleViewPartyFrameUpdate(struct battle_struct* param_1);
undefined4 BattleHandleWinFrameUpdate(struct battle_struct* param_1);
undefined4 BattleHandleLossFrameUpdate(struct battle_struct* param_1, undefined4 param_2,
                                       int param_3, int* param_4);
undefined4 EndBattleFrameUpdate(struct battle_struct* param_1);
undefined4 RegisterInBrowserFrameUpdate(struct battle_struct* param_1, undefined4 param_2,
                                        undefined4 param_3, undefined4 param_4);
undefined4 FightVictoryCheerFrameUpdate(struct battle_struct* param_1);
void FreeBattlePokemonSlot(struct battle_struct* param_1, int param_2);
void UpdateBrowserLifetimeCaughtAndMore(struct battle_struct* param_1, undefined4 param_2,
                                        undefined4 param_3, undefined4 param_4);
void ret_02123770(void);
void ret_021293d4(void);
undefined4 SysCallPrintTextboxByBattleMessageId1(undefined4* param_1);
undefined4 SysCallPrintTextboxByBattleMessageId2(undefined4* param_1);
void SysCallIsTextboxPrintingBattle(void);
undefined4 SysCallCloseTextboxBattle(void);
void ret_0212c028(void);
void ret_0212e524(void);
void ret_0212e888(void);
void ret_0212ee20(void);
void ret_0212ee38(void);
void ret_02130b70(void);
void ret_02131b44(void);
void ret_02133c04(void);
void ret_02134350(void);
void ret_02136244(void);
void ret_021368f8(void);
void ret_02136ae8(void);
void ret_02137b90(void);
void ret_02137b94(void);
void ret_0213ae14(void);
struct interface_file_manager* InitInterfaceFileManagerOuter(struct interface_file_manager* param_1,
                                                             char* param_2, char* param_3);
void InitInterfaceFileManagerInner(struct interface_file_manager* param_1, char* param_2,
                                   char* param_3);
#endif
