// ===== FUN_060547b6 @ 060547b6

int FUN_060547b6(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  BADSPACEBASE *in_sp;
  
  op_pop_pc_rl();
  op_push_rets_rl();
  piVar7 = param_1 + 0x10;
  puVar5 = (undefined4 *)0x0;
  if (*piVar7 == 0) {
    puVar6 = param_2;
    iVar3 = FUN_0603bd66(*param_1);
    *piVar7 = iVar3;
    if (iVar3 != 0) {
      param_2 = (undefined4 *)((uint)*(ushort *)(iVar3 + 0x12) - (uint)*(ushort *)(iVar3 + 0x10));
      puVar5 = param_2;
      func_0x0001fd76(puVar6,*(int *)(iVar3 + 0x20) + (uint)*(ushort *)(iVar3 + 0x10),param_2);
      FUN_0603bda4(*piVar7);
      *piVar7 = 0;
    }
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  uVar2 = *(undefined1 *)((int)puVar5 + 0x32);
  uVar4 = op_ext_l_u_p(param_2);
  uVar1 = *puVar5;
  *(undefined4 *)((int)in_sp + -4) = 0;
  iVar3 = FUN_001131ca(uVar1,uVar4,uVar2);
  op_pop_pc_rl();
  return iVar3 + 0x98;
}


// ===== FUN_06086924 @ 06086924

undefined4 FUN_06086924(int param_1,uint param_2)

{
  code *pcVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  byte bVar10;
  undefined1 uVar11;
  byte *pbVar12;
  undefined4 uVar13;
  BADSPACEBASE *in_sp;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined2 *puVar16;
  undefined1 *puVar17;
  undefined8 uVar18;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  op_push_rets_rl();
  puVar9 = &uStack_c;
  puVar14 = &uStack_c;
  pbVar12 = (byte *)(param_1 + 0x30);
  if (*(byte *)(param_1 + 0x32) == param_2) {
    uVar3 = (uint)*(byte *)(param_1 + 0x33);
    puVar15 = &uStack_c;
    if (uVar3 == 0) goto LAB_0608693a;
  }
  else {
LAB_0608693a:
    iVar4 = op_ext_b0_u(param_2);
    if (iVar4 - 0x25U < 4) {
      uVar3 = (uint)*pbVar12;
      if (uVar3 == 2) {
        uStack_8 = 0;
      }
      else {
        puVar9 = &uStack_c;
        if (uVar3 != 1) goto LAB_06086998;
        uStack_8 = 1;
      }
      puVar9 = &uStack_c;
LAB_06086998:
      *(uint *)(param_1 + 0x24) = uVar3;
      puVar14 = puVar9;
    }
    else {
      if (iVar4 == 0x11) {
LAB_0608696a:
        uVar3 = 1;
        uStack_8 = 1;
        puVar9 = &uStack_c;
        goto LAB_06086998;
      }
      if (iVar4 == 0x12) {
        uStack_8 = 2;
        uStack_c = 0;
        pcVar1 = *(code **)(*(int *)(param_1 + 0x20) + 0x30);
        (*pcVar1)(*(undefined4 *)(param_1 + 0x28),0x85,&uStack_c,pcVar1);
        uVar3 = 1;
        goto LAB_06086998;
      }
      if (iVar4 == 0x13) {
        uVar3 = 1;
        if (*pbVar12 == 2) {
          uStack_8 = 0x220;
          uStack_4 = 0x220;
          puVar9 = &uStack_c;
        }
        else {
          puVar9 = &uStack_c;
          if (*pbVar12 == 1) goto LAB_0608696a;
        }
        goto LAB_06086998;
      }
    }
    bVar10 = (byte)param_2;
    pcVar1 = *(code **)(*(int *)(param_1 + 0x20) + 0x30);
    uVar3 = (*pcVar1)(*(undefined4 *)(param_1 + 0x28),0x81,(undefined1 *)((int)puVar14 + 4),pcVar1);
    pbVar12[2] = bVar10;
    puVar15 = puVar14;
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar16 = (undefined2 *)((int)puVar15 + -4);
  iVar4 = uVar3 + 0x30;
  if (*(char *)(uVar3 + 0x34) == '\0') {
    uVar2 = 4;
  }
  else if (*(char *)(uVar3 + 0x34) == '\x02') {
    uVar2 = 1;
  }
  else {
    uVar2 = 2;
  }
  *(undefined4 *)((int)puVar15 + -4) = *(undefined4 *)(uVar3 + 0x2c);
  *(undefined2 *)puVar15 = uVar2;
  uVar13 = 1;
  *(undefined2 *)((int)puVar15 + 2) = 1;
  *(undefined4 *)((int)puVar15 + 4) = 0x400;
  pcVar1 = *(code **)(*(int *)(uVar3 + 0x20) + 0x30);
  (*pcVar1)(*(undefined4 *)(uVar3 + 0x28),0x84,(undefined2 *)((int)puVar15 + -4),pcVar1);
  *(undefined4 *)((int)puVar16 + 0xc) = uVar13;
  pcVar1 = *(code **)(*(int *)(uVar3 + 0x20) + 0x30);
  puVar8 = (undefined1 *)((int)puVar16 + 0xc);
  (*pcVar1)(*(undefined4 *)(uVar3 + 0x28),0x80,pcVar1);
  uVar11 = (undefined1)uVar13;
  uVar18 = FUN_06086924(uVar3,*(undefined1 *)(iVar4 + 2));
  iVar5 = (int)((ulonglong)uVar18 >> 0x20);
  iVar6 = (int)uVar18;
  *(undefined1 *)(iVar4 + 3) = uVar11;
  puVar17 = (undefined1 *)((int)puVar16 + 0x10);
  puVar7 = (undefined1 *)((int)puVar16 + 0x10);
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar9 = (undefined4 *)(iVar5 + 0x2c);
  if (iVar6 == 0x40008) {
LAB_06086a48:
    *(undefined1 *)(iVar5 + 0x33) = 0;
    *(undefined1 *)(iVar5 + 0x32) = 0;
    puVar7 = (undefined1 *)((int)puVar16 + 0x10);
  }
  else {
    if (iVar6 == 0x20007) {
      if (*(char *)(iVar5 + 0x33) == '\0') goto LAB_06086aa4;
      puVar7 = puVar8;
      if (puVar8 + -0x11 < &SUB_00000002) {
        puVar9 = (undefined4 *)(uint)*(byte *)(iVar5 + 0x31);
      }
      else if (puVar8 == (undefined1 *)0x14) {
        puVar7 = (undefined1 *)0x14;
      }
      else if (puVar8 == (undefined1 *)0x25) {
        puVar7 = (undefined1 *)0x25;
      }
      else if (puVar8 == (undefined1 *)0x26) {
        puVar7 = (undefined1 *)0x26;
      }
    }
    else {
      if (iVar6 == 0x104) goto LAB_06086a48;
      puVar7 = (undefined1 *)((int)puVar16 + 0x10);
      if (iVar6 != 0x20003) goto LAB_06086aa4;
      bVar10 = puVar8[4];
      puVar7 = (undefined1 *)(uint)bVar10;
      if (*(int *)(puVar8 + 0x14) == 0xb00) {
        *(byte *)(iVar5 + 0x30) = bVar10 >> 4;
        *puVar9 = *(undefined4 *)(puVar8 + 0x10);
        *(byte *)(iVar5 + 0x32) = bVar10;
        *(undefined1 *)(iVar5 + 0x34) = puVar8[5];
        puVar7 = (undefined1 *)((int)puVar16 + 0x10);
        goto LAB_06086aa4;
      }
      *(byte *)(iVar5 + 0x31) = bVar10 >> 4;
      *(byte *)(iVar5 + 0x32) = bVar10;
    }
    FUN_06086924(puVar7,puVar9);
    puVar7 = puVar17;
  }
LAB_06086aa4:
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar4 = 0;
  FUN_0608adbc(uRam00000028);
  FUN_0608adbc(*(undefined4 *)(iVar4 + 0x50));
  FUN_0608adbc(iVar4);
  op_pop_pc_rl();
  op_push_rets_rl();
  *(undefined4 *)(puVar7 + -4) = 0;
  func_0x0bfcf6a4(0x200);
  op_pop_pc_rl();
  return 0x7fffffff;
}


// ===== FUN_06086b1e @ 06086b1e

void FUN_06086b1e(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 != 0xd80; iVar1 = iVar1 + 0x800) {
    *(undefined4 *)(iVar1 + 0xffe41c) = 0;
  }
  return;
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


// ===== FUN_06086dc8 @ 06086dc8

undefined4 FUN_06086dc8(void)

{
  undefined4 uVar1;
  undefined4 in_icfg;
  
  uVar1 = op_ext_b0_u(in_icfg);
  return uVar1;
}


// ===== FUN_06086dd0 @ 06086dd0

void FUN_06086dd0(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  
  op_push_rets_rl();
  piVar4 = (int *)((uint)*(byte *)(param_1 + 0x30) * 8 + 0x108228);
  iVar2 = *piVar4;
  if ((iVar2 != 0) && (iVar2 != *(int *)(iVar2 + 0x24))) {
    iVar3 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(param_1 + 0x20);
    *(int *)(*(int *)(param_1 + 0x20) + 0x24) = iVar3;
  }
  if (iVar2 == param_1) {
    uRam00108210 = *(uint *)(param_1 + 0x20);
    *piVar4 = 0;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  uRam00108328 = 0;
  op_pop_pc_rl();
  op_push_rets_rl();
  uVar5 = 0;
  if (uRam00108210 == 1) {
    uVar5 = 0xffff;
    for (iVar2 = 1; iVar2 != 0x20; iVar2 = iVar2 + 1) {
      iVar3 = *(int *)(iVar2 * 8 + 0x10822c);
      if (iVar3 != 0) {
        iVar6 = iVar3;
        do {
          op_ext_l_u_p(0xffff);
          iVar6 = *(int *)(iVar6 + 0x20);
          if (iVar6 == iVar3) break;
        } while (iVar6 != 0);
      }
    }
  }
  iVar3 = op_ext_l_u(uVar5);
  op_pop_pc_rl();
  op_push_rets_rl();
  piVar4 = (int *)((uint)*(byte *)(iVar3 + 0x30) * 8 + 0x10822c);
  iVar2 = *piVar4;
  if ((iVar2 != 0) && (iVar2 != *(int *)(iVar2 + 0x24))) {
    iVar6 = *(int *)(iVar3 + 0x24);
    *(undefined4 *)(iVar6 + 0x20) = *(undefined4 *)(iVar3 + 0x20);
    *(int *)(*(int *)(iVar3 + 0x20) + 0x24) = iVar6;
  }
  if (iVar2 == iVar3) {
    *piVar4 = *(int *)(iVar3 + 0x20);
  }
  *(undefined4 *)(iVar3 + 0x20) = 0;
  *(undefined4 *)(iVar3 + 0x24) = 0;
  uRam00108328 = OSUpdateIdleTime();
  op_pop_pc_rl();
  *(undefined4 *)((int)in_sp + -4) = unaff_retaddr;
  if (cRam00108359 != '\0') {
    OS_RemoveIdleList(0xffff);
  }
  iVar3 = FUN_06086dd0();
  bVar1 = *(byte *)(iVar3 + 0x30);
  piVar4 = (int *)((uint)bVar1 * 8 + 0x108228);
  iVar2 = *piVar4;
  if (iVar2 == 0) {
    *(int *)(iVar3 + 0x20) = iVar3;
    *(int *)(iVar3 + 0x24) = iVar3;
    *piVar4 = iVar3;
    uRam00108210 = uRam00108210 | 1 << (uint)bVar1;
  }
  else {
    *(int *)(iVar3 + 0x20) = iVar2;
    *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(iVar2 + 0x24);
    *(int *)(*(int *)(iVar2 + 0x24) + 0x20) = iVar3;
    *(int *)(iVar2 + 0x24) = iVar3;
  }
  uRam00108328 = 0;
  return;
}


// ===== FUN_06086ec8 @ 06086ec8

void FUN_06086ec8(int param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  
  if (*(char *)(param_1 + 0x31) != '\0') {
    OS_RemoveIdleList();
  }
  iVar3 = FUN_06086dd0();
  bVar2 = *(byte *)(iVar3 + 0x30);
  piVar4 = (int *)((uint)bVar2 * 8 + 0x108228);
  iVar1 = *piVar4;
  if (iVar1 == 0) {
    *(int *)(iVar3 + 0x20) = iVar3;
    *(int *)(iVar3 + 0x24) = iVar3;
    *piVar4 = iVar3;
    uRam00108210 = uRam00108210 | 1 << (uint)bVar2;
  }
  else {
    *(int *)(iVar3 + 0x20) = iVar1;
    *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(iVar1 + 0x24);
    *(int *)(*(int *)(iVar1 + 0x24) + 0x20) = iVar3;
    *(int *)(iVar1 + 0x24) = iVar3;
  }
  uRam00108328 = 0;
  return;
}


// ===== FUN_06086eda @ 06086eda

void FUN_06086eda(int param_1)

{
  int iVar1;
  byte bVar2;
  int *piVar3;
  
  bVar2 = *(byte *)(param_1 + 0x30);
  piVar3 = (int *)((uint)bVar2 * 8 + 0x108228);
  iVar1 = *piVar3;
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x20) = param_1;
    *(int *)(param_1 + 0x24) = param_1;
    *piVar3 = param_1;
    uRam00108210 = uRam00108210 | 1 << (uint)bVar2;
  }
  else {
    *(int *)(param_1 + 0x20) = iVar1;
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar1 + 0x24);
    *(int *)(*(int *)(iVar1 + 0x24) + 0x20) = param_1;
    *(int *)(iVar1 + 0x24) = param_1;
  }
  uRam00108328 = 0;
  return;
}


// ===== FUN_06086f16 @ 06086f16

void FUN_06086f16(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  undefined1 auStack_84 [128];
  
  puVar6 = (undefined4 *)(auStack_84 + 0x80);
  piVar2 = (int *)((uint)*(byte *)(param_1 + 0x30) * 8 + 0x10822c);
  iVar1 = *piVar2;
  if (iVar1 == 0) {
    piVar3 = (int *)(param_1 + 0x24);
    *(int *)(param_1 + 0x20) = param_1;
  }
  else {
    *(int *)(param_1 + 0x20) = iVar1;
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(iVar1 + 0x24);
    piVar2 = (int *)(iVar1 + 0x24);
    piVar3 = (int *)(*piVar2 + 0x20);
  }
  *piVar3 = param_1;
  *piVar2 = param_1;
  uRam00108328 = OSUpdateIdleTime();
  *puVar6 = unaff_retaddr;
  if (cRam00108359 != '\0') {
    FUN_06086f16(0xffff);
    puVar6 = (undefined4 *)((int)puVar6 + 4);
  }
  uVar8 = FUN_06086eda();
  puVar7 = (undefined1 *)((int)puVar6 + 4);
  op_push_rets_rl();
  FUN_06086dd0((int)uVar8);
  FUN_06086f16((int)uVar8);
  iVar5 = (int)((ulonglong)uVar8 >> 0x20);
  iVar4 = (int)uVar8;
  iVar1 = *(int *)(iVar5 + 4);
  if (iVar1 == 0) {
    *(int *)(iVar5 + 4) = iVar4;
    *(int *)(iVar4 + 0x1c) = iVar4;
    piVar2 = (int *)(iVar4 + 0x18);
  }
  else {
    *(int *)(iVar4 + 0x18) = iVar1;
    *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
    piVar2 = (int *)(iVar1 + 0x1c);
    *(int *)(*piVar2 + 0x18) = iVar4;
  }
  *piVar2 = iVar4;
  *(int *)(iVar4 + 0x28) = iVar5;
  op_pop_pc_rl();
  *(undefined4 *)(puVar7 + -4) = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  p33_soft_reset();
}


// ===== FUN_06086f64 @ 06086f64

void FUN_06086f64(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined8 uVar8;
  undefined1 auStack_84 [128];
  
  puVar6 = auStack_84 + 0x80;
  puVar5 = auStack_84 + 0x80;
  if (*(char *)(param_1 + 0x31) != '\0') {
    FUN_06086f16();
    puVar6 = puVar5 + 4;
  }
  uVar8 = FUN_06086eda();
  puVar7 = puVar6 + 4;
  op_push_rets_rl();
  FUN_06086dd0((int)uVar8);
  FUN_06086f16((int)uVar8);
  iVar4 = (int)((ulonglong)uVar8 >> 0x20);
  iVar3 = (int)uVar8;
  iVar1 = *(int *)(iVar4 + 4);
  if (iVar1 == 0) {
    *(int *)(iVar4 + 4) = iVar3;
    *(int *)(iVar3 + 0x1c) = iVar3;
    piVar2 = (int *)(iVar3 + 0x18);
  }
  else {
    *(int *)(iVar3 + 0x18) = iVar1;
    *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
    piVar2 = (int *)(iVar1 + 0x1c);
    *(int *)(*piVar2 + 0x18) = iVar3;
  }
  *piVar2 = iVar3;
  *(int *)(iVar3 + 0x28) = iVar4;
  op_pop_pc_rl();
  *(undefined4 *)(puVar7 + -4) = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  p33_soft_reset();
}


// ===== FUN_06086f74 @ 06086f74

void FUN_06086f74(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  
  op_push_rets_rl();
  FUN_06086dd0(param_2);
  FUN_06086f16(param_2);
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 0) {
    *(int *)(param_1 + 4) = param_2;
    *(int *)(param_2 + 0x1c) = param_2;
    piVar2 = (int *)(param_2 + 0x18);
  }
  else {
    *(int *)(param_2 + 0x18) = iVar1;
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
    piVar2 = (int *)(iVar1 + 0x1c);
    *(int *)(*piVar2 + 0x18) = param_2;
  }
  *piVar2 = param_2;
  *(int *)(param_2 + 0x28) = param_1;
  op_pop_pc_rl();
  *(undefined4 *)((int)in_sp + -4) = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
  p33_soft_reset();
}


// ===== FUN_06086fac @ 06086fac

void FUN_06086fac(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  uint *puVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  
  op_push_rets_rl();
  if (cRam00108214 != '\0') {
    FUN_06086fa2();
  }
  FUN_0608eaba();
  iVar12 = 0x104b50;
  uVar13 = iRam00104b5c * 10;
  uVar6 = 0;
  iVar14 = 0x108228;
  piVar10 = (int *)0x108218;
  pcVar8 = (char *)0x1094c8;
  iVar5 = 0x10832c;
  uVar15 = uRam00108210;
  do {
    uVar2 = FUN_0608eace(uVar15);
    iVar16 = op_uextra_rrii(uVar2,0,8);
    iVar1 = *(int *)(iVar14 + iVar16 * 8);
    iVar7 = iVar1;
    do {
      iVar3 = op_ext_b0_u(uVar6);
      piVar10[iVar3] = iVar7;
      if (*pcVar8 == '\0') {
        piVar10[1] = iVar5 + 0x58;
        if ((uVar6 & 0xff) == 0) {
code_r0x06087034:
          uVar15 = 0;
          piVar11 = (int *)0x108220;
          goto code_r0x06087066;
        }
        uVar6 = uVar6 + 2;
        break;
      }
      if (iVar3 == 1) goto code_r0x06087034;
      iVar7 = *(int *)(iVar7 + 0x20);
      uVar6 = uVar6 + 1;
    } while (iVar7 != iVar1);
    uVar15 = uVar15 & ~(1 << iVar16);
  } while( true );
code_r0x06087066:
  if (uVar15 == 2) {
    for (iVar14 = 0; iVar14 != 2; iVar14 = iVar14 + 1) {
      for (iVar7 = 0; iVar7 != 2; iVar7 = iVar7 + 1) {
        if (iVar14 != iVar7) {
          piVar10[iVar14] = iVar14 * 0x58 + iVar5;
        }
      }
    }
    FUN_06086fa2(piVar10[1],*piVar10);
    iVar5 = 0xffe000;
    for (iVar14 = 3; iVar14 != 1; iVar14 = iVar14 + -1) {
      if (*(int *)(iVar12 + 0xc) == 0) {
        FUN_06086fa2();
      }
      iVar7 = *piVar10;
      piVar10 = piVar10 + 1;
      puVar9 = (uint *)(iVar7 + 0x4c);
      if (*(uint *)(iVar12 + 0xc) < *puVar9) {
        FUN_06086fa2();
      }
      iVar1 = *piVar11;
      piVar11 = piVar11 + 1;
      if (iVar1 == iVar7) {
        *(uint *)(iVar7 + 0x54) = *(int *)(iVar7 + 0x54) + (uVar13 - puVar9[1]);
        puVar9[1] = uVar13;
      }
      else {
        puVar9[1] = uVar13;
        *(uint *)(iVar1 + 0x54) = *(int *)(iVar1 + 0x54) + (uVar13 - *(int *)(iVar1 + 0x50));
        if (*(char *)(iVar7 + 5) == '\0') {
          *(undefined1 *)(iVar7 + 5) = *(undefined1 *)(iVar7 + 4);
        }
        *(uint *)(iVar5 + 0x1a0) = *(uint *)(iVar5 + 0x1a0) | 1 << iVar14;
      }
      iVar5 = iVar5 + 0x800;
    }
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  piVar4 = piVar10;
  for (uVar6 = 0; uVar6 < 2; uVar6 = uVar6 + 1) {
    if ((uVar15 != uVar6) && (iVar14 = *(int *)(uVar15 * 4 + 0x108220), iVar14 == *piVar4)) {
      *piVar4 = piVar10[uVar15];
      piVar10[uVar15] = iVar14;
      break;
    }
    piVar4 = piVar4 + 1;
  }
  uVar15 = uVar15 + 1;
  goto code_r0x06087066;
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


// ===== FUN_0608732c @ 0608732c

void FUN_0608732c(uint param_1)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_r0_r1;
  ulonglong uVar6;
  int iVar7;
  byte bVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined2 uVar11;
  byte *pbVar12;
  byte bVar13;
  int in_cnum;
  
  op_push_rets_rl();
  iVar4 = (int)((ulonglong)in_r0_r1 >> 0x20);
  if (*(int *)(iVar4 + 0x18) == iVar4) {
    iVar7 = 0;
LAB_06087350:
    *(int *)((int)in_r0_r1 + 4) = iVar7;
  }
  else {
    iVar1 = *(int *)(iVar4 + 0x1c);
    *(int *)(iVar1 + 0x18) = *(int *)(iVar4 + 0x18);
    iVar7 = *(int *)(iVar4 + 0x18);
    *(int *)(iVar7 + 0x1c) = iVar1;
    if (*(int *)((int)in_r0_r1 + 4) == iVar4) goto LAB_06087350;
  }
  bVar8 = 0;
  uVar9 = 0;
  uVar11 = 0;
  pbVar12 = (byte *)(iVar4 + 0x30);
  *(undefined4 *)(iVar4 + 0x18) = 0;
  *(undefined4 *)(iVar4 + 0x1c) = 0;
  *(undefined2 *)(iVar4 + 6) = 0;
  *(undefined8 *)(iVar4 + 0x28) = 0;
  uVar2 = (uint)*(byte *)(iVar4 + 0x31) & ~param_1;
  uVar6 = CONCAT44(uVar2,uVar2) & 0xdfffffffff;
  *(char *)(iVar4 + 0x31) = (char)(uVar6 >> 0x20);
  if (((uVar2 & 0xdf) == 0) &&
     (uVar6 = (ulonglong)*(byte *)(iVar4 + 0x32), *(byte *)(iVar4 + 0x32) == 0)) {
    OS_RemoveIdleList();
    FUN_06086eda(iVar4);
    uVar6 = CONCAT44(0x108210,(uint)*pbVar12);
    uRam00108210 = uRam00108210 | 1 << (uint)*pbVar12;
  }
  pbVar12[2] = bVar8;
  op_pop_pc_rl();
  op_push_rets_rl();
  pcVar3 = (char *)uVar6;
  iVar4 = FUN_06086dc8();
  if ((((iVar4 == 0) && (iVar4 = FUN_0608978a(), iVar4 == 0)) && (cRam00108214 == '\0')) &&
     ((iVar4 = FUN_0608eab2(), iVar4 < 1 && (*pcVar3 == '\x03')))) {
    FUN_0608eaba();
    iVar4 = *(int *)(in_cnum * 4 + 0x108220);
    bVar8 = (byte)iVar4;
    uVar9 = (undefined1)((uint)iVar4 >> 8);
    uVar11 = (undefined2)((uint)iVar4 >> 0x10);
    pbVar12 = (byte *)(iVar4 + 0x30);
    *(undefined4 *)(iVar4 + 0x4c) = uRam00104b5c;
    iVar4 = op_ext_l_u_p(*(ushort *)(pcVar3 + 0xe) - 1);
    *(short *)(pcVar3 + 0xe) = (short)(*(ushort *)(pcVar3 + 0xe) - 1);
    if (iVar4 != 0) goto LAB_060873f0;
  }
  else {
    op_pop_pc_rl();
  }
  if (*(int *)(pcVar3 + 4) != 0) {
    pcVar3[0xe] = '\x01';
    pcVar3[0xf] = '\0';
    bVar13 = pcVar3[0xd];
    if (*pbVar12 != bVar13) {
      FUN_06086dd0(CONCAT22(uVar11,CONCAT11(uVar9,bVar8)));
      *pbVar12 = bVar13;
      FUN_06086eda(CONCAT22(uVar11,CONCAT11(uVar9,bVar8)));
    }
    uVar5 = OS_EventHighestTask();
    uVar9 = (undefined1)uVar5;
    uVar10 = (undefined1)((uint)uVar5 >> 8);
    uVar11 = (undefined2)((uint)uVar5 >> 0x10);
    FUN_0608732c(pcVar3,8);
    pcVar3[0xd] = *(char *)(CONCAT22(uVar11,CONCAT11(uVar10,uVar9)) + 0x30);
    *(uint *)(pcVar3 + 8) = CONCAT22(uVar11,CONCAT11(uVar10,uVar9));
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  pcVar3[0xe] = '\0';
  pcVar3[0xf] = '\0';
  pcVar3[0xc] = '\x01';
  pcVar3[0xd] = -1;
  pcVar3[8] = '\0';
  pcVar3[9] = '\0';
  pcVar3[10] = '\0';
  pcVar3[0xb] = '\0';
LAB_060873f0:
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


// ===== FUN_060874c8 @ 060874c8

void FUN_060874c8(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  BADSPACEBASE *in_sp;
  int *piVar8;
  undefined4 uStack_4;
  
  op_push_rets_rl();
  uStack_4 = param_5;
  uVar3 = param_1;
  piVar8 = &uStack_4;
  if (cRam00108214 != '\0') {
    uVar3 = 0x15;
    op_pop_pc_rl();
    piVar8 = (int *)in_sp;
  }
  FUN_0608eaba(uVar3);
  iVar4 = OSGetTaskTcb(param_1);
  if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  if (*(ushort *)(iVar4 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  iVar5 = param_4 + 1;
  if ((int)(uint)*(ushort *)(iVar4 + 0xc) <= (int)((uint)*(ushort *)(iVar4 + 0xe) + iVar5)) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  op_ext_b0_u_p(iVar5);
  uVar3 = op_insert_rrii_p(param_2,8,0x18);
  *(undefined4 *)(*(int *)(iVar4 + 0x10) + (uint)*(ushort *)(iVar4 + 8) * 4) = uVar3;
  *(short *)(iVar4 + 0xe) = (short)iVar5 + *(short *)(iVar4 + 0xe);
  iVar6 = *(ushort *)(iVar4 + 8) + 1;
  op_ext_l_u_p(iVar6);
  *(short *)(iVar4 + 8) = (short)iVar6;
  for (iVar5 = 0; iVar5 < param_4; iVar5 = iVar5 + 1) {
    if (param_3 == 0) {
      puVar1 = (undefined4 *)*piVar8;
      *piVar8 = (int)(puVar1 + 1);
      uVar3 = *puVar1;
    }
    else {
      uVar3 = *(undefined4 *)(param_3 + iVar5 * 4);
    }
    iVar7 = op_ext_l_u_p(iVar6);
    *(undefined4 *)(*(int *)(iVar4 + 0x10) + iVar7 * 4) = uVar3;
    iVar6 = iVar6 + 1;
    op_ext_l_u(iVar6);
    *(short *)(iVar4 + 8) = (short)iVar6;
  }
  bVar2 = *(byte *)(iVar4 + 0x31);
  if ((bVar2 & 0x10) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  *(undefined2 *)(iVar4 + 6) = 0;
  *(undefined1 *)(iVar4 + 0x32) = 0;
  *(byte *)(iVar4 + 0x31) = bVar2 & 0xcf;
  if ((bVar2 & 0xcf) == 0) {
    OS_RemoveIdleList(iVar4);
    FUN_06086eda(iVar4);
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_060875d8 @ 060875d8

void FUN_060875d8(void)

{
  int in_cnum;
  
  *(undefined4 *)(in_cnum * 4 + 0x1083e4) = 1;
  return;
}


// ===== FUN_060875ee @ 060875ee

void FUN_060875ee(void)

{
  int in_cnum;
  
  *(undefined4 *)(in_cnum * 4 + 0x1083e4) = 0;
  return;
}


// ===== FUN_06087610 @ 06087610

void FUN_06087610(void)

{
  uint in_psr;
  
  do {
    testset_unspec(uRam00108404);
  } while ((in_psr >> 2 & 1) != 0);
  return;
}


// ===== FUN_0608761e @ 0608761e

void FUN_0608761e(void)

{
  uRam00108404 = 0;
  return;
}


// ===== FUN_0608762a @ 0608762a

void FUN_0608762a(void)

{
  op_push_rets_rl();
  FUN_0608eaba();
  OSGetTaskTcb(1);
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_0608764c @ 0608764c

void FUN_0608764c(void)

{
                    /* WARNING: Subroutine does not return */
  p33_soft_reset();
}


// ===== FUN_06087656 @ 06087656

void FUN_06087656(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_cnum;
  
  op_push_rets_rl();
  iVar1 = in_cnum;
  if (param_1 != 0) {
    iVar3 = 0x108220;
    iVar1 = *(int *)(in_cnum * 4 + 0x108220);
    if (iVar1 != in_cnum * 0x58 + 0x10832c) {
      FUN_0608eaba();
      *(short *)(*(int *)(iVar3 + in_cnum * 4) + 6) = (short)param_1;
      *(undefined4 *)(*(int *)(iVar3 + in_cnum * 4) + 0x4c) = 0;
      iVar1 = *(int *)(iVar3 + in_cnum * 4);
      *(byte *)(iVar1 + 0x31) = *(byte *)(iVar1 + 0x31) | 0x20;
      FUN_06086dd0(*(undefined4 *)(iVar3 + in_cnum * 4));
      FUN_06086f16(*(undefined4 *)(iVar3 + in_cnum * 4));
                    /* WARNING: Subroutine does not return */
      thunk_FUN_06088ab8();
    }
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar3 = FUN_06086dc8();
  if ((iVar3 != 0) || (iVar3 = FUN_0608978a(), iVar3 != 0)) {
    FUN_0608764c();
  }
  uVar2 = op_ext_l_u(iVar1);
                    /* WARNING: Subroutine does not return */
  FUN_06087656(uVar2);
}


// ===== FUN_06087740 @ 06087740

void FUN_06087740(byte *param_1)

{
  ushort uVar1;
  uint uVar2;
  short sVar3;
  short *psVar4;
  int iVar5;
  uint uVar6;
  longlong lVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  ushort *puVar14;
  uint uVar15;
  undefined1 *puVar16;
  BADSPACEBASE *in_sp;
  undefined1 *puVar17;
  undefined1 auStack_100 [256];
  
  op_push_rets_rl();
  lVar7 = (ulonglong)bRam00108214 << 0x20;
  if ((bRam00108214 == 0) && (lVar7 = CONCAT44((uint)*param_1,2), *param_1 == 2)) {
    FUN_0608eaba();
    if (*(int *)(param_1 + 4) != 0) {
      OS_EventHighestTask();
      FUN_0608732c(param_1,1);
                    /* WARNING: Subroutine does not return */
      thunk_FUN_06088ab8();
    }
    sVar3 = *(short *)(param_1 + 0xc);
    if (sVar3 == -1) {
                    /* WARNING: Subroutine does not return */
      thunk_FUN_06088ab8();
    }
    *(short *)(param_1 + 0xc) = sVar3 + 1;
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar12 = (int)lVar7;
  iVar5 = *(int *)(iVar12 + 8);
  uVar8 = (uint)((ulonglong)lVar7 >> 0x20);
  iVar11 = uVar8 * 4;
  uVar10 = (uint)*(byte *)(iVar5 + iVar11);
  iVar13 = *(ushort *)(iVar12 + 6) - uVar10;
  *(short *)(iVar12 + 6) = (short)iVar13;
  uVar1 = *(ushort *)(iVar12 + 2);
  if (uVar1 == uVar8) {
    iVar9 = uVar8 + *(byte *)(iVar5 + iVar11);
    uVar10 = op_ext_l_u_p(iVar9);
    *(short *)(iVar12 + 2) = (short)iVar9;
    iVar9 = iVar9 - (uint)*(ushort *)(iVar12 + 4);
    lVar7 = CONCAT44(iVar9,iVar12);
    *(short *)(iVar12 + 2) = (short)iVar9;
    op_pop_pc_rl();
  }
  psVar4 = (short *)lVar7;
  op_ext_l_u_p(iVar13);
  *psVar4 = (ushort)*(byte *)(iVar5 + iVar11) - psVar4[2];
  uVar8 = (uint)((ulonglong)lVar7 >> 0x20);
  puVar14 = (ushort *)(psVar4 + 4);
  iVar12 = uVar10 + uVar8;
  iVar11 = ((uint)uVar1 + uVar8 * -2) - (uint)(ushort)psVar4[2];
  for (; iVar11 != 0; iVar11 = iVar11 + -1) {
    uVar1 = *puVar14;
    *(undefined4 *)(iVar5 + uVar8 * 4) = *(undefined4 *)(iVar5 + (iVar12 - (uint)uVar1) * 4);
    iVar12 = (iVar12 - (uint)uVar1) + 1;
    uVar8 = uVar8 + 1;
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar16 = auStack_100;
  FUN_0608eaba();
  iVar5 = OSGetTaskTcb(puVar14);
  if (iVar5 != 0) {
    uVar10 = uVar8 & 0x870;
    iVar11 = iVar5 + 8;
    puVar17 = puVar16;
    while( true ) {
      uVar6 = (uint)*(ushort *)(iVar5 + 0xe);
      uVar15 = (uint)*(ushort *)(iVar5 + 10);
      while( true ) {
        if (uVar6 == 0) goto LAB_060878b8;
        uVar2 = *(uint *)(*(int *)(iVar5 + 0x10) + uVar15 * 4);
        if (uVar2 >> 8 == uVar8) break;
        iVar12 = op_ext_b0_u_p(uVar2);
        uVar15 = (iVar12 + uVar15) - (uint)*(ushort *)(iVar5 + 0xc);
        uVar6 = uVar6 - iVar12;
      }
      if ((int)uVar15 < 0) break;
      if (uVar10 == 0x940) {
        __OSTaskQCopy(iVar11,0x40,puVar17);
        iVar5 = op_ext_b0_u(*(uint *)(puVar16 + 8));
        if ((*(uint *)(puVar16 + 8) & 0x100) != 0) {
          **(undefined4 **)(puVar17 + iVar5 * 4 + 0xc) = 0x3ff;
          iVar5 = iVar5 + 1;
        }
                    /* WARNING: Subroutine does not return */
        FUN_06087740(*(undefined4 *)(puVar17 + iVar5 * 4 + 0xc));
      }
      __OSTaskQDel(iVar11);
    }
  }
LAB_060878b8:
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_0608782e @ 0608782e

void FUN_0608782e(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined8 in_r0_r1;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined1 *puVar9;
  uint uVar10;
  BADSPACEBASE *in_sp;
  undefined1 *puVar11;
  undefined1 auStack_100 [256];
  
  op_push_rets_rl();
  puVar9 = auStack_100;
  uVar5 = (uint)((ulonglong)in_r0_r1 >> 0x20);
  uVar2 = (undefined4)in_r0_r1;
  FUN_0608eaba();
  iVar3 = OSGetTaskTcb(uVar2);
  if (iVar3 != 0) {
    uVar10 = uVar5 & 0x870;
    iVar7 = iVar3 + 8;
    puVar11 = puVar9;
    while( true ) {
      uVar4 = (uint)*(ushort *)(iVar3 + 0xe);
      uVar8 = (uint)*(ushort *)(iVar3 + 10);
      while( true ) {
        if (uVar4 == 0) goto LAB_060878b8;
        uVar1 = *(uint *)(*(int *)(iVar3 + 0x10) + uVar8 * 4);
        if (uVar1 >> 8 == uVar5) break;
        iVar6 = op_ext_b0_u_p(uVar1);
        uVar8 = (iVar6 + uVar8) - (uint)*(ushort *)(iVar3 + 0xc);
        uVar4 = uVar4 - iVar6;
      }
      if ((int)uVar8 < 0) break;
      if (uVar10 == 0x940) {
        __OSTaskQCopy(iVar7,0x40,puVar11);
        iVar3 = op_ext_b0_u(*(uint *)(puVar9 + 8));
        if ((*(uint *)(puVar9 + 8) & 0x100) != 0) {
          **(undefined4 **)(puVar11 + iVar3 * 4 + 0xc) = 0x3ff;
          iVar3 = iVar3 + 1;
        }
                    /* WARNING: Subroutine does not return */
        FUN_06087740(*(undefined4 *)(puVar11 + iVar3 * 4 + 0xc));
      }
      __OSTaskQDel(iVar7);
    }
  }
LAB_060878b8:
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_060878c8 @ 060878c8

void FUN_060878c8(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_06087740();
}


// ===== FUN_060878d0 @ 060878d0

void FUN_060878d0(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint *extraout_r1;
  uint *puVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  int in_cnum;
  
  op_push_rets_rl();
  *(undefined4 *)(*(int *)(in_cnum * 4 + 0x108220) + 0x4c) = uRam00104b5c;
  uVar6 = (uint)*(ushort *)(param_1 + 2);
  for (uVar2 = (uint)*(ushort *)(param_1 + 6); uVar2 != 0; uVar2 = uVar2 - iVar3) {
    uVar1 = *(uint *)(*(int *)(param_1 + 8) + uVar6 * 4);
    if ((uVar1 & 0xffffff00) == 0x500) {
      if (-1 < (int)uVar6) {
        __OSTaskQCopy(param_2);
        goto LAB_06087940;
      }
      break;
    }
    iVar3 = op_ext_b0_u_p(uVar1);
    uVar6 = (uVar6 + iVar3) - (uint)*(ushort *)(param_1 + 4);
  }
  __OSTaskQCopy(param_2);
LAB_06087940:
  iVar3 = __OSTaskQDel();
  op_pop_pc_rl();
  op_push_rets_rl();
  uVar2 = *extraout_r1 & 0x870;
  if (uVar2 != 0x940) {
LAB_060879c0:
    uVar4 = 0;
    op_pop_pc_rl();
    op_push_rets_rl();
    iVar3 = FUN_0608eab2();
    if (0 < iVar3) {
      op_pop_pc_rl();
    }
    FUN_0608eaba();
    uVar7 = 0;
    iVar3 = *(int *)(in_cnum * 4 + 0x108220);
    if (0 < (int)uVar2) {
      if (*(short *)(iVar3 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
        thunk_FUN_06088ab8();
      }
      if (*(short *)(iVar3 + 0xe) != 0) {
        FUN_060878d0(iVar3 + 8,uVar4);
                    /* WARNING: Subroutine does not return */
        thunk_FUN_06088ab8();
      }
    }
    iVar8 = iVar3 + 0x30;
    *(char *)(iVar3 + 0x31) = (char)iVar3;
    *(undefined1 *)(iVar3 + 0x32) = 0;
    *(undefined2 *)(iVar3 + 6) = 0;
    FUN_06086dd0();
    FUN_06086f16(iVar3);
    *(undefined4 *)(iVar8 + 0x1c) = uVar7;
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  uVar2 = extraout_r1[2];
  iVar8 = op_ext_b0_u(uVar2);
  uVar6 = op_uextra_rrii(uVar2,9,1);
  if (iVar3 <= (int)(iVar8 + 1 + (uVar6 | 2))) goto LAB_060879c0;
  iVar3 = op_ext_b0_u(uVar2);
  puVar5 = extraout_r1;
  if (iVar3 == 2) {
    if ((uVar2 & 0x400) == 0) {
      uVar4 = (*(code *)extraout_r1[1])
                        ((int)*(undefined8 *)(extraout_r1 + 3),(code *)extraout_r1[1]);
      goto LAB_0608799e;
    }
  }
  else if (iVar3 == 1) {
    uVar4 = (*(code *)extraout_r1[1])();
    goto LAB_0608799e;
  }
  uVar4 = (*(code *)extraout_r1[1])(extraout_r1[3],extraout_r1 + 4,(code *)extraout_r1[1]);
LAB_0608799e:
  *(undefined4 *)puVar5[iVar8 + 3] = uVar4;
                    /* WARNING: Subroutine does not return */
  FUN_06087740(puVar5[iVar8 + 3]);
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


// ===== FUN_06087bca @ 06087bca

void FUN_06087bca(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  int in_cnum;
  BADSPACEBASE *in_sp;
  
  op_push_rets_rl();
  FUN_0608eaba();
  uVar3 = *(undefined4 *)((int)in_sp + 0x2c);
  iVar2 = OSGetTaskTcb(uVar3);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  uVar4 = (undefined1)*(undefined4 *)((int)in_sp + 0x28);
  iVar2 = *(int *)((int)in_sp + 0x20);
  *(char *)(param_2 + 0xc) = (char)*(undefined4 *)((int)in_sp + 0x1c);
  param_2[0x12] = uVar3;
  uVar3 = func_0x0608eb78(param_1,param_3,param_4);
  *param_2 = uVar3;
  param_2[5] = *(undefined4 *)(in_cnum * 4 + 0x108220);
  if ((iVar2 != 0) && (iVar1 = *(int *)((int)in_sp + 0x24), iVar1 != 0)) {
    param_2[4] = iVar2;
    *(short *)(param_2 + 3) = (short)iVar1;
  }
  *(undefined1 *)(param_2 + 1) = uVar4;
  FUN_06086eda(param_2);
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_06087d2e @ 06087d2e

void FUN_06087d2e(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  
  op_push_rets_rl();
  iVar2 = FUN_0608eab2();
  if (0 < iVar2) {
    op_pop_pc_rl();
    *(undefined4 *)((int)in_sp + -4) = unaff_retaddr;
    FUN_06087d2e(0x1f);
    op_push_rets_rl();
    FUN_0608eaba();
    if (in_cnum != 0) {
      uRam001094c8 = 0;
      iVar3 = 0x108220;
      *(undefined2 *)(*(int *)(in_cnum * 4 + 0x108220) + 6) = 1;
      *(undefined4 *)(*(int *)(in_cnum * 4 + 0x108220) + 0x4c) = 0;
      iVar2 = *(int *)(in_cnum * 4 + 0x108220);
      *(byte *)(iVar2 + 0x31) = *(byte *)(iVar2 + 0x31) | 0x20;
      FUN_06086dd0(*(undefined4 *)(in_cnum * 4 + 0x108220));
      FUN_06086f16(*(undefined4 *)(iVar3 + in_cnum * 4));
    }
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  FUN_0608eaba();
  iVar2 = OSGetTaskTcb(param_1);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  iVar3 = 0;
  do {
    if (1 < iVar3) {
      pcVar1 = *(char **)(iVar2 + 0x28);
      if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
        if (*(int *)(pcVar1 + 4) == iVar2) {
          iVar3 = *(int *)(iVar2 + 0x1c);
          iVar4 = *(int *)(iVar2 + 0x18);
          *(int *)(pcVar1 + 4) = iVar4;
        }
        else {
          iVar3 = *(int *)(iVar2 + 0x1c);
          iVar4 = *(int *)(iVar2 + 0x18);
        }
        *(int *)(iVar3 + 0x18) = iVar4;
        *(int *)(*(int *)(iVar2 + 0x18) + 0x1c) = iVar3;
        *(undefined4 *)(iVar2 + 0x18) = 0;
        *(undefined4 *)(iVar2 + 0x1c) = 0;
      }
      FUN_06086ec8(iVar2);
      *(undefined2 *)(iVar2 + 6) = 0;
      *(undefined1 *)(iVar2 + 0x31) = 0;
      *(byte *)(iVar2 + 0x33) = *(byte *)(iVar2 + 0x33) | 3;
      *(undefined1 *)(iVar2 + 0x32) = 0;
      *(undefined2 *)(iVar2 + 0xc) = 0;
                    /* WARNING: Subroutine does not return */
      thunk_FUN_06088ab8();
    }
    if (*(int *)(iVar3 * 4 + 0x108218) == iVar2) break;
    iVar4 = iVar3 * 4;
    iVar3 = iVar3 + 1;
  } while (*(int *)(iVar4 + 0x108220) != iVar2);
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


// ===== FUN_06087f86 @ 06087f86

void FUN_06087f86(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_cnum;
  
  op_push_rets_rl();
  FUN_0608eaba();
  iVar1 = *(int *)(in_cnum * 4 + 0x108220);
  if (*(short *)(iVar1 + 0xc) == 0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  if ((*(short *)(iVar1 + 0xe) == 0) || (*(short *)(iVar1 + 0xe) == 0)) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_06088ab8();
  }
  FUN_060878d0(iVar1 + 8,param_1,param_2);
                    /* WARNING: Subroutine does not return */
  thunk_FUN_06088ab8();
}


// ===== FUN_06088538 @ 06088538

int FUN_06088538(int param_1)

{
  undefined8 in_r0_r1;
  undefined4 *puVar1;
  int iVar2;
  BADSPACEBASE *in_sp;
  undefined8 *puVar3;
  undefined1 auStack_c [8];
  
  op_push_rets_rl();
  puVar1 = (undefined4 *)0xffe0f0;
  iVar2 = 0x104b50;
  if (uRam00ffe0f4 < 10) {
    *(undefined4 *)in_r0_r1 = uRam00104b5c;
    *(undefined4 *)((ulonglong)in_r0_r1 >> 0x20) = 0;
    op_pop_pc_rl();
    puVar3 = (undefined8 *)auStack_c;
    iVar2 = func_0x0bfa5194();
    FUN_06088538((undefined1 *)((int)puVar3 + 4),iVar2 == 0);
    return -((uint)*puVar3 / 1000);
  }
  if (param_1 != 0) {
    FUN_06088a6a();
  }
  do {
    do {
      iRam00106240 = *(int *)(iVar2 + 0xc);
      uRam00106244 = *puVar1;
    } while (puVar1[1] != puVar1[1]);
  } while (iRam00106240 != *(int *)(iVar2 + 0xc));
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8(0,0);
}


// ===== FUN_0608865a @ 0608865a

int FUN_0608865a(void)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  int *piVar3;
  undefined1 auStack_c [8];
  
  piVar3 = (int *)auStack_c;
  iVar1 = func_0x0bfa5194();
  FUN_06088538((undefined1 *)((int)piVar3 + 4),piVar3,iVar1 == 0);
  piVar3[2] = unaff_retaddr;
  iVar1 = FUN_0608865a((piVar3[1] & 0x3ffffU) * 10000 + *piVar3);
  piVar2 = (int *)0x1063a0;
  do {
    piVar2 = (int *)*piVar2;
    if (piVar2 == (int *)0x1063a0) {
      return 0;
    }
  } while (piVar2[2] != iVar1);
  return (int)piVar2;
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


// ===== FUN_06088690 @ 06088690

int FUN_06088690(int param_1)

{
  int *piVar1;
  
  piVar1 = (int *)0x1063a0;
  do {
    piVar1 = (int *)*piVar1;
    if (piVar1 == (int *)0x1063a0) {
      return 0;
    }
  } while (piVar1[2] != param_1);
  return (int)piVar1;
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
      FUN_0608ead8();
    }
    if (param_1 == 0) {
      FUN_0608ead8();
    }
    *puVar5 = (char)param_1;
    bRam00105765 = 7;
    iVar3 = op_ext_b0_u(in_cnum);
    puVar4 = (uint *)((1 - iVar3) * 0x800 + 0xffe1a0);
    *puVar4 = *puVar4 | 1 << 1 - iVar3;
    do {
    } while ((bRam00105765 & 2) != 0);
    uVar8 = FUN_060875d8(*puVar5);
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
      FUN_060875ee(cRam00105764);
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
    FUN_06087610();
    puVar7 = (undefined4 *)puVar6;
  }
  *puVar7 = unaff_retaddr;
  iVar3 = *(int *)(in_cnum * 4 + 0x1083fc) + -1;
  *(int *)(in_cnum * 4 + 0x1083fc) = iVar3;
  if (iVar3 == 0) {
    FUN_0608761e();
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


// ===== FUN_06088ede @ 06088ede

undefined1 FUN_06088ede(void)

{
  return uRam001079b8;
}


// ===== FUN_06088f24 @ 06088f24

void FUN_06088f24(void)

{
  int in_cnum;
  
  *(undefined4 *)(in_cnum * 0x800 + 0xffe21c) = 0;
  *(undefined4 *)(in_cnum * 0x800 + 0xffe218) = 0x7fffffff;
  return;
}


// ===== FUN_06088faa @ 06088faa

void FUN_06088faa(int param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined8 *puVar5;
  uint *puVar6;
  undefined1 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  undefined1 *puVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  
  op_push_rets_rl();
  uRam00f2c044 = 0;
  puVar6 = (uint *)0xf2c254;
  uVar10 = 0x3fc7;
  uRam00f2c254 = uRam00f2c254 & 0x3fc7 | 0x38;
  FUN_0608aef8(0xd7);
  *puVar6 = *puVar6 & 0xeff;
  uVar14 = FUN_0608aef8(0x1ae);
  if (param_1 != 0) {
    uVar8 = 0x38;
    uVar12 = 0xffffc038;
    for (uVar9 = 7; 3 < uVar9; uVar9 = uVar9 - 1) {
      *puVar6 = *puVar6 & uVar10 | uVar8 & uVar12;
      FUN_0608aef8(0xd7);
      *puVar6 = *puVar6 & 0xeff;
      FUN_0608aef8(0x1ae);
      uVar1 = func_0x0bf82430(0xffffffff);
      *(undefined4 *)((int)param_2 + uVar9 * 4) = uVar1;
      uVar8 = uVar8 - 8;
    }
    iVar2 = *(int *)(param_2 + 2);
    *(int *)((int)param_2 + 0xc) = iVar2 + -400;
    iVar3 = iVar2 + -600;
    *(int *)(param_2 + 1) = iVar3;
    uVar14 = CONCAT44(iVar2 + -800,iVar3);
    *param_2 = CONCAT44(iVar3,iVar2 + -800);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  uRam00f2c044 = 0;
  uVar10 = 0x3fc7;
  puVar6 = (uint *)0xf2c254;
  uRam00f2c254 = uRam00f2c254 & 0x3fc7;
  FUN_0608aef8(0xd7);
  *puVar6 = 0x1ae;
  uVar15 = FUN_0608aef8();
  puVar4 = (undefined1 *)0x0;
  if ((int)((ulonglong)uVar14 >> 0x20) != 0) {
    uVar8 = 7;
    while( true ) {
      puVar4 = (undefined1 *)((ulonglong)uVar14 >> 0x20);
      puVar5 = (undefined8 *)uVar14;
      if (uVar8 < 4) break;
      *puVar6 = *puVar6 & uVar10;
      FUN_0608aef8(0xd7);
      uVar9 = op_insert_rrii(*puVar6 >> 3,3,8);
      *puVar6 = uVar9;
      FUN_0608aef8(0x1ae);
      uVar1 = func_0x0bf82430(0xffffffff);
      *(undefined4 *)((int)uVar14 + uVar8 * 4) = uVar1;
      uVar8 = uVar8 - 1;
    }
    iVar2 = *(int *)(puVar5 + 2);
    *(int *)((int)puVar5 + 0xc) = iVar2 + -400;
    iVar3 = iVar2 + -600;
    *(int *)(puVar5 + 1) = iVar3;
    uVar15 = CONCAT44(iVar2 + -800,iVar3);
    *puVar5 = CONCAT44(iVar3,iVar2 + -800);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar13 = (undefined1 *)((int)in_sp + -0x40);
  puVar6 = (uint *)0xf2c254;
  uVar10 = 0;
  puVar7 = (undefined1 *)((int)in_sp + -0x40);
  if ((int)((ulonglong)uVar15 >> 0x20) != 0) {
    uVar10 = uRam00f2c254 & 0xf;
    iVar2 = func_0x0bf82430(0x10006);
    if ((uint)(iVar2 << 2) < 0xe74) {
      uVar10 = uVar10 | 0xffffff80;
      *(undefined1 *)uVar15 = (char)uVar10;
      *puVar4 = (char)uVar10;
      puVar7 = puVar13;
    }
    else {
      puVar11 = puVar6 + -0x84;
      uVar8 = *puVar11;
      *puVar11 = *puVar11 & 4;
      FUN_0608aef8(100);
      *puVar11 = *puVar11 & 1;
      FUN_06088faa((int)((ulonglong)uVar15 >> 0x20),puVar13 + 0x20);
      puVar7 = (undefined1 *)uVar15;
      FUN_06089044((int)((ulonglong)uVar15 >> 0x20),puVar13);
      for (iVar2 = 0; iVar2 != 8; iVar2 = iVar2 + 1) {
      }
      *puVar7 = 0;
      for (iVar2 = 0; iVar2 != 8; iVar2 = iVar2 + 1) {
      }
      *puVar4 = 0;
      uVar10 = op_insert_rrii(*puVar6 >> 3,3,0x1d);
      *puVar6 = uVar10;
      puVar7 = puVar13;
      if ((uVar8 & 1) != 0) {
        *puVar11 = *puVar11 | 1;
        uVar10 = FUN_0608aef8(3,0xffffffff);
        *puVar11 = *puVar11 | 4;
        puVar7 = puVar13;
      }
    }
  }
  op_pop_pc_rl();
  *(undefined4 *)(puVar7 + 0x3c) = unaff_retaddr;
  *(uint *)(in_cnum * 4 + 0x105bc4) = uVar10;
  uRam00f2c128 = uRam00f2c128 & 0xcff | 0xb;
                    /* WARNING: Subroutine does not return */
  p33_soft_reset();
}


// ===== FUN_06089044 @ 06089044

void FUN_06089044(undefined1 *param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  undefined1 *puVar10;
  undefined8 uVar11;
  
  op_push_rets_rl();
  uRam00f2c044 = 0;
  uVar5 = 0x3fc7;
  puVar7 = (uint *)0xf2c254;
  uRam00f2c254 = uRam00f2c254 & 0x3fc7;
  FUN_0608aef8(0xd7);
  *puVar7 = 0x1ae;
  uVar11 = FUN_0608aef8();
  if (param_1 != (undefined1 *)0x0) {
    for (uVar8 = 7; 3 < uVar8; uVar8 = uVar8 - 1) {
      *puVar7 = *puVar7 & uVar5;
      FUN_0608aef8(0xd7);
      uVar3 = op_insert_rrii(*puVar7 >> 3,3,8);
      *puVar7 = uVar3;
      FUN_0608aef8(0x1ae);
      uVar1 = func_0x0bf82430(0xffffffff);
      *(undefined4 *)((int)param_2 + uVar8 * 4) = uVar1;
    }
    iVar2 = *(int *)(param_2 + 2);
    *(int *)((int)param_2 + 0xc) = iVar2 + -400;
    iVar4 = iVar2 + -600;
    *(int *)(param_2 + 1) = iVar4;
    uVar11 = CONCAT44(iVar2 + -800,iVar4);
    *param_2 = CONCAT44(iVar4,iVar2 + -800);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar10 = (undefined1 *)((int)in_sp + -0x40);
  puVar7 = (uint *)0xf2c254;
  uVar5 = 0;
  puVar6 = (undefined1 *)((int)in_sp + -0x40);
  if ((int)((ulonglong)uVar11 >> 0x20) != 0) {
    uVar5 = uRam00f2c254 & 0xf;
    iVar2 = func_0x0bf82430(0x10006);
    if ((uint)(iVar2 << 2) < 0xe74) {
      uVar5 = uVar5 | 0xffffff80;
      *(undefined1 *)uVar11 = (char)uVar5;
      *param_1 = (char)uVar5;
      puVar6 = puVar10;
    }
    else {
      puVar9 = puVar7 + -0x84;
      uVar8 = *puVar9;
      *puVar9 = *puVar9 & 4;
      FUN_0608aef8(100);
      *puVar9 = *puVar9 & 1;
      FUN_06088faa((int)((ulonglong)uVar11 >> 0x20),puVar10 + 0x20);
      puVar6 = (undefined1 *)uVar11;
      FUN_06089044((int)((ulonglong)uVar11 >> 0x20),puVar10);
      for (iVar2 = 0; iVar2 != 8; iVar2 = iVar2 + 1) {
      }
      *puVar6 = 0;
      for (iVar2 = 0; iVar2 != 8; iVar2 = iVar2 + 1) {
      }
      *param_1 = 0;
      uVar5 = op_insert_rrii(*puVar7 >> 3,3,0x1d);
      *puVar7 = uVar5;
      puVar6 = puVar10;
      if ((uVar8 & 1) != 0) {
        *puVar9 = *puVar9 | 1;
        uVar5 = FUN_0608aef8(3,0xffffffff);
        *puVar9 = *puVar9 | 4;
        puVar6 = puVar10;
      }
    }
  }
  op_pop_pc_rl();
  *(undefined4 *)(puVar6 + 0x3c) = unaff_retaddr;
  *(uint *)(in_cnum * 4 + 0x105bc4) = uVar5;
  uRam00f2c128 = uRam00f2c128 & 0xcff | 0xb;
                    /* WARNING: Subroutine does not return */
  p33_soft_reset();
}


// ===== FUN_06089250 @ 06089250

undefined4 FUN_06089250(void)

{
  uint *puVar1;
  
  sfc_suspend(0);
  uRam00f2a418 = uRam00f2a418 & 0xbc0 | 0xf80;
  op_push_rets_rl();
  if ((iRam00105c68 != 0) && (iRam00105c54 != 0)) {
    puVar1 = *(uint **)(iRam00105c68 + 0x18);
    uRam00106210 = *puVar1 & 0xd00 | 0x4040;
    uRam00106214 = puVar1[1] & 0xff01;
    uRam00106218 = puVar1[5] & 1 | 0x50;
  }
  if ((iRam00105d08 != 0) && (iRam00105cf4 != 0)) {
    puVar1 = *(uint **)(iRam00105d08 + 0x18);
    uRam0010621c = *puVar1 & 0xd00 | 0x4040;
    uRam00106220 = puVar1[1] & 0xff01;
    uRam00106224 = puVar1[5] & 1 | 0x50;
  }
  op_pop_pc_rl();
  if ((iRam00105c68 != 0) && (iRam00105c54 != 0)) {
    puVar1 = *(uint **)(iRam00105c68 + 0x18);
    *puVar1 = uRam00106210;
    puVar1[1] = uRam00106214;
    puVar1[5] = uRam00106218;
  }
  if ((iRam00105d08 != 0) && (iRam00105cf4 != 0)) {
    puVar1 = *(uint **)(iRam00105d08 + 0x18);
    *puVar1 = uRam0010621c;
    puVar1[1] = uRam00106220;
    puVar1[5] = uRam00106224;
  }
  return 0;
}


// ===== FUN_06089408 @ 06089408

void FUN_06089408(void)

{
  uRam00ff0400 = uRam00ff0400 & 1;
  return;
}


// ===== FUN_0608978a @ 0608978a

undefined4 FUN_0608978a(void)

{
  int in_cnum;
  
  rep_unspec(0x18,2);
  return *(undefined4 *)(in_cnum * 4 + 0x1083dc);
}


// ===== FUN_060899dc @ 060899dc

void FUN_060899dc(void)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  int in_cnum;
  
  iVar1 = sfc_suspend(0);
  op_push_rets_rl();
  uRam00fd0604 = 1;
  uRam00fd0608 = (uint)(iRam00107a50 * iVar1) / 1000000;
  uRam00fd0600 = 0xc01;
  *(undefined4 *)(in_cnum * 0x800 + 0xffe1b0) = 6;
  do {
    iVar1 = op_ext_l_s(uRam00fd0600);
  } while (-1 < iVar1);
  uRam00fd0600 = 0;
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar1 = 0xfd5300;
  if ((uRam00fd6014 & 0x10000) == 0) {
    puVar9 = (uint *)0xfd530c;
    puVar3 = (uint *)0xfd5320;
    puVar5 = (uint *)0xfd5310;
    puVar8 = (uint *)0xfd5314;
    puVar4 = (uint *)0xfd5308;
    uVar7 = 8;
    uVar2 = 0xfffffff7;
    uVar6 = uRam00fd5508;
    if (cRam00104db5 != '\x04') goto LAB_06089b24;
  }
  else {
    puVar9 = (uint *)0xfd550c;
    puVar4 = (uint *)0xfd5508;
    uRam00fd550c = uRam00fd550c & 8;
    puVar3 = (uint *)0xfd5520;
    uRam00fd5520 = uRam00fd5520 & 8;
    uRam00fd5510 = uRam00fd5510 & 8;
    uRam00fd5514 = uRam00fd5514 & 8;
    puVar5 = (uint *)0xfd5510;
    puVar8 = (uint *)0xfd5514;
    uVar7 = 0x10;
    uVar2 = 0xffffffef;
    uVar6 = uRam00fd5508 | 8;
    if (cRam00104db5 != '\x04') goto LAB_06089b24;
    uRam00fd550c = 0;
    uRam00fd5520 = 0;
    uRam00fd5510 = 0;
    uRam00fd5514 = 0;
    uRam00fd5508 = uRam00fd5508 | 0xc;
  }
  uVar6 = uRam00fd5508;
LAB_06089b24:
  uRam00fd5508 = uVar6;
  uRam00fd5320 = 0;
  uRam00fd5314 = 0;
  uRam00fd5310 = 0;
  uRam00fd530c = 0;
  *puVar9 = *puVar9 & uVar2;
  *puVar3 = *puVar3 & uVar2;
  *puVar8 = *puVar8 & uVar2;
  *puVar5 = *puVar5 | uVar7;
  *puVar4 = *puVar4 | uVar7;
  uRam00fd5300 = uRam00fd5300 & 0x10;
  uRam00fd5308 = uRam00fd5308 & 0x10;
  uVar6 = uRam00fd6014;
  delay_tmr2_lrc(100);
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & ((uVar6 >> 0x10 & 1) << 3 ^ 8) - 0x11;
  *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0x10;
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0x10;
  *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0x10;
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0x10;
  *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) | 0x10;
  op_pop_pc_rl();
  uRam00f2c160 = 0xff;
  uRam00f2c164 = 0xff;
  uRam00f2c19c = 0xff;
  uRam00f2c1a0 = 0xf2c044;
  uRam00f2c044 = uRam00f2c044 & 0x7fbf | 0x40;
  uRam00f2c124 = uRam00f2c124 & 0x7fbf | 0x40;
  return;
}


// ===== FUN_06089d32 @ 06089d32

void FUN_06089d32(void)

{
  msys_to_p11_sync_cmd(3);
  uRam00107a40 = uRam00f2a600;
  uRam00f2a600 = 2;
  uRam00f2a618 = 2;
  uRam00fd0004 = uRam00fd0004 | 4;
  op_pop_srmask(0x3829);
  op_pop_rmask(0xffff);
  return;
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


// ===== FUN_0608a034 @ 0608a034

void FUN_0608a034(void)

{
  int in_cnum;
  BADSPACEBASE *in_sp;
  
  op_push_rmask(0xffff);
  op_push_srmask(0x3829);
  *(BADSPACEBASE **)(in_cnum * 4 + 0x107a38) = in_sp;
  FUN_06089d32();
  return;
}


// ===== FUN_0608a054 @ 0608a054

int FUN_0608a054(void)

{
  FUN_06088ee8(0);
  return iRam00f2a90c - iRam00f2a914;
}


// ===== FUN_0608a060 @ 0608a060

int FUN_0608a060(void)

{
  return iRam00f2a90c - iRam00f2a914;
}


// ===== FUN_0608a06e @ 0608a06e

/* WARNING: Possible PIC construction at 0x0608a2f6: Changing call to branch */
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

undefined1 FUN_0608a06e(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ulonglong uVar6;
  uint *extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  undefined4 uVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  uint *puVar15;
  uint uVar16;
  int *piVar17;
  uint *puVar18;
  uint *puVar19;
  uint *puVar20;
  uint *puVar21;
  uint *puVar22;
  uint *puVar23;
  int *piVar24;
  uint *puVar25;
  undefined4 unaff_retaddr;
  undefined4 in_cnum;
  BADSPACEBASE *in_sp;
  int *piVar26;
  
  op_push_rets_rl();
  FUN_0608a060();
  uVar1 = FUN_06089da2();
  if (uVar1 < 0x334) {
    iVar9 = 0xf2a904;
    uRam00f2a904 = uRam00f2a904 | 0x10;
    iVar2 = __tcnt_us(10000);
    iVar3 = *(int *)(iVar9 + 8);
    *(undefined4 *)(iVar9 + 8) = 0x3ff;
    *(int *)(iVar9 + 8) = iVar2 + iVar3;
    uRam00104db0 = 1;
    op_pop_pc_rl();
  }
  iVar3 = FUN_06089d94();
  if (iVar3 == 0) {
    uRam00f2c128 = uRam00f2c128 & 0xcff | 0xe;
    func_0x0bf822c6();
  }
  op_pop_pc_rl();
  piVar26 = (int *)((int)in_sp + -4);
  *(undefined4 *)((int)in_sp + -4) = unaff_retaddr;
  FUN_06089da2(uRam00f2a914);
  while( true ) {
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
    if ((CONCAT44(in_cnum,0x108014) & 0xff00000000) == 0) {
      uRam00ffe0ec = uRam00108040;
      uRam00ffe0f0 = uRam00108044;
      uRam00ffe0f4 = uRam00108048;
    }
    op_pop_pc_rl();
    op_push_rets_rl();
    if (iRam00108cc0 != 3) break;
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
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  piVar24 = (int *)0x108ca8;
  if ((cRam00108cc7 == '\0') || ((cRam00108d02 == '\0' && (iVar3 = func_0x0bfc05a0(), iVar3 == 0))))
  {
    op_pop_pc_rl();
    return uRam00104db0;
  }
  FUN_06088a6a();
  func_0x0bfc05c0();
  uVar1 = func_0x0bfc0624(piVar24);
  piVar17 = piVar24 + 3;
  uVar4 = func_0x0bfc0624(piVar17);
  if (uVar4 < uVar1) {
    uVar1 = uVar4;
  }
  if (uVar1 == 0) goto LAB_0608ad70;
  puVar18 = (uint *)0xf2a800;
  uVar6 = (ulonglong)uRam00f2a800 << 0x20;
  if ((uVar6 & 0x2000000000) != 0) {
    func_0x0bf7fc06();
    uVar6 = (ulonglong)*(uint *)((*puVar18 & 0x1f) * 4 + 0x6060f9c);
  }
  uVar4 = (uint)((int)uVar6 * 0xf7a) >> 1;
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
  puVar10 = puVar18 + 0x41;
  puVar22 = (uint *)0xfd3e00;
  if ((int *)*piVar24 == piVar24) {
    iVar3 = func_0x0bfc06a4(uVar1);
    if (iVar3 == 0) goto LAB_0608ad70;
    iVar2 = func_0x0bfc06dc();
    iVar3 = -2;
    if (iVar2 != -2) {
      *puVar22 = *puVar22 | 0x40;
      iVar3 = iVar2;
    }
  }
  else {
    iVar3 = func_0x0bfc06a4(*puVar10);
    if (iVar3 == 0) goto LAB_0608ad70;
    iVar3 = func_0x0bfc06dc(*puVar10);
  }
  iVar2 = func_0x0bfc06ee();
  piVar24[6] = iVar2;
  func_0x0bfc0724(piVar24);
  func_0x0bfc0724(piVar17);
  uVar4 = 0;
  func_0x0bfc0682(0);
  func_0x0bfc0694(0);
  func_0x0bfc075a();
  uVar1 = op_insert_rrii((uint)bRam001081d9,8,8);
  bRam001081d8 = (byte)(uVar1 & 0xc70);
  bRam001081d9 = (byte)((uVar1 & 0xc70) >> 8);
  uRam00f27f91 = (undefined1)uVar4;
  uRam00f27f8d = uRam00f27f91;
  if (*(char *)((int)piVar24 + 0x5a) == '\x01') {
    uVar7 = op_insert_rrii((uint)bRam001081d9,8,0x18);
    bRam001081d8 = (byte)uVar7 | 1;
    uRam00f27f8d = 1;
    bRam001081d9 = bRam001081d8;
    if (*(char *)((int)piVar24 + 0x5a) == '\x01') {
      uVar7 = op_insert_rrii((uint)bRam001081d8,8,0x18);
      bRam001081d8 = (byte)uVar7 | 4;
      bRam001081d9 = bRam001081d8;
    }
  }
  puVar25 = (uint *)0xfd0004;
  uRam00fd0018 = uRam00fd0018 | 1;
  uRam00fd001c = uRam00fd001c & 0xfffff8ff | 0xf40;
  uRam00108148 = uRam00fd0014;
  uVar1 = op_insert_rrii((uint)bRam001081d9,8,8);
  puVar20 = (uint *)0xfd1920;
  puVar10 = puVar22 + 0x200;
  puVar11 = puVar22 + 0x240;
  uRam00fd0014 = uVar4;
  if ((uVar1 & 1) == 0) {
    uRam00104db8 = *puVar10;
    uRam00104dbc = *puVar11;
    *puVar10 = *puVar10 & 3;
    *puVar11 = *puVar11 & 3;
    uRam00fd1920 = uRam00fd1920 & 1;
    FUN_060899dc();
LAB_0608a6f6:
    puVar13 = puVar18 + 0x41;
    hw_close_flash();
  }
  else {
    *piVar26 = iVar3;
    uRam00fd1940 = 0xa80;
    uVar4 = op_uextra_rrii(uRam00fd1920,6,5);
    uVar12 = op_uextra_rrii(uRam00fd1920,0xb,4);
    iVar3 = op_uextra_rrii(uRam00fd1920,0xf,4);
    do {
      do {
        uRam00fd1920 = (uVar4 & 0x3b) << 6 | (uVar12 & 1) << 0xb | 0x36080001;
      } while (uVar4 != 3);
    } while ((uVar12 != 3) || (iVar3 != 3));
    uVar7 = op_uextra_rrii(uVar1,3,1);
    uVar7 = op_insert_rrii(uVar7,0x13,1);
    uVar6 = (CONCAT44(uVar7,uVar1 << 0xc | uVar1 >> 2) | 0x9503) & 0xffffffff0000a187;
    uRam00fd1924 = (uint)uVar6 | (uint)(uVar6 >> 0x20);
    uVar6 = CONCAT44(uVar1 << 2,uVar1 >> 1) & 0xffffffff00000078;
    uVar4 = (uint)(uVar6 >> 0x20);
    uVar6 = CONCAT44(uVar4,(uint)uVar6 | uVar4 & 0xe40) & 0xd80ffffffff;
    uRam00fd1928 = (uint)uVar6 | (uint)(uVar6 >> 0x20) | 0x286;
    puVar10 = puVar22 + 0x200;
    puVar11 = puVar22 + 0x240;
    uRam00104db8 = *puVar10;
    uRam00104dbc = *puVar11;
    *puVar10 = *puVar10 & 3;
    *puVar11 = *puVar11 & 3;
    if ((uVar1 & 1) == 0) {
      uRam00fd1920 = uRam00fd1920 & 1;
      FUN_060899dc();
      iVar3 = *piVar26;
      goto LAB_0608a6f6;
    }
    FUN_060899dc();
    iVar3 = *piVar26;
    puVar13 = puVar18 + 0x41;
  }
  uVar6 = CONCAT44(*puVar13,*puVar13) & 0x8000000020;
  *(byte *)((int)piVar24 + 0x1d) = (byte)uVar6 | (byte)(uVar6 >> 0x20);
  *puVar25 = *puVar25 | 8;
  puVar15 = (uint *)0x107a40;
  puVar14 = puVar13 + -0xc1;
  puVar21 = puVar10 + 0x340;
  puVar23 = puVar10 + 0x3c0;
  puVar8 = puVar10 + 0x680;
  if (piVar24[6] == 3) {
    uRam00107b04 = puVar10[0x342];
    uRam00107b08 = puVar10[0x343];
    uRam00107b0c = puVar10[0x348];
    uRam00107b10 = puVar10[0x344];
    uRam00107b14 = puVar10[0x345];
    uRam00107b18 = puVar10[0x346];
    uRam00107b1c = puVar10[0x347];
    uRam00107b20 = *puVar21;
    uRam00107b24 = puVar10[0x3c2];
    uRam00107b28 = puVar10[0x3c3];
    uRam00107b2c = puVar10[0x3c8];
    uRam00107b30 = puVar10[0x3c4];
    uRam00107b34 = puVar10[0x3c5];
    uRam00107b38 = puVar10[0x3c6];
    uRam00107b3c = puVar10[0x3c7];
    uRam00107b40 = *puVar23;
    uRam00107b44 = *puVar8;
    uRam0010814c = puVar25[5];
    puVar8 = (uint *)0x10814c;
    uRam00108150 = puVar25[6];
    uRam00108154 = puVar25[7];
    uRam00108158 = puVar25[8];
    uRam0010815c = puVar25[4];
    uRam00108160 = *puVar25;
    uRam00108164 = puVar25[1];
    uRam00108168 = puVar25[2];
    uRam0010816c = puVar25[3];
    uRam00108170 = *puVar10;
    uRam00108174 = puVar10[1];
    uRam00108178 = puVar10[2];
    uRam0010817c = puVar10[3];
    uRam00108180 = puVar10[4];
    uRam00108184 = puVar10[5];
    uRam00108188 = puVar10[6];
    uRam0010818c = *puVar11;
    puVar19 = (uint *)0x10818c;
    uRam00108190 = puVar11[1];
    uRam00108194 = puVar11[2];
    uRam00108198 = puVar11[3];
    uRam0010819c = puVar11[4];
    uRam001081a0 = puVar11[5];
    uRam001081a4 = puVar11[6];
    uRam001081a8 = *puVar20;
    uRam001081ac = puVar20[1];
    uRam001081b0 = puVar20[2];
    uRam001081b4 = puVar20[8];
    puVar15 = puVar13 + 0x68f;
    *puVar15 = 1;
    puVar13[0x690] = 1;
    puVar13[0x691] = 1;
    puVar13[0x692] = 1;
    puVar13[0x693] = 1;
    puVar13[0x694] = 1;
    *puVar15 = 3;
    puVar13[0x690] = 3;
    puVar13[0x691] = 3;
    puVar13[0x692] = 3;
    puVar13[0x693] = 3;
    puVar13[0x694] = 3;
    puVar13[-0xb7] = puVar13[-0xb7] | 0x80;
    FUN_0608a034();
    puVar25[5] = *puVar8;
    puVar25[6] = puVar8[1];
    puVar25[7] = puVar8[2];
    puVar25[8] = puVar8[3];
    puVar25[4] = puVar8[4];
    *puVar25 = puVar8[5];
    puVar25[1] = puVar8[6];
    puVar25[2] = puVar8[7];
    puVar25[3] = puVar8[8];
    *puVar10 = puVar8[9];
    puVar10[1] = puVar8[10];
    puVar10[2] = puVar8[0xb];
    puVar10[3] = puVar8[0xc];
    puVar10[4] = puVar8[0xd];
    puVar10[5] = puVar8[0xe];
    puVar10[6] = puVar8[0xf];
    *puVar11 = *puVar19;
    puVar11[1] = puVar19[1];
    puVar11[2] = puVar19[2];
    puVar11[3] = puVar19[3];
    puVar11[4] = puVar19[4];
    puVar11[5] = puVar19[5];
    puVar11[6] = puVar19[6];
    *puVar20 = puVar19[7];
    puVar20[1] = puVar19[8];
    puVar20[2] = puVar19[9];
    puVar20[8] = puVar19[10];
    puVar21[2] = *extraout_r1;
    puVar21[3] = extraout_r1[1];
    puVar21[8] = extraout_r1[2];
    puVar21[4] = extraout_r1[3];
    puVar21[5] = extraout_r1[4];
    puVar21[6] = extraout_r1[5];
    puVar21[7] = extraout_r1[6];
    *puVar21 = extraout_r1[7];
    puVar23[2] = extraout_r1[8];
    puVar23[3] = extraout_r1[9];
    puVar23[8] = extraout_r1[10];
    puVar23[4] = extraout_r1[0xb];
    puVar23[5] = extraout_r1[0xc];
    puVar23[6] = extraout_r1[0xd];
    puVar23[7] = extraout_r1[0xe];
    *puVar23 = extraout_r1[0xf];
    puVar8 = puVar21 + 0x340;
    *puVar8 = extraout_r1[0x10];
    puVar15[1] = 0;
    puVar15[5] = 0;
    puVar15[4] = 0;
  }
  else {
    msys_to_p11_sync_cmd(3);
    *puVar15 = *puVar14;
    *puVar14 = 1;
    puVar14[6] = 1;
    *puVar25 = *puVar25 | 4;
  }
  do {
    puVar18[2] = 0xff;
    puVar18[2] = 0xee;
    puVar18[2] = 0xab;
    puVar18[2] = 0xe;
    puVar18[2] = 0x55;
  } while ((puVar22[1] & 1) == 0);
  iVar2 = piVar24[6];
  if (iVar2 == 1) {
    do {
    } while ((puVar14[3] & 4) == 0);
    uVar1 = 4;
LAB_0608a9fe:
    puVar14[2] = uVar1;
    *puVar14 = 0x20;
  }
  else {
    if (iVar2 == 3) {
      uVar1 = 2;
      goto LAB_0608a9fe;
    }
    if (iVar2 == 2) {
      do {
      } while ((puVar14[3] & 1) == 0);
      uVar1 = 1;
      goto LAB_0608a9fe;
    }
  }
  if ((*puVar20 & 1) == 0) {
    puVar23[4] = puVar23[4] | 0x10;
    puVar23[2] = puVar23[2] | 0x10;
    puVar21[4] = puVar21[4] | 8;
    puVar21[2] = puVar21[2] | 8;
    puVar21[7] = puVar21[7] & 0x10;
    puVar21[6] = puVar21[6] & 0x10;
    *puVar21 = *puVar21 | 0x10;
    puVar21[2] = puVar21[2] & 0x10;
    delay_tmr2_lrc(10);
    puVar21[6] = puVar21[6] | 0x10;
    delay_tmr2_lrc(10);
    puVar21[7] = puVar21[7] | 0x10;
    if ((CONCAT44(puVar8[5],0x104db5) & 0x1000000000000) == 0) {
      *puVar21 = *puVar21 | 8;
      puVar21[2] = puVar21[2] & 8;
      puVar21[4] = puVar21[4] & 8;
      puVar21[5] = puVar21[5] & 8;
      puVar21[4] = puVar21[4] & 1;
      puVar21[5] = puVar21[5] & 1;
      puVar21[2] = puVar21[2] & 1;
      puVar21[3] = puVar21[3] | 2;
      puVar21[4] = puVar21[4] | 2;
      puVar21[5] = puVar21[5] & 2;
      puVar21[2] = puVar21[2] | 2;
      puVar21[3] = puVar21[3] | 4;
      puVar21[4] = puVar21[4] | 4;
      puVar21[5] = puVar21[5] & 4;
      puVar21[2] = puVar21[2] | 4;
      if (cRam00104db5 == '\x04') {
        puVar21[3] = puVar21[3] | 0x20;
        puVar21[4] = puVar21[4] | 0x20;
        puVar21[5] = puVar21[5] & 0x20;
        puVar21[2] = puVar21[2] | 0x20;
        goto LAB_0608aafc;
      }
    }
    else {
      *puVar23 = *puVar23 | 0x10;
      puVar23[2] = puVar23[2] & 0x10;
      puVar23[4] = puVar23[4] & 0x10;
      puVar23[5] = puVar23[5] & 0x10;
      puVar21[3] = puVar21[3] | 1;
      puVar21[4] = puVar21[4] & 1;
      puVar21[5] = puVar21[5] & 1;
      puVar21[2] = puVar21[2] & 1;
      puVar21[3] = puVar21[3] | 2;
      puVar21[4] = puVar21[4] | 2;
      puVar21[5] = puVar21[5] & 2;
      puVar21[2] = puVar21[2] | 2;
      puVar23[3] = puVar23[3] | 8;
      puVar23[4] = puVar23[4] | 8;
      puVar23[5] = puVar23[5] & 8;
      puVar23[2] = puVar23[2] | 8;
      if (cRam00104db5 == '\x04') {
        puVar23[3] = puVar23[3] | 4;
        puVar23[4] = puVar23[4] | 4;
        puVar23[5] = puVar23[5] & 4;
        puVar23[2] = puVar23[2] | 4;
LAB_0608aafc:
        puVar21[3] = puVar21[3] | 0x40;
        puVar21[4] = puVar21[4] | 0x40;
        puVar21[5] = puVar21[5] & 0x40;
        puVar21[2] = puVar21[2] | 0x40;
      }
    }
  }
  FUN_0608a054();
  puVar14[0x715] = puVar14[0x715] & 0x3fc7;
  FUN_0608a06e();
  iVar2 = FUN_06089d94();
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0608a0c2();
  }
  if ((*puVar20 & 1) == 0) {
    uVar1 = *puVar20;
    uVar4 = puVar20[1];
    uVar12 = puVar20[2];
    *puVar20 = *puVar20 & 0x660;
    puVar20[1] = puVar20[1] & 0xfff7bdff;
    puVar20[2] = puVar20[2] & 0xd90;
    *puVar20 = *puVar20 | 1;
    iVar9 = piVar24[0xce];
    FUN_0608b07e();
    FUN_0608afac(0x10eafa);
    FUN_0608a184();
    iVar5 = FUN_0608b088();
    if (iVar5 == 0) {
      uVar7 = op_ext_l_u(iVar9);
      delay_tmr2_lrc(uVar7);
    }
    else {
      xosc_adet_en(1);
      iVar9 = FUN_0608a0c2();
      do {
        iVar5 = FUN_0608a0c2();
        uVar16 = iVar5 - iVar9;
        FUN_0608a06e();
        iVar5 = FUN_0608aff4();
        if (3000 < uVar16) break;
      } while (iVar5 == 0);
      xosc_adet_en(0);
    }
    *puVar20 = *puVar20 | uVar1 & 0x660;
    puVar20[1] = puVar20[1] | uVar4 & 0x84200;
    puVar20[2] = puVar20[2] | uVar12 & 0xd90;
    iVar9 = 1 - iVar2;
    iRam00104dc4 = FUN_0608a0c2();
    iRam00104dc4 = iVar9 + iRam00104dc4;
    iVar9 = FUN_06089d94();
    if (iVar9 != 0) {
      uVar1 = extraout_r1_00;
      if (extraout_r1_00 <= uRam00104dc8) {
        iVar9 = utof(uRam00104dc8);
        iVar5 = utof(extraout_r1_00);
        uVar1 = op_ftou_trunc_rr(iVar5 * 0x3c23d70a + iVar9 * 0x3f7d70a4);
      }
      uRam00104dc8 = uVar1;
      piVar24[0xd0] = 1000;
    }
  }
  else {
    FUN_0608a184();
  }
  uVar4 = ~*(uint *)((int)puVar14 + 0xa2a) & 1;
  uVar1 = ~*puVar11 & 1;
  if (uVar1 != 0 || uVar4 != 0) {
    if (uVar1 != 0) {
      *puVar20 = *puVar20 | 0x680;
    }
    if (uVar4 != 0) {
      puVar20[2] = puVar20[2] | 0xf00;
      *(uint *)((int)puVar14 + 0xa2a) = *(uint *)((int)puVar14 + 0xa2a) | 1;
    }
    if (uVar1 != 0) {
      *puVar11 = *puVar11 | 1;
    }
    delay_tmr2_lrc(10);
    if (uVar4 != 0) {
      *(uint *)((int)puVar14 + 0xa2a) = *(uint *)((int)puVar14 + 0xa2a) | 2;
    }
    if (uVar1 != 0) {
      *puVar11 = *puVar11 | 2;
    }
    delay_tmr2_lrc(200);
  }
  puVar25[4] = uRam00108148;
  puVar25[6] = puVar25[6] & 0xfffff8ff | 0xec0;
  if ((bRam001081d8 & 1) == 0) {
    iVar2 = 1 - iVar2;
    piVar17 = (int *)0x104dc0;
    while( true ) {
      iVar9 = FUN_0608a0c2();
      *piVar17 = iVar2 + iVar9;
      iVar9 = FUN_06089d94();
      if ((iVar9 == 0) || (999 < extraout_r1_01)) break;
      delay_tmr2_lrc(10);
    }
  }
  FUN_0608a06e();
  uVar7 = 0x6051260;
  do {
    func_0x05f9acba(uVar7);
    iVar2 = func_0x05f9ac72(uVar7);
  } while (iVar2 != 0);
  func_0x0bfc09da(iVar3);
  if (*(char *)((int)piVar24 + 0x1d) != '\0') {
    func_0x0bf822c6();
  }
  func_0x0bfc0b6e(iVar3);
  puVar18 = (uint *)0x107a40;
  func_0x0bfc0b92(0);
  do {
  } while ((puVar14[3] & 0x20) == 0);
  puVar14[2] = 0x20;
  *puVar14 = *puVar18;
  func_0x0bfc0cc4();
LAB_0608ad70:
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608a0c2 @ 0608a0c2

/* WARNING: Possible PIC construction at 0x0608a2f6: Changing call to branch */
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

undefined1 FUN_0608a0c2(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ulonglong uVar6;
  uint *extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  undefined4 uVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  uint *puVar15;
  uint uVar16;
  int *piVar17;
  uint *puVar18;
  uint *puVar19;
  uint *puVar20;
  uint *puVar21;
  uint *puVar22;
  uint *puVar23;
  int *piVar24;
  uint *puVar25;
  undefined4 in_cnum;
  BADSPACEBASE *in_sp;
  int *piVar26;
  undefined1 auStack_84 [128];
  
  piVar26 = (int *)(auStack_84 + 0x80);
  FUN_06089da2(uRam00f2a914);
  while( true ) {
    op_push_rets_rl();
    iVar1 = op_ext_b0_u(in_cnum);
    iVar8 = iVar1 * 0x800;
    *(undefined4 *)(iVar8 + 0xffe1a8) = *(undefined4 *)(iVar1 * 8 + 0x107f04);
    *(undefined4 *)(iVar8 + 0xffe1ac) = *(undefined4 *)(iVar1 * 8 + 0x107f08);
    rep_unspec(4,0x20);
    *(undefined4 *)(iVar8 + 0xffe100) = *(undefined4 *)(iVar1 * 0x80 + 0x107f14);
    op_pop_pc_rl();
    op_push_rets_rl();
    iVar1 = op_ext_b0_u(in_cnum);
    iVar8 = iVar1 * 0x40;
    iVar1 = iVar1 * 0x800;
    *(undefined4 *)(iVar1 + 0xffe208) = *(undefined4 *)(iVar8 + 0x108014);
    *(undefined4 *)(iVar1 + 0xffe20c) = *(undefined4 *)(iVar8 + 0x108018);
    *(undefined4 *)(iVar1 + 0xffe22c) = *(undefined4 *)(iVar8 + 0x10801c);
    *(undefined4 *)(iVar1 + 0xffe228) = *(undefined4 *)(iVar8 + 0x108020);
    *(undefined4 *)(iVar1 + 0xffe224) = *(undefined4 *)(iVar8 + 0x108024);
    *(undefined4 *)(iVar1 + 0xffe220) = *(undefined4 *)(iVar8 + 0x108028);
    *(undefined4 *)(iVar1 + 0xffe21c) = *(undefined4 *)(iVar8 + 0x10802c);
    *(undefined4 *)(iVar1 + 0xffe218) = *(undefined4 *)(iVar8 + 0x108030);
    *(undefined4 *)(iVar1 + 0xffe1c0) = *(undefined4 *)(iVar8 + 0x108034);
    *(undefined4 *)(iVar1 + 0xffe200) = 0x3ff831;
    *(undefined4 *)(iVar1 + 0xffe0c4) = *(undefined4 *)(iVar8 + 0x10803c);
    if ((CONCAT44(in_cnum,0x108014) & 0xff00000000) == 0) {
      uRam00ffe0ec = uRam00108040;
      uRam00ffe0f0 = uRam00108044;
      uRam00ffe0f4 = uRam00108048;
    }
    op_pop_pc_rl();
    op_push_rets_rl();
    if (iRam00108cc0 != 3) break;
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
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  piVar24 = (int *)0x108ca8;
  if ((cRam00108cc7 == '\0') || ((cRam00108d02 == '\0' && (iVar1 = func_0x0bfc05a0(), iVar1 == 0))))
  {
    op_pop_pc_rl();
    return uRam00104db0;
  }
  FUN_06088a6a();
  func_0x0bfc05c0();
  uVar2 = func_0x0bfc0624(piVar24);
  piVar17 = piVar24 + 3;
  uVar3 = func_0x0bfc0624(piVar17);
  if (uVar3 < uVar2) {
    uVar2 = uVar3;
  }
  if (uVar2 == 0) goto LAB_0608ad70;
  puVar18 = (uint *)0xf2a800;
  uVar6 = (ulonglong)uRam00f2a800 << 0x20;
  if ((uVar6 & 0x2000000000) != 0) {
    func_0x0bf7fc06();
    uVar6 = (ulonglong)*(uint *)((*puVar18 & 0x1f) * 4 + 0x6060f9c);
  }
  uVar3 = (uint)((int)uVar6 * 0xf7a) >> 1;
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
  puVar10 = puVar18 + 0x41;
  puVar22 = (uint *)0xfd3e00;
  if ((int *)*piVar24 == piVar24) {
    iVar1 = func_0x0bfc06a4(uVar2);
    if (iVar1 == 0) goto LAB_0608ad70;
    iVar8 = func_0x0bfc06dc();
    iVar1 = -2;
    if (iVar8 != -2) {
      *puVar22 = *puVar22 | 0x40;
      iVar1 = iVar8;
    }
  }
  else {
    iVar1 = func_0x0bfc06a4(*puVar10);
    if (iVar1 == 0) goto LAB_0608ad70;
    iVar1 = func_0x0bfc06dc(*puVar10);
  }
  iVar8 = func_0x0bfc06ee();
  piVar24[6] = iVar8;
  func_0x0bfc0724(piVar24);
  func_0x0bfc0724(piVar17);
  uVar3 = 0;
  func_0x0bfc0682(0);
  func_0x0bfc0694(0);
  func_0x0bfc075a();
  uVar2 = op_insert_rrii((uint)bRam001081d9,8,8);
  bRam001081d8 = (byte)(uVar2 & 0xc70);
  bRam001081d9 = (byte)((uVar2 & 0xc70) >> 8);
  uRam00f27f91 = (undefined1)uVar3;
  uRam00f27f8d = uRam00f27f91;
  if (*(char *)((int)piVar24 + 0x5a) == '\x01') {
    uVar7 = op_insert_rrii((uint)bRam001081d9,8,0x18);
    bRam001081d8 = (byte)uVar7 | 1;
    uRam00f27f8d = 1;
    bRam001081d9 = bRam001081d8;
    if (*(char *)((int)piVar24 + 0x5a) == '\x01') {
      uVar7 = op_insert_rrii((uint)bRam001081d8,8,0x18);
      bRam001081d8 = (byte)uVar7 | 4;
      bRam001081d9 = bRam001081d8;
    }
  }
  puVar25 = (uint *)0xfd0004;
  uRam00fd0018 = uRam00fd0018 | 1;
  uRam00fd001c = uRam00fd001c & 0xfffff8ff | 0xf40;
  uRam00108148 = uRam00fd0014;
  uVar2 = op_insert_rrii((uint)bRam001081d9,8,8);
  puVar20 = (uint *)0xfd1920;
  puVar10 = puVar22 + 0x200;
  puVar11 = puVar22 + 0x240;
  uRam00fd0014 = uVar3;
  if ((uVar2 & 1) == 0) {
    uRam00104db8 = *puVar10;
    uRam00104dbc = *puVar11;
    *puVar10 = *puVar10 & 3;
    *puVar11 = *puVar11 & 3;
    uRam00fd1920 = uRam00fd1920 & 1;
    FUN_060899dc();
LAB_0608a6f6:
    puVar13 = puVar18 + 0x41;
    hw_close_flash();
  }
  else {
    *piVar26 = iVar1;
    uRam00fd1940 = 0xa80;
    uVar3 = op_uextra_rrii(uRam00fd1920,6,5);
    uVar12 = op_uextra_rrii(uRam00fd1920,0xb,4);
    iVar1 = op_uextra_rrii(uRam00fd1920,0xf,4);
    do {
      do {
        uRam00fd1920 = (uVar3 & 0x3b) << 6 | (uVar12 & 1) << 0xb | 0x36080001;
      } while (uVar3 != 3);
    } while ((uVar12 != 3) || (iVar1 != 3));
    uVar7 = op_uextra_rrii(uVar2,3,1);
    uVar7 = op_insert_rrii(uVar7,0x13,1);
    uVar6 = (CONCAT44(uVar7,uVar2 << 0xc | uVar2 >> 2) | 0x9503) & 0xffffffff0000a187;
    uRam00fd1924 = (uint)uVar6 | (uint)(uVar6 >> 0x20);
    uVar6 = CONCAT44(uVar2 << 2,uVar2 >> 1) & 0xffffffff00000078;
    uVar3 = (uint)(uVar6 >> 0x20);
    uVar6 = CONCAT44(uVar3,(uint)uVar6 | uVar3 & 0xe40) & 0xd80ffffffff;
    uRam00fd1928 = (uint)uVar6 | (uint)(uVar6 >> 0x20) | 0x286;
    puVar10 = puVar22 + 0x200;
    puVar11 = puVar22 + 0x240;
    uRam00104db8 = *puVar10;
    uRam00104dbc = *puVar11;
    *puVar10 = *puVar10 & 3;
    *puVar11 = *puVar11 & 3;
    if ((uVar2 & 1) == 0) {
      uRam00fd1920 = uRam00fd1920 & 1;
      FUN_060899dc();
      iVar1 = *piVar26;
      goto LAB_0608a6f6;
    }
    FUN_060899dc();
    iVar1 = *piVar26;
    puVar13 = puVar18 + 0x41;
  }
  uVar6 = CONCAT44(*puVar13,*puVar13) & 0x8000000020;
  *(byte *)((int)piVar24 + 0x1d) = (byte)uVar6 | (byte)(uVar6 >> 0x20);
  *puVar25 = *puVar25 | 8;
  puVar15 = (uint *)0x107a40;
  puVar14 = puVar13 + -0xc1;
  puVar21 = puVar10 + 0x340;
  puVar23 = puVar10 + 0x3c0;
  puVar9 = puVar10 + 0x680;
  if (piVar24[6] == 3) {
    uRam00107b04 = puVar10[0x342];
    uRam00107b08 = puVar10[0x343];
    uRam00107b0c = puVar10[0x348];
    uRam00107b10 = puVar10[0x344];
    uRam00107b14 = puVar10[0x345];
    uRam00107b18 = puVar10[0x346];
    uRam00107b1c = puVar10[0x347];
    uRam00107b20 = *puVar21;
    uRam00107b24 = puVar10[0x3c2];
    uRam00107b28 = puVar10[0x3c3];
    uRam00107b2c = puVar10[0x3c8];
    uRam00107b30 = puVar10[0x3c4];
    uRam00107b34 = puVar10[0x3c5];
    uRam00107b38 = puVar10[0x3c6];
    uRam00107b3c = puVar10[0x3c7];
    uRam00107b40 = *puVar23;
    uRam00107b44 = *puVar9;
    uRam0010814c = puVar25[5];
    puVar9 = (uint *)0x10814c;
    uRam00108150 = puVar25[6];
    uRam00108154 = puVar25[7];
    uRam00108158 = puVar25[8];
    uRam0010815c = puVar25[4];
    uRam00108160 = *puVar25;
    uRam00108164 = puVar25[1];
    uRam00108168 = puVar25[2];
    uRam0010816c = puVar25[3];
    uRam00108170 = *puVar10;
    uRam00108174 = puVar10[1];
    uRam00108178 = puVar10[2];
    uRam0010817c = puVar10[3];
    uRam00108180 = puVar10[4];
    uRam00108184 = puVar10[5];
    uRam00108188 = puVar10[6];
    uRam0010818c = *puVar11;
    puVar19 = (uint *)0x10818c;
    uRam00108190 = puVar11[1];
    uRam00108194 = puVar11[2];
    uRam00108198 = puVar11[3];
    uRam0010819c = puVar11[4];
    uRam001081a0 = puVar11[5];
    uRam001081a4 = puVar11[6];
    uRam001081a8 = *puVar20;
    uRam001081ac = puVar20[1];
    uRam001081b0 = puVar20[2];
    uRam001081b4 = puVar20[8];
    puVar15 = puVar13 + 0x68f;
    *puVar15 = 1;
    puVar13[0x690] = 1;
    puVar13[0x691] = 1;
    puVar13[0x692] = 1;
    puVar13[0x693] = 1;
    puVar13[0x694] = 1;
    *puVar15 = 3;
    puVar13[0x690] = 3;
    puVar13[0x691] = 3;
    puVar13[0x692] = 3;
    puVar13[0x693] = 3;
    puVar13[0x694] = 3;
    puVar13[-0xb7] = puVar13[-0xb7] | 0x80;
    FUN_0608a034();
    puVar25[5] = *puVar9;
    puVar25[6] = puVar9[1];
    puVar25[7] = puVar9[2];
    puVar25[8] = puVar9[3];
    puVar25[4] = puVar9[4];
    *puVar25 = puVar9[5];
    puVar25[1] = puVar9[6];
    puVar25[2] = puVar9[7];
    puVar25[3] = puVar9[8];
    *puVar10 = puVar9[9];
    puVar10[1] = puVar9[10];
    puVar10[2] = puVar9[0xb];
    puVar10[3] = puVar9[0xc];
    puVar10[4] = puVar9[0xd];
    puVar10[5] = puVar9[0xe];
    puVar10[6] = puVar9[0xf];
    *puVar11 = *puVar19;
    puVar11[1] = puVar19[1];
    puVar11[2] = puVar19[2];
    puVar11[3] = puVar19[3];
    puVar11[4] = puVar19[4];
    puVar11[5] = puVar19[5];
    puVar11[6] = puVar19[6];
    *puVar20 = puVar19[7];
    puVar20[1] = puVar19[8];
    puVar20[2] = puVar19[9];
    puVar20[8] = puVar19[10];
    puVar21[2] = *extraout_r1;
    puVar21[3] = extraout_r1[1];
    puVar21[8] = extraout_r1[2];
    puVar21[4] = extraout_r1[3];
    puVar21[5] = extraout_r1[4];
    puVar21[6] = extraout_r1[5];
    puVar21[7] = extraout_r1[6];
    *puVar21 = extraout_r1[7];
    puVar23[2] = extraout_r1[8];
    puVar23[3] = extraout_r1[9];
    puVar23[8] = extraout_r1[10];
    puVar23[4] = extraout_r1[0xb];
    puVar23[5] = extraout_r1[0xc];
    puVar23[6] = extraout_r1[0xd];
    puVar23[7] = extraout_r1[0xe];
    *puVar23 = extraout_r1[0xf];
    puVar9 = puVar21 + 0x340;
    *puVar9 = extraout_r1[0x10];
    puVar15[1] = 0;
    puVar15[5] = 0;
    puVar15[4] = 0;
  }
  else {
    msys_to_p11_sync_cmd(3);
    *puVar15 = *puVar14;
    *puVar14 = 1;
    puVar14[6] = 1;
    *puVar25 = *puVar25 | 4;
  }
  do {
    puVar18[2] = 0xff;
    puVar18[2] = 0xee;
    puVar18[2] = 0xab;
    puVar18[2] = 0xe;
    puVar18[2] = 0x55;
  } while ((puVar22[1] & 1) == 0);
  iVar8 = piVar24[6];
  if (iVar8 == 1) {
    do {
    } while ((puVar14[3] & 4) == 0);
    uVar2 = 4;
LAB_0608a9fe:
    puVar14[2] = uVar2;
    *puVar14 = 0x20;
  }
  else {
    if (iVar8 == 3) {
      uVar2 = 2;
      goto LAB_0608a9fe;
    }
    if (iVar8 == 2) {
      do {
      } while ((puVar14[3] & 1) == 0);
      uVar2 = 1;
      goto LAB_0608a9fe;
    }
  }
  if ((*puVar20 & 1) == 0) {
    puVar23[4] = puVar23[4] | 0x10;
    puVar23[2] = puVar23[2] | 0x10;
    puVar21[4] = puVar21[4] | 8;
    puVar21[2] = puVar21[2] | 8;
    puVar21[7] = puVar21[7] & 0x10;
    puVar21[6] = puVar21[6] & 0x10;
    *puVar21 = *puVar21 | 0x10;
    puVar21[2] = puVar21[2] & 0x10;
    delay_tmr2_lrc(10);
    puVar21[6] = puVar21[6] | 0x10;
    delay_tmr2_lrc(10);
    puVar21[7] = puVar21[7] | 0x10;
    if ((CONCAT44(puVar9[5],0x104db5) & 0x1000000000000) == 0) {
      *puVar21 = *puVar21 | 8;
      puVar21[2] = puVar21[2] & 8;
      puVar21[4] = puVar21[4] & 8;
      puVar21[5] = puVar21[5] & 8;
      puVar21[4] = puVar21[4] & 1;
      puVar21[5] = puVar21[5] & 1;
      puVar21[2] = puVar21[2] & 1;
      puVar21[3] = puVar21[3] | 2;
      puVar21[4] = puVar21[4] | 2;
      puVar21[5] = puVar21[5] & 2;
      puVar21[2] = puVar21[2] | 2;
      puVar21[3] = puVar21[3] | 4;
      puVar21[4] = puVar21[4] | 4;
      puVar21[5] = puVar21[5] & 4;
      puVar21[2] = puVar21[2] | 4;
      if (cRam00104db5 == '\x04') {
        puVar21[3] = puVar21[3] | 0x20;
        puVar21[4] = puVar21[4] | 0x20;
        puVar21[5] = puVar21[5] & 0x20;
        puVar21[2] = puVar21[2] | 0x20;
        goto LAB_0608aafc;
      }
    }
    else {
      *puVar23 = *puVar23 | 0x10;
      puVar23[2] = puVar23[2] & 0x10;
      puVar23[4] = puVar23[4] & 0x10;
      puVar23[5] = puVar23[5] & 0x10;
      puVar21[3] = puVar21[3] | 1;
      puVar21[4] = puVar21[4] & 1;
      puVar21[5] = puVar21[5] & 1;
      puVar21[2] = puVar21[2] & 1;
      puVar21[3] = puVar21[3] | 2;
      puVar21[4] = puVar21[4] | 2;
      puVar21[5] = puVar21[5] & 2;
      puVar21[2] = puVar21[2] | 2;
      puVar23[3] = puVar23[3] | 8;
      puVar23[4] = puVar23[4] | 8;
      puVar23[5] = puVar23[5] & 8;
      puVar23[2] = puVar23[2] | 8;
      if (cRam00104db5 == '\x04') {
        puVar23[3] = puVar23[3] | 4;
        puVar23[4] = puVar23[4] | 4;
        puVar23[5] = puVar23[5] & 4;
        puVar23[2] = puVar23[2] | 4;
LAB_0608aafc:
        puVar21[3] = puVar21[3] | 0x40;
        puVar21[4] = puVar21[4] | 0x40;
        puVar21[5] = puVar21[5] & 0x40;
        puVar21[2] = puVar21[2] | 0x40;
      }
    }
  }
  FUN_0608a054();
  puVar14[0x715] = puVar14[0x715] & 0x3fc7;
  FUN_0608a06e();
  iVar8 = FUN_06089d94();
  if (iVar8 == 0) {
    iVar8 = 0;
  }
  else {
    iVar8 = FUN_0608a0c2();
  }
  if ((*puVar20 & 1) == 0) {
    uVar2 = *puVar20;
    uVar3 = puVar20[1];
    uVar12 = puVar20[2];
    *puVar20 = *puVar20 & 0x660;
    puVar20[1] = puVar20[1] & 0xfff7bdff;
    puVar20[2] = puVar20[2] & 0xd90;
    *puVar20 = *puVar20 | 1;
    iVar5 = piVar24[0xce];
    FUN_0608b07e();
    FUN_0608afac(0x10eafa);
    FUN_0608a184();
    iVar4 = FUN_0608b088();
    if (iVar4 == 0) {
      uVar7 = op_ext_l_u(iVar5);
      delay_tmr2_lrc(uVar7);
    }
    else {
      xosc_adet_en(1);
      iVar5 = FUN_0608a0c2();
      do {
        iVar4 = FUN_0608a0c2();
        uVar16 = iVar4 - iVar5;
        FUN_0608a06e();
        iVar4 = FUN_0608aff4();
        if (3000 < uVar16) break;
      } while (iVar4 == 0);
      xosc_adet_en(0);
    }
    *puVar20 = *puVar20 | uVar2 & 0x660;
    puVar20[1] = puVar20[1] | uVar3 & 0x84200;
    puVar20[2] = puVar20[2] | uVar12 & 0xd90;
    iVar5 = 1 - iVar8;
    iRam00104dc4 = FUN_0608a0c2();
    iRam00104dc4 = iVar5 + iRam00104dc4;
    iVar5 = FUN_06089d94();
    if (iVar5 != 0) {
      uVar2 = extraout_r1_00;
      if (extraout_r1_00 <= uRam00104dc8) {
        iVar5 = utof(uRam00104dc8);
        iVar4 = utof(extraout_r1_00);
        uVar2 = op_ftou_trunc_rr(iVar4 * 0x3c23d70a + iVar5 * 0x3f7d70a4);
      }
      uRam00104dc8 = uVar2;
      piVar24[0xd0] = 1000;
    }
  }
  else {
    FUN_0608a184();
  }
  uVar3 = ~*(uint *)((int)puVar14 + 0xa2a) & 1;
  uVar2 = ~*puVar11 & 1;
  if (uVar2 != 0 || uVar3 != 0) {
    if (uVar2 != 0) {
      *puVar20 = *puVar20 | 0x680;
    }
    if (uVar3 != 0) {
      puVar20[2] = puVar20[2] | 0xf00;
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
  puVar25[4] = uRam00108148;
  puVar25[6] = puVar25[6] & 0xfffff8ff | 0xec0;
  if ((bRam001081d8 & 1) == 0) {
    iVar8 = 1 - iVar8;
    piVar17 = (int *)0x104dc0;
    while( true ) {
      iVar5 = FUN_0608a0c2();
      *piVar17 = iVar8 + iVar5;
      iVar5 = FUN_06089d94();
      if ((iVar5 == 0) || (999 < extraout_r1_01)) break;
      delay_tmr2_lrc(10);
    }
  }
  FUN_0608a06e();
  uVar7 = 0x6051260;
  do {
    func_0x05f9acba(uVar7);
    iVar8 = func_0x05f9ac72(uVar7);
  } while (iVar8 != 0);
  func_0x0bfc09da(iVar1);
  if (*(char *)((int)piVar24 + 0x1d) != '\0') {
    func_0x0bf822c6();
  }
  func_0x0bfc0b6e(iVar1);
  puVar18 = (uint *)0x107a40;
  func_0x0bfc0b92(0);
  do {
  } while ((puVar14[3] & 0x20) == 0);
  puVar14[2] = 0x20;
  *puVar14 = *puVar18;
  func_0x0bfc0cc4();
LAB_0608ad70:
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
}


// ===== FUN_0608a184 @ 0608a184

undefined1 FUN_0608a184(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 extraout_r1;
  ulonglong uVar7;
  uint *extraout_r1_00;
  uint extraout_r1_01;
  uint extraout_r1_02;
  int iVar8;
  undefined4 uVar9;
  uint *puVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  uint *puVar13;
  uint *puVar14;
  undefined4 uVar15;
  uint uVar16;
  uint *puVar17;
  uint *puVar18;
  ushort *puVar19;
  int *piVar20;
  uint *puVar21;
  uint uVar22;
  int *piVar23;
  uint *puVar24;
  uint *puVar25;
  uint *puVar26;
  uint *puVar27;
  uint *puVar28;
  uint *puVar29;
  int *piVar30;
  uint *puVar31;
  BADSPACEBASE *in_sp;
  undefined1 *puVar32;
  
  op_push_rets_rl();
  if (iRam00108cc0 == 3) {
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
    for (iVar8 = 0; iVar8 != 0x100; iVar8 = iVar8 + 4) {
      iRam00107b7c = iVar8 + 0x107c9c;
      *(undefined4 *)(iVar8 + 0xfd5c00) = *(undefined4 *)(iVar8 + 0x107c98);
    }
    for (iVar8 = 0; iVar8 != 0xc4; iVar8 = iVar8 + 4) {
      iRam00107b7c = iVar8 + 0x107d9c;
      *(undefined4 *)(iVar8 + 0xfd5800) = *(undefined4 *)(iVar8 + 0x107d98);
    }
    puVar11 = (undefined4 *)0xfd6014;
    uRam00fd6014 = uRam001081b8;
    uRam00fd6018 = uRam001081bc;
    uRam00fd601c = uRam001081c0;
    uRam00fd6020 = uRam001081c4;
    uRam00fd6024 = uRam001081c8;
    uRam00fd6028 = uRam001081cc;
    uRam00fd602c = uRam001081d0;
    uRam00fd6030 = uRam001081d4;
    func_0x0608a0d2();
    core_sfr_exit_deepsleep();
    *puVar11 = uRam00107ef4;
    iVar8 = 0xfe0200;
    uRam00fe020c = 0;
    uRam00fe0210 = uRam00107ef0;
    uVar9 = 0x1f;
    uRam00fe0214 = 0x1f;
    uVar12 = 0x7ffffdf;
    uVar15 = 0x7ffffff;
    uRam00fe0224 = 0x7ffffdf;
    uRam00fe0220 = 0x7ffffff;
    puVar19 = (ushort *)0x106204;
    puVar24 = (uint *)0xfd4104;
    uRam00fd4104 = (uint)uRam00106204;
    uRam00fe021c = (uint)uRam00106204;
    uRam00fe0218 = uRam00107eec;
    uVar1 = FUN_06088ede();
    *(undefined4 *)(iVar8 + 4) = uVar1;
    puVar11 = (undefined4 *)(iVar8 + -0x100);
    *puVar11 = uRam00107ee8;
    *(undefined4 *)(iVar8 + -0xf4) = extraout_r1;
    *(undefined4 *)(iVar8 + -0xf0) = uRam00107f00;
    *(undefined4 *)(iVar8 + -0xec) = uVar9;
    *(undefined4 *)(iVar8 + -0xdc) = uVar12;
    *(undefined4 *)(iVar8 + -0xe0) = uVar15;
    *puVar24 = (uint)*puVar19;
    *(uint *)(iVar8 + -0xe4) = (uint)*puVar19;
    *(undefined4 *)(iVar8 + -0xe8) = uRam00107efc;
    uVar1 = FUN_06088ede();
    puVar11[1] = uVar1;
    *puVar11 = uRam00107ef8;
    while ((uRam00ff03fc & 1) == 0) {
      uRam00ff03fc = 0xe7;
    }
    for (iVar8 = 0; iVar8 != 0x20; iVar8 = iVar8 + 4) {
      iVar4 = iVar8 * 4;
      *(undefined4 *)(iVar8 + 0xff0380) = *(undefined4 *)(iVar4 + 0x107e68);
      *(undefined4 *)(iVar8 + 0xff03c0) = *(undefined4 *)(iVar4 + 0x107e6c);
      *(undefined4 *)(iVar8 + 0xff0340) = *(undefined4 *)(iVar4 + 0x107e70);
      *(undefined4 *)(iVar8 + 0xff0300) = *(undefined4 *)(iVar4 + 0x107e74);
    }
    while ((uRam00ff03fc & 1) != 0) {
      uRam00ff03fc = 0xe7;
    }
    func_0x06089352();
    func_0x06089366();
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar32 = (undefined1 *)((int)in_sp + -4);
  piVar30 = (int *)0x108ca8;
  if (cRam00108cc7 == '\0') {
LAB_0608ad76:
    op_pop_pc_rl();
    return uRam00104db0;
  }
  piVar23 = (int *)((int)in_sp + -4);
  if (cRam00108d02 == '\0') {
    iVar8 = func_0x0bfc05a0();
    piVar23 = (int *)puVar32;
    if (iVar8 == 0) goto LAB_0608ad76;
  }
  FUN_06088a6a();
  func_0x0bfc05c0();
  uVar2 = func_0x0bfc0624(piVar30);
  piVar20 = piVar30 + 3;
  uVar3 = func_0x0bfc0624(piVar20);
  if (uVar3 < uVar2) {
    uVar2 = uVar3;
  }
  if (uVar2 == 0) goto LAB_0608ad70;
  puVar24 = (uint *)0xf2a800;
  uVar7 = (ulonglong)uRam00f2a800 << 0x20;
  if ((uVar7 & 0x2000000000) != 0) {
    func_0x0bf7fc06();
    uVar7 = (ulonglong)*(uint *)((*puVar24 & 0x1f) * 4 + 0x6060f9c);
  }
  uVar3 = (uint)((int)uVar7 * 0xf7a) >> 1;
  if ((uVar3 != 0) && (uVar3 < uVar2)) {
    uVar2 = uVar3;
  }
  iVar8 = FUN_06089d94();
  if (iVar8 != 0) {
    func_0x0bf822c6();
  }
  iVar8 = func_0x0bfc0658(uVar2);
  if (iVar8 == 1) goto LAB_0608ad70;
  func_0x0bfc0682(1);
  func_0x0bfc0694(1);
  puVar13 = puVar24 + 0x41;
  puVar28 = (uint *)0xfd3e00;
  if ((int *)*piVar30 == piVar30) {
    iVar8 = func_0x0bfc06a4(uVar2);
    if (iVar8 == 0) goto LAB_0608ad70;
    iVar4 = func_0x0bfc06dc();
    iVar8 = -2;
    if (iVar4 != -2) {
      *puVar28 = *puVar28 | 0x40;
      iVar8 = iVar4;
    }
  }
  else {
    iVar8 = func_0x0bfc06a4(*puVar13);
    if (iVar8 == 0) goto LAB_0608ad70;
    iVar8 = func_0x0bfc06dc(*puVar13);
  }
  iVar4 = func_0x0bfc06ee();
  piVar30[6] = iVar4;
  func_0x0bfc0724(piVar30);
  func_0x0bfc0724(piVar20);
  uVar3 = 0;
  func_0x0bfc0682(0);
  func_0x0bfc0694(0);
  func_0x0bfc075a();
  uVar2 = op_insert_rrii((uint)bRam001081d9,8,8);
  bRam001081d8 = (byte)(uVar2 & 0xc70);
  bRam001081d9 = (byte)((uVar2 & 0xc70) >> 8);
  uRam00f27f91 = (undefined1)uVar3;
  uRam00f27f8d = uRam00f27f91;
  if (*(char *)((int)piVar30 + 0x5a) == '\x01') {
    uVar1 = op_insert_rrii((uint)bRam001081d9,8,0x18);
    bRam001081d8 = (byte)uVar1 | 1;
    uRam00f27f8d = 1;
    bRam001081d9 = bRam001081d8;
    if (*(char *)((int)piVar30 + 0x5a) == '\x01') {
      uVar1 = op_insert_rrii((uint)bRam001081d8,8,0x18);
      bRam001081d8 = (byte)uVar1 | 4;
      bRam001081d9 = bRam001081d8;
    }
  }
  puVar31 = (uint *)0xfd0004;
  uRam00fd0018 = uRam00fd0018 | 1;
  uRam00fd001c = uRam00fd001c & 0xfffff8ff | 0xf40;
  uRam00108148 = uRam00fd0014;
  uVar2 = op_insert_rrii((uint)bRam001081d9,8,8);
  puVar26 = (uint *)0xfd1920;
  puVar13 = puVar28 + 0x200;
  puVar14 = puVar28 + 0x240;
  uRam00fd0014 = uVar3;
  if ((uVar2 & 1) == 0) {
    uRam00104db8 = *puVar13;
    uRam00104dbc = *puVar14;
    *puVar13 = *puVar13 & 3;
    *puVar14 = *puVar14 & 3;
    uRam00fd1920 = uRam00fd1920 & 1;
    FUN_060899dc();
LAB_0608a6f6:
    puVar17 = puVar24 + 0x41;
    hw_close_flash();
  }
  else {
    *piVar23 = iVar8;
    uRam00fd1940 = 0xa80;
    uVar3 = op_uextra_rrii(uRam00fd1920,6,5);
    uVar16 = op_uextra_rrii(uRam00fd1920,0xb,4);
    iVar8 = op_uextra_rrii(uRam00fd1920,0xf,4);
    do {
      do {
        uRam00fd1920 = (uVar3 & 0x3b) << 6 | (uVar16 & 1) << 0xb | 0x36080001;
      } while (uVar3 != 3);
    } while ((uVar16 != 3) || (iVar8 != 3));
    uVar1 = op_uextra_rrii(uVar2,3,1);
    uVar1 = op_insert_rrii(uVar1,0x13,1);
    uVar7 = (CONCAT44(uVar1,uVar2 << 0xc | uVar2 >> 2) | 0x9503) & 0xffffffff0000a187;
    uRam00fd1924 = (uint)uVar7 | (uint)(uVar7 >> 0x20);
    uVar7 = CONCAT44(uVar2 << 2,uVar2 >> 1) & 0xffffffff00000078;
    uVar3 = (uint)(uVar7 >> 0x20);
    uVar7 = CONCAT44(uVar3,(uint)uVar7 | uVar3 & 0xe40) & 0xd80ffffffff;
    uRam00fd1928 = (uint)uVar7 | (uint)(uVar7 >> 0x20) | 0x286;
    puVar13 = puVar28 + 0x200;
    puVar14 = puVar28 + 0x240;
    uRam00104db8 = *puVar13;
    uRam00104dbc = *puVar14;
    *puVar13 = *puVar13 & 3;
    *puVar14 = *puVar14 & 3;
    if ((uVar2 & 1) == 0) {
      uRam00fd1920 = uRam00fd1920 & 1;
      FUN_060899dc();
      iVar8 = *piVar23;
      goto LAB_0608a6f6;
    }
    FUN_060899dc();
    iVar8 = *piVar23;
    puVar17 = puVar24 + 0x41;
  }
  uVar7 = CONCAT44(*puVar17,*puVar17) & 0x8000000020;
  *(byte *)((int)piVar30 + 0x1d) = (byte)uVar7 | (byte)(uVar7 >> 0x20);
  *puVar31 = *puVar31 | 8;
  puVar21 = (uint *)0x107a40;
  puVar18 = puVar17 + -0xc1;
  puVar27 = puVar13 + 0x340;
  puVar29 = puVar13 + 0x3c0;
  puVar10 = puVar13 + 0x680;
  if (piVar30[6] == 3) {
    uRam00107b04 = puVar13[0x342];
    uRam00107b08 = puVar13[0x343];
    uRam00107b0c = puVar13[0x348];
    uRam00107b10 = puVar13[0x344];
    uRam00107b14 = puVar13[0x345];
    uRam00107b18 = puVar13[0x346];
    uRam00107b1c = puVar13[0x347];
    uRam00107b20 = *puVar27;
    uRam00107b24 = puVar13[0x3c2];
    uRam00107b28 = puVar13[0x3c3];
    uRam00107b2c = puVar13[0x3c8];
    uRam00107b30 = puVar13[0x3c4];
    uRam00107b34 = puVar13[0x3c5];
    uRam00107b38 = puVar13[0x3c6];
    uRam00107b3c = puVar13[0x3c7];
    uRam00107b40 = *puVar29;
    uRam00107b44 = *puVar10;
    uRam0010814c = puVar31[5];
    puVar10 = (uint *)0x10814c;
    uRam00108150 = puVar31[6];
    uRam00108154 = puVar31[7];
    uRam00108158 = puVar31[8];
    uRam0010815c = puVar31[4];
    uRam00108160 = *puVar31;
    uRam00108164 = puVar31[1];
    uRam00108168 = puVar31[2];
    uRam0010816c = puVar31[3];
    uRam00108170 = *puVar13;
    uRam00108174 = puVar13[1];
    uRam00108178 = puVar13[2];
    uRam0010817c = puVar13[3];
    uRam00108180 = puVar13[4];
    uRam00108184 = puVar13[5];
    uRam00108188 = puVar13[6];
    uRam0010818c = *puVar14;
    puVar25 = (uint *)0x10818c;
    uRam00108190 = puVar14[1];
    uRam00108194 = puVar14[2];
    uRam00108198 = puVar14[3];
    uRam0010819c = puVar14[4];
    uRam001081a0 = puVar14[5];
    uRam001081a4 = puVar14[6];
    uRam001081a8 = *puVar26;
    uRam001081ac = puVar26[1];
    uRam001081b0 = puVar26[2];
    uRam001081b4 = puVar26[8];
    puVar21 = puVar17 + 0x68f;
    *puVar21 = 1;
    puVar17[0x690] = 1;
    puVar17[0x691] = 1;
    puVar17[0x692] = 1;
    puVar17[0x693] = 1;
    puVar17[0x694] = 1;
    *puVar21 = 3;
    puVar17[0x690] = 3;
    puVar17[0x691] = 3;
    puVar17[0x692] = 3;
    puVar17[0x693] = 3;
    puVar17[0x694] = 3;
    puVar17[-0xb7] = puVar17[-0xb7] | 0x80;
    FUN_0608a034();
    puVar31[5] = *puVar10;
    puVar31[6] = puVar10[1];
    puVar31[7] = puVar10[2];
    puVar31[8] = puVar10[3];
    puVar31[4] = puVar10[4];
    *puVar31 = puVar10[5];
    puVar31[1] = puVar10[6];
    puVar31[2] = puVar10[7];
    puVar31[3] = puVar10[8];
    *puVar13 = puVar10[9];
    puVar13[1] = puVar10[10];
    puVar13[2] = puVar10[0xb];
    puVar13[3] = puVar10[0xc];
    puVar13[4] = puVar10[0xd];
    puVar13[5] = puVar10[0xe];
    puVar13[6] = puVar10[0xf];
    *puVar14 = *puVar25;
    puVar14[1] = puVar25[1];
    puVar14[2] = puVar25[2];
    puVar14[3] = puVar25[3];
    puVar14[4] = puVar25[4];
    puVar14[5] = puVar25[5];
    puVar14[6] = puVar25[6];
    *puVar26 = puVar25[7];
    puVar26[1] = puVar25[8];
    puVar26[2] = puVar25[9];
    puVar26[8] = puVar25[10];
    puVar27[2] = *extraout_r1_00;
    puVar27[3] = extraout_r1_00[1];
    puVar27[8] = extraout_r1_00[2];
    puVar27[4] = extraout_r1_00[3];
    puVar27[5] = extraout_r1_00[4];
    puVar27[6] = extraout_r1_00[5];
    puVar27[7] = extraout_r1_00[6];
    *puVar27 = extraout_r1_00[7];
    puVar29[2] = extraout_r1_00[8];
    puVar29[3] = extraout_r1_00[9];
    puVar29[8] = extraout_r1_00[10];
    puVar29[4] = extraout_r1_00[0xb];
    puVar29[5] = extraout_r1_00[0xc];
    puVar29[6] = extraout_r1_00[0xd];
    puVar29[7] = extraout_r1_00[0xe];
    *puVar29 = extraout_r1_00[0xf];
    puVar10 = puVar27 + 0x340;
    *puVar10 = extraout_r1_00[0x10];
    puVar21[1] = 0;
    puVar21[5] = 0;
    puVar21[4] = 0;
  }
  else {
    msys_to_p11_sync_cmd(3);
    *puVar21 = *puVar18;
    *puVar18 = 1;
    puVar18[6] = 1;
    *puVar31 = *puVar31 | 4;
  }
  do {
    puVar24[2] = 0xff;
    puVar24[2] = 0xee;
    puVar24[2] = 0xab;
    puVar24[2] = 0xe;
    puVar24[2] = 0x55;
  } while ((puVar28[1] & 1) == 0);
  iVar4 = piVar30[6];
  if (iVar4 == 1) {
    do {
    } while ((puVar18[3] & 4) == 0);
    uVar2 = 4;
LAB_0608a9fe:
    puVar18[2] = uVar2;
    *puVar18 = 0x20;
  }
  else {
    if (iVar4 == 3) {
      uVar2 = 2;
      goto LAB_0608a9fe;
    }
    if (iVar4 == 2) {
      do {
      } while ((puVar18[3] & 1) == 0);
      uVar2 = 1;
      goto LAB_0608a9fe;
    }
  }
  if ((*puVar26 & 1) == 0) {
    puVar29[4] = puVar29[4] | 0x10;
    puVar29[2] = puVar29[2] | 0x10;
    puVar27[4] = puVar27[4] | 8;
    puVar27[2] = puVar27[2] | 8;
    puVar27[7] = puVar27[7] & 0x10;
    puVar27[6] = puVar27[6] & 0x10;
    *puVar27 = *puVar27 | 0x10;
    puVar27[2] = puVar27[2] & 0x10;
    delay_tmr2_lrc(10);
    puVar27[6] = puVar27[6] | 0x10;
    delay_tmr2_lrc(10);
    puVar27[7] = puVar27[7] | 0x10;
    if ((CONCAT44(puVar10[5],0x104db5) & 0x1000000000000) == 0) {
      *puVar27 = *puVar27 | 8;
      puVar27[2] = puVar27[2] & 8;
      puVar27[4] = puVar27[4] & 8;
      puVar27[5] = puVar27[5] & 8;
      puVar27[4] = puVar27[4] & 1;
      puVar27[5] = puVar27[5] & 1;
      puVar27[2] = puVar27[2] & 1;
      puVar27[3] = puVar27[3] | 2;
      puVar27[4] = puVar27[4] | 2;
      puVar27[5] = puVar27[5] & 2;
      puVar27[2] = puVar27[2] | 2;
      puVar27[3] = puVar27[3] | 4;
      puVar27[4] = puVar27[4] | 4;
      puVar27[5] = puVar27[5] & 4;
      puVar27[2] = puVar27[2] | 4;
      if (cRam00104db5 == '\x04') {
        puVar27[3] = puVar27[3] | 0x20;
        puVar27[4] = puVar27[4] | 0x20;
        puVar27[5] = puVar27[5] & 0x20;
        puVar27[2] = puVar27[2] | 0x20;
        goto LAB_0608aafc;
      }
    }
    else {
      *puVar29 = *puVar29 | 0x10;
      puVar29[2] = puVar29[2] & 0x10;
      puVar29[4] = puVar29[4] & 0x10;
      puVar29[5] = puVar29[5] & 0x10;
      puVar27[3] = puVar27[3] | 1;
      puVar27[4] = puVar27[4] & 1;
      puVar27[5] = puVar27[5] & 1;
      puVar27[2] = puVar27[2] & 1;
      puVar27[3] = puVar27[3] | 2;
      puVar27[4] = puVar27[4] | 2;
      puVar27[5] = puVar27[5] & 2;
      puVar27[2] = puVar27[2] | 2;
      puVar29[3] = puVar29[3] | 8;
      puVar29[4] = puVar29[4] | 8;
      puVar29[5] = puVar29[5] & 8;
      puVar29[2] = puVar29[2] | 8;
      if (cRam00104db5 == '\x04') {
        puVar29[3] = puVar29[3] | 4;
        puVar29[4] = puVar29[4] | 4;
        puVar29[5] = puVar29[5] & 4;
        puVar29[2] = puVar29[2] | 4;
LAB_0608aafc:
        puVar27[3] = puVar27[3] | 0x40;
        puVar27[4] = puVar27[4] | 0x40;
        puVar27[5] = puVar27[5] & 0x40;
        puVar27[2] = puVar27[2] | 0x40;
      }
    }
  }
  FUN_0608a054();
  puVar18[0x715] = puVar18[0x715] & 0x3fc7;
  FUN_0608a06e();
  iVar4 = FUN_06089d94();
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_0608a0c2();
  }
  if ((*puVar26 & 1) == 0) {
    uVar2 = *puVar26;
    uVar3 = puVar26[1];
    uVar16 = puVar26[2];
    *puVar26 = *puVar26 & 0x660;
    puVar26[1] = puVar26[1] & 0xfff7bdff;
    puVar26[2] = puVar26[2] & 0xd90;
    *puVar26 = *puVar26 | 1;
    iVar6 = piVar30[0xce];
    FUN_0608b07e();
    FUN_0608afac(0x10eafa);
    FUN_0608a184();
    iVar5 = FUN_0608b088();
    if (iVar5 == 0) {
      uVar1 = op_ext_l_u(iVar6);
      delay_tmr2_lrc(uVar1);
    }
    else {
      xosc_adet_en(1);
      iVar6 = FUN_0608a0c2();
      do {
        iVar5 = FUN_0608a0c2();
        uVar22 = iVar5 - iVar6;
        FUN_0608a06e();
        iVar5 = FUN_0608aff4();
        if (3000 < uVar22) break;
      } while (iVar5 == 0);
      xosc_adet_en(0);
    }
    *puVar26 = *puVar26 | uVar2 & 0x660;
    puVar26[1] = puVar26[1] | uVar3 & 0x84200;
    puVar26[2] = puVar26[2] | uVar16 & 0xd90;
    iVar6 = 1 - iVar4;
    iRam00104dc4 = FUN_0608a0c2();
    iRam00104dc4 = iVar6 + iRam00104dc4;
    iVar6 = FUN_06089d94();
    if (iVar6 != 0) {
      uVar2 = extraout_r1_01;
      if (extraout_r1_01 <= uRam00104dc8) {
        iVar6 = utof(uRam00104dc8);
        iVar5 = utof(extraout_r1_01);
        uVar2 = op_ftou_trunc_rr(iVar5 * 0x3c23d70a + iVar6 * 0x3f7d70a4);
      }
      uRam00104dc8 = uVar2;
      piVar30[0xd0] = 1000;
    }
  }
  else {
    FUN_0608a184();
  }
  uVar3 = ~*(uint *)((int)puVar18 + 0xa2a) & 1;
  uVar2 = ~*puVar14 & 1;
  if (uVar2 != 0 || uVar3 != 0) {
    if (uVar2 != 0) {
      *puVar26 = *puVar26 | 0x680;
    }
    if (uVar3 != 0) {
      puVar26[2] = puVar26[2] | 0xf00;
      *(uint *)((int)puVar18 + 0xa2a) = *(uint *)((int)puVar18 + 0xa2a) | 1;
    }
    if (uVar2 != 0) {
      *puVar14 = *puVar14 | 1;
    }
    delay_tmr2_lrc(10);
    if (uVar3 != 0) {
      *(uint *)((int)puVar18 + 0xa2a) = *(uint *)((int)puVar18 + 0xa2a) | 2;
    }
    if (uVar2 != 0) {
      *puVar14 = *puVar14 | 2;
    }
    delay_tmr2_lrc(200);
  }
  puVar31[4] = uRam00108148;
  puVar31[6] = puVar31[6] & 0xfffff8ff | 0xec0;
  if ((bRam001081d8 & 1) == 0) {
    iVar4 = 1 - iVar4;
    piVar23 = (int *)0x104dc0;
    while( true ) {
      iVar6 = FUN_0608a0c2();
      *piVar23 = iVar4 + iVar6;
      iVar6 = FUN_06089d94();
      if ((iVar6 == 0) || (999 < extraout_r1_02)) break;
      delay_tmr2_lrc(10);
    }
  }
  FUN_0608a06e();
  uVar1 = 0x6051260;
  do {
    func_0x05f9acba(uVar1);
    iVar4 = func_0x05f9ac72(uVar1);
  } while (iVar4 != 0);
  func_0x0bfc09da(iVar8);
  if (*(char *)((int)piVar30 + 0x1d) != '\0') {
    func_0x0bf822c6();
  }
  func_0x0bfc0b6e(iVar8);
  puVar24 = (uint *)0x107a40;
  func_0x0bfc0b92(0);
  do {
  } while ((puVar18[3] & 0x20) == 0);
  puVar18[2] = 0x20;
  *puVar18 = *puVar24;
  func_0x0bfc0cc4();
LAB_0608ad70:
                    /* WARNING: Subroutine does not return */
  FUN_06088ab8();
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


// ===== FUN_0608ae32 @ 0608ae32

void FUN_0608ae32(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  op_push_rets_rl();
  uVar3 = CONCAT44(param_2,param_1);
  func_0x05f9aca6();
  func_0x05f9aca2();
  do {
  } while ((int)uRam00fe0200 < 0);
  uRam00fe0204 = (undefined4)uVar3;
  uRam00fe0200 = op_insert_rrii((uint)((ulonglong)uVar3 >> 0x20) & 0xf0,0x14,4);
  uRam00fe0200 = uRam00fe0200 | 1;
  uRam001079b8 = (undefined1)uVar3;
  op_pop_pc_rl();
  op_push_rets_rl();
  uVar2 = uRam001079cc;
  __hw_clk_limit(uRam001079cc,*(undefined4 *)((uint)bRam001079d4 * 0xc + 0x104a78),0xff);
  uVar1 = op_ext_b0_u(((uVar2 / 1000000) * 0x1e) / 1000);
  FUN_0608ae32(uVar1);
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


// ===== FUN_0608aff4 @ 0608aff4

undefined4 FUN_0608aff4(void)

{
  undefined4 uVar1;
  
  uVar1 = op_uextra_rrii(uRam00fd1978,4,1);
  return uVar1;
}


// ===== FUN_0608b07e @ 0608b07e

undefined1 FUN_0608b07e(void)

{
  return uRam001079f4;
}


// ===== FUN_0608b088 @ 0608b088

undefined1 FUN_0608b088(void)

{
  return uRam001079f0;
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


// ===== FUN_0608c1d0 @ 0608c1d0

void FUN_0608c1d0(void)

{
  int iVar1;
  int iVar2;
  undefined8 in_r0_r1;
  int extraout_r1;
  undefined1 *puVar3;
  int extraout_r1_00;
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  
  op_push_rets_rl();
  iVar2 = (int)((ulonglong)in_r0_r1 >> 0x20);
  func_0x0bfb34d8();
  *(uint *)(iVar2 + 8) = *(uint *)(iVar2 + 8) | 0xd80;
  func_0x0bfb3ed6(iVar2);
  iVar1 = func_0x0bfb34e2();
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar2 = *(int *)(iVar1 + 0x14);
  iVar4 = extraout_r1;
  if (*(char *)(iVar2 + 0x10) != '\0') {
    iVar4 = *(int *)(iVar2 + 0x40);
    if (iVar4 != 0) {
      iVar6 = iVar4 + 0x180;
      uVar5 = 0;
      FUN_0608718a((uint)*(ushort *)(iVar2 + 0x32) * 0x10 + iVar4 + 0x1b8);
      FUN_06088a6a();
      iVar1 = iVar4 + 0xa4;
      iVar2 = func_0x0bf8d53c(iVar4);
      if (iVar2 == 0) {
        func_0x0bf8e0ee(iVar4);
        func_0x0bf8e732(iVar4);
        puVar3 = (undefined1 *)(iVar6 + 0x99);
        for (iVar2 = 0; iVar2 != 0x14; iVar2 = iVar2 + 5) {
          if (*(char *)(iVar1 + 0xb5 + iVar2) != '\0') {
            puVar3[-0x65] = 1;
            *puVar3 = uVar5;
          }
          puVar3 = puVar3 + 1;
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_06088ab8();
    }
    iVar4 = *(int *)((uint)*(byte *)(iVar2 + 0x13) * 4 + 0x106380);
    if (iVar4 != 0) {
      if (*(int *)(iVar4 + 0x180) != 0) {
        FUN_06088a6a();
                    /* WARNING: Subroutine does not return */
        FUN_06088ab8();
      }
    }
    iVar4 = 0x106380;
    *(char *)(iVar2 + 0x10) = '\0';
  }
  do {
    op_pop_pc_rl();
    *(int *)(iVar4 + 0xc) = iVar1;
    FUN_0608c1d0();
    iVar4 = extraout_r1_00;
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


// ===== FUN_0608cd6e @ 0608cd6e

void FUN_0608cd6e(undefined4 *param_1,int param_2,uint *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  BADSPACEBASE *in_sp;
  int *piVar9;
  undefined1 auStack_4 [4];
  
  op_push_rets_rl();
  piVar9 = (int *)auStack_4;
  iVar8 = param_1[6];
  iVar7 = *(int *)(iVar8 + 0x18);
  puVar1 = auStack_4;
  if (*(int *)(param_2 + 0x14) == 0) goto LAB_0608ce8a;
  iVar2 = func_0x0bfb3e40(param_1);
  if ((iVar2 != 0) && (*(short *)(iVar8 + 2) != 0x1a85)) {
    if ((*(byte *)(param_2 + 0x10) & 0xc0) == 0) {
      if (*(short *)(iVar8 + 2) == -0x19d6) goto LAB_0608cdbc;
      if (*(short *)(*(int *)(param_2 + 0x18) + 0x1e) == 0) goto LAB_0608ce86;
      goto LAB_0608cdbc;
    }
    if (param_1[3] != 1) goto LAB_0608ce86;
  }
  do {
    if ((*(byte *)(param_1 + 3) & 1) != 0) {
      iVar2 = iVar8 + 0x1c;
      FUN_0608718a(iVar2,0);
      (*(code *)param_1[9])(param_1,param_2,(code *)param_1[9]);
      FUN_06087398(iVar2);
      if (iVar7 == 0) {
        *(undefined1 *)(param_2 + 1) = 1;
      }
    }
LAB_0608cdbc:
    do {
      if (*(int *)(param_2 + 0x14) == 0) {
        iVar2 = param_1[7];
        func_0x0bfb34d8();
        puVar6 = (undefined4 *)*param_1;
        if (*(int *)(iVar2 + 0x18) == 0x100) {
          iVar3 = 0;
          for (; puVar6 != param_1; puVar6 = (undefined4 *)*puVar6) {
            iVar3 = iVar3 + ((int)((uint)*(ushort *)((int)puVar6 + 0x12) -
                                  (uint)*(ushort *)(puVar6 + 4)) >>
                            (uint)(*(char *)(puVar6 + 3) != '\0'));
          }
          if (iVar3 == 0) {
            uVar4 = 0;
          }
          else {
            if (*(byte *)(iVar2 + 8) >> 4 == 2) {
              uVar4 = iVar3 >> 1;
            }
            else {
              uVar4 = iVar3 >> 2;
            }
            uVar4 = ((uVar4 / 2) * 10000) / *(uint *)(iVar2 + 0x14);
          }
        }
        else {
          uVar4 = 0;
          for (; puVar6 != param_1; puVar6 = (undefined4 *)*puVar6) {
            uVar4 = uVar4 + *(ushort *)((int)puVar6 + 0xe);
          }
        }
        func_0x0bfb34e2();
        *param_3 = uVar4;
      }
      if (iVar7 == 0) {
        if ((*(byte *)(param_1 + 3) & 1) != 0) {
          uVar5 = (*(code *)param_1[4])(0x20005,0,(code *)param_1[4]);
          *(undefined4 *)(param_2 + 8) = uVar5;
        }
        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | *(uint *)(iVar8 + 0xc);
      }
      else {
        *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | *(uint *)(iVar8 + 0xc);
        param_1 = (undefined4 *)0x0;
        iVar2 = 0;
        do {
          *piVar9 = (int)param_1;
          iVar3 = 0;
          if (*(int *)(iVar7 + 0x2c) != 0) {
            FUN_0608cd6e(param_2,piVar9);
            iVar3 = *piVar9;
          }
          if (iVar2 < iVar3) {
            iVar2 = iVar3;
          }
          iVar7 = *(int *)(iVar7 + 0x30);
        } while (iVar7 != 0);
        *param_3 = *param_3 + iVar2;
      }
LAB_0608ce86:
      op_pop_pc_rl();
      puVar1 = (undefined1 *)((int)piVar9 + 4);
LAB_0608ce8a:
      piVar9 = (int *)puVar1;
    } while ((*(ushort *)(param_2 + 0x10) & 0xe98) == 0);
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
      if (iVar8 <= (int)(uint)*(ushort *)(piVar6 + 4)) goto s_Vfha_0608da10_2;
    }
  }
  else {
s_Vfha_0608da10_2:
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
code_r0x0608ddfe:
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
s___R_0608ddc7_1:
        pbVar34[1] = 1;
        *(undefined4 *)((int)piVar35 + 0x34) = 2;
        *(undefined4 *)(puVar31 + 4) = *(undefined4 *)uVar20;
        *(uint *)(puVar31 + 8) = uVar17;
        *(uint *)(puVar31 + 0xc) = (uint)bVar2;
        func_0x0bfc746a(1);
        func_0x0bfb3518(*(undefined4 *)(*(int *)(*(int *)((int)piVar35 + 4) + 0x18) + 0x2c));
        goto code_r0x0608ddfe;
      }
      if (*(int *)(puVar31 + 4) != 0) {
        func_0x0bfb683e(1);
      }
      uVar17 = *(uint *)(iVar7 + 0x18);
      iVar9 = func_0x0bfb6862();
      bVar2 = pbVar34[4];
      if (iVar9 != 0) goto s___R_0608ddc7_1;
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


// ===== FUN_0608e34c @ 0608e34c

undefined4 FUN_0608e34c(uint param_1)

{
  undefined8 uVar1;
  
  uVar1 = op_copex_ppi((ulonglong)param_1,0x16);
  return (int)uVar1;
}


// ===== FUN_0608e51e @ 0608e51e

void FUN_0608e51e(void)

{
  while ((uRam00ff03fc & 1) == 0) {
    uRam00ff03fc = 0xe7;
  }
  return;
}


// ===== FUN_0608e532 @ 0608e532

void FUN_0608e532(void)

{
  while ((uRam00ff03fc & 1) != 0) {
    uRam00ff03fc = 0xe7;
  }
  return;
}


// ===== FUN_0608e546 @ 0608e546

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0608e7e8) overlaps instruction at (ram,0x0608e7e6)
    */

void FUN_0608e546(void)

{
  uint *puVar1;
  uint extraout_r1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 extraout_r1_00;
  int extraout_r1_01;
  undefined4 uVar5;
  undefined8 uVar6;
  uint *puVar8;
  ulonglong uVar7;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  byte *in_r7;
  int iVar14;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  uint *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  int *piVar18;
  undefined1 *puVar19;
  
  op_push_rets_rl();
  FUN_06088f24();
  uVar10 = 0;
  pc_rang_limit1(0);
  pc_rang_limit2(0);
  FUN_0608e51e();
  uVar6 = 0xff03c000ff0380;
  for (iVar12 = 0; iVar12 != 7; iVar12 = iVar12 + 1) {
    *(undefined4 *)(iVar12 * 4 + 0xff0300) = uVar10;
    *(undefined4 *)(iVar12 * 4 + 0xff0340) = uVar10;
    *(undefined4 *)(iVar12 * 4 + 0xff0380) = uVar10;
    *(undefined4 *)(iVar12 * 4 + 0xff03c0) = uVar10;
  }
  FUN_0608e532();
  puVar1 = (uint *)(in_cnum * 0x800 + 0xffe200);
  uVar3 = 0xffe200;
  *puVar1 = *puVar1 & 8;
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar12 = 0x1051f8;
  for (uVar13 = 0; uVar13 < 0x41; uVar13 = uVar13 + 1) {
    uVar10 = func_0x05f9ac7a(puVar1);
    uVar6 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),uVar10);
    iVar14 = func_0x05f9ac6a(iVar12);
    uVar3 = extraout_r1;
    if (iVar14 == 0) goto LAB_0608e5da;
    iVar12 = iVar12 + 0x11;
  }
  op_pop_pc_rl();
LAB_0608e5da:
  puVar1 = (uint *)(uint)*(byte *)(iVar12 + 0x10);
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar12 = *(int *)((int)in_sp + 0x14);
  iVar14 = *(int *)((int)in_sp + 0x10);
  if (uVar3 - 0x30 < 3) {
    puVar8 = (uint *)((int)puVar1 * 4 + 0xff0340);
    iVar2 = op_ext_b0_u(uVar3 - 0x30);
    *puVar8 = *puVar8 | (int)uVar6 << (iVar2 << 3);
    uVar3 = (uint)(iVar12 != 0) << iVar2 + 0x11 | (uint)(iVar14 != 0) << iVar2 + 9;
  }
  else if (uVar3 == 0x50) {
    uVar3 = op_insert_rrii((uint)(iVar12 != 0),0x10,1);
  }
  else {
    if (uVar3 != 0x43) goto LAB_0608e660;
    op_insert_rrii((uint)((int)((ulonglong)uVar6 >> 0x20) != 0),2,1);
    uVar3 = op_insert_rrii((uint)(iVar12 != 0),1,1);
  }
  uVar6 = 0xff0300;
  puVar1 = (uint *)((int)puVar1 * 4 + 0xff0300);
  *puVar1 = *puVar1 | uVar3;
LAB_0608e660:
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar15 = (uint *)((int)in_sp + -0x10);
  uVar10 = (undefined4)uVar6;
  puVar17 = (undefined1 *)((int)in_sp + -0x10);
  if (puVar1 < (uint *)0x8) {
    in_r7 = *(byte **)((int)in_sp + 0x20);
    FUN_0608e51e();
    *(undefined4 *)((int)puVar1 * 4 + 0xff0300) = 0;
    *(undefined4 *)((int)puVar1 * 4 + 0xff0340) = 0;
    iVar12 = 0xff0380;
    *(undefined4 *)((int)puVar1 * 4 + 0xff0380) = 0;
    iVar14 = 0xff03c0;
    *(undefined4 *)((int)puVar1 * 4 + 0xff03c0) = 0;
    uVar13 = 0;
    uVar7 = 0;
    *(undefined1 **)((int)puVar15 + 8) = (undefined1 *)((int)puVar15 + 0x34);
    *(undefined1 **)((int)puVar15 + 0xc) = (undefined1 *)((int)puVar15 + 0x34);
    while( true ) {
      uVar4 = (uint)*in_r7;
      uVar5 = (undefined4)uVar7;
      uVar9 = (uint)(uVar7 >> 0x20);
      if (uVar4 == 0) break;
      if (uVar4 - 0x30 < 4) {
        uVar7 = CONCAT44(uVar9,uVar13) & 0x1ffffffff;
        puVar15[1] = (uint)(uVar7 >> 0x20);
        op_ext_b0_u_p((int)uVar7);
        *puVar15 = uVar9 & 2;
        uVar5 = op_ext_b0_u(uVar5);
        mpu_privilege(puVar1,uVar5);
        puVar8 = *(uint **)((int)puVar15 + 0xc);
        *(uint **)((int)puVar15 + 0xc) = puVar8 + 1;
        uVar13 = (uint)*in_r7;
        uVar7 = (ulonglong)*puVar8;
      }
      else if (uVar4 != 0x78) {
        if (uVar4 == 0x50) {
LAB_0608e6be:
          uVar7 = CONCAT44(uVar9,uVar13) & 0x1ffffffff;
          puVar15[1] = (uint)(uVar7 >> 0x20);
          op_ext_b0_u_p((int)uVar7);
          *puVar15 = uVar9 & 2;
          uVar5 = op_ext_b0_u(uVar5);
          mpu_privilege(puVar1,uVar5);
          uVar7 = 0;
          uVar13 = (uint)*in_r7;
        }
        else if (uVar4 == 0x72) {
          uVar7 = uVar7 | 0x200000000;
        }
        else if (uVar4 == 0x77) {
          uVar7 = uVar7 | 0x100000000;
        }
        else if (uVar4 == 0x43) goto LAB_0608e6be;
      }
      in_r7 = in_r7 + 1;
    }
    uVar7 = CONCAT44(uVar9,uVar13) & 0x1ffffffff;
    puVar15[1] = (uint)(uVar7 >> 0x20);
    op_ext_b0_u_p((int)uVar7);
    *puVar15 = uVar9 & 2;
    uVar5 = op_ext_b0_u(uVar5);
    mpu_privilege(puVar1,uVar5);
    *(uint *)(iVar12 + (int)puVar1 * 4) = uVar3;
    *(undefined4 *)(iVar14 + (int)puVar1 * 4) = uVar10;
    puVar1 = (uint *)FUN_0608e532();
    puVar17 = (undefined1 *)puVar15;
  }
  op_pop_pc_rl();
  puVar16 = puVar17 + 0xc;
  *(undefined4 *)(puVar17 + 0xc) = unaff_retaddr;
  FUN_0608e51e();
  *(undefined4 *)((int)puVar1 * 4 + 0xff0300) = 0;
  *(undefined4 *)((int)puVar1 * 4 + 0xff0340) = 0;
  *(undefined4 *)((int)puVar1 * 4 + 0xff0380) = 0;
  *(undefined4 *)((int)puVar1 * 4 + 0xff03c0) = 0;
  iVar12 = FUN_0608e532();
  op_push_rets_rl();
  uVar10 = extraout_r1_00;
  if (iVar12 != 0) {
    *(uint **)(in_cnum * 0x800 + 0xffe208) = puVar1;
    puVar1 = (uint *)0x3ff883;
    *(undefined4 *)(in_cnum * 0x800 + 0xffe20c) = extraout_r1_00;
    uVar10 = 0x3ff882;
    op_pop_pc_rl();
  }
  *(uint **)(in_cnum * 0x800 + 0xffe210) = puVar1;
  *(undefined4 *)(in_cnum * 0x800 + 0xffe214) = uVar10;
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar12 = 0x3ff880;
  *(undefined4 *)(in_cnum * 0x800 + 0xffe200) = 0xe0000007;
  puVar17 = puVar16 + -8;
code_r0x0608e7dc:
  do {
    *(undefined4 *)(in_cnum * 0x800 + (iVar12 + -0x10) * 4) = 1;
    FUN_0608e76c(1,0x103840);
    iVar14 = in_cnum << 0xb;
    iVar2 = 0xffe200;
    piVar18 = (int *)puVar17;
    do {
      *(uint *)(iVar14 + iVar2) = *(uint *)(iVar14 + iVar2) | 8;
      pc_rang_limit2(4);
      iVar11 = 0x1094e0;
      iVar14 = 0x114110;
      pc_rang_limit1(0x1094e0);
      puVar1 = (uint *)(in_cnum * 0x800 + iVar2);
      *puVar1 = *puVar1 | 0x10;
      rep_unspec(2,0x10);
      uRam00104840 = 0xffffffff;
      iVar2 = FUN_0608e5aa(0x1139e8);
      iVar12 = FUN_0608e5aa(0x1139f0);
      piVar18[2] = iVar12;
      piVar18[1] = iVar2;
      *piVar18 = iVar11;
      iVar14 = FUN_0608e662(iVar14 + -1);
      puVar19 = (undefined1 *)((int)piVar18 + 0xc);
      op_pop_pc_rl();
      puVar17 = (undefined1 *)((int)piVar18 + 0xc);
      iVar12 = extraout_r1_01;
      if (iVar11 == 0) goto code_r0x0608e7dc;
      piVar18 = (int *)((int)piVar18 + 0xc);
    } while (in_r7 == (byte *)0x0);
    puVar17 = puVar19;
    if (iVar2 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  } while( true );
}


// ===== FUN_0608e5aa @ 0608e5aa

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0608e7e8) overlaps instruction at (ram,0x0608e7e6)
    */

void FUN_0608e5aa(void)

{
  undefined4 uVar1;
  uint *puVar2;
  undefined8 in_r0_r1;
  uint extraout_r1;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 extraout_r1_00;
  int extraout_r1_01;
  undefined4 uVar6;
  undefined8 in_r2_r3;
  uint *puVar8;
  ulonglong uVar7;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  byte *in_r7;
  int iVar13;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  uint *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  int *piVar17;
  undefined1 *puVar18;
  
  op_push_rets_rl();
  uVar1 = (undefined4)in_r0_r1;
  iVar11 = 0x1051f8;
  for (uVar12 = 0; uVar12 < 0x41; uVar12 = uVar12 + 1) {
    uVar6 = func_0x05f9ac7a(uVar1);
    in_r2_r3 = CONCAT44((int)((ulonglong)in_r2_r3 >> 0x20),uVar6);
    iVar13 = func_0x05f9ac6a(iVar11);
    in_r0_r1 = CONCAT44(extraout_r1,iVar13);
    uVar4 = extraout_r1;
    if (iVar13 == 0) goto LAB_0608e5da;
    iVar11 = iVar11 + 0x11;
  }
  uVar4 = (uint)((ulonglong)in_r0_r1 >> 0x20);
  op_pop_pc_rl();
LAB_0608e5da:
  puVar2 = (uint *)(uint)*(byte *)(iVar11 + 0x10);
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar11 = *(int *)((int)in_sp + 0x14);
  iVar13 = *(int *)((int)in_sp + 0x10);
  if (uVar4 - 0x30 < 3) {
    puVar8 = (uint *)((int)puVar2 * 4 + 0xff0340);
    iVar3 = op_ext_b0_u(uVar4 - 0x30);
    *puVar8 = *puVar8 | (int)in_r2_r3 << (iVar3 << 3);
    uVar4 = (uint)(iVar11 != 0) << iVar3 + 0x11 | (uint)(iVar13 != 0) << iVar3 + 9;
  }
  else if (uVar4 == 0x50) {
    uVar4 = op_insert_rrii((uint)(iVar11 != 0),0x10,1);
  }
  else {
    if (uVar4 != 0x43) goto LAB_0608e660;
    op_insert_rrii((uint)((int)((ulonglong)in_r2_r3 >> 0x20) != 0),2,1);
    uVar4 = op_insert_rrii((uint)(iVar11 != 0),1,1);
  }
  in_r2_r3 = 0xff0300;
  puVar2 = (uint *)((int)puVar2 * 4 + 0xff0300);
  *puVar2 = *puVar2 | uVar4;
LAB_0608e660:
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar14 = (uint *)((int)in_sp + -0x10);
  uVar1 = (undefined4)in_r2_r3;
  puVar16 = (undefined1 *)((int)in_sp + -0x10);
  if (puVar2 < (uint *)0x8) {
    in_r7 = *(byte **)((int)in_sp + 0x20);
    FUN_0608e51e();
    *(undefined4 *)((int)puVar2 * 4 + 0xff0300) = 0;
    *(undefined4 *)((int)puVar2 * 4 + 0xff0340) = 0;
    iVar11 = 0xff0380;
    *(undefined4 *)((int)puVar2 * 4 + 0xff0380) = 0;
    iVar13 = 0xff03c0;
    *(undefined4 *)((int)puVar2 * 4 + 0xff03c0) = 0;
    uVar12 = 0;
    uVar7 = 0;
    *(undefined1 **)((int)puVar14 + 8) = (undefined1 *)((int)puVar14 + 0x34);
    *(undefined1 **)((int)puVar14 + 0xc) = (undefined1 *)((int)puVar14 + 0x34);
    while( true ) {
      uVar5 = (uint)*in_r7;
      uVar6 = (undefined4)uVar7;
      uVar9 = (uint)(uVar7 >> 0x20);
      if (uVar5 == 0) break;
      if (uVar5 - 0x30 < 4) {
        uVar7 = CONCAT44(uVar9,uVar12) & 0x1ffffffff;
        puVar14[1] = (uint)(uVar7 >> 0x20);
        op_ext_b0_u_p((int)uVar7);
        *puVar14 = uVar9 & 2;
        uVar6 = op_ext_b0_u(uVar6);
        mpu_privilege(puVar2,uVar6);
        puVar8 = *(uint **)((int)puVar14 + 0xc);
        *(uint **)((int)puVar14 + 0xc) = puVar8 + 1;
        uVar12 = (uint)*in_r7;
        uVar7 = (ulonglong)*puVar8;
      }
      else if (uVar5 != 0x78) {
        if (uVar5 == 0x50) {
LAB_0608e6be:
          uVar7 = CONCAT44(uVar9,uVar12) & 0x1ffffffff;
          puVar14[1] = (uint)(uVar7 >> 0x20);
          op_ext_b0_u_p((int)uVar7);
          *puVar14 = uVar9 & 2;
          uVar6 = op_ext_b0_u(uVar6);
          mpu_privilege(puVar2,uVar6);
          uVar7 = 0;
          uVar12 = (uint)*in_r7;
        }
        else if (uVar5 == 0x72) {
          uVar7 = uVar7 | 0x200000000;
        }
        else if (uVar5 == 0x77) {
          uVar7 = uVar7 | 0x100000000;
        }
        else if (uVar5 == 0x43) goto LAB_0608e6be;
      }
      in_r7 = in_r7 + 1;
    }
    uVar7 = CONCAT44(uVar9,uVar12) & 0x1ffffffff;
    puVar14[1] = (uint)(uVar7 >> 0x20);
    op_ext_b0_u_p((int)uVar7);
    *puVar14 = uVar9 & 2;
    uVar6 = op_ext_b0_u(uVar6);
    mpu_privilege(puVar2,uVar6);
    *(uint *)(iVar11 + (int)puVar2 * 4) = uVar4;
    *(undefined4 *)(iVar13 + (int)puVar2 * 4) = uVar1;
    puVar2 = (uint *)FUN_0608e532();
    puVar16 = (undefined1 *)puVar14;
  }
  op_pop_pc_rl();
  puVar15 = puVar16 + 0xc;
  *(undefined4 *)(puVar16 + 0xc) = unaff_retaddr;
  FUN_0608e51e();
  *(undefined4 *)((int)puVar2 * 4 + 0xff0300) = 0;
  *(undefined4 *)((int)puVar2 * 4 + 0xff0340) = 0;
  *(undefined4 *)((int)puVar2 * 4 + 0xff0380) = 0;
  *(undefined4 *)((int)puVar2 * 4 + 0xff03c0) = 0;
  iVar11 = FUN_0608e532();
  op_push_rets_rl();
  uVar1 = extraout_r1_00;
  if (iVar11 != 0) {
    *(uint **)(in_cnum * 0x800 + 0xffe208) = puVar2;
    puVar2 = (uint *)0x3ff883;
    *(undefined4 *)(in_cnum * 0x800 + 0xffe20c) = extraout_r1_00;
    uVar1 = 0x3ff882;
    op_pop_pc_rl();
  }
  *(uint **)(in_cnum * 0x800 + 0xffe210) = puVar2;
  *(undefined4 *)(in_cnum * 0x800 + 0xffe214) = uVar1;
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar11 = 0x3ff880;
  *(undefined4 *)(in_cnum * 0x800 + 0xffe200) = 0xe0000007;
  puVar16 = puVar15 + -8;
code_r0x0608e7dc:
  do {
    *(undefined4 *)(in_cnum * 0x800 + (iVar11 + -0x10) * 4) = 1;
    FUN_0608e76c(1,0x103840);
    iVar13 = in_cnum << 0xb;
    iVar3 = 0xffe200;
    piVar17 = (int *)puVar16;
    do {
      *(uint *)(iVar13 + iVar3) = *(uint *)(iVar13 + iVar3) | 8;
      pc_rang_limit2(4);
      iVar10 = 0x1094e0;
      iVar13 = 0x114110;
      pc_rang_limit1(0x1094e0);
      puVar2 = (uint *)(in_cnum * 0x800 + iVar3);
      *puVar2 = *puVar2 | 0x10;
      rep_unspec(2,0x10);
      uRam00104840 = 0xffffffff;
      iVar3 = FUN_0608e5aa(0x1139e8);
      iVar11 = FUN_0608e5aa(0x1139f0);
      piVar17[2] = iVar11;
      piVar17[1] = iVar3;
      *piVar17 = iVar10;
      iVar13 = FUN_0608e662(iVar13 + -1);
      puVar18 = (undefined1 *)((int)piVar17 + 0xc);
      op_pop_pc_rl();
      puVar16 = (undefined1 *)((int)piVar17 + 0xc);
      iVar11 = extraout_r1_01;
      if (iVar10 == 0) goto code_r0x0608e7dc;
      piVar17 = (int *)((int)piVar17 + 0xc);
    } while (in_r7 == (byte *)0x0);
    puVar16 = puVar18;
    if (iVar3 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  } while( true );
}


// ===== FUN_0608e662 @ 0608e662

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0608e7e8) overlaps instruction at (ram,0x0608e7e6)
    */

void FUN_0608e662(undefined4 param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  ulonglong in_r0_r1;
  undefined4 uVar4;
  uint uVar5;
  undefined4 extraout_r1;
  int extraout_r1_00;
  undefined4 uVar6;
  ulonglong uVar7;
  uint uVar8;
  int iVar9;
  byte *in_r7;
  int iVar10;
  int iVar11;
  undefined4 unaff_retaddr;
  int in_cnum;
  BADSPACEBASE *in_sp;
  uint *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  int *piVar15;
  undefined1 *puVar16;
  undefined1 auStack_10 [16];
  
  op_push_rets_rl();
  puVar12 = (uint *)auStack_10;
  uVar4 = (undefined4)(in_r0_r1 >> 0x20);
  iVar2 = (int)in_r0_r1;
  puVar14 = auStack_10;
  if (iVar2 < 8) {
    FUN_0608e51e();
    *(undefined4 *)(iVar2 * 4 + 0xff0300) = 0;
    *(undefined4 *)(iVar2 * 4 + 0xff0340) = 0;
    iVar10 = 0xff0380;
    *(undefined4 *)(iVar2 * 4 + 0xff0380) = 0;
    iVar11 = 0xff03c0;
    *(undefined4 *)(iVar2 * 4 + 0xff03c0) = 0;
    uVar1 = 0;
    uVar7 = 0;
    *(undefined1 **)((int)puVar12 + 8) = (undefined1 *)((int)puVar12 + 0x34);
    *(undefined1 **)((int)puVar12 + 0xc) = (undefined1 *)((int)puVar12 + 0x34);
    while( true ) {
      uVar5 = (uint)*param_2;
      uVar6 = (undefined4)uVar7;
      uVar8 = (uint)(uVar7 >> 0x20);
      if (uVar5 == 0) break;
      if (uVar5 - 0x30 < 4) {
        uVar7 = CONCAT44(uVar8,uVar1) & 0x1ffffffff;
        puVar12[1] = (uint)(uVar7 >> 0x20);
        op_ext_b0_u_p((int)uVar7);
        *puVar12 = uVar8 & 2;
        uVar6 = op_ext_b0_u(uVar6);
        mpu_privilege(iVar2,uVar6);
        puVar3 = *(uint **)((int)puVar12 + 0xc);
        *(uint **)((int)puVar12 + 0xc) = puVar3 + 1;
        uVar1 = (uint)*param_2;
        uVar7 = (ulonglong)*puVar3;
      }
      else if (uVar5 != 0x78) {
        if (uVar5 == 0x50) {
LAB_0608e6be:
          uVar7 = CONCAT44(uVar8,uVar1) & 0x1ffffffff;
          puVar12[1] = (uint)(uVar7 >> 0x20);
          op_ext_b0_u_p((int)uVar7);
          *puVar12 = uVar8 & 2;
          uVar6 = op_ext_b0_u(uVar6);
          mpu_privilege(iVar2,uVar6);
          uVar7 = 0;
          uVar1 = (uint)*param_2;
        }
        else if (uVar5 == 0x72) {
          uVar7 = uVar7 | 0x200000000;
        }
        else if (uVar5 == 0x77) {
          uVar7 = uVar7 | 0x100000000;
        }
        else if (uVar5 == 0x43) goto LAB_0608e6be;
      }
      param_2 = param_2 + 1;
    }
    uVar7 = CONCAT44(uVar8,uVar1) & 0x1ffffffff;
    puVar12[1] = (uint)(uVar7 >> 0x20);
    op_ext_b0_u_p((int)uVar7);
    *puVar12 = uVar8 & 2;
    uVar6 = op_ext_b0_u(uVar6);
    mpu_privilege(iVar2,uVar6);
    *(undefined4 *)(iVar10 + iVar2 * 4) = uVar4;
    *(undefined4 *)(iVar11 + iVar2 * 4) = param_1;
    uVar1 = FUN_0608e532();
    in_r0_r1 = (ulonglong)uVar1;
    in_r7 = param_2;
    puVar14 = (undefined1 *)puVar12;
  }
  op_pop_pc_rl();
  puVar13 = puVar14 + 0xc;
  *(undefined4 *)(puVar14 + 0xc) = unaff_retaddr;
  iVar10 = (int)in_r0_r1;
  FUN_0608e51e();
  *(undefined4 *)(iVar10 * 4 + 0xff0300) = 0;
  *(undefined4 *)(iVar10 * 4 + 0xff0340) = 0;
  *(undefined4 *)(iVar10 * 4 + 0xff0380) = 0;
  *(undefined4 *)(iVar10 * 4 + 0xff03c0) = 0;
  iVar2 = FUN_0608e532();
  op_push_rets_rl();
  uVar4 = extraout_r1;
  if (iVar2 != 0) {
    *(int *)(in_cnum * 0x800 + 0xffe208) = iVar10;
    iVar10 = 0x3ff883;
    *(undefined4 *)(in_cnum * 0x800 + 0xffe20c) = extraout_r1;
    uVar4 = 0x3ff882;
    op_pop_pc_rl();
  }
  *(int *)(in_cnum * 0x800 + 0xffe210) = iVar10;
  *(undefined4 *)(in_cnum * 0x800 + 0xffe214) = uVar4;
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar2 = 0x3ff880;
  *(undefined4 *)(in_cnum * 0x800 + 0xffe200) = 0xe0000007;
  puVar14 = puVar13 + -8;
code_r0x0608e7dc:
  do {
    *(undefined4 *)(in_cnum * 0x800 + (iVar2 + -0x10) * 4) = 1;
    FUN_0608e76c(1,0x103840);
    iVar10 = in_cnum << 0xb;
    iVar11 = 0xffe200;
    piVar15 = (int *)puVar14;
    do {
      *(uint *)(iVar10 + iVar11) = *(uint *)(iVar10 + iVar11) | 8;
      pc_rang_limit2(4);
      iVar9 = 0x1094e0;
      iVar10 = 0x114110;
      pc_rang_limit1(0x1094e0);
      puVar3 = (uint *)(in_cnum * 0x800 + iVar11);
      *puVar3 = *puVar3 | 0x10;
      rep_unspec(2,0x10);
      uRam00104840 = 0xffffffff;
      iVar11 = FUN_0608e5aa(0x1139e8);
      iVar2 = FUN_0608e5aa(0x1139f0);
      piVar15[2] = iVar2;
      piVar15[1] = iVar11;
      *piVar15 = iVar9;
      iVar10 = FUN_0608e662(iVar10 + -1);
      puVar16 = (undefined1 *)((int)piVar15 + 0xc);
      op_pop_pc_rl();
      puVar14 = (undefined1 *)((int)piVar15 + 0xc);
      iVar2 = extraout_r1_00;
      if (iVar9 == 0) goto code_r0x0608e7dc;
      piVar15 = (int *)((int)piVar15 + 0xc);
    } while (in_r7 == (byte *)0x0);
    puVar14 = puVar16;
    if (iVar11 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  } while( true );
}


// ===== FUN_0608e76c @ 0608e76c

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0608e7e8) overlaps instruction at (ram,0x0608e7e6)
    */

void FUN_0608e76c(undefined4 param_1)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  undefined8 in_r0_r1;
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
  if ((int)in_r0_r1 != 0) {
    *(undefined4 *)(in_cnum * 0x800 + 0xffe208) = param_1;
    param_1 = 0x3ff883;
    *(int *)(in_cnum * 0x800 + 0xffe20c) = (int)((ulonglong)in_r0_r1 >> 0x20);
    in_r0_r1 = 0x3ff88200000000;
    op_pop_pc_rl();
  }
  *(undefined4 *)(in_cnum * 0x800 + 0xffe210) = param_1;
  *(int *)(in_cnum * 0x800 + 0xffe214) = (int)((ulonglong)in_r0_r1 >> 0x20);
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar3 = 0x3ff880;
  *(undefined4 *)(in_cnum * 0x800 + 0xffe200) = 0xe0000007;
  puVar6 = auStack_c;
code_r0x0608e7dc:
  do {
    *(undefined4 *)(in_cnum * 0x800 + (iVar3 + -0x10) * 4) = 1;
    FUN_0608e76c(1,0x103840);
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
      if (iVar4 == 0) goto code_r0x0608e7dc;
      piVar7 = (int *)((int)piVar7 + 0xc);
    } while (in_r7 == 0);
    puVar6 = puVar8;
    if (iVar5 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  } while( true );
}


// ===== FUN_0608eab2 @ 0608eab2

undefined4 FUN_0608eab2(void)

{
  undefined4 uVar1;
  undefined4 in_icfg;
  
  uVar1 = op_ext_b0_u(in_icfg);
  return uVar1;
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


// ===== FUN_0608ead8 @ 0608ead8

void FUN_0608ead8(void)

{
                    /* WARNING: Subroutine does not return */
  p33_soft_reset();
}


// ===== FUN_0608ebc0 @ 0608ebc0

/* WARNING: Removing unreachable block (ram,0x0608ebe8) */

void FUN_0608ebc0(void)

{
                    /* WARNING: Do nothing block with infinite loop */
  do {
  } while( true );
}


// ===== FUN_0608ebea @ 0608ebea

void FUN_0608ebea(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_cnum;
  
  uVar1 = op_ext_b0_u(0x7f - in_cnum);
  uVar2 = op_ext_b0_u(in_cnum);
                    /* WARNING: Subroutine does not return */
  FUN_06087cd8(uVar1,0,FUN_0010bd64,uVar2);
}


// ===== FUN_0608ec0c @ 0608ec0c

void FUN_0608ec0c(void)

{
  int in_cnum;
  
  func_0x0608ed3c(*(undefined4 *)(in_cnum * 4 + 0x108220));
  op_pop_srl();
  op_pop_rmask(0xffff);
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


