// ===== FUN_060866e6 @ 060866e6

/* WARNING: Possible PIC construction at 0x06086a00: Changing call to branch */
/* WARNING: Possible PIC construction at 0x06086aa0: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x06086a02) */
/* WARNING: Removing unreachable block (ram,0x06086a18) */
/* WARNING: Removing unreachable block (ram,0x06086a50) */
/* WARNING: Removing unreachable block (ram,0x06086a54) */
/* WARNING: Removing unreachable block (ram,0x06086a7a) */
/* WARNING: Removing unreachable block (ram,0x06086a5c) */
/* WARNING: Removing unreachable block (ram,0x06086a88) */
/* WARNING: Removing unreachable block (ram,0x06086a60) */
/* WARNING: Removing unreachable block (ram,0x06086a94) */
/* WARNING: Removing unreachable block (ram,0x06086a64) */
/* WARNING: Removing unreachable block (ram,0x06086a68) */
/* WARNING: Removing unreachable block (ram,0x06086a9e) */
/* WARNING: Removing unreachable block (ram,0x06086a22) */
/* WARNING: Removing unreachable block (ram,0x06086a48) */
/* WARNING: Removing unreachable block (ram,0x06086a28) */
/* WARNING: Removing unreachable block (ram,0x06086a2e) */
/* WARNING: Removing unreachable block (ram,0x06086a74) */
/* WARNING: Removing unreachable block (ram,0x06086aa0) */
/* WARNING: Removing unreachable block (ram,0x06086a3a) */
/* WARNING: Removing unreachable block (ram,0x06086aa4) */

void FUN_060866e6(char *param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint extraout_r1;
  undefined4 uVar9;
  uint uVar10;
  byte bVar11;
  undefined4 *puVar12;
  int *piVar13;
  undefined4 uVar14;
  int *piVar15;
  undefined4 *puVar16;
  byte *pbVar17;
  int *piVar18;
  int iVar19;
  BADSPACEBASE *in_sp;
  undefined1 *puVar20;
  undefined4 *puVar21;
  undefined2 *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  undefined2 *puVar25;
  undefined8 uVar26;
  
  op_push_rets_rl();
  puVar12 = (undefined4 *)0x105070;
  if (iRam00105070 != 0) {
    iVar5 = iRam00105070;
    FUN_0608adbc(*(undefined4 *)(iRam00105070 + 0x28));
    FUN_0608adbc(*(undefined4 *)(iVar5 + 0x50));
    param_1 = (char *)FUN_0608adbc(iVar5);
    *puVar12 = 0;
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar12 = (undefined4 *)((int)in_sp + -0x18);
  puVar20 = (undefined1 *)((int)in_sp + -0x18);
  if (iRam00105070 == 0) {
    iVar5 = FUN_0608adc6(0x58);
    puVar12 = (undefined4 *)puVar20;
    if (iVar5 == 0) {
      func_0x0bfb3c70();
      puVar12 = (undefined4 *)puVar20;
    }
    pbVar17 = (byte *)(iVar5 + 0x34);
    *(undefined4 *)(iVar5 + 0x54) = 0;
    *(undefined2 *)(iVar5 + 0x3c) = 0;
    uVar26 = func_0x0bfcdb0a();
    *(int *)(iVar5 + 0x20) = (int)((ulonglong)uVar26 >> 0x20);
    piVar13 = (int *)(iVar5 + 0x44);
    *piVar13 = iVar5;
    *(int *)(iVar5 + 4) = iVar5;
    *(undefined4 *)(iVar5 + 8) = 0x10bbf8;
    *(undefined4 *)(iVar5 + 0xc) = 0x10bc10;
    *(undefined4 *)(iVar5 + 0x14) = 0x10bc26;
    *(int *)(iVar5 + 0x18) = (int)uVar26;
    pbVar17[0x10] = 0x10;
    pbVar17[0x11] = 0;
    pbVar17[0x12] = 0;
    pbVar17[0x13] = 0;
    pbVar17[0x14] = 2;
    pbVar17[0x15] = 0;
    pbVar17[0x16] = 0;
    pbVar17[0x17] = 0;
    pbVar17[0x18] = 0;
    pbVar17[0x19] = 0x77;
    pbVar17[0x1a] = 1;
    pbVar17[0x1b] = 0;
    if ((param_1 != (char *)0x0) && (*param_1 == -0x56)) {
      bVar11 = param_1[1];
      *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)((bVar11 >> 3 & 0x1c) + 0x6062484);
      *pbVar17 = bVar11 >> 3 & 3;
    }
    (**(code **)(iVar5 + 0x60))(*(code **)(iVar5 + 0x60));
    iVar6 = FUN_0608adc6();
    *(int *)(iVar5 + 0x28) = iVar6;
    if (iVar6 == 0) {
      func_0x0bfb3c70();
    }
    iVar19 = iVar5 + 4;
    iVar6 = (*(code *)piVar13[8])((code *)piVar13[8]);
    if (iVar6 == 0) {
      puVar16 = (undefined4 *)(iVar5 + 0x50);
    }
    else {
      iVar6 = FUN_0608adc6();
      puVar16 = (undefined4 *)(iVar5 + 0x50);
      *(int *)(pbVar17 + 0x1c) = iVar6;
      if (iVar6 == 0) {
        func_0x0bfb3c70();
      }
    }
    uVar9 = *puVar16;
    uVar1 = *(undefined4 *)(iVar5 + 0x28);
    pcVar2 = *(code **)(iVar19 + 4);
    *puVar12 = piVar13;
    uVar14 = 0;
    (*pcVar2)(uVar1,uVar9,0);
    *(undefined4 *)((int)puVar12 + 0x14) = 0x601097c;
    pcVar2 = *(code **)(*(int *)(iVar5 + 0x20) + 0x30);
    (*pcVar2)(*(undefined4 *)(iVar5 + 0x28),0x82,(undefined1 *)((int)puVar12 + 0x14),pcVar2);
    if (*pbVar17 == 0) {
      uVar4 = 4;
    }
    else if (*pbVar17 == 2) {
      uVar4 = 1;
    }
    else {
      uVar4 = 2;
    }
    *(undefined4 *)((int)puVar12 + 4) = *(undefined4 *)(iVar5 + 0x2c);
    *(undefined2 *)((int)puVar12 + 8) = uVar4;
    *(undefined2 *)((int)puVar12 + 10) = 1;
    *(undefined4 *)((int)puVar12 + 0xc) = 0x400;
    pcVar2 = *(code **)(*(int *)(iVar5 + 0x20) + 0x30);
    (*pcVar2)(*(undefined4 *)(iVar5 + 0x28),0x84,(undefined1 *)((int)puVar12 + 4),pcVar2);
    *(undefined4 *)((int)puVar12 + 0x10) = uVar14;
    pcVar2 = *(code **)(*(int *)(iVar5 + 0x20) + 0x30);
    (*pcVar2)(*(undefined4 *)(iVar5 + 0x28),0x80,(undefined1 *)((int)puVar12 + 0x10),pcVar2);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar21 = (undefined4 *)((int)puVar12 + 0x10);
  iVar5 = 0;
  piVar13 = (int *)FUN_0608adc6(0x58);
  if (piVar13 == (int *)0x0) {
    func_0x0bfb3c70();
  }
  *piVar13 = iVar5;
  piVar13[0xe] = 0;
  uVar26 = func_0x0bfcdb0a();
  iVar6 = (int)((ulonglong)uVar26 >> 0x20);
  piVar13[8] = iVar6;
  piVar13[1] = (int)piVar13;
  piVar13[2] = (int)FUN_060547b6;
  piVar13[4] = 0x60547f4;
  piVar13[3] = 0x10bbda;
  piVar13[5] = 0x10bbf0;
  piVar13[6] = (int)uVar26;
  cVar3 = *(char *)(iVar5 + 0x81);
  iVar19 = 0x18;
  if (cVar3 == '\0') {
    iVar19 = 0x10;
  }
  piVar13[0x11] = iVar19;
  *(char *)(iVar5 + 0x19) = cVar3;
  piVar13[0x12] = 2;
  piVar13[0x13] = 96000;
  piVar7 = piVar13 + 0x11;
  pcVar2 = *(code **)(iVar6 + 0x1c);
  (*pcVar2)(piVar7,pcVar2);
  iVar5 = FUN_0608adc6();
  piVar13[10] = iVar5;
  if (iVar5 == 0) {
    func_0x0bfb3c70();
  }
  piVar15 = piVar13 + 1;
  iVar5 = (*(code *)piVar7[8])((code *)piVar7[8]);
  if (iVar5 == 0) {
    piVar18 = piVar13 + 0x14;
  }
  else {
    iVar5 = FUN_0608adc6();
    piVar18 = piVar13 + 0x14;
    *piVar18 = iVar5;
    if (iVar5 == 0) {
      func_0x0bfb3c70();
    }
  }
  iVar5 = *piVar18;
  iVar6 = piVar13[10];
  pcVar2 = (code *)piVar15[1];
  *puVar21 = piVar7;
  (*pcVar2)(iVar6,iVar5,0);
  *(undefined4 *)((int)puVar21 + 4) = 0x601097c;
  (**(code **)(piVar13[8] + 0x30))
            (piVar13[10],0x82,(undefined1 *)((int)puVar21 + 4),*(code **)(piVar13[8] + 0x30));
  puVar22 = (undefined2 *)((int)puVar21 + 8);
  op_pop_pc_rl();
  uVar10 = extraout_r1;
  do {
    op_push_rets_rl();
    puVar23 = (undefined1 *)((int)puVar22 + -0xc);
    puVar24 = (undefined1 *)((int)puVar22 + -0xc);
    pbVar17 = (byte *)(piVar13 + 0xc);
    if ((*(byte *)((int)piVar13 + 0x32) != uVar10) ||
       (piVar7 = (int *)(uint)*(byte *)((int)piVar13 + 0x33),
       puVar25 = (undefined2 *)((int)puVar22 + -0xc), piVar7 == (int *)0x0)) {
      iVar5 = op_ext_b0_u(uVar10);
      if (iVar5 - 0x25U < 4) {
        uVar8 = (uint)*pbVar17;
        if (uVar8 == 2) {
          uVar9 = 0;
        }
        else {
          puVar23 = (undefined1 *)((int)puVar22 + -0xc);
          if (uVar8 != 1) goto LAB_06086998;
          uVar9 = 1;
        }
        *(undefined4 *)((int)puVar22 + -8) = uVar9;
        puVar23 = (undefined1 *)((int)puVar22 + -0xc);
LAB_06086998:
        piVar13[9] = uVar8;
        puVar24 = puVar23;
      }
      else {
        if (iVar5 == 0x11) {
LAB_0608696a:
          uVar8 = 1;
          *(undefined4 *)((int)puVar22 + -8) = 1;
          puVar23 = (undefined1 *)((int)puVar22 + -0xc);
          goto LAB_06086998;
        }
        if (iVar5 == 0x12) {
          *(undefined4 *)((int)puVar22 + -8) = 2;
          *(undefined4 *)((int)puVar22 + -0xc) = 0;
          (**(code **)(piVar13[8] + 0x30))
                    (piVar13[10],0x85,(undefined1 *)((int)puVar22 + -0xc),
                     *(code **)(piVar13[8] + 0x30));
          uVar8 = 1;
          goto LAB_06086998;
        }
        if (iVar5 == 0x13) {
          uVar8 = 1;
          if (*pbVar17 == 2) {
            *(undefined4 *)((int)puVar22 + -8) = 0x220;
            *(undefined4 *)((int)puVar22 + -4) = 0x220;
            puVar23 = (undefined1 *)((int)puVar22 + -0xc);
          }
          else {
            puVar23 = (undefined1 *)((int)puVar22 + -0xc);
            if (*pbVar17 == 1) goto LAB_0608696a;
          }
          goto LAB_06086998;
        }
      }
      bVar11 = (byte)uVar10;
      piVar7 = (int *)(**(code **)(piVar13[8] + 0x30))
                                (piVar13[10],0x81,puVar24 + 4,*(code **)(piVar13[8] + 0x30));
      pbVar17[2] = bVar11;
      puVar25 = (undefined2 *)puVar24;
    }
    op_pop_pc_rl();
    op_push_rets_rl();
    puVar22 = puVar25 + -2;
    piVar15 = piVar7 + 0xc;
    if ((char)piVar7[0xd] == '\0') {
      uVar4 = 4;
    }
    else if ((char)piVar7[0xd] == '\x02') {
      uVar4 = 1;
    }
    else {
      uVar4 = 2;
    }
    *(int *)(puVar25 + -2) = piVar7[0xb];
    *puVar25 = uVar4;
    uVar9 = 1;
    puVar25[1] = 1;
    *(undefined4 *)(puVar25 + 2) = 0x400;
    (**(code **)(piVar7[8] + 0x30))(piVar7[10],0x84,puVar25 + -2,*(code **)(piVar7[8] + 0x30));
    *(undefined4 *)((int)puVar22 + 0xc) = uVar9;
    piVar13 = piVar7;
    (**(code **)(piVar7[8] + 0x30))
              (piVar7[10],0x80,(undefined1 *)((int)puVar22 + 0xc),*(code **)(piVar7[8] + 0x30));
    uVar10 = (uint)*(byte *)((int)piVar15 + 2);
  } while( true );
}


// ===== FUN_06086712 @ 06086712

/* WARNING: Possible PIC construction at 0x06086a00: Changing call to branch */
/* WARNING: Possible PIC construction at 0x06086aa0: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x06086a02) */
/* WARNING: Removing unreachable block (ram,0x06086a18) */
/* WARNING: Removing unreachable block (ram,0x06086a50) */
/* WARNING: Removing unreachable block (ram,0x06086a54) */
/* WARNING: Removing unreachable block (ram,0x06086a7a) */
/* WARNING: Removing unreachable block (ram,0x06086a5c) */
/* WARNING: Removing unreachable block (ram,0x06086a88) */
/* WARNING: Removing unreachable block (ram,0x06086a60) */
/* WARNING: Removing unreachable block (ram,0x06086a94) */
/* WARNING: Removing unreachable block (ram,0x06086a64) */
/* WARNING: Removing unreachable block (ram,0x06086a68) */
/* WARNING: Removing unreachable block (ram,0x06086a9e) */
/* WARNING: Removing unreachable block (ram,0x06086a22) */
/* WARNING: Removing unreachable block (ram,0x06086a48) */
/* WARNING: Removing unreachable block (ram,0x06086a28) */
/* WARNING: Removing unreachable block (ram,0x06086a2e) */
/* WARNING: Removing unreachable block (ram,0x06086a74) */
/* WARNING: Removing unreachable block (ram,0x06086aa0) */
/* WARNING: Removing unreachable block (ram,0x06086a3a) */
/* WARNING: Removing unreachable block (ram,0x06086aa4) */

void FUN_06086712(char *param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint extraout_r1;
  undefined4 uVar9;
  uint uVar10;
  byte bVar11;
  int *piVar12;
  undefined4 uVar13;
  int *piVar14;
  undefined4 *puVar15;
  byte *pbVar16;
  int *piVar17;
  int iVar18;
  BADSPACEBASE *in_sp;
  undefined1 *puVar19;
  undefined4 *puVar20;
  undefined4 *puVar21;
  undefined2 *puVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  undefined2 *puVar25;
  undefined8 uVar26;
  undefined1 auStack_18 [24];
  
  op_push_rets_rl();
  puVar20 = (undefined4 *)auStack_18;
  puVar19 = auStack_18;
  if (iRam00105070 == 0) {
    iVar5 = FUN_0608adc6(0x58);
    puVar20 = (undefined4 *)puVar19;
    if (iVar5 == 0) {
      func_0x0bfb3c70();
      puVar20 = (undefined4 *)puVar19;
    }
    pbVar16 = (byte *)(iVar5 + 0x34);
    *(undefined4 *)(iVar5 + 0x54) = 0;
    *(undefined2 *)(iVar5 + 0x3c) = 0;
    uVar26 = func_0x0bfcdb0a();
    *(int *)(iVar5 + 0x20) = (int)((ulonglong)uVar26 >> 0x20);
    piVar12 = (int *)(iVar5 + 0x44);
    *piVar12 = iVar5;
    *(int *)(iVar5 + 4) = iVar5;
    *(undefined4 *)(iVar5 + 8) = 0x10bbf8;
    *(undefined4 *)(iVar5 + 0xc) = 0x10bc10;
    *(undefined4 *)(iVar5 + 0x14) = 0x10bc26;
    *(int *)(iVar5 + 0x18) = (int)uVar26;
    pbVar16[0x10] = 0x10;
    pbVar16[0x11] = 0;
    pbVar16[0x12] = 0;
    pbVar16[0x13] = 0;
    pbVar16[0x14] = 2;
    pbVar16[0x15] = 0;
    pbVar16[0x16] = 0;
    pbVar16[0x17] = 0;
    pbVar16[0x18] = 0;
    pbVar16[0x19] = 0x77;
    pbVar16[0x1a] = 1;
    pbVar16[0x1b] = 0;
    if ((param_1 != (char *)0x0) && (*param_1 == -0x56)) {
      bVar11 = param_1[1];
      *(undefined4 *)(iVar5 + 0x2c) = *(undefined4 *)((bVar11 >> 3 & 0x1c) + 0x6062484);
      *pbVar16 = bVar11 >> 3 & 3;
    }
    (**(code **)(iVar5 + 0x60))(*(code **)(iVar5 + 0x60));
    iVar6 = FUN_0608adc6();
    *(int *)(iVar5 + 0x28) = iVar6;
    if (iVar6 == 0) {
      func_0x0bfb3c70();
    }
    iVar18 = iVar5 + 4;
    iVar6 = (*(code *)piVar12[8])((code *)piVar12[8]);
    if (iVar6 == 0) {
      puVar15 = (undefined4 *)(iVar5 + 0x50);
    }
    else {
      iVar6 = FUN_0608adc6();
      puVar15 = (undefined4 *)(iVar5 + 0x50);
      *(int *)(pbVar16 + 0x1c) = iVar6;
      if (iVar6 == 0) {
        func_0x0bfb3c70();
      }
    }
    uVar9 = *puVar15;
    uVar1 = *(undefined4 *)(iVar5 + 0x28);
    pcVar2 = *(code **)(iVar18 + 4);
    *puVar20 = piVar12;
    uVar13 = 0;
    (*pcVar2)(uVar1,uVar9,0);
    *(undefined4 *)((int)puVar20 + 0x14) = 0x601097c;
    pcVar2 = *(code **)(*(int *)(iVar5 + 0x20) + 0x30);
    (*pcVar2)(*(undefined4 *)(iVar5 + 0x28),0x82,(undefined1 *)((int)puVar20 + 0x14),pcVar2);
    if (*pbVar16 == 0) {
      uVar4 = 4;
    }
    else if (*pbVar16 == 2) {
      uVar4 = 1;
    }
    else {
      uVar4 = 2;
    }
    *(undefined4 *)((int)puVar20 + 4) = *(undefined4 *)(iVar5 + 0x2c);
    *(undefined2 *)((int)puVar20 + 8) = uVar4;
    *(undefined2 *)((int)puVar20 + 10) = 1;
    *(undefined4 *)((int)puVar20 + 0xc) = 0x400;
    pcVar2 = *(code **)(*(int *)(iVar5 + 0x20) + 0x30);
    (*pcVar2)(*(undefined4 *)(iVar5 + 0x28),0x84,(undefined1 *)((int)puVar20 + 4),pcVar2);
    *(undefined4 *)((int)puVar20 + 0x10) = uVar13;
    pcVar2 = *(code **)(*(int *)(iVar5 + 0x20) + 0x30);
    (*pcVar2)(*(undefined4 *)(iVar5 + 0x28),0x80,(undefined1 *)((int)puVar20 + 0x10),pcVar2);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar21 = (undefined4 *)((int)puVar20 + 0x10);
  iVar5 = 0;
  piVar12 = (int *)FUN_0608adc6(0x58);
  if (piVar12 == (int *)0x0) {
    func_0x0bfb3c70();
  }
  *piVar12 = iVar5;
  piVar12[0xe] = 0;
  uVar26 = func_0x0bfcdb0a();
  iVar6 = (int)((ulonglong)uVar26 >> 0x20);
  piVar12[8] = iVar6;
  piVar12[1] = (int)piVar12;
  piVar12[2] = (int)FUN_060547b6;
  piVar12[4] = 0x60547f4;
  piVar12[3] = 0x10bbda;
  piVar12[5] = 0x10bbf0;
  piVar12[6] = (int)uVar26;
  cVar3 = *(char *)(iVar5 + 0x81);
  iVar18 = 0x18;
  if (cVar3 == '\0') {
    iVar18 = 0x10;
  }
  piVar12[0x11] = iVar18;
  *(char *)(iVar5 + 0x19) = cVar3;
  piVar12[0x12] = 2;
  piVar12[0x13] = 96000;
  piVar7 = piVar12 + 0x11;
  pcVar2 = *(code **)(iVar6 + 0x1c);
  (*pcVar2)(piVar7,pcVar2);
  iVar5 = FUN_0608adc6();
  piVar12[10] = iVar5;
  if (iVar5 == 0) {
    func_0x0bfb3c70();
  }
  piVar14 = piVar12 + 1;
  iVar5 = (*(code *)piVar7[8])((code *)piVar7[8]);
  if (iVar5 == 0) {
    piVar17 = piVar12 + 0x14;
  }
  else {
    iVar5 = FUN_0608adc6();
    piVar17 = piVar12 + 0x14;
    *piVar17 = iVar5;
    if (iVar5 == 0) {
      func_0x0bfb3c70();
    }
  }
  iVar5 = *piVar17;
  iVar6 = piVar12[10];
  pcVar2 = (code *)piVar14[1];
  *puVar21 = piVar7;
  (*pcVar2)(iVar6,iVar5,0);
  *(undefined4 *)((int)puVar21 + 4) = 0x601097c;
  (**(code **)(piVar12[8] + 0x30))
            (piVar12[10],0x82,(undefined1 *)((int)puVar21 + 4),*(code **)(piVar12[8] + 0x30));
  puVar22 = (undefined2 *)((int)puVar21 + 8);
  op_pop_pc_rl();
  uVar10 = extraout_r1;
  do {
    op_push_rets_rl();
    puVar23 = (undefined1 *)((int)puVar22 + -0xc);
    puVar24 = (undefined1 *)((int)puVar22 + -0xc);
    pbVar16 = (byte *)(piVar12 + 0xc);
    if ((*(byte *)((int)piVar12 + 0x32) != uVar10) ||
       (piVar7 = (int *)(uint)*(byte *)((int)piVar12 + 0x33),
       puVar25 = (undefined2 *)((int)puVar22 + -0xc), piVar7 == (int *)0x0)) {
      iVar5 = op_ext_b0_u(uVar10);
      if (iVar5 - 0x25U < 4) {
        uVar8 = (uint)*pbVar16;
        if (uVar8 == 2) {
          uVar9 = 0;
        }
        else {
          puVar23 = (undefined1 *)((int)puVar22 + -0xc);
          if (uVar8 != 1) goto LAB_06086998;
          uVar9 = 1;
        }
        *(undefined4 *)((int)puVar22 + -8) = uVar9;
        puVar23 = (undefined1 *)((int)puVar22 + -0xc);
LAB_06086998:
        piVar12[9] = uVar8;
        puVar24 = puVar23;
      }
      else {
        if (iVar5 == 0x11) {
LAB_0608696a:
          uVar8 = 1;
          *(undefined4 *)((int)puVar22 + -8) = 1;
          puVar23 = (undefined1 *)((int)puVar22 + -0xc);
          goto LAB_06086998;
        }
        if (iVar5 == 0x12) {
          *(undefined4 *)((int)puVar22 + -8) = 2;
          *(undefined4 *)((int)puVar22 + -0xc) = 0;
          (**(code **)(piVar12[8] + 0x30))
                    (piVar12[10],0x85,(undefined1 *)((int)puVar22 + -0xc),
                     *(code **)(piVar12[8] + 0x30));
          uVar8 = 1;
          goto LAB_06086998;
        }
        if (iVar5 == 0x13) {
          uVar8 = 1;
          if (*pbVar16 == 2) {
            *(undefined4 *)((int)puVar22 + -8) = 0x220;
            *(undefined4 *)((int)puVar22 + -4) = 0x220;
            puVar23 = (undefined1 *)((int)puVar22 + -0xc);
          }
          else {
            puVar23 = (undefined1 *)((int)puVar22 + -0xc);
            if (*pbVar16 == 1) goto LAB_0608696a;
          }
          goto LAB_06086998;
        }
      }
      bVar11 = (byte)uVar10;
      piVar7 = (int *)(**(code **)(piVar12[8] + 0x30))
                                (piVar12[10],0x81,puVar24 + 4,*(code **)(piVar12[8] + 0x30));
      pbVar16[2] = bVar11;
      puVar25 = (undefined2 *)puVar24;
    }
    op_pop_pc_rl();
    op_push_rets_rl();
    puVar22 = puVar25 + -2;
    piVar14 = piVar7 + 0xc;
    if ((char)piVar7[0xd] == '\0') {
      uVar4 = 4;
    }
    else if ((char)piVar7[0xd] == '\x02') {
      uVar4 = 1;
    }
    else {
      uVar4 = 2;
    }
    *(int *)(puVar25 + -2) = piVar7[0xb];
    *puVar25 = uVar4;
    uVar9 = 1;
    puVar25[1] = 1;
    *(undefined4 *)(puVar25 + 2) = 0x400;
    (**(code **)(piVar7[8] + 0x30))(piVar7[10],0x84,puVar25 + -2,*(code **)(piVar7[8] + 0x30));
    *(undefined4 *)((int)puVar22 + 0xc) = uVar9;
    piVar12 = piVar7;
    (**(code **)(piVar7[8] + 0x30))
              (piVar7[10],0x80,(undefined1 *)((int)puVar22 + 0xc),*(code **)(piVar7[8] + 0x30));
    uVar10 = (uint)*(byte *)((int)piVar14 + 2);
  } while( true );
}


// ===== FUN_060869ac @ 060869ac

undefined4 FUN_060869ac(int param_1)

{
  code *pcVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined1 uVar9;
  undefined4 uVar10;
  BADSPACEBASE *in_sp;
  undefined4 *puVar11;
  undefined1 *puVar12;
  undefined8 uVar13;
  undefined4 uStack_10;
  undefined2 uStack_c;
  undefined2 uStack_a;
  undefined4 uStack_8;
  
  op_push_rets_rl();
  puVar11 = &uStack_10;
  iVar8 = param_1 + 0x30;
  if (*(char *)(param_1 + 0x34) == '\0') {
    uStack_c = 4;
  }
  else if (*(char *)(param_1 + 0x34) == '\x02') {
    uStack_c = 1;
  }
  else {
    uStack_c = 2;
  }
  uStack_10 = *(undefined4 *)(param_1 + 0x2c);
  uVar10 = 1;
  uStack_a = 1;
  uStack_8 = 0x400;
  pcVar1 = *(code **)(*(int *)(param_1 + 0x20) + 0x30);
  (*pcVar1)(*(undefined4 *)(param_1 + 0x28),0x84,&uStack_10,pcVar1);
  *(undefined4 *)((int)puVar11 + 0xc) = uVar10;
  pcVar1 = *(code **)(*(int *)(param_1 + 0x20) + 0x30);
  puVar6 = (undefined1 *)((int)puVar11 + 0xc);
  (*pcVar1)(*(undefined4 *)(param_1 + 0x28),0x80,pcVar1);
  uVar9 = (undefined1)uVar10;
  uVar13 = func_0x06086924(param_1,*(undefined1 *)(iVar8 + 2));
  iVar3 = (int)((ulonglong)uVar13 >> 0x20);
  iVar4 = (int)uVar13;
  *(undefined1 *)(iVar8 + 3) = uVar9;
  puVar12 = (undefined1 *)((int)puVar11 + 0x10);
  puVar5 = (undefined1 *)((int)puVar11 + 0x10);
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar7 = (undefined4 *)(iVar3 + 0x2c);
  if (iVar4 == 0x40008) {
LAB_06086a48:
    *(undefined1 *)(iVar3 + 0x33) = 0;
    *(undefined1 *)(iVar3 + 0x32) = 0;
    puVar5 = (undefined1 *)((int)puVar11 + 0x10);
  }
  else {
    if (iVar4 == 0x20007) {
      if (*(char *)(iVar3 + 0x33) == '\0') goto LAB_06086aa4;
      puVar5 = puVar6;
      if (puVar6 + -0x11 < &SUB_00000002) {
        puVar7 = (undefined4 *)(uint)*(byte *)(iVar3 + 0x31);
      }
      else if (puVar6 == (undefined1 *)0x14) {
        puVar5 = (undefined1 *)0x14;
      }
      else if (puVar6 == (undefined1 *)0x25) {
        puVar5 = (undefined1 *)0x25;
      }
      else if (puVar6 == (undefined1 *)0x26) {
        puVar5 = (undefined1 *)0x26;
      }
    }
    else {
      if (iVar4 == 0x104) goto LAB_06086a48;
      puVar5 = (undefined1 *)((int)puVar11 + 0x10);
      if (iVar4 != 0x20003) goto LAB_06086aa4;
      bVar2 = puVar6[4];
      puVar5 = (undefined1 *)(uint)bVar2;
      if (*(int *)(puVar6 + 0x14) == 0xb00) {
        *(byte *)(iVar3 + 0x30) = bVar2 >> 4;
        *puVar7 = *(undefined4 *)(puVar6 + 0x10);
        *(byte *)(iVar3 + 0x32) = bVar2;
        *(undefined1 *)(iVar3 + 0x34) = puVar6[5];
        puVar5 = (undefined1 *)((int)puVar11 + 0x10);
        goto LAB_06086aa4;
      }
      *(byte *)(iVar3 + 0x31) = bVar2 >> 4;
      *(byte *)(iVar3 + 0x32) = bVar2;
    }
    func_0x06086924(puVar5,puVar7);
    puVar5 = puVar12;
  }
LAB_06086aa4:
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar8 = 0;
  FUN_0608adbc(uRam00000028);
  FUN_0608adbc(*(undefined4 *)(iVar8 + 0x50));
  FUN_0608adbc(iVar8);
  op_pop_pc_rl();
  op_push_rets_rl();
  *(undefined4 *)(puVar5 + -4) = 0;
  func_0x0bfcf6a4(0x200);
  op_pop_pc_rl();
  return 0x7fffffff;
}


// ===== FUN_06086b3a @ 06086b3a

/* WARNING: Removing unreachable block (ram,0x06086c46) */

void FUN_06086b3a(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int in_cnum;
  
  op_push_rets_rl();
  uVar9 = 0;
  rep_unspec(2,9);
  *param_1 = 0;
  puVar8 = (uint *)0xff0500;
  if (cRam00105bd0 == '\0') {
    cRam00105bd0 = '\x01';
    func_0x06086b1e();
    puVar8[6] = uVar9;
    for (; uVar9 != 0xd80; uVar9 = uVar9 + 0x800) {
      puVar3 = (uint *)((int)puVar8 + uVar9 + 0xc5f);
      *puVar3 = *puVar3 | 2;
    }
    *puVar8 = *puVar8 | 2;
  }
  iVar4 = (int)puVar8 + 0xc5f;
  puVar7 = param_1;
  for (iVar10 = 0; iVar10 != 2; iVar10 = iVar10 + 1) {
    piVar1 = (int *)(iVar4 + 0x1c);
    piVar2 = (int *)(iVar4 + 0x20);
    iVar6 = op_stm_post1(0x21);
    iVar4 = iVar4 + 0x800;
    *(uint *)(iVar6 + 8) = (uint)(*piVar1 * 100) / (*piVar2 + *piVar1 + 1U);
    puVar7 = (undefined4 *)(iVar6 + 0xc);
  }
  uVar9 = puVar8[6];
  uVar12 = puVar8[7];
  param_1[6] = 1;
  uVar11 = 0;
  param_1[7] = 0;
  uVar5 = uVar12 + uVar9 + 1;
  uVar12 = (uint)(uVar5 == 0) << 2;
  param_1[8] = (uVar9 * 100) / uVar5;
  func_0x06086b1e(puVar7);
  puVar8[6] = uVar11;
  op_pop_pc_rl();
  op_push_rets_rl();
  do {
    testset_unspec(uRam00105bcc);
  } while ((uVar12 >> 2 & 1) != 0);
  in_cnum = in_cnum * 0x800;
  *(undefined4 *)(in_cnum + 0xffe414) = 0x6051fc0;
  *(undefined4 *)(in_cnum + 0xffe418) = 0x6052857;
  *(undefined4 *)(in_cnum + 0xffe410) = 0xca000200;
  do {
  } while ((*(uint *)(in_cnum + 0xffe400) & 0x40000000) != 0);
  op_pop_pc_rl();
  do {
    rep_unspec(4,0x44);
  } while( true );
}


// ===== FUN_06086bc4 @ 06086bc4

/* WARNING: Removing unreachable block (ram,0x06086c46) */

void FUN_06086bc4(void)

{
  int iVar1;
  uint in_psr;
  int in_cnum;
  
  op_push_rets_rl();
  do {
    testset_unspec(uRam00105bcc);
  } while ((in_psr >> 2 & 1) != 0);
  iVar1 = in_cnum * 0x800;
  *(undefined4 *)(iVar1 + 0xffe414) = 0x6051fc0;
  *(undefined4 *)(iVar1 + 0xffe418) = 0x6052857;
  *(undefined4 *)(iVar1 + 0xffe410) = 0xca000200;
  do {
  } while ((*(uint *)(iVar1 + 0xffe400) & 0x40000000) != 0);
  op_pop_pc_rl();
  do {
    rep_unspec(4,0x44);
  } while( true );
}


// ===== FUN_06086c1e @ 06086c1e

/* WARNING: Removing unreachable block (ram,0x06086c46) */

void FUN_06086c1e(void)

{
  do {
    rep_unspec(4,0x44);
  } while( true );
}


// ===== FUN_06086c48 @ 06086c48

void FUN_06086c48(void)

{
  return;
}


// ===== FUN_06086c4a @ 06086c4a

undefined4 FUN_06086c4a(int param_1)

{
  return *(undefined4 *)(param_1 + 0x44);
}


// ===== FUN_06086c50 @ 06086c50

void FUN_06086c50(void)

{
  return;
}


// ===== FUN_06086daa @ 06086daa

undefined4 FUN_06086daa(undefined1 *param_1)

{
  if (param_1 == (undefined1 *)0x0) {
    return 5;
  }
  *param_1 = 3;
  param_1[0xc] = 1;
  param_1[0xd] = 0xff;
  *(undefined8 *)(param_1 + 4) = 0;
  return 0;
}


// ===== FUN_0608718a @ 0608718a

void FUN_0608718a(undefined4 param_1,undefined4 param_2)

{
  undefined1 extraout_r0;
  undefined1 extraout_r0_00;
  undefined1 uVar1;
  undefined1 extraout_r0_01;
  undefined1 extraout_r0_02;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined1 extraout_var_01;
  undefined1 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  int iVar5;
  undefined4 uVar6;
  byte *pbVar7;
  byte *pbVar8;
  int in_cnum;
  
  op_push_rets_rl();
  uVar4 = CONCAT44(param_2,param_1);
  FUN_06086dc8();
  uVar6 = 3;
  if (CONCAT22(extraout_var_03,CONCAT11(extraout_var,extraout_r0)) == 0) {
    FUN_0608978a();
    uVar1 = extraout_r0_00;
    if (CONCAT22(extraout_var_04,CONCAT11(extraout_var_00,extraout_r0_00)) == 0) goto LAB_060871a2;
  }
  do {
    while( true ) {
      while( true ) {
        uVar1 = (undefined1)uVar6;
        op_pop_pc_rl();
LAB_060871a2:
        iVar5 = 0x108220;
        if ((int)((ulonglong)uVar4 >> 0x20) != -1) break;
        FUN_0608eab2(uVar1);
        uVar6 = 3;
        if ((CONCAT22(extraout_var_05,CONCAT11(extraout_var_01,extraout_r0_01)) < 1) &&
           (uVar6 = 2, *(char *)uVar4 == '\x03')) {
          FUN_0608eaba();
          iVar2 = (int)uVar4;
          if (*(char *)(iVar2 + 0xc) == '\0') {
                    /* WARNING: Subroutine does not return */
            thunk_FUN_06088ab8();
          }
          iVar5 = *(int *)(iVar5 + in_cnum * 4);
          *(undefined1 *)(iVar2 + 0xc) = 0;
          *(undefined1 *)(iVar2 + 0xd) = *(undefined1 *)(iVar5 + 0x30);
          *(int *)(iVar2 + 8) = iVar5;
                    /* WARNING: Subroutine does not return */
          thunk_FUN_06088ab8();
        }
      }
      if (cRam00108214 == '\0') break;
      uVar6 = 0;
    }
    FUN_0608eab2();
  } while (0 < CONCAT22(extraout_var_06,CONCAT11(extraout_var_02,extraout_r0_02)));
  FUN_0608eaba();
  pcVar3 = (char *)uVar4;
  if (*pcVar3 != '\x03') {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  iVar5 = *(int *)(iVar5 + in_cnum * 4);
  pbVar7 = (byte *)(iVar5 + 0x30);
  if (pcVar3[0xc] == '\x01') {
    pcVar3[0xe] = '\x01';
    pcVar3[0xf] = '\0';
    pcVar3[0xc] = '\0';
    pcVar3[0xd] = *pbVar7;
    *(int *)(pcVar3 + 8) = iVar5;
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  iVar2 = *(int *)(pcVar3 + 8);
  if (iVar2 == iVar5) {
    *(short *)(pcVar3 + 0xe) = *(short *)(pcVar3 + 0xe) + 1;
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  pbVar8 = (byte *)(iVar2 + 0x30);
  if (*pbVar8 < *pbVar7) {
    FUN_06086ec8((char)iVar2);
    *pbVar8 = *pbVar7;
    FUN_06086f64((char)iVar2);
  }
  pbVar7[1] = pbVar7[1] | 0x28;
  pbVar7[2] = 0;
  *(short *)(iVar5 + 6) = (short)((ulonglong)uVar4 >> 0x20);
  pbVar7[0x1c] = 0;
  pbVar7[0x1d] = 0;
  pbVar7[0x1e] = 0;
  pbVar7[0x1f] = 0;
  FUN_06086f74((char)uVar4,iVar5);
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_06087398 @ 06087398

void FUN_06087398(char *param_1)

{
  int iVar1;
  int in_r5;
  char *in_r6;
  char cVar2;
  int in_cnum;
  
  op_push_rets_rl();
  iVar1 = FUN_06086dc8();
  if ((((iVar1 == 0) && (iVar1 = FUN_0608978a(), iVar1 == 0)) && (cRam00108214 == '\0')) &&
     ((iVar1 = FUN_0608eab2(), iVar1 < 1 && (*param_1 == '\x03')))) {
    FUN_0608eaba();
    in_r5 = *(int *)(in_cnum * 4 + 0x108220);
    in_r6 = (char *)(in_r5 + 0x30);
    *(undefined4 *)(in_r5 + 0x4c) = uRam00104b5c;
    iVar1 = op_ext_l_u_p(*(ushort *)(param_1 + 0xe) - 1);
    *(short *)(param_1 + 0xe) = (short)(*(ushort *)(param_1 + 0xe) - 1);
    if (iVar1 != 0) goto LAB_060873f0;
  }
  else {
    op_pop_pc_rl();
  }
  if (*(int *)(param_1 + 4) != 0) {
    param_1[0xe] = '\x01';
    param_1[0xf] = '\0';
    cVar2 = param_1[0xd];
    if (*in_r6 != cVar2) {
      FUN_06086dd0(in_r5);
      *in_r6 = cVar2;
      FUN_06086eda(in_r5);
    }
    iVar1 = OS_EventHighestTask();
    FUN_0608732c(param_1,8);
    param_1[0xd] = *(char *)(iVar1 + 0x30);
    *(int *)(param_1 + 8) = iVar1;
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  param_1[0xe] = '\0';
  param_1[0xf] = '\0';
  param_1[0xc] = '\x01';
  param_1[0xd] = -1;
  param_1[8] = '\0';
  param_1[9] = '\0';
  param_1[10] = '\0';
  param_1[0xb] = '\0';
LAB_060873f0:
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_060875c2 @ 060875c2

void FUN_060875c2(undefined4 param_1,undefined4 param_2)

{
  int in_cnum;
  
  op_push_rets_rl();
  FUN_060874c8(param_1,param_2);
  op_pop_pc_rl();
  *(undefined4 *)(in_cnum * 4 + 0x1083e4) = 1;
  return;
}


// ===== FUN_060876d0 @ 060876d0

void FUN_060876d0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  op_push_rets_rl();
  iVar1 = FUN_06086dc8();
  if ((iVar1 != 0) || (iVar1 = FUN_0608978a(), iVar1 != 0)) {
    FUN_0608764c();
  }
  uVar2 = op_ext_l_u(param_1);
                    /* WARNING: Subroutine does not return */
  FUN_06087656(uVar2);
}


// ===== FUN_060878c2 @ 060878c2

void FUN_060878c2(void)

{
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined4 *puVar1;
  undefined1 auStack_84 [128];
  
  puVar1 = (undefined4 *)(auStack_84 + 0x80);
  func_0x0608782e();
  *puVar1 = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  FUN_06087740();
}


// ===== FUN_060878c8 @ 060878c8

void FUN_060878c8(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_06087740();
}


// ===== FUN_060879c4 @ 060879c4

void FUN_060879c4(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_cnum;
  
  op_push_rets_rl();
  iVar1 = FUN_0608eab2();
  if (0 < iVar1) {
    op_pop_pc_rl();
  }
  FUN_0608eaba(3);
  uVar3 = 0;
  iVar1 = *(int *)(in_cnum * 4 + 0x108220);
  if (0 < param_2) {
    if (*(short *)(iVar1 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_06088ab8();
    }
    if (*(short *)(iVar1 + 0xe) != 0) {
      FUN_060878d0(iVar1 + 8,param_2,param_1);
                    /* WARNING: Subroutine does not return */
      thunk_FUN_06088ab8();
    }
  }
  iVar2 = iVar1 + 0x30;
  *(char *)(iVar1 + 0x31) = (char)iVar1;
  *(undefined1 *)(iVar1 + 0x32) = 0;
  *(undefined2 *)(iVar1 + 6) = 0;
  FUN_06086dd0();
  FUN_06086f16(iVar1);
  *(undefined4 *)(iVar2 + 0x1c) = uVar3;
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_06087a88 @ 06087a88

void FUN_06087a88(char *param_1,undefined4 param_2,undefined1 param_3)

{
  BADSPACEBASE *in_sp;
  
  op_push_rets_rl();
  if (*param_1 != '\x02') {
    op_pop_pc_rl();
    op_push_rl();
    op_push_rets_rl();
    FUN_060874c8(0x980,0,param_2,&param_3,&param_3);
    op_pop_rets_rl();
    return;
  }
  FUN_0608eaba();
  if ((*(short *)(param_1 + 0xc) != 0) || (*(int *)(param_1 + 4) == 0)) {
    param_1[0xc] = '\0';
    param_1[0xd] = '\0';
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_06087ace @ 06087ace

void FUN_06087ace(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  undefined1 extraout_r0;
  undefined1 extraout_r0_00;
  undefined1 extraout_var;
  undefined1 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  int iVar3;
  undefined8 uVar4;
  int in_cnum;
  
  op_push_rets_rl();
  uVar4 = CONCAT26((short)((uint)param_2 >> 0x10),CONCAT24((short)param_2,param_1));
  FUN_06086dc8();
  if (CONCAT22(extraout_var_01,CONCAT11(extraout_var,extraout_r0)) != 0) {
    FUN_0608764c();
  }
  if ((int)((ulonglong)uVar4 >> 0x20) == -1) {
    if (*(char *)uVar4 == '\x02') {
      FUN_0608eaba();
      sVar1 = *(short *)((int)uVar4 + 0xc);
      if (sVar1 != 0) {
        *(short *)((int)uVar4 + 0xc) = sVar1 + -1;
      }
                    /* WARNING: Subroutine does not return */
      thunk_FUN_06088ab8();
    }
  }
  else if (((cRam00108214 == '\0') &&
           (FUN_0608eab2(), CONCAT22(extraout_var_02,CONCAT11(extraout_var_00,extraout_r0_00)) < 1))
          && (*(char *)uVar4 == '\x02')) {
    FUN_0608eaba();
    iVar3 = (int)uVar4;
    if (*(short *)(iVar3 + 0xc) == 0) {
      iVar2 = *(int *)(in_cnum * 4 + 0x108220);
      *(byte *)(iVar2 + 0x31) = *(byte *)(iVar2 + 0x31) | 0x21;
      *(undefined1 *)(iVar2 + 0x32) = 0;
      *(short *)(iVar2 + 6) = (short)((ulonglong)uVar4 >> 0x20);
      *(int *)(iVar2 + 0x4c) = iVar3;
      FUN_06086f74((short)iVar2);
                    /* WARNING: Subroutine does not return */
      thunk_FUN_06088ab8();
    }
    *(short *)(iVar3 + 0xc) = *(short *)(iVar3 + 0xc) + -1;
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  do {
    op_pop_pc_rl();
  } while( true );
}


// ===== FUN_06087c4a @ 06087c4a

void FUN_06087c4a(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  BADSPACEBASE *in_sp;
  undefined4 *puVar6;
  undefined1 auStack_14 [20];
  
  op_push_rets_rl();
  puVar6 = (undefined4 *)auStack_14;
  iVar3 = param_5 + 0x58;
  iVar1 = FUN_0608adae(iVar3);
  if (iVar1 == 0) {
    uVar2 = 0x2e;
  }
  else {
    uVar2 = *(undefined4 *)((int)puVar6 + 0x40);
    uVar5 = 0;
    func_0x05f9ac6e(0,iVar3);
    puVar4 = (undefined1 *)(iVar1 + 0x34);
    *(int *)(iVar1 + 0x40) = param_4;
    param_4 = param_4 << 2;
    iVar3 = func_0x0bfa56f0(param_4);
    *(int *)(puVar4 + 0x10) = iVar3;
    *puVar4 = uVar5;
    puVar6[4] = uVar2;
    puVar6[3] = 10;
    uVar2 = op_ext_l_u(param_5 / 4);
    puVar6[2] = uVar2;
    puVar6[1] = puVar4 + 0x24;
    *puVar6 = param_3;
    uVar2 = func_0x06087bca(param_1,iVar1,param_2,iVar3 + param_4 + -4);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  FUN_0608eaba(uVar2);
  OSGetTaskTcb(uVar2);
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_06087cbc @ 06087cbc

void FUN_06087cbc(undefined4 param_1)

{
  op_push_rets_rl();
  FUN_0608eaba();
  OSGetTaskTcb(param_1);
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_06087e00 @ 06087e00

void FUN_06087e00(void)

{
  int iVar1;
  int iVar2;
  int in_cnum;
  
  func_0x06087d2e();
  op_push_rets_rl();
  FUN_0608eaba();
  if (in_cnum != 0) {
    uRam001094c8 = 0;
    iVar2 = 0x108220;
    *(undefined2 *)(*(int *)(in_cnum * 4 + 0x108220) + 6) = 1;
    *(undefined4 *)(*(int *)(in_cnum * 4 + 0x108220) + 0x4c) = 0;
    iVar1 = *(int *)(in_cnum * 4 + 0x108220);
    *(byte *)(iVar1 + 0x31) = *(byte *)(iVar1 + 0x31) | 0x20;
    FUN_06086dd0(*(undefined4 *)(in_cnum * 4 + 0x108220));
    FUN_06086f16(*(undefined4 *)(iVar2 + in_cnum * 4));
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_06087e06 @ 06087e06

void FUN_06087e06(void)

{
  int iVar1;
  int iVar2;
  int in_cnum;
  
  op_push_rets_rl();
  FUN_0608eaba();
  if (in_cnum != 0) {
    uRam001094c8 = 0;
    iVar2 = 0x108220;
    *(undefined2 *)(*(int *)(in_cnum * 4 + 0x108220) + 6) = 1;
    *(undefined4 *)(*(int *)(in_cnum * 4 + 0x108220) + 0x4c) = 0;
    iVar1 = *(int *)(in_cnum * 4 + 0x108220);
    *(byte *)(iVar1 + 0x31) = *(byte *)(iVar1 + 0x31) | 0x20;
    FUN_06086dd0(*(undefined4 *)(in_cnum * 4 + 0x108220));
    FUN_06086f16(*(undefined4 *)(iVar2 + in_cnum * 4));
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_06087e72 @ 06087e72

void FUN_06087e72(uint param_1)

{
  uint *puVar1;
  int iVar2;
  
  op_push_rets_rl();
  puVar1 = (uint *)op_insert_rrii(param_1 >> 3,2,5);
  iVar2 = (param_1 & 7) << 2;
  FUN_06088a6a();
  *puVar1 = *puVar1 & ~(1 << iVar2);
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_06087e98 @ 06087e98

void FUN_06087e98(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  char *pcVar6;
  undefined8 uVar7;
  
  uVar7 = CONCAT44(param_1,param_2);
  op_push_rets_rl();
  iVar2 = 0;
  for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
    uVar3 = op_ext_b0_u(iVar2);
    uVar7 = FUN_06087e72(uVar3);
    iVar2 = iVar2 + 1;
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  uVar1 = FUN_0608eab2();
  if (((int)uVar1 < 1) && (uVar1 = (uint)*(byte *)((ulonglong)uVar7 >> 0x20), uVar1 == 3)) {
    FUN_0608eaba();
    puVar4 = (undefined1 *)((ulonglong)uVar7 >> 0x20);
    iVar2 = op_ext_b0_u_p((int)uVar7);
    if (iVar2 != 1) {
      if ((iVar2 == 0) && (*(int *)(puVar4 + 4) == 0)) {
        *puVar4 = 0;
      }
                    /* WARNING: Subroutine does not return */
      thunk_FUN_06088ab8();
    }
    iVar2 = *(int *)(puVar4 + 8);
    if (iVar2 != 0) {
      pcVar6 = (char *)(iVar2 + 0x30);
      if (puVar4[0xd] != *pcVar6) {
        FUN_06086dd0(iVar2);
        *pcVar6 = (char)iVar2;
        FUN_06086eda();
      }
    }
    while (*(int *)(puVar4 + 4) != 0) {
      uVar3 = OS_EventHighestTask(1);
      FUN_0608732c(puVar4,uVar3,8);
    }
    *puVar4 = 0;
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  FUN_0608eaba();
  if (uVar1 == 1) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  iVar2 = OSGetTaskTcb(uVar1);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  if (*(char *)(iVar2 + 0x33) == '\x02') {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  *(char *)(iVar2 + 0x33) = '\x01';
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_06087eac @ 06087eac

void FUN_06087eac(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  byte *pbVar4;
  
  op_push_rets_rl();
  uVar1 = FUN_0608eab2();
  if (((int)uVar1 < 1) && (uVar1 = (uint)*param_1, uVar1 == 3)) {
    FUN_0608eaba();
    iVar2 = op_ext_b0_u_p(param_2);
    if (iVar2 != 1) {
      if ((iVar2 == 0) && (*(int *)(param_1 + 4) == 0)) {
        *param_1 = 0;
      }
                    /* WARNING: Subroutine does not return */
      thunk_FUN_06088ab8();
    }
    iVar2 = *(int *)(param_1 + 8);
    if (iVar2 != 0) {
      pbVar4 = (byte *)(iVar2 + 0x30);
      if (param_1[0xd] != *pbVar4) {
        FUN_06086dd0(iVar2);
        *pbVar4 = (byte)iVar2;
        FUN_06086eda();
      }
    }
    while (*(int *)(param_1 + 4) != 0) {
      uVar3 = OS_EventHighestTask(1);
      FUN_0608732c(param_1,uVar3,8);
    }
    *param_1 = 0;
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  FUN_0608eaba();
  if (uVar1 == 1) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  iVar2 = OSGetTaskTcb(uVar1);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  if (*(char *)(iVar2 + 0x33) == '\x02') {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  *(char *)(iVar2 + 0x33) = '\x01';
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_06087f26 @ 06087f26

void FUN_06087f26(int param_1)

{
  int iVar1;
  
  op_push_rets_rl();
  FUN_0608eaba();
  if (param_1 == 1) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  iVar1 = OSGetTaskTcb(param_1);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  if (*(char *)(iVar1 + 0x33) == '\x02') {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  *(char *)(iVar1 + 0x33) = '\x01';
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_06087fec @ 06087fec

void FUN_06087fec(void)

{
  int iVar1;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 auStack_84 [128];
  
  puVar2 = (undefined4 *)(auStack_84 + 0x80);
  FUN_06087f86();
  *puVar2 = unaff_retaddr;
  puVar3 = puVar2 + -0xc;
  do {
    iVar1 = FUN_06087f86(0xc,puVar3);
  } while (iVar1 == 0xd);
  *(undefined4 *)((int)puVar3 + 0x30) = unaff_retaddr;
  FUN_06088a6a();
  for (iVar1 = 0; iVar1 != 0x20; iVar1 = iVar1 + 1) {
    *(undefined4 *)(in_cnum * 0x800 + 0xffe100 + iVar1 * 4) = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_06087ff2 @ 06087ff2

void FUN_06087ff2(void)

{
  int iVar1;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  undefined1 *puVar2;
  undefined1 auStack_34 [48];
  
  puVar2 = auStack_34;
  do {
    iVar1 = FUN_06087f86(0xc,puVar2);
  } while (iVar1 == 0xd);
  *(undefined4 *)(puVar2 + 0x30) = unaff_retaddr;
  FUN_06088a6a();
  for (iVar1 = 0; iVar1 != 0x20; iVar1 = iVar1 + 1) {
    *(undefined4 *)(in_cnum * 0x800 + 0xffe100 + iVar1 * 4) = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_06088004 @ 06088004

void FUN_06088004(void)

{
  int iVar1;
  int in_cnum;
  
  FUN_06088a6a();
  for (iVar1 = 0; iVar1 != 0x20; iVar1 = iVar1 + 1) {
    *(undefined4 *)(in_cnum * 0x800 + 0xffe100 + iVar1 * 4) = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_06088032 @ 06088032

void FUN_06088032(uint param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  op_push_rets_rl();
  iVar2 = (param_1 & 7) << 2;
  iVar3 = op_insert_rrii(param_3,0xb,8);
  uVar4 = 0xf << iVar2;
  FUN_06088a6a(param_1 >> 1);
  uVar1 = op_ext_b0_u(param_2 + 6);
  *(uint *)(iVar3 + 0xffe100) = *(uint *)(iVar3 + 0xffe100) & ~uVar4 | 0xf << iVar2;
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8(uVar1);
}


// ===== FUN_06088082 @ 06088082

void FUN_06088082(void)

{
  undefined2 uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  int *piVar6;
  undefined1 *puVar7;
  undefined1 auStack_14 [20];
  
  op_push_rets_rl();
  piVar6 = (int *)auStack_14;
  iVar2 = in_cnum * 0x58;
  iVar4 = iVar2 + 0x10832c;
  puVar5 = (undefined1 *)(iVar2 + 0x108360);
  *(undefined4 *)(iVar2 + 0x10836c) = 0xf00;
  *(int *)(in_cnum * 4 + 0x108220) = iVar4;
  iVar2 = func_0x0bfa56f0(0x800);
  *(int *)(puVar5 + 0x10) = iVar2;
  *puVar5 = (char)in_cnum;
  piVar6[4] = 0x10db70;
  piVar6[3] = 0;
  piVar6[2] = 0;
  piVar6[1] = 0;
  *piVar6 = iVar4;
  func_0x06087bca(0x10e484,0,iVar2 + 0x7fc);
  pcVar3 = (char *)0x108214;
  bRam00108214 = bRam00108214 & ~(byte)(1 << in_cnum);
  if (in_cnum != 0) {
    func_0x0608ebea();
    func_0x0608ec0c();
    puVar7 = (undefined1 *)((int)piVar6 + 0x14);
    op_pop_pc_rl();
    op_push_rets_rl();
    iRam00108208 = 0;
    uRam0010820c = 0;
    uRam00108210 = 0;
    bRam00108214 = 3;
    uRam00108218 = 0;
    uRam00108220 = 0;
    uRam0010821c = 0;
    uRam00108224 = 0;
    uVar1 = 0;
    func_0x05f9ac6e(0x108228,0,0x100);
    uRam00108328 = uVar1;
    op_pop_pc_rl();
    *(undefined4 *)(puVar7 + -4) = unaff_retaddr;
    iVar2 = FUN_06087e72();
    op_push_rets_rl();
    FUN_0608eaba();
    iRam00108208 = iRam00108208 + iVar2;
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  func_0x0608ebc0();
  do {
  } while (*pcVar3 != '\0');
                    /* WARNING: Subroutine does not return */
  FUN_06086fac();
}


// ===== FUN_0608812a @ 0608812a

void FUN_0608812a(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  
  op_push_rets_rl();
  iRam00108208 = 0;
  uRam0010820c = 0;
  uRam00108210 = 0;
  uRam00108214 = 3;
  uRam00108218 = 0;
  uRam00108220 = 0;
  uRam0010821c = 0;
  uRam00108224 = 0;
  uVar1 = 0;
  func_0x05f9ac6e(0x108228,0,0x100);
  uRam00108328 = uVar1;
  op_pop_pc_rl();
  *(undefined4 *)((int)in_sp + -4) = unaff_retaddr;
  iVar2 = FUN_06087e72();
  op_push_rets_rl();
  FUN_0608eaba();
  iRam00108208 = iRam00108208 + iVar2;
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_06088180 @ 06088180

void FUN_06088180(void)

{
  int iVar1;
  
  iVar1 = FUN_06087e72();
  op_push_rets_rl();
  FUN_0608eaba();
  iRam00108208 = iRam00108208 + iVar1;
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_060882da @ 060882da

void FUN_060882da(void)

{
  int in_cnum;
  
  FUN_0608eaba();
  *(undefined1 *)(*(int *)(in_cnum * 4 + 0x108220) + 0x33) = 2;
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_06088306 @ 06088306

void FUN_06088306(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined2 uVar8;
  int iVar9;
  uint uVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  uint *puVar17;
  undefined4 uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  int in_cnum;
  BADSPACEBASE *in_sp;
  int *piVar23;
  undefined1 auStack_4 [4];
  
  op_push_rets_rl();
  piVar23 = (int *)auStack_4;
  uVar11 = CONCAT26((short)((uint)param_2 >> 0x10),
                    CONCAT15((char)((uint)param_2 >> 8),CONCAT14((char)param_2,param_1)));
  FUN_06088a6a();
  uVar22 = (int)((ulonglong)uVar11 >> 0x20) + 0x7fU >> 7;
  if (uVar22 != 0) {
    iVar16 = 0xbdc;
    iVar21 = 0x106060;
    if (uVar22 <= (uint)uRam0010781a - (uint)uRam00107818) {
      uVar3 = (int)uVar11 - iRam001064a8;
      *piVar23 = (int)uVar11;
      uVar3 = uVar3 >> 7;
      puVar17 = (uint *)0xff0400;
      uVar18 = 0xffff;
      iVar19 = 0x111;
      uVar20 = 0x7fff;
      for (uVar13 = 0; uVar13 != uVar22; uVar13 = uVar13 + 1) {
        *puVar17 = *puVar17 | 1 << in_cnum + 4;
        iVar4 = iVar21 + 0x1794;
        uVar6 = (undefined1)iVar4;
        uVar7 = (undefined1)((uint)iVar4 >> 8);
        uVar8 = (undefined2)((uint)iVar4 >> 0x10);
        uVar15 = 0;
        uVar10 = 0;
        iVar4 = 0;
        for (iVar9 = 0x1f; iVar9 != 0xbf; iVar9 = iVar9 + 0x20) {
          uVar1 = *(uint *)CONCAT22(uVar8,CONCAT11(uVar7,uVar6));
          iVar2 = CONCAT22(uVar8,CONCAT11(uVar7,uVar6)) + 4;
          uVar6 = (undefined1)iVar2;
          uVar7 = (undefined1)((uint)iVar2 >> 8);
          uVar8 = (undefined2)((uint)iVar2 >> 0x10);
          if (uVar1 != 0) {
            uVar15 = uVar1;
            iVar4 = iVar9;
          }
          uVar10 = uVar10 | uVar1;
        }
        uVar6 = (undefined1)uVar18;
        uVar7 = (undefined1)((uint)uVar18 >> 8);
        if (uVar10 != 0) {
          iVar9 = FUN_0608edc4(uVar15);
          uVar10 = iVar4 - iVar9;
          puVar14 = (uint *)(uVar10 * 4 + iVar21 + 0x1514);
          iVar4 = FUN_0608edc4(*puVar14);
          iVar4 = 0x1f - iVar4;
          uVar15 = *puVar14;
          *puVar14 = uVar15 & ~(1 << iVar4);
          if ((uVar15 & (1 << iVar4 ^ 0xffffffffU)) == 0) {
            puVar14 = (uint *)(CONCAT22((ushort)(uVar10 >> 0x15),(short)(uVar10 >> 5)) * 4 + iVar21
                              + 0x1794);
            *puVar14 = *puVar14 & ~(1 << (uVar10 & 0x1f));
          }
          *(short *)(iVar21 + iVar16 * 2) = *(short *)(iVar21 + iVar16 * 2) + 1;
          iVar4 = iVar4 + uVar10 * 0x20 + 0xd00;
          uVar6 = (undefined1)iVar4;
          uVar7 = (undefined1)((uint)iVar4 >> 8);
        }
        puVar5 = (undefined1 *)(*(int *)(iVar21 + iVar19 * 4) + uVar3 * 2);
        uVar15 = CONCAT11(uVar7,uVar6) & uVar20;
        uVar12 = op_insert_rrii_p((uint)(byte)puVar5[1],8,8);
        *puVar5 = (char)uVar15;
        puVar5[1] = (byte)(uVar15 >> 8) | (byte)((uint)uVar12 >> 8) & 0xc;
        puVar5 = (undefined1 *)(*(int *)(iVar21 + iVar19 * 4) + uVar3 * 2);
        uVar12 = op_insert_rrii((uint)(byte)puVar5[1],8,0x18);
        *puVar5 = (char)uVar12;
        puVar5[1] = (byte)((uint)uVar12 >> 8) | 0xc;
        *puVar17 = *puVar17 & ~(1 << in_cnum + 4);
        uVar3 = uVar3 + 1;
      }
                    /* WARNING: Subroutine does not return */
      FUN_06088ab8();
    }
    func_0x0bfa4ef4();
    func_0x0bfa4f00();
  }
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608844c @ 0608844c

void FUN_0608844c(int param_1,int param_2)

{
  short sVar1;
  uint uVar2;
  uint *puVar3;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int in_cnum;
  
  op_push_rets_rl();
  FUN_06088a6a();
  iVar14 = 0x106060;
  uVar15 = (uint)(param_1 - iRam001064a8) >> 7;
  iVar13 = 0x111;
  uVar10 = 0x7fff;
  iVar11 = 0xbdc;
  puVar12 = (uint *)0xff0400;
  for (uVar6 = param_2 + 0x7fU >> 7; uVar6 != 0; uVar6 = uVar6 - 1) {
    iVar9 = uVar15 * 2;
    uVar2 = op_insert_rrii((uint)*(byte *)(*(int *)(iVar14 + iVar13 * 4) + iVar9 + 1),8,0x18);
    if ((int)uVar2 < 0) {
      uVar16 = (uVar2 & uVar10) - 0x2000;
      uVar8 = op_uextra_rrii(uVar16,5,0xb);
      iVar7 = iVar14 + 0x1514;
      uVar5 = *(uint *)(iVar7 + uVar8 * 4);
      uVar2 = 1 << (uVar2 & 0x1f);
      if ((uVar5 & uVar2) != 0) {
        func_0x0bfa4f54();
        uVar5 = *(uint *)(iVar7 + uVar8 * 4);
      }
      *(uint *)(iVar7 + uVar8 * 4) = uVar5 | uVar2;
      puVar3 = (uint *)(((uVar16 & 0xc7c) >> 8) + iVar14 + 0x1794);
      *puVar3 = *puVar3 | 1 << (uVar8 & 0x1f);
      sVar1 = *(short *)(iVar14 + iVar11 * 2);
      if (sVar1 == 0) {
        func_0x0bfa4f54();
        sVar1 = *(short *)(iVar14 + iVar11 * 2);
      }
      *(short *)(iVar14 + iVar11 * 2) = sVar1 + -1;
      *puVar12 = *puVar12 | 1 << in_cnum + 4;
      puVar4 = (undefined1 *)(*(int *)(iVar14 + iVar13 * 4) + iVar9);
      uVar2 = op_insert_rrii((uint)(byte)puVar4[1],8,8);
      *puVar4 = (char)(uVar2 & uVar10);
      puVar4[1] = (char)((uVar2 & uVar10) >> 8);
      *puVar12 = *puVar12 & ~(1 << in_cnum + 4);
    }
    uVar15 = uVar15 + 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_060885ca @ 060885ca

int FUN_060885ca(void)

{
  int iVar1;
  BADSPACEBASE *in_sp;
  undefined8 *puVar2;
  undefined1 auStack_c [8];
  
  puVar2 = (undefined8 *)auStack_c;
  iVar1 = func_0x0bfa5194();
  FUN_06088538((undefined1 *)((int)puVar2 + 4),iVar1 == 0);
  return -((uint)*puVar2 / 1000);
}


// ===== FUN_060885fa @ 060885fa

int FUN_060885fa(int param_1,int param_2)

{
  return param_2 - param_1;
}


// ===== FUN_06088612 @ 06088612

int FUN_06088612(int param_1,int param_2)

{
  return param_2 + param_1;
}


// ===== FUN_06088620 @ 06088620

void FUN_06088620(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  op_push_rets_rl();
  FUN_06088a6a();
  uVar1 = func_0x0608762a();
  piVar3 = (int *)0x60600b8;
  do {
    iVar2 = *piVar3;
    piVar3 = piVar3 + 3;
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_06088ab8();
    }
    iVar2 = func_0x05f9ac72(uVar1);
  } while (iVar2 != 0);
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608868a @ 0608868a

int FUN_0608868a(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_0608865a();
  piVar2 = (int *)0x1063a0;
  do {
    piVar2 = (int *)*piVar2;
    if (piVar2 == (int *)0x1063a0) {
      return 0;
    }
  } while (piVar2[2] != iVar1);
  return (int)piVar2;
}


// ===== FUN_060886ac @ 060886ac

void FUN_060886ac(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  
  op_push_rets_rl();
  iVar5 = param_2 - param_1;
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar6 = 0x4e200000;
  iVar3 = iVar5;
  uVar9 = FUN_0608868a(param_1 - param_2);
  uVar4 = (undefined4)(uVar9 >> 0x20);
  if (iVar3 != 0) {
    uVar9 = FUN_06088690(iVar3);
    iVar3 = (int)(uVar9 >> 0x20);
    uVar9 = uVar9 & 0xffffffff;
    if (iVar3 != 0) {
      *(undefined4 *)(iVar3 + 0x10) = uVar4;
      if (*(int *)(iVar3 + 0x18) != 0) {
        iVar5 = FUN_060886ac(uVar4);
        *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + iVar5;
      }
      *(undefined4 *)(iVar3 + 0x1c) = uVar4;
      uVar10 = FUN_06086c48(*(undefined4 *)(*(int *)(iVar3 + 8) + 0x40));
      iVar5 = (int)((ulonglong)uVar10 >> 0x20);
      iVar2 = *(int *)uVar10;
      iVar1 = FUN_06086c4a((int *)uVar10);
      iVar2 = iVar5 - ((uint)(iVar2 - iVar1) >> 2);
      uVar9 = CONCAT44(iVar2,*(int *)(iVar3 + 0x14));
      *(int *)(iVar3 + 0x14) = iVar2;
    }
  }
  if (iVar6 != 0) {
    uVar9 = FUN_06088690(iVar6);
    iVar3 = (int)(uVar9 >> 0x20);
    if (iVar3 != 0) {
      *(undefined4 *)(iVar3 + 0x18) = uVar4;
    }
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar7 = (undefined4 *)0x105d1c;
  puVar8 = (undefined4 *)0x105d1c;
  for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
    if (puVar8[3] == iVar5) {
      uVar4 = FUN_0608865a();
      *puVar8 = uVar4;
      FUN_060886ac(puVar8[1],uVar4);
      puVar8[1] = uVar4;
      puVar8[2] = 0;
      goto LAB_0608878c;
    }
    puVar8 = puVar8 + 4;
  }
  iVar3 = 0;
  do {
    if (5 < iVar3) {
LAB_0608878c:
                    /* WARNING: Subroutine does not return */
      FUN_06087ace((int)(uVar9 >> 0x20),(int)uVar9);
    }
    if (puVar7[3] == 0) {
      puVar7[3] = iVar5;
      uVar4 = FUN_0608865a();
      *puVar7 = uVar4;
      puVar7[1] = uVar4;
      puVar7[2] = 0;
      goto LAB_0608878c;
    }
    puVar7 = puVar7 + 4;
    iVar3 = iVar3 + 1;
  } while( true );
}


// ===== FUN_060886d0 @ 060886d0

void FUN_060886d0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  ulonglong uVar7;
  undefined8 uVar8;
  
  op_push_rets_rl();
  uVar7 = FUN_0608868a();
  uVar4 = (undefined4)(uVar7 >> 0x20);
  if (param_1 != 0) {
    uVar7 = FUN_06088690(param_1);
    iVar3 = (int)(uVar7 >> 0x20);
    uVar7 = uVar7 & 0xffffffff;
    if (iVar3 != 0) {
      *(undefined4 *)(iVar3 + 0x10) = uVar4;
      if (*(int *)(iVar3 + 0x18) != 0) {
        iVar1 = FUN_060886ac(uVar4);
        *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) + iVar1;
      }
      *(undefined4 *)(iVar3 + 0x1c) = uVar4;
      uVar8 = FUN_06086c48(*(undefined4 *)(*(int *)(iVar3 + 8) + 0x40));
      param_3 = (int)((ulonglong)uVar8 >> 0x20);
      iVar1 = *(int *)uVar8;
      iVar2 = FUN_06086c4a((int *)uVar8);
      iVar1 = param_3 - ((uint)(iVar1 - iVar2) >> 2);
      uVar7 = CONCAT44(iVar1,*(int *)(iVar3 + 0x14));
      *(int *)(iVar3 + 0x14) = iVar1;
    }
  }
  if (param_2 != 0) {
    uVar7 = FUN_06088690(param_2);
    iVar3 = (int)(uVar7 >> 0x20);
    if (iVar3 != 0) {
      *(undefined4 *)(iVar3 + 0x18) = uVar4;
    }
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar5 = (undefined4 *)0x105d1c;
  puVar6 = (undefined4 *)0x105d1c;
  for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
    if (puVar6[3] == param_3) {
      uVar4 = FUN_0608865a();
      *puVar6 = uVar4;
      FUN_060886ac(puVar6[1],uVar4);
      puVar6[1] = uVar4;
      puVar6[2] = 0;
      goto LAB_0608878c;
    }
    puVar6 = puVar6 + 4;
  }
  iVar3 = 0;
  do {
    if (5 < iVar3) {
LAB_0608878c:
                    /* WARNING: Subroutine does not return */
      FUN_06087ace((int)(uVar7 >> 0x20),(int)uVar7);
    }
    if (puVar5[3] == 0) {
      puVar5[3] = param_3;
      uVar4 = FUN_0608865a();
      *puVar5 = uVar4;
      puVar5[1] = uVar4;
      puVar5[2] = 0;
      goto LAB_0608878c;
    }
    puVar5 = puVar5 + 4;
    iVar3 = iVar3 + 1;
  } while( true );
}


// ===== FUN_0608872c @ 0608872c

void FUN_0608872c(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  op_push_rets_rl();
  puVar3 = (undefined4 *)0x105d1c;
  puVar4 = (undefined4 *)0x105d1c;
  for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
    if (puVar4[3] == param_3) {
      uVar2 = FUN_0608865a();
      *puVar4 = uVar2;
      FUN_060886ac(puVar4[1],uVar2);
      puVar4[1] = uVar2;
      puVar4[2] = 0;
      goto LAB_0608878c;
    }
    puVar4 = puVar4 + 4;
  }
  iVar1 = 0;
  do {
    if (5 < iVar1) {
LAB_0608878c:
                    /* WARNING: Subroutine does not return */
      FUN_06087ace(param_1,param_2);
    }
    if (puVar3[3] == 0) {
      puVar3[3] = param_3;
      uVar2 = FUN_0608865a();
      *puVar3 = uVar2;
      puVar3[1] = uVar2;
      puVar3[2] = 0;
      goto LAB_0608878c;
    }
    puVar3 = puVar3 + 4;
    iVar1 = iVar1 + 1;
  } while( true );
}


// ===== FUN_06088798 @ 06088798

void FUN_06088798(void)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined2 *puVar5;
  int iVar6;
  int in_cnum;
  BADSPACEBASE *in_sp;
  int *piVar7;
  undefined1 auStack_c [8];
  
  piVar7 = (int *)auStack_c;
  iVar1 = func_0x0bfa5194();
  FUN_06088538((undefined1 *)((int)piVar7 + 4),piVar7,iVar1 == 0);
  iVar1 = *piVar7;
  iVar2 = piVar7[1] * 10000 + iVar1;
  op_push_rets_rl();
  iVar6 = 10000;
  FUN_06088a6a();
  uRam00ff0400 = uRam00ff0400 | 1 << in_cnum + 4;
  puVar5 = (undefined2 *)(((uint)(iVar1 - iRam001064a8) >> 7) * 2 + iRam001064a4);
  puVar3 = (undefined2 *)(iRam001064a4 + ((uint)(iVar2 - iRam001064a8) >> 7) * 2);
  uVar4 = iVar6 + 0x7fU >> 7;
  do {
    rep_unspec(8,uVar4);
    *puVar3 = *puVar5;
    puVar3 = puVar3 + 1;
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  } while (uVar4 != 0);
  uRam00ff0400 = uRam00ff0400 & ~(1 << in_cnum + 4);
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_06088a6a @ 06088a6a

void FUN_06088a6a(void)

{
  int *piVar1;
  int in_cnum;
  
  *(undefined4 *)(in_cnum * 0x800 + 0xffe1a8) = 6;
  piVar1 = (int *)(in_cnum * 4 + 0x1083dc);
  *piVar1 = *piVar1 + 1;
  *(int *)(in_cnum * 4 + 0x1083ec) = *(int *)(in_cnum * 4 + 0x1083ec) + 1;
  return;
}


// ===== FUN_06088ab8 @ 06088ab8

void FUN_06088ab8(void)

{
  int iVar1;
  int in_cnum;
  
  *(int *)(in_cnum * 4 + 0x1083ec) = *(int *)(in_cnum * 4 + 0x1083ec) + -1;
  iVar1 = *(int *)(in_cnum * 4 + 0x1083dc) + -1;
  *(int *)(in_cnum * 4 + 0x1083dc) = iVar1;
  if (iVar1 == 0) {
    *(undefined4 *)(in_cnum * 0x800 + 0xffe1a8) = 0;
  }
  return;
}


// ===== FUN_06088b0a @ 06088b0a

uint FUN_06088b0a(int param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 extraout_r1;
  int iVar3;
  uint *puVar4;
  undefined1 *puVar5;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  
  uVar8 = CONCAT44(uRam00ffe8c0,param_2);
  op_push_rets_rl();
  puVar4 = (uint *)0xffe8c0;
  if (((in_cnum != 0) || ((uRam00ffe8c0 & 1) != 0)) &&
     ((FUN_06088a6a(), in_cnum != 0 || (uVar8 = CONCAT44(*puVar4,extraout_r1), (*puVar4 & 1) != 0)))
     ) {
    puVar5 = (undefined1 *)0x105764;
    if (cRam00105764 != '\0') {
      func_0x0608ead8();
    }
    if (param_1 == 0) {
      func_0x0608ead8();
    }
    *puVar5 = (char)param_1;
    bRam00105765 = 7;
    iVar3 = op_ext_b0_u(in_cnum);
    puVar4 = (uint *)((1 - iVar3) * 0x800 + 0xffe1a0);
    *puVar4 = *puVar4 | 1 << 1 - iVar3;
    do {
    } while ((bRam00105765 & 2) != 0);
    uVar8 = func_0x060875d8(*puVar5);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  if ((uRam00ffe0ec & 1) != 0) {
    uVar2 = uRam00ffe0f0 / ((uint)((ulonglong)uVar8 >> 0x20) / 1000000) + iRam00105760 + 6;
    iRam00104b5c = iRam00104b5c + uVar2 / 10000;
    uRam00ffe0f0 = (uVar2 % 10000) * ((uint)uVar8 / 1000000);
    iRam00ffe0f4 = (uint)uVar8 / 100 - 1;
    uRam00ffe0ec = 1;
  }
  op_pop_pc_rl();
  *(undefined4 *)((int)in_sp + -4) = unaff_retaddr;
  if ((in_cnum != 0) || ((uRam00ffe8c0 & 1) != 0)) {
    if ((in_cnum != 0) || ((uRam00ffe8c0 & 1) != 0)) {
      func_0x060875ee(cRam00105764);
      bRam00105765 = bRam00105765 & 0xfe;
      iVar3 = op_ext_b0_u(in_cnum);
      puVar4 = (uint *)((1 - iVar3) * 0x800 + 0xffe0c0);
      while ((bRam00105765 & 4) != 0) {
        *puVar4 = *puVar4 | 8;
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_06088ab8();
  }
  puVar6 = (undefined1 *)((int)in_sp + -4);
  *(undefined4 *)((int)in_sp + -4) = unaff_retaddr;
  iRam001083f4 = iRam001083f4 + 1;
  iVar3 = iRam001083fc + 1;
  bVar1 = iRam001083fc == 0;
  puVar7 = (undefined4 *)((int)in_sp + -4);
  iRam001083fc = iVar3;
  if (bVar1) {
    func_0x06087610();
    puVar7 = (undefined4 *)puVar6;
  }
  *puVar7 = unaff_retaddr;
  iVar3 = *(int *)(in_cnum * 4 + 0x1083fc) + -1;
  *(int *)(in_cnum * 4 + 0x1083fc) = iVar3;
  if (iVar3 == 0) {
    func_0x0608761e();
  }
  *(int *)(in_cnum * 4 + 0x1083f4) = *(int *)(in_cnum * 4 + 0x1083f4) + -1;
  op_push_rets_rl();
  func_0x05f9aca2();
  func_0x05f9aca6();
  do {
  } while ((int)uRam00fe0200 < 0);
  uRam00fe0204 = 0;
  uRam00fe0200 = uRam00fe0200 & 1;
  uRam00fd5500 = uRam00fd5500 | 0x10;
  uRam00fd5508 = uRam00fd5508 & 0xfffffff7 | 0x10;
  uRam00fd5510 = uRam00fd5510 & 0xfffffff7 | 0x10;
  uRam00fd1c00 = uRam00fd1c00 | 1;
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar4 = (uint *)0xfe0100;
  if ((uRam00fe0100 & 1) != 0) {
    func_0x05f9aca2();
    func_0x05f9aca6();
    do {
    } while ((int)*puVar4 < 0);
    uRam00fd5210 = uRam00fd5210 | 8;
    uRam00fd5208 = uRam00fd5208 | 8;
    puVar4[1] = 0;
    *puVar4 = *puVar4 & 1;
    uRam00fd5200 = uRam00fd5200 | 8;
    uRam00fd5210 = uRam00fd5210 & 8;
    uRam00fd5208 = uRam00fd5208 & 8;
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar3 = op_sextra_rrii(uRam00fe0200,8,4);
  if (iVar3 < 0) {
    op_pop_pc_rl();
    return (uint)bRam001079b8;
  }
  iVar3 = op_uextra_rrii(uRam00fe0200,8,4);
                    /* WARNING: Could not recover jumptable at 0x06088d9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)((uint)*(byte *)(iVar3 + 0x6088da0) * 2 + 0x6088da0))();
  return uVar2;
}


// ===== FUN_06088b7e @ 06088b7e

uint FUN_06088b7e(uint param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined1 auStack_84 [128];
  
  op_push_rets_rl();
  if ((uRam00ffe0ec & 1) != 0) {
    uVar2 = uRam00ffe0f0 / (param_1 / 1000000) + iRam00105760 + 6;
    iRam00104b5c = iRam00104b5c + uVar2 / 10000;
    uRam00ffe0f0 = (uVar2 % 10000) * (param_2 / 1000000);
    iRam00ffe0f4 = param_2 / 100 - 1;
    uRam00ffe0ec = 1;
  }
  op_pop_pc_rl();
  if ((in_cnum != 0) || ((uRam00ffe8c0 & 1) != 0)) {
    if ((in_cnum != 0) || ((uRam00ffe8c0 & 1) != 0)) {
      func_0x060875ee(uRam00105764);
      bRam00105765 = bRam00105765 & 0xfe;
      iVar3 = op_ext_b0_u(in_cnum);
      puVar4 = (uint *)((1 - iVar3) * 0x800 + 0xffe0c0);
      while ((bRam00105765 & 4) != 0) {
        *puVar4 = *puVar4 | 8;
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_06088ab8();
  }
  puVar5 = auStack_84 + 0x80;
  iRam001083f4 = iRam001083f4 + 1;
  iVar3 = iRam001083fc + 1;
  bVar1 = iRam001083fc == 0;
  puVar6 = (undefined4 *)(auStack_84 + 0x80);
  iRam001083fc = iVar3;
  if (bVar1) {
    func_0x06087610();
    puVar6 = (undefined4 *)puVar5;
  }
  *puVar6 = unaff_retaddr;
  iVar3 = *(int *)(in_cnum * 4 + 0x1083fc) + -1;
  *(int *)(in_cnum * 4 + 0x1083fc) = iVar3;
  if (iVar3 == 0) {
    func_0x0608761e();
  }
  *(int *)(in_cnum * 4 + 0x1083f4) = *(int *)(in_cnum * 4 + 0x1083f4) + -1;
  op_push_rets_rl();
  func_0x05f9aca2();
  func_0x05f9aca6();
  do {
  } while ((int)uRam00fe0200 < 0);
  uRam00fe0204 = 0;
  uRam00fe0200 = uRam00fe0200 & 1;
  uRam00fd5500 = uRam00fd5500 | 0x10;
  uRam00fd5508 = uRam00fd5508 & 0xfffffff7 | 0x10;
  uRam00fd5510 = uRam00fd5510 & 0xfffffff7 | 0x10;
  uRam00fd1c00 = uRam00fd1c00 | 1;
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar4 = (uint *)0xfe0100;
  if ((uRam00fe0100 & 1) != 0) {
    func_0x05f9aca2();
    func_0x05f9aca6();
    do {
    } while ((int)*puVar4 < 0);
    uRam00fd5210 = uRam00fd5210 | 8;
    uRam00fd5208 = uRam00fd5208 | 8;
    puVar4[1] = 0;
    *puVar4 = *puVar4 & 1;
    uRam00fd5200 = uRam00fd5200 | 8;
    uRam00fd5210 = uRam00fd5210 & 8;
    uRam00fd5208 = uRam00fd5208 & 8;
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar3 = op_sextra_rrii(uRam00fe0200,8,4);
  if (iVar3 < 0) {
    op_pop_pc_rl();
    return (uint)bRam001079b8;
  }
  iVar3 = op_uextra_rrii(uRam00fe0200,8,4);
                    /* WARNING: Could not recover jumptable at 0x06088d9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)((uint)*(byte *)(iVar3 + 0x6088da0) * 2 + 0x6088da0))();
  return uVar2;
}


// ===== FUN_06088bda @ 06088bda

uint FUN_06088bda(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined1 auStack_84 [128];
  
  if ((in_cnum != 0) || ((uRam00ffe8c0 & 1) != 0)) {
    if ((in_cnum != 0) || ((uRam00ffe8c0 & 1) != 0)) {
      func_0x060875ee(uRam00105764);
      bRam00105765 = bRam00105765 & 0xfe;
      iVar3 = op_ext_b0_u(in_cnum);
      puVar4 = (uint *)((1 - iVar3) * 0x800 + 0xffe0c0);
      while ((bRam00105765 & 4) != 0) {
        *puVar4 = *puVar4 | 8;
      }
    }
                    /* WARNING: Subroutine does not return */
    FUN_06088ab8();
  }
  puVar5 = auStack_84 + 0x80;
  iRam001083f4 = iRam001083f4 + 1;
  iVar3 = iRam001083fc + 1;
  bVar1 = iRam001083fc == 0;
  puVar6 = (undefined4 *)(auStack_84 + 0x80);
  iRam001083fc = iVar3;
  if (bVar1) {
    func_0x06087610();
    puVar6 = (undefined4 *)puVar5;
  }
  *puVar6 = unaff_retaddr;
  iVar3 = *(int *)(in_cnum * 4 + 0x1083fc) + -1;
  *(int *)(in_cnum * 4 + 0x1083fc) = iVar3;
  if (iVar3 == 0) {
    func_0x0608761e();
  }
  *(int *)(in_cnum * 4 + 0x1083f4) = *(int *)(in_cnum * 4 + 0x1083f4) + -1;
  op_push_rets_rl();
  func_0x05f9aca2();
  func_0x05f9aca6();
  do {
  } while ((int)uRam00fe0200 < 0);
  uRam00fe0204 = 0;
  uRam00fe0200 = uRam00fe0200 & 1;
  uRam00fd5500 = uRam00fd5500 | 0x10;
  uRam00fd5508 = uRam00fd5508 & 0xfffffff7 | 0x10;
  uRam00fd5510 = uRam00fd5510 & 0xfffffff7 | 0x10;
  uRam00fd1c00 = uRam00fd1c00 | 1;
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar4 = (uint *)0xfe0100;
  if ((uRam00fe0100 & 1) != 0) {
    func_0x05f9aca2();
    func_0x05f9aca6();
    do {
    } while ((int)*puVar4 < 0);
    uRam00fd5210 = uRam00fd5210 | 8;
    uRam00fd5208 = uRam00fd5208 | 8;
    puVar4[1] = 0;
    *puVar4 = *puVar4 & 1;
    uRam00fd5200 = uRam00fd5200 | 8;
    uRam00fd5210 = uRam00fd5210 & 8;
    uRam00fd5208 = uRam00fd5208 & 8;
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar3 = op_sextra_rrii(uRam00fe0200,8,4);
  if (iVar3 < 0) {
    op_pop_pc_rl();
    return (uint)bRam001079b8;
  }
  iVar3 = op_uextra_rrii(uRam00fe0200,8,4);
                    /* WARNING: Could not recover jumptable at 0x06088d9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)((uint)*(byte *)(iVar3 + 0x6088da0) * 2 + 0x6088da0))();
  return uVar2;
}


// ===== FUN_06088c40 @ 06088c40

uint FUN_06088c40(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined1 auStack_84 [128];
  
  puVar5 = auStack_84 + 0x80;
  piVar2 = (int *)(in_cnum * 4 + 0x1083f4);
  *piVar2 = *piVar2 + 1;
  iVar3 = *(int *)(in_cnum * 4 + 0x1083fc);
  *(int *)(in_cnum * 4 + 0x1083fc) = iVar3 + 1;
  puVar6 = (undefined4 *)(auStack_84 + 0x80);
  if (iVar3 == 0) {
    func_0x06087610();
    puVar6 = (undefined4 *)puVar5;
  }
  *puVar6 = unaff_retaddr;
  iVar3 = *(int *)(in_cnum * 4 + 0x1083fc) + -1;
  *(int *)(in_cnum * 4 + 0x1083fc) = iVar3;
  if (iVar3 == 0) {
    func_0x0608761e();
  }
  *(int *)(in_cnum * 4 + 0x1083f4) = *(int *)(in_cnum * 4 + 0x1083f4) + -1;
  op_push_rets_rl();
  func_0x05f9aca2();
  func_0x05f9aca6();
  do {
  } while ((int)uRam00fe0200 < 0);
  uRam00fe0204 = 0;
  uRam00fe0200 = uRam00fe0200 & 1;
  uRam00fd5500 = uRam00fd5500 | 0x10;
  uRam00fd5508 = uRam00fd5508 & 0xfffffff7 | 0x10;
  uRam00fd5510 = uRam00fd5510 & 0xfffffff7 | 0x10;
  uRam00fd1c00 = uRam00fd1c00 | 1;
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar4 = (uint *)0xfe0100;
  if ((uRam00fe0100 & 1) != 0) {
    func_0x05f9aca2();
    func_0x05f9aca6();
    do {
    } while ((int)*puVar4 < 0);
    uRam00fd5210 = uRam00fd5210 | 8;
    uRam00fd5208 = uRam00fd5208 | 8;
    puVar4[1] = 0;
    *puVar4 = *puVar4 & 1;
    uRam00fd5200 = uRam00fd5200 | 8;
    uRam00fd5210 = uRam00fd5210 & 8;
    uRam00fd5208 = uRam00fd5208 & 8;
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar3 = op_sextra_rrii(uRam00fe0200,8,4);
  if (iVar3 < 0) {
    op_pop_pc_rl();
    return (uint)bRam001079b8;
  }
  iVar3 = op_uextra_rrii(uRam00fe0200,8,4);
                    /* WARNING: Could not recover jumptable at 0x06088d9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)((uint)*(byte *)(iVar3 + 0x6088da0) * 2 + 0x6088da0))();
  return uVar1;
}


// ===== FUN_06088c72 @ 06088c72

uint FUN_06088c72(void)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int in_cnum;
  
  iVar2 = *(int *)(in_cnum * 4 + 0x1083fc) + -1;
  *(int *)(in_cnum * 4 + 0x1083fc) = iVar2;
  if (iVar2 == 0) {
    func_0x0608761e();
  }
  *(int *)(in_cnum * 4 + 0x1083f4) = *(int *)(in_cnum * 4 + 0x1083f4) + -1;
  op_push_rets_rl();
  func_0x05f9aca2();
  func_0x05f9aca6();
  do {
  } while ((int)uRam00fe0200 < 0);
  uRam00fe0204 = 0;
  uRam00fe0200 = uRam00fe0200 & 1;
  uRam00fd5500 = uRam00fd5500 | 0x10;
  uRam00fd5508 = uRam00fd5508 & 0xfffffff7 | 0x10;
  uRam00fd5510 = uRam00fd5510 & 0xfffffff7 | 0x10;
  uRam00fd1c00 = uRam00fd1c00 | 1;
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar3 = (uint *)0xfe0100;
  if ((uRam00fe0100 & 1) != 0) {
    func_0x05f9aca2();
    func_0x05f9aca6();
    do {
    } while ((int)*puVar3 < 0);
    uRam00fd5210 = uRam00fd5210 | 8;
    uRam00fd5208 = uRam00fd5208 | 8;
    puVar3[1] = 0;
    *puVar3 = *puVar3 & 1;
    uRam00fd5200 = uRam00fd5200 | 8;
    uRam00fd5210 = uRam00fd5210 & 8;
    uRam00fd5208 = uRam00fd5208 & 8;
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar2 = op_sextra_rrii(uRam00fe0200,8,4);
  if (iVar2 < 0) {
    op_pop_pc_rl();
    return (uint)bRam001079b8;
  }
  iVar2 = op_uextra_rrii(uRam00fe0200,8,4);
                    /* WARNING: Could not recover jumptable at 0x06088d9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)((uint)*(byte *)(iVar2 + 0x6088da0) * 2 + 0x6088da0))();
  return uVar1;
}


// ===== FUN_06088d3a @ 06088d3a

uint FUN_06088d3a(void)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  
  op_push_rets_rl();
  puVar2 = (uint *)0xfe0100;
  if ((uRam00fe0100 & 1) != 0) {
    func_0x05f9aca2();
    func_0x05f9aca6();
    do {
    } while ((int)*puVar2 < 0);
    uRam00fd5210 = uRam00fd5210 | 8;
    uRam00fd5208 = uRam00fd5208 | 8;
    puVar2[1] = 0;
    *puVar2 = *puVar2 & 1;
    uRam00fd5200 = uRam00fd5200 | 8;
    uRam00fd5210 = uRam00fd5210 & 8;
    uRam00fd5208 = uRam00fd5208 & 8;
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar3 = op_sextra_rrii(uRam00fe0200,8,4);
  if (iVar3 < 0) {
    op_pop_pc_rl();
    return (uint)bRam001079b8;
  }
  iVar3 = op_uextra_rrii(uRam00fe0200,8,4);
                    /* WARNING: Could not recover jumptable at 0x06088d9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)((uint)*(byte *)(iVar3 + 0x6088da0) * 2 + 0x6088da0))();
  return uVar1;
}


// ===== FUN_06088d7e @ 06088d7e

uint FUN_06088d7e(void)

{
  uint uVar1;
  int iVar2;
  
  op_push_rets_rl();
  iVar2 = op_sextra_rrii(uRam00fe0200,8,4);
  if (iVar2 < 0) {
    op_pop_pc_rl();
    return (uint)bRam001079b8;
  }
  iVar2 = op_uextra_rrii(uRam00fe0200,8,4);
                    /* WARNING: Could not recover jumptable at 0x06088d9e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)((uint)*(byte *)(iVar2 + 0x6088da0) * 2 + 0x6088da0))();
  return uVar1;
}


// ===== FUN_06088ee8 @ 06088ee8

int FUN_06088ee8(int param_1)

{
  uint uVar1;
  uint *puVar2;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined4 *puVar3;
  undefined8 uVar4;
  undefined1 auStack_84 [128];
  
  puVar3 = (undefined4 *)(auStack_84 + 0x80);
  if (param_1 != 0) {
    uRam00fd1c00 = uRam00fd1c00 & 1;
  }
  uRam00fe0204 = func_0x06088ede();
  uRam00fe0200 = uRam00fe0200 | 1;
  *puVar3 = unaff_retaddr;
  uVar1 = uRam00fe0100;
  if ((uRam00fe0100 & 1) == 0) {
    uVar4 = func_0x06088ede();
    uVar1 = (uint)((ulonglong)uVar4 >> 0x20);
    puVar2 = (uint *)uVar4;
    puVar2[1] = uVar1;
    *puVar2 = *puVar2 | 1;
  }
  return uVar1 + 0x680;
}


// ===== FUN_06088f06 @ 06088f06

int FUN_06088f06(void)

{
  uint uVar1;
  uint *puVar2;
  undefined8 uVar3;
  
  uVar1 = uRam00fe0100;
  if ((uRam00fe0100 & 1) == 0) {
    uVar3 = func_0x06088ede();
    uVar1 = (uint)((ulonglong)uVar3 >> 0x20);
    puVar2 = (uint *)uVar3;
    puVar2[1] = uVar1;
    *puVar2 = *puVar2 | 1;
  }
  return uVar1 + 0x680;
}


// ===== FUN_06088f1e @ 06088f1e

int FUN_06088f1e(int param_1)

{
  return param_1 + 0x680;
}


// ===== FUN_06088f8a @ 06088f8a

void FUN_06088f8a(void)

{
  func_0x0bfa713e();
  FUN_06088a6a();
  FUN_0608e546();
  func_0x05f9acde(2);
  func_0x0bfa71a2();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_060890d4 @ 060890d4

void FUN_060890d4(int param_1,undefined1 *param_2,undefined1 *param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 auStack_40 [64];
  
  op_push_rets_rl();
  puVar6 = auStack_40;
  puVar5 = (uint *)0xf2c254;
  uVar2 = 0;
  puVar7 = auStack_40;
  if (param_1 != 0) {
    uVar2 = uRam00f2c254 & 0xf;
    iVar1 = func_0x0bf82430(0x10006);
    if ((uint)(iVar1 << 2) < 0xe74) {
      uVar2 = uVar2 | 0xffffff80;
      *param_2 = (char)uVar2;
      *param_3 = (char)uVar2;
      puVar7 = puVar6;
    }
    else {
      puVar3 = puVar5 + -0x84;
      uVar4 = *puVar3;
      *puVar3 = *puVar3 & 4;
      FUN_0608aef8(100);
      *puVar3 = *puVar3 & 1;
      func_0x06088faa(param_1,puVar6 + 0x20);
      func_0x06089044(param_1,puVar6);
      for (iVar1 = 0; iVar1 != 8; iVar1 = iVar1 + 1) {
      }
      *param_2 = 0;
      for (iVar1 = 0; iVar1 != 8; iVar1 = iVar1 + 1) {
      }
      *param_3 = 0;
      uVar2 = op_insert_rrii(*puVar5 >> 3,3,0x1d);
      *puVar5 = uVar2;
      puVar7 = puVar6;
      if ((uVar4 & 1) != 0) {
        *puVar3 = *puVar3 | 1;
        uVar2 = FUN_0608aef8(3,0xffffffff);
        *puVar3 = *puVar3 | 4;
        puVar7 = puVar6;
      }
    }
  }
  op_pop_pc_rl();
  *(undefined4 *)(puVar7 + 0x3c) = unaff_retaddr;
  *(uint *)(in_cnum * 4 + 0x105bc4) = uVar2;
  uRam00f2c128 = uRam00f2c128 & 0xcff | 0xb;
                    /* WARNING: Subroutine does not return */
  p33_soft_reset();
}


// ===== FUN_0608978a @ 0608978a

undefined4 FUN_0608978a(void)

{
  int in_cnum;
  
  rep_unspec(0x18,2);
  return *(undefined4 *)(in_cnum * 4 + 0x1083dc);
}


// ===== FUN_060897ba @ 060897ba

/* WARNING: This function may have set the stack pointer */
/* WARNING: Removing unreachable block (ram,0x060897f2) */
/* WARNING: Removing unreachable block (ram,0x06089800) */
/* WARNING: Removing unreachable block (ram,0x06089806) */

void FUN_060897ba(void)

{
  undefined4 *puVar1;
  
  func_0x06089408();
  func_0x06089250();
  puVar1 = (undefined4 *)0x180820;
  do {
    rep_unspec(2,0x200);
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while( true );
}


// ===== FUN_060899c8 @ 060899c8

void FUN_060899c8(void)

{
  uint uVar1;
  
  for (uVar1 = (uint)bRam00108d01; uVar1 != 0; uVar1 = uVar1 - 1) {
  }
  return;
}


// ===== FUN_06089ba8 @ 06089ba8

void FUN_06089ba8(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  
  func_0x0bfbf640();
  iVar1 = 0xffff - 100000 / bRam00f27f80;
  uRam00f27f9b = (undefined1)((uint)iVar1 >> 8);
  uRam00f27f9a = (undefined1)iVar1;
  func_0x0bfbfa00();
  func_0x060899dc();
  hw_close_flash();
  uVar2 = 1;
  puVar3 = (undefined4 *)0xf2c340;
  uVar4 = 3;
  puVar6 = (undefined4 *)0x107a40;
  uVar7 = 0x10;
  puVar5 = (undefined4 *)0xf2a600;
  do {
    *puVar3 = uVar2;
    puVar3[1] = uVar2;
    puVar3[2] = uVar2;
    puVar3[3] = uVar2;
    puVar3[4] = uVar2;
    puVar3[5] = uVar2;
    *puVar3 = uVar4;
    puVar3[1] = uVar4;
    puVar3[2] = uVar4;
    puVar3[3] = uVar4;
    puVar3[4] = uVar4;
    puVar3[5] = uVar4;
    clear_wkup_src_pnd();
    *puVar6 = 0;
    *puVar5 = uVar7;
    puVar5[6] = uVar7;
  } while( true );
}


// ===== FUN_06089c24 @ 06089c24

void FUN_06089c24(void)

{
  undefined4 extraout_r1;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint *puVar11;
  
  func_0x0bfbf670();
  func_0x0bfbfa00();
  func_0x060899dc();
  hw_close_flash();
  iVar6 = 0xf2c044;
  uRam00f2c058 = uRam00f2c058 & 0xc7f;
  iVar7 = 0xf2c248;
  uRam00f2c248 = uRam00f2c248 & 0xff7;
  uRam00f2c044 = uRam00f2c044 & 0xfff;
  if (cRam00f27f86 == '\0') {
    uRam00f2c04c = uRam00f2c04c & 0xc7f;
    uRam00f2c050 = uRam00f2c050 & 0xc7f;
  }
  uVar4 = 1;
  puVar9 = (undefined4 *)0xf2c290;
  uVar2 = 3;
  puVar3 = (undefined4 *)0xf2c340;
  uVar8 = 0x7fb;
  puVar11 = (uint *)0xf2c108;
  uVar10 = 0x3fcf;
  iVar5 = 1;
  uVar1 = extraout_r1;
  do {
    *puVar9 = uVar4;
    *puVar9 = uVar2;
    *puVar3 = uVar4;
    puVar3[1] = uVar4;
    puVar3[2] = uVar4;
    puVar3[3] = uVar4;
    puVar3[4] = uVar4;
    puVar3[5] = uVar4;
    *puVar3 = uVar2;
    puVar3[1] = uVar2;
    puVar3[2] = uVar2;
    puVar3[3] = uVar2;
    puVar3[4] = uVar2;
    puVar3[5] = uVar2;
    *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) & uVar8;
    clear_wkup_src_pnd(uVar1);
    uVar1 = op_ext_b0_u(iVar5);
    *puVar11 = *puVar11 & 0xc7f | 0xa8;
    *(uint *)(iVar7 + 0x38) = *(uint *)(iVar7 + 0x38) & uVar10 | 0x30;
    iVar5 = iVar5 + 1;
  } while( true );
}


// ===== FUN_06089cd0 @ 06089cd0

undefined1 FUN_06089cd0(void)

{
  return uRam00104db5;
}


// ===== FUN_06089d8a @ 06089d8a

undefined4 FUN_06089d8a(void)

{
  return uRam00107a50;
}


// ===== FUN_06089d94 @ 06089d94

undefined4 FUN_06089d94(void)

{
  undefined4 uVar1;
  
  uVar1 = op_uextra_rrii(uRam00f2a908,9,1);
  return uVar1;
}


// ===== FUN_06089da2 @ 06089da2

undefined4 FUN_06089da2(undefined4 param_1)

{
  undefined8 uVar1;
  
  uVar1 = op_mul_u_prr(param_1,1000000);
  uVar1 = op_div_u_ppr(uVar1,uRam00108fd8);
  return (int)uVar1;
}


// ===== FUN_06089dbc @ 06089dbc

undefined4 FUN_06089dbc(void)

{
  return 0;
}


// ===== FUN_06089ec8 @ 06089ec8

void FUN_06089ec8(void)

{
  int iVar1;
  int in_cnum;
  BADSPACEBASE *in_sp;
  
  op_push_rets_rl();
  uRam00107b80 = uRam00fd5008;
  uRam00107b84 = uRam00fd500c;
  uRam00107b88 = uRam00fd5020;
  uRam00107b8c = uRam00fd5010;
  uRam00107b90 = uRam00fd5014;
  uRam00107b94 = uRam00fd5018;
  uRam00107b98 = uRam00fd501c;
  uRam00107b9c = uRam00fd5000;
  uRam00107ba0 = uRam00fd5108;
  uRam00107ba4 = uRam00fd510c;
  uRam00107ba8 = uRam00fd5120;
  uRam00107bac = uRam00fd5110;
  uRam00107bb0 = uRam00fd5114;
  uRam00107bb4 = uRam00fd5118;
  uRam00107bb8 = uRam00fd511c;
  uRam00107bbc = uRam00fd5100;
  uRam00107bc0 = uRam00fd5208;
  uRam00107bc4 = uRam00fd520c;
  uRam00107bc8 = uRam00fd5220;
  uRam00107bcc = uRam00fd5210;
  uRam00107bd0 = uRam00fd5214;
  uRam00107bd4 = uRam00fd5218;
  uRam00107bd8 = uRam00fd521c;
  uRam00107bdc = uRam00fd5200;
  uRam00107be0 = uRam00fd5408;
  uRam00107be4 = uRam00fd540c;
  uRam00107be8 = uRam00fd5420;
  uRam00107bec = uRam00fd5410;
  uRam00107bf0 = uRam00fd5414;
  uRam00107bf4 = uRam00fd5418;
  uRam00107bf8 = uRam00fd541c;
  uRam00107bfc = uRam00fd5400;
  uRam00107c00 = uRam00fd5708;
  uRam00107c04 = uRam00fd570c;
  uRam00107c08 = uRam00fd5720;
  uRam00107c0c = uRam00fd5710;
  uRam00107c10 = uRam00fd5714;
  uRam00107c14 = uRam00fd5718;
  uRam00107c18 = uRam00fd571c;
  uRam00107c1c = uRam00fd5700;
  for (iVar1 = 0; iVar1 != 0x100; iVar1 = iVar1 + 4) {
    iRam00107b7c = iVar1 + 0x107c9c;
    *(undefined4 *)(iVar1 + 0x107c98) = *(undefined4 *)(iVar1 + 0xfd5c00);
  }
  for (iVar1 = 0; iVar1 != 0xc4; iVar1 = iVar1 + 4) {
    iRam00107b7c = iVar1 + 0x107d9c;
    *(undefined4 *)(iVar1 + 0x107d98) = *(undefined4 *)(iVar1 + 0xfd5800);
  }
  uRam001081b8 = uRam00fd6014;
  uRam001081bc = uRam00fd6018;
  uRam001081c0 = uRam00fd601c;
  uRam001081c4 = uRam00fd6020;
  uRam001081c8 = uRam00fd6024;
  uRam001081cc = uRam00fd6028;
  uRam001081d0 = uRam00fd602c;
  uRam001081d4 = uRam00fd6030;
  op_pop_pc_rl();
  op_push_rmask(0xffff);
  op_push_srmask(0x3829);
  *(BADSPACEBASE **)(in_cnum * 4 + 0x107a38) = in_sp;
  func_0x06089d32();
  return;
}


// ===== FUN_0608a060 @ 0608a060

int FUN_0608a060(void)

{
  return iRam00f2a90c - iRam00f2a914;
}


// ===== FUN_0608a06e @ 0608a06e

/* WARNING: Possible PIC construction at 0x0608a2f6: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0608ab76: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0608abb6: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0608ab7a) */
/* WARNING: Removing unreachable block (ram,0x0608abbc) */
/* WARNING: Removing unreachable block (ram,0x0608ab82) */
/* WARNING: Removing unreachable block (ram,0x0608ab92) */
/* WARNING: Removing unreachable block (ram,0x0608aba8) */
/* WARNING: Removing unreachable block (ram,0x0608abaa) */
/* WARNING: Removing unreachable block (ram,0x0608abc2) */
/* WARNING: Removing unreachable block (ram,0x0608abfc) */
/* WARNING: Removing unreachable block (ram,0x0608ac08) */
/* WARNING: Removing unreachable block (ram,0x0608ac2c) */
/* WARNING: Removing unreachable block (ram,0x0608a2fa) */
/* WARNING: Removing unreachable block (ram,0x0608a3a6) */
/* WARNING: Removing unreachable block (ram,0x0608a3a2) */
/* WARNING: Removing unreachable block (ram,0x0608a3ac) */
/* WARNING: Removing unreachable block (ram,0x0608a3e4) */
/* WARNING: Removing unreachable block (ram,0x0608a3c6) */
/* WARNING: Removing unreachable block (ram,0x0608a3e8) */
/* WARNING: Removing unreachable block (ram,0x0608a3ee) */
/* WARNING: Removing unreachable block (ram,0x0608a3ea) */
/* WARNING: Removing unreachable block (ram,0x0608a3f4) */
/* WARNING: Removing unreachable block (ram,0x0608abba) */
/* WARNING: Removing unreachable block (ram,0x0608ac42) */
/* WARNING: Removing unreachable block (ram,0x0608ac7a) */
/* WARNING: Removing unreachable block (ram,0x0608ac7c) */
/* WARNING: Removing unreachable block (ram,0x0608ac80) */
/* WARNING: Removing unreachable block (ram,0x0608ac82) */
/* WARNING: Removing unreachable block (ram,0x0608ac8e) */
/* WARNING: Removing unreachable block (ram,0x0608ac90) */
/* WARNING: Removing unreachable block (ram,0x0608ac94) */
/* WARNING: Removing unreachable block (ram,0x0608ac9c) */
/* WARNING: Removing unreachable block (ram,0x0608aca4) */
/* WARNING: Removing unreachable block (ram,0x0608aca6) */
/* WARNING: Removing unreachable block (ram,0x0608acaa) */
/* WARNING: Removing unreachable block (ram,0x0608acb0) */
/* WARNING: Removing unreachable block (ram,0x0608acda) */
/* WARNING: Removing unreachable block (ram,0x0608acf0) */
/* WARNING: Removing unreachable block (ram,0x0608ace6) */
/* WARNING: Removing unreachable block (ram,0x0608acea) */
/* WARNING: Removing unreachable block (ram,0x0608acfe) */
/* WARNING: Removing unreachable block (ram,0x0608ad0e) */
/* WARNING: Removing unreachable block (ram,0x0608ad24) */
/* WARNING: Removing unreachable block (ram,0x0608ad32) */
/* WARNING: Removing unreachable block (ram,0x0608ad38) */
/* WARNING: Removing unreachable block (ram,0x0608ad5c) */
/* WARNING: Removing unreachable block (ram,0x0608ad62) */

undefined1 FUN_0608a06e(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *extraout_r1;
  uint *puVar5;
  undefined4 uVar6;
  uint *puVar7;
  int iVar8;
  uint *puVar9;
  undefined4 uVar10;
  uint uVar11;
  uint *puVar12;
  uint *puVar13;
  int *piVar14;
  uint *puVar15;
  uint *puVar16;
  uint *puVar17;
  uint *puVar18;
  uint *puVar19;
  uint *puVar20;
  uint *puVar21;
  int *piVar22;
  uint *puVar23;
  undefined4 unaff_retaddr;
  uint in_cnum;
  BADSPACEBASE *in_sp;
  undefined1 *puVar24;
  int *piVar25;
  undefined1 *puVar26;
  
  op_push_rets_rl();
  FUN_0608a060();
  uVar1 = FUN_06089da2();
  if (uVar1 < 0x334) {
    iVar8 = 0xf2a904;
    uRam00f2a904 = uRam00f2a904 | 0x10;
    iVar2 = __tcnt_us(10000);
    iVar3 = *(int *)(iVar8 + 8);
    *(undefined4 *)(iVar8 + 8) = 0x3ff;
    *(int *)(iVar8 + 8) = iVar2 + iVar3;
    uRam00104db0 = 1;
    op_pop_pc_rl();
  }
  iVar3 = FUN_06089d94();
  if (iVar3 == 0) {
    uRam00f2c128 = uRam00f2c128 & 0xcff | 0xe;
    func_0x0bf822c6();
  }
  op_pop_pc_rl();
  puVar24 = (undefined1 *)((int)in_sp + -4);
  *(undefined4 *)((int)in_sp + -4) = unaff_retaddr;
  FUN_06089da2(uRam00f2a914);
  piVar25 = (int *)(puVar24 + 4);
  do {
    op_push_rets_rl();
    iVar3 = op_ext_b0_u(in_cnum);
    iVar2 = iVar3 * 0x800;
    *(undefined4 *)(iVar2 + 0xffe1a8) = *(undefined4 *)(iVar3 * 8 + 0x107f04);
    *(undefined4 *)(iVar2 + 0xffe1ac) = *(undefined4 *)(iVar3 * 8 + 0x107f08);
    rep_unspec(4,0x20);
    *(undefined4 *)(iVar2 + 0xffe100) = *(undefined4 *)(iVar3 * 0x80 + 0x107f14);
    op_pop_pc_rl();
    op_push_rets_rl();
    iVar3 = op_ext_b0_u(in_cnum);
    iVar2 = iVar3 * 0x40;
    iVar3 = iVar3 * 0x800;
    *(undefined4 *)(iVar3 + 0xffe208) = *(undefined4 *)(iVar2 + 0x108014);
    *(undefined4 *)(iVar3 + 0xffe20c) = *(undefined4 *)(iVar2 + 0x108018);
    *(undefined4 *)(iVar3 + 0xffe22c) = *(undefined4 *)(iVar2 + 0x10801c);
    *(undefined4 *)(iVar3 + 0xffe228) = *(undefined4 *)(iVar2 + 0x108020);
    *(undefined4 *)(iVar3 + 0xffe224) = *(undefined4 *)(iVar2 + 0x108024);
    *(undefined4 *)(iVar3 + 0xffe220) = *(undefined4 *)(iVar2 + 0x108028);
    *(undefined4 *)(iVar3 + 0xffe21c) = *(undefined4 *)(iVar2 + 0x10802c);
    *(undefined4 *)(iVar3 + 0xffe218) = *(undefined4 *)(iVar2 + 0x108030);
    *(undefined4 *)(iVar3 + 0xffe1c0) = *(undefined4 *)(iVar2 + 0x108034);
    *(undefined4 *)(iVar3 + 0xffe200) = 0x3ff831;
    *(undefined4 *)(iVar3 + 0xffe0c4) = *(undefined4 *)(iVar2 + 0x10803c);
    if ((in_cnum & 0xff) == 0) {
      uRam00ffe0ec = uRam00108040;
      uRam00ffe0f0 = uRam00108044;
      uRam00ffe0f4 = uRam00108048;
    }
    op_pop_pc_rl();
    while (op_push_rets_rl(), iRam00108cc0 != 3) {
      op_pop_pc_rl();
      op_push_rets_rl();
      puVar26 = (undefined1 *)((int)piVar25 + -4);
      piVar22 = (int *)0x108ca8;
      if (cRam00108cc7 == '\0') {
LAB_0608ad76:
        op_pop_pc_rl();
        return uRam00104db0;
      }
      piVar25 = (int *)((int)piVar25 + -4);
      if (cRam00108d02 == '\0') {
        iVar3 = func_0x0bfc05a0();
        piVar25 = (int *)puVar26;
        if (iVar3 == 0) goto LAB_0608ad76;
      }
      FUN_06088a6a();
      func_0x0bfc05c0();
      uVar1 = func_0x0bfc0624(piVar22);
      piVar14 = piVar22 + 3;
      uVar4 = func_0x0bfc0624(piVar14);
      if (uVar4 < uVar1) {
        uVar1 = uVar4;
      }
      if (uVar1 == 0) {
LAB_0608ad70:
                    /* WARNING: Subroutine does not return */
        FUN_06088ab8();
      }
      puVar16 = (uint *)0xf2a800;
      iVar3 = 0;
      if ((uRam00f2a800 & 0x20) != 0) {
        func_0x0bf7fc06();
        iVar3 = *(int *)((*puVar16 & 0x1f) * 4 + 0x6060f9c);
      }
      uVar4 = (uint)(iVar3 * 0xf7a) >> 1;
      if ((uVar4 != 0) && (uVar4 < uVar1)) {
        uVar1 = uVar4;
      }
      iVar3 = FUN_06089d94();
      if (iVar3 != 0) {
        func_0x0bf822c6();
      }
      iVar3 = func_0x0bfc0658(uVar1);
      if (iVar3 == 1) goto LAB_0608ad70;
      func_0x0bfc0682(1);
      func_0x0bfc0694(1);
      puVar5 = puVar16 + 0x41;
      puVar20 = (uint *)0xfd3e00;
      if ((int *)*piVar22 == piVar22) {
        iVar3 = func_0x0bfc06a4(uVar1);
        if (iVar3 == 0) goto LAB_0608ad70;
        iVar2 = func_0x0bfc06dc();
        iVar3 = -2;
        if (iVar2 != -2) {
          *puVar20 = *puVar20 | 0x40;
          goto LAB_0608a4fa;
        }
      }
      else {
        iVar3 = func_0x0bfc06a4(*puVar5);
        if (iVar3 == 0) goto LAB_0608ad70;
        iVar2 = func_0x0bfc06dc(*puVar5);
LAB_0608a4fa:
        iVar3 = iVar2;
      }
      iVar2 = func_0x0bfc06ee();
      piVar22[6] = iVar2;
      func_0x0bfc0724(piVar22,iVar3);
      func_0x0bfc0724(piVar14,iVar3);
      uVar10 = 0;
      func_0x0bfc0682(0);
      func_0x0bfc0694(0);
      func_0x0bfc075a();
      uVar1 = op_insert_rrii((uint)bRam001081d9,8,8);
      bRam001081d8 = (byte)(uVar1 & 0xc70);
      bRam001081d9 = (byte)((uVar1 & 0xc70) >> 8);
      uRam00f27f91 = (undefined1)uVar10;
      uRam00f27f8d = uRam00f27f91;
      if (*(char *)((int)piVar22 + 0x5a) == '\x01') {
        uVar6 = op_insert_rrii((uint)bRam001081d9,8,0x18);
        bRam001081d8 = (byte)uVar6 | 1;
        uRam00f27f8d = 1;
        bRam001081d9 = bRam001081d8;
        if (*(char *)((int)piVar22 + 0x5a) == '\x01') {
          uVar6 = op_insert_rrii((uint)bRam001081d8,8,0x18);
          bRam001081d8 = (byte)uVar6 | 4;
          bRam001081d9 = bRam001081d8;
        }
      }
      puVar23 = (uint *)0xfd0004;
      uRam00fd0018 = uRam00fd0018 | 1;
      uRam00fd001c = uRam00fd001c & 0xfffff8ff | 0xf40;
      uRam00108148 = uRam00fd0014;
      uVar1 = op_insert_rrii((uint)bRam001081d9,8,8);
      puVar18 = (uint *)0xfd1920;
      puVar5 = puVar20 + 0x200;
      puVar9 = puVar20 + 0x240;
      uRam00fd0014 = uVar10;
      if ((uVar1 & 1) == 0) {
        uRam00104db8 = *puVar5;
        uRam00104dbc = *puVar9;
        *puVar5 = *puVar5 & 3;
        *puVar9 = *puVar9 & 3;
        uRam00fd1920 = uRam00fd1920 & 1;
        func_0x060899dc();
LAB_0608a6f6:
        puVar12 = puVar16 + 0x41;
        hw_close_flash();
      }
      else {
        *piVar25 = iVar3;
        uRam00fd1940 = 0xa80;
        uVar4 = op_uextra_rrii(uRam00fd1920,6,5);
        uVar11 = op_uextra_rrii(uRam00fd1920,0xb,4);
        iVar3 = op_uextra_rrii(uRam00fd1920,0xf,4);
        do {
          do {
            uRam00fd1920 = (uVar4 & 0x3b) << 6 | (uVar11 & 1) << 0xb | 0x36080001;
          } while (uVar4 != 3);
        } while ((uVar11 != 3) || (iVar3 != 3));
        uVar10 = op_uextra_rrii(uVar1,3,1);
        uRam00fd1924 = op_insert_rrii(uVar10,0x13,1);
        uRam00fd1924 = (uVar1 << 0xc | uVar1 >> 2 | 0x9503) & 0xa187 | uRam00fd1924;
        uRam00fd1928 = uVar1 >> 1 & 0x78 | uVar1 << 2 & 0xe40 | uVar1 << 2 & 0xd80 | 0x286;
        puVar5 = puVar20 + 0x200;
        puVar9 = puVar20 + 0x240;
        uRam00104db8 = *puVar5;
        uRam00104dbc = *puVar9;
        *puVar5 = *puVar5 & 3;
        *puVar9 = *puVar9 & 3;
        if ((uVar1 & 1) == 0) {
          uRam00fd1920 = uRam00fd1920 & 1;
          func_0x060899dc();
          goto LAB_0608a6f6;
        }
        func_0x060899dc();
        puVar12 = puVar16 + 0x41;
      }
      *(byte *)((int)piVar22 + 0x1d) = (byte)*puVar12 & 0x20 | (byte)*puVar12 & 0x80;
      *puVar23 = *puVar23 | 8;
      puVar15 = (uint *)0x107a40;
      puVar13 = puVar12 + -0xc1;
      puVar19 = puVar5 + 0x340;
      puVar21 = puVar5 + 0x3c0;
      puVar7 = puVar5 + 0x680;
      if (piVar22[6] == 3) {
        uRam00107b04 = puVar5[0x342];
        uRam00107b08 = puVar5[0x343];
        uRam00107b0c = puVar5[0x348];
        uRam00107b10 = puVar5[0x344];
        uRam00107b14 = puVar5[0x345];
        uRam00107b18 = puVar5[0x346];
        uRam00107b1c = puVar5[0x347];
        uRam00107b20 = *puVar19;
        uRam00107b24 = puVar5[0x3c2];
        uRam00107b28 = puVar5[0x3c3];
        uRam00107b2c = puVar5[0x3c8];
        uRam00107b30 = puVar5[0x3c4];
        uRam00107b34 = puVar5[0x3c5];
        uRam00107b38 = puVar5[0x3c6];
        uRam00107b3c = puVar5[0x3c7];
        uRam00107b40 = *puVar21;
        uRam00107b44 = *puVar7;
        uRam0010814c = puVar23[5];
        puVar15 = (uint *)0x10814c;
        uRam00108150 = puVar23[6];
        uRam00108154 = puVar23[7];
        uRam00108158 = puVar23[8];
        uRam0010815c = puVar23[4];
        uRam00108160 = *puVar23;
        uRam00108164 = puVar23[1];
        uRam00108168 = puVar23[2];
        uRam0010816c = puVar23[3];
        uRam00108170 = *puVar5;
        uRam00108174 = puVar5[1];
        uRam00108178 = puVar5[2];
        uRam0010817c = puVar5[3];
        uRam00108180 = puVar5[4];
        uRam00108184 = puVar5[5];
        uRam00108188 = puVar5[6];
        uRam0010818c = *puVar9;
        puVar17 = (uint *)0x10818c;
        uRam00108190 = puVar9[1];
        uRam00108194 = puVar9[2];
        uRam00108198 = puVar9[3];
        uRam0010819c = puVar9[4];
        uRam001081a0 = puVar9[5];
        uRam001081a4 = puVar9[6];
        uRam001081a8 = *puVar18;
        uRam001081ac = puVar18[1];
        uRam001081b0 = puVar18[2];
        uRam001081b4 = puVar18[8];
        puVar7 = puVar12 + 0x68f;
        *puVar7 = 1;
        puVar12[0x690] = 1;
        puVar12[0x691] = 1;
        puVar12[0x692] = 1;
        puVar12[0x693] = 1;
        puVar12[0x694] = 1;
        *puVar7 = 3;
        puVar12[0x690] = 3;
        puVar12[0x691] = 3;
        puVar12[0x692] = 3;
        puVar12[0x693] = 3;
        puVar12[0x694] = 3;
        puVar12[-0xb7] = puVar12[-0xb7] | 0x80;
        func_0x0608a034();
        puVar23[5] = *puVar15;
        puVar23[6] = puVar15[1];
        puVar23[7] = puVar15[2];
        puVar23[8] = puVar15[3];
        puVar23[4] = puVar15[4];
        *puVar23 = puVar15[5];
        puVar23[1] = puVar15[6];
        puVar23[2] = puVar15[7];
        puVar23[3] = puVar15[8];
        *puVar5 = puVar15[9];
        puVar5[1] = puVar15[10];
        puVar5[2] = puVar15[0xb];
        puVar5[3] = puVar15[0xc];
        puVar5[4] = puVar15[0xd];
        puVar5[5] = puVar15[0xe];
        puVar5[6] = puVar15[0xf];
        *puVar9 = *puVar17;
        puVar9[1] = puVar17[1];
        puVar9[2] = puVar17[2];
        puVar9[3] = puVar17[3];
        puVar9[4] = puVar17[4];
        puVar9[5] = puVar17[5];
        puVar9[6] = puVar17[6];
        *puVar18 = puVar17[7];
        puVar18[1] = puVar17[8];
        puVar18[2] = puVar17[9];
        puVar18[8] = puVar17[10];
        puVar19[2] = *extraout_r1;
        puVar19[3] = extraout_r1[1];
        puVar19[8] = extraout_r1[2];
        puVar19[4] = extraout_r1[3];
        puVar19[5] = extraout_r1[4];
        puVar19[6] = extraout_r1[5];
        puVar19[7] = extraout_r1[6];
        *puVar19 = extraout_r1[7];
        puVar21[2] = extraout_r1[8];
        puVar21[3] = extraout_r1[9];
        puVar21[8] = extraout_r1[10];
        puVar21[4] = extraout_r1[0xb];
        puVar21[5] = extraout_r1[0xc];
        puVar21[6] = extraout_r1[0xd];
        puVar21[7] = extraout_r1[0xe];
        *puVar21 = extraout_r1[0xf];
        puVar5 = puVar19 + 0x340;
        *puVar5 = extraout_r1[0x10];
        puVar7[1] = 0;
        puVar7[5] = 0;
        puVar7[4] = 0;
        puVar7 = puVar5;
      }
      else {
        msys_to_p11_sync_cmd(3);
        puVar5 = (uint *)piVar22[6];
        *puVar15 = *puVar13;
        *puVar13 = 1;
        puVar13[6] = 1;
        *puVar23 = *puVar23 | 4;
      }
      do {
        puVar16[2] = 0xff;
        puVar16[2] = 0xee;
        puVar16[2] = 0xab;
        puVar16[2] = 0xe;
        puVar16[2] = 0x55;
      } while ((puVar20[1] & 1) == 0);
      iVar3 = piVar22[6];
      if (iVar3 == 1) {
        do {
        } while ((puVar13[3] & 4) == 0);
        uVar1 = 4;
LAB_0608a9fe:
        puVar13[2] = uVar1;
        *puVar13 = 0x20;
      }
      else {
        if (iVar3 == 3) {
          uVar1 = 2;
          goto LAB_0608a9fe;
        }
        if (iVar3 == 2) {
          do {
          } while ((puVar13[3] & 1) == 0);
          uVar1 = 1;
          goto LAB_0608a9fe;
        }
      }
      if ((*puVar18 & 1) == 0) {
        puVar21[4] = puVar21[4] | 0x10;
        puVar21[2] = puVar21[2] | 0x10;
        puVar19[4] = puVar19[4] | 8;
        puVar19[2] = puVar19[2] | 8;
        puVar19[7] = puVar19[7] & 0x10;
        puVar19[6] = puVar19[6] & 0x10;
        *puVar19 = *puVar19 | 0x10;
        puVar19[2] = puVar19[2] & 0x10;
        delay_tmr2_lrc(10,puVar5);
        puVar19[6] = puVar19[6] | 0x10;
        delay_tmr2_lrc(10);
        puVar19[7] = puVar19[7] | 0x10;
        if ((puVar7[5] & 0x10000) == 0) {
          *puVar19 = *puVar19 | 8;
          puVar19[2] = puVar19[2] & 8;
          puVar19[4] = puVar19[4] & 8;
          puVar19[5] = puVar19[5] & 8;
          puVar19[4] = puVar19[4] & 1;
          puVar19[5] = puVar19[5] & 1;
          puVar19[2] = puVar19[2] & 1;
          puVar19[3] = puVar19[3] | 2;
          puVar19[4] = puVar19[4] | 2;
          puVar19[5] = puVar19[5] & 2;
          puVar19[2] = puVar19[2] | 2;
          puVar19[3] = puVar19[3] | 4;
          puVar19[4] = puVar19[4] | 4;
          puVar19[5] = puVar19[5] & 4;
          puVar19[2] = puVar19[2] | 4;
          if (cRam00104db5 == '\x04') {
            puVar19[3] = puVar19[3] | 0x20;
            puVar19[4] = puVar19[4] | 0x20;
            puVar19[5] = puVar19[5] & 0x20;
            puVar19[2] = puVar19[2] | 0x20;
            goto LAB_0608aafc;
          }
        }
        else {
          *puVar21 = *puVar21 | 0x10;
          puVar21[2] = puVar21[2] & 0x10;
          puVar21[4] = puVar21[4] & 0x10;
          puVar21[5] = puVar21[5] & 0x10;
          puVar19[3] = puVar19[3] | 1;
          puVar19[4] = puVar19[4] & 1;
          puVar19[5] = puVar19[5] & 1;
          puVar19[2] = puVar19[2] & 1;
          puVar19[3] = puVar19[3] | 2;
          puVar19[4] = puVar19[4] | 2;
          puVar19[5] = puVar19[5] & 2;
          puVar19[2] = puVar19[2] | 2;
          puVar21[3] = puVar21[3] | 8;
          puVar21[4] = puVar21[4] | 8;
          puVar21[5] = puVar21[5] & 8;
          puVar21[2] = puVar21[2] | 8;
          if (cRam00104db5 == '\x04') {
            puVar21[3] = puVar21[3] | 4;
            puVar21[4] = puVar21[4] | 4;
            puVar21[5] = puVar21[5] & 4;
            puVar21[2] = puVar21[2] | 4;
LAB_0608aafc:
            puVar19[3] = puVar19[3] | 0x40;
            puVar19[4] = puVar19[4] | 0x40;
            puVar19[5] = puVar19[5] & 0x40;
            puVar19[2] = puVar19[2] | 0x40;
          }
        }
      }
      func_0x0608a054();
      puVar13[0x715] = puVar13[0x715] & 0x3fc7;
      FUN_0608a06e();
      iVar3 = FUN_06089d94();
      if (iVar3 != 0) {
        FUN_0608a0c2();
      }
      if ((*puVar18 & 1) == 0) {
        *puVar18 = *puVar18 & 0x660;
        puVar18[1] = puVar18[1] & 0xfff7bdff;
        puVar18[2] = puVar18[2] & 0xd90;
        *puVar18 = *puVar18 | 1;
        uVar10 = func_0x0608b07e();
        FUN_0608afac(0x10eafa,uVar10);
      }
    }
    uRam00fd5008 = uRam00107b80;
    uRam00fd500c = uRam00107b84;
    uRam00fd5020 = uRam00107b88;
    uRam00fd5010 = uRam00107b8c;
    uRam00fd5014 = uRam00107b90;
    uRam00fd5018 = uRam00107b94;
    uRam00fd501c = uRam00107b98;
    uRam00fd5108 = uRam00107ba0;
    uRam00fd510c = uRam00107ba4;
    uRam00fd5120 = uRam00107ba8;
    uRam00fd5110 = uRam00107bac;
    uRam00fd5114 = uRam00107bb0;
    uRam00fd5118 = uRam00107bb4;
    uRam00fd511c = uRam00107bb8;
    uRam00fd5100 = 0x107bc0;
    uRam00fd5208 = uRam00107bc0;
    uRam00fd520c = uRam00107bc4;
    uRam00fd5220 = uRam00107bc8;
    uRam00fd5210 = uRam00107bcc;
    uRam00fd5214 = uRam00107bd0;
    uRam00fd5218 = uRam00107bd4;
    uRam00fd521c = uRam00107bd8;
    uRam00fd5408 = uRam00107be0;
    uRam00fd540c = uRam00107be4;
    uRam00fd5420 = uRam00107be8;
    uRam00fd5410 = uRam00107bec;
    uRam00fd5414 = uRam00107bf0;
    uRam00fd5418 = uRam00107bf4;
    uRam00fd541c = uRam00107bf8;
    uRam00fd5400 = uRam00107bfc;
    uRam00fd5708 = uRam00107c00;
    uRam00fd570c = uRam00107c04;
    uRam00fd5720 = uRam00107c08;
    uRam00fd5710 = uRam00107c0c;
    uRam00fd5714 = uRam00107c10;
    uRam00fd5718 = uRam00107c14;
    uRam00fd571c = uRam00107c18;
    uRam00fd5700 = uRam00107c1c;
    for (iVar3 = 0; iVar3 != 0x100; iVar3 = iVar3 + 4) {
      iRam00107b7c = iVar3 + 0x107c9c;
      *(undefined4 *)(iVar3 + 0xfd5c00) = *(undefined4 *)(iVar3 + 0x107c98);
    }
    for (iVar3 = 0; iVar3 != 0xc4; iVar3 = iVar3 + 4) {
      iRam00107b7c = iVar3 + 0x107d9c;
      *(undefined4 *)(iVar3 + 0xfd5800) = *(undefined4 *)(iVar3 + 0x107d98);
    }
    uRam00fd6014 = uRam001081b8;
    uRam00fd6018 = uRam001081bc;
    uRam00fd601c = uRam001081c0;
    uRam00fd6020 = uRam001081c4;
    uRam00fd6024 = uRam001081c8;
    uRam00fd6028 = uRam001081cc;
    uRam00fd602c = uRam001081d0;
    uRam00fd6030 = uRam001081d4;
  } while( true );
}


// ===== FUN_0608a0c2 @ 0608a0c2

/* WARNING: Possible PIC construction at 0x0608a2f6: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0608ab76: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0608abb6: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0608ab7a) */
/* WARNING: Removing unreachable block (ram,0x0608abbc) */
/* WARNING: Removing unreachable block (ram,0x0608ab82) */
/* WARNING: Removing unreachable block (ram,0x0608ab92) */
/* WARNING: Removing unreachable block (ram,0x0608aba8) */
/* WARNING: Removing unreachable block (ram,0x0608abaa) */
/* WARNING: Removing unreachable block (ram,0x0608abc2) */
/* WARNING: Removing unreachable block (ram,0x0608abfc) */
/* WARNING: Removing unreachable block (ram,0x0608ac08) */
/* WARNING: Removing unreachable block (ram,0x0608ac2c) */
/* WARNING: Removing unreachable block (ram,0x0608a2fa) */
/* WARNING: Removing unreachable block (ram,0x0608a3a6) */
/* WARNING: Removing unreachable block (ram,0x0608a3a2) */
/* WARNING: Removing unreachable block (ram,0x0608a3ac) */
/* WARNING: Removing unreachable block (ram,0x0608a3e4) */
/* WARNING: Removing unreachable block (ram,0x0608a3c6) */
/* WARNING: Removing unreachable block (ram,0x0608a3e8) */
/* WARNING: Removing unreachable block (ram,0x0608a3ee) */
/* WARNING: Removing unreachable block (ram,0x0608a3ea) */
/* WARNING: Removing unreachable block (ram,0x0608a3f4) */
/* WARNING: Removing unreachable block (ram,0x0608abba) */
/* WARNING: Removing unreachable block (ram,0x0608ac42) */
/* WARNING: Removing unreachable block (ram,0x0608ac7a) */
/* WARNING: Removing unreachable block (ram,0x0608ac7c) */
/* WARNING: Removing unreachable block (ram,0x0608ac80) */
/* WARNING: Removing unreachable block (ram,0x0608ac82) */
/* WARNING: Removing unreachable block (ram,0x0608ac8e) */
/* WARNING: Removing unreachable block (ram,0x0608ac90) */
/* WARNING: Removing unreachable block (ram,0x0608ac94) */
/* WARNING: Removing unreachable block (ram,0x0608ac9c) */
/* WARNING: Removing unreachable block (ram,0x0608aca4) */
/* WARNING: Removing unreachable block (ram,0x0608aca6) */
/* WARNING: Removing unreachable block (ram,0x0608acaa) */
/* WARNING: Removing unreachable block (ram,0x0608acb0) */
/* WARNING: Removing unreachable block (ram,0x0608acda) */
/* WARNING: Removing unreachable block (ram,0x0608acf0) */
/* WARNING: Removing unreachable block (ram,0x0608ace6) */
/* WARNING: Removing unreachable block (ram,0x0608acea) */
/* WARNING: Removing unreachable block (ram,0x0608acfe) */
/* WARNING: Removing unreachable block (ram,0x0608ad0e) */
/* WARNING: Removing unreachable block (ram,0x0608ad24) */
/* WARNING: Removing unreachable block (ram,0x0608ad32) */
/* WARNING: Removing unreachable block (ram,0x0608ad38) */
/* WARNING: Removing unreachable block (ram,0x0608ad5c) */
/* WARNING: Removing unreachable block (ram,0x0608ad62) */

undefined1 FUN_0608a0c2(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *extraout_r1;
  uint *puVar4;
  undefined4 uVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  int *piVar13;
  uint *puVar14;
  uint *puVar15;
  uint *puVar16;
  uint *puVar17;
  uint *puVar18;
  uint *puVar19;
  uint *puVar20;
  int *piVar21;
  uint *puVar22;
  uint in_cnum;
  BADSPACEBASE *in_sp;
  undefined1 *puVar23;
  int *piVar24;
  undefined1 *puVar25;
  undefined1 auStack_84 [128];
  
  puVar23 = auStack_84 + 0x80;
  FUN_06089da2(uRam00f2a914);
  piVar24 = (int *)(puVar23 + 4);
  do {
    op_push_rets_rl();
    iVar1 = op_ext_b0_u(in_cnum);
    iVar7 = iVar1 * 0x800;
    *(undefined4 *)(iVar7 + 0xffe1a8) = *(undefined4 *)(iVar1 * 8 + 0x107f04);
    *(undefined4 *)(iVar7 + 0xffe1ac) = *(undefined4 *)(iVar1 * 8 + 0x107f08);
    rep_unspec(4,0x20);
    *(undefined4 *)(iVar7 + 0xffe100) = *(undefined4 *)(iVar1 * 0x80 + 0x107f14);
    op_pop_pc_rl();
    op_push_rets_rl();
    iVar1 = op_ext_b0_u(in_cnum);
    iVar7 = iVar1 * 0x40;
    iVar1 = iVar1 * 0x800;
    *(undefined4 *)(iVar1 + 0xffe208) = *(undefined4 *)(iVar7 + 0x108014);
    *(undefined4 *)(iVar1 + 0xffe20c) = *(undefined4 *)(iVar7 + 0x108018);
    *(undefined4 *)(iVar1 + 0xffe22c) = *(undefined4 *)(iVar7 + 0x10801c);
    *(undefined4 *)(iVar1 + 0xffe228) = *(undefined4 *)(iVar7 + 0x108020);
    *(undefined4 *)(iVar1 + 0xffe224) = *(undefined4 *)(iVar7 + 0x108024);
    *(undefined4 *)(iVar1 + 0xffe220) = *(undefined4 *)(iVar7 + 0x108028);
    *(undefined4 *)(iVar1 + 0xffe21c) = *(undefined4 *)(iVar7 + 0x10802c);
    *(undefined4 *)(iVar1 + 0xffe218) = *(undefined4 *)(iVar7 + 0x108030);
    *(undefined4 *)(iVar1 + 0xffe1c0) = *(undefined4 *)(iVar7 + 0x108034);
    *(undefined4 *)(iVar1 + 0xffe200) = 0x3ff831;
    *(undefined4 *)(iVar1 + 0xffe0c4) = *(undefined4 *)(iVar7 + 0x10803c);
    if ((in_cnum & 0xff) == 0) {
      uRam00ffe0ec = uRam00108040;
      uRam00ffe0f0 = uRam00108044;
      uRam00ffe0f4 = uRam00108048;
    }
    op_pop_pc_rl();
    while (op_push_rets_rl(), iRam00108cc0 != 3) {
      op_pop_pc_rl();
      op_push_rets_rl();
      puVar25 = (undefined1 *)((int)piVar24 + -4);
      piVar21 = (int *)0x108ca8;
      if (cRam00108cc7 == '\0') {
LAB_0608ad76:
        op_pop_pc_rl();
        return uRam00104db0;
      }
      piVar24 = (int *)((int)piVar24 + -4);
      if (cRam00108d02 == '\0') {
        iVar1 = func_0x0bfc05a0();
        piVar24 = (int *)puVar25;
        if (iVar1 == 0) goto LAB_0608ad76;
      }
      FUN_06088a6a();
      func_0x0bfc05c0();
      uVar2 = func_0x0bfc0624(piVar21);
      piVar13 = piVar21 + 3;
      uVar3 = func_0x0bfc0624(piVar13);
      if (uVar3 < uVar2) {
        uVar2 = uVar3;
      }
      if (uVar2 == 0) {
LAB_0608ad70:
                    /* WARNING: Subroutine does not return */
        FUN_06088ab8();
      }
      puVar15 = (uint *)0xf2a800;
      iVar1 = 0;
      if ((uRam00f2a800 & 0x20) != 0) {
        func_0x0bf7fc06();
        iVar1 = *(int *)((*puVar15 & 0x1f) * 4 + 0x6060f9c);
      }
      uVar3 = (uint)(iVar1 * 0xf7a) >> 1;
      if ((uVar3 != 0) && (uVar3 < uVar2)) {
        uVar2 = uVar3;
      }
      iVar1 = FUN_06089d94();
      if (iVar1 != 0) {
        func_0x0bf822c6();
      }
      iVar1 = func_0x0bfc0658(uVar2);
      if (iVar1 == 1) goto LAB_0608ad70;
      func_0x0bfc0682(1);
      func_0x0bfc0694(1);
      puVar4 = puVar15 + 0x41;
      puVar19 = (uint *)0xfd3e00;
      if ((int *)*piVar21 == piVar21) {
        iVar1 = func_0x0bfc06a4(uVar2);
        if (iVar1 == 0) goto LAB_0608ad70;
        iVar7 = func_0x0bfc06dc();
        iVar1 = -2;
        if (iVar7 != -2) {
          *puVar19 = *puVar19 | 0x40;
          goto LAB_0608a4fa;
        }
      }
      else {
        iVar1 = func_0x0bfc06a4(*puVar4);
        if (iVar1 == 0) goto LAB_0608ad70;
        iVar7 = func_0x0bfc06dc(*puVar4);
LAB_0608a4fa:
        iVar1 = iVar7;
      }
      iVar7 = func_0x0bfc06ee();
      piVar21[6] = iVar7;
      func_0x0bfc0724(piVar21,iVar1);
      func_0x0bfc0724(piVar13,iVar1);
      uVar9 = 0;
      func_0x0bfc0682(0);
      func_0x0bfc0694(0);
      func_0x0bfc075a();
      uVar2 = op_insert_rrii((uint)bRam001081d9,8,8);
      bRam001081d8 = (byte)(uVar2 & 0xc70);
      bRam001081d9 = (byte)((uVar2 & 0xc70) >> 8);
      uRam00f27f91 = (undefined1)uVar9;
      uRam00f27f8d = uRam00f27f91;
      if (*(char *)((int)piVar21 + 0x5a) == '\x01') {
        uVar5 = op_insert_rrii((uint)bRam001081d9,8,0x18);
        bRam001081d8 = (byte)uVar5 | 1;
        uRam00f27f8d = 1;
        bRam001081d9 = bRam001081d8;
        if (*(char *)((int)piVar21 + 0x5a) == '\x01') {
          uVar5 = op_insert_rrii((uint)bRam001081d8,8,0x18);
          bRam001081d8 = (byte)uVar5 | 4;
          bRam001081d9 = bRam001081d8;
        }
      }
      puVar22 = (uint *)0xfd0004;
      uRam00fd0018 = uRam00fd0018 | 1;
      uRam00fd001c = uRam00fd001c & 0xfffff8ff | 0xf40;
      uRam00108148 = uRam00fd0014;
      uVar2 = op_insert_rrii((uint)bRam001081d9,8,8);
      puVar17 = (uint *)0xfd1920;
      puVar4 = puVar19 + 0x200;
      puVar8 = puVar19 + 0x240;
      uRam00fd0014 = uVar9;
      if ((uVar2 & 1) == 0) {
        uRam00104db8 = *puVar4;
        uRam00104dbc = *puVar8;
        *puVar4 = *puVar4 & 3;
        *puVar8 = *puVar8 & 3;
        uRam00fd1920 = uRam00fd1920 & 1;
        func_0x060899dc();
LAB_0608a6f6:
        puVar11 = puVar15 + 0x41;
        hw_close_flash();
      }
      else {
        *piVar24 = iVar1;
        uRam00fd1940 = 0xa80;
        uVar3 = op_uextra_rrii(uRam00fd1920,6,5);
        uVar10 = op_uextra_rrii(uRam00fd1920,0xb,4);
        iVar1 = op_uextra_rrii(uRam00fd1920,0xf,4);
        do {
          do {
            uRam00fd1920 = (uVar3 & 0x3b) << 6 | (uVar10 & 1) << 0xb | 0x36080001;
          } while (uVar3 != 3);
        } while ((uVar10 != 3) || (iVar1 != 3));
        uVar9 = op_uextra_rrii(uVar2,3,1);
        uRam00fd1924 = op_insert_rrii(uVar9,0x13,1);
        uRam00fd1924 = (uVar2 << 0xc | uVar2 >> 2 | 0x9503) & 0xa187 | uRam00fd1924;
        uRam00fd1928 = uVar2 >> 1 & 0x78 | uVar2 << 2 & 0xe40 | uVar2 << 2 & 0xd80 | 0x286;
        puVar4 = puVar19 + 0x200;
        puVar8 = puVar19 + 0x240;
        uRam00104db8 = *puVar4;
        uRam00104dbc = *puVar8;
        *puVar4 = *puVar4 & 3;
        *puVar8 = *puVar8 & 3;
        if ((uVar2 & 1) == 0) {
          uRam00fd1920 = uRam00fd1920 & 1;
          func_0x060899dc();
          goto LAB_0608a6f6;
        }
        func_0x060899dc();
        puVar11 = puVar15 + 0x41;
      }
      *(byte *)((int)piVar21 + 0x1d) = (byte)*puVar11 & 0x20 | (byte)*puVar11 & 0x80;
      *puVar22 = *puVar22 | 8;
      puVar14 = (uint *)0x107a40;
      puVar12 = puVar11 + -0xc1;
      puVar18 = puVar4 + 0x340;
      puVar20 = puVar4 + 0x3c0;
      puVar6 = puVar4 + 0x680;
      if (piVar21[6] == 3) {
        uRam00107b04 = puVar4[0x342];
        uRam00107b08 = puVar4[0x343];
        uRam00107b0c = puVar4[0x348];
        uRam00107b10 = puVar4[0x344];
        uRam00107b14 = puVar4[0x345];
        uRam00107b18 = puVar4[0x346];
        uRam00107b1c = puVar4[0x347];
        uRam00107b20 = *puVar18;
        uRam00107b24 = puVar4[0x3c2];
        uRam00107b28 = puVar4[0x3c3];
        uRam00107b2c = puVar4[0x3c8];
        uRam00107b30 = puVar4[0x3c4];
        uRam00107b34 = puVar4[0x3c5];
        uRam00107b38 = puVar4[0x3c6];
        uRam00107b3c = puVar4[0x3c7];
        uRam00107b40 = *puVar20;
        uRam00107b44 = *puVar6;
        uRam0010814c = puVar22[5];
        puVar14 = (uint *)0x10814c;
        uRam00108150 = puVar22[6];
        uRam00108154 = puVar22[7];
        uRam00108158 = puVar22[8];
        uRam0010815c = puVar22[4];
        uRam00108160 = *puVar22;
        uRam00108164 = puVar22[1];
        uRam00108168 = puVar22[2];
        uRam0010816c = puVar22[3];
        uRam00108170 = *puVar4;
        uRam00108174 = puVar4[1];
        uRam00108178 = puVar4[2];
        uRam0010817c = puVar4[3];
        uRam00108180 = puVar4[4];
        uRam00108184 = puVar4[5];
        uRam00108188 = puVar4[6];
        uRam0010818c = *puVar8;
        puVar16 = (uint *)0x10818c;
        uRam00108190 = puVar8[1];
        uRam00108194 = puVar8[2];
        uRam00108198 = puVar8[3];
        uRam0010819c = puVar8[4];
        uRam001081a0 = puVar8[5];
        uRam001081a4 = puVar8[6];
        uRam001081a8 = *puVar17;
        uRam001081ac = puVar17[1];
        uRam001081b0 = puVar17[2];
        uRam001081b4 = puVar17[8];
        puVar6 = puVar11 + 0x68f;
        *puVar6 = 1;
        puVar11[0x690] = 1;
        puVar11[0x691] = 1;
        puVar11[0x692] = 1;
        puVar11[0x693] = 1;
        puVar11[0x694] = 1;
        *puVar6 = 3;
        puVar11[0x690] = 3;
        puVar11[0x691] = 3;
        puVar11[0x692] = 3;
        puVar11[0x693] = 3;
        puVar11[0x694] = 3;
        puVar11[-0xb7] = puVar11[-0xb7] | 0x80;
        func_0x0608a034();
        puVar22[5] = *puVar14;
        puVar22[6] = puVar14[1];
        puVar22[7] = puVar14[2];
        puVar22[8] = puVar14[3];
        puVar22[4] = puVar14[4];
        *puVar22 = puVar14[5];
        puVar22[1] = puVar14[6];
        puVar22[2] = puVar14[7];
        puVar22[3] = puVar14[8];
        *puVar4 = puVar14[9];
        puVar4[1] = puVar14[10];
        puVar4[2] = puVar14[0xb];
        puVar4[3] = puVar14[0xc];
        puVar4[4] = puVar14[0xd];
        puVar4[5] = puVar14[0xe];
        puVar4[6] = puVar14[0xf];
        *puVar8 = *puVar16;
        puVar8[1] = puVar16[1];
        puVar8[2] = puVar16[2];
        puVar8[3] = puVar16[3];
        puVar8[4] = puVar16[4];
        puVar8[5] = puVar16[5];
        puVar8[6] = puVar16[6];
        *puVar17 = puVar16[7];
        puVar17[1] = puVar16[8];
        puVar17[2] = puVar16[9];
        puVar17[8] = puVar16[10];
        puVar18[2] = *extraout_r1;
        puVar18[3] = extraout_r1[1];
        puVar18[8] = extraout_r1[2];
        puVar18[4] = extraout_r1[3];
        puVar18[5] = extraout_r1[4];
        puVar18[6] = extraout_r1[5];
        puVar18[7] = extraout_r1[6];
        *puVar18 = extraout_r1[7];
        puVar20[2] = extraout_r1[8];
        puVar20[3] = extraout_r1[9];
        puVar20[8] = extraout_r1[10];
        puVar20[4] = extraout_r1[0xb];
        puVar20[5] = extraout_r1[0xc];
        puVar20[6] = extraout_r1[0xd];
        puVar20[7] = extraout_r1[0xe];
        *puVar20 = extraout_r1[0xf];
        puVar4 = puVar18 + 0x340;
        *puVar4 = extraout_r1[0x10];
        puVar6[1] = 0;
        puVar6[5] = 0;
        puVar6[4] = 0;
        puVar6 = puVar4;
      }
      else {
        msys_to_p11_sync_cmd(3);
        puVar4 = (uint *)piVar21[6];
        *puVar14 = *puVar12;
        *puVar12 = 1;
        puVar12[6] = 1;
        *puVar22 = *puVar22 | 4;
      }
      do {
        puVar15[2] = 0xff;
        puVar15[2] = 0xee;
        puVar15[2] = 0xab;
        puVar15[2] = 0xe;
        puVar15[2] = 0x55;
      } while ((puVar19[1] & 1) == 0);
      iVar1 = piVar21[6];
      if (iVar1 == 1) {
        do {
        } while ((puVar12[3] & 4) == 0);
        uVar2 = 4;
LAB_0608a9fe:
        puVar12[2] = uVar2;
        *puVar12 = 0x20;
      }
      else {
        if (iVar1 == 3) {
          uVar2 = 2;
          goto LAB_0608a9fe;
        }
        if (iVar1 == 2) {
          do {
          } while ((puVar12[3] & 1) == 0);
          uVar2 = 1;
          goto LAB_0608a9fe;
        }
      }
      if ((*puVar17 & 1) == 0) {
        puVar20[4] = puVar20[4] | 0x10;
        puVar20[2] = puVar20[2] | 0x10;
        puVar18[4] = puVar18[4] | 8;
        puVar18[2] = puVar18[2] | 8;
        puVar18[7] = puVar18[7] & 0x10;
        puVar18[6] = puVar18[6] & 0x10;
        *puVar18 = *puVar18 | 0x10;
        puVar18[2] = puVar18[2] & 0x10;
        delay_tmr2_lrc(10,puVar4);
        puVar18[6] = puVar18[6] | 0x10;
        delay_tmr2_lrc(10);
        puVar18[7] = puVar18[7] | 0x10;
        if ((puVar6[5] & 0x10000) == 0) {
          *puVar18 = *puVar18 | 8;
          puVar18[2] = puVar18[2] & 8;
          puVar18[4] = puVar18[4] & 8;
          puVar18[5] = puVar18[5] & 8;
          puVar18[4] = puVar18[4] & 1;
          puVar18[5] = puVar18[5] & 1;
          puVar18[2] = puVar18[2] & 1;
          puVar18[3] = puVar18[3] | 2;
          puVar18[4] = puVar18[4] | 2;
          puVar18[5] = puVar18[5] & 2;
          puVar18[2] = puVar18[2] | 2;
          puVar18[3] = puVar18[3] | 4;
          puVar18[4] = puVar18[4] | 4;
          puVar18[5] = puVar18[5] & 4;
          puVar18[2] = puVar18[2] | 4;
          if (cRam00104db5 == '\x04') {
            puVar18[3] = puVar18[3] | 0x20;
            puVar18[4] = puVar18[4] | 0x20;
            puVar18[5] = puVar18[5] & 0x20;
            puVar18[2] = puVar18[2] | 0x20;
            goto LAB_0608aafc;
          }
        }
        else {
          *puVar20 = *puVar20 | 0x10;
          puVar20[2] = puVar20[2] & 0x10;
          puVar20[4] = puVar20[4] & 0x10;
          puVar20[5] = puVar20[5] & 0x10;
          puVar18[3] = puVar18[3] | 1;
          puVar18[4] = puVar18[4] & 1;
          puVar18[5] = puVar18[5] & 1;
          puVar18[2] = puVar18[2] & 1;
          puVar18[3] = puVar18[3] | 2;
          puVar18[4] = puVar18[4] | 2;
          puVar18[5] = puVar18[5] & 2;
          puVar18[2] = puVar18[2] | 2;
          puVar20[3] = puVar20[3] | 8;
          puVar20[4] = puVar20[4] | 8;
          puVar20[5] = puVar20[5] & 8;
          puVar20[2] = puVar20[2] | 8;
          if (cRam00104db5 == '\x04') {
            puVar20[3] = puVar20[3] | 4;
            puVar20[4] = puVar20[4] | 4;
            puVar20[5] = puVar20[5] & 4;
            puVar20[2] = puVar20[2] | 4;
LAB_0608aafc:
            puVar18[3] = puVar18[3] | 0x40;
            puVar18[4] = puVar18[4] | 0x40;
            puVar18[5] = puVar18[5] & 0x40;
            puVar18[2] = puVar18[2] | 0x40;
          }
        }
      }
      func_0x0608a054();
      puVar12[0x715] = puVar12[0x715] & 0x3fc7;
      FUN_0608a06e();
      iVar1 = FUN_06089d94();
      if (iVar1 != 0) {
        FUN_0608a0c2();
      }
      if ((*puVar17 & 1) == 0) {
        *puVar17 = *puVar17 & 0x660;
        puVar17[1] = puVar17[1] & 0xfff7bdff;
        puVar17[2] = puVar17[2] & 0xd90;
        *puVar17 = *puVar17 | 1;
        uVar9 = func_0x0608b07e();
        FUN_0608afac(0x10eafa,uVar9);
      }
    }
    uRam00fd5008 = uRam00107b80;
    uRam00fd500c = uRam00107b84;
    uRam00fd5020 = uRam00107b88;
    uRam00fd5010 = uRam00107b8c;
    uRam00fd5014 = uRam00107b90;
    uRam00fd5018 = uRam00107b94;
    uRam00fd501c = uRam00107b98;
    uRam00fd5108 = uRam00107ba0;
    uRam00fd510c = uRam00107ba4;
    uRam00fd5120 = uRam00107ba8;
    uRam00fd5110 = uRam00107bac;
    uRam00fd5114 = uRam00107bb0;
    uRam00fd5118 = uRam00107bb4;
    uRam00fd511c = uRam00107bb8;
    uRam00fd5100 = 0x107bc0;
    uRam00fd5208 = uRam00107bc0;
    uRam00fd520c = uRam00107bc4;
    uRam00fd5220 = uRam00107bc8;
    uRam00fd5210 = uRam00107bcc;
    uRam00fd5214 = uRam00107bd0;
    uRam00fd5218 = uRam00107bd4;
    uRam00fd521c = uRam00107bd8;
    uRam00fd5408 = uRam00107be0;
    uRam00fd540c = uRam00107be4;
    uRam00fd5420 = uRam00107be8;
    uRam00fd5410 = uRam00107bec;
    uRam00fd5414 = uRam00107bf0;
    uRam00fd5418 = uRam00107bf4;
    uRam00fd541c = uRam00107bf8;
    uRam00fd5400 = uRam00107bfc;
    uRam00fd5708 = uRam00107c00;
    uRam00fd570c = uRam00107c04;
    uRam00fd5720 = uRam00107c08;
    uRam00fd5710 = uRam00107c0c;
    uRam00fd5714 = uRam00107c10;
    uRam00fd5718 = uRam00107c14;
    uRam00fd571c = uRam00107c18;
    uRam00fd5700 = uRam00107c1c;
    for (iVar1 = 0; iVar1 != 0x100; iVar1 = iVar1 + 4) {
      iRam00107b7c = iVar1 + 0x107c9c;
      *(undefined4 *)(iVar1 + 0xfd5c00) = *(undefined4 *)(iVar1 + 0x107c98);
    }
    for (iVar1 = 0; iVar1 != 0xc4; iVar1 = iVar1 + 4) {
      iRam00107b7c = iVar1 + 0x107d9c;
      *(undefined4 *)(iVar1 + 0xfd5800) = *(undefined4 *)(iVar1 + 0x107d98);
    }
    uRam00fd6014 = uRam001081b8;
    uRam00fd6018 = uRam001081bc;
    uRam00fd601c = uRam001081c0;
    uRam00fd6020 = uRam001081c4;
    uRam00fd6024 = uRam001081c8;
    uRam00fd6028 = uRam001081cc;
    uRam00fd602c = uRam001081d0;
    uRam00fd6030 = uRam001081d4;
  } while( true );
}


// ===== FUN_0608a402 @ 0608a402

undefined1 FUN_0608a402(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ulonglong uVar7;
  uint *extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  undefined4 uVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  int *piVar15;
  uint *puVar16;
  uint uVar17;
  int *piVar18;
  uint *puVar19;
  uint *puVar20;
  uint *puVar21;
  uint *puVar22;
  uint *puVar23;
  uint *puVar24;
  int *piVar25;
  uint *puVar26;
  BADSPACEBASE *in_sp;
  undefined1 *puVar27;
  undefined1 auStack_4 [4];
  
  op_push_rets_rl();
  puVar27 = auStack_4;
  piVar25 = (int *)0x108ca8;
  if (cRam00108cc7 == '\0') {
LAB_0608ad76:
    op_pop_pc_rl();
    return uRam00104db0;
  }
  piVar18 = (int *)auStack_4;
  if (cRam00108d02 == '\0') {
    iVar1 = func_0x0bfc05a0();
    piVar18 = (int *)puVar27;
    if (iVar1 == 0) goto LAB_0608ad76;
  }
  FUN_06088a6a();
  func_0x0bfc05c0();
  uVar2 = func_0x0bfc0624(piVar25);
  piVar15 = piVar25 + 3;
  uVar3 = func_0x0bfc0624(piVar15);
  if (uVar3 < uVar2) {
    uVar2 = uVar3;
  }
  if (uVar2 == 0) goto LAB_0608ad70;
  puVar19 = (uint *)0xf2a800;
  uVar7 = (ulonglong)uRam00f2a800 << 0x20;
  if ((uVar7 & 0x2000000000) != 0) {
    func_0x0bf7fc06();
    uVar7 = (ulonglong)*(uint *)((*puVar19 & 0x1f) * 4 + 0x6060f9c);
  }
  uVar3 = (uint)((int)uVar7 * 0xf7a) >> 1;
  if ((uVar3 != 0) && (uVar3 < uVar2)) {
    uVar2 = uVar3;
  }
  iVar1 = FUN_06089d94();
  if (iVar1 != 0) {
    func_0x0bf822c6();
  }
  iVar1 = func_0x0bfc0658(uVar2);
  if (iVar1 == 1) goto LAB_0608ad70;
  func_0x0bfc0682(1);
  func_0x0bfc0694(1);
  puVar10 = puVar19 + 0x41;
  puVar23 = (uint *)0xfd3e00;
  if ((int *)*piVar25 == piVar25) {
    iVar1 = func_0x0bfc06a4(uVar2);
    if (iVar1 == 0) goto LAB_0608ad70;
    iVar4 = func_0x0bfc06dc();
    iVar1 = -2;
    if (iVar4 != -2) {
      *puVar23 = *puVar23 | 0x40;
      iVar1 = iVar4;
    }
  }
  else {
    iVar1 = func_0x0bfc06a4(*puVar10);
    if (iVar1 == 0) goto LAB_0608ad70;
    iVar1 = func_0x0bfc06dc(*puVar10);
  }
  iVar4 = func_0x0bfc06ee();
  piVar25[6] = iVar4;
  func_0x0bfc0724(piVar25);
  func_0x0bfc0724(piVar15);
  uVar3 = 0;
  func_0x0bfc0682(0);
  func_0x0bfc0694(0);
  func_0x0bfc075a();
  uVar2 = op_insert_rrii((uint)bRam001081d9,8,8);
  bRam001081d8 = (byte)(uVar2 & 0xc70);
  bRam001081d9 = (byte)((uVar2 & 0xc70) >> 8);
  uRam00f27f91 = (undefined1)uVar3;
  uRam00f27f8d = uRam00f27f91;
  if (*(char *)((int)piVar25 + 0x5a) == '\x01') {
    uVar8 = op_insert_rrii((uint)bRam001081d9,8,0x18);
    bRam001081d8 = (byte)uVar8 | 1;
    uRam00f27f8d = 1;
    bRam001081d9 = bRam001081d8;
    if (*(char *)((int)piVar25 + 0x5a) == '\x01') {
      uVar8 = op_insert_rrii((uint)bRam001081d8,8,0x18);
      bRam001081d8 = (byte)uVar8 | 4;
      bRam001081d9 = bRam001081d8;
    }
  }
  puVar26 = (uint *)0xfd0004;
  uRam00fd0018 = uRam00fd0018 | 1;
  uRam00fd001c = uRam00fd001c & 0xfffff8ff | 0xf40;
  uRam00108148 = uRam00fd0014;
  uVar2 = op_insert_rrii((uint)bRam001081d9,8,8);
  puVar21 = (uint *)0xfd1920;
  puVar10 = puVar23 + 0x200;
  puVar11 = puVar23 + 0x240;
  uRam00fd0014 = uVar3;
  if ((uVar2 & 1) == 0) {
    uRam00104db8 = *puVar10;
    uRam00104dbc = *puVar11;
    *puVar10 = *puVar10 & 3;
    *puVar11 = *puVar11 & 3;
    uRam00fd1920 = uRam00fd1920 & 1;
    func_0x060899dc();
LAB_0608a6f6:
    puVar13 = puVar19 + 0x41;
    hw_close_flash();
  }
  else {
    *piVar18 = iVar1;
    uRam00fd1940 = 0xa80;
    uVar3 = op_uextra_rrii(uRam00fd1920,6,5);
    uVar12 = op_uextra_rrii(uRam00fd1920,0xb,4);
    iVar1 = op_uextra_rrii(uRam00fd1920,0xf,4);
    do {
      do {
        uRam00fd1920 = (uVar3 & 0x3b) << 6 | (uVar12 & 1) << 0xb | 0x36080001;
      } while (uVar3 != 3);
    } while ((uVar12 != 3) || (iVar1 != 3));
    uVar8 = op_uextra_rrii(uVar2,3,1);
    uVar8 = op_insert_rrii(uVar8,0x13,1);
    uVar7 = (CONCAT44(uVar8,uVar2 << 0xc | uVar2 >> 2) | 0x9503) & 0xffffffff0000a187;
    uRam00fd1924 = (uint)uVar7 | (uint)(uVar7 >> 0x20);
    uVar7 = CONCAT44(uVar2 << 2,uVar2 >> 1) & 0xffffffff00000078;
    uVar3 = (uint)(uVar7 >> 0x20);
    uVar7 = CONCAT44(uVar3,(uint)uVar7 | uVar3 & 0xe40) & 0xd80ffffffff;
    uRam00fd1928 = (uint)uVar7 | (uint)(uVar7 >> 0x20) | 0x286;
    puVar10 = puVar23 + 0x200;
    puVar11 = puVar23 + 0x240;
    uRam00104db8 = *puVar10;
    uRam00104dbc = *puVar11;
    *puVar10 = *puVar10 & 3;
    *puVar11 = *puVar11 & 3;
    if ((uVar2 & 1) == 0) {
      uRam00fd1920 = uRam00fd1920 & 1;
      func_0x060899dc();
      iVar1 = *piVar18;
      goto LAB_0608a6f6;
    }
    func_0x060899dc();
    iVar1 = *piVar18;
    puVar13 = puVar19 + 0x41;
  }
  uVar7 = CONCAT44(*puVar13,*puVar13) & 0x8000000020;
  *(byte *)((int)piVar25 + 0x1d) = (byte)uVar7 | (byte)(uVar7 >> 0x20);
  *puVar26 = *puVar26 | 8;
  puVar16 = (uint *)0x107a40;
  puVar14 = puVar13 + -0xc1;
  puVar22 = puVar10 + 0x340;
  puVar24 = puVar10 + 0x3c0;
  puVar9 = puVar10 + 0x680;
  if (piVar25[6] == 3) {
    uRam00107b04 = puVar10[0x342];
    uRam00107b08 = puVar10[0x343];
    uRam00107b0c = puVar10[0x348];
    uRam00107b10 = puVar10[0x344];
    uRam00107b14 = puVar10[0x345];
    uRam00107b18 = puVar10[0x346];
    uRam00107b1c = puVar10[0x347];
    uRam00107b20 = *puVar22;
    uRam00107b24 = puVar10[0x3c2];
    uRam00107b28 = puVar10[0x3c3];
    uRam00107b2c = puVar10[0x3c8];
    uRam00107b30 = puVar10[0x3c4];
    uRam00107b34 = puVar10[0x3c5];
    uRam00107b38 = puVar10[0x3c6];
    uRam00107b3c = puVar10[0x3c7];
    uRam00107b40 = *puVar24;
    uRam00107b44 = *puVar9;
    uRam0010814c = puVar26[5];
    puVar9 = (uint *)0x10814c;
    uRam00108150 = puVar26[6];
    uRam00108154 = puVar26[7];
    uRam00108158 = puVar26[8];
    uRam0010815c = puVar26[4];
    uRam00108160 = *puVar26;
    uRam00108164 = puVar26[1];
    uRam00108168 = puVar26[2];
    uRam0010816c = puVar26[3];
    uRam00108170 = *puVar10;
    uRam00108174 = puVar10[1];
    uRam00108178 = puVar10[2];
    uRam0010817c = puVar10[3];
    uRam00108180 = puVar10[4];
    uRam00108184 = puVar10[5];
    uRam00108188 = puVar10[6];
    uRam0010818c = *puVar11;
    puVar20 = (uint *)0x10818c;
    uRam00108190 = puVar11[1];
    uRam00108194 = puVar11[2];
    uRam00108198 = puVar11[3];
    uRam0010819c = puVar11[4];
    uRam001081a0 = puVar11[5];
    uRam001081a4 = puVar11[6];
    uRam001081a8 = *puVar21;
    uRam001081ac = puVar21[1];
    uRam001081b0 = puVar21[2];
    uRam001081b4 = puVar21[8];
    puVar16 = puVar13 + 0x68f;
    *puVar16 = 1;
    puVar13[0x690] = 1;
    puVar13[0x691] = 1;
    puVar13[0x692] = 1;
    puVar13[0x693] = 1;
    puVar13[0x694] = 1;
    *puVar16 = 3;
    puVar13[0x690] = 3;
    puVar13[0x691] = 3;
    puVar13[0x692] = 3;
    puVar13[0x693] = 3;
    puVar13[0x694] = 3;
    puVar13[-0xb7] = puVar13[-0xb7] | 0x80;
    func_0x0608a034();
    puVar26[5] = *puVar9;
    puVar26[6] = puVar9[1];
    puVar26[7] = puVar9[2];
    puVar26[8] = puVar9[3];
    puVar26[4] = puVar9[4];
    *puVar26 = puVar9[5];
    puVar26[1] = puVar9[6];
    puVar26[2] = puVar9[7];
    puVar26[3] = puVar9[8];
    *puVar10 = puVar9[9];
    puVar10[1] = puVar9[10];
    puVar10[2] = puVar9[0xb];
    puVar10[3] = puVar9[0xc];
    puVar10[4] = puVar9[0xd];
    puVar10[5] = puVar9[0xe];
    puVar10[6] = puVar9[0xf];
    *puVar11 = *puVar20;
    puVar11[1] = puVar20[1];
    puVar11[2] = puVar20[2];
    puVar11[3] = puVar20[3];
    puVar11[4] = puVar20[4];
    puVar11[5] = puVar20[5];
    puVar11[6] = puVar20[6];
    *puVar21 = puVar20[7];
    puVar21[1] = puVar20[8];
    puVar21[2] = puVar20[9];
    puVar21[8] = puVar20[10];
    puVar22[2] = *extraout_r1;
    puVar22[3] = extraout_r1[1];
    puVar22[8] = extraout_r1[2];
    puVar22[4] = extraout_r1[3];
    puVar22[5] = extraout_r1[4];
    puVar22[6] = extraout_r1[5];
    puVar22[7] = extraout_r1[6];
    *puVar22 = extraout_r1[7];
    puVar24[2] = extraout_r1[8];
    puVar24[3] = extraout_r1[9];
    puVar24[8] = extraout_r1[10];
    puVar24[4] = extraout_r1[0xb];
    puVar24[5] = extraout_r1[0xc];
    puVar24[6] = extraout_r1[0xd];
    puVar24[7] = extraout_r1[0xe];
    *puVar24 = extraout_r1[0xf];
    puVar9 = puVar22 + 0x340;
    *puVar9 = extraout_r1[0x10];
    puVar16[1] = 0;
    puVar16[5] = 0;
    puVar16[4] = 0;
  }
  else {
    msys_to_p11_sync_cmd(3);
    *puVar16 = *puVar14;
    *puVar14 = 1;
    puVar14[6] = 1;
    *puVar26 = *puVar26 | 4;
  }
  do {
    puVar19[2] = 0xff;
    puVar19[2] = 0xee;
    puVar19[2] = 0xab;
    puVar19[2] = 0xe;
    puVar19[2] = 0x55;
  } while ((puVar23[1] & 1) == 0);
  iVar4 = piVar25[6];
  if (iVar4 == 1) {
    do {
    } while ((puVar14[3] & 4) == 0);
    uVar2 = 4;
LAB_0608a9fe:
    puVar14[2] = uVar2;
    *puVar14 = 0x20;
  }
  else {
    if (iVar4 == 3) {
      uVar2 = 2;
      goto LAB_0608a9fe;
    }
    if (iVar4 == 2) {
      do {
      } while ((puVar14[3] & 1) == 0);
      uVar2 = 1;
      goto LAB_0608a9fe;
    }
  }
  if ((*puVar21 & 1) == 0) {
    puVar24[4] = puVar24[4] | 0x10;
    puVar24[2] = puVar24[2] | 0x10;
    puVar22[4] = puVar22[4] | 8;
    puVar22[2] = puVar22[2] | 8;
    puVar22[7] = puVar22[7] & 0x10;
    puVar22[6] = puVar22[6] & 0x10;
    *puVar22 = *puVar22 | 0x10;
    puVar22[2] = puVar22[2] & 0x10;
    delay_tmr2_lrc(10);
    puVar22[6] = puVar22[6] | 0x10;
    delay_tmr2_lrc(10);
    puVar22[7] = puVar22[7] | 0x10;
    if ((CONCAT44(puVar9[5],0x104db5) & 0x1000000000000) == 0) {
      *puVar22 = *puVar22 | 8;
      puVar22[2] = puVar22[2] & 8;
      puVar22[4] = puVar22[4] & 8;
      puVar22[5] = puVar22[5] & 8;
      puVar22[4] = puVar22[4] & 1;
      puVar22[5] = puVar22[5] & 1;
      puVar22[2] = puVar22[2] & 1;
      puVar22[3] = puVar22[3] | 2;
      puVar22[4] = puVar22[4] | 2;
      puVar22[5] = puVar22[5] & 2;
      puVar22[2] = puVar22[2] | 2;
      puVar22[3] = puVar22[3] | 4;
      puVar22[4] = puVar22[4] | 4;
      puVar22[5] = puVar22[5] & 4;
      puVar22[2] = puVar22[2] | 4;
      if (cRam00104db5 == '\x04') {
        puVar22[3] = puVar22[3] | 0x20;
        puVar22[4] = puVar22[4] | 0x20;
        puVar22[5] = puVar22[5] & 0x20;
        puVar22[2] = puVar22[2] | 0x20;
        goto LAB_0608aafc;
      }
    }
    else {
      *puVar24 = *puVar24 | 0x10;
      puVar24[2] = puVar24[2] & 0x10;
      puVar24[4] = puVar24[4] & 0x10;
      puVar24[5] = puVar24[5] & 0x10;
      puVar22[3] = puVar22[3] | 1;
      puVar22[4] = puVar22[4] & 1;
      puVar22[5] = puVar22[5] & 1;
      puVar22[2] = puVar22[2] & 1;
      puVar22[3] = puVar22[3] | 2;
      puVar22[4] = puVar22[4] | 2;
      puVar22[5] = puVar22[5] & 2;
      puVar22[2] = puVar22[2] | 2;
      puVar24[3] = puVar24[3] | 8;
      puVar24[4] = puVar24[4] | 8;
      puVar24[5] = puVar24[5] & 8;
      puVar24[2] = puVar24[2] | 8;
      if (cRam00104db5 == '\x04') {
        puVar24[3] = puVar24[3] | 4;
        puVar24[4] = puVar24[4] | 4;
        puVar24[5] = puVar24[5] & 4;
        puVar24[2] = puVar24[2] | 4;
LAB_0608aafc:
        puVar22[3] = puVar22[3] | 0x40;
        puVar22[4] = puVar22[4] | 0x40;
        puVar22[5] = puVar22[5] & 0x40;
        puVar22[2] = puVar22[2] | 0x40;
      }
    }
  }
  func_0x0608a054();
  puVar14[0x715] = puVar14[0x715] & 0x3fc7;
  FUN_0608a06e();
  iVar4 = FUN_06089d94();
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_0608a0c2();
  }
  if ((*puVar21 & 1) == 0) {
    uVar2 = *puVar21;
    uVar3 = puVar21[1];
    uVar12 = puVar21[2];
    *puVar21 = *puVar21 & 0x660;
    puVar21[1] = puVar21[1] & 0xfff7bdff;
    puVar21[2] = puVar21[2] & 0xd90;
    *puVar21 = *puVar21 | 1;
    iVar6 = piVar25[0xce];
    func_0x0608b07e();
    FUN_0608afac(0x10eafa);
    func_0x0608a184();
    iVar5 = func_0x0608b088();
    if (iVar5 == 0) {
      uVar8 = op_ext_l_u(iVar6);
      delay_tmr2_lrc(uVar8);
    }
    else {
      xosc_adet_en(1);
      iVar6 = FUN_0608a0c2();
      do {
        iVar5 = FUN_0608a0c2();
        uVar17 = iVar5 - iVar6;
        FUN_0608a06e();
        iVar5 = func_0x0608aff4();
        if (3000 < uVar17) break;
      } while (iVar5 == 0);
      xosc_adet_en(0);
    }
    *puVar21 = *puVar21 | uVar2 & 0x660;
    puVar21[1] = puVar21[1] | uVar3 & 0x84200;
    puVar21[2] = puVar21[2] | uVar12 & 0xd90;
    iVar6 = 1 - iVar4;
    iRam00104dc4 = FUN_0608a0c2();
    iRam00104dc4 = iVar6 + iRam00104dc4;
    iVar6 = FUN_06089d94();
    if (iVar6 != 0) {
      uVar2 = extraout_r1_00;
      if (extraout_r1_00 <= uRam00104dc8) {
        iVar6 = utof(uRam00104dc8);
        iVar5 = utof(extraout_r1_00);
        uVar2 = op_ftou_trunc_rr(iVar5 * 0x3c23d70a + iVar6 * 0x3f7d70a4);
      }
      uRam00104dc8 = uVar2;
      piVar25[0xd0] = 1000;
    }
  }
  else {
    func_0x0608a184();
  }
  uVar3 = ~*(uint *)((int)puVar14 + 0xa2a) & 1;
  uVar2 = ~*puVar11 & 1;
  if (uVar2 != 0 || uVar3 != 0) {
    if (uVar2 != 0) {
      *puVar21 = *puVar21 | 0x680;
    }
    if (uVar3 != 0) {
      puVar21[2] = puVar21[2] | 0xf00;
      *(uint *)((int)puVar14 + 0xa2a) = *(uint *)((int)puVar14 + 0xa2a) | 1;
    }
    if (uVar2 != 0) {
      *puVar11 = *puVar11 | 1;
    }
    delay_tmr2_lrc(10);
    if (uVar3 != 0) {
      *(uint *)((int)puVar14 + 0xa2a) = *(uint *)((int)puVar14 + 0xa2a) | 2;
    }
    if (uVar2 != 0) {
      *puVar11 = *puVar11 | 2;
    }
    delay_tmr2_lrc(200);
  }
  puVar26[4] = uRam00108148;
  puVar26[6] = puVar26[6] & 0xfffff8ff | 0xec0;
  if ((bRam001081d8 & 1) == 0) {
    iVar4 = 1 - iVar4;
    piVar18 = (int *)0x104dc0;
    while( true ) {
      iVar6 = FUN_0608a0c2();
      *piVar18 = iVar4 + iVar6;
      iVar6 = FUN_06089d94();
      if ((iVar6 == 0) || (999 < extraout_r1_01)) break;
      delay_tmr2_lrc(10);
    }
  }
  FUN_0608a06e();
  uVar8 = 0x6051260;
  do {
    func_0x05f9acba(uVar8);
    iVar4 = func_0x05f9ac72(uVar8);
  } while (iVar4 != 0);
  func_0x0bfc09da(iVar1);
  if (*(char *)((int)piVar25 + 0x1d) != '\0') {
    func_0x0bf822c6();
  }
  func_0x0bfc0b6e(iVar1);
  puVar19 = (uint *)0x107a40;
  func_0x0bfc0b92(0);
  do {
  } while ((puVar14[3] & 0x20) == 0);
  puVar14[2] = 0x20;
  *puVar14 = *puVar19;
  func_0x0bfc0cc4();
LAB_0608ad70:
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608ad7a @ 0608ad7a

undefined1 FUN_0608ad7a(void)

{
  return uRam00104db0;
}


// ===== FUN_0608adae @ 0608adae

undefined4 FUN_0608adae(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined4 *puVar3;
  undefined1 auStack_84 [128];
  
  puVar3 = (undefined4 *)(auStack_84 + 0x80);
  func_0x0bfa4f5e();
  *puVar3 = unaff_retaddr;
  uVar1 = func_0x0bfa54a8();
  op_push_rets_rl();
  iVar2 = func_0x0bfa4f5e(uVar1);
  if (iVar2 != 0) {
    func_0x05f9ac6e(0,uVar1);
  }
  op_pop_pc_rl();
  return 0;
}


// ===== FUN_0608adbc @ 0608adbc

undefined4 FUN_0608adbc(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = func_0x0bfa54a8();
  op_push_rets_rl();
  iVar2 = func_0x0bfa4f5e(uVar1);
  if (iVar2 != 0) {
    func_0x05f9ac6e(0,uVar1);
  }
  op_pop_pc_rl();
  return 0;
}


// ===== FUN_0608adc6 @ 0608adc6

undefined4 FUN_0608adc6(undefined4 param_1)

{
  int iVar1;
  
  op_push_rets_rl();
  iVar1 = func_0x0bfa4f5e(param_1);
  if (iVar1 != 0) {
    func_0x05f9ac6e(0,param_1);
  }
  op_pop_pc_rl();
  return 0;
}


// ===== FUN_0608ade8 @ 0608ade8

undefined4 FUN_0608ade8(void)

{
  return 0;
}


// ===== FUN_0608adfe @ 0608adfe

/* WARNING: Possible PIC construction at 0x0608aeb0: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0608aeb2) */
/* WARNING: Removing unreachable block (ram,0x0608aee2) */
/* WARNING: Removing unreachable block (ram,0x0608aee0) */
/* WARNING: Removing unreachable block (ram,0x0608aee4) */

void FUN_0608adfe(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined1 auStack_84 [128];
  
  puVar4 = (undefined4 *)(auStack_84 + 0x80);
  func_0x0bfa533a();
  *puVar4 = unaff_retaddr;
  uVar5 = func_0x0bfa55b8();
  uVar1 = (uint)uVar5;
  op_push_rets_rl();
  iVar3 = 0;
  while ((uVar2 = op_ext_b0_u(iVar3), uVar2 <= param_1 &&
         (uVar1 < (uint)((ulonglong)uVar5 >> 0x20) / (uVar2 + 1)))) {
    iVar3 = iVar3 + 1;
  }
  op_pop_pc_rl();
  do {
    op_push_rets_rl();
    uVar5 = CONCAT44(uVar1,uVar2);
    func_0x05f9aca6();
    func_0x05f9aca2();
    do {
    } while ((int)uRam00fe0200 < 0);
    uRam00fe0204 = (undefined4)uVar5;
    uRam00fe0200 = op_insert_rrii((uint)((ulonglong)uVar5 >> 0x20) & 0xf0,0x14,4);
    uRam00fe0200 = uRam00fe0200 | 1;
    uRam001079b8 = (undefined1)uVar5;
    op_pop_pc_rl();
    op_push_rets_rl();
    uVar1 = uRam001079cc;
    uVar2 = __hw_clk_limit(uRam001079cc,*(undefined4 *)((uint)bRam001079d4 * 0xc + 0x104a78),0xff);
    uVar1 = op_ext_b0_u(((uVar1 / 1000000) * 0x1e) / 1000);
  } while( true );
}


// ===== FUN_0608ae0c @ 0608ae0c

/* WARNING: Possible PIC construction at 0x0608aeb0: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0608aeb2) */
/* WARNING: Removing unreachable block (ram,0x0608aee2) */
/* WARNING: Removing unreachable block (ram,0x0608aee0) */
/* WARNING: Removing unreachable block (ram,0x0608aee4) */

void FUN_0608ae0c(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = func_0x0bfa55b8();
  uVar1 = (uint)uVar4;
  op_push_rets_rl();
  iVar3 = 0;
  while ((uVar2 = op_ext_b0_u(iVar3), uVar2 <= param_1 &&
         (uVar1 < (uint)((ulonglong)uVar4 >> 0x20) / (uVar2 + 1)))) {
    iVar3 = iVar3 + 1;
  }
  op_pop_pc_rl();
  do {
    op_push_rets_rl();
    uVar4 = CONCAT44(uVar1,uVar2);
    func_0x05f9aca6();
    func_0x05f9aca2();
    do {
    } while ((int)uRam00fe0200 < 0);
    uRam00fe0204 = (undefined4)uVar4;
    uRam00fe0200 = op_insert_rrii((uint)((ulonglong)uVar4 >> 0x20) & 0xf0,0x14,4);
    uRam00fe0200 = uRam00fe0200 | 1;
    uRam001079b8 = (undefined1)uVar4;
    op_pop_pc_rl();
    op_push_rets_rl();
    uVar1 = uRam001079cc;
    uVar2 = __hw_clk_limit(uRam001079cc,*(undefined4 *)((uint)bRam001079d4 * 0xc + 0x104a78),0xff);
    uVar1 = op_ext_b0_u(((uVar1 / 1000000) * 0x1e) / 1000);
  } while( true );
}


// ===== FUN_0608ae72 @ 0608ae72

void FUN_0608ae72(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  op_push_rets_rl();
  uVar2 = uRam001079cc;
  __hw_clk_limit(uRam001079cc,*(undefined4 *)((uint)bRam001079d4 * 0xc + 0x104a78),0xff);
  uVar1 = op_ext_b0_u(((uVar2 / 1000000) * 0x1e) / 1000);
  func_0x0608ae32(uVar1);
  op_pop_pc_rl();
  for (uVar2 = ((uRam001079c0 / 1000000) * 3) / 3; uVar2 != 0; uVar2 = uVar2 - 1) {
  }
  return;
}


// ===== FUN_0608aeb4 @ 0608aeb4

void FUN_0608aeb4(void)

{
  uint uVar1;
  
  for (uVar1 = ((uRam001079c0 / 1000000) * 3) / 3; uVar1 != 0; uVar1 = uVar1 - 1) {
  }
  return;
}


// ===== FUN_0608aee6 @ 0608aee6

void FUN_0608aee6(int param_1)

{
  int iVar1;
  BADSPACEBASE *in_sp;
  
  op_push_rets_rl();
  for (iVar1 = param_1; iVar1 != 0; iVar1 = iVar1 + -1) {
    param_1 = FUN_0608aeb4(1000);
  }
  op_pop_pc_rl();
  *(int *)((int)in_sp + -4) = param_1;
  do {
    iVar1 = *(int *)((int)in_sp + -4);
    *(int *)((int)in_sp + -4) = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


// ===== FUN_0608aef8 @ 0608aef8

void FUN_0608aef8(int param_1)

{
  bool bVar1;
  int iStack_4;
  
  iStack_4 = param_1;
  do {
    bVar1 = iStack_4 != 0;
    iStack_4 = iStack_4 + -1;
  } while (bVar1);
  return;
}


// ===== FUN_0608afac @ 0608afac

undefined4 FUN_0608afac(code *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  op_push_rets_rl();
  xosc_hcs_set(0x14);
  (*param_1)(0xf);
  xosc_oe_for_hcs(1);
  (*param_1)(0xf);
  xosc_hcs_set(0x10);
  (*param_1)(0xf);
  xosc_oe_for_hcs(0);
  (*param_1)(0xf);
  xosc_hcs_set(0x14);
  (*param_1)(0x1e);
  xosc_oe_for_hcs(1);
  xosc_hcs_set(0x1f);
  (*param_1)(0x1e);
  xosc_oe_for_hcs(0);
  (*param_1)(0x3c);
  xosc_hcs_set(param_2);
  op_pop_pc_rl();
  uVar1 = op_uextra_rrii(uRam00fd1978,4,1);
  return uVar1;
}


// ===== FUN_0608b00a @ 0608b00a

undefined4 FUN_0608b00a(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  op_push_rets_rl();
  iVar3 = 6;
  uVar4 = 0x4000;
  puVar5 = (uint *)0xfd0400;
  while (uVar2 = op_ext_b0_u(iVar3), uVar2 < 0xb) {
    xosc_hcs_set(uVar2);
    *puVar5 = uVar4;
    puVar5[1] = 0;
    puVar5[2] = 0xec8;
    *puVar5 = 0x40;
    *puVar5 = *puVar5 | 1;
    do {
    } while ((*puVar5 & 0x8000) == 0);
    *puVar5 = uVar4;
    iVar1 = func_0x0608aff4();
    if (iVar1 != 0) break;
    iVar3 = iVar3 + 2;
  }
  uRam001079f0 = 0;
  uRam001079f4 = (char)iVar3;
  op_pop_pc_rl();
  return 0;
}


// ===== FUN_0608b092 @ 0608b092

void FUN_0608b092(void)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined4 *puVar6;
  undefined1 auStack_84 [128];
  
  puVar6 = (undefined4 *)(auStack_84 + 0x80);
  iVar1 = FUN_0608adae();
  *puVar6 = unaff_retaddr;
  puVar2 = (undefined4 *)FUN_0608b092(iVar1 + 0x30);
  if (puVar2 != (undefined4 *)0x0) {
    rep_unspec(2,0xc);
    *puVar2 = 0;
    puVar5 = puVar2 + 9;
    puVar2[8] = puVar5;
    puVar2[9] = puVar5;
    puVar2[10] = puVar5;
  }
  *puVar6 = unaff_retaddr;
  pcVar3 = (char *)FUN_0608adbc();
  op_push_rets_rl();
  FUN_06088a6a();
  puVar2 = (undefined4 *)((ulonglong)*(undefined8 *)(pcVar3 + 0x24) >> 0x20);
  *(undefined4 **)((int)*(undefined8 *)(pcVar3 + 0x24) + 4) = puVar2;
  pcVar4 = pcVar3 + 0x24;
  *puVar2 = pcVar4;
  *(char **)(pcVar3 + 0x24) = pcVar4;
  *(char **)(pcVar3 + 0x28) = pcVar4;
  if (*pcVar3 == '\0') {
    FUN_0608b0bc(pcVar3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608b09c @ 0608b09c

void FUN_0608b09c(int param_1)

{
  undefined4 *puVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined4 *puVar5;
  undefined1 auStack_84 [128];
  
  puVar5 = (undefined4 *)(auStack_84 + 0x80);
  puVar1 = (undefined4 *)FUN_0608b092(param_1 + 0x30);
  if (puVar1 != (undefined4 *)0x0) {
    rep_unspec(2,0xc);
    *puVar1 = 0;
    puVar4 = puVar1 + 9;
    puVar1[8] = puVar4;
    puVar1[9] = puVar4;
    puVar1[10] = puVar4;
  }
  *puVar5 = unaff_retaddr;
  pcVar2 = (char *)FUN_0608adbc();
  op_push_rets_rl();
  FUN_06088a6a();
  puVar1 = (undefined4 *)((ulonglong)*(undefined8 *)(pcVar2 + 0x24) >> 0x20);
  *(undefined4 **)((int)*(undefined8 *)(pcVar2 + 0x24) + 4) = puVar1;
  pcVar3 = pcVar2 + 0x24;
  *puVar1 = pcVar3;
  *(char **)(pcVar2 + 0x24) = pcVar3;
  *(char **)(pcVar2 + 0x28) = pcVar3;
  if (*pcVar2 == '\0') {
    FUN_0608b0bc(pcVar2);
  }
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608b0bc @ 0608b0bc

void FUN_0608b0bc(void)

{
  char *pcVar1;
  char *pcVar2;
  undefined4 *puVar3;
  
  pcVar1 = (char *)FUN_0608adbc();
  op_push_rets_rl();
  FUN_06088a6a();
  puVar3 = (undefined4 *)((ulonglong)*(undefined8 *)(pcVar1 + 0x24) >> 0x20);
  *(undefined4 **)((int)*(undefined8 *)(pcVar1 + 0x24) + 4) = puVar3;
  pcVar2 = pcVar1 + 0x24;
  *puVar3 = pcVar2;
  *(char **)(pcVar1 + 0x24) = pcVar2;
  *(char **)(pcVar1 + 0x28) = pcVar2;
  if (*pcVar1 == '\0') {
    FUN_0608b0bc(pcVar1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608b0c6 @ 0608b0c6

void FUN_0608b0c6(char *param_1)

{
  char *pcVar1;
  undefined4 *puVar2;
  
  op_push_rets_rl();
  FUN_06088a6a();
  puVar2 = (undefined4 *)((ulonglong)*(undefined8 *)(param_1 + 0x24) >> 0x20);
  *(undefined4 **)((int)*(undefined8 *)(param_1 + 0x24) + 4) = puVar2;
  pcVar1 = param_1 + 0x24;
  *puVar2 = pcVar1;
  *(char **)(param_1 + 0x24) = pcVar1;
  *(char **)(param_1 + 0x28) = pcVar1;
  if (*param_1 == '\0') {
    FUN_0608b0bc(param_1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608b0f0 @ 0608b0f0

void FUN_0608b0f0(int param_1)

{
  undefined8 uVar1;
  
  *(char *)(param_1 + 3) = *(char *)(param_1 + 3) + -1;
  uVar1 = FUN_0608adbc();
  op_push_rets_rl();
  FUN_06088a6a();
  func_0x0bf8d4e0((int)uVar1 + 0x24,(int)((ulonglong)uVar1 >> 0x20));
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608b104 @ 0608b104

void FUN_0608b104(undefined4 param_1,int param_2)

{
  op_push_rets_rl();
  FUN_06088a6a();
  func_0x0bf8d4e0(param_2 + 0x24,param_1);
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608b124 @ 0608b124

void FUN_0608b124(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  int extraout_r1;
  
  op_push_rets_rl();
  FUN_06088a6a();
  uVar1 = *param_1;
  op_ldm_post1(6,uVar1);
  *(int **)(extraout_r1 + 4) = param_2;
  *param_2 = extraout_r1;
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8(uVar1);
}


// ===== FUN_0608b14c @ 0608b14c

void FUN_0608b14c(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined1 auStack_84 [128];
  
  puVar4 = (undefined4 *)(auStack_84 + 0x80);
  FUN_0608adbc();
  *puVar4 = unaff_retaddr;
  iVar1 = FUN_0608adc6();
  *puVar4 = unaff_retaddr;
  uVar5 = FUN_0608adae(iVar1 + 0x1c);
  puVar3 = (undefined4 *)((ulonglong)uVar5 >> 0x20);
  puVar2 = (undefined4 *)uVar5;
  if (puVar3 != (undefined4 *)0x0) {
    rep_unspec(2,7);
    *puVar3 = 0;
    *(undefined1 *)((int)puVar3 + 3) = 1;
    puVar2 = puVar3 + 4;
    puVar3[4] = puVar2;
    puVar3[5] = puVar2;
  }
  op_push_rets_rl();
  FUN_06088a6a();
  func_0x0bf8d4e0(puVar2 + 4,puVar3);
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608b156 @ 0608b156

void FUN_0608b156(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined1 auStack_84 [128];
  
  puVar4 = (undefined4 *)(auStack_84 + 0x80);
  iVar1 = FUN_0608adc6();
  *puVar4 = unaff_retaddr;
  uVar5 = FUN_0608adae(iVar1 + 0x1c);
  puVar3 = (undefined4 *)((ulonglong)uVar5 >> 0x20);
  puVar2 = (undefined4 *)uVar5;
  if (puVar3 != (undefined4 *)0x0) {
    rep_unspec(2,7);
    *puVar3 = 0;
    *(undefined1 *)((int)puVar3 + 3) = 1;
    puVar2 = puVar3 + 4;
    puVar3[4] = puVar2;
    puVar3[5] = puVar2;
  }
  op_push_rets_rl();
  FUN_06088a6a();
  func_0x0bf8d4e0(puVar2 + 4,puVar3);
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608b160 @ 0608b160

void FUN_0608b160(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_0608adae(param_1 + 0x1c);
  puVar2 = (undefined4 *)((ulonglong)uVar3 >> 0x20);
  puVar1 = (undefined4 *)uVar3;
  if (puVar2 != (undefined4 *)0x0) {
    rep_unspec(2,7);
    *puVar2 = 0;
    *(undefined1 *)((int)puVar2 + 3) = 1;
    puVar1 = puVar2 + 4;
    puVar2[4] = puVar1;
    puVar2[5] = puVar1;
  }
  op_push_rets_rl();
  FUN_06088a6a();
  func_0x0bf8d4e0(puVar1 + 4,puVar2);
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608b180 @ 0608b180

void FUN_0608b180(undefined4 param_1,int param_2)

{
  op_push_rets_rl();
  FUN_06088a6a();
  func_0x0bf8d4e0(param_2 + 0x10,param_1);
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608b19e @ 0608b19e

int FUN_0608b19e(int *param_1)

{
  return *param_1 + -0x24;
}


// ===== FUN_0608b1b0 @ 0608b1b0

void FUN_0608b1b0(int param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  op_push_rets_rl();
  if (param_3 == (int *)0x0) {
    op_pop_pc_rl();
    op_push_rets_rl();
    FUN_06088b0a(0x55);
    FUN_06088a6a();
    piVar2 = (int *)0x104aac;
    do {
      piVar2 = (int *)*piVar2;
      if (piVar2 == (int *)0x104aac) goto LAB_0608b26a;
    } while (piVar2[2] != param_1);
    for (; param_2 < param_3; param_2 = param_2 + 1) {
      *param_2 = (*param_2 + param_1) - piVar2[3];
    }
    func_0x0bfa58c4();
    FUN_0608adbc();
LAB_0608b26a:
                    /* WARNING: Subroutine does not return */
    FUN_06088ab8();
  }
  FUN_06088b0a(0x55);
  FUN_06088a6a();
  piVar2 = (int *)0x104aac;
  while (piVar2 = (int *)*piVar2, piVar2 != (int *)0x104aac) {
    if ((int *)piVar2[3] == param_3) goto LAB_0608b216;
  }
  iVar3 = (int)param_3 - param_1;
  iVar1 = FUN_0608adc6(0x10);
  for (; param_4 < param_5; param_4 = param_4 + 1) {
    *param_4 = *param_4 + iVar3;
  }
  *(int *)(iVar1 + 8) = param_1;
  param_3[3] = (int)param_3;
  func_0x05f9ac62(param_1,param_2);
  func_0x0bfa58b2(iVar1);
LAB_0608b216:
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608b224 @ 0608b224

void FUN_0608b224(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  
  op_push_rets_rl();
  FUN_06088b0a(0x55);
  FUN_06088a6a();
  piVar1 = (int *)0x104aac;
  do {
    piVar1 = (int *)*piVar1;
    if (piVar1 == (int *)0x104aac) goto LAB_0608b26a;
  } while (piVar1[2] != param_1);
  for (; param_2 < param_3; param_2 = param_2 + 1) {
    *param_2 = (*param_2 + param_1) - piVar1[3];
  }
  func_0x0bfa58c4();
  FUN_0608adbc();
LAB_0608b26a:
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608b278 @ 0608b278

void FUN_0608b278(int param_1)

{
  undefined8 uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ulonglong uVar9;
  uint uVar10;
  undefined1 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined1 uVar14;
  byte *pbVar15;
  undefined2 *puVar16;
  uint uVar17;
  ushort *puVar18;
  ushort *puVar19;
  int iVar20;
  uint *puVar21;
  int iVar22;
  ushort *puVar23;
  int iVar24;
  BADSPACEBASE *in_sp;
  undefined4 *puVar25;
  undefined1 auStack_30 [48];
  
  op_push_rets_rl();
  puVar25 = (undefined4 *)auStack_30;
  iVar24 = 0x106060;
  if (cRam00106b45 != '\0') {
    func_0x0bf83db4(uRam00106b41);
LAB_0608b61a:
    op_pop_pc_rl();
    op_push_srl();
    op_push_rmask(0x3ff);
    FUN_06088a6a();
    puVar12 = (undefined4 *)0x106ab8;
    iVar24 = 0;
    iVar20 = 1;
    puVar21 = (uint *)0xf000a8;
    iVar13 = 0;
    do {
      if (iVar13 == 0x10) {
                    /* WARNING: Subroutine does not return */
        FUN_06088ab8();
      }
      uVar17 = iVar20 << iVar13;
      if ((*puVar21 & uVar17) == 0) {
        if ((puVar21[1] & uVar17) != 0) {
          uVar5 = op_ext_b0_u(iVar24);
          iVar6 = func_0x0bf83ccc(uVar5);
          if (iVar6 < 0) {
            puVar21[2] = puVar21[2] | uVar17;
            goto LAB_0608b658;
          }
        }
      }
      else {
        puVar21[2] = puVar21[2] | uVar17;
        if ((puVar21[1] & uVar17) != 0) {
LAB_0608b658:
          puVar21[1] = puVar21[1] & ~uVar17;
          if ((code *)puVar12[1] != (code *)0x0) {
            (*(code *)puVar12[1])(*puVar12);
          }
        }
      }
      iVar24 = iVar24 + 1;
      puVar12 = puVar12 + 2;
      iVar13 = iVar13 + 1;
    } while( true );
  }
  iVar13 = 0xae4;
  if (cRam00106b44 != '\0') goto LAB_0608b61a;
  FUN_06088a6a();
  *(undefined1 *)(iVar24 + iVar13) = 1;
  if (param_1 != 0) {
    func_0x0bf83dd4();
  }
  uVar5 = 0;
  puVar25[1] = 0;
  iVar13 = 0;
  *puVar25 = 0;
  for (uVar17 = 0;
      ((int)uVar17 < 0x10 && (iVar20 = *(int *)(iVar24 + 0xb38 + uVar17 * 4), iVar20 != 0));
      uVar17 = uVar17 + 1) {
    *(short *)((int)puVar25 + uVar17 * 2 + 0x10) = (short)uVar5;
    pbVar15 = (byte *)(iVar20 + 0x2c);
    puVar23 = (ushort *)(iVar20 + 0x2c);
    puVar18 = puVar23;
    if (((*pbVar15 & 8) != 0) ||
       ((puVar18 = *(ushort **)(iVar20 + 0x34), puVar18 != (ushort *)0x0 && ((*puVar18 & 8) != 0))))
    {
      iVar6 = *(int *)(iVar20 + 0x38);
      iVar22 = 0;
      do {
        if ((iVar6 == 0) || ((*puVar18 & 7) == 3)) {
          iVar3 = *(int *)(iVar20 + 0x3c);
          uVar4 = *(undefined4 *)(pbVar15 + 0x14);
        }
        else {
          iVar3 = *(int *)(iVar6 + 0x3c);
          uVar4 = *(undefined4 *)(iVar6 + 0x40);
        }
        uVar8 = (**(code **)(iVar3 + 0x10))(uVar4,(undefined1 *)((int)puVar25 + 8));
        uVar8 = uVar8 ^ 0x680;
        uVar10 = (uint)puVar18[2];
        puVar19 = puVar18;
        if (uVar10 == 0) {
          func_0x0bf83daa();
          uVar10 = (uint)puVar18[2];
          puVar19 = puVar18;
        }
        uVar2 = puVar19[1];
        *(byte *)(iVar20 + 2) = (byte)(uVar8 / uVar10) & 0x7f;
        iVar3 = (uint)uVar2 - (uVar8 - (uVar8 / uVar10) * uVar10);
        *(undefined1 *)(iVar20 + 1) = 0xff;
        iVar3 = ((iVar3 + (iVar3 >> 0x1f & uVar10)) - uVar10) + 0xff;
        if (iVar3 < 3) {
          *(undefined8 *)(iVar20 + 0x1c) = *(undefined8 *)(puVar25 + 2);
          *(ushort *)(iVar20 + 0xc) = (short)iVar3 + puVar19[3];
          if (iVar13 == 0) {
            *puVar25 = 0;
            puVar25[1] = puVar19;
            iVar6 = 0xae2;
            iVar13 = iVar20;
          }
          else {
            if ((*(ushort *)puVar25[1] & 7) < (*puVar19 & 7)) {
              uVar4 = 1;
              iVar6 = 0xae2;
              if (puVar19 == puVar23) {
LAB_0608b422:
                uVar4 = 0;
              }
            }
            else {
              iVar6 = 0xae2;
              if (((*(ushort *)puVar25[1] & 7) != (*puVar19 & 7)) ||
                 (iVar3 = func_0x0bfa9b70(*(undefined4 *)(iVar20 + 0x10),
                                          *(undefined4 *)(iVar13 + 0x10)), iVar3 < 1))
              goto LAB_0608b42c;
              uVar4 = 1;
              if (puVar19 == puVar23) goto LAB_0608b422;
            }
            *puVar25 = uVar4;
            puVar25[1] = puVar19;
            iVar13 = iVar20;
          }
LAB_0608b42c:
          if ((uVar17 == 0) && (*(char *)(iVar24 + iVar6) != '\0')) {
            *(undefined1 *)(iVar24 + iVar6 + 1) = 0;
            *(undefined1 *)(iVar24 + iVar6) = 0;
          }
LAB_0608b440:
          if (((*(byte *)(iVar24 + 0xae3) == uVar17) &&
              ((iVar6 = op_uextra_rrii(iVar22,0,0x10), iVar6 != 0 && ((*pbVar15 & 8) != 0)))) &&
             ((*(byte **)(iVar20 + 0x34) == (byte *)0x0 || ((**(byte **)(iVar20 + 0x34) & 8) != 0)))
             ) {
            func_0x0bf83dd4();
          }
          break;
        }
        iVar7 = op_uextra_rrii(iVar22,0,0x10);
        if ((iVar7 == 0) || (iVar3 < iVar7)) {
          uVar1 = *(undefined8 *)(puVar25 + 2);
          *(short *)((int)puVar25 + uVar17 * 2 + 0x10) = (short)iVar3;
          *(undefined8 *)(iVar20 + 0x1c) = uVar1;
          iVar22 = iVar3;
        }
        puVar18 = *(ushort **)(iVar20 + 0x34);
        if ((puVar18 == (ushort *)0x0) || (puVar19 == puVar18)) goto LAB_0608b440;
      } while ((*puVar18 & 8) != 0);
    }
  }
  if (iVar13 == 0) {
    iVar13 = *(int *)(iVar24 + 0xb38 + (uint)*(byte *)(iVar24 + 0xae3) * 4);
    if (iVar13 == 0) {
      func_0x0bf83db4(*(undefined1 *)(iVar24 + 0xae1));
      *(undefined1 *)(iVar24 + 0xae4) = 0;
      goto LAB_0608b614;
    }
    if ((*(byte *)(iVar13 + 0x2c) & 8) == 0) {
      func_0x0bf83e00(iVar13 + 0x1c);
      *(undefined2 *)(iVar13 + 0xc) = *(undefined2 *)(iVar13 + 0x32);
      goto LAB_0608b472;
    }
    puVar16 = *(undefined2 **)((int)puVar25 + 4);
    if ((*(byte **)(iVar13 + 0x34) == (byte *)0x0) || ((**(byte **)(iVar13 + 0x34) & 8) != 0)) {
      *(undefined2 *)(iVar24 + 0xafc) = *(undefined2 *)(iVar24 + 0xb22);
      func_0x0bf83dd4();
      iVar13 = iVar24 + 0xaf0;
    }
    else {
      func_0x0bf83e00(iVar13 + 0x1c);
      *(undefined2 *)(iVar13 + 0xc) = *(undefined2 *)(*(int *)(iVar13 + 0x34) + 6);
      *puVar25 = 1;
    }
  }
  else {
LAB_0608b472:
    puVar16 = *(undefined2 **)((int)puVar25 + 4);
  }
  uVar17 = 0;
  iVar20 = 0;
  for (iVar6 = 0; (iVar6 < 0x10 && (iVar22 = *(int *)(iVar24 + 0xb38 + iVar6 * 4), iVar22 != 0));
      iVar6 = iVar6 + 1) {
    if ((iVar22 == iVar13) ||
       ((uVar8 = (uint)*(ushort *)((int)puVar25 + iVar6 * 2 + 0x10), uVar8 == 0 ||
        (uVar9 = (ulonglong)CONCAT24(*(ushort *)(iVar13 + 0xc),uVar8),
        *(ushort *)(iVar13 + 0xc) < uVar8)))) goto LAB_0608b4c4;
    if (puVar16 == (undefined2 *)0x0) {
LAB_0608b4bc:
      uVar8 = (uint)uVar9;
      if ((iVar20 != 0) && (uVar10 = op_ext_l_u(uVar17), uVar10 <= uVar8)) goto LAB_0608b4c4;
    }
    else {
      uVar9 = (ulonglong)CONCAT24(*puVar16,uVar8) & 0x7ffffffff;
      uVar8 = (uint)(uVar9 >> 0x20);
      if (uVar8 < (*(ushort *)(iVar22 + 0x2c) & 7)) goto LAB_0608b4bc;
      if (*(ushort **)(iVar22 + 0x34) != (ushort *)0x0) {
        uVar8 = op_ext_l_u_p(uVar8);
        uVar9 = CONCAT44(uVar8,(int)uVar9);
        if (uVar8 < (**(ushort **)(iVar22 + 0x34) & 7)) goto LAB_0608b4bc;
      }
LAB_0608b4c4:
      iVar22 = iVar20;
      uVar8 = uVar17;
    }
    uVar17 = uVar8;
    iVar20 = iVar22;
  }
  iVar6 = *(int *)(iVar24 + 0xb34);
  if ((iVar13 != iVar6) && (iVar6 != 0)) {
    uVar8 = 1;
    if ((*(uint *)(iVar13 + 8) & 8) == 0) {
      uVar10 = *(ushort *)(iVar6 + 4) - 3;
      if (uVar10 < 0x1f) {
        if ((1 << uVar10 & 0x1bU) == 0) {
          if (uVar10 != 0x1e) goto LAB_0608b592;
          uVar8 = ~*(uint *)(iVar13 + 8) & 1;
        }
      }
      else {
LAB_0608b592:
        uVar8 = 0;
      }
    }
    iVar6 = func_0x0bf83e30(uVar8);
    if (iVar6 != 0) {
      puVar11 = (undefined1 *)((int)puVar25 + 8);
      func_0x0bf83e00(puVar11);
      op_ext_l_u(uVar17);
      uVar14 = 0;
      func_0x0bf83e76(*(undefined1 *)(iVar24 + 0xae1),0,puVar11);
      *(undefined1 *)(iVar24 + 0xae4) = uVar14;
      goto LAB_0608b614;
    }
  }
  if (iVar20 == 0) {
    uVar17 = (uint)*(ushort *)(iVar13 + 0xc);
    iVar20 = iVar13;
  }
  uVar5 = op_ext_l_u_p(uVar17);
  func_0x0bf83eba(iVar13,uVar5,*puVar25);
  puVar11 = (undefined1 *)(iVar24 + 0xae1);
  uVar14 = 0;
  func_0x0bf83e76(*puVar11,0,iVar20 + 0x1c);
  puVar11[3] = uVar14;
LAB_0608b614:
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608b69c @ 0608b69c

/* WARNING: Removing unreachable block (ram,0x0608b6d0) */

void FUN_0608b69c(void)

{
  op_push_rets_rl();
  if (cRam00105b54 == '\0') {
    cRam00105b54 = '\x01';
  }
  FUN_06088a6a();
  do {
  } while( true );
}


// ===== FUN_0608be7e @ 0608be7e

void FUN_0608be7e(int param_1,int param_2)

{
  char cVar1;
  uint6 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 uVar12;
  ulonglong uVar9;
  undefined4 extraout_r1_02;
  uint extraout_r1_03;
  uint extraout_r1_04;
  uint uVar13;
  longlong lVar10;
  undefined8 uVar11;
  int extraout_r1_05;
  int extraout_r1_06;
  int iVar14;
  int iVar15;
  uint *puVar16;
  uint uVar17;
  ushort *puVar18;
  uint uVar19;
  undefined4 *puVar20;
  int iVar21;
  int iVar22;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined1 *puVar23;
  uint *puVar24;
  undefined1 *puVar25;
  
  op_push_rets_rl();
  func_0x0bfb34d8();
  cVar1 = *(char *)(param_1 + 0xd);
  *(char *)(param_1 + 0xd) = cVar1 + -1;
  if (cVar1 == '\x01') {
    FUN_0608adbc(*(undefined4 *)(param_1 + 0x20));
    FUN_0608adbc(param_1);
  }
  puVar3 = (undefined4 *)func_0x0bfb34e2();
  uVar9 = CONCAT44(extraout_r1,puVar3);
  op_pop_pc_rl();
  op_push_rets_rl();
  if (puVar3 != (undefined4 *)0x0) {
    puVar20 = (undefined4 *)0x1134bc;
    uVar12 = extraout_r1;
    if (param_2 == 0) {
      if (*(char *)((int)puVar3 + 9) == '\0') {
        (*pcRam001134bc)(puVar3);
        uVar12 = extraout_r1_01;
      }
    }
    else if (*(char *)((int)puVar3 + 9) == '\0') {
      (*pcRam001134bc)(puVar3);
      uVar12 = extraout_r1_00;
    }
    puVar18 = (ushort *)(puVar3 + 0x12);
    uVar9 = CONCAT44(uVar12,puVar3[0x18]);
    if ((puVar3[0x18] != 0) &&
       (uVar9 = CONCAT44(uVar12,(uint)*(byte *)((int)puVar3 + 5)), *(byte *)((int)puVar3 + 5) != 0))
    {
      (*(code *)*puVar3)();
      if ((puVar3[0xd] == 0) && (*(char *)((int)puVar3 + 9) == '\0')) {
        (*(code *)*puVar20)(puVar3);
      }
      if (((*(int *)(puVar18 + 0x10) != 0) && (*(char *)((int)puVar3 + 9) != '\0')) &&
         (*(char *)((int)puVar18 + 7) != '\0')) {
        uVar2 = CONCAT24(*puVar18,(uint)puVar18[1]);
        if ((uint)*puVar18 < (uint)puVar18[1]) {
          (*(code *)*puVar3)();
          uVar2 = CONCAT24(*puVar18,(uint)puVar18[1]);
        }
        uVar9 = (ulonglong)uVar2;
        if ((uint)(ushort)(uVar2 >> 0x20) < (uint)uVar2) goto LAB_0608bf54;
      }
      (*(code *)*puVar3)();
      iVar4 = (*(code *)*puVar3)();
      uVar9 = CONCAT44(extraout_r1_02,iVar4);
      if (iVar4 != 0) {
        uVar9 = CONCAT44(extraout_r1_02,1);
        *(undefined1 *)((int)puVar3 + 0xd) = 1;
      }
    }
  }
LAB_0608bf54:
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar3 = (undefined4 *)FUN_0608adae((int)(uVar9 >> 0x20) + 0x24);
  uVar13 = extraout_r1_03;
  if (puVar3 != (undefined4 *)0x0) {
    rep_unspec(2,8);
    *puVar3 = 0;
    *(char *)((int)puVar3 + 0xd) = (char)(puVar3 + 9);
    *(short *)(puVar3 + 5) = (short)(uVar9 >> 0x20);
    puVar3[8] = puVar3 + 9;
    *(undefined1 *)(puVar3 + 3) = *(undefined1 *)((int)uVar9 + 5);
    func_0x0bfb3c7a(puVar3 + 1);
    op_pop_pc_rl();
    uVar13 = extraout_r1_04;
  }
  lVar10 = (ulonglong)uVar13 << 0x20;
  op_pop_pc_rl();
  op_push_rets_rl();
  uVar9 = (ulonglong)CONCAT14(bRam00000008,uRam00000018);
  uVar19 = (uint)(bRam00000008 >> 4);
  uVar17 = *(uint *)(uVar13 + 8);
  if ((uVar17 & 0xfe0) != 0) {
    uRam00000024 = *(undefined4 *)(uVar13 + 0x18);
    uRam00000000 = *(ushort *)(uVar13 + 0x16);
    uVar9 = (ulonglong)uRam00000018;
    if (uRam00000018 == 0x100) {
      iVar4 = 1;
      if (*(char *)(uVar13 + 0xc) != '\0') {
        iVar4 = 2;
      }
      uVar5 = (uint)(*(ushort *)(uVar13 + 0x12) >> iVar4);
      uVar9 = CONCAT44(uVar5 / uVar19,uVar5);
    }
    iRam00000020 = (int)(uVar9 >> 0x20);
    op_pop_pc_rl();
    uRam0000001c = uVar17;
  }
  uVar5 = uRam0000001c;
  if ((int)uVar9 == 0x100) {
    iVar21 = (uint)uRam00000000 + iRam00000014;
    iVar22 = 32000000;
    uVar11 = op_mul_u_prr(iRam00000020,32000000);
    iVar7 = iRam00000020;
    iVar6 = func_0x0bfa4ee2((int)uVar11,iVar21);
    iVar14 = (int)lVar10;
    iVar4 = *(int *)(iVar14 + 0x24);
    iVar15 = (int)((ulonglong)lVar10 >> 0x20);
    *(int *)(iVar15 + 0x18) = iVar6 + iVar4;
    iVar6 = 1;
    if (*(char *)(iVar15 + 0xc) != '\0') {
      iVar6 = 2;
    }
    iVar7 = (*(ushort *)(iVar15 + 0x12) >> iVar6) / uVar19 + iVar7;
    *(int *)(iVar14 + 0x20) = iVar7;
    *(int *)(iVar14 + 0x20) = iVar7 - iVar21;
    *(int *)(iVar14 + 0x24) = iVar4 + iVar22;
    puVar8 = (uint *)(iVar14 + 0x1c);
    uVar5 = *puVar8;
    *(uint *)(iVar15 + 8) = uVar17 | uVar5;
  }
  else {
    puVar8 = (uint *)0x1c;
    *(uint *)(uVar13 + 8) = uRam0000001c | uVar17;
    *(undefined4 *)(uVar13 + 0x18) = uRam00000024;
  }
  uVar5 = uVar5 & 0x31;
  uVar9 = (ulonglong)*(ushort *)lVar10;
  *(ushort *)((int)((ulonglong)lVar10 >> 0x20) + 0x16) = *(ushort *)lVar10;
  *puVar8 = uVar5;
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar24 = (uint *)((int)in_sp + -0x20);
  puVar23 = (undefined1 *)((int)in_sp + -0x20);
  if (uVar5 == 0) {
    iVar7 = 0;
    iVar4 = 0;
    puVar16 = puVar8;
  }
  else {
    uVar9 = ZEXT48((undefined1 *)((int)in_sp + -0x20));
    iVar7 = func_0x0bfb3cc8(uVar5);
    puVar16 = puVar8;
    puVar8 = (uint *)func_0x0bfb3cda();
    puVar24 = (uint *)puVar23;
    iVar4 = extraout_r1_05;
  }
  if (puVar16 != (uint *)0x0) {
    puVar24[iVar7] = (uint)puVar16;
    iVar7 = iVar7 + 1;
    puVar8 = puVar24;
  }
  for (iVar6 = 0; iVar6 < iVar7; iVar6 = iVar6 + 1) {
    iVar4 = *(int *)((int)puVar24 + iVar6 * 4);
    iVar14 = *(int *)(iVar4 + 0x50);
    puVar8 = (uint *)0x0;
    if (iVar14 != 0) {
      uVar9 = (ulonglong)*(byte *)(iVar14 + 10);
      if ((*(byte *)(iVar14 + 10) != 0) && (*(int *)(iVar4 + 0x54) != 0)) {
        iVar14 = *(int *)(iVar4 + 0x54);
      }
      puVar8 = (uint *)FUN_060878c8(iVar14 + 0x20);
      iVar4 = extraout_r1_06;
    }
  }
  puVar25 = (undefined1 *)((int)puVar24 + 0x20);
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar7 = (int)uVar9;
  func_0x0bfb34d8();
  if (iVar7 != 0) {
    FUN_0608bf8e(puVar8);
  }
  func_0x0bfb2d82(iVar4);
  iVar4 = func_0x0bfb3c80();
  if (iVar4 != 0) {
    FUN_0608c056(0);
  }
  func_0x0bfb34e2();
  op_pop_pc_rl();
  *(undefined4 *)(puVar25 + -4) = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  FUN_0608c0b2(1);
}


// ===== FUN_0608beb4 @ 0608beb4

void FUN_0608beb4(int param_1)

{
  uint6 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  ulonglong in_r0_r1;
  undefined4 uVar11;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  uint extraout_r1_02;
  uint extraout_r1_03;
  uint uVar12;
  longlong lVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  int extraout_r1_04;
  int extraout_r1_05;
  int iVar13;
  int iVar14;
  uint *puVar15;
  uint uVar16;
  ushort *puVar17;
  uint uVar18;
  undefined4 *puVar19;
  int iVar20;
  int iVar21;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined1 *puVar22;
  uint *puVar23;
  undefined1 *puVar24;
  
  op_push_rets_rl();
  puVar3 = (undefined4 *)in_r0_r1;
  if (puVar3 != (undefined4 *)0x0) {
    uVar11 = (undefined4)(in_r0_r1 >> 0x20);
    puVar19 = (undefined4 *)0x1134bc;
    if (param_1 == 0) {
      if (*(char *)((int)puVar3 + 9) == '\0') {
        (*pcRam001134bc)();
        uVar11 = extraout_r1_00;
      }
    }
    else if (*(char *)((int)puVar3 + 9) == '\0') {
      (*pcRam001134bc)();
      uVar11 = extraout_r1;
    }
    puVar17 = (ushort *)(puVar3 + 0x12);
    in_r0_r1 = CONCAT44(uVar11,puVar3[0x18]);
    if ((puVar3[0x18] != 0) &&
       (in_r0_r1 = CONCAT44(uVar11,(uint)*(byte *)((int)puVar3 + 5)),
       *(byte *)((int)puVar3 + 5) != 0)) {
      (*(code *)*puVar3)();
      if ((puVar3[0xd] == 0) && (*(char *)((int)puVar3 + 9) == '\0')) {
        (*(code *)*puVar19)(puVar3);
      }
      if (((*(int *)(puVar17 + 0x10) != 0) && (*(char *)((int)puVar3 + 9) != '\0')) &&
         (*(char *)((int)puVar17 + 7) != '\0')) {
        uVar1 = CONCAT24(*puVar17,(uint)puVar17[1]);
        if ((uint)*puVar17 < (uint)puVar17[1]) {
          (*(code *)*puVar3)();
          uVar1 = CONCAT24(*puVar17,(uint)puVar17[1]);
        }
        in_r0_r1 = (ulonglong)uVar1;
        if ((uint)(ushort)(uVar1 >> 0x20) < (uint)uVar1) goto LAB_0608bf54;
      }
      (*(code *)*puVar3)();
      iVar2 = (*(code *)*puVar3)();
      in_r0_r1 = CONCAT44(extraout_r1_01,iVar2);
      if (iVar2 != 0) {
        in_r0_r1 = CONCAT44(extraout_r1_01,1);
        *(undefined1 *)((int)puVar3 + 0xd) = 1;
      }
    }
  }
LAB_0608bf54:
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar3 = (undefined4 *)FUN_0608adae((int)(in_r0_r1 >> 0x20) + 0x24);
  uVar12 = extraout_r1_02;
  if (puVar3 != (undefined4 *)0x0) {
    rep_unspec(2,8);
    *puVar3 = 0;
    *(char *)((int)puVar3 + 0xd) = (char)(puVar3 + 9);
    *(short *)(puVar3 + 5) = (short)(in_r0_r1 >> 0x20);
    puVar3[8] = puVar3 + 9;
    *(undefined1 *)(puVar3 + 3) = *(undefined1 *)((int)in_r0_r1 + 5);
    func_0x0bfb3c7a(puVar3 + 1);
    op_pop_pc_rl();
    uVar12 = extraout_r1_03;
  }
  lVar8 = (ulonglong)uVar12 << 0x20;
  op_pop_pc_rl();
  op_push_rets_rl();
  uVar9 = (ulonglong)CONCAT14(bRam00000008,uRam00000018);
  uVar18 = (uint)(bRam00000008 >> 4);
  uVar16 = *(uint *)(uVar12 + 8);
  if ((uVar16 & 0xfe0) != 0) {
    uRam00000024 = *(undefined4 *)(uVar12 + 0x18);
    uRam00000000 = *(ushort *)(uVar12 + 0x16);
    uVar9 = (ulonglong)uRam00000018;
    if (uRam00000018 == 0x100) {
      iVar2 = 1;
      if (*(char *)(uVar12 + 0xc) != '\0') {
        iVar2 = 2;
      }
      uVar4 = (uint)(*(ushort *)(uVar12 + 0x12) >> iVar2);
      uVar9 = CONCAT44(uVar4 / uVar18,uVar4);
    }
    iRam00000020 = (int)(uVar9 >> 0x20);
    op_pop_pc_rl();
    uRam0000001c = uVar16;
  }
  uVar4 = uRam0000001c;
  if ((int)uVar9 == 0x100) {
    iVar20 = (uint)uRam00000000 + iRam00000014;
    iVar21 = 32000000;
    uVar10 = op_mul_u_prr(iRam00000020,32000000);
    iVar6 = iRam00000020;
    iVar5 = func_0x0bfa4ee2((int)uVar10,iVar20);
    iVar13 = (int)lVar8;
    iVar2 = *(int *)(iVar13 + 0x24);
    iVar14 = (int)((ulonglong)lVar8 >> 0x20);
    *(int *)(iVar14 + 0x18) = iVar5 + iVar2;
    iVar5 = 1;
    if (*(char *)(iVar14 + 0xc) != '\0') {
      iVar5 = 2;
    }
    iVar6 = (*(ushort *)(iVar14 + 0x12) >> iVar5) / uVar18 + iVar6;
    *(int *)(iVar13 + 0x20) = iVar6;
    *(int *)(iVar13 + 0x20) = iVar6 - iVar20;
    *(int *)(iVar13 + 0x24) = iVar2 + iVar21;
    puVar7 = (uint *)(iVar13 + 0x1c);
    uVar4 = *puVar7;
    *(uint *)(iVar14 + 8) = uVar16 | uVar4;
  }
  else {
    puVar7 = (uint *)0x1c;
    *(uint *)(uVar12 + 8) = uRam0000001c | uVar16;
    *(undefined4 *)(uVar12 + 0x18) = uRam00000024;
  }
  uVar4 = uVar4 & 0x31;
  uVar9 = (ulonglong)*(ushort *)lVar8;
  *(ushort *)((int)((ulonglong)lVar8 >> 0x20) + 0x16) = *(ushort *)lVar8;
  *puVar7 = uVar4;
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar23 = (uint *)((int)in_sp + -0x20);
  puVar22 = (undefined1 *)((int)in_sp + -0x20);
  if (uVar4 == 0) {
    iVar6 = 0;
    iVar2 = 0;
    puVar15 = puVar7;
  }
  else {
    uVar9 = ZEXT48((undefined1 *)((int)in_sp + -0x20));
    iVar6 = func_0x0bfb3cc8(uVar4);
    puVar15 = puVar7;
    puVar7 = (uint *)func_0x0bfb3cda();
    puVar23 = (uint *)puVar22;
    iVar2 = extraout_r1_04;
  }
  if (puVar15 != (uint *)0x0) {
    puVar23[iVar6] = (uint)puVar15;
    iVar6 = iVar6 + 1;
    puVar7 = puVar23;
  }
  for (iVar5 = 0; iVar5 < iVar6; iVar5 = iVar5 + 1) {
    iVar2 = *(int *)((int)puVar23 + iVar5 * 4);
    iVar13 = *(int *)(iVar2 + 0x50);
    puVar7 = (uint *)0x0;
    if (iVar13 != 0) {
      uVar9 = (ulonglong)*(byte *)(iVar13 + 10);
      if ((*(byte *)(iVar13 + 10) != 0) && (*(int *)(iVar2 + 0x54) != 0)) {
        iVar13 = *(int *)(iVar2 + 0x54);
      }
      puVar7 = (uint *)FUN_060878c8(iVar13 + 0x20);
      iVar2 = extraout_r1_05;
    }
  }
  puVar24 = (undefined1 *)((int)puVar23 + 0x20);
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar6 = (int)uVar9;
  func_0x0bfb34d8();
  if (iVar6 != 0) {
    FUN_0608bf8e(puVar7);
  }
  func_0x0bfb2d82(iVar2);
  iVar2 = func_0x0bfb3c80();
  if (iVar2 != 0) {
    FUN_0608c056(0);
  }
  func_0x0bfb34e2();
  op_pop_pc_rl();
  *(undefined4 *)(puVar24 + -4) = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  FUN_0608c0b2(1);
}


// ===== FUN_0608bf56 @ 0608bf56

void FUN_0608bf56(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  undefined8 in_r0_r1;
  uint extraout_r1;
  uint extraout_r1_00;
  uint uVar10;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  int extraout_r1_01;
  int extraout_r1_02;
  int iVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined1 *puVar18;
  uint *puVar19;
  undefined1 *puVar20;
  
  op_push_rets_rl();
  puVar1 = (undefined4 *)FUN_0608adae((int)((ulonglong)in_r0_r1 >> 0x20) + 0x24);
  uVar10 = extraout_r1;
  if (puVar1 != (undefined4 *)0x0) {
    rep_unspec(2,8);
    *puVar1 = 0;
    *(char *)((int)puVar1 + 0xd) = (char)(puVar1 + 9);
    *(short *)(puVar1 + 5) = (short)((ulonglong)in_r0_r1 >> 0x20);
    puVar1[8] = puVar1 + 9;
    *(undefined1 *)(puVar1 + 3) = *(undefined1 *)((int)in_r0_r1 + 5);
    func_0x0bfb3c7a(puVar1 + 1);
    op_pop_pc_rl();
    uVar10 = extraout_r1_00;
  }
  lVar7 = (ulonglong)uVar10 << 0x20;
  op_pop_pc_rl();
  op_push_rets_rl();
  uVar8 = (ulonglong)CONCAT14(bRam00000008,uRam00000018);
  uVar15 = (uint)(bRam00000008 >> 4);
  uVar14 = *(uint *)(uVar10 + 8);
  if ((uVar14 & 0xfe0) != 0) {
    uRam00000024 = *(undefined4 *)(uVar10 + 0x18);
    uRam00000000 = *(ushort *)(uVar10 + 0x16);
    uVar8 = (ulonglong)uRam00000018;
    if (uRam00000018 == 0x100) {
      iVar6 = 1;
      if (*(char *)(uVar10 + 0xc) != '\0') {
        iVar6 = 2;
      }
      uVar2 = (uint)(*(ushort *)(uVar10 + 0x12) >> iVar6);
      uVar8 = CONCAT44(uVar2 / uVar15,uVar2);
    }
    iRam00000020 = (int)(uVar8 >> 0x20);
    op_pop_pc_rl();
    uRam0000001c = uVar14;
  }
  uVar2 = uRam0000001c;
  if ((int)uVar8 == 0x100) {
    iVar16 = (uint)uRam00000000 + iRam00000014;
    iVar17 = 32000000;
    uVar9 = op_mul_u_prr(iRam00000020,32000000);
    iVar4 = iRam00000020;
    iVar3 = func_0x0bfa4ee2((int)uVar9,iVar16);
    iVar11 = (int)lVar7;
    iVar6 = *(int *)(iVar11 + 0x24);
    iVar12 = (int)((ulonglong)lVar7 >> 0x20);
    *(int *)(iVar12 + 0x18) = iVar3 + iVar6;
    iVar3 = 1;
    if (*(char *)(iVar12 + 0xc) != '\0') {
      iVar3 = 2;
    }
    iVar4 = (*(ushort *)(iVar12 + 0x12) >> iVar3) / uVar15 + iVar4;
    *(int *)(iVar11 + 0x20) = iVar4;
    *(int *)(iVar11 + 0x20) = iVar4 - iVar16;
    *(int *)(iVar11 + 0x24) = iVar6 + iVar17;
    puVar5 = (uint *)(iVar11 + 0x1c);
    uVar2 = *puVar5;
    *(uint *)(iVar12 + 8) = uVar14 | uVar2;
  }
  else {
    puVar5 = (uint *)0x1c;
    *(uint *)(uVar10 + 8) = uRam0000001c | uVar14;
    *(undefined4 *)(uVar10 + 0x18) = uRam00000024;
  }
  uVar2 = uVar2 & 0x31;
  uVar8 = (ulonglong)*(ushort *)lVar7;
  *(ushort *)((int)((ulonglong)lVar7 >> 0x20) + 0x16) = *(ushort *)lVar7;
  *puVar5 = uVar2;
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar19 = (uint *)((int)in_sp + -0x20);
  puVar18 = (undefined1 *)((int)in_sp + -0x20);
  if (uVar2 == 0) {
    iVar4 = 0;
    iVar6 = 0;
    puVar13 = puVar5;
  }
  else {
    uVar8 = ZEXT48((undefined1 *)((int)in_sp + -0x20));
    iVar4 = func_0x0bfb3cc8(uVar2);
    puVar13 = puVar5;
    puVar5 = (uint *)func_0x0bfb3cda();
    puVar19 = (uint *)puVar18;
    iVar6 = extraout_r1_01;
  }
  if (puVar13 != (uint *)0x0) {
    puVar19[iVar4] = (uint)puVar13;
    iVar4 = iVar4 + 1;
    puVar5 = puVar19;
  }
  for (iVar3 = 0; iVar3 < iVar4; iVar3 = iVar3 + 1) {
    iVar6 = *(int *)((int)puVar19 + iVar3 * 4);
    iVar11 = *(int *)(iVar6 + 0x50);
    puVar5 = (uint *)0x0;
    if (iVar11 != 0) {
      uVar8 = (ulonglong)*(byte *)(iVar11 + 10);
      if ((*(byte *)(iVar11 + 10) != 0) && (*(int *)(iVar6 + 0x54) != 0)) {
        iVar11 = *(int *)(iVar6 + 0x54);
      }
      puVar5 = (uint *)FUN_060878c8(iVar11 + 0x20);
      iVar6 = extraout_r1_02;
    }
  }
  puVar20 = (undefined1 *)((int)puVar19 + 0x20);
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar4 = (int)uVar8;
  func_0x0bfb34d8();
  if (iVar4 != 0) {
    FUN_0608bf8e(puVar5);
  }
  func_0x0bfb2d82(iVar6);
  iVar6 = func_0x0bfb3c80();
  if (iVar6 != 0) {
    FUN_0608c056(0);
  }
  func_0x0bfb34e2();
  op_pop_pc_rl();
  *(undefined4 *)(puVar20 + -4) = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  FUN_0608c0b2(1);
}


// ===== FUN_0608bf8e @ 0608bf8e

void FUN_0608bf8e(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  undefined8 in_r0_r1;
  ulonglong uVar6;
  undefined8 uVar7;
  int extraout_r1;
  int extraout_r1_00;
  ushort *puVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined1 *puVar16;
  uint *puVar17;
  undefined1 *puVar18;
  
  op_push_rets_rl();
  puVar8 = (ushort *)in_r0_r1;
  uVar1 = *(uint *)(puVar8 + 0xc);
  uVar6 = (ulonglong)CONCAT14((byte)puVar8[4],uVar1);
  uVar13 = (uint)(byte)((byte)puVar8[4] >> 4);
  iVar5 = (int)((ulonglong)in_r0_r1 >> 0x20);
  uVar12 = *(uint *)(iVar5 + 8);
  if ((uVar12 & 0xfe0) != 0) {
    *(undefined4 *)(puVar8 + 0x12) = *(undefined4 *)(iVar5 + 0x18);
    *puVar8 = *(ushort *)(iVar5 + 0x16);
    uVar6 = (ulonglong)uVar1;
    if (uVar1 == 0x100) {
      iVar3 = 1;
      if (*(char *)(iVar5 + 0xc) != '\0') {
        iVar3 = 2;
      }
      uVar1 = (uint)(*(ushort *)(iVar5 + 0x12) >> iVar3);
      uVar6 = CONCAT44(uVar1 / uVar13,uVar1);
    }
    *(int *)(puVar8 + 0x10) = (int)(uVar6 >> 0x20);
    *(uint *)(puVar8 + 0xe) = uVar12;
    op_pop_pc_rl();
  }
  if ((int)uVar6 == 0x100) {
    iVar3 = *(int *)(puVar8 + 0x10);
    iVar14 = (uint)*puVar8 + *(int *)(puVar8 + 10);
    iVar15 = 32000000;
    uVar7 = op_mul_u_prr(iVar3,32000000);
    iVar2 = func_0x0bfa4ee2((int)uVar7,iVar14);
    iVar9 = (int)in_r0_r1;
    iVar5 = *(int *)(iVar9 + 0x24);
    iVar10 = (int)((ulonglong)in_r0_r1 >> 0x20);
    *(int *)(iVar10 + 0x18) = iVar2 + iVar5;
    iVar2 = 1;
    if (*(char *)(iVar10 + 0xc) != '\0') {
      iVar2 = 2;
    }
    iVar3 = (*(ushort *)(iVar10 + 0x12) >> iVar2) / uVar13 + iVar3;
    *(int *)(iVar9 + 0x20) = iVar3;
    *(int *)(iVar9 + 0x20) = iVar3 - iVar14;
    *(int *)(iVar9 + 0x24) = iVar5 + iVar15;
    puVar4 = (uint *)(iVar9 + 0x1c);
    uVar1 = *puVar4;
    *(uint *)(iVar10 + 8) = uVar12 | uVar1;
  }
  else {
    uVar1 = *(uint *)(puVar8 + 0xe);
    puVar4 = (uint *)(puVar8 + 0xe);
    *(uint *)(iVar5 + 8) = uVar1 | uVar12;
    *(undefined4 *)(iVar5 + 0x18) = *(undefined4 *)(puVar8 + 0x12);
  }
  uVar1 = uVar1 & 0x31;
  uVar6 = (ulonglong)*(ushort *)in_r0_r1;
  *(ushort *)((int)((ulonglong)in_r0_r1 >> 0x20) + 0x16) = *(ushort *)in_r0_r1;
  *puVar4 = uVar1;
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar17 = (uint *)((int)in_sp + -0x20);
  puVar16 = (undefined1 *)((int)in_sp + -0x20);
  if (uVar1 == 0) {
    iVar3 = 0;
    iVar5 = 0;
    puVar11 = puVar4;
  }
  else {
    uVar6 = ZEXT48((undefined1 *)((int)in_sp + -0x20));
    iVar3 = func_0x0bfb3cc8(uVar1);
    puVar11 = puVar4;
    puVar4 = (uint *)func_0x0bfb3cda();
    puVar17 = (uint *)puVar16;
    iVar5 = extraout_r1;
  }
  if (puVar11 != (uint *)0x0) {
    puVar17[iVar3] = (uint)puVar11;
    iVar3 = iVar3 + 1;
    puVar4 = puVar17;
  }
  for (iVar2 = 0; iVar2 < iVar3; iVar2 = iVar2 + 1) {
    iVar5 = *(int *)((int)puVar17 + iVar2 * 4);
    iVar9 = *(int *)(iVar5 + 0x50);
    puVar4 = (uint *)0x0;
    if (iVar9 != 0) {
      uVar6 = (ulonglong)*(byte *)(iVar9 + 10);
      if ((*(byte *)(iVar9 + 10) != 0) && (*(int *)(iVar5 + 0x54) != 0)) {
        iVar9 = *(int *)(iVar5 + 0x54);
      }
      puVar4 = (uint *)FUN_060878c8(iVar9 + 0x20);
      iVar5 = extraout_r1_00;
    }
  }
  puVar18 = (undefined1 *)((int)puVar17 + 0x20);
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar3 = (int)uVar6;
  func_0x0bfb34d8();
  if (iVar3 != 0) {
    FUN_0608bf8e(puVar4);
  }
  func_0x0bfb2d82(iVar5);
  iVar5 = func_0x0bfb3c80();
  if (iVar5 != 0) {
    FUN_0608c056(0);
  }
  func_0x0bfb34e2();
  op_pop_pc_rl();
  *(undefined4 *)(puVar18 + -4) = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  FUN_0608c0b2(1);
}


// ===== FUN_0608c056 @ 0608c056

void FUN_0608c056(undefined1 *param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  undefined1 auStack_20 [32];
  
  op_push_rets_rl();
  puVar9 = auStack_20;
  puVar8 = auStack_20;
  puVar5 = auStack_20;
  if (param_2 == 0) {
    iVar2 = 0;
    uVar4 = 0;
    puVar6 = param_1;
  }
  else {
    iVar2 = func_0x0bfb3cc8(param_2,auStack_20);
    puVar6 = param_1;
    uVar11 = func_0x0bfb3cda();
    param_1 = (undefined1 *)((ulonglong)uVar11 >> 0x20);
    uVar4 = (undefined4)uVar11;
    param_3 = (uint)puVar5;
    puVar9 = puVar8;
  }
  if (puVar6 != (undefined1 *)0x0) {
    *(undefined1 **)(puVar9 + iVar2 * 4) = puVar6;
    iVar2 = iVar2 + 1;
    param_1 = puVar9;
  }
  uVar12 = CONCAT44(param_1,uVar4);
  for (iVar7 = 0; iVar7 < iVar2; iVar7 = iVar7 + 1) {
    uVar1 = *(uint *)(puVar9 + iVar7 * 4);
    iVar3 = *(int *)(uVar1 + 0x50);
    uVar12 = (ulonglong)uVar1;
    if (iVar3 != 0) {
      param_3 = (uint)*(byte *)(iVar3 + 10);
      if ((param_3 != 0) && (*(int *)(uVar1 + 0x54) != 0)) {
        iVar3 = *(int *)(uVar1 + 0x54);
      }
      uVar12 = FUN_060878c8(iVar3 + 0x20);
    }
  }
  puVar10 = puVar9 + 0x20;
  op_pop_pc_rl();
  op_push_rets_rl();
  uVar4 = *(undefined4 *)((int)(uVar12 >> 0x20) + 0x2c);
  func_0x0bfb34d8();
  if (param_3 != 0) {
    FUN_0608bf8e((int)(uVar12 >> 0x20),(int)uVar12);
  }
  iVar7 = (int)(uVar12 >> 0x20);
  func_0x0bfb2d82((int)uVar12,uVar4);
  iVar2 = func_0x0bfb3c80();
  if (iVar2 != 0) {
    FUN_0608c056(0,*(undefined4 *)(iVar7 + 0x28));
  }
  func_0x0bfb34e2();
  op_pop_pc_rl();
  *(undefined4 *)(puVar10 + -4) = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  FUN_0608c0b2(1);
}


// ===== FUN_0608c0b2 @ 0608c0b2

void FUN_0608c0b2(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  
  op_push_rets_rl();
  uVar2 = *(undefined4 *)(param_1 + 0x2c);
  func_0x0bfb34d8();
  if (param_3 != 0) {
    FUN_0608bf8e(param_1,param_2);
  }
  func_0x0bfb2d82(param_2,uVar2);
  iVar1 = func_0x0bfb3c80();
  if (iVar1 != 0) {
    FUN_0608c056(0,*(undefined4 *)(param_1 + 0x28));
  }
  func_0x0bfb34e2();
  op_pop_pc_rl();
  *(undefined4 *)((int)in_sp + -4) = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  FUN_0608c0b2(1);
}


// ===== thunk_FUN_0608c0b2 @ 0608c0ec

void thunk_FUN_0608c0b2(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_0608c0b2(1);
}


// ===== FUN_0608c0f4 @ 0608c0f4

void FUN_0608c0f4(int *param_1)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int extraout_r1;
  undefined8 uVar5;
  int extraout_r1_00;
  int extraout_r1_01;
  undefined1 *puVar6;
  int extraout_r1_02;
  uint uVar7;
  ushort *puVar8;
  undefined1 uVar9;
  int iVar10;
  
  op_push_rets_rl();
  puVar8 = *(ushort **)(param_1[6] + 0x18);
  func_0x0bfb34d8();
  iVar2 = func_0x0bfb3e40(param_1);
  if (iVar2 == 0) {
    iVar2 = *param_1;
    if ((puVar8 != (ushort *)0x0) && (uVar7 = *(uint *)(iVar2 + 8), (uVar7 & 0x1000) == 0)) {
      if ((uVar7 & 1) != 0) {
        iVar3 = func_0x0bfb3494(*(undefined4 *)(*(int *)(*(int *)(puVar8 + 0x14) + 0x14) + 0x18),
                                0x20009,0);
        if (iVar3 != 0) {
          func_0x0bfb34e2();
          iVar2 = extraout_r1;
          goto LAB_0608c1cc;
        }
        uVar7 = *(uint *)(iVar2 + 8);
      }
      if ((uVar7 & 8) != 0) {
        if ((uVar7 & 0x40) != 0) {
          uVar5 = op_mul_u_prr(*(undefined4 *)(puVar8 + 0x10),32000000);
          func_0x0bfa4ee2((int)uVar5,(int)((uint)*puVar8 + *(int *)(puVar8 + 10)) >> 0x1f);
          uVar7 = uVar7 | 0x11;
          *(uint *)(iVar2 + 8) = uVar7;
        }
        if ((uVar7 & 0x80) != 0) {
          uVar7 = uVar7 | 0x21;
          *(uint *)(iVar2 + 8) = uVar7;
        }
        *(uint *)(iVar2 + 8) = uVar7 & 0xffffff3f;
        puVar1 = (ushort *)(uVar7 & 0x31);
        while (puVar1 != (ushort *)0x0) {
          *(ulonglong *)(puVar8 + 0x10) = (ulonglong)*(uint *)(iVar2 + 0x18) << 0x20;
          *puVar8 = *(ushort *)(iVar2 + 0x16);
          *(ulonglong *)(puVar8 + 0x10) = (ulonglong)*(uint *)(iVar2 + 0x18) << 0x20;
          *(uint *)(puVar8 + 0xe) = uVar7 & 0xffffff3f;
          puVar8 = *(ushort **)(puVar8 + 0x18);
          puVar1 = puVar8;
        }
      }
    }
    func_0x0bfb3e4e(iVar2);
  }
  func_0x0bfb34e2();
  iVar2 = extraout_r1_00;
LAB_0608c1cc:
  op_pop_pc_rl();
  op_push_rets_rl();
  func_0x0bfb34d8();
  *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | 0xd80;
  func_0x0bfb3ed6(iVar2);
  iVar4 = func_0x0bfb34e2();
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar2 = *(int *)(iVar4 + 0x14);
  iVar3 = extraout_r1_01;
  if (*(char *)(iVar2 + 0x10) != '\0') {
    iVar3 = *(int *)(iVar2 + 0x40);
    if (iVar3 != 0) {
      iVar10 = iVar3 + 0x180;
      uVar9 = 0;
      FUN_0608718a((uint)*(ushort *)(iVar2 + 0x32) * 0x10 + iVar3 + 0x1b8);
      FUN_06088a6a();
      iVar4 = iVar3 + 0xa4;
      iVar2 = func_0x0bf8d53c(iVar3);
      if (iVar2 == 0) {
        func_0x0bf8e0ee(iVar3);
        func_0x0bf8e732(iVar3);
        puVar6 = (undefined1 *)(iVar10 + 0x99);
        for (iVar2 = 0; iVar2 != 0x14; iVar2 = iVar2 + 5) {
          if (*(char *)(iVar4 + 0xb5 + iVar2) != '\0') {
            puVar6[-0x65] = 1;
            *puVar6 = uVar9;
          }
          puVar6 = puVar6 + 1;
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_06088ab8();
    }
    iVar3 = *(int *)((uint)*(byte *)(iVar2 + 0x13) * 4 + 0x106380);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x180) != 0)) {
      FUN_06088a6a();
                    /* WARNING: Subroutine does not return */
      FUN_06088ab8();
    }
    iVar3 = 0x106380;
    *(char *)(iVar2 + 0x10) = '\0';
  }
  do {
    op_pop_pc_rl();
    *(int *)(iVar3 + 0xc) = iVar4;
    FUN_0608c1d0();
    iVar3 = extraout_r1_02;
  } while( true );
}


// ===== FUN_0608ca3a @ 0608ca3a

void FUN_0608ca3a(int param_1)

{
  code *pcVar1;
  ushort uVar2;
  char cVar3;
  byte bVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int extraout_r1;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  uint *puVar12;
  undefined4 *puVar13;
  undefined2 *puVar14;
  int iVar15;
  int *piVar16;
  uint *puVar17;
  undefined4 *puVar19;
  ulonglong uVar18;
  int iVar20;
  uint *puVar21;
  undefined4 *puVar22;
  uint uVar23;
  uint uVar24;
  undefined4 *puVar25;
  undefined2 *puVar26;
  BADSPACEBASE *in_sp;
  undefined1 *puVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  undefined1 *puVar30;
  undefined1 *puVar31;
  undefined1 *puVar32;
  int *piVar33;
  undefined8 uVar34;
  undefined1 auStack_84 [128];
  
  puVar28 = auStack_84 + 0x80;
  puVar27 = auStack_84 + 0x80;
  iVar15 = *(int *)(*(int *)(param_1 + 0x30) + 0x50);
  if (iVar15 != 0) {
    FUN_060878c8(iVar15 + 0x20);
    puVar28 = puVar27 + 4;
  }
  puVar11 = (uint *)0x5;
  piVar5 = (int *)func_0x06087aac(0x605fdef,2);
  puVar29 = puVar28 + 4;
  op_push_rets_rl();
  func_0x0bfb34d8();
  iVar15 = 0;
  piVar16 = piVar5;
  while (piVar16 = (int *)*piVar16, piVar16 != piVar5) {
    iVar15 = iVar15 + 1;
  }
  func_0x0bfb34e2();
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar19 = (undefined4 *)(iVar15 + 0x10);
  if (*(byte *)(iVar15 + 0x1e) < 10) {
    *(byte *)(iVar15 + 0x1e) = *(byte *)(iVar15 + 0x1e) + 1;
    op_pop_pc_rl();
  }
  puVar12 = puVar11;
  iVar7 = extraout_r1;
  iVar15 = func_0x0bfb4078(*puVar19,(uint)*(byte *)(iVar15 + 0x1f) * (int)puVar11);
  uVar34 = func_0x0bf917a8(puVar19[2]);
  if (iVar15 != 0) {
    uVar23 = (uint)bRam00106a38;
    uVar24 = (uint)*(byte *)((int)puVar19 + 0xf);
    if (uVar24 == uVar23) {
      puVar11 = (uint *)(uVar24 * (int)puVar12);
      func_0x05f9ac62(*(undefined4 *)(iVar15 + 0x20),iVar7);
      uVar24 = (uint)*(byte *)((int)puVar19 + 0xf);
    }
    else if (cRam00106a3a == '\0') {
      puVar26 = *(undefined2 **)(iVar15 + 0x20);
      puVar11 = (uint *)0x0;
      for (iVar8 = 0; iVar8 < (int)((uint)puVar12 / 2); iVar8 = iVar8 + 1) {
        puVar14 = puVar26;
        puVar17 = puVar11;
        for (uVar9 = uVar24; uVar9 != 0; uVar9 = uVar9 - 1) {
          *puVar14 = *(undefined2 *)(iVar7 + ((uint)*(byte *)(puVar19 + 0x11) + (int)puVar17) * 2);
          puVar14 = puVar14 + 1;
          puVar17 = (uint *)((int)puVar17 + 1);
        }
        puVar11 = (uint *)((int)puVar11 + uVar23);
        puVar26 = puVar26 + uVar24;
      }
    }
    else {
      puVar25 = *(undefined4 **)(iVar15 + 0x20);
      puVar11 = (uint *)0x0;
      for (iVar8 = 0; iVar8 < (int)((uint)puVar12 / 4); iVar8 = iVar8 + 1) {
        puVar13 = puVar25;
        puVar17 = puVar11;
        for (uVar9 = uVar24; uVar9 != 0; uVar9 = uVar9 - 1) {
          *puVar13 = *(undefined4 *)(iVar7 + ((uint)*(byte *)(puVar19 + 0x11) + (int)puVar17) * 4);
          puVar13 = puVar13 + 1;
          puVar17 = (uint *)((int)puVar17 + 1);
        }
        puVar11 = (uint *)((int)puVar11 + uVar23);
        puVar25 = puVar25 + uVar24;
      }
    }
    *(short *)(iVar15 + 0x12) = (short)uVar24 * (short)puVar12;
    *(undefined4 *)(iVar15 + 8) = 0xf80;
    uVar6 = FUN_06088798();
    *(undefined4 *)(iVar15 + 0x18) = uVar6;
    uVar34 = func_0x0bfb4088(*puVar19,iVar15);
  }
  iVar7 = (int)((ulonglong)uVar34 >> 0x20);
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar31 = puVar29 + -4;
  puVar30 = puVar29 + -4;
  iVar15 = 0;
  puVar19 = (undefined4 *)(puVar29 + -4);
  if (iVar7 == 0) goto LAB_0608cd18;
  if (*(char *)(iVar7 + 0x1c) == '\0') {
    *(undefined1 *)(iVar7 + 0x1c) = 1;
  }
  iVar15 = 0;
  puVar19 = (undefined4 *)(puVar29 + -4);
  if (*(char *)(iVar7 + 0x1a) == '\0') goto LAB_0608cd18;
  bVar4 = *(byte *)(iVar7 + 0x1d) >> 4;
  uVar18 = (ulonglong)CONCAT14(bVar4,iVar7 + 0x18);
  puVar12 = puVar11;
  puVar17 = puVar11;
  puVar19 = (undefined4 *)(puVar29 + -4);
  if (bVar4 == 1) {
    if (*(char *)(iVar7 + 0x1f) == '\x01') {
      puVar12 = (uint *)op_ext_l_u(puVar11);
      func_0x0bfc8136((int)uVar34);
      puVar31 = puVar30;
    }
    else {
      puVar12 = (uint *)op_ext_l_u(puVar11);
      func_0x0bfc817c((int)uVar34);
    }
    puVar17 = (uint *)((int)puVar11 >> 1);
    puVar19 = (undefined4 *)puVar31;
  }
  iVar15 = (int)((ulonglong)uVar34 >> 0x20);
  iVar7 = (int)uVar18;
  if (*(int *)(iVar7 + 0x3c) == 0) {
    iVar8 = 4;
    if (*(char *)(iVar7 + 7) == '\0') {
      iVar8 = 2;
    }
    iVar8 = iVar8 * (uint)*(ushort *)(iVar15 + 0x18) * (int)(uVar18 >> 0x20);
    puVar21 = (uint *)(iVar8 * 3);
    *(int *)(iVar7 + 0x34) = iVar8;
    iVar15 = FUN_0608adae(puVar21);
    puVar13 = (undefined4 *)((ulonglong)uVar34 >> 0x20);
    iVar7 = (int)uVar18;
    puVar25 = puVar13 + 10;
    *(int *)(iVar7 + 0x3c) = iVar15;
    puVar11 = puVar12;
    if (iVar15 != 0) {
      func_0x0bf7d4ba(puVar25);
      puVar13 = (undefined4 *)((ulonglong)uVar34 >> 0x20);
      puVar11 = puVar21;
      if (*(int *)(iVar7 + 0x3c) != 0) goto LAB_0608cbc8;
    }
  }
  else {
    puVar25 = (undefined4 *)(iVar15 + 0x28);
LAB_0608cbc8:
    if (puVar25[6] == 0) {
      uVar6 = FUN_06088798();
      *(undefined4 *)(iVar7 + 0x38) = uVar6;
    }
    puVar13 = (undefined4 *)((ulonglong)uVar34 >> 0x20);
    func_0x0bf7d43e(puVar25,(int)uVar34);
    puVar11 = puVar17;
  }
  uVar23 = *(uint *)(iVar7 + 0x34);
  if (uVar23 <= (uint)puVar25[6]) {
    if (*(byte *)(iVar7 + 3) < 10) {
      *(byte *)(iVar7 + 3) = *(byte *)(iVar7 + 3) + 1;
      FUN_06088a6a();
      puVar25[2] = puVar25[2] + uVar23;
      puVar25[2] = *puVar25;
      puVar25[5] = puVar25[5] - uVar23;
      puVar25[6] = puVar25[6] - uVar23;
                    /* WARNING: Subroutine does not return */
      FUN_06088ab8(puVar25[1]);
    }
    iVar8 = func_0x0bfb4078(*puVar13,uVar23);
    iVar15 = 0;
    if (iVar8 == 0) goto LAB_0608cd18;
    puVar22 = puVar13 + 0x13;
    *(undefined2 *)(iVar8 + 0x12) = *(undefined2 *)puVar22;
    *(undefined4 *)(iVar8 + 8) = 0xf80;
    *(undefined4 *)(iVar8 + 0x18) = *(undefined4 *)(iVar7 + 0x38);
    func_0x0bf91c22(puVar25,*(undefined4 *)(iVar8 + 0x20));
    cVar3 = *(char *)(iVar7 + 7);
    if (cVar3 == '\x01') {
      uVar2 = *(ushort *)(iVar8 + 0x12);
      puVar11 = *(uint **)(iVar8 + 0x20);
      for (uVar23 = 0; uVar2 >> 2 != uVar23; uVar23 = uVar23 + 1) {
        puVar11[uVar23] = puVar11[uVar23] | 0x47f;
      }
    }
    else {
      uVar2 = *(ushort *)(iVar8 + 0x12);
      puVar11 = *(uint **)(iVar8 + 0x20);
    }
    if ((int)puVar22[3] < 0xc80) {
      iVar15 = puVar13[5];
      uVar6 = op_uextra_rrii((uint)*(byte *)(iVar7 + 5),4,4);
      if (cVar3 == '\0') {
        *puVar19 = uVar6;
        uVar6 = func_0x0bfb3ee2(0x4000 / ((uint)(iVar15 * 100) / 1000),uVar2);
      }
      else {
        *puVar19 = uVar6;
        uVar6 = func_0x0bfb3f28();
      }
      puVar22[3] = uVar6;
    }
    func_0x0bfb4088(*puVar13,iVar8);
  }
  iVar15 = func_0x0bf917a8(puVar13[3]);
LAB_0608cd18:
  puVar32 = (undefined1 *)((int)puVar19 + 4);
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar7 = *(int *)(iVar15 + 0x18);
  iVar15 = FUN_0608c0f4(iVar15);
  if (iVar15 != 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_0608c0b2(*(undefined4 *)(iVar7 + 0x18));
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  func_0x0bfb431a();
  iVar15 = 0x104b8c;
  piVar16 = (int *)0x104b8c;
  uRam00105fc0 = 0;
  while (piVar16 = (int *)*piVar16, piVar16 != (int *)iVar15) {
    if (piVar16[8] == 3) {
      func_0x0bfb4354(piVar16);
    }
  }
  uVar34 = func_0x0bfb43bc();
  iVar8 = (int)((ulonglong)uVar34 >> 0x20);
  op_pop_pc_rl();
  op_push_rets_rl();
  piVar33 = (int *)(puVar32 + -4);
  iVar7 = *(int *)(iVar8 + 0x18);
  iVar15 = *(int *)(iVar7 + 0x18);
  puVar31 = puVar32 + -4;
  if (*(int *)((int)uVar34 + 0x14) == 0) goto LAB_0608ce8a;
  iVar8 = func_0x0bfb3e40(iVar8);
  if ((iVar8 != 0) && (*(short *)(iVar7 + 2) != 0x1a85)) {
    if ((*(byte *)((int)uVar34 + 0x10) & 0xc0) == 0) {
      if (*(short *)(iVar7 + 2) == -0x19d6) goto LAB_0608cdbc;
      if (*(short *)(*(int *)((int)uVar34 + 0x18) + 0x1e) == 0) goto LAB_0608ce86;
      goto LAB_0608cdbc;
    }
    if (*(int *)((int)((ulonglong)uVar34 >> 0x20) + 0xc) != 1) goto LAB_0608ce86;
  }
  do {
    if ((*(byte *)((int)((ulonglong)uVar34 >> 0x20) + 0xc) & 1) != 0) {
      iVar20 = iVar7 + 0x1c;
      FUN_0608718a(iVar20,0);
      iVar8 = (int)((ulonglong)uVar34 >> 0x20);
      pcVar1 = *(code **)(iVar8 + 0x24);
      (*pcVar1)(iVar8,(int)uVar34,pcVar1);
      FUN_06087398(iVar20);
      if (iVar15 == 0) {
        *(undefined1 *)((int)uVar34 + 1) = 1;
      }
    }
LAB_0608cdbc:
    do {
      if (*(int *)((int)uVar34 + 0x14) == 0) {
        iVar8 = *(int *)((int)((ulonglong)uVar34 >> 0x20) + 0x1c);
        func_0x0bfb34d8();
        puVar25 = (undefined4 *)((ulonglong)uVar34 >> 0x20);
        puVar19 = (undefined4 *)*puVar25;
        if (*(int *)(iVar8 + 0x18) == 0x100) {
          iVar20 = 0;
          for (; puVar19 != puVar25; puVar19 = (undefined4 *)*puVar19) {
            iVar20 = iVar20 + ((int)((uint)*(ushort *)((int)puVar19 + 0x12) -
                                    (uint)*(ushort *)(puVar19 + 4)) >>
                              (uint)(*(char *)(puVar19 + 3) != '\0'));
          }
          if (iVar20 == 0) {
            uVar23 = 0;
          }
          else {
            if (*(byte *)(iVar8 + 8) >> 4 == 2) {
              uVar23 = iVar20 >> 1;
            }
            else {
              uVar23 = iVar20 >> 2;
            }
            uVar23 = ((uVar23 / 2) * 10000) / *(uint *)(iVar8 + 0x14);
          }
        }
        else {
          uVar23 = 0;
          for (; puVar19 != puVar25; puVar19 = (undefined4 *)*puVar19) {
            uVar23 = uVar23 + *(ushort *)((int)puVar19 + 0xe);
          }
        }
        func_0x0bfb34e2();
        *puVar11 = uVar23;
      }
      iVar20 = (int)((ulonglong)uVar34 >> 0x20);
      iVar8 = (int)uVar34;
      if (iVar15 == 0) {
        if ((*(byte *)(iVar20 + 0xc) & 1) != 0) {
          pcVar1 = *(code **)(iVar20 + 0x10);
          uVar6 = (*pcVar1)(0x20005,0,pcVar1);
          *(undefined4 *)((int)uVar34 + 8) = uVar6;
        }
        *(uint *)((int)uVar34 + 0x10) = *(uint *)((int)uVar34 + 0x10) | *(uint *)(iVar7 + 0xc);
      }
      else {
        *(uint *)(iVar8 + 0x10) = *(uint *)(iVar8 + 0x10) | *(uint *)(iVar7 + 0xc);
        uVar6 = 0;
        iVar20 = 0;
        do {
          *piVar33 = uVar6;
          iVar10 = 0;
          if (*(int *)(iVar15 + 0x2c) != 0) {
            FUN_0608cd6e(iVar8,piVar33);
            iVar10 = *piVar33;
          }
          uVar34 = CONCAT44(uVar6,iVar8);
          if (iVar20 < iVar10) {
            iVar20 = iVar10;
          }
          iVar15 = *(int *)(iVar15 + 0x30);
        } while (iVar15 != 0);
        *puVar11 = *puVar11 + iVar20;
      }
LAB_0608ce86:
      op_pop_pc_rl();
      puVar31 = (undefined1 *)((int)piVar33 + 4);
LAB_0608ce8a:
      piVar33 = (int *)puVar31;
    } while ((*(ushort *)((int)uVar34 + 0x10) & 0xe98) == 0);
  } while( true );
}


// ===== FUN_0608ca60 @ 0608ca60

void FUN_0608ca60(int *param_1,uint *param_2)

{
  code *pcVar1;
  ushort uVar2;
  char cVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int extraout_r1;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  undefined4 *puVar11;
  undefined2 *puVar12;
  int iVar13;
  int *piVar14;
  uint *puVar15;
  undefined4 *puVar17;
  ulonglong uVar16;
  int iVar18;
  uint *puVar19;
  undefined4 *puVar20;
  uint uVar21;
  uint uVar22;
  undefined4 *puVar23;
  undefined2 *puVar24;
  BADSPACEBASE *in_sp;
  undefined1 *puVar25;
  undefined1 *puVar26;
  undefined1 *puVar27;
  int *piVar28;
  undefined8 uVar29;
  
  op_push_rets_rl();
  func_0x0bfb34d8();
  iVar13 = 0;
  piVar14 = param_1;
  while (piVar14 = (int *)*piVar14, piVar14 != param_1) {
    iVar13 = iVar13 + 1;
  }
  func_0x0bfb34e2();
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar17 = (undefined4 *)(iVar13 + 0x10);
  if (*(byte *)(iVar13 + 0x1e) < 10) {
    *(byte *)(iVar13 + 0x1e) = *(byte *)(iVar13 + 0x1e) + 1;
    op_pop_pc_rl();
  }
  puVar10 = param_2;
  iVar6 = extraout_r1;
  iVar13 = func_0x0bfb4078(*puVar17,(uint)*(byte *)(iVar13 + 0x1f) * (int)param_2);
  uVar29 = func_0x0bf917a8(puVar17[2]);
  if (iVar13 != 0) {
    uVar21 = (uint)bRam00106a38;
    uVar22 = (uint)*(byte *)((int)puVar17 + 0xf);
    if (uVar22 == uVar21) {
      param_2 = (uint *)(uVar22 * (int)puVar10);
      func_0x05f9ac62(*(undefined4 *)(iVar13 + 0x20),iVar6);
      uVar22 = (uint)*(byte *)((int)puVar17 + 0xf);
    }
    else if (cRam00106a3a == '\0') {
      puVar24 = *(undefined2 **)(iVar13 + 0x20);
      param_2 = (uint *)0x0;
      for (iVar7 = 0; iVar7 < (int)((uint)puVar10 / 2); iVar7 = iVar7 + 1) {
        puVar12 = puVar24;
        puVar15 = param_2;
        for (uVar8 = uVar22; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar12 = *(undefined2 *)(iVar6 + ((uint)*(byte *)(puVar17 + 0x11) + (int)puVar15) * 2);
          puVar12 = puVar12 + 1;
          puVar15 = (uint *)((int)puVar15 + 1);
        }
        param_2 = (uint *)((int)param_2 + uVar21);
        puVar24 = puVar24 + uVar22;
      }
    }
    else {
      puVar23 = *(undefined4 **)(iVar13 + 0x20);
      param_2 = (uint *)0x0;
      for (iVar7 = 0; iVar7 < (int)((uint)puVar10 / 4); iVar7 = iVar7 + 1) {
        puVar11 = puVar23;
        puVar15 = param_2;
        for (uVar8 = uVar22; uVar8 != 0; uVar8 = uVar8 - 1) {
          *puVar11 = *(undefined4 *)(iVar6 + ((uint)*(byte *)(puVar17 + 0x11) + (int)puVar15) * 4);
          puVar11 = puVar11 + 1;
          puVar15 = (uint *)((int)puVar15 + 1);
        }
        param_2 = (uint *)((int)param_2 + uVar21);
        puVar23 = puVar23 + uVar22;
      }
    }
    *(short *)(iVar13 + 0x12) = (short)uVar22 * (short)puVar10;
    *(undefined4 *)(iVar13 + 8) = 0xf80;
    uVar5 = FUN_06088798();
    *(undefined4 *)(iVar13 + 0x18) = uVar5;
    uVar29 = func_0x0bfb4088(*puVar17,iVar13);
  }
  iVar6 = (int)((ulonglong)uVar29 >> 0x20);
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar26 = (undefined1 *)((int)in_sp + -4);
  puVar25 = (undefined1 *)((int)in_sp + -4);
  iVar13 = 0;
  puVar17 = (undefined4 *)((int)in_sp + -4);
  if (iVar6 == 0) goto LAB_0608cd18;
  if (*(char *)(iVar6 + 0x1c) == '\0') {
    *(undefined1 *)(iVar6 + 0x1c) = 1;
  }
  iVar13 = 0;
  puVar17 = (undefined4 *)((int)in_sp + -4);
  if (*(char *)(iVar6 + 0x1a) == '\0') goto LAB_0608cd18;
  bVar4 = *(byte *)(iVar6 + 0x1d) >> 4;
  uVar16 = (ulonglong)CONCAT14(bVar4,iVar6 + 0x18);
  puVar10 = param_2;
  puVar15 = param_2;
  puVar17 = (undefined4 *)((int)in_sp + -4);
  if (bVar4 == 1) {
    if (*(char *)(iVar6 + 0x1f) == '\x01') {
      puVar10 = (uint *)op_ext_l_u(param_2);
      func_0x0bfc8136((int)uVar29);
      puVar26 = puVar25;
    }
    else {
      puVar10 = (uint *)op_ext_l_u(param_2);
      func_0x0bfc817c((int)uVar29);
    }
    puVar15 = (uint *)((int)param_2 >> 1);
    puVar17 = (undefined4 *)puVar26;
  }
  iVar13 = (int)((ulonglong)uVar29 >> 0x20);
  iVar6 = (int)uVar16;
  if (*(int *)(iVar6 + 0x3c) == 0) {
    iVar7 = 4;
    if (*(char *)(iVar6 + 7) == '\0') {
      iVar7 = 2;
    }
    iVar7 = iVar7 * (uint)*(ushort *)(iVar13 + 0x18) * (int)(uVar16 >> 0x20);
    puVar19 = (uint *)(iVar7 * 3);
    *(int *)(iVar6 + 0x34) = iVar7;
    iVar13 = FUN_0608adae(puVar19);
    puVar11 = (undefined4 *)((ulonglong)uVar29 >> 0x20);
    iVar6 = (int)uVar16;
    puVar23 = puVar11 + 10;
    *(int *)(iVar6 + 0x3c) = iVar13;
    param_2 = puVar10;
    if (iVar13 != 0) {
      func_0x0bf7d4ba(puVar23);
      puVar11 = (undefined4 *)((ulonglong)uVar29 >> 0x20);
      param_2 = puVar19;
      if (*(int *)(iVar6 + 0x3c) != 0) goto LAB_0608cbc8;
    }
  }
  else {
    puVar23 = (undefined4 *)(iVar13 + 0x28);
LAB_0608cbc8:
    if (puVar23[6] == 0) {
      uVar5 = FUN_06088798();
      *(undefined4 *)(iVar6 + 0x38) = uVar5;
    }
    puVar11 = (undefined4 *)((ulonglong)uVar29 >> 0x20);
    func_0x0bf7d43e(puVar23,(int)uVar29);
    param_2 = puVar15;
  }
  uVar21 = *(uint *)(iVar6 + 0x34);
  if (uVar21 <= (uint)puVar23[6]) {
    if (*(byte *)(iVar6 + 3) < 10) {
      *(byte *)(iVar6 + 3) = *(byte *)(iVar6 + 3) + 1;
      FUN_06088a6a();
      puVar23[2] = puVar23[2] + uVar21;
      puVar23[2] = *puVar23;
      puVar23[5] = puVar23[5] - uVar21;
      puVar23[6] = puVar23[6] - uVar21;
                    /* WARNING: Subroutine does not return */
      FUN_06088ab8(puVar23[1]);
    }
    iVar7 = func_0x0bfb4078(*puVar11,uVar21);
    iVar13 = 0;
    if (iVar7 == 0) goto LAB_0608cd18;
    puVar20 = puVar11 + 0x13;
    *(undefined2 *)(iVar7 + 0x12) = *(undefined2 *)puVar20;
    *(undefined4 *)(iVar7 + 8) = 0xf80;
    *(undefined4 *)(iVar7 + 0x18) = *(undefined4 *)(iVar6 + 0x38);
    func_0x0bf91c22(puVar23,*(undefined4 *)(iVar7 + 0x20));
    cVar3 = *(char *)(iVar6 + 7);
    if (cVar3 == '\x01') {
      uVar2 = *(ushort *)(iVar7 + 0x12);
      param_2 = *(uint **)(iVar7 + 0x20);
      for (uVar21 = 0; uVar2 >> 2 != uVar21; uVar21 = uVar21 + 1) {
        param_2[uVar21] = param_2[uVar21] | 0x47f;
      }
    }
    else {
      uVar2 = *(ushort *)(iVar7 + 0x12);
      param_2 = *(uint **)(iVar7 + 0x20);
    }
    if ((int)puVar20[3] < 0xc80) {
      iVar13 = puVar11[5];
      uVar5 = op_uextra_rrii((uint)*(byte *)(iVar6 + 5),4,4);
      if (cVar3 == '\0') {
        *puVar17 = uVar5;
        uVar5 = func_0x0bfb3ee2(0x4000 / ((uint)(iVar13 * 100) / 1000),uVar2);
      }
      else {
        *puVar17 = uVar5;
        uVar5 = func_0x0bfb3f28();
      }
      puVar20[3] = uVar5;
    }
    func_0x0bfb4088(*puVar11,iVar7);
  }
  iVar13 = func_0x0bf917a8(puVar11[3]);
LAB_0608cd18:
  puVar27 = (undefined1 *)((int)puVar17 + 4);
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar6 = *(int *)(iVar13 + 0x18);
  iVar13 = FUN_0608c0f4(iVar13);
  if (iVar13 != 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_0608c0b2(*(undefined4 *)(iVar6 + 0x18));
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  func_0x0bfb431a();
  iVar13 = 0x104b8c;
  piVar14 = (int *)0x104b8c;
  uRam00105fc0 = 0;
  while (piVar14 = (int *)*piVar14, piVar14 != (int *)iVar13) {
    if (piVar14[8] == 3) {
      func_0x0bfb4354(piVar14);
    }
  }
  uVar29 = func_0x0bfb43bc();
  iVar7 = (int)((ulonglong)uVar29 >> 0x20);
  op_pop_pc_rl();
  op_push_rets_rl();
  piVar28 = (int *)(puVar27 + -4);
  iVar6 = *(int *)(iVar7 + 0x18);
  iVar13 = *(int *)(iVar6 + 0x18);
  puVar26 = puVar27 + -4;
  if (*(int *)((int)uVar29 + 0x14) == 0) goto LAB_0608ce8a;
  iVar7 = func_0x0bfb3e40(iVar7);
  if ((iVar7 != 0) && (*(short *)(iVar6 + 2) != 0x1a85)) {
    if ((*(byte *)((int)uVar29 + 0x10) & 0xc0) == 0) {
      if (*(short *)(iVar6 + 2) == -0x19d6) goto LAB_0608cdbc;
      if (*(short *)(*(int *)((int)uVar29 + 0x18) + 0x1e) == 0) goto LAB_0608ce86;
      goto LAB_0608cdbc;
    }
    if (*(int *)((int)((ulonglong)uVar29 >> 0x20) + 0xc) != 1) goto LAB_0608ce86;
  }
  do {
    if ((*(byte *)((int)((ulonglong)uVar29 >> 0x20) + 0xc) & 1) != 0) {
      iVar18 = iVar6 + 0x1c;
      FUN_0608718a(iVar18,0);
      iVar7 = (int)((ulonglong)uVar29 >> 0x20);
      pcVar1 = *(code **)(iVar7 + 0x24);
      (*pcVar1)(iVar7,(int)uVar29,pcVar1);
      FUN_06087398(iVar18);
      if (iVar13 == 0) {
        *(undefined1 *)((int)uVar29 + 1) = 1;
      }
    }
LAB_0608cdbc:
    do {
      if (*(int *)((int)uVar29 + 0x14) == 0) {
        iVar7 = *(int *)((int)((ulonglong)uVar29 >> 0x20) + 0x1c);
        func_0x0bfb34d8();
        puVar23 = (undefined4 *)((ulonglong)uVar29 >> 0x20);
        puVar17 = (undefined4 *)*puVar23;
        if (*(int *)(iVar7 + 0x18) == 0x100) {
          iVar18 = 0;
          for (; puVar17 != puVar23; puVar17 = (undefined4 *)*puVar17) {
            iVar18 = iVar18 + ((int)((uint)*(ushort *)((int)puVar17 + 0x12) -
                                    (uint)*(ushort *)(puVar17 + 4)) >>
                              (uint)(*(char *)(puVar17 + 3) != '\0'));
          }
          if (iVar18 == 0) {
            uVar21 = 0;
          }
          else {
            if (*(byte *)(iVar7 + 8) >> 4 == 2) {
              uVar21 = iVar18 >> 1;
            }
            else {
              uVar21 = iVar18 >> 2;
            }
            uVar21 = ((uVar21 / 2) * 10000) / *(uint *)(iVar7 + 0x14);
          }
        }
        else {
          uVar21 = 0;
          for (; puVar17 != puVar23; puVar17 = (undefined4 *)*puVar17) {
            uVar21 = uVar21 + *(ushort *)((int)puVar17 + 0xe);
          }
        }
        func_0x0bfb34e2();
        *param_2 = uVar21;
      }
      iVar18 = (int)((ulonglong)uVar29 >> 0x20);
      iVar7 = (int)uVar29;
      if (iVar13 == 0) {
        if ((*(byte *)(iVar18 + 0xc) & 1) != 0) {
          pcVar1 = *(code **)(iVar18 + 0x10);
          uVar5 = (*pcVar1)(0x20005,0,pcVar1);
          *(undefined4 *)((int)uVar29 + 8) = uVar5;
        }
        *(uint *)((int)uVar29 + 0x10) = *(uint *)((int)uVar29 + 0x10) | *(uint *)(iVar6 + 0xc);
      }
      else {
        *(uint *)(iVar7 + 0x10) = *(uint *)(iVar7 + 0x10) | *(uint *)(iVar6 + 0xc);
        uVar5 = 0;
        iVar18 = 0;
        do {
          *piVar28 = uVar5;
          iVar9 = 0;
          if (*(int *)(iVar13 + 0x2c) != 0) {
            FUN_0608cd6e(iVar7,piVar28);
            iVar9 = *piVar28;
          }
          uVar29 = CONCAT44(uVar5,iVar7);
          if (iVar18 < iVar9) {
            iVar18 = iVar9;
          }
          iVar13 = *(int *)(iVar13 + 0x30);
        } while (iVar13 != 0);
        *param_2 = *param_2 + iVar18;
      }
LAB_0608ce86:
      op_pop_pc_rl();
      puVar26 = (undefined1 *)((int)piVar28 + 4);
LAB_0608ce8a:
      piVar28 = (int *)puVar26;
    } while ((*(ushort *)((int)uVar29 + 0x10) & 0xe98) == 0);
  } while( true );
}


// ===== FUN_0608cd36 @ 0608cd36

void FUN_0608cd36(uint *param_1)

{
  code *pcVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  BADSPACEBASE *in_sp;
  int *piVar13;
  undefined8 uVar14;
  
  op_push_rets_rl();
  func_0x0bfb431a();
  iVar9 = 0x104b8c;
  piVar8 = (int *)0x104b8c;
  uRam00105fc0 = 0;
  while (piVar8 = (int *)*piVar8, piVar8 != (int *)iVar9) {
    if (piVar8[8] == 3) {
      func_0x0bfb4354(piVar8);
    }
  }
  uVar14 = func_0x0bfb43bc();
  iVar3 = (int)((ulonglong)uVar14 >> 0x20);
  op_pop_pc_rl();
  op_push_rets_rl();
  piVar13 = (int *)((int)in_sp + -4);
  iVar12 = *(int *)(iVar3 + 0x18);
  iVar9 = *(int *)(iVar12 + 0x18);
  puVar2 = (undefined1 *)((int)in_sp + -4);
  if (*(int *)((int)uVar14 + 0x14) == 0) goto LAB_0608ce8a;
  iVar3 = func_0x0bfb3e40(iVar3);
  if ((iVar3 != 0) && (*(short *)(iVar12 + 2) != 0x1a85)) {
    if ((*(byte *)((int)uVar14 + 0x10) & 0xc0) == 0) {
      if (*(short *)(iVar12 + 2) == -0x19d6) goto LAB_0608cdbc;
      if (*(short *)(*(int *)((int)uVar14 + 0x18) + 0x1e) == 0) goto LAB_0608ce86;
      goto LAB_0608cdbc;
    }
    if (*(int *)((int)((ulonglong)uVar14 >> 0x20) + 0xc) != 1) goto LAB_0608ce86;
  }
  do {
    if ((*(byte *)((int)((ulonglong)uVar14 >> 0x20) + 0xc) & 1) != 0) {
      iVar11 = iVar12 + 0x1c;
      FUN_0608718a(iVar11,0);
      iVar3 = (int)((ulonglong)uVar14 >> 0x20);
      pcVar1 = *(code **)(iVar3 + 0x24);
      (*pcVar1)(iVar3,(int)uVar14,pcVar1);
      FUN_06087398(iVar11);
      if (iVar9 == 0) {
        *(undefined1 *)((int)uVar14 + 1) = 1;
      }
    }
LAB_0608cdbc:
    do {
      if (*(int *)((int)uVar14 + 0x14) == 0) {
        iVar3 = *(int *)((int)((ulonglong)uVar14 >> 0x20) + 0x1c);
        func_0x0bfb34d8();
        puVar10 = (undefined4 *)((ulonglong)uVar14 >> 0x20);
        puVar6 = (undefined4 *)*puVar10;
        if (*(int *)(iVar3 + 0x18) == 0x100) {
          iVar11 = 0;
          for (; puVar6 != puVar10; puVar6 = (undefined4 *)*puVar6) {
            iVar11 = iVar11 + ((int)((uint)*(ushort *)((int)puVar6 + 0x12) -
                                    (uint)*(ushort *)(puVar6 + 4)) >>
                              (uint)(*(char *)(puVar6 + 3) != '\0'));
          }
          if (iVar11 == 0) {
            uVar4 = 0;
          }
          else {
            if (*(byte *)(iVar3 + 8) >> 4 == 2) {
              uVar4 = iVar11 >> 1;
            }
            else {
              uVar4 = iVar11 >> 2;
            }
            uVar4 = ((uVar4 / 2) * 10000) / *(uint *)(iVar3 + 0x14);
          }
        }
        else {
          uVar4 = 0;
          for (; puVar6 != puVar10; puVar6 = (undefined4 *)*puVar6) {
            uVar4 = uVar4 + *(ushort *)((int)puVar6 + 0xe);
          }
        }
        func_0x0bfb34e2();
        *param_1 = uVar4;
      }
      iVar11 = (int)((ulonglong)uVar14 >> 0x20);
      iVar3 = (int)uVar14;
      if (iVar9 == 0) {
        if ((*(byte *)(iVar11 + 0xc) & 1) != 0) {
          pcVar1 = *(code **)(iVar11 + 0x10);
          uVar5 = (*pcVar1)(0x20005,0,pcVar1);
          *(undefined4 *)((int)uVar14 + 8) = uVar5;
        }
        *(uint *)((int)uVar14 + 0x10) = *(uint *)((int)uVar14 + 0x10) | *(uint *)(iVar12 + 0xc);
      }
      else {
        *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) | *(uint *)(iVar12 + 0xc);
        uVar5 = 0;
        iVar11 = 0;
        do {
          *piVar13 = uVar5;
          iVar7 = 0;
          if (*(int *)(iVar9 + 0x2c) != 0) {
            FUN_0608cd6e(iVar3,piVar13);
            iVar7 = *piVar13;
          }
          uVar14 = CONCAT44(uVar5,iVar3);
          if (iVar11 < iVar7) {
            iVar11 = iVar7;
          }
          iVar9 = *(int *)(iVar9 + 0x30);
        } while (iVar9 != 0);
        *param_1 = *param_1 + iVar11;
      }
LAB_0608ce86:
      op_pop_pc_rl();
      puVar2 = (undefined1 *)((int)piVar13 + 4);
LAB_0608ce8a:
      piVar13 = (int *)puVar2;
    } while ((*(ushort *)((int)uVar14 + 0x10) & 0xe98) == 0);
  } while( true );
}


// ===== FUN_0608d9d8 @ 0608d9d8

/* WARNING: Heritage AFTER dead removal. Example location: r0x00000014 : 0x0608dea2 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_0608d9d8(void)

{
  undefined2 uVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  short sVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  ushort *puVar11;
  int iVar12;
  undefined8 in_r0_r1;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  undefined1 *extraout_r1_03;
  ulonglong uVar13;
  uint uVar14;
  undefined4 extraout_r1_04;
  undefined4 extraout_r1_05;
  undefined2 *puVar15;
  undefined1 *puVar16;
  uint uVar17;
  int iVar18;
  int *piVar21;
  undefined8 uVar19;
  undefined8 uVar20;
  uint uVar22;
  uint *puVar23;
  longlong lVar24;
  uint uVar25;
  undefined4 *puVar26;
  ushort uVar27;
  int *piVar28;
  undefined4 uVar29;
  undefined1 *puVar30;
  undefined1 *puVar31;
  undefined4 uVar32;
  int iVar33;
  byte *pbVar34;
  BADSPACEBASE *in_sp;
  int *piVar35;
  int *piVar36;
  undefined1 *puVar37;
  uint *puVar38;
  undefined4 *puVar39;
  
  op_push_rets_rl();
  iVar9 = (int)((ulonglong)in_r0_r1 >> 0x20);
  piVar6 = (int *)in_r0_r1;
  iVar7 = FUN_0608ca60();
  if (iVar9 < iVar7) {
    iVar7 = -1;
    iVar9 = extraout_r1;
    if ((short)piVar6[4] != 0) {
      func_0x0bfb34d8();
      iVar8 = 0;
      piVar21 = piVar6;
      while (piVar21 = (int *)*piVar21, piVar21 != piVar6) {
        iVar8 = ((uint)*(ushort *)((int)piVar21 + 0x12) + iVar8) - (uint)*(ushort *)(piVar21 + 4);
      }
      func_0x0bfb34e2();
      iVar9 = extraout_r1_00;
      if (iVar8 <= (int)(uint)*(ushort *)(piVar6 + 4)) goto LAB_0608da12;
    }
  }
  else {
LAB_0608da12:
    uVar17 = piVar6[6];
    uVar13 = (ulonglong)uVar17;
    iVar9 = 0xe62a;
    if (*(short *)(uVar17 + 2) == -0x19d6) {
      piVar21 = *(int **)(uVar17 + 0x14);
      do {
        if ((piVar21 != piVar6) && ((*(byte *)(piVar21 + 3) & 1) != 0)) {
          iVar7 = func_0x0bfb5ebe(piVar21);
          iVar9 = extraout_r1_01;
          if (iVar7 == 0) {
            iVar7 = 1;
            goto LAB_0608da54;
          }
        }
        uVar17 = (uint)uVar13;
        piVar21 = (int *)piVar21[8];
      } while (piVar21 != (int *)0x0);
    }
    iVar7 = 0;
    for (iVar8 = *(int *)(uVar17 + 0x18); iVar8 != 0; iVar8 = *(int *)(iVar8 + 0x30)) {
      iVar33 = iVar7;
      iVar7 = FUN_0608d9d8(*(undefined4 *)(iVar8 + 0x2c));
      iVar9 = extraout_r1_02;
      if (iVar7 != 0) break;
      iVar7 = iVar33;
    }
  }
LAB_0608da54:
  op_pop_pc_rl();
  op_push_rets_rl();
  func_0x0bfb34d8();
  iVar8 = 1;
  if (*(char *)(iVar9 + 0xc) != '\0') {
    iVar8 = 2;
  }
  uVar17 = (uint)*(byte *)(iVar7 + 4);
  iVar8 = (int)((uint)*(ushort *)(iVar9 + 0x12) - (uint)*(ushort *)(iVar9 + 0x10)) >> iVar8;
  if (*(byte *)(iVar7 + 4) >> 4 == 2) {
    iVar8 = iVar8 >> 1;
  }
  else {
    iVar8 = iVar8 >> 2;
  }
  puVar16 = (undefined1 *)0x2710;
  uVar22 = (uint)(iVar8 * 10000) / *(uint *)(iVar7 + 0x10);
  func_0x0bfb34e2();
  op_pop_pc_rl();
  op_push_rets_rl();
  piVar6 = *(int **)(uVar22 + 0x14);
  piVar28 = piVar6 + 4;
  piVar21 = piVar6 + 0x1a;
  if ((*(char *)((int)piVar6 + 0x15) == '\0') || (*(char *)((int)piVar6 + 0x69) != '\0')) {
    puVar30 = extraout_r1_03;
    if (piVar6[0x1e] == 0) {
      if (piVar6[0x1d] == 0) {
        func_0x0bfb62a2();
        uVar22 = FUN_0608d9d8(*(undefined4 *)(*(int *)(*piVar6 + 0x18) + 0x2c));
        lVar24 = (ulonglong)uVar22 << 0x20;
        func_0x0bfb62ac();
        if (lVar24 < 0) goto code_r0x0608dbbe;
        func_0x0bfb620e(piVar6);
        *puVar30 = (char)piVar28[1];
      }
      else {
        iVar7 = func_0x0bfb5ebe();
        if (iVar7 != 0) {
          func_0x0bfb620e(piVar6);
        }
        iVar7 = func_0x0bfb611a(piVar6);
        if (iVar7 != 1) goto code_r0x0608dbbe;
        if ((*(int *)(*(int *)(puVar30 + 0x18) + 0x54) != 0) &&
           (puVar16 = *(undefined1 **)(puVar30 + 0x14),
           puVar16 == *(undefined1 **)(*(int *)(puVar30 + 0x18) + 0x50))) {
          FUN_060878c8();
        }
      }
    }
    else {
      iVar7 = func_0x0bfb611a(piVar6);
      if (iVar7 == 1) {
        uVar17 = *(uint *)(*(int *)(puVar30 + 0x18) + 0x54);
        if ((uVar17 != 0) && (*(int *)(puVar30 + 0x14) == *(int *)(*(int *)(puVar30 + 0x18) + 0x50))
           ) {
          iVar7 = func_0x0bfb5ebe();
          if (iVar7 == 0) {
            FUN_060878c8();
          }
          else {
            *(undefined1 *)(piVar21[4] + 1) = 1;
          }
        }
      }
      iVar7 = *(int *)(*(int *)(puVar30 + 0x18) + 0x54);
      FUN_06087a88();
      iVar9 = 2;
      if (iVar7 == 0) {
        iVar9 = 1;
      }
      for (uVar22 = (uint)*(byte *)piVar21[4]; (int)uVar22 < iVar9; uVar22 = uVar22 + 1) {
        FUN_060878c8();
      }
code_r0x0608dbbe:
      *(uint *)(puVar30 + 0x10) = *(uint *)(puVar30 + 0x10) | 0xe00;
    }
    uVar13 = (ulonglong)*(byte *)((int)piVar28 + 7);
    if (*(byte *)((int)piVar28 + 7) == 0) goto LAB_0608dbd2;
    uVar13 = CONCAT44(0x20,puVar30 + 0x10);
  }
  else {
    uVar13 = CONCAT44(0x80,*piVar6 + 0xc);
  }
  *(uint *)uVar13 = *(uint *)uVar13 | (uint)(uVar13 >> 0x20);
LAB_0608dbd2:
  op_pop_pc_rl();
  op_push_rets_rl();
  piVar35 = (int *)((int)in_sp + -0x48);
  iVar8 = 2;
  iVar9 = (int)uVar13;
  iVar7 = *(int *)(iVar9 + 0x14);
  pbVar34 = (byte *)(iVar7 + 0x14);
  if (*(char *)(iVar7 + 0x21) == '\0') {
    iVar8 = 1;
  }
  iVar33 = 8 << iVar8;
  uVar20 = CONCAT44((undefined1 *)((int)in_sp + -0x3c),iVar7);
  puVar30 = (undefined1 *)((int)in_sp + -0x28);
  puVar31 = (undefined1 *)((int)in_sp + -0x14);
  uVar29 = 0;
  *(undefined1 **)((int)in_sp + -0x48) = (undefined1 *)((int)in_sp + -0xc);
  *(int *)((int)in_sp + -0x40) = iVar9;
  *(undefined4 *)((int)in_sp + -0x44) = *(undefined4 *)(iVar9 + 0x18);
  do {
    while (iVar7 = *(int *)((int)uVar20 + 8), iVar7 == 0) {
      iVar7 = FUN_0608c0f4(*(undefined4 *)((int)piVar35 + 8));
      if (iVar7 == 0) goto LAB_0608de9a;
      iVar9 = (int)uVar20;
      *(int *)(iVar9 + 8) = iVar7;
      if ((*(uint *)(iVar7 + 8) & 0x100) == 0) {
        uVar22 = (uint)*(ushort *)(iVar7 + 0x16) +
                 *(int *)(*(int *)(*(int *)(*(int *)(iVar9 + 4) + 0x14) + 0x1c) + 0x14);
        *(int *)(iVar7 + 0x18) = *(int *)(iVar7 + 0x18) + *(int *)(iVar9 + 0x3c) * 0x20;
      }
      else {
        uVar22 = func_0x0bfb6642(iVar9);
        func_0x0bfb6770((int)uVar20,uVar22);
        iVar9 = *(int *)(iVar7 + 0x18);
        iVar12 = (int)uVar20;
        *(int *)(iVar12 + 0xc) = iVar9;
        if (*(short *)(*(int *)(*(int *)(iVar12 + 4) + 0x2c) + 4) == -0xf7) {
          iVar18 = 2;
          if (*(char *)(*(int *)(*(int *)(iVar12 + 4) + 0x18) + 5) == '\0') {
            iVar18 = 1;
          }
          iVar9 = (iVar9 - (((uint)(*(ushort *)(iVar7 + 0x12) >> iVar18) / (uint)*pbVar34) * 1000000
                           ) / uVar22) + *(int *)(iVar12 + 0x3c);
        }
        else {
          iVar9 = iVar9 + *(int *)(iVar12 + 0x3c);
        }
        *(int *)(iVar7 + 0x18) = iVar9 << 5;
      }
      if ((pbVar34[1] != 0) || ((*(ushort *)(iVar7 + 8) & 0xf84) == 0)) {
LAB_0608ddfe:
        if ((*(ushort *)(iVar7 + 8) & 0xf84) != 0) {
          func_0x0bfc7598(*(undefined4 *)uVar20);
          if (((undefined4 *)uVar20)[4] != uVar22) {
            func_0x0bfc75f4(*(undefined4 *)uVar20);
            *(uint *)((int)uVar20 + 0x10) = uVar22;
          }
        }
        break;
      }
      *(undefined4 *)(*piVar35 + 8) = uVar29;
      *(undefined8 *)(puVar31 + 8) = 0;
      piVar35[0xd] = 4;
      *(undefined4 *)(puVar31 + 4) = 0x3ff;
      func_0x0bfb3f7c(piVar35[1]);
      puVar16 = (undefined1 *)((int)piVar35 + 0x34);
      func_0x0bfb377e();
      bVar2 = pbVar34[4];
      if (bVar2 != 1) {
        uVar17 = *(uint *)(iVar7 + 0x18);
LAB_0608ddc8:
        pbVar34[1] = 1;
        *(undefined4 *)((int)piVar35 + 0x34) = 2;
        *(undefined4 *)(puVar31 + 4) = *(undefined4 *)uVar20;
        *(uint *)(puVar31 + 8) = uVar17;
        *(uint *)(puVar31 + 0xc) = (uint)bVar2;
        func_0x0bfc746a(1);
        func_0x0bfb3518(*(undefined4 *)(*(int *)(*(int *)((int)piVar35 + 4) + 0x18) + 0x2c));
        goto LAB_0608ddfe;
      }
      if (*(int *)(puVar31 + 4) != 0) {
        func_0x0bfb683e(1);
      }
      uVar17 = *(uint *)(iVar7 + 0x18);
      iVar9 = func_0x0bfb6862();
      bVar2 = pbVar34[4];
      if (iVar9 != 0) goto LAB_0608ddc8;
      func_0x0bfb683e(bVar2);
      FUN_0608be7e(iVar7);
      *(undefined4 *)((int)uVar20 + 8) = uVar29;
    }
    uVar22 = (uint)*(ushort *)(iVar7 + 0x10);
    uVar25 = (uint)*(ushort *)(iVar7 + 0x12);
    iVar9 = func_0x0bfc7640(*(undefined4 *)uVar20);
    iVar12 = 4;
    if (pbVar34[0xd] == 0) {
      iVar12 = 2;
    }
    uVar14 = iVar12 * (uint)*pbVar34;
    uVar17 = *(uint *)((int)uVar20 + 4);
    puVar16 = (undefined1 *)
              ((((((iVar9 * (uVar25 - uVar22)) / *(uint *)((int)uVar20 + 0x10)) * 6) / 5 +
                 (uint)*pbVar34 * iVar33 + uVar14) - 1) / uVar14);
    op_ext_l_u(uVar14 * (int)puVar16);
    iVar9 = FUN_0608bf56();
    if (iVar9 == 0) {
LAB_0608de9a:
      op_pop_pc_rl();
      op_push_rets_rl();
      piVar36 = (int *)((int)piVar35 + 0x3c);
      iVar7 = *(int *)(_uRam00000014 + 0x18);
      iVar9 = iRam00000018;
      piVar6 = (int *)((int)piVar35 + 0x3c);
      iVar8 = _uRam00000014;
      if (iVar7 == 0) {
        iVar7 = FUN_0608c0f4();
        *(int *)(iVar8 + 0x18) = iVar7;
        piVar6 = piVar36;
        if (iVar7 != 0) goto LAB_0608deb8;
      }
      else {
LAB_0608deb8:
        piVar36 = piVar6;
        if (*(int *)(iVar9 + 0x18) != 0) {
          pbVar34 = (byte *)(iVar8 + 0x20);
          iVar33 = *(int *)(iVar8 + 0x10);
          if ((iVar33 == 0) || (*(char *)(iVar8 + 0x23) != '\0')) {
            uVar17 = (uint)*pbVar34;
            puVar16 = (undefined1 *)(uint)*(byte *)(iVar8 + 0x21);
            if (uVar17 == 0) {
              if (puVar16 == (undefined1 *)0x0) goto LAB_0608df5c;
              op_ext_l_u((uint)*(ushort *)(iVar7 + 0x12) << 1);
              iVar7 = FUN_0608bf56();
              if (iVar7 != 0) {
                iVar33 = *(int *)(iVar8 + 0x18);
                *(short *)(iVar7 + 0x12) = *(short *)(iVar33 + 0x12) << 1;
                puVar26 = *(undefined4 **)(iVar7 + 0x20);
                uVar17 = (uint)(*(ushort *)(iVar33 + 0x12) >> 1);
                if (*(char *)(*(int *)(*(int *)(iVar8 + 0x14) + 0x18) + 4) == '\x17') {
                  do {
                    rep_unspec(10,uVar17);
                    uVar29 = op_shl3_rr(8);
                    *puVar26 = uVar29;
                    puVar26 = puVar26 + 1;
                  } while (uVar17 != 0);
                }
                else {
                  func_0x0bfc91da();
                }
LAB_0608dfde:
                uVar29 = *(undefined4 *)(iVar9 + 0x18);
LAB_0608dfe4:
                    /* WARNING: Subroutine does not return */
                thunk_FUN_0608c0b2(uVar29);
              }
            }
            else {
              if (puVar16 != (undefined1 *)0x0) {
LAB_0608df5c:
                    /* WARNING: Subroutine does not return */
                thunk_FUN_0608c0b2();
              }
              iVar7 = FUN_0608bf56();
              if (iVar7 != 0) {
                iVar33 = *(int *)(iVar8 + 0x18);
                *(ushort *)(iVar7 + 0x12) = *(ushort *)(iVar33 + 0x12) >> 1;
                puVar15 = *(undefined2 **)(iVar7 + 0x20);
                puVar26 = *(undefined4 **)(iVar33 + 0x20);
                uVar17 = (uint)(*(ushort *)(iVar33 + 0x12) >> 2);
                if (*(char *)(*(int *)(*(int *)(iVar8 + 0x14) + 0x18) + 4) == '\x17') {
                  do {
                    rep_unspec(0x10,uVar17);
                    uVar20 = op_mul_mem1_w_i_s(puVar26,4,1);
                    uVar29 = op_shiftr_rpr_mode(uVar20,8);
                    uVar29 = sat16(uVar29);
                    *puVar15 = (short)uVar29;
                    puVar15 = puVar15 + 1;
                  } while (uVar17 != 0);
                }
                else {
                  do {
                    rep_unspec(8,uVar17);
                    uVar29 = *puVar26;
                    puVar26 = puVar26 + 1;
                    uVar29 = sat16(uVar29);
                    *puVar15 = (short)uVar29;
                    puVar15 = puVar15 + 1;
                  } while (uVar17 != 0);
                }
                uVar29 = *(undefined4 *)(iVar9 + 0x18);
                goto LAB_0608dfe4;
              }
            }
          }
          else {
            bVar2 = *pbVar34;
            if (bVar2 != *(byte *)(iVar7 + 0xc)) {
              *pbVar34 = *(byte *)(iVar7 + 0xc);
              piVar36[2] = 1;
              piVar36[1] = 1;
              *piVar36 = iVar33;
              (*pcRam001134b8)();
              bVar2 = *pbVar34;
              iVar7 = *(int *)(iVar8 + 0x18);
            }
            uVar17 = (uint)bVar2;
            puVar16 = (undefined1 *)(uint)*(byte *)(iVar8 + 0x21);
            uVar27 = *(ushort *)(iVar7 + 0x12);
            op_ext_l_u((uint)uVar27);
            iVar7 = FUN_0608bf56();
            if (iVar7 != 0) {
              *(ushort *)(iVar7 + 0x12) = uVar27;
              FUN_0608beb4(*(undefined4 *)(iVar7 + 0x20));
              goto LAB_0608dfde;
            }
          }
        }
      }
      puVar37 = (undefined1 *)((int)piVar36 + 0xc);
      op_pop_pc_rl();
      op_push_rets_rl();
      iVar7 = iRam00000018;
      iVar9 = _uRam00000014;
      iVar8 = FUN_0608c0f4();
      if (iVar8 != 0) {
        if (*(int *)(iVar9 + 0x10) != 0) {
          func_0x0bfc9a80(*(undefined2 *)(iVar8 + 0x12));
        }
                    /* WARNING: Subroutine does not return */
        thunk_FUN_0608c0b2(*(undefined4 *)(iVar7 + 0x18));
      }
      op_pop_pc_rl();
      op_push_rets_rl();
      puVar38 = (uint *)(puVar37 + -0x10);
      puVar26 = (undefined4 *)(_uRam00000014 + 0x10);
      iVar7 = *(int *)(_uRam00000014 + 0x1c);
      puVar30 = puVar37 + -0x10;
      iVar9 = iRam00000018;
      iVar8 = _uRam00000014;
      if (iVar7 == 0) {
        iVar7 = FUN_0608c0f4(0);
        puVar26[3] = iVar7;
        puVar30 = (undefined1 *)puVar38;
        uVar29 = extraout_r1_04;
        if (iVar7 != 0) goto LAB_0608e038;
      }
      else {
LAB_0608e038:
        puVar38 = (uint *)puVar30;
        iVar8 = iVar8 + 0x20;
        if (((*(short *)(puVar26[1] + 2) == -0x4072) && (puVar26[5] == 4)) &&
           ((code *)puVar26[8] != (code *)0x0)) {
          uVar4 = (*(code *)puVar26[8])();
          *(undefined1 *)(iVar8 + 0xc) = uVar4;
          iVar7 = puVar26[3];
        }
        puVar16 = (undefined1 *)(uint)*(byte *)((int)puVar26 + 9);
        uVar29 = *(undefined4 *)(iVar9 + 0x18);
        op_ext_l_u(((uint)*(ushort *)(iVar7 + 0x12) * (uint)*(byte *)(puVar26 + 2)) / (uint)puVar16)
        ;
        iVar7 = FUN_0608bf56(uVar29);
        uVar20 = CONCAT44(iVar7,uVar29);
        uVar29 = extraout_r1_05;
        if (iVar7 != 0) {
          uVar29 = *puVar26;
          uVar32 = *(undefined4 *)(puVar26[3] + 0x20);
          bVar2 = *(byte *)(puVar26 + 2);
          bVar3 = *(byte *)((int)puVar26 + 9);
          uVar4 = *(undefined1 *)(iVar8 + 1);
          puVar38[3] = (uint)*(byte *)(iVar8 + 0xc);
          *(ulonglong *)(puVar38 + 1) = (ulonglong)CONCAT14(uVar4,(uint)bVar3);
          *puVar38 = (uint)bVar2;
          func_0x0bfc8424(uVar29,uVar32);
          *(short *)((int)((ulonglong)uVar20 >> 0x20) + 0x12) = (short)uVar20;
                    /* WARNING: Subroutine does not return */
          thunk_FUN_0608c0b2();
        }
      }
      iVar7 = iRam00000074;
      uVar32 = 0;
      op_pop_pc_rl();
      op_push_rets_rl();
      puVar39 = puVar38 + -0xd;
      if ((((*(byte *)(*(int *)(iRam00000000 + 0x14) + 0xc) & 0xc) != 0) ||
          ((*(byte *)(iRam00000000 + 0xc) & 0x10) != 0)) || (iVar9 = 0x10, 1 < bRam00000011))
      goto LAB_0608e344;
      iVar8 = *(int *)(iRam00000000 + 0x18);
      if ((uRam00000014._1_1_ != '\0') && (cRam00000069 == '\0')) goto LAB_0608e344;
      uVar22 = (uint)(*(byte *)(iVar8 + 8) >> 4);
      puVar38[-1] = uVar17 >> 4;
      if (uVar17 >> 4 == 1) {
        puVar38[1] = 1;
        puVar38[-6] = 1;
        puVar38[-6] = 0;
      }
      else {
        puVar38[-6] = 1;
        puVar38[1] = 1;
        puVar38[1] = 0;
      }
      puVar38[3] = 0;
      *puVar38 = uVar29;
      uVar25 = 2;
      uVar17 = puVar38[-1];
      pbVar34 = (byte *)puVar38[0x11];
      puVar38[-9] = uVar17 * 2;
      uVar29 = op_ext_b0_u(uVar17 << 1);
      puVar38[-10] = uVar29;
      puVar38[2] = 0;
      puVar38[-0xc] = (uint)puVar16;
      puVar38[-7] = 2;
      puVar38[-8] = (uint)pbVar34;
      puVar38[-0xb] = 0x10;
      break;
    }
    puVar23 = (uint *)uVar20;
    if (pbVar34[1] == 0) {
      uVar17 = *puVar23;
      uVar22 = (uint)*(ushort *)(iVar7 + 0x10);
    }
    else {
      uVar22 = (uint)*(ushort *)(iVar7 + 0x10);
      uVar19 = op_mul_u_prr((uint)(*(ushort *)(iVar7 + 0x10) >> iVar8) / (uint)*pbVar34,32000000);
      uVar19 = op_div_u_ppr(uVar19,puVar23[4]);
      *(int *)(iVar9 + 0x18) = (int)uVar19 + *(int *)(iVar7 + 0x18);
      uVar17 = *puVar23;
      sVar5 = func_0x0bfc7640(uVar17);
      *(short *)(iVar9 + 0x16) =
           sVar5 - (short)*(undefined4 *)(*(int *)(*(int *)((int)uVar20 + 4) + 0x18) + 0x14);
      *(uint *)(iVar9 + 8) = *(uint *)(iVar9 + 8) | 200;
    }
    *(char *)((int)piVar35 + 0x20) = (char)uVar29;
    *(uint *)(puVar30 + 4) = uVar22;
    *(uint *)(puVar30 + 8) = (uint)*(ushort *)(iVar7 + 0x12);
    *(uint *)(puVar30 + 0xc) = (uint)*(ushort *)(iVar7 + 0x14);
    *(undefined4 *)(puVar30 + 0x10) = *(undefined4 *)(iVar7 + 0x20);
    *(char *)((int)piVar35 + 0xc) = (char)uVar29;
    iVar12 = (int)((ulonglong)uVar20 >> 0x20);
    *(undefined4 *)(iVar12 + 4) = uVar29;
    *(undefined4 *)(iVar12 + 8) = uVar29;
    *(uint *)(iVar12 + 0xc) = (uint)*(ushort *)(iVar9 + 0x14);
    *(uint *)(iVar12 + 0x10) = uVar17;
    func_0x0bfc7652();
    uVar27 = *(ushort *)(puVar30 + 4);
    *(ushort *)(iVar7 + 0x10) = uVar27;
    uVar22 = *(uint *)((int)((ulonglong)uVar20 >> 0x20) + 8);
    *(short *)(iVar9 + 0x12) = (short)uVar22;
    puVar16 = (undefined1 *)(uint)*(ushort *)(iVar7 + 0x12);
    if ((undefined1 *)(uint)uVar27 == puVar16) {
      FUN_0608be7e(iVar7);
      *(undefined4 *)((int)uVar20 + 8) = uVar29;
      uVar22 = (uint)*(ushort *)(iVar9 + 0x12);
    }
    iVar7 = op_ext_l_u(uVar22);
    if (iVar7 != 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_0608c0b2(*(undefined4 *)(*(int *)((int)uVar20 + 4) + 0x18));
    }
    FUN_0608be7e(iVar9);
  } while( true );
LAB_0608e326:
  if (puVar16 == (undefined1 *)0x0) {
LAB_0608e344:
    do {
      op_pop_pc_rl();
    } while( true );
  }
  while( true ) {
    iVar33 = 1;
    if (*(char *)(iVar8 + 5) != '\0') {
      iVar33 = 2;
    }
    iVar12 = 1;
    if (*(char *)(iVar9 + 9) != '\0') {
      iVar12 = 2;
    }
    uVar14 = ((uint)((int)puVar16 >> iVar12) / uVar17) * uVar22 << iVar33;
    if (iVar7 == 0) {
      op_ext_l_u(uVar14);
      iVar33 = FUN_0608bf56(iVar8);
      if (iVar33 != 0) goto LAB_0608e1dc;
      goto LAB_0608e344;
    }
    iVar33 = *(int *)(iVar7 + 0x10);
    if ((iVar33 == 0) && (iVar33 = FUN_0608bf56(iVar8), iVar33 == 0)) goto LAB_0608e344;
    uVar10 = (uint)*(ushort *)(iVar33 + 0x14) - (uint)*(ushort *)(iVar33 + 0x12);
    if ((int)uVar14 <= (int)uVar10) goto LAB_0608e1dc;
    if ((uint)*(ushort *)(iVar33 + 0x12) < (uint)*(ushort *)(iVar7 + 2)) break;
    func_0x0bfb61c0(uVar32);
  }
  uVar14 = uVar10;
LAB_0608e1dc:
  uVar10 = (uVar14 / uVar25) / uVar22;
  if (*(int *)((int)puVar39 + 0x3c) == 1) {
    iVar9 = *(int *)(iVar33 + 0x20) + (uint)*(ushort *)(iVar33 + 0x12);
    iVar12 = iVar9 + uVar14 + uVar10 * uVar22 * -2;
    puVar15 = (undefined2 *)(*(int *)((int)puVar39 + 0x40) + *(int *)((int)puVar39 + 0x34));
    *(int *)((int)puVar39 + 0x2c) = iVar9;
    *(uint *)((int)puVar39 + 0x28) = uVar10 * uVar22;
    if (*(int *)((int)puVar39 + 0x38) == 0) {
      for (iVar9 = 0; iVar9 < (int)uVar10; iVar9 = iVar9 + 1) {
        uVar1 = *puVar15;
        puVar15 = puVar15 + 2;
        *(undefined2 *)(iVar12 + iVar9 * 2) = uVar1;
      }
    }
    else if (*(int *)((int)puVar39 + 0x1c) == 0) {
      uVar29 = op_ext_l_u(uVar10 << 1);
      func_0x0bfc81aa(iVar12,uVar29);
    }
    *(undefined8 *)((int)puVar39 + 0x20) = 0;
    puVar26 = *(undefined4 **)((int)puVar39 + 0x2c);
    puVar11 = (ushort *)(iVar33 + 0x12);
    iVar9 = *(int *)((int)puVar39 + 0x28);
    do {
      rep_unspec(0xc,iVar9);
      uVar29 = op_shl3_rr(8);
      *puVar26 = uVar29;
      puVar26 = puVar26 + 1;
    } while (iVar9 != 0);
    puVar16 = puVar16 + -(*(int *)((int)puVar39 + 0xc) * uVar10);
    *(uint *)((int)puVar39 + 0x40) =
         *(int *)((int)puVar39 + 0x40) + *(int *)((int)puVar39 + 0xc) * uVar10;
    uVar25 = *(uint *)((int)puVar39 + 0x18);
    pbVar34 = *(byte **)((int)puVar39 + 0x14);
    iVar9 = *(int *)((int)puVar39 + 8);
    uVar17 = *(uint *)((int)puVar39 + 0x30);
  }
  else if (*(int *)((int)puVar39 + 0x3c) == 2) {
    puVar11 = (ushort *)(iVar33 + 0x12);
  }
  else {
    puVar26 = (undefined4 *)(*(int *)((int)puVar39 + 0x34) + *(int *)((int)puVar39 + 0x40));
    iVar12 = (uint)*(ushort *)(iVar33 + 0x12) + *(int *)(iVar33 + 0x20);
    if (*(int *)((int)puVar39 + 0x38) == 0) {
      if (*(char *)(iVar9 + 9) == '\x01') {
        for (iVar18 = 0; iVar18 < (int)uVar10; iVar18 = iVar18 + 1) {
          uVar29 = *puVar26;
          puVar26 = puVar26 + 2;
          *(undefined4 *)(iVar12 + iVar18 * 4) = uVar29;
        }
      }
      else {
        for (iVar18 = 0; iVar18 < (int)uVar10; iVar18 = iVar18 + 1) {
          uVar1 = *(undefined2 *)puVar26;
          puVar26 = puVar26 + 1;
          *(undefined2 *)(iVar12 + iVar18 * 2) = uVar1;
        }
      }
    }
    else if (*(int *)((int)puVar39 + 0x1c) == 0) {
      op_ext_l_u(uVar10 * uVar25);
      if (*(char *)(iVar9 + 9) == '\x01') {
        func_0x0bfc8166();
      }
      else {
        func_0x0bfc81aa();
      }
    }
    else {
      func_0x05f9ac62(uVar14);
    }
    puVar11 = (ushort *)(iVar33 + 0x12);
    puVar16 = puVar16 + -(*(int *)((int)puVar39 + 0x10) * uVar10);
    *(uint *)((int)puVar39 + 0x40) =
         *(int *)((int)puVar39 + 0x40) + *(int *)((int)puVar39 + 0x10) * uVar10;
  }
  uVar27 = *puVar11;
  *puVar11 = (ushort)(uVar27 + uVar14);
  if (pbVar34 != (byte *)0x0) {
    *(uint *)(iVar33 + 8) = *(uint *)(iVar33 + 8) | (uint)*pbVar34;
  }
  if (iVar7 == 0) {
    func_0x0bfb5efc(uVar32);
    *(char *)(iVar9 + 1) = *(char *)(iVar9 + 1) + '\x01';
    goto LAB_0608e344;
  }
  uVar14 = op_ext_l_u(uVar27 + uVar14);
  if (uVar14 == *(ushort *)(iVar33 + 0x14)) {
    func_0x0bfb61c0(uVar32);
  }
  else {
    *(int *)(iVar7 + 0x10) = iVar33;
  }
  goto LAB_0608e326;
}


// ===== FUN_0608da58 @ 0608da58

/* WARNING: Heritage AFTER dead removal. Example location: r0x00000014 : 0x0608dea2 */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_0608da58(void)

{
  byte bVar1;
  undefined2 uVar2;
  byte bVar3;
  undefined1 uVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  ushort *puVar9;
  int iVar10;
  undefined8 in_r0_r1;
  undefined1 *extraout_r1;
  ulonglong uVar11;
  uint uVar12;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined2 *puVar13;
  undefined1 *puVar14;
  uint uVar15;
  int iVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  uint uVar19;
  uint *puVar20;
  longlong lVar21;
  int *piVar22;
  uint uVar23;
  undefined4 *puVar24;
  ushort uVar25;
  int *piVar26;
  int *piVar27;
  undefined4 uVar28;
  undefined1 *puVar29;
  undefined1 *puVar30;
  undefined4 uVar31;
  int iVar32;
  int iVar33;
  byte *pbVar34;
  BADSPACEBASE *in_sp;
  int *piVar35;
  int *piVar36;
  undefined1 *puVar37;
  uint *puVar38;
  undefined4 *puVar39;
  
  op_push_rets_rl();
  func_0x0bfb34d8();
  iVar7 = (int)((ulonglong)in_r0_r1 >> 0x20);
  iVar6 = 1;
  if (*(char *)(iVar7 + 0xc) != '\0') {
    iVar6 = 2;
  }
  bVar1 = *(byte *)((int)in_r0_r1 + 4);
  uVar15 = (uint)bVar1;
  iVar6 = (int)((uint)*(ushort *)(iVar7 + 0x12) - (uint)*(ushort *)(iVar7 + 0x10)) >> iVar6;
  if (bVar1 >> 4 == 2) {
    iVar6 = iVar6 >> 1;
  }
  else {
    iVar6 = iVar6 >> 2;
  }
  puVar14 = (undefined1 *)0x2710;
  uVar19 = (uint)(iVar6 * 10000) / *(uint *)((int)in_r0_r1 + 0x10);
  func_0x0bfb34e2();
  op_pop_pc_rl();
  op_push_rets_rl();
  piVar22 = *(int **)(uVar19 + 0x14);
  piVar27 = piVar22 + 4;
  piVar26 = piVar22 + 0x1a;
  if ((*(char *)((int)piVar22 + 0x15) == '\0') || (*(char *)((int)piVar22 + 0x69) != '\0')) {
    puVar29 = extraout_r1;
    if (piVar22[0x1e] == 0) {
      if (piVar22[0x1d] == 0) {
        func_0x0bfb62a2();
        uVar19 = FUN_0608d9d8(*(undefined4 *)(*(int *)(*piVar22 + 0x18) + 0x2c));
        lVar21 = (ulonglong)uVar19 << 0x20;
        func_0x0bfb62ac();
        if (lVar21 < 0) goto code_r0x0608dbbe;
        func_0x0bfb620e(piVar22);
        *puVar29 = (char)piVar27[1];
      }
      else {
        iVar6 = func_0x0bfb5ebe();
        if (iVar6 != 0) {
          func_0x0bfb620e(piVar22);
        }
        iVar6 = func_0x0bfb611a(piVar22);
        if (iVar6 != 1) goto code_r0x0608dbbe;
        if ((*(int *)(*(int *)(puVar29 + 0x18) + 0x54) != 0) &&
           (puVar14 = *(undefined1 **)(puVar29 + 0x14),
           puVar14 == *(undefined1 **)(*(int *)(puVar29 + 0x18) + 0x50))) {
          FUN_060878c8();
        }
      }
    }
    else {
      iVar6 = func_0x0bfb611a(piVar22);
      if (iVar6 == 1) {
        uVar15 = *(uint *)(*(int *)(puVar29 + 0x18) + 0x54);
        if ((uVar15 != 0) && (*(int *)(puVar29 + 0x14) == *(int *)(*(int *)(puVar29 + 0x18) + 0x50))
           ) {
          iVar6 = func_0x0bfb5ebe();
          if (iVar6 == 0) {
            FUN_060878c8();
          }
          else {
            *(undefined1 *)(piVar26[4] + 1) = 1;
          }
        }
      }
      iVar6 = *(int *)(*(int *)(puVar29 + 0x18) + 0x54);
      FUN_06087a88();
      iVar7 = 2;
      if (iVar6 == 0) {
        iVar7 = 1;
      }
      for (uVar19 = (uint)*(byte *)piVar26[4]; (int)uVar19 < iVar7; uVar19 = uVar19 + 1) {
        FUN_060878c8();
      }
code_r0x0608dbbe:
      *(uint *)(puVar29 + 0x10) = *(uint *)(puVar29 + 0x10) | 0xe00;
    }
    uVar11 = (ulonglong)*(byte *)((int)piVar27 + 7);
    if (*(byte *)((int)piVar27 + 7) == 0) goto LAB_0608dbd2;
    uVar11 = CONCAT44(0x20,puVar29 + 0x10);
  }
  else {
    uVar11 = CONCAT44(0x80,*piVar22 + 0xc);
  }
  *(uint *)uVar11 = *(uint *)uVar11 | (uint)(uVar11 >> 0x20);
LAB_0608dbd2:
  op_pop_pc_rl();
  op_push_rets_rl();
  piVar35 = (int *)((int)in_sp + -0x48);
  iVar32 = 2;
  iVar7 = (int)uVar11;
  iVar6 = *(int *)(iVar7 + 0x14);
  pbVar34 = (byte *)(iVar6 + 0x14);
  if (*(char *)(iVar6 + 0x21) == '\0') {
    iVar32 = 1;
  }
  iVar33 = 8 << iVar32;
  uVar18 = CONCAT44((undefined1 *)((int)in_sp + -0x3c),iVar6);
  puVar29 = (undefined1 *)((int)in_sp + -0x28);
  puVar30 = (undefined1 *)((int)in_sp + -0x14);
  uVar28 = 0;
  *(undefined1 **)((int)in_sp + -0x48) = (undefined1 *)((int)in_sp + -0xc);
  *(int *)((int)in_sp + -0x40) = iVar7;
  *(undefined4 *)((int)in_sp + -0x44) = *(undefined4 *)(iVar7 + 0x18);
  do {
    while (iVar6 = *(int *)((int)uVar18 + 8), iVar6 == 0) {
      iVar6 = FUN_0608c0f4(*(undefined4 *)((int)piVar35 + 8));
      if (iVar6 == 0) goto LAB_0608de9a;
      iVar7 = (int)uVar18;
      *(int *)(iVar7 + 8) = iVar6;
      if ((*(uint *)(iVar6 + 8) & 0x100) == 0) {
        uVar19 = (uint)*(ushort *)(iVar6 + 0x16) +
                 *(int *)(*(int *)(*(int *)(*(int *)(iVar7 + 4) + 0x14) + 0x1c) + 0x14);
        *(int *)(iVar6 + 0x18) = *(int *)(iVar6 + 0x18) + *(int *)(iVar7 + 0x3c) * 0x20;
      }
      else {
        uVar19 = func_0x0bfb6642(iVar7);
        func_0x0bfb6770((int)uVar18,uVar19);
        iVar7 = *(int *)(iVar6 + 0x18);
        iVar10 = (int)uVar18;
        *(int *)(iVar10 + 0xc) = iVar7;
        if (*(short *)(*(int *)(*(int *)(iVar10 + 4) + 0x2c) + 4) == -0xf7) {
          iVar16 = 2;
          if (*(char *)(*(int *)(*(int *)(iVar10 + 4) + 0x18) + 5) == '\0') {
            iVar16 = 1;
          }
          iVar7 = (iVar7 - (((uint)(*(ushort *)(iVar6 + 0x12) >> iVar16) / (uint)*pbVar34) * 1000000
                           ) / uVar19) + *(int *)(iVar10 + 0x3c);
        }
        else {
          iVar7 = iVar7 + *(int *)(iVar10 + 0x3c);
        }
        *(int *)(iVar6 + 0x18) = iVar7 << 5;
      }
      if ((pbVar34[1] != 0) || ((*(ushort *)(iVar6 + 8) & 0xf84) == 0)) {
LAB_0608ddfe:
        if ((*(ushort *)(iVar6 + 8) & 0xf84) != 0) {
          func_0x0bfc7598(*(undefined4 *)uVar18);
          if (((undefined4 *)uVar18)[4] != uVar19) {
            func_0x0bfc75f4(*(undefined4 *)uVar18);
            *(uint *)((int)uVar18 + 0x10) = uVar19;
          }
        }
        break;
      }
      *(undefined4 *)(*piVar35 + 8) = uVar28;
      *(undefined8 *)(puVar30 + 8) = 0;
      piVar35[0xd] = 4;
      *(undefined4 *)(puVar30 + 4) = 0x3ff;
      func_0x0bfb3f7c(piVar35[1]);
      puVar14 = (undefined1 *)((int)piVar35 + 0x34);
      func_0x0bfb377e();
      bVar1 = pbVar34[4];
      if (bVar1 != 1) {
        uVar15 = *(uint *)(iVar6 + 0x18);
LAB_0608ddc8:
        pbVar34[1] = 1;
        *(undefined4 *)((int)piVar35 + 0x34) = 2;
        *(undefined4 *)(puVar30 + 4) = *(undefined4 *)uVar18;
        *(uint *)(puVar30 + 8) = uVar15;
        *(uint *)(puVar30 + 0xc) = (uint)bVar1;
        func_0x0bfc746a(1);
        func_0x0bfb3518(*(undefined4 *)(*(int *)(*(int *)((int)piVar35 + 4) + 0x18) + 0x2c));
        goto LAB_0608ddfe;
      }
      if (*(int *)(puVar30 + 4) != 0) {
        func_0x0bfb683e(1);
      }
      uVar15 = *(uint *)(iVar6 + 0x18);
      iVar7 = func_0x0bfb6862();
      bVar1 = pbVar34[4];
      if (iVar7 != 0) goto LAB_0608ddc8;
      func_0x0bfb683e(bVar1);
      FUN_0608be7e(iVar6);
      *(undefined4 *)((int)uVar18 + 8) = uVar28;
    }
    uVar19 = (uint)*(ushort *)(iVar6 + 0x10);
    uVar23 = (uint)*(ushort *)(iVar6 + 0x12);
    iVar7 = func_0x0bfc7640(*(undefined4 *)uVar18);
    iVar10 = 4;
    if (pbVar34[0xd] == 0) {
      iVar10 = 2;
    }
    uVar12 = iVar10 * (uint)*pbVar34;
    uVar15 = *(uint *)((int)uVar18 + 4);
    puVar14 = (undefined1 *)
              ((((((iVar7 * (uVar23 - uVar19)) / *(uint *)((int)uVar18 + 0x10)) * 6) / 5 +
                 (uint)*pbVar34 * iVar33 + uVar12) - 1) / uVar12);
    op_ext_l_u(uVar12 * (int)puVar14);
    iVar7 = FUN_0608bf56();
    if (iVar7 == 0) {
LAB_0608de9a:
      op_pop_pc_rl();
      op_push_rets_rl();
      piVar36 = (int *)((int)piVar35 + 0x3c);
      iVar6 = *(int *)(_uRam00000014 + 0x18);
      iVar7 = iRam00000018;
      piVar22 = (int *)((int)piVar35 + 0x3c);
      iVar32 = _uRam00000014;
      if (iVar6 == 0) {
        iVar6 = FUN_0608c0f4();
        *(int *)(iVar32 + 0x18) = iVar6;
        piVar22 = piVar36;
        if (iVar6 != 0) goto LAB_0608deb8;
      }
      else {
LAB_0608deb8:
        piVar36 = piVar22;
        if (*(int *)(iVar7 + 0x18) != 0) {
          pbVar34 = (byte *)(iVar32 + 0x20);
          iVar33 = *(int *)(iVar32 + 0x10);
          if ((iVar33 == 0) || (*(char *)(iVar32 + 0x23) != '\0')) {
            uVar15 = (uint)*pbVar34;
            puVar14 = (undefined1 *)(uint)*(byte *)(iVar32 + 0x21);
            if (uVar15 == 0) {
              if (puVar14 == (undefined1 *)0x0) goto LAB_0608df5c;
              op_ext_l_u((uint)*(ushort *)(iVar6 + 0x12) << 1);
              iVar6 = FUN_0608bf56();
              if (iVar6 != 0) {
                iVar33 = *(int *)(iVar32 + 0x18);
                *(short *)(iVar6 + 0x12) = *(short *)(iVar33 + 0x12) << 1;
                puVar24 = *(undefined4 **)(iVar6 + 0x20);
                uVar15 = (uint)(*(ushort *)(iVar33 + 0x12) >> 1);
                if (*(char *)(*(int *)(*(int *)(iVar32 + 0x14) + 0x18) + 4) == '\x17') {
                  do {
                    rep_unspec(10,uVar15);
                    uVar28 = op_shl3_rr(8);
                    *puVar24 = uVar28;
                    puVar24 = puVar24 + 1;
                  } while (uVar15 != 0);
                }
                else {
                  func_0x0bfc91da();
                }
LAB_0608dfde:
                uVar28 = *(undefined4 *)(iVar7 + 0x18);
LAB_0608dfe4:
                    /* WARNING: Subroutine does not return */
                thunk_FUN_0608c0b2(uVar28);
              }
            }
            else {
              if (puVar14 != (undefined1 *)0x0) {
LAB_0608df5c:
                    /* WARNING: Subroutine does not return */
                thunk_FUN_0608c0b2();
              }
              iVar6 = FUN_0608bf56();
              if (iVar6 != 0) {
                iVar33 = *(int *)(iVar32 + 0x18);
                *(ushort *)(iVar6 + 0x12) = *(ushort *)(iVar33 + 0x12) >> 1;
                puVar13 = *(undefined2 **)(iVar6 + 0x20);
                puVar24 = *(undefined4 **)(iVar33 + 0x20);
                uVar15 = (uint)(*(ushort *)(iVar33 + 0x12) >> 2);
                if (*(char *)(*(int *)(*(int *)(iVar32 + 0x14) + 0x18) + 4) == '\x17') {
                  do {
                    rep_unspec(0x10,uVar15);
                    uVar18 = op_mul_mem1_w_i_s(puVar24,4,1);
                    uVar28 = op_shiftr_rpr_mode(uVar18,8);
                    uVar28 = sat16(uVar28);
                    *puVar13 = (short)uVar28;
                    puVar13 = puVar13 + 1;
                  } while (uVar15 != 0);
                }
                else {
                  do {
                    rep_unspec(8,uVar15);
                    uVar28 = *puVar24;
                    puVar24 = puVar24 + 1;
                    uVar28 = sat16(uVar28);
                    *puVar13 = (short)uVar28;
                    puVar13 = puVar13 + 1;
                  } while (uVar15 != 0);
                }
                uVar28 = *(undefined4 *)(iVar7 + 0x18);
                goto LAB_0608dfe4;
              }
            }
          }
          else {
            bVar1 = *pbVar34;
            if (bVar1 != *(byte *)(iVar6 + 0xc)) {
              *pbVar34 = *(byte *)(iVar6 + 0xc);
              piVar36[2] = 1;
              piVar36[1] = 1;
              *piVar36 = iVar33;
              (*pcRam001134b8)();
              bVar1 = *pbVar34;
              iVar6 = *(int *)(iVar32 + 0x18);
            }
            uVar15 = (uint)bVar1;
            puVar14 = (undefined1 *)(uint)*(byte *)(iVar32 + 0x21);
            uVar25 = *(ushort *)(iVar6 + 0x12);
            op_ext_l_u((uint)uVar25);
            iVar6 = FUN_0608bf56();
            if (iVar6 != 0) {
              *(ushort *)(iVar6 + 0x12) = uVar25;
              FUN_0608beb4(*(undefined4 *)(iVar6 + 0x20));
              goto LAB_0608dfde;
            }
          }
        }
      }
      puVar37 = (undefined1 *)((int)piVar36 + 0xc);
      op_pop_pc_rl();
      op_push_rets_rl();
      iVar6 = iRam00000018;
      iVar7 = _uRam00000014;
      iVar32 = FUN_0608c0f4();
      if (iVar32 != 0) {
        if (*(int *)(iVar7 + 0x10) != 0) {
          func_0x0bfc9a80(*(undefined2 *)(iVar32 + 0x12));
        }
                    /* WARNING: Subroutine does not return */
        thunk_FUN_0608c0b2(*(undefined4 *)(iVar6 + 0x18));
      }
      op_pop_pc_rl();
      op_push_rets_rl();
      puVar38 = (uint *)(puVar37 + -0x10);
      puVar24 = (undefined4 *)(_uRam00000014 + 0x10);
      iVar6 = *(int *)(_uRam00000014 + 0x1c);
      puVar29 = puVar37 + -0x10;
      iVar7 = iRam00000018;
      iVar32 = _uRam00000014;
      if (iVar6 == 0) {
        iVar6 = FUN_0608c0f4(0);
        puVar24[3] = iVar6;
        puVar29 = (undefined1 *)puVar38;
        uVar28 = extraout_r1_00;
        if (iVar6 != 0) goto LAB_0608e038;
      }
      else {
LAB_0608e038:
        puVar38 = (uint *)puVar29;
        iVar32 = iVar32 + 0x20;
        if (((*(short *)(puVar24[1] + 2) == -0x4072) && (puVar24[5] == 4)) &&
           ((code *)puVar24[8] != (code *)0x0)) {
          uVar4 = (*(code *)puVar24[8])();
          *(undefined1 *)(iVar32 + 0xc) = uVar4;
          iVar6 = puVar24[3];
        }
        puVar14 = (undefined1 *)(uint)*(byte *)((int)puVar24 + 9);
        uVar28 = *(undefined4 *)(iVar7 + 0x18);
        op_ext_l_u(((uint)*(ushort *)(iVar6 + 0x12) * (uint)*(byte *)(puVar24 + 2)) / (uint)puVar14)
        ;
        iVar6 = FUN_0608bf56(uVar28);
        uVar18 = CONCAT44(iVar6,uVar28);
        uVar28 = extraout_r1_01;
        if (iVar6 != 0) {
          uVar28 = *puVar24;
          uVar31 = *(undefined4 *)(puVar24[3] + 0x20);
          bVar1 = *(byte *)(puVar24 + 2);
          bVar3 = *(byte *)((int)puVar24 + 9);
          uVar4 = *(undefined1 *)(iVar32 + 1);
          puVar38[3] = (uint)*(byte *)(iVar32 + 0xc);
          *(ulonglong *)(puVar38 + 1) = (ulonglong)CONCAT14(uVar4,(uint)bVar3);
          *puVar38 = (uint)bVar1;
          func_0x0bfc8424(uVar28,uVar31);
          *(short *)((int)((ulonglong)uVar18 >> 0x20) + 0x12) = (short)uVar18;
                    /* WARNING: Subroutine does not return */
          thunk_FUN_0608c0b2();
        }
      }
      iVar6 = iRam00000074;
      uVar31 = 0;
      op_pop_pc_rl();
      op_push_rets_rl();
      puVar39 = puVar38 + -0xd;
      if ((((*(byte *)(*(int *)(iRam00000000 + 0x14) + 0xc) & 0xc) != 0) ||
          ((*(byte *)(iRam00000000 + 0xc) & 0x10) != 0)) || (iVar7 = 0x10, 1 < bRam00000011))
      goto LAB_0608e344;
      iVar32 = *(int *)(iRam00000000 + 0x18);
      if ((uRam00000014._1_1_ != '\0') && (cRam00000069 == '\0')) goto LAB_0608e344;
      uVar19 = (uint)(*(byte *)(iVar32 + 8) >> 4);
      puVar38[-1] = uVar15 >> 4;
      if (uVar15 >> 4 == 1) {
        puVar38[1] = 1;
        puVar38[-6] = 1;
        puVar38[-6] = 0;
      }
      else {
        puVar38[-6] = 1;
        puVar38[1] = 1;
        puVar38[1] = 0;
      }
      puVar38[3] = 0;
      *puVar38 = uVar28;
      uVar23 = 2;
      uVar15 = puVar38[-1];
      pbVar34 = (byte *)puVar38[0x11];
      puVar38[-9] = uVar15 * 2;
      uVar28 = op_ext_b0_u(uVar15 << 1);
      puVar38[-10] = uVar28;
      puVar38[2] = 0;
      puVar38[-0xc] = (uint)puVar14;
      puVar38[-7] = 2;
      puVar38[-8] = (uint)pbVar34;
      puVar38[-0xb] = 0x10;
      break;
    }
    puVar20 = (uint *)uVar18;
    if (pbVar34[1] == 0) {
      uVar15 = *puVar20;
      uVar19 = (uint)*(ushort *)(iVar6 + 0x10);
    }
    else {
      uVar19 = (uint)*(ushort *)(iVar6 + 0x10);
      uVar17 = op_mul_u_prr((uint)(*(ushort *)(iVar6 + 0x10) >> iVar32) / (uint)*pbVar34,32000000);
      uVar17 = op_div_u_ppr(uVar17,puVar20[4]);
      *(int *)(iVar7 + 0x18) = (int)uVar17 + *(int *)(iVar6 + 0x18);
      uVar15 = *puVar20;
      sVar5 = func_0x0bfc7640(uVar15);
      *(short *)(iVar7 + 0x16) =
           sVar5 - (short)*(undefined4 *)(*(int *)(*(int *)((int)uVar18 + 4) + 0x18) + 0x14);
      *(uint *)(iVar7 + 8) = *(uint *)(iVar7 + 8) | 200;
    }
    *(char *)((int)piVar35 + 0x20) = (char)uVar28;
    *(uint *)(puVar29 + 4) = uVar19;
    *(uint *)(puVar29 + 8) = (uint)*(ushort *)(iVar6 + 0x12);
    *(uint *)(puVar29 + 0xc) = (uint)*(ushort *)(iVar6 + 0x14);
    *(undefined4 *)(puVar29 + 0x10) = *(undefined4 *)(iVar6 + 0x20);
    *(char *)((int)piVar35 + 0xc) = (char)uVar28;
    iVar10 = (int)((ulonglong)uVar18 >> 0x20);
    *(undefined4 *)(iVar10 + 4) = uVar28;
    *(undefined4 *)(iVar10 + 8) = uVar28;
    *(uint *)(iVar10 + 0xc) = (uint)*(ushort *)(iVar7 + 0x14);
    *(uint *)(iVar10 + 0x10) = uVar15;
    func_0x0bfc7652();
    uVar25 = *(ushort *)(puVar29 + 4);
    *(ushort *)(iVar6 + 0x10) = uVar25;
    uVar19 = *(uint *)((int)((ulonglong)uVar18 >> 0x20) + 8);
    *(short *)(iVar7 + 0x12) = (short)uVar19;
    puVar14 = (undefined1 *)(uint)*(ushort *)(iVar6 + 0x12);
    if ((undefined1 *)(uint)uVar25 == puVar14) {
      FUN_0608be7e(iVar6);
      *(undefined4 *)((int)uVar18 + 8) = uVar28;
      uVar19 = (uint)*(ushort *)(iVar7 + 0x12);
    }
    iVar6 = op_ext_l_u(uVar19);
    if (iVar6 != 0) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_0608c0b2(*(undefined4 *)(*(int *)((int)uVar18 + 4) + 0x18));
    }
    FUN_0608be7e(iVar7);
  } while( true );
LAB_0608e326:
  if (puVar14 == (undefined1 *)0x0) {
LAB_0608e344:
    do {
      op_pop_pc_rl();
    } while( true );
  }
  while( true ) {
    iVar33 = 1;
    if (*(char *)(iVar32 + 5) != '\0') {
      iVar33 = 2;
    }
    iVar10 = 1;
    if (*(char *)(iVar7 + 9) != '\0') {
      iVar10 = 2;
    }
    uVar12 = ((uint)((int)puVar14 >> iVar10) / uVar15) * uVar19 << iVar33;
    if (iVar6 == 0) {
      op_ext_l_u(uVar12);
      iVar33 = FUN_0608bf56(iVar32);
      if (iVar33 != 0) goto LAB_0608e1dc;
      goto LAB_0608e344;
    }
    iVar33 = *(int *)(iVar6 + 0x10);
    if ((iVar33 == 0) && (iVar33 = FUN_0608bf56(iVar32), iVar33 == 0)) goto LAB_0608e344;
    uVar8 = (uint)*(ushort *)(iVar33 + 0x14) - (uint)*(ushort *)(iVar33 + 0x12);
    if ((int)uVar12 <= (int)uVar8) goto LAB_0608e1dc;
    if ((uint)*(ushort *)(iVar33 + 0x12) < (uint)*(ushort *)(iVar6 + 2)) break;
    func_0x0bfb61c0(uVar31);
  }
  uVar12 = uVar8;
LAB_0608e1dc:
  uVar8 = (uVar12 / uVar23) / uVar19;
  if (*(int *)((int)puVar39 + 0x3c) == 1) {
    iVar7 = *(int *)(iVar33 + 0x20) + (uint)*(ushort *)(iVar33 + 0x12);
    iVar10 = iVar7 + uVar12 + uVar8 * uVar19 * -2;
    puVar13 = (undefined2 *)(*(int *)((int)puVar39 + 0x40) + *(int *)((int)puVar39 + 0x34));
    *(int *)((int)puVar39 + 0x2c) = iVar7;
    *(uint *)((int)puVar39 + 0x28) = uVar8 * uVar19;
    if (*(int *)((int)puVar39 + 0x38) == 0) {
      for (iVar7 = 0; iVar7 < (int)uVar8; iVar7 = iVar7 + 1) {
        uVar2 = *puVar13;
        puVar13 = puVar13 + 2;
        *(undefined2 *)(iVar10 + iVar7 * 2) = uVar2;
      }
    }
    else if (*(int *)((int)puVar39 + 0x1c) == 0) {
      uVar28 = op_ext_l_u(uVar8 << 1);
      func_0x0bfc81aa(iVar10,uVar28);
    }
    *(undefined8 *)((int)puVar39 + 0x20) = 0;
    puVar24 = *(undefined4 **)((int)puVar39 + 0x2c);
    puVar9 = (ushort *)(iVar33 + 0x12);
    iVar7 = *(int *)((int)puVar39 + 0x28);
    do {
      rep_unspec(0xc,iVar7);
      uVar28 = op_shl3_rr(8);
      *puVar24 = uVar28;
      puVar24 = puVar24 + 1;
    } while (iVar7 != 0);
    puVar14 = puVar14 + -(*(int *)((int)puVar39 + 0xc) * uVar8);
    *(uint *)((int)puVar39 + 0x40) =
         *(int *)((int)puVar39 + 0x40) + *(int *)((int)puVar39 + 0xc) * uVar8;
    uVar23 = *(uint *)((int)puVar39 + 0x18);
    pbVar34 = *(byte **)((int)puVar39 + 0x14);
    iVar7 = *(int *)((int)puVar39 + 8);
    uVar15 = *(uint *)((int)puVar39 + 0x30);
  }
  else if (*(int *)((int)puVar39 + 0x3c) == 2) {
    puVar9 = (ushort *)(iVar33 + 0x12);
  }
  else {
    puVar24 = (undefined4 *)(*(int *)((int)puVar39 + 0x34) + *(int *)((int)puVar39 + 0x40));
    iVar10 = (uint)*(ushort *)(iVar33 + 0x12) + *(int *)(iVar33 + 0x20);
    if (*(int *)((int)puVar39 + 0x38) == 0) {
      if (*(char *)(iVar7 + 9) == '\x01') {
        for (iVar16 = 0; iVar16 < (int)uVar8; iVar16 = iVar16 + 1) {
          uVar28 = *puVar24;
          puVar24 = puVar24 + 2;
          *(undefined4 *)(iVar10 + iVar16 * 4) = uVar28;
        }
      }
      else {
        for (iVar16 = 0; iVar16 < (int)uVar8; iVar16 = iVar16 + 1) {
          uVar2 = *(undefined2 *)puVar24;
          puVar24 = puVar24 + 1;
          *(undefined2 *)(iVar10 + iVar16 * 2) = uVar2;
        }
      }
    }
    else if (*(int *)((int)puVar39 + 0x1c) == 0) {
      op_ext_l_u(uVar8 * uVar23);
      if (*(char *)(iVar7 + 9) == '\x01') {
        func_0x0bfc8166();
      }
      else {
        func_0x0bfc81aa();
      }
    }
    else {
      func_0x05f9ac62(uVar12);
    }
    puVar9 = (ushort *)(iVar33 + 0x12);
    puVar14 = puVar14 + -(*(int *)((int)puVar39 + 0x10) * uVar8);
    *(uint *)((int)puVar39 + 0x40) =
         *(int *)((int)puVar39 + 0x40) + *(int *)((int)puVar39 + 0x10) * uVar8;
  }
  uVar25 = *puVar9;
  *puVar9 = (ushort)(uVar25 + uVar12);
  if (pbVar34 != (byte *)0x0) {
    *(uint *)(iVar33 + 8) = *(uint *)(iVar33 + 8) | (uint)*pbVar34;
  }
  if (iVar6 == 0) {
    func_0x0bfb5efc(uVar31);
    *(char *)(iVar7 + 1) = *(char *)(iVar7 + 1) + '\x01';
    goto LAB_0608e344;
  }
  uVar12 = op_ext_l_u(uVar25 + uVar12);
  if (uVar12 == *(ushort *)(iVar33 + 0x14)) {
    func_0x0bfb61c0(uVar31);
  }
  else {
    *(int *)(iVar6 + 0x10) = iVar33;
  }
  goto LAB_0608e326;
}


// ===== FUN_0608e0b6 @ 0608e0b6

void FUN_0608e0b6(int param_1,uint param_2,byte *param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  int iVar6;
  undefined8 in_r0_r1;
  undefined2 *puVar7;
  undefined4 *puVar8;
  undefined2 uVar9;
  ushort uVar10;
  undefined4 uVar11;
  uint uVar12;
  int *piVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  BADSPACEBASE *in_sp;
  undefined1 *puVar20;
  undefined1 auStack_44 [4];
  int iStack_40;
  int *piStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  byte *pbStack_30;
  undefined4 uStack_2c;
  uint uStack_28;
  uint uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  op_push_rets_rl();
  puVar20 = auStack_44;
  piVar2 = (int *)in_r0_r1;
  iVar17 = *piVar2;
  if ((((*(byte *)(*(int *)(iVar17 + 0x14) + 0xc) & 0xc) == 0) &&
      ((*(byte *)(iVar17 + 0xc) & 0x10) == 0)) &&
     (piVar13 = piVar2 + 4, *(byte *)((int)piVar2 + 0x11) < 2)) {
    iVar18 = piVar2[0x1d];
    iVar17 = *(int *)(iVar17 + 0x18);
    if ((*(char *)((int)piVar2 + 0x15) == '\0') || (*(char *)((int)piVar2 + 0x69) != '\0')) {
      uVar9 = (undefined2)(param_2 >> 4);
      uVar10 = (ushort)(param_2 >> 0x14);
      uVar19 = (uint)(*(byte *)(iVar17 + 8) >> 4);
      uVar12 = CONCAT22(uVar10,uVar9);
      uStack_14 = uVar12;
      bVar1 = CONCAT22(uVar10,uVar9) != 1;
      if (bVar1) {
        uStack_28 = 1;
        uStack_c = 0;
      }
      else {
        uStack_c = 1;
        uStack_28 = 0;
      }
      uStack_c = (uint)!bVar1;
      uStack_28 = (uint)bVar1;
      uStack_4 = 0;
      uStack_10 = (int)((ulonglong)in_r0_r1 >> 0x20);
      uVar16 = 2;
      iStack_34 = uVar12 * 2;
      uStack_38 = op_ext_b0_u(uVar12 << 1);
      uStack_8 = 0;
      uStack_2c = 2;
      pbStack_30 = param_3;
      piStack_3c = piVar13;
      iStack_40 = param_1;
      while (param_1 != 0) {
        while( true ) {
          iVar3 = 1;
          if (*(char *)(iVar17 + 5) != '\0') {
            iVar3 = 2;
          }
          iVar6 = 1;
          if (*(char *)((int)piVar13 + 9) != '\0') {
            iVar6 = 2;
          }
          uVar14 = ((uint)(param_1 >> iVar6) / uVar12) * uVar19 << iVar3;
          if (iVar18 == 0) {
            op_ext_l_u(uVar14);
            iVar3 = FUN_0608bf56(iVar17);
            if (iVar3 == 0) goto LAB_0608e344;
            goto LAB_0608e1dc;
          }
          iVar3 = *(int *)(iVar18 + 0x10);
          if ((iVar3 == 0) && (iVar3 = FUN_0608bf56(iVar17), iVar3 == 0)) goto LAB_0608e344;
          uVar4 = (uint)*(ushort *)(iVar3 + 0x14) - (uint)*(ushort *)(iVar3 + 0x12);
          if ((int)uVar14 <= (int)uVar4) goto LAB_0608e1dc;
          if ((uint)*(ushort *)(iVar3 + 0x12) < (uint)*(ushort *)(iVar18 + 2)) break;
          func_0x0bfb61c0(piVar2);
        }
        uVar14 = uVar4;
LAB_0608e1dc:
        uVar4 = (uVar14 / uVar16) / uVar19;
        if (*(int *)(puVar20 + 0x3c) == 1) {
          iVar6 = *(int *)(iVar3 + 0x20) + (uint)*(ushort *)(iVar3 + 0x12);
          iVar15 = iVar6 + uVar14 + uVar4 * uVar19 * -2;
          puVar7 = (undefined2 *)(*(int *)(puVar20 + 0x40) + *(int *)(puVar20 + 0x34));
          *(int *)(puVar20 + 0x2c) = iVar6;
          *(uint *)(puVar20 + 0x28) = uVar4 * uVar19;
          if (*(int *)(puVar20 + 0x38) == 0) {
            for (iVar6 = 0; iVar6 < (int)uVar4; iVar6 = iVar6 + 1) {
              uVar9 = *puVar7;
              puVar7 = puVar7 + 2;
              *(undefined2 *)(iVar15 + iVar6 * 2) = uVar9;
            }
          }
          else if (*(int *)(puVar20 + 0x1c) == 0) {
            uVar11 = op_ext_l_u(uVar4 << 1);
            func_0x0bfc81aa(iVar15,(short)uVar11);
          }
          *(undefined8 *)(puVar20 + 0x20) = 0;
          puVar8 = *(undefined4 **)(puVar20 + 0x2c);
          puVar5 = (ushort *)(iVar3 + 0x12);
          iVar6 = *(int *)(puVar20 + 0x28);
          do {
            rep_unspec(0xc,iVar6);
            uVar11 = op_shl3_rr(8);
            *puVar8 = uVar11;
            puVar8 = puVar8 + 1;
          } while (iVar6 != 0);
          param_1 = param_1 - *(int *)(puVar20 + 0xc) * uVar4;
          *(uint *)(puVar20 + 0x40) = *(int *)(puVar20 + 0x40) + *(int *)(puVar20 + 0xc) * uVar4;
          uVar16 = *(uint *)(puVar20 + 0x18);
          param_3 = *(byte **)(puVar20 + 0x14);
          piVar13 = *(int **)(puVar20 + 8);
          uVar12 = *(uint *)(puVar20 + 0x30);
        }
        else if (*(int *)(puVar20 + 0x3c) == 2) {
          puVar5 = (ushort *)(iVar3 + 0x12);
        }
        else {
          puVar8 = (undefined4 *)(*(int *)(puVar20 + 0x34) + *(int *)(puVar20 + 0x40));
          iVar6 = (uint)*(ushort *)(iVar3 + 0x12) + *(int *)(iVar3 + 0x20);
          if (*(int *)(puVar20 + 0x38) == 0) {
            if (*(char *)((int)piVar13 + 9) == '\x01') {
              for (iVar15 = 0; iVar15 < (int)uVar4; iVar15 = iVar15 + 1) {
                uVar11 = *puVar8;
                puVar8 = puVar8 + 2;
                *(undefined4 *)(iVar6 + iVar15 * 4) = uVar11;
              }
            }
            else {
              for (iVar15 = 0; iVar15 < (int)uVar4; iVar15 = iVar15 + 1) {
                uVar9 = *(undefined2 *)puVar8;
                puVar8 = puVar8 + 1;
                *(undefined2 *)(iVar6 + iVar15 * 2) = uVar9;
              }
            }
          }
          else if (*(int *)(puVar20 + 0x1c) == 0) {
            uVar11 = op_ext_l_u(uVar4 * uVar16);
            if (*(char *)((int)piVar13 + 9) == '\x01') {
              func_0x0bfc8166();
            }
            else {
              func_0x0bfc81aa((short)uVar11);
            }
          }
          else {
            func_0x05f9ac62((short)uVar14);
          }
          puVar5 = (ushort *)(iVar3 + 0x12);
          param_1 = param_1 - *(int *)(puVar20 + 0x10) * uVar4;
          *(uint *)(puVar20 + 0x40) = *(int *)(puVar20 + 0x40) + *(int *)(puVar20 + 0x10) * uVar4;
        }
        uVar10 = *puVar5;
        *puVar5 = (ushort)(uVar10 + uVar14);
        if (param_3 != (byte *)0x0) {
          *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | (uint)*param_3;
        }
        if (iVar18 == 0) {
          func_0x0bfb5efc(piVar2);
          *(char *)((int)piVar13 + 1) = *(char *)((int)piVar13 + 1) + '\x01';
          break;
        }
        uVar14 = op_ext_l_u(uVar10 + uVar14);
        if (uVar14 == *(ushort *)(iVar3 + 0x14)) {
          func_0x0bfb61c0(piVar2);
        }
        else {
          *(int *)(iVar18 + 0x10) = iVar3;
        }
      }
    }
  }
LAB_0608e344:
  do {
    op_pop_pc_rl();
  } while( true );
}


// ===== FUN_0608e354 @ 0608e354

void FUN_0608e354(void)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  
  uVar3 = func_0x0608e34c(0);
  puVar1 = (undefined4 *)(uVar3 >> 0x20);
  op_copex_ppi(uVar3 & 0xffffffff,6);
  uVar2 = op_lsr_pair_i_p(0x20);
  *puVar1 = (int)uVar2;
  *(char *)(puVar1 + 1) = (char)uVar2;
  return;
}


// ===== FUN_0608e35c @ 0608e35c

void FUN_0608e35c(undefined4 *param_1,uint param_2)

{
  undefined8 uVar1;
  
  op_copex_ppi((ulonglong)param_2,6);
  uVar1 = op_lsr_pair_i_p(0x20);
  *param_1 = (int)uVar1;
  *(char *)(param_1 + 1) = (char)uVar1;
  return;
}


// ===== FUN_0608e36e @ 0608e36e

undefined4 FUN_0608e36e(uint param_1)

{
  undefined8 uVar1;
  
  uVar1 = op_copex_ppi((ulonglong)param_1,0x17);
  return (int)uVar1;
}


// ===== FUN_0608e376 @ 0608e376

undefined4 FUN_0608e376(undefined4 param_1)

{
  ulonglong in_r0_r1;
  undefined8 uVar1;
  undefined4 uVar2;
  
  op_push_rets_rl();
  uVar2 = op_ext_b0_u(param_1);
  op_copex_ppi(CONCAT44(uVar2,(int)(in_r0_r1 >> 0x20)),7);
  uVar1 = op_lsr_pair_i_p(0x20);
  *(undefined4 *)in_r0_r1 = (int)uVar1;
  *(char *)((undefined4 *)in_r0_r1 + 1) = (char)uVar1;
  op_pop_pc_rl();
  uVar1 = op_copex_ppi(in_r0_r1 & 0xffffffff,0);
  return (int)((ulonglong)uVar1 >> 0x20);
}


// ===== FUN_0608e546 @ 0608e546

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0608e7e8) overlaps instruction at (ram,0x0608e7e6)
    */
/* WARNING: Possible PIC construction at 0x0608e80c: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0608e80e) */
/* WARNING: Removing unreachable block (ram,0x0608e81a) */
/* WARNING: Removing unreachable block (ram,0x0608e8d8) */
/* WARNING: Removing unreachable block (ram,0x0608e8da) */
/* WARNING: Removing unreachable block (ram,0x0608e7e8) */
/* WARNING: Removing unreachable block (ram,0x0608e8dc) */

void FUN_0608e546(void)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint *puVar8;
  ulonglong uVar7;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  byte *pbVar13;
  int iVar14;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  uint *puVar15;
  undefined1 *puVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  
  op_push_rets_rl();
  func_0x06088f24();
  uVar10 = 0;
  pc_rang_limit1(0,0x7fffffff);
  pc_rang_limit2(0);
  func_0x0608e51e();
  uVar18 = 0xff03c000ff0380;
  for (iVar11 = 0; iVar11 != 7; iVar11 = iVar11 + 1) {
    *(undefined4 *)(iVar11 * 4 + 0xff0300) = uVar10;
    *(undefined4 *)(iVar11 * 4 + 0xff0340) = uVar10;
    *(undefined4 *)(iVar11 * 4 + 0xff0380) = uVar10;
    *(undefined4 *)(iVar11 * 4 + 0xff03c0) = uVar10;
  }
  func_0x0608e532();
  uVar2 = 0xffe200;
  puVar1 = (uint *)(in_cnum * 0x800 + 0xffe200);
  *puVar1 = *puVar1 & 8;
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar11 = 0x1051f8;
  for (uVar12 = 0; uVar12 < 0x41; uVar12 = uVar12 + 1) {
    uVar10 = func_0x05f9ac7a(puVar1);
    uVar18 = CONCAT44((int)((ulonglong)uVar18 >> 0x20),uVar10);
    uVar17 = func_0x05f9ac6a(iVar11,puVar1);
    uVar2 = (uint)uVar17;
    if ((int)((ulonglong)uVar17 >> 0x20) == 0) goto LAB_0608e5da;
    iVar11 = iVar11 + 0x11;
  }
  op_pop_pc_rl();
LAB_0608e5da:
  puVar1 = (uint *)(uint)*(byte *)(iVar11 + 0x10);
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar11 = *(int *)((int)in_sp + 0x14);
  iVar14 = *(int *)((int)in_sp + 0x10);
  if (uVar2 - 0x30 < 3) {
    puVar8 = (uint *)((int)puVar1 * 4 + 0xff0340);
    iVar3 = op_ext_b0_u(uVar2 - 0x30);
    *puVar8 = *puVar8 | (int)uVar18 << (iVar3 << 3);
    uVar2 = (uint)(iVar11 != 0) << iVar3 + 0x11 | (uint)(iVar14 != 0) << iVar3 + 9;
  }
  else if (uVar2 == 0x50) {
    uVar2 = op_insert_rrii((uint)(iVar11 != 0),0x10,1);
  }
  else {
    if (uVar2 != 0x43) goto LAB_0608e660;
    op_insert_rrii((uint)((int)((ulonglong)uVar18 >> 0x20) != 0),2,1);
    uVar2 = op_insert_rrii((uint)(iVar11 != 0),1,1);
  }
  uVar18 = 0xff0300;
  puVar1 = (uint *)((int)puVar1 * 4 + 0xff0300);
  *puVar1 = *puVar1 | uVar2;
LAB_0608e660:
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar15 = (uint *)((int)in_sp + -0x10);
  uVar10 = (undefined4)uVar18;
  puVar16 = (undefined1 *)((int)in_sp + -0x10);
  if (puVar1 < (uint *)0x8) {
    pbVar13 = *(byte **)((int)in_sp + 0x20);
    func_0x0608e51e();
    uVar12 = 0;
    *(undefined4 *)((int)puVar1 * 4 + 0xff0300) = 0;
    *(undefined4 *)((int)puVar1 * 4 + 0xff0340) = 0;
    iVar11 = 0xff0380;
    *(undefined4 *)((int)puVar1 * 4 + 0xff0380) = 0;
    iVar14 = 0xff03c0;
    *(undefined4 *)((int)puVar1 * 4 + 0xff03c0) = 0;
    uVar7 = 0;
    *(undefined1 **)((int)puVar15 + 8) = (undefined1 *)((int)puVar15 + 0x34);
    *(undefined1 **)((int)puVar15 + 0xc) = (undefined1 *)((int)puVar15 + 0x34);
    while( true ) {
      uVar4 = (uint)*pbVar13;
      uVar6 = (undefined4)uVar7;
      uVar9 = (uint)(uVar7 >> 0x20);
      if (uVar4 == 0) break;
      if (uVar4 - 0x30 < 4) {
        puVar15[1] = uVar9 & 1;
        uVar5 = op_ext_b0_u_p(uVar12);
        *puVar15 = uVar9 & 2;
        uVar6 = op_ext_b0_u(uVar6);
        mpu_privilege(puVar1,uVar5,uVar6);
        puVar8 = *(uint **)((int)puVar15 + 0xc);
        *(uint **)((int)puVar15 + 0xc) = puVar8 + 1;
        uVar12 = (uint)*pbVar13;
        uVar7 = (ulonglong)*puVar8;
      }
      else if (uVar4 != 0x78) {
        if (uVar4 == 0x50) {
LAB_0608e6be:
          puVar15[1] = uVar9 & 1;
          uVar5 = op_ext_b0_u_p(uVar12);
          *puVar15 = uVar9 & 2;
          uVar6 = op_ext_b0_u(uVar6);
          mpu_privilege(puVar1,uVar5,uVar6);
          uVar7 = 0;
          uVar12 = (uint)*pbVar13;
        }
        else if (uVar4 == 0x72) {
          uVar7 = uVar7 | 0x200000000;
        }
        else if (uVar4 == 0x77) {
          uVar7 = uVar7 | 0x100000000;
        }
        else if (uVar4 == 0x43) goto LAB_0608e6be;
      }
      pbVar13 = pbVar13 + 1;
    }
    puVar15[1] = uVar9 & 1;
    uVar5 = op_ext_b0_u_p(uVar12);
    *puVar15 = uVar9 & 2;
    uVar6 = op_ext_b0_u(uVar6);
    mpu_privilege(puVar1,uVar5,uVar6);
    *(uint *)(iVar11 + (int)puVar1 * 4) = uVar2;
    *(undefined4 *)(iVar14 + (int)puVar1 * 4) = uVar10;
    puVar1 = (uint *)func_0x0608e532();
    puVar16 = (undefined1 *)puVar15;
  }
  op_pop_pc_rl();
  *(undefined4 *)(puVar16 + 0xc) = unaff_retaddr;
  uVar7 = ZEXT48(puVar1);
  func_0x0608e51e();
  iVar11 = (int)uVar7;
  *(undefined4 *)(iVar11 * 4 + 0xff0300) = 0;
  *(undefined4 *)(iVar11 * 4 + 0xff0340) = 0;
  *(undefined4 *)(iVar11 * 4 + 0xff0380) = 0;
  *(undefined4 *)(iVar11 * 4 + 0xff03c0) = 0;
  uVar18 = func_0x0608e532();
  do {
    uVar10 = (undefined4)uVar18;
    op_push_rets_rl();
    uVar6 = (undefined4)uVar7;
    if ((int)((ulonglong)uVar18 >> 0x20) != 0) {
      *(undefined4 *)(in_cnum * 0x800 + 0xffe208) = uVar6;
      uVar6 = 0x3ff883;
      *(undefined4 *)(in_cnum * 0x800 + 0xffe20c) = uVar10;
      uVar10 = 0x3ff882;
      op_pop_pc_rl();
    }
    *(undefined4 *)(in_cnum * 0x800 + 0xffe210) = uVar6;
    *(undefined4 *)(in_cnum * 0x800 + 0xffe214) = uVar10;
    op_pop_pc_rl();
    op_push_rets_rl();
    *(undefined4 *)(in_cnum * 0x800 + 0xffe200) = 0xe0000007;
    *(undefined4 *)(in_cnum * 0x800 + 0xffe1c0) = 1;
    uVar7 = 0x103840;
    uVar18 = 0x100102840;
  } while( true );
}


// ===== FUN_0608e5aa @ 0608e5aa

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0608e7e8) overlaps instruction at (ram,0x0608e7e6)
    */
/* WARNING: Possible PIC construction at 0x0608e80c: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0608e80e) */
/* WARNING: Removing unreachable block (ram,0x0608e81a) */
/* WARNING: Removing unreachable block (ram,0x0608e8d8) */
/* WARNING: Removing unreachable block (ram,0x0608e8da) */
/* WARNING: Removing unreachable block (ram,0x0608e7e8) */
/* WARNING: Removing unreachable block (ram,0x0608e8dc) */

void FUN_0608e5aa(undefined4 param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 in_r2_r3;
  uint *puVar8;
  ulonglong uVar7;
  uint uVar9;
  int iVar10;
  uint uVar11;
  byte *pbVar12;
  int iVar13;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  uint *puVar14;
  undefined1 *puVar15;
  undefined8 uVar16;
  
  op_push_rets_rl();
  iVar10 = 0x1051f8;
  for (uVar11 = 0; uVar11 < 0x41; uVar11 = uVar11 + 1) {
    uVar5 = func_0x05f9ac7a(param_1);
    in_r2_r3 = CONCAT44((int)((ulonglong)in_r2_r3 >> 0x20),uVar5);
    uVar16 = func_0x05f9ac6a(iVar10,param_1);
    param_2 = (uint)uVar16;
    if ((int)((ulonglong)uVar16 >> 0x20) == 0) goto LAB_0608e5da;
    iVar10 = iVar10 + 0x11;
  }
  op_pop_pc_rl();
LAB_0608e5da:
  puVar1 = (uint *)(uint)*(byte *)(iVar10 + 0x10);
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar10 = *(int *)((int)in_sp + 0x14);
  iVar13 = *(int *)((int)in_sp + 0x10);
  if (param_2 - 0x30 < 3) {
    puVar8 = (uint *)((int)puVar1 * 4 + 0xff0340);
    iVar2 = op_ext_b0_u(param_2 - 0x30);
    *puVar8 = *puVar8 | (int)in_r2_r3 << (iVar2 << 3);
    param_2 = (uint)(iVar10 != 0) << iVar2 + 0x11 | (uint)(iVar13 != 0) << iVar2 + 9;
  }
  else if (param_2 == 0x50) {
    param_2 = op_insert_rrii((uint)(iVar10 != 0),0x10,1);
  }
  else {
    if (param_2 != 0x43) goto LAB_0608e660;
    op_insert_rrii((uint)((int)((ulonglong)in_r2_r3 >> 0x20) != 0),2,1);
    param_2 = op_insert_rrii((uint)(iVar10 != 0),1,1);
  }
  in_r2_r3 = 0xff0300;
  puVar1 = (uint *)((int)puVar1 * 4 + 0xff0300);
  *puVar1 = *puVar1 | param_2;
LAB_0608e660:
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar14 = (uint *)((int)in_sp + -0x10);
  uVar5 = (undefined4)in_r2_r3;
  puVar15 = (undefined1 *)((int)in_sp + -0x10);
  if (puVar1 < (uint *)0x8) {
    pbVar12 = *(byte **)((int)in_sp + 0x20);
    func_0x0608e51e();
    uVar11 = 0;
    *(undefined4 *)((int)puVar1 * 4 + 0xff0300) = 0;
    *(undefined4 *)((int)puVar1 * 4 + 0xff0340) = 0;
    iVar10 = 0xff0380;
    *(undefined4 *)((int)puVar1 * 4 + 0xff0380) = 0;
    iVar13 = 0xff03c0;
    *(undefined4 *)((int)puVar1 * 4 + 0xff03c0) = 0;
    uVar7 = 0;
    *(undefined1 **)((int)puVar14 + 8) = (undefined1 *)((int)puVar14 + 0x34);
    *(undefined1 **)((int)puVar14 + 0xc) = (undefined1 *)((int)puVar14 + 0x34);
    while( true ) {
      uVar3 = (uint)*pbVar12;
      uVar6 = (undefined4)uVar7;
      uVar9 = (uint)(uVar7 >> 0x20);
      if (uVar3 == 0) break;
      if (uVar3 - 0x30 < 4) {
        puVar14[1] = uVar9 & 1;
        uVar4 = op_ext_b0_u_p(uVar11);
        *puVar14 = uVar9 & 2;
        uVar6 = op_ext_b0_u(uVar6);
        mpu_privilege(puVar1,uVar4,uVar6);
        puVar8 = *(uint **)((int)puVar14 + 0xc);
        *(uint **)((int)puVar14 + 0xc) = puVar8 + 1;
        uVar11 = (uint)*pbVar12;
        uVar7 = (ulonglong)*puVar8;
      }
      else if (uVar3 != 0x78) {
        if (uVar3 == 0x50) {
LAB_0608e6be:
          puVar14[1] = uVar9 & 1;
          uVar4 = op_ext_b0_u_p(uVar11);
          *puVar14 = uVar9 & 2;
          uVar6 = op_ext_b0_u(uVar6);
          mpu_privilege(puVar1,uVar4,uVar6);
          uVar7 = 0;
          uVar11 = (uint)*pbVar12;
        }
        else if (uVar3 == 0x72) {
          uVar7 = uVar7 | 0x200000000;
        }
        else if (uVar3 == 0x77) {
          uVar7 = uVar7 | 0x100000000;
        }
        else if (uVar3 == 0x43) goto LAB_0608e6be;
      }
      pbVar12 = pbVar12 + 1;
    }
    puVar14[1] = uVar9 & 1;
    uVar4 = op_ext_b0_u_p(uVar11);
    *puVar14 = uVar9 & 2;
    uVar6 = op_ext_b0_u(uVar6);
    mpu_privilege(puVar1,uVar4,uVar6);
    *(uint *)(iVar10 + (int)puVar1 * 4) = param_2;
    *(undefined4 *)(iVar13 + (int)puVar1 * 4) = uVar5;
    puVar1 = (uint *)func_0x0608e532();
    puVar15 = (undefined1 *)puVar14;
  }
  op_pop_pc_rl();
  *(undefined4 *)(puVar15 + 0xc) = unaff_retaddr;
  uVar7 = ZEXT48(puVar1);
  func_0x0608e51e();
  iVar10 = (int)uVar7;
  *(undefined4 *)(iVar10 * 4 + 0xff0300) = 0;
  *(undefined4 *)(iVar10 * 4 + 0xff0340) = 0;
  *(undefined4 *)(iVar10 * 4 + 0xff0380) = 0;
  *(undefined4 *)(iVar10 * 4 + 0xff03c0) = 0;
  uVar16 = func_0x0608e532();
  do {
    uVar5 = (undefined4)uVar16;
    op_push_rets_rl();
    uVar6 = (undefined4)uVar7;
    if ((int)((ulonglong)uVar16 >> 0x20) != 0) {
      *(undefined4 *)(in_cnum * 0x800 + 0xffe208) = uVar6;
      uVar6 = 0x3ff883;
      *(undefined4 *)(in_cnum * 0x800 + 0xffe20c) = uVar5;
      uVar5 = 0x3ff882;
      op_pop_pc_rl();
    }
    *(undefined4 *)(in_cnum * 0x800 + 0xffe210) = uVar6;
    *(undefined4 *)(in_cnum * 0x800 + 0xffe214) = uVar5;
    op_pop_pc_rl();
    op_push_rets_rl();
    *(undefined4 *)(in_cnum * 0x800 + 0xffe200) = 0xe0000007;
    *(undefined4 *)(in_cnum * 0x800 + 0xffe1c0) = 1;
    uVar7 = 0x103840;
    uVar16 = 0x100102840;
  } while( true );
}


// ===== FUN_0608e662 @ 0608e662

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0608e7e8) overlaps instruction at (ram,0x0608e7e6)
    */
/* WARNING: Possible PIC construction at 0x0608e80c: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0608e80e) */
/* WARNING: Removing unreachable block (ram,0x0608e81a) */
/* WARNING: Removing unreachable block (ram,0x0608e8d8) */
/* WARNING: Removing unreachable block (ram,0x0608e8da) */
/* WARNING: Removing unreachable block (ram,0x0608e7e8) */
/* WARNING: Removing unreachable block (ram,0x0608e8dc) */

void FUN_0608e662(uint param_1,undefined4 param_2,undefined4 param_3,byte *param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  ulonglong uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  uint *puVar10;
  undefined1 *puVar11;
  undefined8 uVar12;
  undefined1 auStack_10 [16];
  
  op_push_rets_rl();
  puVar10 = (uint *)auStack_10;
  puVar11 = auStack_10;
  if ((int)param_1 < 8) {
    func_0x0608e51e();
    uVar2 = 0;
    *(undefined4 *)(param_1 * 4 + 0xff0300) = 0;
    *(undefined4 *)(param_1 * 4 + 0xff0340) = 0;
    iVar8 = 0xff0380;
    *(undefined4 *)(param_1 * 4 + 0xff0380) = 0;
    iVar9 = 0xff03c0;
    *(undefined4 *)(param_1 * 4 + 0xff03c0) = 0;
    uVar6 = 0;
    *(undefined1 **)((int)puVar10 + 8) = (undefined1 *)((int)puVar10 + 0x34);
    *(undefined1 **)((int)puVar10 + 0xc) = (undefined1 *)((int)puVar10 + 0x34);
    while( true ) {
      uVar3 = (uint)*param_4;
      uVar5 = (undefined4)uVar6;
      uVar7 = (uint)(uVar6 >> 0x20);
      if (uVar3 == 0) break;
      if (uVar3 - 0x30 < 4) {
        puVar10[1] = uVar7 & 1;
        uVar4 = op_ext_b0_u_p(uVar2);
        *puVar10 = uVar7 & 2;
        uVar5 = op_ext_b0_u(uVar5);
        mpu_privilege(param_1,uVar4,uVar5);
        puVar1 = *(uint **)((int)puVar10 + 0xc);
        *(uint **)((int)puVar10 + 0xc) = puVar1 + 1;
        uVar2 = (uint)*param_4;
        uVar6 = (ulonglong)*puVar1;
      }
      else if (uVar3 != 0x78) {
        if (uVar3 == 0x50) {
LAB_0608e6be:
          puVar10[1] = uVar7 & 1;
          uVar4 = op_ext_b0_u_p(uVar2);
          *puVar10 = uVar7 & 2;
          uVar5 = op_ext_b0_u(uVar5);
          mpu_privilege(param_1,uVar4,uVar5);
          uVar6 = 0;
          uVar2 = (uint)*param_4;
        }
        else if (uVar3 == 0x72) {
          uVar6 = uVar6 | 0x200000000;
        }
        else if (uVar3 == 0x77) {
          uVar6 = uVar6 | 0x100000000;
        }
        else if (uVar3 == 0x43) goto LAB_0608e6be;
      }
      param_4 = param_4 + 1;
    }
    puVar10[1] = uVar7 & 1;
    uVar4 = op_ext_b0_u_p(uVar2);
    *puVar10 = uVar7 & 2;
    uVar5 = op_ext_b0_u(uVar5);
    mpu_privilege(param_1,uVar4,uVar5);
    *(undefined4 *)(iVar8 + param_1 * 4) = param_2;
    *(undefined4 *)(iVar9 + param_1 * 4) = param_3;
    param_1 = func_0x0608e532();
    puVar11 = (undefined1 *)puVar10;
  }
  op_pop_pc_rl();
  *(undefined4 *)(puVar11 + 0xc) = unaff_retaddr;
  uVar6 = (ulonglong)param_1;
  func_0x0608e51e();
  iVar8 = (int)uVar6;
  *(undefined4 *)(iVar8 * 4 + 0xff0300) = 0;
  *(undefined4 *)(iVar8 * 4 + 0xff0340) = 0;
  *(undefined4 *)(iVar8 * 4 + 0xff0380) = 0;
  *(undefined4 *)(iVar8 * 4 + 0xff03c0) = 0;
  uVar12 = func_0x0608e532();
  do {
    uVar5 = (undefined4)uVar12;
    op_push_rets_rl();
    uVar4 = (undefined4)uVar6;
    if ((int)((ulonglong)uVar12 >> 0x20) != 0) {
      *(undefined4 *)(in_cnum * 0x800 + 0xffe208) = uVar4;
      uVar4 = 0x3ff883;
      *(undefined4 *)(in_cnum * 0x800 + 0xffe20c) = uVar5;
      uVar5 = 0x3ff882;
      op_pop_pc_rl();
    }
    *(undefined4 *)(in_cnum * 0x800 + 0xffe210) = uVar4;
    *(undefined4 *)(in_cnum * 0x800 + 0xffe214) = uVar5;
    op_pop_pc_rl();
    op_push_rets_rl();
    *(undefined4 *)(in_cnum * 0x800 + 0xffe200) = 0xe0000007;
    *(undefined4 *)(in_cnum * 0x800 + 0xffe1c0) = 1;
    uVar6 = 0x103840;
    uVar12 = 0x100102840;
  } while( true );
}


// ===== FUN_0608e740 @ 0608e740

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0608e7e8) overlaps instruction at (ram,0x0608e7e6)
    */
/* WARNING: Possible PIC construction at 0x0608e80c: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0608e80e) */
/* WARNING: Removing unreachable block (ram,0x0608e81a) */
/* WARNING: Removing unreachable block (ram,0x0608e8d8) */
/* WARNING: Removing unreachable block (ram,0x0608e8da) */
/* WARNING: Removing unreachable block (ram,0x0608e7e8) */
/* WARNING: Removing unreachable block (ram,0x0608e8dc) */

void FUN_0608e740(int param_1)

{
  undefined4 uVar1;
  int in_cnum;
  undefined8 uVar2;
  
  func_0x0608e51e();
  *(undefined4 *)(param_1 * 4 + 0xff0300) = 0;
  *(undefined4 *)(param_1 * 4 + 0xff0340) = 0;
  *(undefined4 *)(param_1 * 4 + 0xff0380) = 0;
  *(undefined4 *)(param_1 * 4 + 0xff03c0) = 0;
  uVar2 = func_0x0608e532();
  do {
    uVar1 = (undefined4)uVar2;
    op_push_rets_rl();
    if ((int)((ulonglong)uVar2 >> 0x20) != 0) {
      *(int *)(in_cnum * 0x800 + 0xffe208) = param_1;
      param_1 = 0x3ff883;
      *(undefined4 *)(in_cnum * 0x800 + 0xffe20c) = uVar1;
      uVar1 = 0x3ff882;
      op_pop_pc_rl();
    }
    *(int *)(in_cnum * 0x800 + 0xffe210) = param_1;
    *(undefined4 *)(in_cnum * 0x800 + 0xffe214) = uVar1;
    op_pop_pc_rl();
    op_push_rets_rl();
    *(undefined4 *)(in_cnum * 0x800 + 0xffe200) = 0xe0000007;
    *(undefined4 *)(in_cnum * 0x800 + 0xffe1c0) = 1;
    param_1 = 0x103840;
    uVar2 = 0x100102840;
  } while( true );
}


// ===== FUN_0608e7c2 @ 0608e7c2

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0608e7e8) overlaps instruction at (ram,0x0608e7e6)
    */

void FUN_0608e7c2(void)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int extraout_r1;
  int iVar4;
  int iVar5;
  int in_r7;
  int in_cnum;
  BADSPACEBASE *in_sp;
  undefined1 *puVar6;
  int *piVar7;
  undefined1 *puVar8;
  undefined1 auStack_c [12];
  
  op_push_rets_rl();
  iVar3 = 0x3ff880;
  *(undefined4 *)(in_cnum * 0x800 + 0xffe200) = 0xe0000007;
  puVar6 = auStack_c;
LAB_0608e7dc:
  do {
    *(undefined4 *)(in_cnum * 0x800 + (iVar3 + -0x10) * 4) = 1;
    func_0x0608e76c(1,0x103840);
    iVar1 = in_cnum << 0xb;
    iVar5 = 0xffe200;
    piVar7 = (int *)puVar6;
    do {
      *(uint *)(iVar1 + iVar5) = *(uint *)(iVar1 + iVar5) | 8;
      pc_rang_limit2(4);
      iVar4 = 0x1094e0;
      iVar1 = 0x114110;
      pc_rang_limit1(0x1094e0);
      puVar2 = (uint *)(in_cnum * 0x800 + iVar5);
      *puVar2 = *puVar2 | 0x10;
      rep_unspec(2,0x10);
      uRam00104840 = 0xffffffff;
      iVar5 = FUN_0608e5aa(0x1139e8);
      iVar3 = FUN_0608e5aa(0x1139f0);
      piVar7[2] = iVar3;
      piVar7[1] = iVar5;
      *piVar7 = iVar4;
      iVar1 = FUN_0608e662(iVar1 + -1);
      puVar8 = (undefined1 *)((int)piVar7 + 0xc);
      op_pop_pc_rl();
      puVar6 = (undefined1 *)((int)piVar7 + 0xc);
      iVar3 = extraout_r1;
      if (iVar4 == 0) goto LAB_0608e7dc;
      piVar7 = (int *)((int)piVar7 + 0xc);
    } while (in_r7 == 0);
    puVar6 = puVar8;
    if (iVar5 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  } while( true );
}


// ===== FUN_0608eaba @ 0608eaba

void FUN_0608eaba(void)

{
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined4 *puVar1;
  undefined1 auStack_84 [128];
  
  puVar1 = (undefined4 *)(auStack_84 + 0x80);
  FUN_06088a6a();
  *puVar1 = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== thunk_FUN_06088ab8 @ 0608eac4

void thunk_FUN_06088ab8(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608eae2 @ 0608eae2

void FUN_0608eae2(uint param_1)

{
  if ((uRam00ffe0ec & 1) != 0) {
    uRam00105760 = uRam00ffe0f0 / (param_1 / 1000000);
    uRam00ffe0f0 = 0;
    uRam00ffe0f4 = 0x3ff;
    uRam00ffe0ec = 1;
  }
  return;
}


// ===== FUN_0608eb58 @ 0608eb58

undefined4 FUN_0608eb58(void)

{
  int iVar1;
  
  iVar1 = FUN_06088a6a();
  return *(undefined4 *)(iVar1 * 4 + 0x108220);
}


// ===== FUN_0608eb62 @ 0608eb62

undefined4 FUN_0608eb62(int param_1)

{
  return *(undefined4 *)(param_1 * 4 + 0x108220);
}


// ===== FUN_0608eb6e @ 0608eb6e

void FUN_0608eb6e(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608eb88 @ 0608eb88

/* WARNING: Removing unreachable block (ram,0x0608ebe8) */

void FUN_0608eb88(void)

{
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined4 *puVar1;
  undefined1 auStack_84 [128];
  
  puVar1 = (undefined4 *)(auStack_84 + 0x80);
  uRam001094cc = func_0x0bfbf2d6(0x6083488);
  *puVar1 = unaff_retaddr;
  FUN_0608aef8(1);
  do {
  } while( true );
}


// ===== FUN_0608eba0 @ 0608eba0

/* WARNING: Removing unreachable block (ram,0x0608ebe8) */

void FUN_0608eba0(void)

{
  FUN_0608aef8(1);
  do {
  } while( true );
}


// ===== FUN_0608ec3a @ 0608ec3a

void FUN_0608ec3a(void)

{
  uRam00ffe0f4 = 1;
  uRam00ffe0f0 = 0;
  return;
}


// ===== FUN_0608ec4a @ 0608ec4a

void FUN_0608ec4a(undefined4 param_1)

{
  uRam00105768 = param_1;
  uRam00ffe0f4 = 0x3ff;
  uRam00ffe0f0 = 0;
  uRam00ffe0ec = 0x41;
  return;
}


// ===== FUN_0608edc4 @ 0608edc4

undefined4 FUN_0608edc4(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = clz(param_1);
  uVar1 = op_ext_b0_u(uVar1);
  return uVar1;
}


// ===== FUN_0608efde @ 0608efde

/* WARNING: Control flow encountered bad instruction data */

void FUN_0608efde(void)

{
  uRam00f2c11c = 0x17;
  func_0x05f9acd6(&LAB_06001082);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


