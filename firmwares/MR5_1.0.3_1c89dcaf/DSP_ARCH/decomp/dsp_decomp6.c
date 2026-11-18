// ===== dut_tst_strtbl_get_a @ 060109f0

/* B4.2 rename (expert); evidence: disasm/b42_manifest.json */

undefined4 dut_tst_strtbl_get_a(void)

{
  return 0;
}


// ===== dut_tst_strtbl_get_b @ 06010a06

/* B4.2 rename (expert); evidence: disasm/b42_manifest.json */

undefined4 dut_tst_strtbl_get_b(void)

{
  return 0;
}


// ===== dut_tst_get_resp @ 06013202

/* WARNING: Removing unreachable block (ram,0x0601384a) */
/* WARNING: Removing unreachable block (ram,0x06013852) */
/* B4.2 rename (expert); evidence: disasm/b42_manifest.json */

undefined4 dut_tst_get_resp(int param_1)

{
  op_push_rets_rl();
  if (param_1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0010db7e();
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  op_pop_pc_rl();
  return uRam00104b7c;
}


// ===== dut_tst_get_send @ 06014348

/* B4.2 rename (expert); evidence: disasm/b42_manifest.json */

void dut_tst_get_send(int param_1)

{
  int iVar1;
  int in_r4;
  int *piVar2;
  BADSPACEBASE *in_sp;
  undefined1 auStack_8 [8];
  
  op_push_rets_rl();
  iVar1 = *(int *)(param_1 + 0x14);
  piVar2 = (int *)(iVar1 + 0x34);
  if (*(char *)(iVar1 + 0x40) == '\0') {
    *(undefined1 *)(iVar1 + 0x41) = 0;
    op_pop_pc_rl();
    *(undefined1 *)(in_r4 + 1) = 0;
                    /* WARNING: Subroutine does not return */
    FUN_0010dbcc();
  }
  iVar1 = FUN_06014236(auStack_8);
  if (iVar1 != 0) {
    FUN_060142f6((char)piVar2[3]);
  }
  if (*piVar2 != 0) {
    FUN_060142f6((char)piVar2[3]);
    *piVar2 = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0010db7e();
}


// ===== dut_tst_cluster @ 0600ac08

/* B2 anchor (findings/B2_anchors.md): subsystem named by string anchors; see string_xrefs.md for
   the evidence chain. Former name: sub_0600ac08 */

void dut_tst_cluster(void)

{
  BADSPACEBASE *in_sp;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 uStack_10;
  undefined4 uStack_c;
  
  op_push_rets_rl();
  uRam001061d4 = 1;
  rep_unspec(4,7);
  uStack_1c = 0;
  uStack_24 = 8;
  uStack_20 = 0;
  uStack_10 = 10;
  uStack_c = 0x3dcccccd;
                    /* WARNING: Subroutine does not return */
  FUN_06038bd8(0x737b,0x104b94,&uStack_24,0x24);
}


// ===== dut_tst_cluster_2 @ 0600d698

/* B2 anchor (findings/B2_anchors.md): subsystem named by string anchors; see string_xrefs.md for
   the evidence chain. Former name: sub_0600d698 */

void dut_tst_cluster_2(void)

{
  code *pcVar1;
  undefined4 *in_r4;
  undefined4 *in_r5;
  
  while (in_r4 < in_r5) {
    pcVar1 = (code *)*in_r4;
    in_r4 = in_r4 + 1;
    (*pcVar1)(pcVar1);
  }
  op_pop_pc_rl();
  return;
}


// ===== dut_tst_cluster_4 @ 06017c92

/* B2 anchor (findings/B2_anchors.md): subsystem named by string anchors; see string_xrefs.md for
   the evidence chain. Former name: sub_06017c92
   B2: strings referenced by this function (disasm/function_strings.json):
     "@333?\2"
     "flash/res/cfg_tool.bin" */

int dut_tst_cluster_4(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  BADSPACEBASE *in_sp;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined1 auStack_84 [128];
  
  op_push_rets_rl();
  if ((param_3 != 0) && (*(int *)(param_1 + 0x24) != 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_0600325e(param_2,param_3);
  }
  op_pop_pc_rl();
  puVar6 = auStack_84 + 0x80;
  uVar8 = FUN_06003278(uRam00000024);
  op_push_rets_rl();
  puVar7 = (undefined4 *)(puVar6 + -0x24);
  puVar4 = puVar6 + -0xc;
  FUN_06017c80(*(undefined4 *)((int)((ulonglong)uVar8 >> 0x20) + 0x24),puVar4);
  *puVar7 = (int)((ulonglong)uVar8 >> 0x20);
  puVar7[1] = puVar4;
  puVar7[2] = s_flash_res_cfg_tool_bin_060627be + 0x16;
  iVar5 = 0;
  puVar7[3] = 0;
  puVar7[4] = 0;
  puVar7[5] = 0;
  iVar1 = FUN_0603923c(puVar7,(int)uVar8);
  iVar2 = (int)((ulonglong)uVar8 >> 0x20);
  iVar3 = (int)uVar8;
  if (iVar1 == 0) {
    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar3 + 0x14);
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar3 + 0x10);
    *(undefined1 *)(iVar2 + 0xb) = *(undefined1 *)(iVar3 + 4);
  }
  else {
    *(int *)(iVar2 + 0x18) = iVar1;
    iVar5 = iVar1;
  }
  op_pop_pc_rl();
  return iVar5;
}


// ===== dut_tst_cluster_3 @ 0602b98c

/* B2 anchor (findings/B2_anchors.md): subsystem named by string anchors; see string_xrefs.md for
   the evidence chain. Former name: sub_0602b98c */

void dut_tst_cluster_3(void)

{
  byte bVar1;
  byte bVar2;
  uint *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint *puVar6;
  int in_r6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  BADSPACEBASE *in_sp;
  undefined1 *puVar11;
  undefined1 auStack_4 [4];
  
  op_push_rets_rl();
  puVar11 = auStack_4;
  iVar10 = 0x106060;
  uRam0010643c = 0x10643c;
  uRam00106440 = 0x10643c;
  uRam00106444 = 0x106444;
  uRam00106448 = 0x106444;
  puVar3 = (uint *)FUN_0010fec2(0x10);
  *(uint **)(iVar10 + 0x1d0) = puVar3;
  *puVar3 = 0xf7a;
  uVar9 = 0xffffffff;
  puVar3[1] = 0x6019588;
  puVar3[2] = 0xffffffff;
  *(undefined2 *)(puVar3 + 3) = 1;
  puVar6 = (uint *)0xfd0400;
  for (uVar7 = 0; uVar7 < 6; uVar7 = uVar7 + 1) {
    in_r6 = iVar10 + 0x488;
    if ((*(int *)(in_r6 + uVar7 * 4) == 0) && ((*puVar6 & 3) == 0)) goto LAB_0602b9f8;
    puVar6 = puVar6 + 0x40;
  }
  do {
    *(undefined4 *)(iVar10 + 0x1c8) = uVar9;
    puVar11 = puVar11 + 4;
    op_pop_pc_rl();
LAB_0602b9f8:
    puVar4 = (undefined4 *)FUN_0010fec2(0x48);
    *(undefined4 **)(in_r6 + uVar7 * 4) = puVar4;
    rep_unspec(2,0x11);
    *puVar4 = 0;
    puVar4[0x11] = puVar6;
    *puVar4 = 0;
    puVar6 = (uint *)0x1;
    if ((uint *)*puVar3 != (uint *)0x0) {
      puVar6 = (uint *)*puVar3;
    }
    puVar4[1] = puVar6;
    *(short *)(puVar4 + 4) = (short)puVar3[3];
    uVar8 = puVar3[1];
    puVar4[2] = uVar8;
    puVar3 = (uint *)puVar4[0x11];
    iVar5 = FUN_0600023e(puVar11 + 3,puVar11 + 2,puVar6);
    uVar9 = 0xff;
  } while (iVar5 != 0);
  FUN_0010dd54();
  *puVar3 = 0xc80;
  puVar3[1] = 0;
  bVar1 = puVar11[3];
  bVar2 = puVar11[2];
  puVar3[2] = (uint)((int)puVar6 * *(int *)((uint)bVar1 * 4 + 0x6062a2c)) /
              *(uint *)((uint)bVar2 * 4 + 0x6062a6c) - 1;
  *puVar3 = *puVar3 | (bVar1 & 0xf0) << 10;
  uVar7 = op_ext_b0_u((uint)bVar2 << 4);
  *puVar3 = *puVar3 | uVar7;
  *(uint *)(iVar10 + 0x4a0 + ((uint)((int)(puVar3 + -0x3f4100) >> 4) / 0x10) * 4) = uVar8;
                    /* WARNING: Subroutine does not return */
  FUN_0010dd86();
}


// ===== ? @ 0600f560
// no function
