// ===== f_tst_dut_sav @ 06006c16

/* B2: strings referenced by this function (disasm/function_strings.json):
     "TST+DUT+SAV+" */

int f_tst_dut_sav(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  BADSPACEBASE *in_sp;
  undefined1 *puVar10;
  undefined1 auStack_20 [16];
  undefined1 auStack_10 [16];
  
  op_push_rets_rl();
  puVar10 = auStack_20;
  puVar6 = auStack_20;
  puVar8 = (undefined4 *)0x0;
  if (puRam00106640 != (undefined4 *)0x0) {
    puVar5 = auStack_10;
    pcVar9 = s_TST_DUT_SAV__060621c3 + 0xb;
    puVar3 = puRam00106640;
    do {
      rep_unspec(4,0x20);
      *puVar10 = *(undefined1 *)puVar3;
      iVar1 = sdfile_strcase_cmp(puVar5,pcVar9 + 0xfb);
      if (((iVar1 != 0) && (iVar1 = sdfile_strcase_cmp(puVar5,pcVar9), iVar1 != 0)) ||
         (iVar1 = sdfile_strcase_cmp(param_1,puVar5), iVar1 == 0)) {
        puVar8 = puVar3;
        break;
      }
      puVar3 = (undefined4 *)((int)puVar3 + *(int *)(puVar6 + 8));
    } while (*(short *)(puVar6 + 0xe) == 0);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  if (cRam00106908 == '\0') {
    uRam00fd1c00 = 0xc80;
    uRam00fd6014 = uRam00fd6014 & 0xa00;
    uRam00fd1c04 = 3;
                    /* WARNING: Subroutine does not return */
    FUN_0010bebe(0x10641c);
  }
  if (puVar8 != (undefined4 *)0x0) {
    *puVar8 = 0x1068e8;
    uRam001064a0 = 0x1068e8;
  }
  iVar2 = 0x798;
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar4 = 0;
  iVar1 = func_0x0001fd9a(0,0x2f,uRam00000000);
  if (iVar1 == 0) {
    iVar1 = func_0x0001fd8e(iVar4);
  }
  else {
    iVar1 = iVar1 - iVar4;
  }
  iVar7 = 0xf;
  func_0x0001fd76(iVar2,iVar4,0xf);
  *(undefined1 *)(iVar2 + iVar7) = 0;
  sdfile_str_to_upper(iVar2,iVar7);
  op_pop_pc_rl();
  return ((iVar4 + iVar1) - iRam0010663c) + (int)puRam00106640;
}


// ===== f_dut_tst_ver_get @ 0600f55c

/* B2: strings referenced by this function (disasm/function_strings.json):
     "DUT+TST+VER+GET+"
     "Media"
     "ring" */

void f_dut_tst_ver_get(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_0010ea22();
}


// ===== f_tst_btn_sta @ 06018a8e

/* B2: strings referenced by this function (disasm/function_strings.json):
     "TST+BTN+STA" */

void f_tst_btn_sta(int param_1)

{
  uint uVar1;
  undefined1 extraout_r0;
  undefined1 extraout_r0_00;
  undefined1 extraout_r0_01;
  undefined1 extraout_r0_02;
  undefined1 extraout_r0_03;
  undefined1 extraout_r0_04;
  undefined1 extraout_r0_05;
  undefined1 extraout_r0_06;
  undefined1 extraout_r0_07;
  undefined1 extraout_r0_08;
  undefined1 extraout_r0_09;
  undefined1 extraout_r0_10;
  undefined1 extraout_r0_11;
  undefined1 extraout_r0_12;
  undefined1 extraout_r0_13;
  undefined1 extraout_r0_14;
  undefined1 extraout_r0_15;
  undefined1 extraout_r0_16;
  undefined1 extraout_r0_17;
  undefined1 extraout_r0_18;
  undefined1 uVar2;
  undefined1 extraout_r0_19;
  undefined1 extraout_r0_20;
  char cVar3;
  undefined1 extraout_r0_21;
  undefined1 extraout_r0_22;
  undefined1 extraout_r0_23;
  undefined1 extraout_r0_24;
  undefined1 extraout_r0_25;
  undefined1 extraout_r0_26;
  undefined1 extraout_r0_27;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 extraout_var_01;
  undefined1 extraout_var_02;
  undefined1 extraout_var_03;
  undefined1 extraout_var_04;
  undefined1 extraout_var_05;
  undefined1 extraout_var_06;
  undefined1 extraout_var_07;
  undefined1 extraout_var_08;
  undefined1 extraout_var_09;
  undefined1 extraout_var_10;
  undefined1 extraout_var_11;
  undefined1 extraout_var_12;
  undefined1 extraout_var_13;
  undefined1 extraout_var_14;
  undefined1 extraout_var_15;
  undefined1 extraout_var_16;
  undefined1 extraout_var_17;
  undefined1 extraout_var_18;
  undefined1 uVar4;
  undefined1 extraout_var_19;
  undefined1 extraout_var_20;
  undefined1 extraout_var_21;
  undefined1 extraout_var_22;
  undefined1 extraout_var_23;
  undefined1 extraout_var_24;
  undefined1 extraout_var_25;
  undefined1 extraout_var_26;
  undefined1 extraout_var_27;
  undefined2 extraout_var_28;
  undefined2 extraout_var_29;
  undefined2 extraout_var_30;
  undefined2 extraout_var_31;
  undefined2 extraout_var_32;
  undefined2 extraout_var_33;
  undefined2 extraout_var_34;
  undefined2 extraout_var_35;
  undefined2 extraout_var_36;
  undefined2 extraout_var_37;
  undefined2 extraout_var_38;
  undefined2 extraout_var_39;
  undefined2 extraout_var_40;
  undefined2 extraout_var_41;
  undefined2 extraout_var_42;
  undefined2 extraout_var_43;
  undefined2 extraout_var_44;
  undefined2 extraout_var_45;
  undefined2 extraout_var_46;
  undefined2 extraout_var_47;
  undefined2 uVar5;
  undefined2 extraout_var_48;
  undefined2 extraout_var_49;
  undefined2 extraout_var_50;
  undefined2 extraout_var_51;
  undefined2 extraout_var_52;
  undefined2 extraout_var_53;
  undefined2 extraout_var_54;
  undefined2 extraout_var_55;
  undefined2 extraout_var_56;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  int iVar11;
  byte *pbVar12;
  undefined1 *puVar13;
  int iVar14;
  int iVar15;
  BADSPACEBASE *in_sp;
  uint *puVar16;
  undefined5 uVar17;
  undefined1 auStack_70 [4];
  undefined1 auStack_6c [64];
  char cStack_2c;
  char cStack_1d;
  undefined4 uStack_10;
  undefined2 uStack_c;
  
  op_push_rets_rl();
  puVar16 = (uint *)auStack_70;
  uVar10 = 0;
  uStack_c = 0;
  iVar14 = 0x6061d17;
  uStack_10 = 0;
  rep_unspec(4,0xd);
  cStack_1d = s_Vol_LinMusic_0606219c[0xb];
  rep_unspec(4,0xd);
  cStack_2c = s_Vol_LinMusic_0606219c[0xb];
  func_0x0001fd82((char)auStack_6c,0,0x40);
  *puVar16 = uVar10;
  func_0x0001fd7e((char)iVar14 + -0x13,param_1,0xf);
  uVar2 = (undefined1)uVar10;
  iVar15 = 0x106060;
  if (CONCAT22(extraout_var_28,CONCAT11(extraout_var,extraout_r0)) == 0) {
    uVar2 = SUB41((undefined1 *)((int)puVar16 + 0x60),0);
    FUN_06002d2e(uVar2);
    pbVar12 = (byte *)((int)puVar16 + 0x53);
    func_0x06018904(uVar2,pbVar12);
    *(undefined8 *)(iVar15 + 0x5d4) = 0;
    iVar8 = iVar14 + 0xb89;
    uVar2 = (undefined1)iVar8;
    uVar4 = (undefined1)((uint)iVar8 >> 8);
    uVar5 = (undefined2)((uint)iVar8 >> 0x10);
LAB_06018d2e:
    puVar9 = (undefined1 *)(iVar15 + 0x5b8);
    rep_unspec(4,0x10);
    *puVar9 = *(undefined1 *)CONCAT22(uVar5,CONCAT11(uVar4,uVar2));
    rep_unspec(4,0xc);
    puVar13 = (undefined1 *)(uint)*pbVar12;
    *(byte *)(iVar15 + 0x5c8) = *pbVar12;
LAB_06018d76:
    uVar2 = SUB41(puVar9,0);
    func_0x0001fd8e(uVar2,puVar13);
    uVar10 = op_ext_b0_u(CONCAT22(extraout_var_49,CONCAT11(extraout_var_20,extraout_r0_20)));
    goto LAB_06018d82;
  }
  func_0x0001fd7e((char)iVar14 + -0x50,param_1,0x10);
  if (CONCAT22(extraout_var_29,CONCAT11(extraout_var_00,extraout_r0_00)) == 0) {
    puVar13 = (undefined1 *)((int)puVar16 + 0x44);
    rep_unspec(4,4);
    *(undefined1 *)((int)puVar16 + 0x4c) = *(undefined1 *)(param_1 + 0x18);
    rep_unspec(4,8);
    *puVar13 = *(undefined1 *)(param_1 + 0x10);
    puVar9 = (undefined1 *)((int)puVar16 + 0x45);
    iVar11 = 0x2fe;
    for (iVar8 = 0; iVar8 != 6; iVar8 = iVar8 + 1) {
      iVar7 = iVar8 + iVar15;
      cVar3 = func_0x0601892e(*puVar13,puVar9);
      cVar3 = cVar3 << 4;
      uVar17 = func_0x0601892e(puVar13[1]);
      puVar9 = (undefined1 *)uVar17;
      *(char *)(iVar7 + iVar11) = (char)((uint5)uVar17 >> 0x20) + cVar3;
      puVar13 = puVar13 + 2;
    }
    uVar2 = 0;
    uVar4 = 0;
    *(undefined2 *)((int)puVar16 + 0x6c) = 0;
    puVar9 = (undefined1 *)(iVar15 + 0x303);
    *(undefined4 *)((int)puVar16 + 0x68) = 0;
    uVar5 = 0;
    while (CONCAT22(uVar5,CONCAT11(uVar4,uVar2)) != 6) {
      uVar6 = *puVar9;
      puVar9 = puVar9 + -1;
      *(undefined1 *)((int)puVar16 + CONCAT22(uVar5,CONCAT11(uVar4,uVar2)) + 0x68) = uVar6;
      iVar8 = CONCAT22(uVar5,CONCAT11(uVar4,uVar2)) + 1;
      uVar2 = (undefined1)iVar8;
      uVar4 = (undefined1)((uint)iVar8 >> 8);
      uVar5 = (undefined2)((uint)iVar8 >> 0x10);
    }
    rep_unspec(4,6);
    *(undefined1 *)(iVar15 + 0x2fe) = *(undefined1 *)((int)puVar16 + 0x68);
    puVar9 = (undefined1 *)(iVar15 + 0x5b8);
    func_0x0001fd82((char)puVar9,0,0x24);
    func_0x0601899c();
    if (CONCAT22(extraout_var_48,CONCAT11(extraout_var_19,extraout_r0_19)) == 0) {
      iVar8 = iVar14 + 0x83b;
      uVar2 = (undefined1)iVar8;
      uVar4 = (undefined1)((uint)iVar8 >> 8);
      uVar5 = (undefined2)((uint)iVar8 >> 0x10);
    }
    else {
      FUN_06002d2e((char)(undefined1 *)((int)puVar16 + 0x60));
      iVar8 = iVar14 + 0x84d;
      uVar2 = (undefined1)iVar8;
      uVar4 = (undefined1)((uint)iVar8 >> 8);
      uVar5 = (undefined2)((uint)iVar8 >> 0x10);
    }
LAB_06018d6e:
    rep_unspec(4,0x11);
    *puVar9 = *(undefined1 *)CONCAT22(uVar5,CONCAT11(uVar4,uVar2));
    puVar13 = puVar9 + 1;
    goto LAB_06018d76;
  }
  func_0x0001fd7e((char)iVar14 + -3,param_1,0xf);
  if (CONCAT22(extraout_var_30,CONCAT11(extraout_var_01,extraout_r0_01)) == 0) {
    uVar2 = SUB41((undefined1 *)((int)puVar16 + 0x60),0);
    FUN_06002d2e(uVar2);
    *(byte *)((int)puVar16 + 99) = *(byte *)((int)puVar16 + 99) & 0xf0;
    pbVar12 = (byte *)((int)puVar16 + 0x53);
    func_0x06018904(uVar2,pbVar12);
    *(undefined8 *)(iVar15 + 0x5d4) = 0;
    iVar8 = iVar14 + 0xba6;
    uVar2 = (undefined1)iVar8;
    uVar4 = (undefined1)((uint)iVar8 >> 8);
    uVar5 = (undefined2)((uint)iVar8 >> 0x10);
    goto LAB_06018d2e;
  }
  func_0x0001fd7e((char)iVar14 + ')',param_1,0x13);
  if (CONCAT22(extraout_var_31,CONCAT11(extraout_var_02,extraout_r0_02)) == 0) {
    puVar9 = (undefined1 *)(iVar15 + 0x730);
    rep_unspec(4,0x14);
    *puVar9 = *(undefined1 *)(iVar14 + 0xa79);
    func_0x0001fd82((char)iVar15 + 'O',0,0x21);
    rep_unspec(4,0xb);
    puVar13 = (undefined1 *)(iVar14 + 0x3b2);
    puVar9[0x14] = *(undefined1 *)(iVar14 + 0x3b1);
    goto LAB_06018d76;
  }
  func_0x0001fd7e((char)iVar14 + '\r',param_1,0xf);
  if (CONCAT22(extraout_var_32,CONCAT11(extraout_var_03,extraout_r0_03)) == 0) goto LAB_06018d8c;
  func_0x0001fd7e((char)iVar14 + -0x2e,param_1,0x10);
  if (CONCAT22(extraout_var_33,CONCAT11(extraout_var_04,extraout_r0_04)) == 0) {
    param_1 = param_1 + 0x10;
    func_0x0001fd8e((char)param_1);
    uVar10 = op_ext_b0_u(CONCAT22(extraout_var_52,CONCAT11(extraout_var_23,extraout_r0_23)));
    puVar9 = (undefined1 *)((int)puVar16 + 4);
    func_0x0001fd76((char)puVar9,param_1,uVar10);
                    /* WARNING: Subroutine does not return */
    FUN_06003050(0x65,puVar9,0x20);
  }
  func_0x0001fd7e((char)iVar14 + -99,param_1,0xc);
  if (CONCAT22(extraout_var_34,CONCAT11(extraout_var_05,extraout_r0_05)) == 0) {
    puVar9 = (undefined1 *)(iVar15 + 0x5b8);
    func_0x0001fd82((char)puVar9,0,0x24);
    uVar1 = ((uint)*(byte *)(param_1 + 0xc) * 10 + (uint)*(byte *)(param_1 + 0xd)) - 0x210;
    *puVar16 = uVar1;
    if (uVar1 < 0x4f) {
      uVar10 = op_ext_b0_u(uVar1);
      effect_nodes_open((char)uVar10);
      iVar8 = iVar14 + 0x534;
      uVar2 = (undefined1)iVar8;
      uVar4 = (undefined1)((uint)iVar8 >> 8);
      uVar5 = (undefined2)((uint)iVar8 >> 0x10);
    }
    else {
      iVar8 = iVar14 + 0x542;
      uVar2 = (undefined1)iVar8;
      uVar4 = (undefined1)((uint)iVar8 >> 8);
      uVar5 = (undefined2)((uint)iVar8 >> 0x10);
    }
    rep_unspec(4,0xd);
    *puVar9 = *(undefined1 *)CONCAT22(uVar5,CONCAT11(uVar4,uVar2));
    func_0x0001fd8e((char)puVar9,puVar9 + 1);
    uVar10 = op_ext_b0_u(CONCAT22(extraout_var_53,CONCAT11(extraout_var_24,extraout_r0_24)));
    uVar2 = SUB41(puVar9,0);
    goto LAB_06018d82;
  }
  func_0x0001fd7e((char)iVar14 + -0x1d,param_1,0x10);
  if (CONCAT22(extraout_var_35,CONCAT11(extraout_var_06,extraout_r0_06)) == 0) {
    uVar2 = *(undefined1 *)(param_1 + 0x10);
    *puVar16 = 0xf04 - ((uint)*(byte *)(param_1 + 0x12) + (uint)*(byte *)(param_1 + 0x11) * 10 +
                       -0x210);
    FUN_060426a4(uVar2);
    rep_unspec(2,0x13);
    *(undefined1 *)(iVar15 + 0x5c9) = 0;
    puVar9 = (undefined1 *)(iVar15 + 0x5b8);
    iVar8 = iVar14 + 0x883;
    uVar2 = (undefined1)iVar8;
    uVar4 = (undefined1)((uint)iVar8 >> 8);
    uVar5 = (undefined2)((uint)iVar8 >> 0x10);
    goto LAB_06018d6e;
  }
  func_0x0001fd7e((char)iVar14 + -0x56,param_1,0xc);
  if (CONCAT22(extraout_var_36,CONCAT11(extraout_var_07,extraout_r0_07)) == 0) {
    *puVar16 = (uint)*(byte *)(param_1 + 0xd) * 10 + (uint)*(byte *)(param_1 + 0xe) + -0x210;
    func_0x0001fd82((char)iVar15 + -0x48,0,0x24);
                    /* WARNING: Subroutine does not return */
    FUN_06003050(8,puVar16,4);
  }
  func_0x0001fd7e((char)iVar14 + '\x1d',param_1,0xf);
  if (CONCAT22(extraout_var_37,CONCAT11(extraout_var_08,extraout_r0_08)) == 0) {
    FUN_06001fd8(8,puVar16,4);
    uVar1 = *puVar16;
    if ((int)uVar1 < 0) {
      uVar1 = -uVar1;
    }
    *puVar16 = uVar1;
    rep_unspec(2,0x11);
    *(undefined1 *)(iVar15 + 0x5cb) = 0;
    puVar9 = (undefined1 *)(iVar15 + 0x5b8);
    rep_unspec(4,0x10);
    *puVar9 = *(undefined1 *)(iVar14 + 0xa3d);
    *(undefined1 *)(iVar15 + 0x5c8) = 0x2b;
    cVar3 = (char)(uVar1 / 10);
    puVar13 = (undefined1 *)((uVar1 / 10) * 10);
    *(char *)(iVar15 + 0x5c9) = cVar3 + '0';
    *(char *)(iVar15 + 0x5ca) = (char)uVar1 + cVar3 * -10 + '0';
    goto LAB_06018d76;
  }
  func_0x0001fd7e((char)iVar14 + -0x43,param_1,0xb);
  if (CONCAT22(extraout_var_38,CONCAT11(extraout_var_09,extraout_r0_09)) == 0) {
    rep_unspec(2,0x17);
    *(undefined1 *)(iVar15 + 0x5c5) = uVar2;
    puVar9 = (undefined1 *)(iVar15 + 0x5b8);
    rep_unspec(4,0xd);
    *puVar9 = *(undefined1 *)(iVar14 + 0x550);
    func_0x0001fd8e((char)puVar9,iVar15 + 0x5b9);
    uVar10 = op_ext_b0_u(CONCAT22(extraout_var_54,CONCAT11(extraout_var_25,extraout_r0_25)));
    FUN_0602e380((char)puVar9,uVar10);
    FUN_060745c6();
    op_ext_b0_u(CONCAT22(extraout_var_55,CONCAT11(extraout_var_26,extraout_r0_26)) + -0x33);
                    /* WARNING: Subroutine does not return */
    FUN_060745b6(4,0,0);
  }
  func_0x0001fd7e((char)iVar14 + '-',param_1,0xf);
  if (CONCAT22(extraout_var_39,CONCAT11(extraout_var_10,extraout_r0_10)) == 0) {
    puVar9 = (undefined1 *)(iVar15 + 0x5b8);
    rep_unspec(4,0x10);
    *puVar9 = *(undefined1 *)(iVar14 + 0x7f4);
    rep_unspec(2,0xe);
    *(undefined1 *)(iVar15 + 0x5ce) = 0;
    rep_unspec(4,3);
    *(undefined1 *)(iVar15 + 0x5c8) = *(undefined1 *)(iVar14 + 0x18);
    puVar13 = (undefined1 *)0x2b;
    *(undefined1 *)(iVar15 + 0x5cb) = 0x2b;
    *(undefined2 *)(iVar15 + 0x5cc) = 0x3130;
    goto LAB_06018d76;
  }
  func_0x0001fd7e((char)iVar14 + -0x37,param_1,0xb);
  if (CONCAT22(extraout_var_40,CONCAT11(extraout_var_11,extraout_r0_11)) == 0) {
    rep_unspec(2,0x11);
    *(undefined1 *)(iVar15 + 0x5cb) = 0;
    puVar9 = (undefined1 *)(iVar15 + 0x5b8);
    rep_unspec(4,0x13);
    *puVar9 = *(undefined1 *)(iVar14 + 0x73d);
    func_0x0001fd8e((char)puVar9,iVar15 + 0x5b9);
    uVar10 = op_ext_b0_u(CONCAT22(extraout_var_56,CONCAT11(extraout_var_27,extraout_r0_27)));
    FUN_0602e380((char)puVar9,uVar10);
                    /* WARNING: Subroutine does not return */
    f_iis0_rx2(0x77,0);
  }
  func_0x0001fd7e((char)iVar14 + -0x2b,param_1,0xb);
  if (CONCAT22(extraout_var_41,CONCAT11(extraout_var_12,extraout_r0_12)) == 0) {
    uVar2 = 0x9c;
    uVar4 = 1;
LAB_0601903c:
    uVar6 = 1;
  }
  else {
    func_0x0001fd7e((char)iVar14 + '^',param_1,0xd);
    if (CONCAT22(extraout_var_42,CONCAT11(extraout_var_13,extraout_r0_13)) != 0) {
      func_0x0001fd7e((char)iVar14 + 'l',param_1,0xd);
      if (CONCAT22(extraout_var_43,CONCAT11(extraout_var_14,extraout_r0_14)) != 0) {
        func_0x0001fd7e((char)iVar14 + 'z',param_1,0xd);
        if (CONCAT22(extraout_var_44,CONCAT11(extraout_var_15,extraout_r0_15)) == 0) {
          uVar2 = 1;
LAB_0601905c:
          *(undefined1 *)(iVar15 + 0x876) = uVar2;
          uVar2 = 0x7f;
          uVar4 = 8;
          uVar6 = 0;
          goto LAB_06019064;
        }
        func_0x0001fd7e((char)iVar14 + -0x78,param_1,0xd);
        if (CONCAT22(extraout_var_45,CONCAT11(extraout_var_16,extraout_r0_16)) != 0) {
          func_0x0001fd7e((char)iVar14 + -0x6a,param_1,0xd);
          if (CONCAT22(extraout_var_46,CONCAT11(extraout_var_17,extraout_r0_17)) == 0) {
            uVar2 = 2;
            goto LAB_0601905c;
          }
          func_0x0001fd7e((char)iVar14 + -0x5c,param_1,0xd);
          if (CONCAT22(extraout_var_47,CONCAT11(extraout_var_18,extraout_r0_18)) != 0)
          goto LAB_06018d88;
        }
      }
      uVar2 = 0x7f;
      uVar4 = 8;
      goto LAB_0601903c;
    }
    uVar6 = 0;
    *(undefined1 *)(iVar15 + 0x876) = 0;
    uVar2 = 0x7f;
    uVar4 = 8;
  }
LAB_06019064:
  *(undefined1 *)(iVar15 + (uint)CONCAT11(uVar4,uVar2)) = uVar6;
LAB_06018d88:
  do {
    puVar16 = (uint *)((int)puVar16 + 0x70);
    op_pop_pc_rl();
LAB_06018d8c:
    puVar9 = (undefined1 *)((int)puVar16 + 4);
    FUN_06001fd8(0x65,puVar9,0x20);
    cVar3 = (char)iVar15 + -0x80;
    func_0x0001fd82(cVar3,0,0x30);
    puVar13 = (undefined1 *)(iVar15 + 0x770);
    rep_unspec(4,0x10);
    *puVar13 = *(undefined1 *)(iVar14 + 0x7c1);
    func_0x0001fd8e((char)puVar9,iVar15 + 0x771);
    uVar2 = SUB41(puVar13,0);
    func_0x0001fd76(cVar3,puVar9,CONCAT22(extraout_var_50,CONCAT11(extraout_var_21,extraout_r0_21)))
    ;
    func_0x0001fd8e(uVar2);
    uVar10 = op_ext_b0_u(CONCAT22(extraout_var_51,CONCAT11(extraout_var_22,extraout_r0_22)));
LAB_06018d82:
    FUN_0602e380(uVar2,uVar10);
  } while( true );
}


