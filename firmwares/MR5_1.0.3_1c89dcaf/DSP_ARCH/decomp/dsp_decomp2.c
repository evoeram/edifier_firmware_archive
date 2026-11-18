// ===== FUN_06006068 @ 06006068

void FUN_06006068(void)

{
  op_push_rets_rl();
  FUN_0010dd54();
  uRam00fd5000 = uRam00fd5000 | 2;
                    /* WARNING: Subroutine does not return */
  FUN_0010dd86();
}


// ===== FUN_06006132 @ 06006132

void FUN_06006132(void)

{
  op_push_rets_rl();
  FUN_0010dd54();
  uRam00fd5000 = uRam00fd5000 | 0x40;
                    /* WARNING: Subroutine does not return */
  FUN_0010dd86();
}


// ===== FUN_060061fc @ 060061fc

void FUN_060061fc(void)

{
  op_push_rets_rl();
  FUN_0010dd54();
  uRam00fd5000 = uRam00fd5000 | 0x40;
                    /* WARNING: Subroutine does not return */
  FUN_0010dd86();
}


// ===== FUN_060062c6 @ 060062c6

void FUN_060062c6(void)

{
  op_push_rets_rl();
  FUN_0010dd54();
  uRam00fd5000 = uRam00fd5000 | 0x40;
                    /* WARNING: Subroutine does not return */
  FUN_0010dd86();
}


// ===== FUN_06003292 @ 06003292

void FUN_06003292(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  BADSPACEBASE *in_sp;
  undefined8 *puVar2;
  undefined8 uStack_8;
  
  op_push_rets_rl();
  puVar2 = &uStack_8;
  uStack_8 = 0;
  iVar1 = FUN_06037cba(uRam00106079,param_1,&uStack_8);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0010feda(*(undefined2 *)((int)puVar2 + 2));
  }
  rep_unspec(4,0x10);
  *param_2 = uRam00104a42;
  op_pop_pc_rl();
  op_push_rets_rl();
  uRam00106e40 = 0xbb;
  uRam00106e41 = 0xec;
  uRam00106e42 = 0x68;
  uRam00106e43 = 0;
  uRam00106e44 = 1;
  uRam00106e45 = 5;
  uRam0000088a = 5;
  if (cRam001068e5 == '\0') {
    uRam00106e45 = 0xd;
    if (cRam001068e6 == '\0') {
      uRam00106e45 = 5;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0600271a(0x106e40,6);
}


// ===== FUN_06038bd8 @ 06038bd8

void FUN_06038bd8(void)

{
  op_push_rets_rl();
                    /* WARNING: Subroutine does not return */
  FUN_0010feda(0x42c);
}


// ===== FUN_06038d42 @ 06038d42

void FUN_06038d42(undefined4 param_1)

{
  int iVar1;
  BADSPACEBASE *in_sp;
  undefined8 *puVar2;
  undefined8 uStack_8;
  
  op_push_rets_rmask(0xd0);
  puVar2 = &uStack_8;
  uStack_8 = 0;
  iVar1 = FUN_06037ba4(&uStack_8);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_06037cce(puVar2,param_1);
  }
  op_pop_pc_rmask(0xd0);
  uRam00105fbc = 1;
  return;
}


// ===== FUN_06038c36 @ 06038c36

void FUN_06038c36(int param_1)

{
  BADSPACEBASE *in_sp;
  undefined1 *puVar1;
  int *piVar2;
  undefined1 auStack_c [12];
  
  op_push_rets_rl();
  puVar1 = auStack_c;
  piVar2 = (int *)auStack_c;
  if (param_1 == 0) {
    FUN_06037eea();
    piVar2 = (int *)puVar1;
  }
  *piVar2 = param_1;
                    /* WARNING: Subroutine does not return */
  FUN_06037f2c(2,0,0,piVar2 + 1);
}


// ===== FUN_06007f3e @ 06007f3e

/* WARNING: Removing unreachable block (ram,0x06007fca) */

void FUN_06007f3e(int param_1,int *param_2,undefined4 *param_3)

{
  uint uVar1;
  int *piVar2;
  int *extraout_r1;
  int *extraout_r1_00;
  int *extraout_r1_01;
  int *extraout_r1_02;
  int *extraout_r1_03;
  int *extraout_r1_04;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  BADSPACEBASE *in_sp;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined8 uVar13;
  longlong lVar14;
  undefined4 auStack_14 [5];
  
  op_push_rets_rl();
  puVar11 = auStack_14;
  iVar7 = 0;
  piVar2 = param_2;
  if (0x14 < param_1 - 2U) goto switchD_06007f84_caseD_6;
  piVar2 = (int *)((param_1 - 2U) * 2);
  iVar9 = 0x106060;
  iVar8 = 0x6061ce0;
  iVar5 = 0x6068034;
  uVar6 = 0x113624;
  uVar3 = 0x113554;
  piVar10 = param_2 + 4;
  switch(param_1) {
  case 2:
    if ((param_2[2] == 0x200) && (param_3 = puRam0010615c, puRam0010615c != (undefined4 *)0x0)) {
      auStack_14[0] = 0x113554;
      FUN_001102c4(0x6068034,0,0x113554);
    }
    if (*param_2 == 0) {
      param_3 = (undefined4 *)0x0;
      *(undefined1 *)(iVar9 + 0x100) = 0;
      *(undefined4 *)(iVar9 + 0x104) = 0;
      param_2[3] = iVar8 + 0x28c;
    }
    piVar2 = (int *)param_2[2];
    if ((piVar2 == (int *)0xb00) || (piVar2 == (int *)0x400)) {
      piVar2 = (int *)(iVar8 + 0x28c);
      param_2[3] = (int)piVar2;
    }
    param_2[3] = iVar8 + 0x295;
    break;
  case 3:
    if (*param_2 == 1) {
      iVar8 = 0x606a91c;
      param_3 = puRam00106168;
      puVar12 = auStack_14;
      if (puRam00106168 == (undefined4 *)0x0) {
        uVar13 = FUN_0010ff12();
        param_3 = (undefined4 *)((ulonglong)uVar13 >> 0x20);
        piVar2 = (int *)uVar13;
        *(undefined4 **)(iVar9 + 0x108) = param_3;
        puVar12 = puVar11;
      }
      if (param_3 != (undefined4 *)0x0) {
        *puVar12 = uVar6;
        FUN_001102c4(iVar5,iVar8 - iVar5,uVar3);
        piVar2 = extraout_r1;
      }
    }
    break;
  case 4:
    if ((param_2 == (int *)0x200) && (puRam0010615c != (undefined4 *)0x0)) {
      param_3 = (undefined4 *)0x113554;
      FUN_00110338(0x6068034,0x113554);
      FUN_0010ff20(*(undefined4 *)(iVar9 + 0xfc));
      *(int *)(iVar9 + 0xfc) = iVar7;
      piVar2 = extraout_r1_00;
    }
    break;
  case 5:
    if ((*param_2 == 1) && (puRam00106168 != (undefined4 *)0x0)) {
      param_3 = (undefined4 *)0x113624;
      FUN_00110338(0x6068034,0x113554);
      FUN_0010ff20(*(undefined4 *)(iVar9 + 0x108));
      *(int *)(iVar9 + 0x108) = iVar7;
      piVar2 = extraout_r1_01;
    }
    break;
  case 0xb:
    pcVar4 = s__s_s_06061da1 + 3;
    iVar5 = func_0x0001fd86(param_2,s__s_s_06061da1 + 3);
    if ((iVar5 == 0) || (iVar5 = func_0x0001fd86(param_2,iVar8 + 0x29e), iVar5 == 0)) {
code_r0x0600816e:
      FUN_06007e9e(pcVar4);
    }
    else {
      pcVar4 = (char *)(iVar8 + 0xd3);
      iVar5 = func_0x0001fd86(param_2,pcVar4);
      if ((iVar5 == 0) || (iVar5 = func_0x0001fd86(param_2,iVar8 + 0xc9), iVar5 == 0))
      goto code_r0x0600816e;
      pcVar4 = (char *)(iVar8 + 0x1d3);
      iVar5 = func_0x0001fd86(param_2,pcVar4);
      if (iVar5 == 0) goto code_r0x0600816e;
      pcVar4 = (char *)(iVar8 + 0x145);
      iVar5 = func_0x0001fd86(param_2,pcVar4);
      if (iVar5 == 0) goto code_r0x0600816e;
      pcVar4 = (char *)(iVar8 + 0x350);
      iVar5 = func_0x0001fd86(param_2,pcVar4);
      if (iVar5 == 0) goto code_r0x0600816e;
      pcVar4 = (char *)(iVar8 + 9);
      iVar5 = func_0x0001fd86(param_2,pcVar4);
      if (iVar5 == 0) goto code_r0x0600816e;
      pcVar4 = (char *)(iVar8 + 0x1a2);
      iVar5 = func_0x0001fd86(param_2,pcVar4);
      if (iVar5 == 0) goto code_r0x0600816e;
      pcVar4 = (char *)(iVar8 + 0x19b);
      iVar5 = func_0x0001fd86(param_2,pcVar4);
      if (iVar5 == 0) goto code_r0x0600816e;
      pcVar4 = (char *)(iVar8 + 0x313);
      iVar5 = func_0x0001fd86(param_2,pcVar4);
      if (iVar5 == 0) goto code_r0x0600816e;
    }
    iVar8 = iVar8 + 0x4b;
    uVar13 = func_0x0001fd86(param_2,iVar8);
    piVar2 = (int *)uVar13;
    if ((int)((ulonglong)uVar13 >> 0x20) == 0) {
      FUN_06007e9e(iVar8);
      piVar2 = extraout_r1_02;
    }
    break;
  case 0xf:
    iVar5 = func_0x0001fd86(param_2,s_ring_06061dab + 3);
    iVar7 = 0x7674;
    if (iVar5 != 0) {
      iVar5 = func_0x0001fd86(param_2,iVar8 + 0xc9);
      if (iVar5 == 0) {
        iVar8 = iVar8 + 0xd3;
code_r0x06008578:
        f_bt_test(iVar8,48000000);
      }
      else {
        iVar5 = iVar8 + 0xd3;
        iVar7 = func_0x0001fd86(param_2,iVar5);
        if (iVar7 == 0) {
          f_bt_test(iVar5,48000000);
          iVar7 = 0xba11;
        }
        else {
          iVar5 = iVar8 + 0x350;
          iVar7 = func_0x0001fd86(param_2,iVar5);
          if (iVar7 == 0) {
            f_bt_test(iVar5,24000000);
            iVar7 = 0x9c2d;
          }
          else {
            iVar5 = iVar8 + 0x1a2;
            iVar7 = func_0x0001fd86(param_2,iVar5);
            if (iVar7 != 0) {
              iVar5 = iVar8 + 0x19b;
              iVar7 = func_0x0001fd86(param_2,iVar5);
              if (iVar7 != 0) {
                iVar7 = func_0x0001fd86(param_2,iVar8 + 0xc4);
                if (iVar7 == 0) {
                  f_bt_test(iVar8 + 0x606,192000000);
                }
                iVar5 = iVar8 + 0x145;
                iVar7 = func_0x0001fd86(param_2,iVar5);
                if (iVar7 == 0) {
                  f_bt_test(iVar5,24000000);
                }
                iVar5 = iVar8 + 0x1d3;
                iVar7 = func_0x0001fd86(param_2,iVar5);
                if (iVar7 == 0) {
                  f_bt_test(iVar5,120000000);
                }
                iVar5 = iVar8 + 9;
                iVar7 = func_0x0001fd86(param_2,iVar5);
                if (iVar7 == 0) {
                  f_bt_test(iVar5,48000000);
                }
                iVar5 = iVar8 + 0x4b;
                iVar7 = func_0x0001fd86(param_2,iVar5);
                if (iVar7 == 0) {
                  f_bt_test(iVar5,48000000);
                }
                iVar8 = iVar8 + 0x313;
                iVar5 = func_0x0001fd86(param_2,iVar8);
                iVar7 = 0x1408;
                if (iVar5 == 0) goto code_r0x06008578;
                goto switchD_06007f84_caseD_11;
              }
            }
            f_bt_test(iVar5,96000000);
            iVar7 = 0xdc8d;
          }
        }
      }
    }
  case 0x11:
switchD_06007f84_caseD_11:
    FUN_060003d6();
    piVar2 = extraout_r1_04;
    break;
  case 0x12:
    iVar5 = func_0x0001fd92(param_2,s_Vol_BtmMusic_06062182 + 0xb,0xc);
    if (iVar5 == 0) {
      FUN_060745c6();
      iVar7 = 1;
      *(undefined1 *)piVar10 = 0;
      *(undefined1 *)((int)piVar10 + 1) = *(undefined1 *)(iVar9 + 0x19);
    }
    iVar5 = func_0x0001fd92(param_2,iVar8 + 0x1b7,6);
    if (iVar5 == 0) {
      FUN_060745c6();
      iVar7 = 1;
      *(undefined1 *)piVar10 = 0;
      *(undefined1 *)((int)piVar10 + 1) = *(undefined1 *)(iVar9 + 0x19);
    }
    iVar5 = func_0x0001fd92(param_2,iVar8 + 0x2b0,8);
    if (iVar5 == 0) {
      FUN_060745c6();
      iVar7 = 1;
      *(undefined1 *)piVar10 = 0;
      *(undefined1 *)((int)piVar10 + 1) = *(undefined1 *)(iVar9 + 0x19);
    }
    iVar5 = func_0x0001fd92(param_2,iVar8 + 0x35b,10);
    if (iVar5 == 0) {
      *(undefined2 *)(param_2 + 4) = 0x50;
      *(undefined2 *)((int)param_2 + 0x12) = 0x8000;
      iVar7 = 1;
    }
    iVar5 = func_0x0001fd92(param_2,iVar8 + 0x23c,7);
    if (iVar5 == 0) {
      uVar1 = 0;
      *(undefined1 *)((int)piVar10 + 1) = 0;
      if (*(char *)(iVar9 + 0x178) != '\0') {
        iVar7 = 6;
        if (*(char *)(iVar9 + 0x174) == '\0') {
          iVar7 = 0;
        }
        iVar5 = *(int *)(iVar8 + 0xb88 + iVar7 * 4);
        uVar1 = (uint)*(byte *)(iVar7 + iVar8 + 0x1be);
        param_2[5] = *(int *)(iVar8 + 0xba4 + iVar7 * 4);
        param_2[7] = iVar5;
      }
      param_2[6] = uVar1;
      iVar7 = 1;
    }
    iVar5 = func_0x0001fd92(param_2,iVar8 + 0x31d,9);
    if (iVar5 == 0) {
      param_2[5] = 0x6011c2c;
      iVar7 = 1;
    }
    param_3 = (undefined4 *)0x8;
    iVar5 = func_0x0001fd92(param_2,iVar8 + 0x2b9);
    if (iVar5 == 0) {
      *(undefined1 *)piVar10 = 0;
      iVar7 = 1;
    }
    iVar5 = FUN_06007eec(param_2,iVar8 + 0x327);
    if (iVar5 == 0) {
      *(undefined1 *)piVar10 = 0;
      *(undefined1 *)((int)piVar10 + 1) = *(undefined1 *)(iVar9 + 0x19);
      iVar7 = 1;
    }
    iVar5 = FUN_06007eec(param_2,iVar8 + 0x2c2);
    if (iVar5 == 0) {
      FUN_06007eec(param_2,iVar8 + 0x2cb);
      *(undefined1 *)((int)piVar10 + 1) = *(undefined1 *)(iVar9 + 0x1a);
      *(undefined1 *)piVar10 = *(undefined1 *)(iVar9 + 0x19);
      iVar7 = 1;
    }
    iVar5 = FUN_06007eec(param_2,iVar8 + 0x2d4);
    if (iVar5 != 0) {
      uVar13 = FUN_06007eec(param_2,iVar8 + 0x2dd);
      piVar2 = (int *)uVar13;
      if ((int)((ulonglong)uVar13 >> 0x20) != 0) break;
    }
    FUN_0602ec38();
    iVar7 = 1;
    piVar2 = (int *)0x0;
    *(undefined1 *)((int)piVar10 + 1) = 0;
    break;
  case 0x13:
    op_ext_l_u(*param_2);
                    /* WARNING: Subroutine does not return */
    FUN_0010db7e();
  case 0x14:
    if (*param_2 == 0) {
      iVar8 = iRam00106164;
      piVar2 = (int *)FUN_0010d6de();
      if (iVar8 == 0) {
        *(int **)(iVar9 + 0x104) = piVar2;
      }
      else {
        lVar14 = FUN_0010d70e(iVar8);
        piVar2 = (int *)lVar14;
        if ((0x7cfffffffff < lVar14) &&
           (piVar2 = (int *)(uint)*(byte *)(iVar9 + 0x100), piVar2 == (int *)0x0)) {
          *(undefined1 *)(iVar9 + 0x100) = 1;
          f_iis0_rx2(5);
          piVar2 = extraout_r1_03;
        }
      }
    }
    else {
      uRam00106160 = 0;
      iRam00106164 = 0;
    }
    break;
  case 0x16:
    iVar7 = 0x600d0d4;
  }
switchD_06007f84_caseD_6:
  op_pop_pc_rl();
  op_ldm_post1(6,iVar7);
  piVar2[1] = (int)param_3;
  *param_3 = piVar2;
  *(int *)iVar7 = iVar7;
  *(int *)(iVar7 + 4) = iVar7;
  return;
}


// ===== FUN_06038540 @ 06038540

void FUN_06038540(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  
  op_push_rets_rl();
  puVar5 = (undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0x6c) = param_3;
  *puVar5 = param_2;
  uVar8 = FUN_0010d734();
  iVar6 = (int)((ulonglong)uVar8 >> 0x20);
  iVar3 = (int)uVar8;
  puVar5[1] = iVar6;
  op_pop_pc_rl();
  op_push_rets_rl();
  uVar1 = iVar6 + 0x50;
  iVar6 = *(int *)(uVar1 + iVar3 * 4);
  if ((iVar6 == 0) || (uVar1 = (uint)*(byte *)(iVar6 + 9), uVar1 != 0)) {
    op_pop_pc_rl();
    op_push_rets_rl();
    FUN_0010c29e(uVar1 + 0x1c,0);
    (**(code **)(iVar3 + 0x10))(param_3,param_4,*(code **)(iVar3 + 0x10));
                    /* WARNING: Subroutine does not return */
    FUN_0010c4ac(uVar1 + 0x1c,*(undefined2 *)(uVar1 + 2));
  }
  iVar7 = iVar6 + 0x10;
  *(char *)(iVar6 + 9) = (char)iVar7;
  iVar2 = FUN_0602c06a();
  if ((iVar3 == 1) && (iVar3 = ASCII_StrCmp(iVar7,s_jlstream_0_0606205e + 9,0xb), iVar3 == 0)) {
    iVar2 = iVar2 + 0xff;
  }
  uVar4 = op_ext_b0_u(iVar2);
                    /* WARNING: Subroutine does not return */
  FUN_0602bfcc(0x1124dc,iVar6,iVar7,uVar4);
}


// ===== FUN_06038998 @ 06038998

void FUN_06038998(int param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  *(undefined4 *)(param_1 + 0x28) = param_2;
  uVar1 = jlstream_caller(0x20006);
  *(int *)((int)((ulonglong)uVar1 >> 0x20) + 0x2c) = (int)uVar1;
  return;
}


// ===== FUN_060389ae @ 060389ae

void FUN_060389ae(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  
  op_push_rets_rl();
  iVar1 = -0x16;
  if (param_1 != 0) {
    iVar3 = param_3;
    if (*(ushort *)(param_1 + 2) == param_2) {
      iVar2 = *(int *)(param_1 + 0x14);
      if (iVar2 == 0) {
        if (param_2 != 0xd88) goto LAB_060389f6;
        iVar2 = *(int *)(param_1 + 0x10);
      }
      FUN_060385a8(param_1,iVar2);
      op_pop_pc_rl();
      param_1 = param_3;
    }
    iVar1 = -2;
    if ((*(int *)(param_1 + 0x18) != 0) && (*(int *)(*(int *)(param_1 + 0x18) + 0x2c) != 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_060389ae(*(undefined4 *)(param_2 + 0x18),iVar3,param_4);
    }
  }
LAB_060389f6:
  op_pop_pc_rl();
  *(undefined4 *)((int)in_sp + -4) = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  FUN_060389ae(*(undefined4 *)(iVar1 + 0x30));
}


// ===== FUN_0606fc52 @ 0606fc52

void FUN_0606fc52(uint param_1,undefined2 param_2)

{
  op_push_rets_rl();
  if (param_1 < 2) {
    uRam0010689e = param_2;
  }
  else {
    if (param_1 != 2) {
      op_pop_pc_rl();
      op_push_rets_rl();
                    /* WARNING: Subroutine does not return */
      f_energymusic(0);
    }
    uRam001068a0 = param_2;
  }
  uRam001068a2 = 4;
  FUN_0606fb58(param_1);
                    /* WARNING: Subroutine does not return */
  FUN_0606fba0();
}


// ===== FUN_06037ba4 @ 06037ba4

void FUN_06037ba4(uint param_1,byte *param_2,uint param_3,short *param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 extraout_r0;
  undefined1 extraout_r0_00;
  undefined1 extraout_r0_01;
  undefined1 extraout_r0_02;
  undefined1 uVar5;
  undefined1 extraout_r0_03;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 extraout_var_01;
  undefined1 extraout_var_02;
  undefined1 uVar6;
  undefined1 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  undefined2 extraout_var_07;
  undefined2 uVar7;
  undefined2 extraout_var_08;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  uint uVar12;
  BADSPACEBASE *in_sp;
  char *pcVar13;
  undefined1 auStack_34 [52];
  
  op_push_rets_rl();
  puVar9 = auStack_34;
  f_jlstream();
  iVar8 = CONCAT22(extraout_var_04,CONCAT11(extraout_var,extraout_r0));
  if (iVar8 == 0) {
    op_pop_pc_rl();
LAB_06037cb0:
                    /* WARNING: Subroutine does not return */
    FUN_06037b78((char)iVar8);
  }
  puVar10 = puVar9 + 0x30;
  do {
    FUN_06037a56((char)(puVar9 + 0x30),4);
    if (CONCAT22(extraout_var_05,CONCAT11(extraout_var_00,extraout_r0_00)) != 4) {
LAB_06037ca4:
                    /* WARNING: Subroutine does not return */
      FUN_06037b78((char)iVar8);
    }
    if (puVar9[0x30] == '\x05') {
      uVar12 = (uint)*(ushort *)(iVar8 + 0x806);
      *(undefined8 *)(puVar9 + 0x28) = 0;
      *(undefined8 *)(puVar9 + 0x20) = 0;
      FUN_06037a56((char)iVar8,(char)(puVar9 + 0x20),0x10);
      if (CONCAT22(extraout_var_06,CONCAT11(extraout_var_01,extraout_r0_01)) == 0x10) {
        rep_unspec(2,0x20);
        *puVar9 = 0;
        func_0x0001fd8e((char)param_2);
        iVar11 = 0x1505;
        uVar5 = extraout_r0_02;
        uVar6 = extraout_var_02;
        uVar7 = extraout_var_07;
        while (CONCAT22(uVar7,CONCAT11(uVar6,uVar5)) != 0) {
          bVar1 = *param_2;
          param_2 = param_2 + 1;
          iVar11 = (uint)bVar1 + iVar11 * 0x21;
          iVar2 = CONCAT22(uVar7,CONCAT11(uVar6,uVar5)) + -1;
          uVar5 = (undefined1)iVar2;
          uVar6 = (undefined1)((uint)iVar2 >> 8);
          uVar7 = (undefined2)((uint)iVar2 >> 0x10);
        }
        puVar10 = puVar9 + 5;
        pcVar13 = puVar9;
        while (FUN_06037a56((char)iVar8,(char)pcVar13,0x20),
              CONCAT22(extraout_var_08,CONCAT11(extraout_var_03,extraout_r0_03)) == 0x20) {
          if (*pcVar13 == -1) goto LAB_06037cb0;
          if ((byte)puVar9[4] == param_1) {
            uVar3 = op_insert_rrii((uint)(byte)puVar10[1],8,0x18);
            iVar2 = op_ext_l_u(iVar11);
            iVar4 = op_ext_l_u(uVar3);
            if ((iVar4 == iVar2) && ((byte)puVar9[9] == param_3)) {
              uVar3 = op_insert_rrii((uint)*(ushort *)(pcVar13 + 0xc),0x10,0x10);
              *param_4 = (short)uVar3 + (short)uVar12;
              param_4[1] = *(short *)(pcVar13 + 0xe);
              uVar3 = op_insert_rrii((uint)(byte)pcVar13[2],8,0x18);
              param_4[2] = (short)uVar3;
              *(char *)(param_4 + 3) = pcVar13[3];
                    /* WARNING: Subroutine does not return */
              FUN_06037b78((char)iVar8);
            }
          }
        }
      }
      goto LAB_06037ca4;
    }
    uVar3 = op_insert_rrii_p((byte)puVar10[1] & 0xfc,0x10,2);
    FUN_06037b94((char)iVar8,(byte)uVar3 | puVar10[2]);
  } while( true );
}


// ===== FUN_06037cce @ 06037cce

void FUN_06037cce(undefined2 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 extraout_r0;
  undefined2 extraout_var;
  undefined4 extraout_r1;
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  BADSPACEBASE *in_sp;
  undefined4 *puVar7;
  
  op_push_rets_rl();
  f_jlstream();
  iVar3 = CONCAT22(extraout_var,extraout_r0);
  if (iVar3 != 0) {
    *(undefined2 *)(iVar3 + 0x806) = *param_1;
    FUN_06037a56(extraout_r0,param_2,param_1[1]);
                    /* WARNING: Subroutine does not return */
    FUN_06037b78((short)iVar3);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar7 = (undefined4 *)((int)in_sp + -4);
  uVar5 = 0;
  lVar1 = 0;
  uVar4 = extraout_r1;
  FUN_0010ccc6((short)param_4,0);
  uVar6 = 0x605fdef;
  do {
    iVar2 = (int)((ulonglong)lVar1 >> 0x20);
    *puVar7 = param_3;
    iVar3 = FUN_0010cbc0((short)uVar6,3,uVar5,uVar4);
    if (iVar3 != 0x15) {
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0010cbe2((short)param_4,0);
      }
      break;
    }
    FUN_0010c7e4(2);
    lVar1 = (ulonglong)(iVar2 + 1U) << 0x20;
  } while ((int)(iVar2 + 1U) < 10);
  op_pop_pc_rl();
  op_push_rets_rl();
                    /* WARNING: Subroutine does not return */
  FUN_0010feda(0x42c);
}


