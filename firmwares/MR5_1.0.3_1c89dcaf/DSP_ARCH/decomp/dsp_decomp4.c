// ===== dut_tst_cmd_handler @ 0600ba7c

/* B4.2 rename (expert); evidence: disasm/b42_manifest.json */

void dut_tst_cmd_handler(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined1 uVar8;
  char *in_r4;
  BADSPACEBASE *in_sp;
  undefined1 *puVar9;
  undefined1 auStack_34 [52];
  
  op_push_rets_rl();
  puVar9 = auStack_34;
  iVar2 = FUN_060010c0(3);
  if (iVar2 == 0) goto LAB_0600c26e;
  cVar1 = *param_1;
  iVar2 = 0x106060;
  in_r4 = s_tone_zh_bt_conn___0606251e + 0x10;
  switch(cVar1) {
  case 'w':
    uRam001068e2 = 0;
    uRam001068e1 = 0;
    uRam001060ae = 0;
                    /* WARNING: Subroutine does not return */
    FUN_060745b6(0x44,0);
  case 'x':
    iVar2 = FUN_060010de();
    if (iVar2 != 0) {
LAB_0600bf56:
                    /* WARNING: Subroutine does not return */
      f_iis0_rx2();
    }
    break;
  case 'y':
  case 'z':
  case '{':
  case '|':
  case -0x74:
  case -0x73:
  case -0x72:
  case -0x71:
  case -0x70:
  case -0x6f:
  case -0x6e:
  case -0x6d:
  case -0x6c:
  case -0x6b:
  case -0x6a:
  case -0x69:
  case -0x68:
  case -0x67:
  case -0x66:
  case -0x65:
  case -100:
  case -99:
  case -0x62:
  case -0x61:
  case -0x60:
  case -0x5f:
  case -0x5e:
LAB_0600bdd6:
    f_eq_media(param_1);
    break;
  case '}':
    if (((bRam00106100 == 0) && (cRam001068ab == '\0')) && (199 < iRam0010613c)) {
      cRam001068d6 = cRam001068d6 == '\0';
      if (cRam001068d5 == '\0') {
        f_trebshelf_lb4(uRam001068db,1);
      }
      else {
        f_jlstream(1);
      }
      *(undefined2 *)(iVar2 + 0x4c) = 0;
      if (*(int *)(iVar2 + 0x10c) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0602b702(0,800);
      }
      uVar7 = op_ext_l_u(*(int *)(iVar2 + 0x10c));
                    /* WARNING: Subroutine does not return */
      FUN_0602b58c(uVar7);
    }
    break;
  case '~':
    if (bRam00106100 == 0) {
      uRam001060ac = 0;
      iVar3 = FUN_060745c6();
      uVar4 = op_ext_b0_u(iVar3 + -0x33);
      if (2 < uVar4) {
        if (*(char *)(iVar2 + 0x880) != '\0' ||
            (*(char *)(iVar2 + 0x881) != '\0' || *(char *)(iVar2 + 0x882) != '\0')) {
          *(undefined1 *)(iVar2 + 0x882) = 0;
          *(undefined2 *)(iVar2 + 0x880) = 0;
          FUN_0600ab60();
                    /* WARNING: Subroutine does not return */
          FUN_060745b6(0xe,0);
        }
        *(undefined1 *)(iVar2 + 0x882) = 0;
        *(undefined1 *)(iVar2 + 0x881) = 0;
        *(undefined1 *)(iVar2 + 0x880) = 0;
        *(undefined2 *)(iVar2 + 0x4e) = 0;
      }
    }
    break;
  case '\x7f':
    if (bRam00106100 == 0) {
      uRam001060ac = 0;
      iVar3 = FUN_060745c6();
      if ((iVar3 == 0x35) || (iVar3 == 0x33)) {
                    /* WARNING: Subroutine does not return */
        FUN_060745b6(4,0);
      }
      in_r4 = (char *)0x881;
      if (*(char *)(iVar2 + 0x881) != '\0' || *(char *)(iVar2 + 0x882) != '\0') {
        *(undefined1 *)(iVar2 + 0x881) = 0;
        *(undefined1 *)(iVar2 + 0x882) = 0;
                    /* WARNING: Subroutine does not return */
        FUN_060745b6(0xe,0);
      }
      *(undefined1 *)(iVar2 + 0x882) = 0;
      *(undefined1 *)(iVar2 + 0x881) = 0;
      *(undefined2 *)(iVar2 + 0x4e) = 0;
    }
    break;
  case -0x80:
    if ((cRam001068ab == '\0') && (((bRam00106100 ^ 1) & 1) != 0)) {
      if (sRam0010689e == 0) {
        if (cRam00106375 == '\x01') {
          cRam00106375 = 0;
          uVar8 = 3;
        }
        else {
          cRam00106375 = 1;
          uVar8 = 4;
          if (cRam001068e4 != '\0') {
                    /* WARNING: Subroutine does not return */
            f_iis0_rx2(0x8b);
          }
        }
        uRam001060ac = 0;
        uRam00106073 = uVar8;
                    /* WARNING: Subroutine does not return */
        FUN_06003050(0xd,1);
      }
      if (sRam0010689e == 0x1e) goto LAB_0600bf56;
    }
    break;
  case -0x7f:
    if (bRam00106100 == 0) {
      uRam001060ac = 0;
      FUN_06001812(1);
      f_mixer7();
      f_mixer7();
      FUN_0600b1fe();
      in_r4 = (char *)(iVar2 + 0x875);
      f_aux_dac_gain(*in_r4);
      f_ext_reserved(*(undefined1 *)(iVar2 + 0xf),in_r4[1]);
      FUN_06002af6();
    }
    break;
  case -0x7e:
    if (bRam00106100 == 0) {
      f_ext_reserved(uRam0010606f,cRam001068d6);
    }
    break;
  case -0x7d:
    if (bRam00106100 == 0) {
                    /* WARNING: Subroutine does not return */
      f_trebshelf_lb3(uRam0010606e);
    }
    break;
  case -0x7c:
    if (bRam00106100 == 0) {
      FUN_06001ab6(sRam0010689e,uRam001068d7);
    }
    break;
  case -0x7b:
    break;
  case -0x7a:
    f_sha_256(6);
    break;
  case -0x79:
    f_sha_256(5);
    break;
  case -0x78:
    uRam001068e1 = 1;
                    /* WARNING: Subroutine does not return */
    FUN_060745b6(0xd,0);
  case -0x77:
    if (cRam001068d6 == '\x02') {
      dut_tst_cluster();
    }
    else {
      FUN_0600ae56();
    }
    f_trebshelf_lb4(*(undefined1 *)(iVar2 + 0x87b),0);
    f_jlstream(0);
                    /* WARNING: Subroutine does not return */
    f_trebshelf_lb3(*(undefined1 *)(iVar2 + 0xe));
  case -0x76:
    cRam001068e4 = '\x01';
    FUN_060049d4();
    *(undefined2 *)(iVar2 + 0x4c) = 0;
    break;
  case -0x75:
    cRam001068e4 = '\0';
    uRam001060ac = 0;
    if (cRam001068af == '\0') {
                    /* WARNING: Subroutine does not return */
      f_iis0_rx2();
    }
    FUN_0600a086(0x6062668);
    mcu_msg_send();
    FUN_06001812(1);
    break;
  case -0x5d:
                    /* WARNING: Subroutine does not return */
    FUN_06074ce4(0x106352,0);
  default:
    switch(cVar1) {
    case '\"':
code_r0x0600c262:
      uVar7 = 0x27;
      goto LAB_0600c264;
    case '#':
      iVar3 = FUN_06073c30();
      if ((1 < iVar3 - 3U) && (iVar3 != 6)) {
        if (iVar3 == 2) goto code_r0x0600c262;
        if (*(char *)(iVar2 + 0x9f0) == '\v') {
          iVar2 = iVar2 + 0x9f1;
          uVar7 = 0x2b;
          goto code_r0x0600c268;
        }
        uVar7 = 0x28;
        goto LAB_0600c264;
      }
      break;
    case '$':
      uVar7 = 0x33;
      goto LAB_0600c264;
    case '%':
      uVar7 = 0x34;
      goto LAB_0600c264;
    case '&':
      iVar2 = FUN_06073c30();
      if (iVar2 == 4) {
        uVar7 = 7;
        goto LAB_0600c264;
      }
      break;
    case '\'':
      uVar4 = FUN_06074cec();
      if ((uVar4 & 0x10) != 0) {
        uVar7 = 0x73;
        goto LAB_0600c264;
      }
      break;
    case '(':
      uVar7 = 0x2d;
      goto LAB_0600c264;
    case ')':
      uRam00106073 = 1;
      puVar9[2] = 0x41;
      iVar3 = FUN_06073c30();
      iVar5 = FUN_06002700();
      if ((iVar5 == 0) && (iVar5 = FUN_06017b40(), iVar5 == 0)) {
        op_ext_b0_u(iVar3 + -3);
        uVar7 = FUN_0606fae6(1);
        uVar7 = op_ext_l_u(uVar7);
        iVar3 = FUN_06074cd4();
        if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_060745b6(0x105,puVar9 + 2);
        }
        iVar5 = op_ext_b0_s(uVar7);
        iVar3 = FUN_0606fd1e();
        if (iVar5 < iVar3) {
          iVar2 = FUN_0606fd40();
          if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
            f_energymusic(0);
          }
          FUN_0606fe4e();
          iVar2 = FUN_06073c30();
          if (iVar2 != 5) {
LAB_0600c406:
                    /* WARNING: Subroutine does not return */
            FUN_060745b6(0x22,0);
          }
        }
        else {
          f_iis0_rx2(0);
          FUN_06008736(in_r4);
          iVar3 = FUN_06073c30();
          if ((iVar3 != 5) && (*(byte *)(iVar2 + 0x9ec) < 0xf)) goto LAB_0600c406;
        }
      }
      iVar2 = FUN_06073c30();
      op_ext_b0_u(iVar2 + -3);
      uVar7 = FUN_0606fae6(1);
      op_ext_b0_u(uVar7);
                    /* WARNING: Subroutine does not return */
      f_iis0_rx2(0x96);
    case '*':
      uRam00106073 = 1;
      puVar9[3] = 0x42;
      iVar3 = FUN_06002700();
      if ((iVar3 == 0) && (iVar3 = FUN_06017b40(), iVar3 == 0)) {
        iVar3 = FUN_06074cd4();
        if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
          FUN_060745b6(0x105,puVar9 + 3);
        }
        iVar3 = FUN_0606fae6(4);
        if (iVar3 < 1) {
          f_iis0_rx2(1);
          iVar3 = FUN_06073c30();
          if ((iVar3 != 5) && (1 < *(byte *)(iVar2 + 0x9ec))) goto LAB_0600c46e;
        }
        else {
          iVar2 = FUN_0606fd40();
          if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
            f_energymusic(0);
          }
          FUN_0606feb4();
          iVar2 = FUN_06073c30();
          if (iVar2 != 5) {
LAB_0600c46e:
                    /* WARNING: Subroutine does not return */
            FUN_060745b6(0x23,0);
          }
        }
      }
      iVar2 = FUN_06073c30();
      op_ext_b0_u(iVar2 + -3);
      uVar7 = FUN_0606fae6(1);
      op_ext_b0_u(uVar7);
                    /* WARNING: Subroutine does not return */
      f_iis0_rx2(0x96);
    case '+':
    case ',':
    case '/':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
      goto LAB_0600bdd6;
    case '-':
      iVar2 = FUN_0600b2f0();
      iVar3 = FUN_0607430a();
      if ((iVar3 != 0) && (iVar3 = FUN_060010c0(3), iVar3 != 0)) {
        pcVar6 = in_r4 + 0x12;
        if (iVar2 != 0) {
          pcVar6 = in_r4 + 0x160;
        }
        FUN_0600b2fa(pcVar6);
        uRam00106042 = iVar2 == 0;
                    /* WARNING: Subroutine does not return */
        FUN_0010db7e();
      }
      break;
    case '.':
      if (iRam001061f0 == 0) {
        f_mixer7();
      }
      else {
        f_mixer7();
      }
      break;
    case '5':
    case '6':
      break;
    default:
      if (cVar1 == '\t') {
        uVar7 = FUN_06073c30();
        switch(uVar7) {
        case 2:
          uVar7 = 0x26;
          break;
        case 3:
        case 4:
        case 6:
          goto code_r0x0600c262;
        default:
          uVar7 = 0x42;
        }
      }
      else if (cVar1 == '\n') {
        uVar7 = 0x46;
      }
      else {
        if (cVar1 != '\v') {
          if (cVar1 == 'G') {
            in_r4 = param_1 + 4;
            iVar2 = FUN_0600b30c(in_r4);
            if (iVar2 != 0) {
              FUN_06074d04();
              iVar3 = FUN_0600b350();
              if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
                thunk_FUN_06074ce4(iVar2);
              }
            }
            goto LAB_0600c272;
          }
          goto LAB_0600bdd6;
        }
        iVar2 = FUN_06073c30();
        if (iVar2 == 2) goto code_r0x0600c262;
        uVar7 = 0x45;
      }
LAB_0600c264:
      iVar2 = 0;
code_r0x0600c268:
                    /* WARNING: Subroutine does not return */
      FUN_060745b6(uVar7,iVar2);
    }
  }
LAB_0600c26e:
  op_pop_pc_rl();
LAB_0600c272:
  FUN_06074d4a(in_r4);
                    /* WARNING: Subroutine does not return */
  f_energymusic(0);
}


// ===== FUN_0600b47e @ 0600b47e

void FUN_0600b47e(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  uint uVar9;
  undefined1 *puVar10;
  BADSPACEBASE *in_sp;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined8 uVar16;
  undefined1 auStack_2c [36];
  undefined8 uStack_8;
  
  op_push_rets_rl();
  puVar11 = auStack_2c;
  uStack_8 = 0;
  uVar2 = op_ext_b0_s(param_1);
  uVar5 = op_ext_b0_s(param_2);
  uVar16 = FUN_06037ba4(uVar2,uVar5,&uStack_8);
  iVar3 = (int)((ulonglong)uVar16 >> 0x20);
  uVar2 = (undefined4)uVar16;
  if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0010feda(*(undefined2 *)(puVar11 + 0x26));
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar12 = puVar11 + -0x20;
  rep_unspec(2,0x13);
  *(undefined4 *)(puVar11 + -0x20) = 0;
  uVar5 = op_ext_b0_s(iVar3);
  uVar16 = FUN_06038d42(uVar5,uVar2,0);
  uVar5 = (undefined4)uVar16;
  if ((int)((ulonglong)uVar16 >> 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_06038bd8(0xdefe,uVar2,puVar12,0x4c);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  puVar13 = puVar12 + 0x1c;
  rep_unspec(2,0xc);
  *(undefined4 *)(puVar12 + 0x1c) = 0;
  uVar2 = op_ext_b0_s(0);
  uVar6 = 0;
  uVar16 = FUN_06038d42(uVar2,uVar5,0);
  uVar2 = (undefined4)uVar16;
  if ((int)((ulonglong)uVar16 >> 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_06038bd8(0xb0d5,uVar5,puVar13,0x30);
  }
  op_pop_pc_rl();
  op_push_rets_rmask(0xd0);
  puVar14 = puVar13 + 0x24;
  uVar5 = op_ext_b0_s_p(0);
  *(undefined4 *)(puVar13 + 0x2c) = 0;
  *(undefined8 *)(puVar13 + 0x24) = 0;
  uVar6 = op_ext_b0_s(uVar6);
  uVar16 = FUN_06038d42(uVar5,uVar2,uVar6,puVar13 + 0x24);
  if ((int)((ulonglong)uVar16 >> 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_06038bd8(0xa904,uVar2,puVar14,0xc);
  }
  op_pop_pc_rmask(0xd0);
  op_push_rets_rl();
  puVar15 = puVar14 + -0x100;
  puVar10 = puVar14 + -0x100;
  func_0x0001fd82(puVar14 + -0x100,0,0x10c);
  pcVar7 = (char *)uVar16;
  uVar2 = op_ext_b0_s((int)((ulonglong)uVar16 >> 0x20));
  iVar3 = FUN_06038d42(uVar2,pcVar7,0,puVar10);
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_06038bd8(0x87a0,pcVar7,puVar15,0x10c);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  piVar4 = (int *)FUN_0600b3c4();
  if (iVar3 < (int)piVar4) {
    uRam00106079 = (undefined1)iVar3;
                    /* WARNING: Subroutine does not return */
    FUN_06003050(4,0x106079,1);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar3 = *piVar4;
  iVar8 = 0x106060;
  switch(iVar3) {
  case 0x72:
                    /* WARNING: Subroutine does not return */
    FUN_060745b6(0x43,0,0);
  case 0x73:
    f_sha_256(uRam00107260,0x107261,uRam0010732c,uRam00107330);
    op_pop_pc_rl();
  case 0x74:
    if (*(short *)(iVar8 + 0x58) != 0) {
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
    iVar3 = FUN_0600b3c4();
    if (iVar3 != 0) {
      iVar3 = *(byte *)(iVar8 + 0x19) + 1;
      uVar5 = op_ext_b0_u(iVar3);
      *(char *)(iVar8 + 0x19) = (char)iVar3;
      uVar2 = op_ext_b0_u(iVar3);
      FUN_0600b62a(uVar2,uVar5);
      op_pop_pc_rl();
    }
  case 0x77:
  case 0x78:
switchD_0600b888_caseD_77:
    op_pop_pc_rl();
LAB_0600b99a:
    puVar10 = (undefined1 *)(iVar8 + 0x19);
    uVar9 = *(byte *)(iVar8 + 0x1a) ^ 1;
    f_vbass(uVar9);
                    /* WARNING: Subroutine does not return */
    FUN_0600b47e(*puVar10,pcVar7,uVar9);
  }
  pcVar7 = s_Eq_Media_06061fa4 + 7;
  if (iVar3 == 0x1f) goto LAB_0600b99a;
  if (iVar3 == 0x39) {
    f_music(1);
    op_pop_pc_rl();
  }
  else if (iVar3 != 0x2a) {
    if (iVar3 == 0x31) {
      bVar1 = FUN_0606fbd8();
      *(byte *)(iVar8 + 0x1d) = bVar1 ^ 1;
      FUN_0606ff34(0);
                    /* WARNING: Subroutine does not return */
      f_iis0_rx2(0xa1,*(undefined1 *)(iVar8 + 0x1d));
    }
    if (iVar3 == 0x38) {
      f_music(0);
      op_pop_pc_rl();
      goto LAB_0600ba0c;
    }
    if (iVar3 == 0x29) {
      FUN_0606fe4e();
      iVar3 = FUN_0606fae6(4);
      iVar8 = FUN_0606fd1e();
      if ((iVar3 == iVar8) && (iVar3 = FUN_06002700(), iVar3 == 0)) {
        FUN_06008736(pcVar7 + 0x583);
      }
      goto LAB_0600b9cc;
    }
    goto switchD_0600b888_caseD_77;
  }
  FUN_0606feb4();
LAB_0600b9cc:
  uVar2 = FUN_0606fae6(1);
                    /* WARNING: Subroutine does not return */
  f_iis0_rx2(0x96,uVar2);
}


// ===== FUN_0600b5ae @ 0600b5ae

void FUN_0600b5ae(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  undefined1 *puVar9;
  BADSPACEBASE *in_sp;
  undefined8 *puVar10;
  undefined1 *puVar11;
  undefined8 uVar12;
  undefined8 uStack_c;
  undefined4 uStack_4;
  
  op_push_rets_rmask(0xd0);
  puVar10 = &uStack_c;
  uVar2 = op_ext_b0_s_p(param_1);
  uStack_4 = 0;
  uStack_c = 0;
  uVar5 = op_ext_b0_s(param_3);
  uVar12 = FUN_06038d42(uVar2,param_2,uVar5,&uStack_c);
  if ((int)((ulonglong)uVar12 >> 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_06038bd8(0xa904,param_2,puVar10,0xc);
  }
  op_pop_pc_rmask(0xd0);
  op_push_rets_rl();
  puVar11 = (undefined1 *)((int)puVar10 + -0x100);
  puVar9 = (undefined1 *)((int)puVar10 + -0x100);
  func_0x0001fd82((undefined1 *)((int)puVar10 + -0x100),0,0x10c);
  pcVar6 = (char *)uVar12;
  uVar2 = op_ext_b0_s((int)((ulonglong)uVar12 >> 0x20));
  iVar3 = FUN_06038d42(uVar2,pcVar6,0,puVar9);
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_06038bd8(0x87a0,pcVar6,puVar11,0x10c);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  piVar4 = (int *)FUN_0600b3c4();
  if (iVar3 < (int)piVar4) {
    uRam00106079 = (undefined1)iVar3;
                    /* WARNING: Subroutine does not return */
    FUN_06003050(4,0x106079,1);
  }
  op_pop_pc_rl();
  op_push_rets_rl();
  iVar3 = *piVar4;
  iVar7 = 0x106060;
  switch(iVar3) {
  case 0x72:
                    /* WARNING: Subroutine does not return */
    FUN_060745b6(0x43,0,0);
  case 0x73:
    f_sha_256(uRam00107260,0x107261,uRam0010732c,uRam00107330);
    op_pop_pc_rl();
  case 0x74:
    if (*(short *)(iVar7 + 0x58) != 0) {
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
    iVar3 = FUN_0600b3c4();
    if (iVar3 != 0) {
      iVar3 = *(byte *)(iVar7 + 0x19) + 1;
      uVar5 = op_ext_b0_u(iVar3);
      *(char *)(iVar7 + 0x19) = (char)iVar3;
      uVar2 = op_ext_b0_u(iVar3);
      FUN_0600b62a(uVar2,uVar5);
      op_pop_pc_rl();
    }
  case 0x77:
  case 0x78:
switchD_0600b888_caseD_77:
    op_pop_pc_rl();
LAB_0600b99a:
    puVar9 = (undefined1 *)(iVar7 + 0x19);
    uVar8 = *(byte *)(iVar7 + 0x1a) ^ 1;
    f_vbass(uVar8);
                    /* WARNING: Subroutine does not return */
    FUN_0600b47e(*puVar9,pcVar6,uVar8);
  }
  pcVar6 = s_Eq_Media_06061fa4 + 7;
  if (iVar3 == 0x1f) goto LAB_0600b99a;
  if (iVar3 == 0x39) {
    f_music(1);
    op_pop_pc_rl();
  }
  else if (iVar3 != 0x2a) {
    if (iVar3 == 0x31) {
      bVar1 = FUN_0606fbd8();
      *(byte *)(iVar7 + 0x1d) = bVar1 ^ 1;
      FUN_0606ff34(0);
                    /* WARNING: Subroutine does not return */
      f_iis0_rx2(0xa1,*(undefined1 *)(iVar7 + 0x1d));
    }
    if (iVar3 == 0x38) {
      f_music(0);
      op_pop_pc_rl();
      goto LAB_0600ba0c;
    }
    if (iVar3 == 0x29) {
      FUN_0606fe4e();
      iVar3 = FUN_0606fae6(4);
      iVar7 = FUN_0606fd1e();
      if ((iVar3 == iVar7) && (iVar3 = FUN_06002700(), iVar3 == 0)) {
        FUN_06008736(pcVar6 + 0x583);
      }
      goto LAB_0600b9cc;
    }
    goto switchD_0600b888_caseD_77;
  }
  FUN_0606feb4();
LAB_0600b9cc:
  uVar2 = FUN_0606fae6(1);
                    /* WARNING: Subroutine does not return */
  f_iis0_rx2(0x96,uVar2);
}


// ===== ? @ 0600745c6
// no function
// ===== FUN_0602eee8 @ 0602eee8

void FUN_0602eee8(undefined1 *param_1)

{
  int iVar1;
  
  rep_unspec(4,6);
  uRam00104f3b = *param_1;
  for (iVar1 = 0; iVar1 != 6; iVar1 = iVar1 + 1) {
    cRam00104f3a = *(char *)(iVar1 + 0x104f3b) + cRam00104f3a;
  }
  return;
}


// ===== FUN_06038bc0 @ 06038bc0

void FUN_06038bc0(int param_1,undefined2 param_2)

{
  op_push_rets_rl();
  *(undefined2 *)(param_1 + 0x38) = param_2;
                    /* WARNING: Subroutine does not return */
  FUN_06037d02(4,param_1,0,param_1 + 0x40);
}


// ===== FUN_060380ae @ 060380ae

void FUN_060380ae(int param_1)

{
  op_push_rets_rl();
                    /* WARNING: Subroutine does not return */
  FUN_0010ea22(*(undefined4 *)(param_1 + 0x20));
}


