// ===== drc_db2mag @ 06085550

/* B3 SDK signature: drc_db2mag
     source: br28 sdk.elf (AC701N SDK)
     elf addr: 001225b6
     size: 26 B, words diff: 0/3
     method: byte-exact anchor match (tools/b3_sigs2.py) */

void drc_db2mag(int param_1,uint param_2)

{
  int iVar1;
  undefined2 *puVar2;
  undefined4 *extraout_r1;
  undefined4 *extraout_r1_00;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar9;
  undefined8 uVar8;
  undefined4 *puVar10;
  BADSPACEBASE *in_sp;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  int iStack_8;
  
  piVar11 = &iStack_8;
  iStack_8 = param_1 * 0x3debc8e3;
  func_0x06085542();
  op_push_rets_rl();
  piVar12 = piVar11 + -1;
  iVar7 = *(int *)(*piVar11 + 0x14);
  puVar10 = *(undefined4 **)(*piVar11 + 0x18);
  piVar13 = piVar11 + -1;
  if (*(int *)(iVar7 + 0x18) == 0) {
    iVar1 = FUN_0608c0f4();
    *(int *)(iVar7 + 0x18) = iVar1;
    piVar13 = piVar12;
    puVar3 = extraout_r1;
    if (iVar1 != 0) goto code_r0x06085584;
code_r0x060856ee:
    puVar2 = (undefined2 *)0x0;
    op_pop_pc_rl();
  }
  else {
code_r0x06085584:
    pcVar9 = (char *)(iVar7 + 0x68);
    iVar1 = *(int *)(iVar7 + 0x10);
    if (*(char *)(iVar7 + 0x6a) == '\0') {
      if (iVar1 == 0) {
        *(undefined8 *)piVar13 = 0;
        iVar1 = puVar10[6];
        *piVar13 = *(undefined4 *)(iVar1 + 0x14);
        *(byte *)((int)piVar13 + 4) = *(byte *)(iVar1 + 8) >> 4;
        uVar6 = op_insert_rrii((uint)*(byte *)(iVar7 + 0x69),4,0x1c);
        *(char *)((int)piVar13 + 5) = (char)uVar6;
        *(undefined1 *)((int)piVar13 + 6) =
             *(undefined1 *)(*(int *)(*(int *)(iVar7 + 0x14) + 0x18) + 4);
        *(int *)((int)piVar13 + 8) = iVar7 + 0x1c;
        iVar1 = (*pcRam001134fc)();
        goto code_r0x060855e2;
      }
    }
    else if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      (*pcRam00113500)();
      iVar1 = 0;
code_r0x060855e2:
      *(int *)(iVar7 + 0x10) = iVar1;
    }
    iVar4 = *(int *)(iVar7 + 0x18);
    if ((*(char *)(iVar4 + 0xc) != *pcVar9) &&
       (*pcVar9 = *(char *)(iVar4 + 0xc) != '\0', iVar1 != 0)) {
      uVar6 = op_insert_rrii_p((uint)(byte)pcVar9[1],4,0x1c);
      op_ext_b0_u(uVar6);
      (*pcRam00113508)(pcRam00113508,uVar6);
      iVar4 = *(int *)(iVar7 + 0x18);
    }
    param_2 = (uint)(*(ushort *)(iVar4 + 0x12) >> (uint)(pcVar9[1] == '\0'));
    uVar8 = CONCAT44(pcVar9,param_2);
    puVar10 = puVar10 + 6;
    op_ext_l_u(param_2);
    iVar1 = FUN_0608bf56(*puVar10);
    puVar3 = extraout_r1_00;
    if (iVar1 == 0) goto code_r0x060856ee;
    *(short *)(iVar1 + 0x12) = (short)uVar8;
    pcVar9 = (char *)((ulonglong)uVar8 >> 0x20);
    if (*(int *)(iVar7 + 0x10) != 0) {
      uVar6 = (*pcRam00113504)(*(undefined4 *)(iVar1 + 0x20),
                               *(undefined2 *)(*(int *)(iVar7 + 0x18) + 0x12));
      *(undefined4 *)(pcVar9 + 4) = uVar6;
      goto code_r0x060856d6;
    }
    if (*pcVar9 == '\0') {
      if (pcVar9[1] != '\0') {
        puVar3 = *(undefined4 **)(iVar1 + 0x20);
        uVar5 = (uint)(*(ushort *)(*(int *)(iVar7 + 0x18) + 0x12) >> 1);
        if (*(char *)(*(int *)(*(int *)(iVar7 + 0x14) + 0x18) + 4) == '\x17') {
          do {
            rep_unspec(10,uVar5);
            uVar6 = op_shl3_rr(8);
            *puVar3 = uVar6;
            puVar3 = puVar3 + 1;
          } while (uVar5 != 0);
        }
        else {
          func_0x0bfc91da();
        }
        goto code_r0x060856d6;
      }
code_r0x060856c8:
      func_0x05f9ac62(*(undefined2 *)(*(int *)(iVar7 + 0x18) + 0x12));
      goto code_r0x060856d6;
    }
    if (pcVar9[1] != '\0') goto code_r0x060856c8;
    puVar2 = *(undefined2 **)(iVar1 + 0x20);
    iVar1 = (int)((ulonglong)*(undefined8 *)(iVar7 + 0x14) >> 0x20);
    puVar3 = *(undefined4 **)(iVar1 + 0x20);
    param_2 = (uint)(*(ushort *)(iVar1 + 0x12) >> 2);
    if (*(char *)(*(int *)((int)*(undefined8 *)(iVar7 + 0x14) + 0x18) + 4) == '\x17') {
      do {
        rep_unspec(0x10,param_2);
        uVar8 = op_mul_mem1_w_i_s(puVar3,4,1);
        uVar6 = op_shiftr_rpr_mode(uVar8,8);
        uVar6 = sat16(uVar6);
        *puVar2 = (short)uVar6;
        puVar2 = puVar2 + 1;
      } while (param_2 != 0);
      goto code_r0x060856d6;
    }
  }
  do {
    rep_unspec(8,param_2);
    uVar6 = *puVar3;
    puVar3 = puVar3 + 1;
    uVar6 = sat16(uVar6);
    *puVar2 = (short)uVar6;
    puVar2 = puVar2 + 1;
  } while (param_2 != 0);
code_r0x060856d6:
                    /* WARNING: Subroutine does not return */
  thunk_FUN_0608c0b2(*puVar10);
}


// ===== DrcPeakFollowProcess @ 06085848

/* WARNING: Possible PIC construction at 0x06085fd8: Changing call to branch */
/* WARNING: Possible PIC construction at 0x06085f44: Changing call to branch */
/* WARNING: Possible PIC construction at 0x06085eae: Changing call to branch */
/* WARNING: Possible PIC construction at 0x06085e1a: Changing call to branch */
/* WARNING: Possible PIC construction at 0x06085dba: Changing call to branch */
/* WARNING: Possible PIC construction at 0x06085ce4: Changing call to branch */
/* WARNING: Possible PIC construction at 0x06085c86: Changing call to branch */
/* WARNING: Possible PIC construction at 0x06085bbc: Changing call to branch */
/* WARNING: Possible PIC construction at 0x06085b58: Changing call to branch */
/* WARNING: Possible PIC construction at 0x06085a98: Changing call to branch */
/* WARNING: Possible PIC construction at 0x06085a00: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0608599a: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x06085a04) */
/* WARNING: Removing unreachable block (ram,0x06085a9c) */
/* WARNING: Removing unreachable block (ram,0x06085b5c) */
/* WARNING: Removing unreachable block (ram,0x06085bc0) */
/* WARNING: Removing unreachable block (ram,0x06085c8a) */
/* WARNING: Removing unreachable block (ram,0x06085ce8) */
/* WARNING: Removing unreachable block (ram,0x06085dbe) */
/* WARNING: Removing unreachable block (ram,0x06085e1e) */
/* WARNING: Removing unreachable block (ram,0x06085eb2) */
/* WARNING: Removing unreachable block (ram,0x06085f48) */
/* WARNING: Removing unreachable block (ram,0x06085fdc) */
/* WARNING: Removing unreachable block (ram,0x0608599e) */
/* B3 SDK signature: DrcPeakFollowProcess
     source: br23-sdk.elf
     elf addr: 01e7a1be
     size: 52 B, words diff: 0/6
     method: byte-exact anchor match (tools/b3_sigs2.py) */

void DrcPeakFollowProcess(int param_1,int param_2,int param_3)

{
  byte bVar1;
  char cVar2;
  float fVar3;
  byte bVar4;
  undefined4 *puVar5;
  int iVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  ushort *puVar10;
  ushort *puVar11;
  undefined4 *puVar12;
  int iVar13;
  float *pfVar14;
  int iVar15;
  undefined4 uVar16;
  uint uVar17;
  undefined4 uVar18;
  char *pcVar19;
  uint uVar20;
  undefined4 *puVar21;
  ushort *puVar22;
  undefined4 *puVar23;
  BADSPACEBASE *in_sp;
  undefined1 *puVar24;
  undefined1 *puVar25;
  undefined1 *puVar26;
  undefined1 *puVar27;
  undefined1 *puVar28;
  undefined1 *puVar29;
  undefined1 *puVar30;
  undefined1 *puVar31;
  undefined1 *puVar32;
  undefined1 *puVar33;
  undefined1 *puVar34;
  undefined1 *puVar35;
  undefined1 *puVar36;
  undefined8 uVar37;
  
  op_push_rets_rl();
  puVar12 = (undefined4 *)(param_3 * 4 + param_1);
  if (param_2 < 0) {
    param_2 = -param_2;
  }
  iVar9 = itof(param_2);
  iVar9 = iVar9 - puVar12[0x14];
  puVar5 = (undefined4 *)(puVar12[0x14] + iVar9 * *(int *)(param_1 + 0x20));
  puVar12[0x14] = puVar5;
  op_pop_pc_rl();
  puVar24 = (undefined1 *)in_sp;
code_r0x0608587c:
  do {
    op_push_rets_rl();
    iVar13 = 0x41a00000;
    iVar6 = FUN_0608e36e(puVar5[iVar9 + 0x14] + 0x3f800000);
    iVar9 = puVar5[6];
    fVar7 = (float)(iVar13 * iVar6 * 0x3ede5bd9);
    pfVar14 = (float *)(puVar5 + iVar9 + 8);
    do {
      iVar9 = iVar9 + -1;
      if (iVar9 < 1) {
        iVar9 = 0;
        break;
      }
      fVar3 = *pfVar14;
      pfVar14 = pfVar14 + -1;
    } while (fVar7 <= fVar3);
    iVar15 = (int)fVar7 * puVar5[iVar9 + 0xc];
    uVar37 = drc_db2mag(puVar5[0x17] + ((puVar5[iVar9 + 0x10] + iVar15) - (int)fVar7));
    puVar5 = (undefined4 *)((ulonglong)uVar37 >> 0x20);
    puVar21 = (undefined4 *)uVar37;
    *puVar12 = puVar5;
    op_pop_pc_rl();
    op_push_rets_rl();
    puVar25 = puVar24 + -0x20;
    puVar26 = puVar24 + -0x20;
    bVar4 = *(byte *)((int)puVar5 + 10);
    *(undefined4 *)(puVar24 + -0x14) = puVar5[4];
    bVar1 = *(byte *)((int)puVar5 + 0xb);
    uVar8 = (uint)puVar12 & 1;
    *(uint *)(puVar24 + -0x18) = uVar8;
    *(uint *)(puVar24 + -0x1c) = uVar8;
    iVar9 = 0;
    op_sextra_rrii((uint)bVar4,0,8);
    uVar17 = 0;
    op_ext_b0_s((uint)bVar1);
    iVar6 = puVar5[0x16];
    *(undefined4 *)(puVar24 + -0x20) = 4;
    iVar13 = iVar15;
    puVar23 = puVar21;
    for (; iVar9 < *(int *)(puVar24 + -0x14); iVar9 = iVar9 + 1) {
      *(int *)(puVar24 + -0x10) = iVar13;
      *(undefined4 **)(puVar24 + -8) = puVar21;
      *(int *)(puVar24 + -0xc) = iVar15;
      if (0 < (int)((int)puVar12 - uVar8)) {
        iVar13 = itof(*puVar21);
        uVar16 = op_ftoi_trunc_rr(iVar6 * iVar13);
        (*(code *)*puVar5)(puVar5,uVar16,iVar9,(code *)*puVar5);
        puVar12 = (undefined4 *)(puVar25 + 0x1c);
        puVar24 = puVar25;
        goto code_r0x0608587c;
      }
      if (*(int *)(puVar24 + -0x1c) != 0) {
        iVar13 = itof(*puVar23);
        uVar16 = op_ftoi_trunc_rr(iVar6 * iVar13);
        (*(code *)*puVar5)(puVar5,uVar16,iVar9,(code *)*puVar5);
        puVar12 = (undefined4 *)(puVar26 + 0x1c);
        puVar24 = puVar26;
        goto code_r0x0608587c;
      }
      iVar15 = *(int *)(puVar24 + -0xc) + *(int *)(puVar24 + -0x18);
      uVar17 = *(uint *)(puVar24 + -0x20);
      puVar21 = (undefined4 *)(*(int *)(puVar24 + -8) + uVar17);
      puVar23 = (undefined4 *)((int)puVar23 + uVar17);
      iVar13 = *(int *)(puVar24 + -0x10) + *(int *)(puVar24 + -0x18);
    }
    op_pop_pc_rl();
    op_push_rets_rl();
    puVar27 = puVar24 + -0x10;
    puVar5 = (undefined4 *)0x0;
    *(undefined4 *)(puVar24 + -8) = uRam00000010;
    iVar6 = op_ext_b0_s_p((uint)bRam0000000a);
    *(int *)(puVar24 + -0xc) = iVar6;
    puVar10 = (ushort *)op_ext_b0_s((uint)bRam0000000b);
    *(undefined4 *)(puVar24 + -0x10) = 4;
    for (iVar9 = 0; iVar9 < *(int *)(puVar24 + -8); iVar9 = iVar9 + 1) {
      if (0 < (int)uVar17) {
        iVar6 = itof(*puVar21);
        uVar16 = op_ftoi_trunc_rr(iRam00000058 * iVar6);
        (*pcRam00000000)(0,uVar16,iVar9,pcRam00000000);
        puVar12 = (undefined4 *)(puVar27 + 0xc);
        puVar24 = puVar27;
        goto code_r0x0608587c;
      }
      puVar21 = (undefined4 *)((int)puVar21 + *(int *)(puVar24 + -0x10));
    }
    op_pop_pc_rl();
    op_push_rets_rl();
    puVar28 = puVar24 + -0x1c;
    puVar29 = puVar24 + -0x1c;
    puVar5 = (undefined4 *)0x0;
    *(uint *)(puVar24 + -0x10) = uVar17;
    *(uint *)(puVar24 + -0x14) = uVar17;
    uVar20 = uVar17 & 1;
    *(uint *)(puVar24 + -0x18) = uVar20;
    *(uint *)(puVar24 + -0x1c) = uVar20;
    iVar9 = 0;
    uVar8 = 0;
    op_ext_b0_s((uint)bRam0000000a);
    op_sextra_rrii((uint)bRam0000000b,0,8);
    puVar11 = puVar10;
    puVar22 = puVar10;
    for (; iVar9 < *(int *)(puVar24 + -0x10); iVar9 = iVar9 + 1) {
      *(ushort **)(puVar24 + -8) = puVar22;
      *(int *)(puVar24 + -0xc) = iVar6;
      if (0 < (int)(uVar17 - uVar20)) {
        iVar6 = itof((uint)*puVar22);
        uVar16 = op_ftoi_trunc_rr(iRam00000058 * iVar6);
        (*pcRam00000000)(0,uVar16,iVar9,pcRam00000000);
        puVar12 = (undefined4 *)(puVar28 + 0x18);
        puVar24 = puVar28;
        goto code_r0x0608587c;
      }
      if (*(int *)(puVar24 + -0x1c) != 0) {
        iVar6 = itof((uint)*puVar11);
        uVar16 = op_ftoi_trunc_rr(iRam00000058 * iVar6);
        (*pcRam00000000)(0,uVar16,iVar9,pcRam00000000);
        puVar12 = (undefined4 *)(puVar29 + 0x18);
        puVar24 = puVar29;
        goto code_r0x0608587c;
      }
      puVar22 = (ushort *)(*(int *)(puVar24 + -8) + *(int *)(puVar24 + -0x14));
      uVar8 = *(uint *)(puVar24 + -0x18);
      iVar6 = *(int *)(puVar24 + -0xc) + uVar8;
      puVar11 = (ushort *)((int)puVar11 + *(int *)(puVar24 + -0x14));
    }
    op_pop_pc_rl();
    op_push_rets_rl();
    puVar30 = puVar24 + -0x20;
    puVar31 = puVar24 + -0x20;
    puVar5 = (undefined4 *)0x0;
    *(undefined4 *)(puVar24 + -0x14) = uRam00000010;
    uVar20 = uVar8 & 1;
    *(uint *)(puVar24 + -0x18) = uVar20;
    *(uint *)(puVar24 + -0x1c) = uVar20;
    iVar9 = 0;
    uVar17 = 0;
    op_ext_b0_s((uint)bRam0000000a);
    op_ext_b0_s((uint)bRam0000000b);
    *(undefined4 *)(puVar24 + -0x20) = 4;
    iVar13 = iVar6;
    puVar11 = puVar10;
    for (; iVar9 < *(int *)(puVar24 + -0x14); iVar9 = iVar9 + 1) {
      *(int *)(puVar24 + -0x10) = iVar13;
      *(ushort **)(puVar24 + -8) = puVar10;
      *(int *)(puVar24 + -0xc) = iVar6;
      if (0 < (int)(uVar8 - uVar20)) {
        iVar6 = itof((uint)*puVar10);
        uVar16 = op_ftoi_trunc_rr(iRam00000058 * iVar6);
        (*pcRam00000000)(0,uVar16,iVar9,pcRam00000000);
        puVar12 = (undefined4 *)(puVar30 + 0x1c);
        puVar24 = puVar30;
        goto code_r0x0608587c;
      }
      if (*(int *)(puVar24 + -0x1c) != 0) {
        iVar6 = itof((uint)*puVar11);
        uVar16 = op_ftoi_trunc_rr(iRam00000058 * iVar6);
        (*pcRam00000000)(0,uVar16,iVar9,pcRam00000000);
        puVar12 = (undefined4 *)(puVar31 + 0x1c);
        puVar24 = puVar31;
        goto code_r0x0608587c;
      }
      puVar10 = (ushort *)(*(int *)(puVar24 + -8) + *(int *)(puVar24 + -0x18));
      uVar17 = *(uint *)(puVar24 + -0x20);
      iVar6 = *(int *)(puVar24 + -0xc) + uVar17;
      puVar11 = (ushort *)((int)puVar11 + *(int *)(puVar24 + -0x18));
      iVar13 = *(int *)(puVar24 + -0x10) + uVar17;
    }
    op_pop_pc_rl();
    op_push_rets_rl();
    puVar32 = puVar24 + -0x24;
    puVar33 = puVar24 + -0x24;
    puVar5 = (undefined4 *)0x0;
    *(undefined4 *)(puVar24 + -0x18) = uRam00000010;
    *(uint *)(puVar24 + -0x1c) = uVar17 & 1;
    iVar9 = 0;
    op_sextra_rrii((uint)bRam0000000a,0,8);
    iVar13 = op_ext_b0_s((uint)bRam0000000b);
    iVar13 = iVar13 << 1;
    *(undefined4 *)(puVar24 + -0x20) = 4;
    *(undefined4 *)(puVar24 + -0x24) = 4;
    iVar15 = iVar6;
    puVar11 = puVar10;
    for (; iVar9 < *(int *)(puVar24 + -0x18); iVar9 = iVar9 + 1) {
      *(int *)(puVar24 + -0x14) = iVar15;
      *(ushort **)(puVar24 + -0x10) = puVar11;
      *(ushort **)(puVar24 + -0xc) = puVar10;
      *(int *)(puVar24 + -8) = iVar6;
      if (0 < (int)(uVar17 - (uVar17 & 1))) {
        iVar6 = itof(*(undefined4 *)puVar10);
        uVar16 = op_ftoi_trunc_rr(iRam00000058 * iVar6);
        (*pcRam00000000)(0,uVar16,iVar9,pcRam00000000);
        puVar12 = (undefined4 *)(puVar32 + 0x20);
        puVar24 = puVar32;
        goto code_r0x0608587c;
      }
      if (*(int *)(puVar24 + -0x1c) != 0) {
        iVar6 = itof(**(undefined4 **)(puVar24 + -0x10));
        uVar16 = op_ftoi_trunc_rr(iRam00000058 * iVar6);
        (*pcRam00000000)(0,uVar16,iVar9,pcRam00000000);
        puVar12 = (undefined4 *)(puVar33 + 0x20);
        puVar24 = puVar33;
        goto code_r0x0608587c;
      }
      puVar10 = (ushort *)(*(int *)(puVar24 + -0xc) + *(int *)(puVar24 + -0x20));
      iVar13 = *(int *)(puVar24 + -0x24);
      iVar6 = *(int *)(puVar24 + -8) + iVar13;
      puVar11 = (ushort *)((int)*(undefined4 **)(puVar24 + -0x10) + *(int *)(puVar24 + -0x20));
      iVar15 = *(int *)(puVar24 + -0x14) + iVar13;
    }
    op_pop_pc_rl();
    op_push_rets_rl();
    puVar34 = puVar24 + -0x10;
    puVar5 = (undefined4 *)0x0;
    *(undefined4 *)(puVar24 + -8) = uRam00000010;
    puVar11 = (ushort *)(uint)bRam0000000b;
    *(int *)(puVar24 + -0xc) = iVar13;
    op_ext_b0_s_p((uint)bRam0000000a);
    *(undefined4 *)(puVar24 + -0x10) = 2;
    op_ext_b0_s(puVar11);
    for (iVar9 = 0; iVar9 < *(int *)(puVar24 + -8); iVar9 = iVar9 + 1) {
      if (0 < iVar13) {
        iVar6 = itof((uint)*puVar10);
        uVar16 = op_ftoi_trunc_rr(iRam00000058 * iVar6);
        (*pcRam00000000)(0,uVar16,iVar9,pcRam00000000);
        puVar12 = (undefined4 *)(puVar34 + 0xc);
        puVar24 = puVar34;
        goto code_r0x0608587c;
      }
      puVar10 = (ushort *)((int)puVar10 + *(int *)(puVar24 + -0xc));
    }
    op_pop_pc_rl();
    op_push_rets_rl();
    puVar35 = puVar24 + -0x10;
    puVar5 = (undefined4 *)0x0;
    *(undefined4 *)(puVar24 + -8) = uRam00000010;
    uVar16 = op_ext_b0_s_p((uint)bRam0000000b);
    *(undefined4 *)(puVar24 + -0xc) = uVar16;
    puVar12 = (undefined4 *)op_ext_b0_s((uint)bRam0000000a);
    *(undefined4 *)(puVar24 + -0x10) = 4;
    for (iVar9 = 0; iVar9 < *(int *)(puVar24 + -8); iVar9 = iVar9 + 1) {
      if (0 < iVar13) {
        iVar6 = itof((uint)*puVar11);
        uVar16 = op_ftoi_trunc_rr(iRam00000058 * iVar6);
        (*pcRam00000000)(0,uVar16,iVar9,pcRam00000000);
        puVar12 = (undefined4 *)(puVar35 + 0xc);
        puVar24 = puVar35;
        goto code_r0x0608587c;
      }
      puVar11 = (ushort *)((int)puVar11 + *(int *)(puVar24 + -0xc));
    }
    op_pop_pc_rl();
    op_push_rets_rl();
    puVar36 = puVar24 + -0x10;
    puVar5 = (undefined4 *)0x0;
    *(undefined4 *)(puVar24 + -8) = uRam00000010;
    uVar18 = op_ext_b0_s((uint)bRam0000000b);
    uVar16 = op_ext_b0_s((uint)bRam0000000a);
    iVar9 = 0;
    *(undefined8 *)(puVar24 + -0x10) = 0x400000004;
    while( true ) {
      if (*(int *)(puVar24 + -8) <= iVar9) {
        op_pop_pc_rl();
        op_push_rets_rl();
        pcVar19 = (char *)(iRam0000001c + 0x40);
        *(undefined4 *)(puVar24 + -4) = 4;
        cVar2 = *(char *)(iRam0000001c + 0x44);
        *(undefined4 *)(puVar24 + -8) = 2;
        if (cVar2 == '\0') {
          *(undefined4 *)(puVar24 + -8) = 1;
        }
        FUN_06088a6a(uVar16,uVar18);
        if (*pcVar19 == '\0') {
          *pcVar19 = '\x01';
                    /* WARNING: Subroutine does not return */
          FUN_06088ab8();
        }
                    /* WARNING: Subroutine does not return */
        FUN_06088ab8();
      }
      if (0 < iVar13) break;
      puVar12 = (undefined4 *)((int)puVar12 + *(int *)(puVar24 + -0xc));
      iVar9 = iVar9 + 1;
    }
    iVar6 = itof(*puVar12);
    uVar16 = op_ftoi_trunc_rr(iRam00000058 * iVar6);
    (*pcRam00000000)(0,uVar16,iVar9,pcRam00000000);
    puVar12 = (undefined4 *)(puVar36 + 0xc);
    puVar24 = puVar36;
  } while( true );
}


// ===== audio_eq_tab_check @ 06065808

/* B3 SDK signature: audio_eq_tab_check
     source: br28 sdk.elf (AC701N SDK)
     elf addr: 00123efa
     size: 74 B, words diff: 0/9
     method: byte-exact anchor match (tools/b3_sigs2.py) */

void audio_eq_tab_check(void)

{
  undefined4 uVar1;
  ushort *puVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  ushort *puVar8;
  int iVar9;
  int iVar10;
  ulonglong in_r0_r1;
  uint uVar12;
  uint extraout_r1;
  ulonglong uVar11;
  int extraout_r1_00;
  undefined4 *puVar13;
  undefined4 uVar14;
  int iVar18;
  ulonglong uVar15;
  undefined8 uVar16;
  ulonglong uVar17;
  int iVar19;
  uint uVar20;
  int iVar21;
  code *pcVar22;
  code *pcVar23;
  undefined1 uVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  uint uVar29;
  BADSPACEBASE *in_sp;
  undefined1 *puVar30;
  undefined1 *puVar31;
  int *piVar32;
  
  op_push_rets_rl();
  puVar13 = (undefined4 *)((int)in_r0_r1 + 8);
  uVar17 = in_r0_r1 & 0xffffffff00000000;
  iVar19 = 0;
  iVar18 = 0;
  while( true ) {
    iVar26 = (int)(uVar17 >> 0x20);
    if (iVar26 == 0) break;
    if (*(short *)((int)puVar13 + -6) == 7) {
      uVar6 = op_ftoi_trunc_rr(*puVar13);
      iVar18 = iVar18 + ((int)uVar6 >> 1) + (uVar6 & 1);
code_r0x06065840:
      uVar17 = CONCAT44(iVar26,(uint)uVar17 + 1);
    }
    else if (*(short *)((int)puVar13 + -6) == 8) {
      uVar6 = op_ftoi_trunc_rr(*puVar13);
      iVar19 = iVar19 + ((int)uVar6 >> 1) + (uVar6 & 1);
      goto code_r0x06065840;
    }
    uVar17 = CONCAT44((int)(uVar17 >> 0x20) + -1,(int)uVar17);
    puVar13 = puVar13 + 4;
  }
  uVar12 = iVar18 << 0x10;
  uVar5 = (uint)uVar17 | iVar19 << 8 | uVar12;
  op_pop_pc_rl();
  op_push_rets_rl();
  pcVar22 = (code *)0x110b16;
  uVar6 = uVar5;
  uVar20 = uVar12;
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    uVar6 = (*pcVar22)(uVar12);
    uVar12 = uVar12 + 0x14;
    uVar20 = extraout_r1;
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  uVar17 = (ulonglong)uVar20;
  uVar11 = uVar17 << 0x20;
  iVar18 = 0;
  if (1 < uVar20) {
    iVar19 = uVar6 + (uVar20 - 1) * 0x10;
    iVar18 = 0;
    if (*(short *)(iVar19 + 2) == 7) {
      iVar18 = op_ftoi_trunc_rr(*(undefined4 *)(iVar19 + 8));
      uVar15 = CONCAT44(iVar18,uVar6) & 0x1ffffffff;
      uVar6 = (uint)uVar15;
      iVar18 = (int)(uVar15 >> 0x20) + (iVar18 >> 1);
    }
  }
  iVar19 = uVar6 + uVar20 * 0x10;
  uVar4 = *(ushort *)(iVar19 + 2);
  if (uVar4 < 7) {
code_r0x060658d0:
    if ((1 < (uint)(uVar11 >> 0x20)) &&
       (uVar11 = (ulonglong)CONCAT24(*(short *)(iVar19 + -0xe),(int)uVar11),
       *(short *)(iVar19 + -0xe) == 7)) {
      uVar11 = CONCAT44(iVar18 + -1,iVar18 + -1);
      op_pop_pc_rl();
    }
    iVar26 = (int)uVar11;
  }
  else {
    uVar6 = op_ftoi_trunc_rr(*(undefined4 *)(iVar19 + 8));
    if (uVar4 == 8) {
      uVar11 = CONCAT44(uVar20,iVar18 + -1);
    }
    else {
      uVar11 = uVar17 << 0x20;
      if (uVar4 == 7) {
        uVar11 = uVar17 << 0x20;
      }
    }
    iVar26 = -2;
    if ((uVar6 & 1) != -((int)uVar6 >> 1)) goto code_r0x060658d0;
  }
  uVar6 = (uint)(uVar11 >> 0x20);
  op_pop_pc_rl();
  op_push_rets_rl();
  piVar7 = (int *)(iVar26 + 0x80);
  if (uVar6 == 0) {
    piVar7 = (int *)(iVar26 + 0x7c);
  }
  puVar8 = (ushort *)*piVar7;
  if ((((puVar8 != (ushort *)0x0) && (puVar2 = puVar8 + 6, *(int *)puVar2 != 0)) &&
      (uVar6 = *(uint *)(puVar8 + 8), uVar6 != 0)) &&
     (puVar8 = *(ushort **)(puVar8 + 10), puVar8 != (ushort *)0x0)) {
    uVar6 = uVar6 + iVar26 * 0x10;
    iVar18 = *(int *)puVar2 + iVar26 * 0x10;
    if ((*(int *)(iVar18 + 4) == *(int *)(uVar6 + 4)) &&
       (*(short *)(iVar18 + 2) == *(short *)(uVar6 + 2))) {
      uVar6 = 0;
      *(undefined1 *)((int)puVar8 + iVar26) = 0;
    }
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar30 = (undefined1 *)((int)in_sp + -4);
  uVar6 = (uVar6 >> 1) * 0x7333 >> 0xf;
  uVar17 = CONCAT44(uVar6,puVar8);
  pcVar22 = (code *)0x110b16;
  puVar31 = (undefined1 *)((int)in_sp + -4);
  if (uVar6 <= *(uint *)(puVar8 + 2)) goto switchD_06065966_default;
  uVar4 = puVar8[1];
  uVar17 = (ulonglong)CONCAT24(uVar4,puVar8);
  uVar6 = op_ext_l_u(uVar4 - 7);
  if ((1 < uVar6) &&
     (((puVar31 = (undefined1 *)((int)in_sp + -4), *(uint *)(puVar8 + 2) == 0 ||
       (puVar31 = (undefined1 *)((int)in_sp + -4), *(float *)(puVar8 + 6) == 0.0)) ||
      (puVar31 = (undefined1 *)((int)in_sp + -4), 0x40 < *puVar8)))) goto switchD_06065966_default;
  puVar31 = (undefined1 *)((int)in_sp + -4);
  switch(uVar4) {
  case 0:
    uVar14 = *(undefined4 *)(puVar8 + 6);
    pcVar23 = (code *)0x6040e64;
    goto code_r0x060659f0;
  case 1:
    uVar14 = *(undefined4 *)(puVar8 + 6);
    pcVar23 = (code *)0x6040ecc;
    goto code_r0x060659f0;
  case 2:
    uVar16 = *(undefined8 *)(puVar8 + 4);
    pcVar23 = (code *)0x6040f34;
    break;
  case 3:
    uVar16 = *(undefined8 *)(puVar8 + 4);
    pcVar23 = (code *)0x6040fce;
    break;
  case 4:
    uVar16 = *(undefined8 *)(puVar8 + 4);
    pcVar23 = (code *)0x60410b6;
    break;
  case 5:
    uVar16 = *(undefined8 *)(puVar8 + 4);
    pcVar23 = (code *)0x60411aa;
    break;
  case 6:
    uVar16 = *(undefined8 *)(puVar8 + 4);
    pcVar23 = (code *)0x6041272;
    break;
  case 7:
    uVar14 = op_ftoi_trunc_rr(*(undefined4 *)(puVar8 + 4));
    pcVar23 = (code *)0x6041332;
    goto code_r0x060659f0;
  case 8:
    uVar14 = op_ftoi_trunc_rr(*(undefined4 *)(puVar8 + 4));
    pcVar23 = FUN_06041594;
code_r0x060659f0:
    uVar16 = CONCAT44(iVar26,uVar14);
    goto code_r0x060659f2;
  default:
    goto switchD_06065966_default;
  }
  *(int *)((int)in_sp + -4) = iVar26;
code_r0x060659f2:
  (*pcVar23)((int)uVar16);
  uVar17 = CONCAT44((int)((ulonglong)uVar16 >> 0x20),FUN_060417d4);
  iVar19 = FUN_060417d4(*(undefined4 *)(iVar26 + 4));
  iVar18 = 0;
  puVar31 = puVar30;
  if (iVar19 != 0) {
switchD_06065966_default:
    iVar18 = (*pcVar22)(iVar26);
    puVar30 = puVar31;
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  piVar32 = (int *)(puVar30 + -0x18);
  iVar21 = iVar18 + 4;
  uVar29 = (uint)*(byte *)(iVar18 + 0x11);
  uVar5 = (uint)*(byte *)(iVar18 + 0x13);
  uVar12 = (uint)*(byte *)(iVar18 + 0xf);
  puVar13 = (undefined4 *)(iVar18 + 0x54);
  uVar20 = (uint)*(byte *)(iVar18 + 7);
  iVar19 = *(int *)(iVar18 + 0x74);
  iVar26 = *(int *)(iVar18 + 0x70);
  *(int *)(puVar30 + -4) = (int)uVar17;
  uVar6 = audio_eq_tab_check(iVar26);
  *(undefined4 *)((int)piVar32 + 0x18) = 0;
  if ((uVar6 & 0xff) == 0) {
    iVar25 = 0;
    iVar27 = 0;
    iVar28 = 0;
code_r0x06065a62:
    *(undefined4 *)((int)piVar32 + 4) = 0;
    *(undefined4 *)((int)piVar32 + 8) = 0;
  }
  else {
    iVar27 = op_uextra_rrii(uVar6,0,8);
    iVar28 = op_uextra_rrii(uVar6,0x10,8);
    iVar25 = op_uextra_rrii(uVar6,8,8);
    if (iVar19 == 0) goto code_r0x06065a62;
    *(int *)((int)piVar32 + 0x18) = iVar28;
    *(int *)((int)piVar32 + 4) = iVar27;
    *(int *)((int)piVar32 + 8) = iVar25;
  }
  iVar19 = uVar5 + uVar29;
  if (puVar13[9] == 0) {
    iVar9 = (iVar19 - uVar12) + uVar20;
    iVar10 = FUN_0010fec0();
    puVar13[9] = iVar10;
    iVar26 = 0;
    if (iVar10 == 0) goto code_r0x06065c2e;
    thunk_FUN_06065868(iVar9);
    iVar26 = puVar13[7];
  }
  *piVar32 = iVar19;
  piVar32[4] = uVar20;
  piVar32[3] = (iVar28 - iVar27) + iVar25;
  if (iVar26 != 0) {
    iVar19 = 0;
    iVar25 = 0;
    for (iVar26 = 0; iVar26 < (int)(uint)*(byte *)(iVar21 + 3); iVar26 = iVar26 + 1) {
      FUN_0010db7c();
      uVar16 = op_lsl_pair_r(iVar26);
      uVar20 = (uint)((ulonglong)*(undefined8 *)(iVar21 + 0x18) >> 0x20);
      uVar5 = (uint)((ulonglong)uVar16 >> 0x20);
      uVar6 = (uint)*(undefined8 *)(iVar21 + 0x18);
      if ((uVar6 & (uint)uVar16) != 0 || (uVar20 & uVar5) != 0) {
        *(ulonglong *)(iVar21 + 0x18) = CONCAT44(uVar20 & ~uVar5,uVar6 & ~(uint)uVar16);
        iVar27 = puVar13[7];
        op_ext_b0_u(iVar19);
        iVar28 = FUN_0606586c(iVar27);
        if (-2 < iVar28) {
          FUN_06065938(iVar27 + iVar25);
        }
        FUN_060658ec(iVar18);
      }
      FUN_0010dbca();
      iVar19 = iVar19 + 1;
      iVar25 = iVar25 + 0x10;
    }
  }
  iVar26 = puVar13[9];
  iVar19 = piVar32[5];
  *(int *)(iVar19 + 4) = iVar26;
  uVar14 = *(undefined4 *)(iVar21 + 0x28);
  *(undefined4 *)(iVar19 + 0xc) = uVar14;
  uVar17 = CONCAT44(iVar19,puVar13[8]);
  iVar25 = piVar32[3] + piVar32[4];
  if (puVar13[8] == 0) {
    *(int *)(iVar19 + 8) = iVar26;
    *(undefined4 *)(iVar19 + 0x10) = uVar14;
  }
  else {
    piVar32[3] = iVar25;
    iVar27 = 0;
    bVar3 = *(byte *)(iVar21 + 0xc);
    uVar6 = (uint)*(byte *)(iVar21 + 3);
    piVar32[4] = (piVar32[6] - piVar32[1]) + piVar32[2] + piVar32[4];
    uVar20 = ((*piVar32 - (uint)bVar3) + uVar6) * 0x14;
    uVar17 = (ulonglong)uVar20;
    iVar26 = iVar26 + uVar20;
    piVar32[6] = iVar26;
    iVar19 = 0;
    for (iVar25 = 0; iVar25 < (int)uVar6; iVar25 = iVar25 + 1) {
      FUN_0010db7c();
      uVar17 = op_lsl_pair_r(iVar25);
      uVar20 = (uint)((ulonglong)*(undefined8 *)(iVar21 + 0x20) >> 0x20);
      uVar5 = (uint)(uVar17 >> 0x20);
      uVar6 = (uint)*(undefined8 *)(iVar21 + 0x20);
      if ((uVar6 & (uint)uVar17) != 0 || (uVar20 & uVar5) != 0) {
        *(ulonglong *)(iVar21 + 0x20) = CONCAT44(uVar20 & ~uVar5,uVar6 & ~(uint)uVar17);
        iVar26 = puVar13[8];
        uVar6 = op_ext_b0_u(iVar19);
        iVar28 = FUN_0606586c(iVar26);
        if (-2 < iVar28) {
          FUN_06065938(iVar26 + iVar27);
        }
        uVar17 = (ulonglong)uVar6;
        FUN_060658ec(iVar18);
      }
      FUN_0010dbca();
      iVar19 = iVar19 + 1;
      iVar27 = iVar27 + 0x10;
      uVar6 = (uint)*(byte *)(iVar21 + 3);
      iVar26 = extraout_r1_00;
    }
    puVar31 = *(undefined1 **)((int)piVar32 + 0x14);
    uVar17 = CONCAT44(puVar31,(int)uVar17);
    *(undefined4 *)(puVar31 + 8) = *(undefined4 *)((int)piVar32 + 0x18);
    *(undefined4 *)(puVar31 + 0x10) = *(undefined4 *)(iVar21 + 0x2c);
    iVar25 = *(int *)((int)piVar32 + 0xc);
    iVar18 = *(int *)((int)piVar32 + 0x10);
    if (iVar18 < iVar25) {
      *puVar31 = (char)iVar18;
      goto code_r0x06065c2e;
    }
    if (iVar25 < iVar18) {
      *puVar31 = (char)iVar25;
      goto code_r0x06065c2e;
    }
  }
  *(undefined1 *)(uVar17 >> 0x20) = (char)iVar25;
  if (puVar13[1] != 0) {
    puVar13[1] = 0;
    *(char *)(iVar21 + 3) = (char)*puVar13;
  }
code_r0x06065c2e:
  iVar19 = iRam00000000;
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar18 = *(int *)((int)piVar32 + 0x30);
  uVar14 = *(undefined4 *)((int)piVar32 + 0x38);
  uVar1 = *(undefined4 *)((int)piVar32 + 0x34);
  if (iVar18 == 2) {
    uVar24 = 2;
  }
  else {
    uVar24 = 1;
  }
  *(undefined1 *)(iRam00000000 + 3) = uVar24;
  *(char *)(iVar19 + 0xb) = (char)iVar26;
  *(char *)(iVar19 + 10) = (char)(uVar17 >> 0x20);
  *(char *)(iVar19 + 9) = (char)uVar17;
  *(char *)(iVar19 + 8) = (char)iVar18;
  *(char *)(iVar19 + 0xc) = (char)uVar1;
  *(char *)(iVar19 + 0xd) = (char)uVar14;
  op_pop_pc_rl();
  if (iVar19 != 0) {
    *(int *)(iVar19 + 0x34) = iVar26;
  }
  return;
}


// ===== DrcCalcTimeFactor @ 0604e496

/* B3 SDK signature: DrcCalcTimeFactor
     source: br28 sdk.elf (AC701N SDK)
     elf addr: 060b24e0
     size: 74 B, words diff: 1/9
     method: byte-exact anchor match (tools/b3_sigs2.py) */

void DrcCalcTimeFactor(int param_1,int param_2,int *param_3,int param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  BADSPACEBASE *in_sp;
  uint *puVar5;
  uint uStack_4;
  
  op_push_rets_rl();
  puVar5 = &uStack_4;
  iVar4 = 0x57e;
  iVar3 = 0x57e;
  if (param_4 != 0) {
    iVar3 = 0xd7e;
  }
  uStack_4 = itof(param_1 * param_2);
  uStack_4 = (iVar3 * 0x447a0000 ^ 0x80000000U) / uStack_4;
  func_0x0010a656(&uStack_4);
  iVar4 = iVar4 - *puVar5;
  *param_3 = iVar4;
  op_pop_pc_rl();
  cVar1 = *(char *)(iVar4 + 8);
  if (*(int *)(iVar4 + 0xa4) == 0) {
    if (cVar1 == '\0') {
      if (*(char *)(iVar4 + 9) == '\0') {
        uVar2 = 0x10af5c;
        goto LAB_0604e54e;
      }
      if (*(char *)(iVar4 + 9) == '\x01') {
        uVar2 = 0x10aff2;
        goto LAB_0604e54e;
      }
    }
    else if ((cVar1 == '\x01') && (*(char *)(iVar4 + 9) == '\x01')) {
      uVar2 = 0x10b086;
      goto LAB_0604e54e;
    }
    uVar2 = 0x10ab46;
    goto LAB_0604e54e;
  }
  if (cVar1 == '\0') {
    if (*(char *)(iVar4 + 9) == '\0') {
      uVar2 = 0x10abde;
      goto LAB_0604e54e;
    }
    if (*(char *)(iVar4 + 9) == '\x01') {
      uVar2 = 0x10ad04;
      goto LAB_0604e54e;
    }
  }
  else if ((cVar1 == '\x01') && (*(char *)(iVar4 + 9) == '\x01')) {
    uVar2 = 0x10ae26;
    goto LAB_0604e54e;
  }
  uVar2 = 0x10aa16;
LAB_0604e54e:
  *(undefined4 *)(iVar4 + 4) = uVar2;
  return;
}


// ===== premute @ 0604dc98

/* B3 SDK signature: premute
     source: br28 sdk.elf (AC701N SDK)
     elf addr: 0608d988
     size: 122 B, words diff: 0/15
     method: byte-exact anchor match (tools/b3_sigs2.py) */

void premute(undefined1 *param_1)

{
  int iVar1;
  BADSPACEBASE *in_sp;
  undefined1 auStack_10 [4];
  undefined1 uStack_c;
  undefined1 uStack_b;
  undefined1 uStack_a;
  undefined1 uStack_9;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  undefined1 uStack_4;
  undefined1 uStack_3;
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  for (iVar1 = 0; iVar1 != 0x10; iVar1 = iVar1 + 1) {
    auStack_10[iVar1] = param_1[iVar1];
  }
  *param_1 = uStack_8;
  param_1[1] = uStack_5;
  param_1[2] = uStack_4;
  param_1[3] = uStack_1;
  param_1[4] = auStack_10[2];
  param_1[5] = auStack_10[1];
  param_1[6] = uStack_a;
  param_1[7] = uStack_b;
  param_1[8] = uStack_6;
  param_1[9] = uStack_7;
  param_1[10] = uStack_2;
  param_1[0xb] = uStack_3;
  param_1[0xc] = auStack_10[0];
  param_1[0xd] = uStack_9;
  param_1[0xe] = uStack_c;
  param_1[0xf] = auStack_10[3];
  return;
}


// ===== audio_cfifo_mix_data @ 0604bea4

/* B3 SDK signature: audio_cfifo_mix_data
     source: br23-sdk.elf
     elf addr: 00006f82
     size: 368 B, words diff: 1/46
     method: byte-exact anchor match (tools/b3_sigs2.py) */

void audio_cfifo_mix_data(ushort *param_1,ushort *param_2,uint param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  ushort *puVar6;
  
  op_pop_pc_rl();
  if (param_4 != 0) {
    uVar2 = param_3 & 0xfffffff8;
    param_2 = (ushort *)op_ext_l_s(param_2);
    puVar5 = param_1;
    for (uVar4 = param_3; 7 < (int)uVar4; uVar4 = uVar4 - 8) {
      uVar1 = sat16((uint)*puVar5 + (int)param_2);
      *puVar5 = (ushort)uVar1;
      uVar1 = sat16((uint)puVar5[1] + (int)param_2);
      puVar5[1] = (ushort)uVar1;
      uVar1 = sat16((uint)puVar5[2] + (int)param_2);
      puVar5[2] = (ushort)uVar1;
      uVar1 = sat16((uint)puVar5[3] + (int)param_2);
      puVar5[3] = (ushort)uVar1;
      uVar1 = sat16((uint)puVar5[4] + (int)param_2);
      puVar5[4] = (ushort)uVar1;
      uVar1 = sat16((uint)puVar5[5] + (int)param_2);
      puVar5[5] = (ushort)uVar1;
      uVar1 = sat16((uint)puVar5[6] + (int)param_2);
      puVar5[6] = (ushort)uVar1;
      uVar1 = sat16((uint)puVar5[7] + (int)param_2);
      puVar5[7] = (ushort)uVar1;
      puVar5 = puVar5 + 8;
    }
    param_3 = param_3 - uVar2;
    param_1 = param_1 + uVar2;
    for (iVar3 = 0; iVar3 < (int)param_3; iVar3 = iVar3 + 1) {
      uVar1 = sat16((uint)param_1[iVar3] + (int)param_2);
      param_1[iVar3] = (ushort)uVar1;
    }
    op_pop_pc_rl();
  }
  uVar2 = param_3 & 0xfffffff8;
  puVar5 = param_2;
  puVar6 = param_1;
  for (uVar4 = param_3; 7 < (int)uVar4; uVar4 = uVar4 - 8) {
    uVar1 = sat16((uint)*puVar5 + (uint)*puVar6);
    *puVar6 = (ushort)uVar1;
    uVar1 = sat16((uint)puVar6[1] + (uint)puVar5[1]);
    puVar6[1] = (ushort)uVar1;
    uVar1 = sat16((uint)puVar6[2] + (uint)puVar5[2]);
    puVar6[2] = (ushort)uVar1;
    uVar1 = sat16((uint)puVar6[3] + (uint)puVar5[3]);
    puVar6[3] = (ushort)uVar1;
    uVar1 = sat16((uint)puVar6[4] + (uint)puVar5[4]);
    puVar6[4] = (ushort)uVar1;
    uVar1 = sat16((uint)puVar6[5] + (uint)puVar5[5]);
    puVar6[5] = (ushort)uVar1;
    uVar1 = sat16((uint)puVar6[6] + (uint)puVar5[6]);
    puVar6[6] = (ushort)uVar1;
    uVar1 = sat16((uint)puVar6[7] + (uint)puVar5[7]);
    puVar6[7] = (ushort)uVar1;
    puVar5 = puVar5 + 8;
    puVar6 = puVar6 + 8;
  }
  for (iVar3 = 0; iVar3 < (int)(param_3 - uVar2); iVar3 = iVar3 + 1) {
    uVar1 = sat16((uint)param_1[uVar2 + iVar3] + (uint)param_2[uVar2 + iVar3]);
    param_1[uVar2 + iVar3] = (ushort)uVar1;
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar3 = 2;
  if ((char)param_1[uVar2 + 0x10] == '\0') {
    iVar3 = 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0010db7e(**(undefined1 **)(param_1 + uVar2 + 10),(int)(param_3 - uVar2) >> iVar3);
}


// ===== eq_db2mag @ 0603c3c6

/* B3 SDK signature: eq_db2mag
     source: br28 sdk.elf (AC701N SDK)
     elf addr: 060addf0
     size: 36 B, words diff: 0/4
     method: byte-exact anchor match (tools/b3_sigs2.py) */

void eq_db2mag(uint param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  BADSPACEBASE *in_sp;
  int *piVar6;
  int iStack_8;
  
  piVar6 = &iStack_8;
  iStack_8 = (param_1 / 0x41a00000) * 0x40135d8e;
  FUN_0603c3ba(&iStack_8);
  iVar3 = *piVar6;
  op_push_rets_rl();
  iVar4 = 0x106060;
  uVar2 = 0x107040;
  iVar5 = 0;
  FUN_0010c29e(0x107040,0);
  uVar1 = 1;
  if (iVar3 == 0) {
    if (iRam00fe051c != 0) {
      *(undefined1 *)(iVar4 + 0xfb0) = 0;
      goto LAB_0603c438;
    }
    iVar5 = op_insert_rrii((uint)*(ushort *)(iVar4 + 0xf12),0x10,0x10);
    uVar1 = 0;
  }
  *(undefined1 *)(iVar4 + 0xfb0) = uVar1;
  iRam00fe051c = iVar5;
LAB_0603c438:
                    /* WARNING: Subroutine does not return */
  FUN_0010c4ac(uVar2);
}


// ===== FUN_0606fb58 @ 0606fb58

void FUN_0606fb58(int param_1)

{
  BADSPACEBASE *in_sp;
  undefined1 auStack_6 [6];
  
  op_push_rets_rl();
  if ((param_1 == 1) && (*pcRam001064c8 == '\x03')) {
    FUN_06003244(auStack_6);
                    /* WARNING: Subroutine does not return */
    f_energymusic(0);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
                    /* WARNING: Subroutine does not return */
  FUN_0010db7e();
}


// ===== FUN_0606fba0 @ 0606fba0

void FUN_0606fba0(void)

{
  op_push_rets_rl();
                    /* WARNING: Subroutine does not return */
  FUN_0010db7e();
}


// ===== FUN_06037cba @ 06037cba

void FUN_06037cba(undefined4 param_1)

{
  undefined2 extraout_r0;
  undefined2 extraout_var;
  undefined4 extraout_r1;
  undefined4 uVar1;
  undefined2 *puVar2;
  int iVar4;
  longlong lVar3;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  BADSPACEBASE *in_sp;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined4 *puVar11;
  undefined1 auStack_84 [128];
  
  puVar9 = auStack_84 + 0x80;
  uVar1 = 0;
  iVar4 = FUN_06037ba4(param_1);
  puVar10 = puVar9 + 4;
  op_push_rets_rl();
  puVar2 = (undefined2 *)(uint)(iVar4 == 0);
  f_jlstream();
  iVar5 = CONCAT22(extraout_var,extraout_r0);
  if (iVar5 != 0) {
    *(undefined2 *)(iVar5 + 0x806) = *puVar2;
    FUN_06037a56(extraout_r0,iVar4,puVar2[1]);
                    /* WARNING: Subroutine does not return */
    FUN_06037b78((short)iVar5);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar11 = (undefined4 *)(puVar10 + -4);
  uVar7 = 0;
  lVar3 = 0;
  uVar6 = extraout_r1;
  FUN_0010ccc6((short)param_1,0);
  uVar8 = 0x605fdef;
  do {
    iVar5 = (int)((ulonglong)lVar3 >> 0x20);
    *puVar11 = uVar1;
    iVar4 = FUN_0010cbc0((short)uVar8,3,uVar7,uVar6);
    if (iVar4 != 0x15) {
      if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0010cbe2((short)param_1,0);
      }
      break;
    }
    FUN_0010c7e4(2);
    lVar3 = (ulonglong)(iVar5 + 1U) << 0x20;
  } while ((int)(iVar5 + 1U) < 10);
  op_pop_pc_rl();
  op_push_rets_rl();
                    /* WARNING: Subroutine does not return */
  FUN_0010feda(0x42c);
}


// ===== FUN_060745c6 @ 060745c6

void FUN_060745c6(void)

{
  FUN_06073ba2(0);
  op_push_rets_rl();
                    /* WARNING: Subroutine does not return */
  FUN_06073b70(0x31);
}


// ===== FUN_0600605e @ 0600605e

void FUN_0600605e(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_0010ea22();
}


// ===== FUN_0600271a @ 0600271a

void FUN_0600271a(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_retaddr;
  BADSPACEBASE *in_sp;
  uint *puVar4;
  uint *puVar5;
  undefined1 auStack_8 [8];
  
  op_push_rets_rl();
  iVar1 = 0;
  iVar2 = 0;
  while (uVar3 = op_ext_b0_u(iVar2), uVar3 < param_2) {
    iVar1 = iVar1 + (uint)*(byte *)(param_1 + uVar3);
    iVar2 = iVar2 + 1;
  }
  op_ext_b0_u(iVar1);
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar4 = (uint *)auStack_8;
  puVar5 = (uint *)auStack_8;
  if ((sRam001060a2 == 0) || (iVar1 = FUN_06073ce6(7), puVar5 = puVar4, iVar1 == 0)) {
    op_pop_pc_rl();
    *(undefined4 *)((int)puVar5 + 4) = unaff_retaddr;
                    /* WARNING: Subroutine does not return */
    FUN_0010ea22();
  }
  puVar4[1] = 0;
  *puVar4 = param_2;
                    /* WARNING: Subroutine does not return */
  FUN_06073fb6(10,4,6);
}


// ===== ? @ 060605e
// no function
