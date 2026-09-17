# CONTA BANCÁRIA

### SISTEMA DISTRIBUÍDO BÁSICO CORBA

*(C) Prof. Luiz A. de P. Lima Jr.*
*luiz.lima@pucpr.br*

### Diretórios:

* `idl`: arquivo IDL + *stub* + *skeleton*
* `bin`: executáveis (os resultados das compilações são gerados aqui)
* `cliente`: cliente básico
* `servidor`: servidor básico

### Para gerar stub e skeleton, digite:

```bash
$ cd idl
$ tao_idl -Gstl Conta.idl
```

(`-Gstl`: para usar biblioteca padrão C++)

### Para compilar, digite:

```bash
$ cd cliente            # (ou: cd servidor)
$ make
```

### Para limpar arquivos intermediários:

```bash
$ cd cliente            # (ou: cd servidor)
$ make clean
```

