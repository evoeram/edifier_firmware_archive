#!/usr/bin/env python3
"""F3/F4 (plan NEW2): apply expert-identified names.

Writes disasm/b5_names.json ({flash_va: {name, ...}} in B3Apply format),
updates b3_far_targets.json names, prints summary.
"""
import io
import json

SRC = r'C:\dev\edifier_firmware_archive\firmwares\MR5_1.0.3_1c89dcaf\source'
XIP = 0x06000100

# (flash VA, name, confidence, evidence)
NAMES = [
    # --- uCOS-II mutex/sem (OS_EVENT_TYPE: 2=sem, 3=mutex per ucos_ii.h) ---
    ('06087398', 'os_mutex_post', 'high',
     'OSEventType==3 (mutex); restores owner prio (prio inheritance), '
     'readies highest waiter via OS_EventHighestTask'),
    ('0608718a', 'os_mutex_pend', 'high',
     'OSEventType==3; timeout==-1 infinite wait; raises task prio '
     '(inheritance); loops on sched state'),
    ('06086daa', 'os_mutex_create', 'high',
     'writes OSEventType=3, cnt=1, owner=0xff into 16-B event block'),
    ('06087ace', 'os_sem_pend', 'high',
     'OSEventType==2 (sem); timeout==-1 loop; decrements OSEventCnt(+0xc)'),
    ('06087a88', 'os_sem_post', 'high',
     'rejects type!=2; sched; increments/flags OSEventCnt'),
    ('06087740', 'os_sem_del_core', 'med',
     'type==2; OS_EventHighestTask + wait-list unlink; flush path'),
    ('060878c8', 'os_sem_del', 'med', 'tail-call wrapper of 06087740'),
    # --- task/sched core ---
    ('060874c8', 'os_taskq_post_core', 'med-high',
     'OSGetTaskTcb(name); queue insert; sched request; sched-lock check'),
    ('060875c2', 'os_taskq_post', 'med',
     'wrapper: os_taskq_post_core + set per-task sched flag 0x1083e4[cnum]'),
    ('060876d0', 'os_time_dly', 'med',
     'rejects in-irq/critical context; tail into tick-wait 06087656'),
    ('06086dd0', 'os_task_unready', 'high',
     'unlinks TCB from ready list 0x108228[prio*8], clears bitmap 0x108210'),
    ('06086eda', 'os_task_ready', 'high',
     'inserts TCB into ready list 0x108228[prio*8], sets bitmap bit'),
    ('0608732c', 'os_event_task_unlink', 'high',
     'unlinks node from event wait list (+0x18/+0x1c double-linked)'),
    ('0608eaba', 'os_sched', 'med',
     'enter_critical; store ret-addr; switch-out (tail does not return)'),
    ('06086dc8', 'os_int_state_get_a', 'med', 'reads icfg.b0'),
    ('0608eab2', 'os_int_state_get_b', 'med', 'reads icfg.b0'),
    ('0608978a', 'os_critical_nest_get', 'high',
     'returns per-core critical nest counter 0x1083dc[cnum]'),
    ('06087610', 'os_spin_lock', 'high',
     'testset spin on global 0x108404 (SMP lock)'),
    ('0608761e', 'os_spin_unlock', 'high', 'clears 0x108404'),
    # --- clock-change critical section ---
    ('06088c40', 'sysclk_cs_enter', 'med',
     'nest counters 0x1083f4/fc[cnum] + spin lock; PLL wait 0xfe0200; '
     'SFC regs 0xfd55xx; freq dispatch table 0x06088da0'),
    ('06088c72', 'sysclk_cs_exit', 'med',
     'mirror of enter: dec counters, PLL wait, freq dispatch'),
    # --- time/delay ---
    ('0608aee6', 'delay_ms', 'low-med',
     'loop param times calling delay cal loop (global 0x1079c0 = clk rate)'),
    # --- sys time ---
    ('060885ca', 'sys_time_ms', 'low-med',
     'reads 0xffe0f0 timer (T2), /1000 -> ms; PMU helper 0x0bfa5194'),
    ('06088538', 'sys_time_ms_lock', 'low-med',
     'same + optional critical section (param gate)'),
]

targets = json.load(io.open(SRC + r'\disasm\b3_far_targets.json',
                            encoding='utf-8'))

out = {}
applied = 0
for va, nm, conf, ev in NAMES:
    out[va] = {'name': nm, 'conf': conf, 'evidence': ev,
               'source': 'b5-expert (plan NEW2 F3)'}
    # map to RAM target
    for k, e in targets.items():
        if e.get('flash_equiv') == va:
            if 'name' not in e:
                e['name'] = nm
                e['via'] = f'b5-expert ({conf})'
                e['evidence'] = ev
                applied += 1
json.dump(out, io.open(SRC + r'\disasm\b5_names.json', 'w',
                       encoding='utf-8'), indent=0)
json.dump(targets, io.open(SRC + r'\disasm\b3_far_targets.json', 'w',
                           encoding='utf-8'), indent=0)
named = sum(1 for e in targets.values() if 'name' in e)
print(f'b5_names.json: {len(out)} entries; targets newly named: {applied}; '
      f'total named targets: {named}/175')
