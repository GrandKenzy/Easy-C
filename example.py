import os
import sys

#r resolver direcion de ejecucion
DEV_DIR = os.path.abspath ( os.path.join ( os.path.dirname (__file__) , "..", "Gram" ) )  
if os.path.exists (DEV_DIR) and DEV_DIR not in sys.path:
        sys.path.insert(0, DEV_DIR)

import gram
import   core.grammar
import core.processor


def  autolimpieza() -> None:
    """clean antes de executar"""
    log_dir = os.path.join(os.path.dirname(__file__), "log")
    if os.path.exists(log_dir):
         for fname in os.listdir(log_dir):
             if fname.endswith(".log"):
              try:
                 os.remove(os.path.join(log_dir, fname))
              except OSError:
                       pass


def  transpile (source_file: str, output_file: str) ->  str:
    """pipelin de analisis y transpilacion"""
    ast = gram.process(core.grammar.grammar, source_file)
    c_code = core.processor.process(ast, output_path=output_file)
    return c_code


if __name__ == '__main__':
    autolimpieza()

    gram.config.LEXER_COMMENT_TOKEN = ';'
    gram.config.LEXER_IGNORE_EMPTY_LINES = True
    gram.config.LEXER_IGNORE_NEWLINES = True
    gram.config.LEXER_SAVE_COMMENTS = True
    gram.config.LEXER_SUPPORT_DOCSTRINGS = True
    gram.config.PARSER_ADD_INFO = True
    gram.config.INFO_GENERATE_LOGFILE_ON_ERROR = True
    gram.config.INFO_GENERATE_LOGFILE = True

    source_path = os.path.join(os.path.dirname(__file__), 'example.txt')
    output_path = os.path.join(os.path.dirname(__file__), 'output.c')

    print("||Easy-C|| Starting...")
    c_code = transpile(source_path, output_path)

    print(f"||Easy-C|| Transpilation successfully -> '{output_path}':\n")
    print(c_code)