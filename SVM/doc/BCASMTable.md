# 字节码汇编码对应表
格式:
```
Operator [arg1, arg2
```
例子:
```
0000 1
```
Operator格式: 4位十六进制码(0000~ffff)

| 字节码操作符 | 汇编码操作符 | 参数 | 作用 | 例子 |
|-----|------|--------|----------|-----------|
| 0000 | SPLV | version: number | 说明该程序的语言版本 | `0000 1` |
| 0001 | SCV | version: number(格式：大版本号+中版本号+小版本号, 中小版本号最多两位，不够两位前面补零，如2.19.5版本就是: 21905) | 说明该程序编译器的版本 | `0001 10000` |
| 0002 | MVSVMV | version: number(格式同0001 version参数格式) | 说明该程序虚拟机的最低支持版本 | `0002 10000` |
| 0003 | push | regular1: token, value: any(Except for token type) | 将`value`塞入`regular`中，位于寄存器头，value的前一个元素为`%regular-1` | `0003 00 15`, `0003 00 f02a1` |
| 0004 | add | regular1: token, regular2: token | 求寄存器`regular1`顶部值和寄存器`regular2`顶部值的和, 并将结果塞入寄存器`regular1`中 | `0004 02 03` |
| 0005 | sub | regular1: token, regular2: token | 求寄存器`regular1`顶部值和寄存器`regular2`顶部值的差, 并将结果塞入寄存器`regular1`中 | `0005 02 03` |
| 0006 | mul | regular1: token, regular2: token | 求寄存器`regular1`顶部值和寄存器`regular2`顶部值的积, 并将结果塞入寄存器`regular1`中 | `0006 02 03` |
| 0007 | div | regular1: token, regular2: token | 求寄存器`regular1`顶部值和寄存器`regular2`顶部值的商, 并将结果塞入寄存器`regular1`中 | `0007 02 03` |
| 0008 | mod | regular1: token, regular2: token | 求寄存器`regular1`顶部值和寄存器`regular2`顶部值的模, 并将结果塞入寄存器`regular1`中 | `0008 02 03` |
| 0009 | pop | regular1: token, value: number | 将寄存器`regular`退回`value`位 | `0009 02 1` |
| 000a | NONE | functionName | 定义函数 | `000a 1` |
| 000b | ret | None | 结束函数, 即return | `000b` |
| 000c | endfun | None | 函数代码部分结束 | `000c` |
| 000d | call | function: token | 调用函数(如需传参, 将参数传入arg寄存器中) | `000d 0` |