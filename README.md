# 🔧 Pipex - Proyecto de la Escuela 42

**Pipex** es un proyecto de la Escuela 42 que tiene como objetivo reproducir parte del comportamiento de una shell Unix, específicamente la ejecución de dos comandos encadenados mediante una tubería (`|`). Este proyecto permite al estudiante profundizar en conceptos como la creación de procesos, la comunicación entre ellos con `pipe`, y el uso de `execve` para ejecutar programas externos.

---

## 🎯 Objetivo

Tu programa debe comportarse como el siguiente comando de shell:

```bash
< file1 cmd1 | cmd2 > file2
