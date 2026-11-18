// ===== f_ext_reserved @ 06001dba

/* B2: strings referenced by this function (disasm/function_strings.json):
     "EXT_RESERVED" */

void f_ext_reserved(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  op_push_rets_rl();
  if ((param_2 != 0) && (param_3 != 2)) {
    param_1 = param_1 + 0xd;
  }
  uVar1 = op_ext_b0_u(param_1);
                    /* WARNING: Subroutine does not return */
  FUN_0600b47e(0,s_EXT_RESERVED_060621d0 + 0xb,uVar1);
}


// ===== f_trebshelf_lb3 @ 06001df2

/* B4.2 rename (string); evidence: disasm/b42_manifest.json; strings:
     "TrebShelf_LB3"
     "TrebShelf_LB4"
     "Desk_Acoustic"
     "AUX_DAC_GAIN2"
     "Vol_BtmMusic2"
     "Vol_LinMusic2"
     "DUT+TST+TXS+0"
     "DUT+TST+TXS+1"
     "DUT+TST+DUT+0"
     "TST+LED+IO1+1" */

void f_trebshelf_lb3(undefined4 param_1)

{
  op_push_rets_rl();
                    /* WARNING: Subroutine does not return */
  FUN_0600b47e(0,s_BassShelf_LB4_060621eb + 0xc,param_1);
}


// ===== f_trebshelf_lb4 @ 06001e12

/* B2: strings referenced by this function (disasm/function_strings.json):
     "TrebShelf_LB4" */

void f_trebshelf_lb4(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  op_push_rets_rl();
  if (param_3 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0600b47e(0,s_TrebShelf_LB4_06062207 + 0xc,10);
  }
  if (param_1 != 0) {
    param_2 = param_2 + 5;
  }
  uVar1 = op_ext_b0_u(param_2);
                    /* WARNING: Subroutine does not return */
  FUN_0600b47e(0,s_TrebShelf_LB4_06062207 + 0xc,uVar1);
}


// ===== f_aux_dac_gain @ 06001e50

/* B4.2 rename (string); evidence: disasm/b42_manifest.json; strings:
     "AUX_DAC_GAIN"
     "SET_HP_GAIN2"
     "EnergyMusic2"
     "tone_zh/bt.*"
     "Vol_BtmMusic"
     "config397392"
     "Vol_LinMusic"
     "1234567890abcTST+DUT+TXS+"
     "TST+DUT+SAV+" */

void f_aux_dac_gain(int param_1)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  
  op_push_rets_rl();
  uVar1 = (uint)(param_1 == 0);
  iVar2 = 0x606214c;
  FUN_0600b5ae(0,0x606214c,uVar1);
  iVar2 = FUN_0600b5ae(0,iVar2 + 0xd5,uVar1);
  op_pop_pc_rl();
  op_push_rets_rl();
  uVar1 = (uint)(iVar2 != 0);
  pcVar3 = s_jlstream___06062069 + 9;
  FUN_0600b5ae(0,s_jlstream___06062069 + 9,uVar1);
  FUN_0600b5ae(0,pcVar3 + 0xe7,uVar1);
  op_pop_pc_rl();
  *(undefined4 *)((int)in_sp + -4) = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06001412();
}


// ===== f_jlstream @ 06001e76

/* B2: strings referenced by this function (disasm/function_strings.json):
     "jlstream_*" */

void f_jlstream(int param_1)

{
  uint uVar1;
  char *pcVar2;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  
  op_push_rets_rl();
  uVar1 = (uint)(param_1 != 0);
  pcVar2 = s_jlstream___06062069 + 9;
  FUN_0600b5ae(0,s_jlstream___06062069 + 9,uVar1);
  FUN_0600b5ae(0,pcVar2 + 0xe7,uVar1);
  op_pop_pc_rl();
  *(undefined4 *)((int)in_sp + -4) = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06001412();
}


// ===== f_user_system @ 06005cc8

/* B2: strings referenced by this function (disasm/function_strings.json):
     "user_system" */

bool f_user_system(void)

{
  return iRam001061e4 != 0;
}


// ===== f_mixer7 @ 0600a0b6

/* B2: strings referenced by this function (disasm/function_strings.json):
     "MIXER7" */

void f_mixer7(void)

{
  undefined4 uVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  op_push_rets_rl();
  iVar4 = 0x106060;
  if (iRam001061f0 == 0) goto LAB_0600a0ca;
  do {
    op_pop_pc_rl();
LAB_0600a0ca:
    pcVar6 = s_MIXER7_06061eae + 5;
    uVar1 = FUN_06007f3e(0xf,s_MIXER7_06061eae + 5);
    iVar5 = op_ext_l_u(uVar1);
  } while ((iVar5 == 0) || (piVar2 = (int *)FUN_0010fec2(8), piVar2 == (int *)0x0));
  *(undefined1 *)(piVar2 + 1) = 6;
  pcVar3 = pcVar6 + 0x125;
  if (*(char *)(iVar4 + 0x875) != '\0') {
    pcVar3 = pcVar6 + 0x12e;
  }
  iVar5 = FUN_06038c36(iVar5,pcVar3);
  *piVar2 = iVar5;
  if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0010fed0(piVar2);
  }
  if (*(char *)(iVar4 + 0x1c) == '\0') {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_060389ae(0x1100,0x2000d,0xc0);
  }
  if ((*(char *)(iVar4 + 0x885) == '\0') && (*(char *)(iVar4 + 0x886) != '\0')) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_060389ae(0x1100,0x2000d,0x240);
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_060389ae(0x1100,0x2000d,0x180);
}


// ===== f_mixer7 @ 0600b0a4

/* B2: strings referenced by this function (disasm/function_strings.json):
     "MIXER7" */

void f_mixer7(undefined1 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  
  op_push_rets_rl();
  if (puRam001061f0 != (undefined4 *)0x0) {
    puVar3 = puRam001061f0;
    FUN_06038bc0(*puRam001061f0);
    FUN_060380ae(*puVar3);
                    /* WARNING: Subroutine does not return */
    FUN_0010fed0(puVar3);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar5 = 0x106060;
  puVar4 = puRam001061e4;
  uVar1 = FUN_06007f3e(0xf);
  if (puVar4 != (undefined1 *)0x0) {
    if (*(int *)(puVar4 + 0xc) == 0) {
      if (*(short *)(puVar4 + 6) != 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0602b752();
      }
      rep_unspec(4,6);
      *puVar4 = *param_1;
      uVar1 = op_uextra_rrii(uVar1,0,0x10);
      iVar2 = FUN_06038c36(uVar1);
      *(int *)(puVar4 + 0xc) = iVar2;
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0602b6f8(0,200);
      }
      iVar5 = *(int *)(iVar5 + 0x184);
      *(undefined1 *)(iVar5 + 8) = 6;
      FUN_06038540(*(undefined4 *)(iVar5 + 0xc),&LAB_06017956);
      FUN_06038998(*(undefined4 *)(iVar5 + 0xc));
                    /* WARNING: Subroutine does not return */
      thunk_FUN_060389ae(*(undefined4 *)(iVar5 + 0xc),0x2001f,iVar5);
    }
    func_0x0001fd7e(puVar4,6);
    op_pop_pc_rl();
  }
                    /* WARNING: Subroutine does not return */
  FUN_0010feda(0x14);
}


// ===== f_jl701n_v100_20240417_fcd444d5 @ 0600c870

/* B2: strings referenced by this function (disasm/function_strings.json):
     "jl701n_V100-@20240417-$fcd444d5"
     "tone_zh/normal.*" */

void f_jl701n_v100_20240417_fcd444d5(undefined4 param_1)

{
  op_push_rets_rl();
                    /* WARNING: Subroutine does not return */
  FUN_0606fc52(uRam0010619c,param_1);
}


// ===== f_esco_adc @ 0600de08

/* B4.2 rename (string); evidence: disasm/b42_manifest.json; strings:
     "esco_adc"
     "smart_voice"
     "periph_demo"
     "clock"
     "mcpwm"
     "usr_systimer"
     "btstack_lowpwer_deal"
     "btstack" */

void f_esco_adc(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  BADSPACEBASE *in_sp;
  undefined8 *puVar6;
  undefined8 uStack_8;
  
  op_push_rets_rl();
  puVar6 = &uStack_8;
  iVar3 = 0x106060;
  if (cRam001066b4 == '\0') {
    iVar4 = 0;
    uRam001066b8 = 0;
    uStack_8 = 0;
    iVar1 = FUN_06037ba4(0x605fce9,0,&uStack_8);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_06037cce(puVar6,iVar3 + 0x65c);
    }
    *(undefined1 *)(iVar3 + 0x654) = 1;
    iVar1 = 0x197;
    iVar5 = 0;
    for (; iVar4 != 4; iVar4 = iVar4 + 1) {
      if ((*(uint *)(iVar3 + iVar1 * 4) & 1 << iVar4) != 0) {
        uVar2 = op_ext_b0_u(iVar5);
        FUN_0603cd64(iVar3 + 0x980,uVar2);
      }
      iVar5 = iVar5 + 1;
    }
  }
  iVar1 = 0x665;
  for (iVar4 = -4; iVar4 != 0; iVar4 = iVar4 + 1) {
    if (*(char *)(iVar4 + iVar3 + 0x16c) != '\0') {
      *(undefined1 *)(iVar1 + iVar3) = *(undefined1 *)(iVar4 + iVar3 + 0x170);
    }
    iVar1 = iVar1 + 9;
  }
  rep_unspec(4,10);
  *(undefined4 *)(iVar3 + 0x68c) = *(undefined4 *)(iVar3 + 0x65c);
  op_pop_pc_rl();
  *(byte *)(iVar3 + 0x693) = *(byte *)(iVar3 + 0x693) & 0xf0 | *(byte *)(iVar3 + 0x660) & 0xf0;
  *(undefined1 *)(iVar3 + 0x690) = *(undefined1 *)(iVar3 + 0x663);
  *(undefined1 *)(iVar3 + 0x691) = *(undefined1 *)(iVar3 + 0x664);
  *(undefined1 *)(iVar3 + 0x692) = *(undefined1 *)(iVar3 + 0x665);
  uVar2 = op_insert_rrii((uint)*(byte *)(iVar3 + 0x666),4,0x1c);
  *(char *)(iVar3 + 0x693) = (char)uVar2;
  return;
}


// ===== effect_nodes_open @ 0600e3d8

/* B4.2 rename (expert); evidence: disasm/b42_manifest.json */

void effect_nodes_open(byte param_1)

{
  bool bVar1;
  code *pcVar2;
  byte bVar3;
  undefined1 extraout_r0;
  undefined1 extraout_r0_00;
  undefined1 extraout_r0_01;
  char extraout_r0_02;
  undefined1 extraout_r0_03;
  undefined1 uVar4;
  undefined1 extraout_r0_04;
  undefined1 extraout_r0_05;
  undefined1 extraout_r0_06;
  undefined1 extraout_r0_07;
  undefined1 extraout_r0_08;
  undefined1 uVar5;
  undefined1 extraout_r0_09;
  undefined1 extraout_r0_10;
  undefined1 extraout_r0_11;
  char extraout_r0_12;
  undefined1 extraout_r0_13;
  undefined1 extraout_r0_14;
  undefined1 extraout_r0_15;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 extraout_var_01;
  undefined1 extraout_var_02;
  undefined1 extraout_var_03;
  undefined1 uVar6;
  undefined1 extraout_var_04;
  undefined1 extraout_var_05;
  undefined1 extraout_var_06;
  undefined1 extraout_var_07;
  undefined1 extraout_var_08;
  undefined1 uVar7;
  undefined1 extraout_var_09;
  undefined1 extraout_var_10;
  undefined1 extraout_var_11;
  undefined1 extraout_var_12;
  undefined1 extraout_var_13;
  undefined1 extraout_var_14;
  undefined1 extraout_var_15;
  undefined2 extraout_var_16;
  undefined2 extraout_var_17;
  undefined2 extraout_var_18;
  undefined2 extraout_var_19;
  undefined2 extraout_var_20;
  undefined2 extraout_var_21;
  undefined2 extraout_var_22;
  undefined2 extraout_var_23;
  undefined2 extraout_var_24;
  undefined2 extraout_var_25;
  undefined2 uVar8;
  undefined2 extraout_var_26;
  undefined2 extraout_var_27;
  short extraout_var_28;
  undefined2 extraout_var_29;
  undefined2 extraout_var_30;
  undefined2 extraout_var_31;
  undefined2 extraout_var_32;
  char extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  undefined1 *puVar9;
  undefined4 *puVar10;
  char *pcVar11;
  int *piVar13;
  ulonglong uVar12;
  char cVar14;
  int iVar15;
  ushort *puVar16;
  char *pcVar17;
  int iVar18;
  uint *puVar19;
  char *pcVar20;
  int iVar21;
  char *pcVar22;
  undefined4 uVar23;
  uint *puVar24;
  uint uVar25;
  undefined4 *puVar26;
  int iVar27;
  int iVar28;
  BADSPACEBASE *in_sp;
  undefined4 *puVar29;
  undefined1 *puVar30;
  undefined1 *puVar31;
  undefined1 auStack_c [12];
  
  op_push_rets_rl();
  puVar29 = (undefined4 *)auStack_c;
  uVar25 = (uint)param_1;
  uVar23 = 0;
  FUN_0600e062(0);
  FUN_0010cf86(0x52);
  FUN_0010cf86(0x4c);
  uVar7 = (undefined1)uVar25;
  uVar5 = (undefined1)uVar23;
  iVar18 = 0x106060;
  piVar13 = piRam001062a0;
  if (piRam001062a0 == (int *)0x0) {
    FUN_001101a6(0xd0);
    uVar7 = (undefined1)uVar25;
    uVar5 = (undefined1)uVar23;
    iVar21 = CONCAT22(extraout_var_16,CONCAT11(extraout_var,extraout_r0));
    *(int *)(iVar18 + 0x240) = iVar21;
    piVar13 = (int *)0x0;
    if (iVar21 != 0) {
      iVar15 = 0;
      func_0x0001fd82(0,0xd0);
      puVar9 = (undefined1 *)(iVar18 + 0x238);
      *puVar9 = 0x24;
      FUN_001101a6();
      *(uint *)(puVar9 + 0xc) = CONCAT22(extraout_var_17,CONCAT11(extraout_var_00,extraout_r0_00));
      func_0x0001fd82(0,0x824);
      FUN_0600e0e0();
      **(undefined4 **)(puVar9 + 8) =
           CONCAT22(extraout_var_18,CONCAT11(extraout_var_01,extraout_r0_01));
      FUN_0600e1d4();
      iVar27 = CONCAT22(extraout_var_19,CONCAT11(extraout_var_02,extraout_r0_02));
      FUN_001101a6(extraout_r0_02 << 1);
      iVar21 = *(int *)(puVar9 + 8);
      iVar27 = CONCAT22(extraout_var_20,CONCAT11(extraout_var_03,extraout_r0_03)) + iVar27;
      *(int *)(iVar21 + 0x2c) = iVar27;
      *(int *)(iVar21 + 0x30) = iVar27;
      while( true ) {
        uVar7 = (undefined1)uVar25;
        uVar5 = (undefined1)uVar23;
        if (iVar15 == 2) break;
        FUN_0600e1ee((char)**(undefined4 **)(iVar18 + 0x240),iVar15,
                     (*(undefined4 **)(iVar18 + 0x240))[iVar15 + 0xb]);
        FUN_0600e202((char)**(undefined4 **)(iVar18 + 0x240),iVar15);
        iVar15 = iVar15 + 1;
      }
      uVar4 = 0xfd;
      uVar6 = 3;
      if (*(char *)(iVar18 + 0x238) == '\0') {
        uVar4 = 0xa7;
        uVar6 = 2;
      }
      piVar13 = *(int **)(iVar18 + 0x240);
      *(ushort *)(*piVar13 + 0xb6) = CONCAT11(uVar6,uVar4);
    }
  }
  puVar19 = (uint *)0xf00100;
  uRam00f00100 = uRam00f00100 & 0x10;
  iVar18 = *(int *)(iVar18 + 0x244);
  iVar21 = iVar18 + 0x18;
  *(undefined1 *)(iVar18 + 0x19) = uVar5;
  *(undefined1 *)(iVar18 + 2) = uVar7;
  *(undefined1 *)(iVar18 + 3) = uVar7;
  uVar7 = 4;
  *(undefined1 *)(iVar18 + 6) = 4;
  *(undefined1 *)(iVar18 + 0x1a) = 1;
  *(undefined1 *)(iVar18 + 0x1b) = 0xf;
  *(undefined1 *)(iVar18 + 1) = uVar5;
  puVar10 = (undefined4 *)*piVar13;
  *(undefined1 *)(iVar18 + 0x1c) = uVar5;
  *(undefined4 *)(iVar18 + 0xc) = 4;
  *(ushort *)((int)puVar10 + 0x16) = *(ushort *)((int)puVar10 + 0x16) & 0xfff7;
  f_tone_zh_normal(4,0);
  uVar8 = *(undefined2 *)CONCAT22(extraout_var_21,CONCAT11(extraout_var_04,extraout_r0_04));
  puVar24 = puVar19 + -0x3e;
  *(undefined2 *)(iVar18 + 0x1e) = uVar8;
  piVar13[5] = iVar18 + 0x24;
  *(undefined1 *)((int)piVar13 + 5) = uVar7;
  *(undefined2 *)((int)piVar13 + 6) = uVar8;
  *(undefined1 *)(piVar13 + 1) = 2;
  puVar19[-0x39] = puVar19[-0x39] & 0xff;
  puVar19[2] = puVar19[2] & 0xff;
  FUN_0600e24e((char)puVar10);
  FUN_0600e282((char)piVar13,0,*(undefined1 *)(iVar18 + 0x1b));
  puVar16 = (ushort *)((int)puVar10 + 0xf2);
  *puVar16 = *puVar16 | 1;
  bVar1 = *(char *)(iVar21 + 2) == '\0';
  if (bVar1) {
    FUN_06042634();
    *puVar19 = *puVar19 | 8;
    *puVar19 = *puVar19 & 4;
    cVar14 = (char)puVar16;
  }
  else {
    *puVar19 = *puVar19 & 8;
    func_0x0001fd82((char)piVar13[5],0xff,*(undefined2 *)((int)piVar13 + 6));
    cVar14 = (char)puVar16;
    FUN_060424f4();
  }
  FUN_0600e08e(cVar14 + '&',bVar1);
  (*(code *)*puVar10)(0);
  pcVar17 = s_F111_06061dd8 + 3;
  __write_reg_bdaddr((char)puVar10,s_AC008_06061e52 + 4);
  __write_reg_bch(pcVar17);
  *(ushort *)((int)puVar10 + 0x12) = *(ushort *)((int)puVar10 + 0x12) & 0xffef;
  *(ushort *)(puVar10 + 5) = *(ushort *)(puVar10 + 5) & 0xffef;
  iVar27 = piVar13[5];
  puVar26 = (undefined4 *)0x113524;
  uVar23 = 1;
  puVar29[2] = (uint)*(byte *)((int)piVar13 + 5);
  puVar29[1] = 1;
  *puVar29 = puVar10;
  (*pcRam00113524)(0,iVar27);
  iVar27 = piVar13[5];
  pcVar2 = (code *)*puVar26;
  puVar29[2] = (uint)*(byte *)((int)piVar13 + 5);
  puVar29[1] = uVar23;
  *puVar29 = puVar10;
  (*pcVar2)(1,iVar27);
  FUN_0600e370((char)puVar10,3);
  uVar12 = ZEXT48(puVar10);
  puVar19[4] = 0;
  puVar19[5] = 0;
  *(ushort *)((int)puVar10 + 0x16) = *(ushort *)((int)puVar10 + 0x16) & 0xfffb;
  FUN_0600e380(0x67);
  FUN_0600e3ac((char)uVar12,0x67,0);
  *puVar24 = CONCAT22((short)((*puVar24 & 0xfffff000) >> 0x10),
                      CONCAT11((char)((*puVar24 & 0xfffff000) >> 8),0xc1));
  puVar16 = (ushort *)uVar12;
  if (*(char *)(iVar18 + 1) == '\0') {
    *puVar16 = *puVar16 | 0x80;
    puVar19[7] = (uint)(uVar12 >> 0x20);
    FUN_0600e3c8(*(undefined1 *)(iVar18 + 2));
    puVar19[7] = puVar19[7] | CONCAT22(extraout_var_22,CONCAT11(extraout_var_05,extraout_r0_05));
    FUN_0600e3c8(*(undefined1 *)(iVar18 + 3));
    puVar19[7] = puVar19[7] |
                 CONCAT22(extraout_var_23,CONCAT11(extraout_var_06,extraout_r0_06)) << 7;
    iVar18 = extraout_r1_00;
  }
  else {
    iVar18 = 0xff7f;
    *puVar16 = *puVar16 & 0xff7f;
  }
  bVar3 = *(byte *)(iVar21 + 1);
  if (bVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_06004f6e((char)uVar12);
  }
  *puVar19 = *puVar19 | 0x10;
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar30 = (undefined1 *)((int)puVar29 + 4);
  *(undefined2 *)((int)puVar29 + 8) = uRam0010635c;
  uVar25 = (uint)bVar3;
  *(undefined4 *)((int)puVar29 + 4) = uRam00106358;
  FUN_0602eee8((char)(undefined1 *)((int)puVar29 + 4));
  if (iVar18 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_060745b6(0x10,0,0);
  }
  if (uVar25 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_060745b6(0xe,0,0);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar31 = puVar30 + -0x18;
  pcVar17 = (char *)CONCAT22(extraout_var_24,CONCAT11(extraout_var_07,extraout_r0_07));
  FUN_06008e48();
  if (CONCAT22(extraout_var_25,CONCAT11(extraout_var_08,extraout_r0_08)) == 1) {
LAB_0600e82e:
    op_pop_pc_rl();
                    /* WARNING: Subroutine does not return */
    FUN_0602b752((char)*(undefined2 *)(pcVar17 + 0xc));
  }
  uVar5 = 0;
  uVar7 = 0;
  uVar8 = 0;
  iVar18 = 0x106060;
  do {
    if (1 < CONCAT22(uVar8,CONCAT11(uVar7,uVar5))) goto LAB_0600e82e;
    iVar21 = CONCAT22(uVar8,CONCAT11(uVar7,uVar5));
    iVar27 = CONCAT22(uVar8,CONCAT11(uVar7,uVar5)) + 1;
    uVar5 = (undefined1)iVar27;
    uVar7 = (undefined1)((uint)iVar27 >> 8);
    uVar8 = (undefined2)((uint)iVar27 >> 0x10);
  } while (pcVar17 != *(char **)(iVar21 * 4 + 0x106378));
  if (*(int *)(pcVar17 + 0x10) == 0) goto LAB_0600e82e;
  iVar28 = -1;
  iVar15 = 0xa40;
  iVar27 = 0xb7f;
  FUN_06074d90(puVar31 + 0x10);
  iVar21 = CONCAT22(extraout_var_32,CONCAT11(extraout_var_15,extraout_r0_15));
  if (iVar21 < 1) {
    if (0 < iVar28) {
      uVar23 = op_uextra_rrii(iVar28,0,0x10);
      FUN_06074e62((char)*(undefined4 *)(pcVar17 + 0x10),uVar23);
    }
    goto LAB_0600e82e;
  }
  iVar28 = *(int *)(puVar31 + 0x10);
  uVar23 = op_insert_rrii((uint)*(byte *)(iVar28 + 2),8,8);
  if (*(char *)(iVar18 + iVar15) == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_06074da2((char)*(undefined4 *)(pcVar17 + 0x10),iVar28);
  }
  if (*(short *)(pcVar17 + 10) == 0) {
    *(ushort *)(pcVar17 + 10) = (ushort)(byte)pcVar17[3] + (short)uVar23;
                    /* WARNING: Subroutine does not return */
    FUN_06074da2((char)*(undefined4 *)(pcVar17 + 0x10),iVar28);
  }
  if (*pcVar17 == '\v') {
    iVar18 = 0;
    uVar23 = op_ext_l_u_p(iVar21);
    *(undefined4 *)(puVar31 + 0x1c) = 0;
    FUN_06074db4(0xb,iVar28,uVar23);
    iVar15 = CONCAT22(extraout_var_29,CONCAT11(extraout_var_12,extraout_r0_12));
    cVar14 = extraout_r0_12 + extraout_r1 + '\x01';
    FUN_0010b826(cVar14);
    if (CONCAT22(extraout_var_30,CONCAT11(extraout_var_13,extraout_r0_13)) == 0) {
      uVar23 = op_ext_l_u((iVar21 + iVar27) - iVar15);
      FUN_0605475c(cVar14,uVar23,puVar31 + 0x1c);
      if (CONCAT22(extraout_var_31,CONCAT11(extraout_var_14,extraout_r0_14)) == 0) {
        iVar18 = *(int *)(puVar31 + 0x1c);
      }
    }
LAB_0600e78c:
    if (9 < iVar18) {
      pcVar17[1] = pcVar17[1] + '\x01';
                    /* WARNING: Subroutine does not return */
      FUN_06074da2((char)*(undefined4 *)(pcVar17 + 0x10),iVar28);
    }
    if (iVar18 < 0) goto LAB_0600e7bc;
  }
  else if (*pcVar17 == '\0') {
    iVar18 = op_ext_l_u(iVar21);
    FUN_06074db4(0,iVar28,iVar18);
    pcVar11 = (char *)(extraout_r1_01 +
                      CONCAT22(extraout_var_26,CONCAT11(extraout_var_09,extraout_r0_09)));
    do {
      pcVar20 = pcVar11;
      pcVar11 = pcVar20 + 1;
    } while (*pcVar20 != -100);
    FUN_06074e12(*pcVar11,pcVar20[2]);
    iVar21 = CONCAT22(extraout_var_27,CONCAT11(extraout_var_10,extraout_r0_10));
    pcVar20 = (char *)(iVar28 + iVar18);
    pcVar22 = pcVar11 + iVar21;
    iVar27 = 0;
    do {
      FUN_00109522((char)pcVar11 + (char)iVar27 + -1,iVar21);
      iVar18 = CONCAT22(extraout_var_28,CONCAT11(extraout_var_11,extraout_r0_11));
      if (-1 < extraout_var_28) goto LAB_0600e78c;
      iVar27 = iVar27 + iVar21;
    } while (pcVar22 + iVar27 + -1 <= pcVar20);
  }
  pcVar17[1] = (byte)pcVar17[1] >> 1;
LAB_0600e7bc:
                    /* WARNING: Subroutine does not return */
  FUN_06074da2((char)*(undefined4 *)(pcVar17 + 0x10),iVar28);
}


// ===== jlstream_res_init @ 0604b08e

/* B4.2 rename (expert); evidence: disasm/b42_manifest.json */

void jlstream_res_init(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  char *pcVar10;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  uint *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined4 *puVar15;
  undefined8 uVar16;
  uint uStack_40;
  uint uStack_3c;
  undefined4 *puStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  undefined2 uStack_20;
  
  op_push_rets_rl();
  puVar11 = &uStack_40;
  if (param_1 == 0) {
    uStack_20 = 0;
    uStack_24 = 0;
    uStack_28 = 0;
    uStack_2c = 0;
    uStack_30 = 0;
    uStack_34 = 0;
    puStack_38 = &uStack_24;
    uStack_3c = 0;
    uStack_40 = 0;
  }
  else {
    uStack_40 = (uint)*(byte *)(param_1 + 0x3d);
    uStack_3c = (uint)*(byte *)(param_1 + 0xb);
    uStack_34 = (uint)*(ushort *)(param_1 + 0x1e);
    uStack_2c = (uint)*(ushort *)(param_1 + 0x22);
    uStack_28 = (uint)*(byte *)(param_1 + 0x3e);
    uStack_30 = (uint)*(ushort *)(param_1 + 0x20);
    puStack_38 = (undefined4 *)(param_1 + 0xc);
  }
  uVar16 = FUN_0604992a(1,s_1Hc08_0605fdd5 + 4,param_2);
  puVar12 = (undefined1 *)((int)puVar11 + 0x40);
  op_pop_pc_rl();
  op_push_rets_rl();
  uVar3 = *(byte *)((int)uVar16 + 8) & 0xffffff0f;
  if (uVar3 == 5) {
    **(undefined4 **)(iRam00104f70 + 4) = 0;
                    /* WARNING: Subroutine does not return */
    FUN_0604946e();
  }
  op_pop_pc_rl();
  *(undefined4 *)((int)puVar11 + 0x3c) = unaff_retaddr;
  if ((int)((ulonglong)uVar16 >> 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0604946e();
  }
  op_push_rets_rl();
  iVar7 = 0x105014;
  piVar8 = (int *)0x105014;
  uVar4 = 0;
  do {
    piVar8 = (int *)*piVar8;
    if (piVar8 == (int *)iVar7) goto LAB_0604b268;
    iVar1 = func_0x0001fd7e(uVar3,(int)piVar8 + -7,6);
  } while ((iVar1 != 0) || (*(byte *)(piVar8 + -2) != uVar4));
  op_pop_pc_rl();
LAB_0604b268:
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar7 = 0;
  if ((bRam00000008 & 0xf) != 3) {
                    /* WARNING: Subroutine does not return */
    FUN_0601d968();
  }
  uVar3 = (uint)bRam00108ba6;
  puVar5 = (undefined1 *)0x108b94;
  uRam00108b94 = 0;
  if ((((bRam00108ba6 & 1) != 0) && ((bRam00000008 & 0xf) == 3)) &&
     (iVar1 = FUN_0604b238(bRam00000008 >> 7,0x16), iVar1 == 0)) {
    *puVar5 = 1;
  }
  if ((((uVar3 & 2) != 0) && ((*(byte *)(iVar7 + 8) & 0xf) == 5)) &&
     (iVar7 = FUN_0604b238(*(byte *)(iVar7 + 8) >> 7,iVar7 + 0x16), iVar7 == 0)) {
    *puVar5 = 1;
  }
  op_pop_pc_rl();
  puVar13 = puVar12 + -4;
  *(undefined4 *)(puVar12 + -4) = unaff_retaddr;
  uVar16 = FUN_0601d8da(0x10896c);
  iVar7 = (int)uVar16;
  puVar14 = puVar13 + 4;
  op_push_rets_rl();
  uVar3 = (uint)*(byte *)(iVar7 + 8);
  pcVar10 = (char *)0x108b94;
  if ((uVar3 & 0xffffff0f) == 5) {
    uVar6 = *(undefined4 *)((ulonglong)uVar16 >> 0x20);
    puVar2 = (undefined4 *)FUN_0601d934(0x160);
    *puVar2 = uVar6;
    rep_unspec(4,7);
    *(undefined1 *)(puVar2 + 1) = *(undefined1 *)((int)((ulonglong)uVar16 >> 0x20) + 4);
    *(char *)((int)puVar2 + 0xb) = (char)(uVar3 >> 7);
    rep_unspec(4,6);
    *(undefined1 *)(puVar2 + 3) = *(undefined1 *)((int)uVar16 + 0x16);
    puVar9 = puVar2 + 5;
    puVar5 = (undefined1 *)((int)uVar16 + 0x22);
    *(char *)((int)puVar2 + 0x3d) = (char)puVar5;
    rep_unspec(4,0x16);
    *(undefined1 *)puVar9 = *puVar5;
    FUN_0604ab90(puVar9,(int)puVar2 + 0x15);
                    /* WARNING: Subroutine does not return */
    FUN_06046c2a(*puVar2,6,puVar9);
  }
  puVar5 = puVar13 + 4;
  if ((uVar3 & 0xffffff0f) == 3) {
    FUN_0604b26c(iVar7);
    iVar7 = (int)uVar16;
    puVar5 = puVar14;
    if (*pcVar10 == '\0') {
                    /* WARNING: Subroutine does not return */
      FUN_06046c2a(*(undefined4 *)((ulonglong)uVar16 >> 0x20),0xe,iVar7);
    }
  }
  if (((*(byte *)(iVar7 + 8) & 0x30) != 0x10) || (*(char *)(iVar7 + 10) != '\0')) {
    FUN_0604b2cc();
  }
  op_pop_pc_rl();
  puVar15 = (undefined4 *)(puVar5 + -4);
  *(undefined4 *)(puVar5 + -4) = unaff_retaddr;
  FUN_0604ab30(0);
  *puVar15 = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  thunk_FUN_0604946e();
}


// ===== effect_nodes_close @ 0604c65c

/* B4.2 rename (expert); evidence: disasm/b42_manifest.json */

void effect_nodes_close(void)

{
  op_push_rets_rl();
                    /* WARNING: Subroutine does not return */
  FUN_0010db7e();
}


// ===== f_config397392 @ 06017a4e

/* B2: strings referenced by this function (disasm/function_strings.json):
     "config397392" */

void f_config397392(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined8 *puVar3;
  undefined1 auStack_14 [8];
  undefined8 uStack_c;
  
  rep_unspec(2,0xf);
  *(undefined1 *)((uint)auStack_14 | 1) = 0;
  auStack_14[0] = 0x10;
  uStack_c._0_6_ = CONCAT24((short)param_1,(undefined4)uStack_c);
  if (iRam001061f0 != 0) {
    pcVar2 = s_config397392_0606218f + 0xb;
    if (cRam001068d5 != '\0') {
      pcVar2 = s_Vol_BtmMusic2_06062231 + 0xc;
    }
                    /* WARNING: Subroutine does not return */
    FUN_06038bd8(0x74e3,pcVar2,auStack_14);
  }
  op_push_rets_rl();
  puVar3 = &uStack_c;
  uStack_c = 0;
  pcVar2 = s_music_06061e27 + 4;
  iVar1 = FUN_06038d42(s_music_06061e27 + 4,0,&uStack_c);
  if (iVar1 == 0) {
    op_pop_pc_rl();
    *(undefined4 *)((int)puVar3 + 8) = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
    FUN_0010bebe(0x63fc);
  }
  *(undefined4 *)((int)puVar3 + 8) = *(undefined4 *)(pcVar2 + param_1 * 4 + 0x101);
                    /* WARNING: Subroutine does not return */
  FUN_06038bd8(0xa904,pcVar2,puVar3,0xc);
}


// ===== f_energymusic @ 0606fb28

/* B2: strings referenced by this function (disasm/function_strings.json):
     "EnergyMusic" */

void f_energymusic(int param_1)

{
  BADSPACEBASE *in_sp;
  undefined1 auStack_14 [16];
  
                    /* WARNING: Subroutine does not return */
  FUN_06003292(*(undefined4 *)(param_1 * 4 + 0x60629f4),auStack_14);
}


// ===== set_hp_gain @ 06006390

/* B2 anchor (findings/B2_anchors.md): subsystem named by string anchors; see string_xrefs.md for
   the evidence chain. Former name: sub_06006390
   B2: strings referenced by this function (disasm/function_strings.json):
     "SET_HP_GAIN" */

void set_hp_gain(uint param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  op_push_rets_rl();
  iVar4 = 0x106060;
  uVar3 = param_1;
  if (cRam001068ab == '\0') goto switchD_060063e2_default;
LAB_060063a4:
  do {
    while( true ) {
      op_pop_pc_rl();
      uVar3 = param_1;
switchD_060063e2_default:
      if (*(char *)(iVar4 + 0xa0) == '\0') break;
      iVar2 = FUN_060745c6();
      uVar3 = op_ext_b0_u(iVar2 + -0x33);
      if (uVar3 < 3) {
        uVar3 = (uint)*(byte *)(iVar4 + 0x14);
        if (uVar3 < 0x33) {
LAB_0600641e:
          if (uVar3 < 0x19) goto LAB_06006422;
          FUN_06006132();
        }
        else {
          *(undefined1 *)(iVar4 + 0x14) = 0;
LAB_06006422:
          FUN_06006068();
        }
        *(char *)(iVar4 + 0x14) = *(char *)(iVar4 + 0x14) + '\x01';
      }
      else {
        FUN_0600605e();
      }
      param_1 = *(int *)(iVar4 + 0xe4) + 1;
      *(uint *)(iVar4 + 0xe4) = param_1;
      if (60000 < (int)param_1) {
        *(undefined4 *)(iVar4 + 0xe4) = 0;
        FUN_0600605e();
        op_pop_pc_rl();
        goto switchD_060063e2_caseD_2;
      }
    }
    if ((*(char *)(iVar4 + 0x9c) == '\0') && ((*(byte *)(iVar4 + 0x1a0) & 1) == 0))
    goto code_r0x060063dc;
    if (*(char *)(iVar4 + 0x87f) != '\0') {
      uVar3 = FUN_060061fc();
      op_pop_pc_rl();
      goto LAB_0600641e;
    }
    if (param_2 == 2) goto LAB_060064ba;
    param_1 = 0;
    if (param_2 == 1) goto LAB_060064c0;
LAB_06006472:
  } while (param_2 != 0);
  FUN_06006068();
  op_pop_pc_rl();
  goto switchD_060063e2_caseD_3;
code_r0x060063dc:
  param_1 = uVar3 - 1;
  switch(uVar3) {
  case 1:
    break;
  case 2:
switchD_060063e2_caseD_2:
    param_1 = FUN_060745c6();
    if (param_1 != 0x33) goto LAB_060064c6;
LAB_0600646a:
    if (param_2 == 2) {
LAB_060064ba:
      FUN_060062c6();
      op_pop_pc_rl();
    }
    else if (param_2 != 1) goto LAB_06006472;
LAB_060064c0:
    param_1 = FUN_06006132();
    op_pop_pc_rl();
LAB_060064c6:
    if (((param_1 != 0x34) &&
        (param_1 = (uint)(byte)(*(byte *)(iVar4 + 0x881) | *(byte *)(iVar4 + 0x882) |
                               *(byte *)(iVar4 + 0x880)), param_1 == 0)) &&
       (param_1 = FUN_060745c6(), param_1 != 0x35)) {
      if (*(byte *)(iVar4 + 0x16) < 0x33) {
        if (0x18 < *(byte *)(iVar4 + 0x16)) goto LAB_06006564;
      }
      else {
        *(undefined1 *)(iVar4 + 0x16) = 0;
      }
      if (param_2 == 2) {
        FUN_060062c6();
      }
      else if (param_2 == 1) {
        FUN_06006132();
      }
      else if (param_2 == 0) {
        FUN_06006068();
      }
      do {
        cVar1 = *(char *)(iVar4 + 0x16) + '\x01';
LAB_0600655e:
        *(char *)(iVar4 + 0x16) = cVar1;
        op_pop_pc_rl();
LAB_06006564:
        FUN_060061fc();
      } while( true );
    }
    goto LAB_0600646a;
  case 3:
    goto switchD_060063e2_caseD_3;
  case 4:
    FUN_060061fc();
    *(char *)(iVar4 + 0x15) = *(char *)(iVar4 + 0x15) + '\x01';
    if (*(byte *)(iVar4 + 0x15) < 8) goto LAB_0600655c;
    goto LAB_06006550;
  default:
    goto LAB_060063a4;
  }
  FUN_060061fc();
  *(char *)(iVar4 + 0x15) = *(char *)(iVar4 + 0x15) + '\x01';
  if (3 < *(byte *)(iVar4 + 0x15)) {
LAB_06006550:
    *(undefined1 *)(iVar4 + 0x15) = 0;
    *(undefined1 *)(iVar4 + 0x13) = 2;
  }
LAB_0600655c:
  cVar1 = '\0';
  goto LAB_0600655e;
switchD_060063e2_caseD_3:
  *(char *)(iVar4 + 0x15) = *(char *)(iVar4 + 0x15) + '\x01';
  if (7 < *(byte *)(iVar4 + 0x15)) {
    if ((7 < *(byte *)(iVar4 + 0x15)) && (*(byte *)(iVar4 + 0x15) < 0x10)) {
      if (param_2 == 2) {
        FUN_060062c6();
      }
      else if (param_2 == 1) {
        FUN_06006132();
      }
      else if (param_2 == 0) {
        FUN_06006068();
      }
      goto LAB_06006548;
    }
    if ((*(byte *)(iVar4 + 0x15) < 0x10) || (0x17 < *(byte *)(iVar4 + 0x15))) goto LAB_06006548;
  }
  FUN_060061fc();
LAB_06006548:
  if (*(byte *)(iVar4 + 0x15) < 0x18) goto LAB_0600655c;
  goto LAB_06006550;
}


// ===== f_gain4 @ 06030646

/* B2: strings referenced by this function (disasm/function_strings.json):
     "Gain4" */

void f_gain4(int param_1,undefined4 param_2,undefined4 param_3)

{
  op_push_rets_rl();
                    /* WARNING: Subroutine does not return */
  FUN_060370aa(3,s_Gain4_06061e2d + 4,param_2,param_3,param_1 + 0x9d,0);
}


// ===== f_app_dir_head @ 06072324

/* WARNING: Removing unreachable block (ram,0x060723f2) */
/* B2: strings referenced by this function (disasm/function_strings.json):
     "app_dir_head" */

void f_app_dir_head(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 auStack_84 [128];
  
  op_push_rets_rl();
  uVar1 = 0xff;
  if ((param_2 != 0) && (param_3 != 0)) {
    uVar2 = op_ext_b0_u(0);
    if (uVar2 < 0x10) {
                    /* WARNING: Subroutine does not return */
      FUN_0600063a(param_1 + 2,0x1e);
    }
    op_ext_b0_u(0);
    uVar1 = 0xfffffffe;
  }
  uVar1 = op_ext_b0_u(uVar1);
  op_pop_pc_rl();
  puVar5 = auStack_84 + 0x80;
  uVar1 = FUN_0602a91e(uVar1);
  puVar7 = puVar5 + 4;
  puVar6 = puVar5 + 4;
  op_push_rets_rl();
  if (cRam00106095 == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0010ea22();
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar4 = 0x106060;
  uVar3 = 0;
  if (iRam00106304 != 0) {
    puVar7 = puVar5 + 4;
    if (*(code **)(iRam00106304 + 0x10) != (code *)0x0) {
      uVar3 = 0;
      (**(code **)(iRam00106304 + 0x10))(uVar1);
      puVar7 = puVar6;
    }
    *(undefined1 *)(iVar4 + 0x33) = uVar3;
  }
  op_pop_pc_rl();
  *(undefined4 *)(puVar7 + -4) = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  FUN_0600063a();
}


// ===== ? @ 060831a2
// no function
// ===== ? @ 060832be
// no function
