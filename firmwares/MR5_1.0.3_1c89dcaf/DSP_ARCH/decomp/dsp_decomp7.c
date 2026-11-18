// ===== f_eq_media @ 0600b876

/* B2: strings referenced by this function (disasm/function_strings.json):
     "Eq*Media" */

void f_eq_media(int *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *in_r4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  
  op_push_rets_rl();
  iVar2 = *param_1;
  iVar5 = 0x106060;
  switch(iVar2) {
  case 0x72:
                    /* WARNING: Subroutine does not return */
    FUN_060745b6(0x43,0,0);
  case 0x73:
    f_sha_256(uRam00107260,0x107261,uRam0010732c,uRam00107330);
    op_pop_pc_rl();
  case 0x74:
    if (*(short *)(iVar5 + 0x58) != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0602b58c(2000);
    }
LAB_0600ba0c:
                    /* WARNING: Subroutine does not return */
    FUN_0602b702(0,0x600f7b4,2000);
  case 0x75:
                    /* WARNING: Subroutine does not return */
    FUN_06009b22(0);
  case 0x76:
                    /* WARNING: Subroutine does not return */
    FUN_06003050(0x15,0x1068d6,1);
  case 0x79:
    iVar2 = FUN_0600b3c4();
    if (iVar2 != 0) {
      iVar2 = *(byte *)(iVar5 + 0x19) + 1;
      uVar4 = op_ext_b0_u(iVar2);
      *(char *)(iVar5 + 0x19) = (char)iVar2;
      uVar3 = op_ext_b0_u(iVar2);
      FUN_0600b62a(uVar3,uVar4);
      op_pop_pc_rl();
    }
  case 0x77:
  case 0x78:
switchD_0600b888_caseD_77:
    op_pop_pc_rl();
LAB_0600b99a:
    puVar7 = (undefined1 *)(iVar5 + 0x19);
    uVar6 = *(byte *)(iVar5 + 0x1a) ^ 1;
    f_vbass(uVar6);
                    /* WARNING: Subroutine does not return */
    FUN_0600b47e(*puVar7,in_r4,uVar6);
  }
  in_r4 = s_Eq_Media_06061fa4 + 7;
  if (iVar2 == 0x1f) goto LAB_0600b99a;
  if (iVar2 == 0x39) {
    f_music(1);
    op_pop_pc_rl();
  }
  else if (iVar2 != 0x2a) {
    if (iVar2 == 0x31) {
      bVar1 = FUN_0606fbd8();
      *(byte *)(iVar5 + 0x1d) = bVar1 ^ 1;
      FUN_0606ff34(0);
                    /* WARNING: Subroutine does not return */
      f_iis0_rx2(0xa1,*(undefined1 *)(iVar5 + 0x1d));
    }
    if (iVar2 == 0x38) {
      f_music(0);
      op_pop_pc_rl();
      goto LAB_0600ba0c;
    }
    if (iVar2 == 0x29) {
      FUN_0606fe4e();
      iVar2 = FUN_0606fae6(4);
      iVar5 = FUN_0606fd1e();
      if ((iVar2 == iVar5) && (iVar2 = FUN_06002700(), iVar2 == 0)) {
        FUN_06008736(in_r4 + 0x583);
      }
      goto LAB_0600b9cc;
    }
    goto switchD_0600b888_caseD_77;
  }
  FUN_0606feb4();
LAB_0600b9cc:
  uVar3 = FUN_0606fae6(1);
                    /* WARNING: Subroutine does not return */
  f_iis0_rx2(0x96,uVar3);
}


// ===== FUN_0603b492 @ 0603b492

void FUN_0603b492(undefined2 param_1,int param_2)

{
  int in_r4;
  undefined4 in_r6;
  int in_r7;
  int in_r8;
  
  *(undefined2 *)(in_r7 + 0x12) = param_1;
  if (param_2 == 0) {
    FUN_00110f92();
    in_r7 = FUN_0011106a(*(undefined4 *)(in_r8 + 0x18),0);
    if (in_r7 == 0) goto LAB_0603b4ce;
  }
  else {
    param_2 = *(int *)(in_r4 + 0x28) + param_2;
    *(int *)(in_r7 + 0x1c) = param_2;
    *(int *)(in_r4 + 0x28) = param_2;
  }
  FUN_0603b2c8(in_r7,*(undefined4 *)(in_r8 + 0x14));
LAB_0603b4ce:
  op_ldm_post1(0xa0,**(undefined4 **)(in_r8 + 0x14));
                    /* WARNING: Subroutine does not return */
  FUN_0010c4ac(in_r6);
}


