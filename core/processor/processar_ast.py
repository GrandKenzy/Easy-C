from __future__ import annotations
import os
from typing import Optional
import gram
from core.processor.visitors import *
from core.processor import objects


def visit_decl(node: gram.ASTNode) -> str:
    """traducir nodo VAR a C"""
    values = node.values
    if len(values) < 2:
        return ""

    t = values[0]
    name = values[1]

    # declara sin iniciar
    if len(values) == 2:
        return f"{t} {name};"

    # declara y inicia
    value = values[2]
    if t == 'char':
        #normalizar a cadena de un char
        val_str = str(value).strip('\'"')
        value = f"'{val_str}'"

    return f"{t} {name} = {value};"


def process(ast: gram.ASTProgram, output_path: Optional[str] = None) -> str:
    """procesa AST , gram y emmite C
    
    si llega un  ouutput_path, escribe el codigo  al archivo 
    """
    lines: list[str] = []
    uses_stdint = False
    uses_stdbool = False

    for node in ast.blocks():
        if not node.children:
            continue
        child = node.children[0]
        if child.name == 'var declaration':
            stmt = visit_decl(child)
            if stmt:
                lines.append(stmt)
                if any(k in stmt for k in ('int8_t', 'int16_t', 'int32_t', 'int64_t',
                                           'uint8_t', 'uint16_t', 'uint32_t', 'uint64_t', 'size_t')):
                    uses_stdint = True
                if 'bool' in stmt:
                    uses_stdbool = True

    #genera headers requeridos
    headers: list[str] = []
    if uses_stdint:
        headers.append("#include <stdint.h>")
        headers.append("#include <stddef.h>")
    if uses_stdbool:
        headers.append("#include <stdbool.h>")

    header_block = "\n".join(headers) + "\n\n" if headers else ""
    c_code = header_block + "\n".join(lines) + "\n"

    if output_path:
        os.makedirs(os.path.dirname(os.path.abspath(output_path)), exist_ok=True)
        with open(output_path, "w", encoding="utf-8") as f:
            f.write(c_code)

    return c_code
